/*
 * msb.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "msb.h"
#include "main.h"
#include <uv_canopen.h>


void msb_step(msb_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

}

#define this ((msb_st*)me)

void msb_update(void *me) {
	msb_set_heater(this, this->write.heater);
	msb_set_crane_light(this, this->write.crane_light);
}



void msb_set_heater(void *me, uint8_t value) {
	this->write.heater = value;
	if (uv_canopen_sdo_write(CANOPEN_SDO_CMD_WRITE_1_BYTE, this->super.node_id,
			0x1101, 0, this->write.heater * 2)) {
		netdev_set_transmit_failure(this);
	}

}

void msb_set_crane_light(void *me, bool value) {
	this->write.crane_light = value;
	if (uv_canopen_sdo_write(CANOPEN_SDO_CMD_WRITE_1_BYTE, this->super.node_id,
			0x1102, 0, this->write.crane_light)) {
		netdev_set_transmit_failure(this);
	}
}
