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
#include <can_esb.h>
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

#if CONFIG_TARGET_LPC1785
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + HCU_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + CSB_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + FSB_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + ESB_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + LKEYPAD_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + RKEYPAD_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + CCU_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_SDO_RESPONSE_ID + ICU_NODE_ID, CAN_STD);

	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + HCU_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + CSB_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + FSB_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + ESB_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + LKEYPAD_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + RKEYPAD_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + CCU_NODE_ID, CAN_STD);
	uv_can_config_rx_message(CONFIG_CANOPEN_CHANNEL, CANOPEN_EMCY_ID + ICU_NODE_ID, CAN_STD);
#endif

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

		this->lang = LANG_EN;

		alert_reset(&this->alert);

		users_reset();

		gui_reset();

		// save initialized values to memory
		uv_memory_save();
	}

	set_lang(this->lang);


 	// init terminal
	uv_terminal_init(terminal_commands, commands_count());

	// init PWM and start with full duty cycle (LCD off)
	uv_pwm_set(LCD_BACKLIGHT, DUTY_CYCLE(1));
	uv_pwm_set(BUZZER, DUTY_CYCLE(0));

	uv_eeprom_init_circular_buffer(sizeof(log_entry_st));

	log_init();

	users_init();

	network_init(&this->network);

	uv_time_st time;
	uv_rtc_get_time(&time);
	this->last_min = time.min;
	// init sec counter to half an hour in startup
	this->min_counter = 30;

	// read hour counter value from EEPROM
	uv_eeprom_read((unsigned char*) &this->hour_counter,
			sizeof(this->hour_counter), HOUR_COUNTER_EEPROM_ADDR);
	// also read hour value from ESB
	uint32_t esb_hour = 0;
	if (uv_canopen_sdo_read(ESB_NODE_ID, ESB_HOUR_INDEX, ESB_HOUR_SUBINDEX,
			CANOPEN_TYPE_LEN(ESB_HOUR_TYPE), &esb_hour) == ERR_NONE) {
		if (esb_hour > this->hour_counter) {
			// if ESB had bigger counter, update ours
			this->hour_counter = esb_hour;
			uv_eeprom_write((unsigned char*) &this->hour_counter,
					sizeof(this->hour_counter), HOUR_COUNTER_EEPROM_ADDR);
		}
		else {
			// if we had bigger counter, update ESB's
			esb_hour = this->hour_counter;
			uv_canopen_sdo_write(ESB_NODE_ID, ESB_HOUR_INDEX, ESB_HOUR_SUBINDEX,
					CANOPEN_TYPE_LEN(ESB_HOUR_TYPE), &esb_hour);
		}
	}


	gui_init();

	alert_init(&this->alert);

	uv_canopen_set_can_callback(can_callback);

	// the display lives it's own life. It is allowed to boot itself up into operational mode
	uv_canopen_set_state(CANOPEN_OPERATIONAL);

	printf("asd\n");

}


void dspl_step(void *me) {

	dspl_init(&dspl);

	while (true) {
		int step_ms = 20;

		uv_terminal_step();

		alert_step(&this->alert, step_ms);

		uv_time_st time;
		uv_rtc_get_time(&time);
		if (esb_get_rpm(&dspl.network.esb) != 0) {
			if (this->last_min != time.min) {
				this->min_counter++;
				if (this->min_counter == 60) {
					this->hour_counter++;
					uv_eeprom_write((unsigned char*) &this->hour_counter,
							sizeof(this->hour_counter), HOUR_COUNTER_EEPROM_ADDR);
					this->min_counter = 0;
				}
			}
		}
		this->last_min = time.min;

		uv_rtos_task_delay(step_ms);
	}
}


implement_st *dspl_get_implement_ptr(void *me) {
	void *ret = NULL;
	if (this->user != NULL) {
		switch (hcu_get_implement(&this->network.hcu)) {
		case HCU_IMPLEMENT_UW180S:
			ret = &this->user->uw180s;
			break;
		case HCU_IMPLEMENT_UW100:
			ret = &this->user->uw100;
			break;
		case HCU_IMPLEMENT_UW50:
			ret = &this->user->uw50;
			break;
		case HCU_IMPLEMENT_HYDOUTPUT:
			ret = &this->user->hydout;
			break;
		default:
			ret = NULL;
			break;
		}
	}
	return ret;
}


int main(void) {

	uv_init(&dspl);

	uv_rtos_task_create(dspl_step, "dspl_step", UV_RTOS_MIN_STACK_SIZE * 6,
			&dspl, UV_RTOS_IDLE_PRIORITY + 2, NULL);

	uv_rtos_start_scheduler();

    return 0 ;
}





