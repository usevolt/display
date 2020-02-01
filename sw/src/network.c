/*
 * network.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */



#include "network.h"
#include "main.h"

static void network_task(void *me);


#define NETWORK_CAN_BUS_OFF_AVER_COUNT		500



void network_init(network_st *this) {
	this->updating = true;
	this->save = false;
	this->update_disabled = false;
	this->can_last_state = CAN_ERROR_ACTIVE;
	uv_moving_aver_init(&this->can_state, NETWORK_CAN_BUS_OFF_AVER_COUNT);

	uv_rtos_task_create(network_task, "network",
			UV_RTOS_MIN_STACK_SIZE * 10, this, UV_RTOS_IDLE_PRIORITY + 1, NULL);
	esb_init(&this->esb);
	csb_init(&this->csb);
	fsb_init(&this->fsb);
	rkeypad_init(&this->r_keypad);
	lkeypad_init(&this->l_keypad);
	hcu_init(&this->hcu);
	ccu_init(&this->ccu);
	pedal_init(&this->pedal);
	icu_init(&this->icu);
	tcu_init(&this->tcu);
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
			netdev_receive_heartbeat(&this->hcu, msg);
			netdev_receive_heartbeat(&this->ccu, msg);
			netdev_receive_heartbeat(&this->icu, msg);
			netdev_receive_heartbeat(&this->tcu, msg);
		}
	}
}


void network_save_params(network_st *this) {
	uv_canopen_sdo_write(ESB_NODE_ID, CONFIG_CANOPEN_STORE_PARAMS_INDEX, 1,
			CANOPEN_TYPE_LEN(CANOPEN_UNSIGNED32),
			"save");

	uv_canopen_sdo_write(FSB_NODE_ID, CONFIG_CANOPEN_STORE_PARAMS_INDEX, 1,
			CANOPEN_TYPE_LEN(CANOPEN_UNSIGNED32),
			"save");

	uv_canopen_sdo_write(ICU_NODE_ID, CONFIG_CANOPEN_STORE_PARAMS_INDEX, 1,
			CANOPEN_TYPE_LEN(CANOPEN_UNSIGNED32),
			"save");

	uv_rtos_task_delay(10);

	uv_canopen_sdo_write(HCU_NODE_ID, CONFIG_CANOPEN_STORE_PARAMS_INDEX, 1,
			CANOPEN_TYPE_LEN(CANOPEN_UNSIGNED32),
			"save");

	uv_canopen_sdo_write(CCU_NODE_ID, CONFIG_CANOPEN_STORE_PARAMS_INDEX, 1,
			CANOPEN_TYPE_LEN(CANOPEN_UNSIGNED32),
			"save");

	uv_canopen_sdo_write(CSB_NODE_ID, CONFIG_CANOPEN_STORE_PARAMS_INDEX, 1,
			CANOPEN_TYPE_LEN(CANOPEN_UNSIGNED32),
			"save");

	uv_rtos_task_delay(10);

	uv_canopen_sdo_write(TCU_NODE_ID, CONFIG_CANOPEN_STORE_PARAMS_INDEX, 1,
			CANOPEN_TYPE_LEN(CANOPEN_UNSIGNED32),
			"save");

}


#define this ((network_st *)me)


