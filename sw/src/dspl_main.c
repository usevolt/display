/*
===============================================================================
 Name        : uv_display.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "LPC177x_8x.h"
#include <cr_section_macros.h>
#include <stdint.h>
#include <stdio.h>
#include <uv_rtos.h>
#include <uv_terminal.h>
#include <uv_timer.h>
#include <uv_uart.h>
#include <uv_utilities.h>
#include <uv_wdt.h>
#include "dspl_main.h"
#include "dspl_commands.h"

#define this ((dspl_st*)me)

static dspl_st dspl;


const dspl_const_obj_dict_st dspl_const_obj_dict = {
		.device_type = 0x00000000
};




void dspl_init(dspl_st *me) {
	uv_err_check(uv_memory_load(&this->data_start, &this->data_endl)) {
		// non-volatile data load failed, initialize factory settings
		this->step_cycle_ms = 1000;

		// save initialized values to memory
		uv_memory_save(&this->data_start, &this->data_endl);
	}


}


//void dspl_step(void *me, unsigned int step_ms) {
void dspl_step(void *me) {
	while (true) {
//		uv_wdt_update();

		uv_gpio_toggle_pin(PIO2_31);

		uv_terminal_step();

		uv_rtos_task_delay(this->step_cycle_ms);
	}
}

void dspl_pin_callback(void *me, uv_gpios_e pin) {

}



int main(void) {
//	uv_wdt_init(10);


	uv_set_int_priority(INT_SYSTICK, 31);
	uv_set_int_priority(INT_UART0, 30);


	// init GPIO's
	uv_gpio_add_interrupt_callback(dspl_pin_callback);
	uv_gpio_init_output(PIO2_31, false);

	// init UART0
	uv_err_check(uv_uart_init(UART0));

	// init terminal
	uv_terminal_init(dspl_commands(), dspl_commands_count(), dspl_command_callback);

	// set application pointer to HAL library
	uv_set_application_ptr(&dspl);

	dspl_init(&dspl);



	uv_rtos_task_create(dspl_step, "dspl_step", UV_RTOS_MIN_STACK_SIZE,
			&dspl, UV_RTOS_IDLE_PRIORITY + 1, NULL);

	printf("ready\n\r>");

	uv_rtos_start_scheduler();

    return 0 ;
}
