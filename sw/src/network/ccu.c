/*
 * uw180s.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#include <ccu.h>
#include "netdev.h"
#include <uv_rtos.h>


void ccu_init(ccu_st *this) {
	netdev_init(this, ccu_update);
	netdev_set_node_id(this, CCU_NODE_ID);
	netdev_set_disconnected_type(this, LOG_CCU_DISCONNECTED);
	this->total_current = 0;
	this->gear = CCU_GEAR_1;
}


void ccu_step(ccu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}


#define this ((ccu_st*)me)

void ccu_update(void *me) {

}


void ccu_set_gear(ccu_gear_e gear) {
	uv_canopen_sdo_write(CCU_NODE_ID, CCU_GEAR_INDEX,
			CCU_GEAR_SUBINDEX, CANOPEN_TYPE_LEN(CCU_GEAR_TYPE),
			&gear);
}


static void update_valve_params(valve_st *valve, uint16_t mindex, uint8_t sindex, uint8_t data_len) {
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 1,
			data_len,
			&valve->min_speed_p);
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 2,
			data_len,
			&valve->max_speed_p);
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 3,
			data_len,
			&valve->min_speed_n);
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 4,
			data_len,
			&valve->max_speed_n);
	uv_rtos_task_delay(10);
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 5,
			data_len,
			&valve->acc);
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 6,
			data_len,
			&valve->dec);
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 7,
			data_len,
			&valve->invert);
	uv_canopen_sdo_write(CCU_NODE_ID,
			mindex, sindex + 8,
			data_len,
			&valve->assembly_invert);
}

void ccu_set_gear1_params(valve_st *valve) {
	update_valve_params(valve, CCU_DRIVE_PARAM_INDEX, 0,
			CANOPEN_TYPE_LEN(CCU_DRIVE_PARAM_TYPE));
}

void ccu_set_gear2_params(valve_st *valve) {
	update_valve_params(valve, CCU_DRIVE_PARAM_INDEX, 8,
			CANOPEN_TYPE_LEN(CCU_DRIVE_PARAM_TYPE));
}

void ccu_set_gear3_params(valve_st *valve) {
	update_valve_params(valve, CCU_DRIVE_PARAM_INDEX, 16,
			CANOPEN_TYPE_LEN(CCU_DRIVE_PARAM_TYPE));
}

void ccu_set_steer_params(valve_st *valve) {
	update_valve_params(valve, CCU_STEER_PARAM_INDEX, 0,
			CANOPEN_TYPE_LEN(CCU_STEER_PARAM_TYPE));
}

void ccu_set_telescope_params(valve_st *valve) {
	update_valve_params(valve, CCU_TELESCOPE_PARAM_INDEX, 0,
			CANOPEN_TYPE_LEN(CCU_TELESCOPE_PARAM_TYPE));
}

void ccu_set_cab_rot_params(valve_st *valve) {
	update_valve_params(valve, CCU_CABROT_PARAM_INDEX, 0,
			CANOPEN_TYPE_LEN(CCU_CABROT_PARAM_TYPE));
}