static void network_task(void *me) {
	int16_t step_ms = 20;
	while (true) {

		esb_step(&this->esb, step_ms);
		csb_step(&this->csb, step_ms);
		fsb_step(&this->fsb, step_ms);
		pedal_step(&this->pedal, step_ms);
		hcu_step(&this->hcu, step_ms);
		ccu_step(&this->ccu, step_ms);
		keypad_step(&this->l_keypad, step_ms);
		keypad_step(&this->r_keypad, step_ms);
		icu_step(&this->icu, step_ms);
		tcu_step(&this->tcu, step_ms);

		if(this->updating && !this->update_disabled) {
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

			hcu_update(&this->hcu);
			uv_rtos_task_delay(update_step_ms);

			ccu_update(&this->ccu);
			uv_rtos_task_delay(update_step_ms);

			keypad_update(&this->l_keypad);
			uv_rtos_task_delay(update_step_ms);

			keypad_update(&this->r_keypad);
			uv_rtos_task_delay(update_step_ms);

			tcu_update(&this->tcu);
			uv_rtos_task_delay(update_step_ms);

			// read CCU assembly parameters to check if telescope or backsteer is enabled
			uint8_t ccu_assembly[CCU_ASSEMBLY_ARRAY_SIZE];
			for (uint8_t i = 0; i < CCU_ASSEMBLY_ARRAY_SIZE; i++) {
				uv_canopen_sdo_read(CCU_NODE_ID, CCU_ASSEMBLY_INDEX, i + 1,
						CANOPEN_TYPE_LEN(CCU_ASSEMBLY_TYPE), &ccu_assembly[i]);
			}
			// since valve settings are shared across the devices,
			// update them here
			for (uint8_t i = 0; i < BASE_VALVE_COUNT; i++) {
				// CCU telescope and backsteer are special cases since they use
				// same parameters and only one of them can be enabled.
				// We want to update values only on the enabled one
				if (dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREETELESCOPE) {
					if (ccu_assembly[CCU_ASSEMBLY_TELESCOPE_INDEX]) {
						dspl.user->base_valves[i].setter(&dspl.user->base_valves[i]);
					}
				}
				else if (dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREESTEERBACK) {
					if (ccu_assembly[CCU_ASSEMBLY_BACKSTEER_INDEX]) {
						dspl.user->base_valves[i].setter(&dspl.user->base_valves[i]);
					}
				}
				else {
					dspl.user->base_valves[i].setter(&dspl.user->base_valves[i]);
				}
				uv_rtos_task_delay(update_step_ms);
			}

			// update implement valves
			implement_st *im = dspl_get_implement_ptr(&dspl);
			if (im != NULL) {
				hcu_impls_e impl = hcu_get_implement(&this->hcu);

				if (impl == HCU_IMPLEMENT_UW180S) {
					// this is done in icu.c
				}
				else if (impl == HCU_IMPLEMENT_UW100) {
					dspl.user->uw100.open.setter(&dspl.user->uw100.open);
					dspl.user->uw100.rotator.setter(&dspl.user->uw100.rotator);
				}
				else if (impl == HCU_IMPLEMENT_UW50) {
					dspl.user->uw50.saw.setter(&dspl.user->uw50.saw);
					dspl.user->uw50.tilt.setter(&dspl.user->uw50.tilt);
				}
				else if (impl == HCU_IMPLEMENT_HYDOUTPUT) {
					dspl.user->hydout.impl2.setter(&dspl.user->hydout.impl2);
				}
				else {

				}
			}

			if (this->save) {
				this->save = false;
				network_save_params(this);
			}
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
			else if ((emcy.node_id == HCU_NODE_ID) &&
					(emcy.data < HCU_EMCY_COUNT)) {
				uint8_t i = emcy.data - HCU_EMCY_BOOM_ROTATE_OVERLOAD_A;
				log_add(HCU_EMCY_BOOM_ROTATE_OVERLOAD_A + i);
			}
			else if ((emcy.node_id == CCU_NODE_ID) &&
					(emcy.data < CCU_EMCY_COUNT)) {
				uint8_t i = emcy.data - CCU_EMCY_STEER_OVERLOAD_A;
				log_add(CCU_EMCY_STEER_OVERLOAD_A + i);
			}
			else if ((emcy.node_id == ICU_NODE_ID) &&
					(emcy.data < ICU_EMCY_COUNT)) {
				uint8_t i = emcy.data - ICU_EMCY_BLADEOPEN_OVERCURRENT;
				log_add(ICU_EMCY_BLADEOPEN_OVERCURRENT + i);
			}
			else {

			}
		}


		uv_rtos_task_delay(step_ms);
	}
}


