/*
 * network.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */



#include "network.h"

static void network_task(void *me);


#define NETWORK_CAN_BUS_OFF_AVER_COUNT		500



void network_init(network_st *this) {
	this->updating = true;
	this->can_last_state = CAN_ERROR_ACTIVE;
	uv_moving_aver_init(&this->can_state, NETWORK_CAN_BUS_OFF_AVER_COUNT);

	uv_rtos_task_create(network_task, "network",
			UV_RTOS_MIN_STACK_SIZE * 10, this, UV_RTOS_IDLE_PRIORITY + 1, NULL);
	esb_init(&this->esb);
	csb_init(&this->csb);
	fsb_init(&this->fsb);
	rkeypad_init(&this->r_keypad);
	lkeypad_init(&this->l_keypad);
	ecu_init(&this->ecu);
	pedal_init(&this->pedal);
	mb_init(&this->uw180s_mb);
	uw180s_ecu_init(&this->uw180s_ecu);
}

void network_receive_emcy(network_st *this, const canopen_emcy_msg_st *emcy) {
	if (emcy->node_id == ((netdev_st*) &this->ecu)->node_id) {
		ecu_emcy(&this->ecu, emcy);
	}
}


void network_receive_message(network_st *this, uv_can_message_st *msg) {
	if (msg->type == CAN_STD) {
		uint16_t id_type = msg->id & (~0xFF);

		if ((id_type == CANOPEN_HEARTBEAT_ID) ||
				(id_type == CANOPEN_TXPDO1_ID)) {
			netdev_receive_heartbeat(&this->esb, msg);
			netdev_receive_heartbeat(&this->csb, msg);
			netdev_receive_heartbeat(&this->fsb, msg);
			netdev_receive_heartbeat(&this->l_keypad, msg);
			netdev_receive_heartbeat(&this->r_keypad, msg);
			netdev_receive_heartbeat(&this->pedal, msg);
			netdev_receive_heartbeat(&this->ecu, msg);
			netdev_receive_heartbeat(&this->uw180s_ecu, msg);
			netdev_receive_heartbeat(&this->uw180s_mb, msg);
		}
	}
}

#define this ((network_st *)me)


static void network_task(void *me) {
	int16_t step_ms = 20;
	while (true) {

		esb_step(&this->esb, step_ms);
		csb_step(&this->csb, step_ms);
		fsb_step(&this->fsb, step_ms);
		pedal_step(&this->pedal, step_ms);
		ecu_step(&this->ecu, step_ms);
		keypad_step(&this->l_keypad, step_ms);
		keypad_step(&this->r_keypad, step_ms);
		if (ecu_get_implement(&this->ecu) == IMPL_UW180S) {
			mb_step(&this->uw180s_mb, step_ms);
			uw180s_ecu_step(&this->uw180s_ecu, step_ms);
		}

		if(this->updating) {
			this->updating = false;

			uint8_t update_step_ms = 10;

			esb_update(&this->esb);
			uv_rtos_task_delay(update_step_ms);

			csb_update(&this->csb);
			uv_rtos_task_delay(update_step_ms);

			fsb_update(&this->fsb);
			uv_rtos_task_delay(update_step_ms);

			pedal_update(&this->pedal);
			uv_rtos_task_delay(update_step_ms);

			ecu_update(&this->ecu);
			uv_rtos_task_delay(update_step_ms);

			keypad_update(&this->l_keypad);
			uv_rtos_task_delay(update_step_ms);

			keypad_update(&this->r_keypad);
			uv_rtos_task_delay(update_step_ms);

			mb_update(&this->uw180s_mb);
			uv_rtos_task_delay(update_step_ms);

			uw180s_ecu_update(&this->uw180s_ecu);
		}

		canopen_emcy_msg_st emcy;
		if (uv_canopen_emcy_get(&emcy)) {
			if ((emcy.node_id == ESB_NODE_ID) &&
					(emcy.data < ESB_EMCY_COUNT)) {
				uint8_t i = emcy.data - ESB_EMCY_GLOW_OVERLOAD;
				log_add(LOG_ESB_GLOW_OVERLOAD + i);
			}
			else if ((emcy.node_id == FSB_NODE_ID) &&
					(emcy.data < FSB_EMCY_COUNT)) {
				uint8_t i = emcy.data - FSB_EMCY_HORN_OVERCURRENT;
				log_add(LOG_FSB_HORN_OVERCURRENT + i);
			}
			else if ((emcy.node_id == CSB_NODE_ID) &&
					(emcy.data < CSB_EMCY_COUNT)) {
				uint8_t i = emcy.data - CSB_EMCY_WORK_LIGHT_OVERCURRENT;
				log_add(LOG_CSB_WORK_LIGHT_OVERCURRENT + i);
			}
			else {

			}
		}


		uv_rtos_task_delay(step_ms);
	}
}
