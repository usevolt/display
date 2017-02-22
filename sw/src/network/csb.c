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
	csb->write.drive_light = value;
	uv_canopen_sdo_message_st msg = {
			.main_index = 0x1100,
			.sub_index = 0,
			.data_length = 1,
			.data_8bit[0] = (value) ? 1 : 0,
			.request = CANOPEN_SDO_CMD_WRITE_1_BYTE,
	};
	if (uv_canopen_send_sdo(&msg, CSB_NODE_ID)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

/// @brief: Sends the request to CSB to set work lights to *value*
void csb_set_work_light(csb_st *csb, bool value) {
	csb->write.work_light = value;
	uv_canopen_sdo_message_st msg = {
			.main_index = 0x1101,
			.sub_index = 0,
			.data_length = 1,
			.data_8bit[0] = (value) ? 1 : 0,
			.request = CANOPEN_SDO_CMD_WRITE_1_BYTE,
	};
	if (uv_canopen_send_sdo(&msg, CSB_NODE_ID)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

void csb_set_wiper(csb_st *csb, uint8_t value) {
	csb->write.wiper = value;
	uv_canopen_sdo_message_st msg = {
			.main_index = 0x1102,
			.sub_index = 0,
			.data_length = 1,
			.data_8bit[0] = value,
			.request = CANOPEN_SDO_CMD_WRITE_1_BYTE,
	};
	if (uv_canopen_send_sdo(&msg, CSB_NODE_ID)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

#define this ((csb_st*)me)

void csb_update(void *me) {
	csb_set_work_light(this, this->write.work_light);
	csb_set_drive_light(this, this->write.drive_light);
	csb_set_wiper(this, this->write.wiper);
}
