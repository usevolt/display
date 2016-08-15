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
#include <stdint.h>
#include <stdio.h>
#include <uv_rtos.h>
#include <uv_terminal.h>
#include <uv_timer.h>
#include <uv_uart.h>
#include <uv_utilities.h>
#include <uv_wdt.h>
#include <uv_emc.h>
#include "pin_mappings.h"

#define this ((dspl_st*)me)

dspl_st dspl;



void dspl_init(dspl_st *me) {
	uv_err_check(uv_memory_load(&this->data_start, &this->data_endl)) {
		// non-volatile data load failed, initialize factory settings

		// save initialized values to memory
		uv_memory_save(&this->data_start, &this->data_endl);
	}

	uv_delay_init(1000, &this->step_delay);

}


//void dspl_step(void *me, unsigned int step_ms) {
void dspl_step(void *me) {
	while (true) {
		int step_ms = 20;

//		uv_wdt_update();


		uv_terminal_step();
		uv_can_step(CAN1, step_ms);
		uv_canopen_step(&this->canopen, step_ms);

		if (uv_delay(step_ms, &this->step_delay)) {
			uv_gpio_toggle(LED_PIN);
			uv_delay_init(1000, &this->step_delay);
		}


		uv_rtos_task_delay(step_ms);
	}
}

void dspl_pin_callback(void *me, uv_gpios_e pin) {

}



int main(void) {
//	uv_wdt_init(1);

	uv_set_int_priority(INT_SYSTICK, 31);
	uv_set_int_priority(INT_UART0, 30);


	// init GPIO's
	uv_gpio_add_interrupt_callback(dspl_pin_callback);
	uv_gpio_init_output(LED_PIN, false);

	// init UART0
	uv_uart_init(UART0);

	// init MEC
	uv_emc_init();

	// init terminal
	uv_terminal_init(commands(), commands_count());

	// set application pointer to HAL library
	uv_set_application_ptr(&dspl);

	uv_can_init(CAN1);

	uv_canopen_init(&dspl.canopen, obj_dict, object_dictionary_size(), CAN1, NULL, NULL);

	dspl_init(&dspl);



	uv_rtos_task_create(dspl_step, "dspl_step", UV_RTOS_MIN_STACK_SIZE,
			&dspl, UV_RTOS_IDLE_PRIORITY + 1, NULL);

	printf("ready\n\r>");

	uv_rtos_start_scheduler();

    return 0 ;
}
