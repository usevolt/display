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
#include "dspl_main.h"
#include "dspl_commands.h"
#include "FreeRTOS.h"
#include "task.h"

#define this ((dspl_st*)me)

static dspl_st dspl;


const dspl_const_obj_dict_st dspl_const_obj_dict = {
		.device_type = 0x00000000
};




void dspl_init(dspl_st *me) {
	uw_err_check(uw_memory_load(&this->data_start, &this->data_endl)) {
		// non-volatile data load failed, initialize factory settings

		// save initialized values to memory
		uw_memory_save(&this->data_start, &this->data_endl);
	}

}


//void dspl_step(void *me, unsigned int step_ms) {
void dspl_step(void *me) {
	while (true) {
		uw_gpio_toggle_pin(PIO2_31);
		// 1 s delay
		vTaskDelay(1000);
	}
}

void dspl_pin_callback(void *me, uw_gpios_e pin) {

}


int main(void) {
//	uw_set_int_priority(INT_SYSTICK, 31);
//	uw_set_int_priority(INT_UART0, 30);


	// init GPIO's
//	uw_gpio_add_interrupt_callback(dspl_pin_callback);
	uw_gpio_init_output(PIO2_31, false);

//	// init UART0
//	uw_err_check(uw_uart_init(UART0, 115200, UART0_TX_PIO0_2, UART0_RX_PIO0_3));
//
//	// init terminal
//	uw_terminal_init(dspl_commands(), dspl_commands_count(), dspl_command_callback);
//
//	// set application pointer to HAL library
//	uw_set_application_ptr(&dspl);

	// init tick timer for 20 ms step cycle
//	uw_tick_timer_init(50);
//	uw_tick_timer_add_callback(dspl_step);

//	dspl_init(&dspl);

//	printf("ready\n\r>");

	xTaskCreate(dspl_step, (signed char *) "display_step",
			configMINIMAL_STACK_SIZE, &dspl, tskIDLE_PRIORITY + 1, NULL);

	vTaskStartScheduler();

    while(1);

    return 0 ;
}
