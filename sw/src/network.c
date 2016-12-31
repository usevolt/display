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
			UV_RTOS_MIN_STACK_SIZE * 10, this, UV_RTOS_IDLE_PRIORITY + 1, NULL);
	msb_init(&this->msb);
	csb_init(&this->csb);
	rkeypad_init(&this->r_keypad);
	lkeypad_init(&this->l_keypad);
	ecu_init(&this->ecu);
	pedal_init(&this->pedal);
	mb_init(&this->uw180s_mb);
	uw180s_ecu_init(&this->uw180s_ecu);
}

void network_receive_message(network_st *this, uv_can_message_st *msg) {
	if (msg->type == CAN_STD && (msg->id & ~0xFF) == CANOPEN_HEARTBEAT_ID) {
		netdev_receive_heartbeat(&this->msb, msg);
		netdev_receive_heartbeat(&this->csb, msg);
		netdev_receive_heartbeat(&this->l_keypad, msg);
		netdev_receive_heartbeat(&this->r_keypad, msg);
		netdev_receive_heartbeat(&this->pedal, msg);
		netdev_receive_heartbeat(&this->ecu, msg);
		netdev_receive_heartbeat(&this->uw180s_ecu, msg);
		netdev_receive_heartbeat(&this->uw180s_mb, msg);
	}
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
		mb_step(&this->uw180s_mb, step_ms);
		uw180s_ecu_step(&this->uw180s_ecu, step_ms);

		if(this->updating) {
			msb_update(&this->msb);
			csb_update(&this->csb);
			pedal_update(&this->pedal);
			ecu_update(&this->ecu);
			keypad_update(&this->l_keypad);
			keypad_update(&this->r_keypad);
			mb_update(&this->uw180s_mb);
			uw180s_ecu_update(&this->uw180s_ecu);
			this->updating = false;
		}

		uv_rtos_task_delay(step_ms);
	}
}
