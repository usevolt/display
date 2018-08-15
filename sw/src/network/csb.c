/*
 * csb.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "csb.h"
#include "main.h"
#include <uv_canopen.h>


void csb_step(csb_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

}


/// @brief: Sends the request to CSB to set the drive lights to *value*
void csb_set_drive_light(csb_st *csb, bool value) {
	csb->read.lights.drive_light = value;
	if (uv_canopen_sdo_write(CSB_NODE_ID, CSB_DRIVE_LIGHT_STATUS_INDEX,
			CSB_DRIVE_LIGHT_STATUS_SUBINDEX, 1, &value)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

/// @brief: Sends the request to CSB to set work lights to *value*
void csb_set_work_light(csb_st *csb, bool value) {
	csb->read.lights.work_light = value;
	if (uv_canopen_sdo_write(CSB_NODE_ID, CSB_WORK_LIGHT_STATUS_INDEX,
			CSB_WORK_LIGHT_STATUS_SUBINDEX, 1, &value)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

void csb_set_wiper(csb_st *csb, uint8_t value) {
	csb->read.wiper = value;
	if (uv_canopen_sdo_write(CSB_NODE_ID, 0x1104, 0, 1, &value)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

#define this ((csb_st*)me)

void csb_update(void *me) {
	csb_set_work_light(this, this->read.lights.work_light);
	csb_set_drive_light(this, this->read.lights.drive_light);
	csb_set_wiper(this, this->read.wiper);
}
