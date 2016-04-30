/*
===============================================================================
 Name        : uw_display.c
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
#include <uw_utilities.h>
#include <uw_uart.h>
#include <uw_timer.h>
#include <uw_terminal.h>
#include <uw_rtos.h>
#include <uw_wdt.h>
#include "dspl_main.h"
#include "dspl_commands.h"

#define this ((dspl_st*)me)

static dspl_st dspl;


const dspl_const_obj_dict_st dspl_const_obj_dict = {
		.device_type = 0x00000000
};




void dspl_init(dspl_st *me) {
	uw_err_check(uw_memory_load(&this->data_start, &this->data_endl)) {
		// non-volatile data load failed, initialize factory settings
		this->step_cycle_ms = 1000;

		// save initialized values to memory
		uw_memory_save(&this->data_start, &this->data_endl);
	}


}


//void dspl_step(void *me, unsigned int step_ms) {
void dspl_step(void *me) {
	while (true) {
//		uw_wdt_update();

		uw_gpio_toggle_pin(PIO2_31);

		uw_terminal_step();

		uw_rtos_task_delay(this->step_cycle_ms);
	}
}

void dspl_pin_callback(void *me, uw_gpios_e pin) {

}



int main(void) {
//	uw_wdt_init(10);


	uw_set_int_priority(INT_SYSTICK, 31);
	uw_set_int_priority(INT_UART0, 30);


	// init GPIO's
	uw_gpio_add_interrupt_callback(dspl_pin_callback);
	uw_gpio_init_output(PIO2_31, false);

	// init UART0
	uw_err_check(uw_uart_init(UART0));

	// init terminal
	uw_terminal_init(dspl_commands(), dspl_commands_count(), dspl_command_callback);

	// set application pointer to HAL library
	uw_set_application_ptr(&dspl);

	dspl_init(&dspl);



	uw_rtos_task_create(dspl_step, "dspl_step", UW_RTOS_MIN_STACK_SIZE,
			&dspl, UW_RTOS_IDLE_PRIORITY + 1, NULL);

	printf("ready\n\r>");

	uw_rtos_start_scheduler();

    return 0 ;
}
