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
#include <cr_section_macros.h>
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



void dspl_init(dspl_st *me) {

	uv_set_int_priority(INT_SYSTICK, 31);
	uv_set_int_priority(INT_UART0, 30);

	// init GPIO's
	uv_gpio_init_output(LED_PIN, false);
	uv_gpio_init_output(FLASH_CS, false);
	uv_gpio_init_output(FLASH_RESET, true);

	uv_canopen_init(&this->canopen, obj_dict, object_dictionary_size(), CAN1, NULL, NULL);

	// init terminal
	uv_terminal_init(terminal_commands, commands_count());

	// init PWM and start with full duty cycle (LCD off)
	uv_pwm_set(LCD_BACKLIGHT, DUTY_CYCLE(1));
	uv_pwm_set(BUZZER, DUTY_CYCLE(1));

	uv_eeprom_init_circular_buffer(sizeof(log_entry_st));




	// read hour counter value from EEPROM
	uv_eeprom_read((unsigned char*) &this->hour_counter,
			sizeof(this->hour_counter), CONFIG_EEPROM_RING_BUFFER_END_ADDR);

	uv_err_check(uv_memory_load(&this->data_start, &this->data_endl)) {
		// non-volatile data load failed, initialize factory settings

		alert_reset(&this->alert);

		uv_vector_init(&this->users, this->userdata,
				sizeof(this->userdata) / sizeof(userdata_st), sizeof(userdata_st));
		users_add("Usewood");
		users_set("Usewood");


		// save initialized values to memory
		uv_memory_save(&this->data_start, &this->data_endl);
	}



	uv_time_st time;
	uv_rtc_get_time(&time);
	this->last_hour = time.hour;

	gui_init();

	alert_init(&this->alert);

	uv_delay_init(1000, &this->step_delay);

	log_add(LOG_BOOT_UP, uv_reset_get_source());




}


void dspl_step(void *me) {
	while (true) {
		int step_ms = 20;

//		uv_wdt_update();

		uv_terminal_step();

		uv_can_step(CAN1, step_ms);

		uv_canopen_step(&this->canopen, step_ms);

		alert_step(&this->alert, step_ms);

		uv_time_st time;
		uv_rtc_get_time(&time);
		if (this->last_hour != time.hour) {
			this->hour_counter++;
			uv_eeprom_write((unsigned char*) &this->hour_counter,
					sizeof(this->hour_counter), CONFIG_EEPROM_RING_BUFFER_END_ADDR);
		}
		this->last_hour = time.hour;

		if (uv_delay(step_ms, &this->step_delay)) {
			uv_gpio_toggle(LED_PIN);
			uv_delay_init(1000, &this->step_delay);
		}

		uv_rtos_task_delay(step_ms);
	}
}


int main(void) {
//	uv_wdt_init(1);

	uv_init(&dspl);

	dspl_init(&dspl);


	uv_rtos_task_create(dspl_step, "dspl_step", UV_RTOS_MIN_STACK_SIZE * 3,
			&dspl, UV_RTOS_IDLE_PRIORITY + 2, NULL);

	printf("ready\n\r>");

	uv_rtos_start_scheduler();

    return 0 ;
}
