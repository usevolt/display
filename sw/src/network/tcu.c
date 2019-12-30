/*
 * uw180s.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#include <tcu.h>
#include <uv_rtos.h>
#include "netdev.h"
#include "main.h"


void tcu_init(tcu_st *this) {
	netdev_init(this, tcu_update);
	netdev_set_node_id(this, TCU_NODE_ID);
	netdev_set_disconnected_type(this, LOG_CCU_DISCONNECTED);
}


void tcu_step(tcu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}


#define this ((tcu_st*)me)

void tcu_update(void *me) {
	// note: No need to update valve settings,
	// they are already updated in network.c
}




static void update_valve_params(valve_st *valve, uint16_t mindex, uint8_t sindex, uint8_t data_len) {
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 1,
			data_len,
			&valve->min_speed_p);
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 2,
			data_len,
			&valve->max_speed_p);
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 3,
			data_len,
			&valve->min_speed_n);
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 4,
			data_len,
			&valve->max_speed_n);
	uv_rtos_task_delay(10);
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 5,
			data_len,
			&valve->acc);
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 6,
			data_len,
			&valve->dec);
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 7,
			data_len,
			&valve->invert);
	uv_canopen_sdo_write(TCU_NODE_ID,
			mindex, sindex + 8,
			data_len,
			&valve->assembly_invert);
}


void tcu_set_drive_params(valve_st *valve) {
	update_valve_params(valve, TCU_DRIVE_PARAM_INDEX, 0,
			CANOPEN_TYPE_LEN(TCU_DRIVE_PARAM_TYPE));
}

void tcu_set_telescope_params(valve_st *valve) {
	update_valve_params(valve, TCU_TELESCOPE_PARAM_INDEX, 0,
			CANOPEN_TYPE_LEN(TCU_TELESCOPE_PARAM_TYPE));
}

