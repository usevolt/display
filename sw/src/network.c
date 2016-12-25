/*
 * network.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */



#include "network.h"

static void network_task(void *me);



void network_init(network_st *this) {
	this->updating = true;
	uv_rtos_task_create(network_task, "network",
			UV_RTOS_MIN_STACK_SIZE * 2, this, UV_RTOS_IDLE_PRIORITY + 1, NULL);
	msb_init(&this->msb);
	csb_init(&this->csb);
	rkeypad_init(&this->r_keypad);
	lkeypad_init(&this->l_keypad);
	ecu_init(&this->ecu);
	pedal_init(&this->pedal);
}

#define this ((network_st *)me)

static void network_task(void *me) {
	int16_t step_ms = 20;
	while (true) {

		msb_step(&this->msb, step_ms);
		csb_step(&this->csb, step_ms);
		pedal_step(&this->pedal, step_ms);
		ecu_step(&this->ecu, step_ms);
		keypad_step(&this->l_keypad, step_ms);
		keypad_step(&this->r_keypad, step_ms);

		if(this->updating) {
			msb_update(&this->msb);
			csb_update(&this->csb);
			pedal_update(&this->pedal);
			ecu_update(&this->ecu);
			keypad_update(&this->l_keypad);
			keypad_update(&this->r_keypad);
			this->updating = false;
		}

		uv_rtos_task_delay(step_ms);
	}
}
