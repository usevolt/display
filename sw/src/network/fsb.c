/*
 * fsb.c
 *
 *  Created on: Oct 25, 2017
 *      Author: usevolt
 */


#include "fsb.h"




void fsb_init(fsb_st *this) {
	netdev_init(this, fsb_update);
	netdev_set_node_id(this, FSB_NODE_ID);
	netdev_set_disconnected_type(this, LOG_FSB_DISCONNECTED);
	this->read.emcy = 0;
	// door and seat switches are active high. They are initialized as 1 for start up
	this->read.doorsw1 = 1;
	this->read.doorsw2 = 1;
	this->read.seatsw = 1;
	this->read.total_current = 0;
	this->read.ignkey = FSB_IGNKEY_STATE_OFF;
	this->read.heater_speed = 0;
}


void fsb_step(fsb_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}


#define this ((fsb_st*) me)
void fsb_update(void *me) {
}
#undef this


void fsb_set_heater_speed(fsb_st *this, uint8_t value) {
	if (value) {
		value = 100;
	}

	this->read.heater_speed = value;
	uv_canopen_sdo_write8(FSB_NODE_ID, FSB_HEATER_SPEED_INDEX,
			FSB_HEATER_SPEED_SUBINDEX, value);
}
