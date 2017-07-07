/*
===============================================================================
 Name        : uv_display.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <canopen.h>
#include <commands.h>
#include "LPC177x_8x.h"
#include <main.h>
#include <uv_rtos.h>
#include <uv_terminal.h>
#include <uv_timer.h>
#include <uv_uart.h>
#include <uv_utilities.h>
#include <uv_wdt.h>
#include <uv_emc.h>
#include <uv_lcd.h>
#include <uv_pwm.h>
#include <uv_eeprom.h>
#include <uv_reset.h>
#include <uv_rtc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pin_mappings.h"
#include "log.h"
#include "gui.h"
#include "alert.h"
#include "users.h"

#define this ((dspl_st*)me)

dspl_st dspl;

void can_callback(void *me, uv_can_message_st *msg) {
	network_receive_message(&this->network, msg);
}

void dspl_init(dspl_st *me) {

	uv_set_int_priority(INT_SYSTICK, 31);
	uv_set_int_priority(INT_UART0, 30);


	// read hour counter value from EEPROM
	uv_eeprom_read((unsigned char*) &this->hour_counter,
			sizeof(this->hour_counter), HOUR_COUNTER_EEPROM_ADDR);

	// the first thing to do: if display is pressed for 10 s, restore system defaults
	bool restore = false;
	int counter = 10;
	char str[3];
	char coord[30];
	int16_t x,y;
	while (uv_lcd_touch_get(&x, &y)) {
		uv_pwm_set(LCD_BACKLIGHT, DUTY_CYCLE(0.9f));

		uv_lcd_draw_rect(0, 0, LCD_W(1.0f), LCD_H(1.0f), C(0x000000));
		_uv_ui_draw_text(LCD_W(0.5f), LCD_H(0.5f) - 120, &UI_FONT_BIG, ALIGN_CENTER,
				C(0xFFFFFF), C(0xFFFFFFFF), "Press the screen for 10 seconds to\n"
						"restore factory settings\n \n"
						"WARNING: This will clear all\nparameters from all users", 1.0f);
		sprintf(str, "%u", counter);
		_uv_ui_draw_text(LCD_W(0.5f), LCD_H(0.5f), &UI_FONT_BIG, ALIGN_CENTER,
				(counter <= 5) ? C(0xFF0000) : C(0xFFFFFF), C(0xFFFFFFFF), str, 1.0f);
		sprintf(coord, "(%i,%i)", x, y);
		_uv_ui_draw_text(5, LCD_H(1.0f) - UI_FONT_SMALL.char_height - 5, &UI_FONT_SMALL,
				ALIGN_TOP_LEFT, C(0xFFFFFF), C(0), coord, 1.0f);
		uv_lcd_draw_rect(x - 5, y - 5, 10, 10, C(0xFF0000));


		if (!counter) {
			restore = true;
			break;
		}

		counter--;

		uv_lcd_double_buffer_swap();

		uv_rtos_task_delay(1000);
	}

	if (restore || uv_memory_load()) {
		// non-volatile data load failed, initialize factory settings


		alert_reset(&this->alert);

		users_reset();

		gui_set_backlight(100);

		// save initialized values to memory
		uv_memory_save();
	}


 	// init terminal
	uv_terminal_init(terminal_commands, commands_count());

	// init PWM and start with full duty cycle (LCD off)
	uv_pwm_set(LCD_BACKLIGHT, DUTY_CYCLE(1));
	uv_pwm_set(BUZZER, DUTY_CYCLE(0));

	uv_eeprom_init_circular_buffer(sizeof(log_entry_st));

	log_init();

	network_init(&this->network);

	uv_time_st time;
	uv_rtc_get_time(&time);
	this->last_sec = time.sec;
	// init sec counter to half an hour in startup
	this->sec_counter = 60 * 30;

	users_init();

	gui_init();

	alert_init(&this->alert);

	uv_canopen_set_can_callback(can_callback);

	// the display lives it's own life. It is allowed to boot itself up into operational mode
	uv_canopen_set_state(CANOPEN_OPERATIONAL);


}


void dspl_step(void *me) {

	dspl_init(&dspl);

	while (true) {
		int step_ms = 20;

		uv_terminal_step();

		alert_step(&this->alert, step_ms);

		canopen_emcy_msg_st emcy;
		if (uv_canopen_emcy_get(&emcy)) {
			network_receive_emcy(&this->network, &emcy);
		}

		uv_time_st time;
		uv_rtc_get_time(&time);
		if (this->last_sec != time.sec) {
			this->sec_counter++;
			if (this->sec_counter == 60 * 60) {
				this->hour_counter++;
				uv_eeprom_write((unsigned char*) &this->hour_counter,
						sizeof(this->hour_counter), HOUR_COUNTER_EEPROM_ADDR);
				this->sec_counter = 0;
			}
		}
		this->last_sec = time.sec;

		uv_rtos_task_delay(step_ms);
	}
}


int main(void) {

	uv_init(&dspl);

	uv_rtos_task_create(dspl_step, "dspl_step", UV_RTOS_MIN_STACK_SIZE * 8,
			&dspl, UV_RTOS_IDLE_PRIORITY + 2, NULL);

	uv_rtos_start_scheduler();

    return 0 ;
}
