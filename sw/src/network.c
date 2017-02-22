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

		int cur_state = (uv_can_get_error_state(CAN1) == CAN_ERROR_ACTIVE);


		int state = uv_moving_aver_step(&this->can_state, cur_state);

//		printf("cur_state: %u, state: %u\n ", cur_state, state);

		// log an error when the error state has been entered
		if (!state) {
			if (this->can_last_state != state) {
				log_add(LOG_CAN_BUS_OFF, 0);
			}
			netdev_clear_disconnect_delay(&this->msb);
			netdev_clear_disconnect_delay(&this->csb);
			netdev_clear_disconnect_delay(&this->l_keypad);
			netdev_clear_disconnect_delay(&this->r_keypad);
			netdev_clear_disconnect_delay(&this->pedal);
			netdev_clear_disconnect_delay(&this->ecu);
			netdev_clear_disconnect_delay(&this->uw180s_ecu);
			netdev_clear_disconnect_delay(&this->uw180s_mb);
		}
		else {
			for (int i = 0; i < log_get_nack_count(); i++) {
				log_entry_st e;
				log_get_nack(&e, i);
				if (e.type == LOG_CAN_BUS_OFF) {
					log_ack(i);
					break;
				}
			}
			msb_step(&this->msb, step_ms);
			csb_step(&this->csb, step_ms);
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

				msb_update(&this->msb);
				uv_rtos_task_delay(update_step_ms);

				csb_update(&this->csb);
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
		}

		this->can_last_state = state;

		uv_rtos_task_delay(step_ms);
	}
}
