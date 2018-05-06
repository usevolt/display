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
	msb_set_heater(this, msb_get_heater(&dspl.network.msb));
	msb_set_crane_light(this, this->read.power.crane_light);
}



void msb_set_heater(void *me, uint8_t value) {
	if (value) {
		value = 2;
	}
	this->read.heater = value;
	if (uv_canopen_sdo_write(this->super.node_id,
			0x1101, 0, 1, &value)) {
		netdev_set_transmit_failure(this);
	}

}

void msb_set_crane_light(void *me, bool value) {
	this->read.power.crane_light = value;
	if (uv_canopen_sdo_write(this->super.node_id,
			0x1102, 0, 1, &value)) {
		netdev_set_transmit_failure(this);
	}
}

void msb_set_horn(void *me, bool value) {
	if (value != this->horn) {
		uv_canopen_sdo_write(this->super.node_id,
				0x1103, 0, 1, &value);
		this->horn = value;
	}
}