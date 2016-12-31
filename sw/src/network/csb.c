/*
 * csb.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "csb.h"
#include "main.h"


void csb_step(csb_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

}


/// @brief: Sends the request to CSB to set the drive lights to *value*
void csb_set_drive_light(csb_st *csb, bool value) {
	csb->lights.drive_light = value;
	uv_canopen_sdo_message_st msg = {
			.main_index = 0x1100,
			.sub_index = 0,
			.data_length = 1,
			.data_8bit[0] = (value) ? 1 : 0,
			.request = CANOPEN_SDO_CMD_WRITE_1_BYTE,
	};
	uv_canopen_send_sdo(&dspl.canopen, &msg, CSB_NODE_ID);
}

/// @brief: Sends the request to CSB to set work lights to *value*
void csb_set_work_light(csb_st *csb, bool value) {
	csb->lights.work_light = value;
	uv_canopen_sdo_message_st msg = {
			.main_index = 0x1101,
			.sub_index = 0,
			.data_length = 1,
			.data_8bit[0] = (value) ? 1 : 0,
			.request = CANOPEN_SDO_CMD_WRITE_1_BYTE,
	};
	uv_canopen_send_sdo(&dspl.canopen, &msg, CSB_NODE_ID);
}


void csb_update(csb_st *this) {

}
