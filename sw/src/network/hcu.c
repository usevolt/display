/*
 * uw180s.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#include <hcu.h>
#include "netdev.h"
#include "main.h"



void hcu_init(hcu_st *this) {
	netdev_init(this, hcu_update);
	netdev_set_node_id(this, HCU_NODE_ID);
	netdev_set_disconnected_type(this, LOG_HCU_DISCONNECTED);
	this->total_current = 0;
	this->implement = HCU_IMPLEMENT_UW180S;
	this->pressure = 0;
}

void hcu_step(hcu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}


#define this (&(dspl.network.hcu))

void hcu_update(void *me) {

	// note: No need to update valve settings,
	// they are already updated in network.c
}


static void update_valve_params(valve_st *valve, uint16_t mindex, uint8_t data_len) {
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 1,
			data_len,
			&valve->min_speed_p);
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 2,
			data_len,
			&valve->max_speed_p);
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 3,
			data_len,
			&valve->min_speed_n);
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 4,
			data_len,
			&valve->max_speed_n);
	uv_rtos_task_delay(10);
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 5,
			data_len,
			&valve->acc);
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 6,
			data_len,
			&valve->dec);
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 7,
			data_len,
			&valve->invert);
	uv_canopen_sdo_write(HCU_NODE_ID,
			mindex, 8,
			data_len,
			&valve->assembly_invert);
}

void hcu_set_boom_lift_params(valve_st *valve) {
	update_valve_params(valve, HCU_BOOM_LIFT_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_BOOM_LIFT_PARAM_TYPE));
}

void hcu_set_boom_fold_params(valve_st *valve) {
	update_valve_params(valve, HCU_BOOM_FOLD_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_BOOM_FOLD_PARAM_TYPE));
}

void hcu_set_boom_rotate_params(valve_st *valve) {
	update_valve_params(valve, HCU_BOOM_ROTATE_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_BOOM_ROTATE_PARAM_TYPE));
}

void hcu_set_boom_telescope_params(valve_st *valve) {
	update_valve_params(valve, HCU_BOOM_TELESCOPE_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_BOOM_TELESCOPE_PARAM_TYPE));
}

void hcu_set_left_leg_params(valve_st *valve) {
	update_valve_params(valve, HCU_LEFT_FOOT_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_LEFT_FOOT_PARAM_TYPE));
}

void hcu_set_right_leg_params(valve_st *valve) {
	update_valve_params(valve, HCU_RIGHT_FOOT_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_RIGHT_FOOT_PARAM_TYPE));
}

void hcu_set_rotator_params(valve_st *valve) {
	update_valve_params(valve, HCU_ROTATOR_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_ROTATOR_PARAM_TYPE));
}

void hcu_set_impl1_params(valve_st *valve) {
	update_valve_params(valve, HCU_IMPL1_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_IMPL1_PARAM_TYPE));
}

void hcu_set_impl2_params(valve_st *valve) {
	update_valve_params(valve, HCU_IMPL2_PARAM_INDEX,
			CANOPEN_TYPE_LEN(HCU_IMPL2_PARAM_TYPE));
}

void hcu_set_implement(hcu_impls_e impl) {
	if (uv_canopen_sdo_write(HCU_NODE_ID, HCU_IMPLEMENT_INDEX, HCU_IMPLEMENT_SUBINDEX,
			CANOPEN_TYPE_LEN(HCU_IMPLEMENT_TYPE), &impl) != ERR_NONE) {
		netdev_set_transmit_failure(this);
	}
}

