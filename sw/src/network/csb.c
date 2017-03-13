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
	if (uv_canopen_sdo_write(CSB_NODE_ID, 0x1100, 0, 1, &value)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

/// @brief: Sends the request to CSB to set work lights to *value*
void csb_set_work_light(csb_st *csb, bool value) {
	csb->write.work_light = value;
	if (uv_canopen_sdo_write(CSB_NODE_ID, 0x1101, 0, 1, &value)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

void csb_set_wiper(csb_st *csb, uint8_t value) {
	csb->write.wiper = value;
	if (uv_canopen_sdo_write(CSB_NODE_ID, 0x1104, 0, 1, &value)) {
		netdev_set_transmit_failure(&dspl.network.csb);
	}
}

#define this ((csb_st*)me)

void csb_update(void *me) {
	csb_set_work_light(this, this->write.work_light);
	csb_set_drive_light(this, this->write.drive_light);
	csb_set_wiper(this, this->write.wiper);
}
