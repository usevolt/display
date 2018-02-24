/*
 * csb.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "csb.h"
#include "main.h"


void csb_init(csb_st *this) {
	netdev_init(this, csb_update);
	netdev_set_node_id(this, CSB_NODE_ID);
	netdev_set_disconnected_type(this, LOG_CSB_DISCONNECTED);
	this->read.total_current = 0;
	this->read.wiper_speed = 0;
}


void csb_step(csb_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

}


#define this ((csb_st*)me)
void csb_update(void *me) {
}
#undef this



void csb_set_wiper_speed(csb_st *this, uint8_t value) {
	if (value > CSB_WIPER_MAX_SPEED) {
		value = CSB_WIPER_MAX_SPEED;
	}
	this->read.wiper_speed = value;
	uv_canopen_sdo_write8(CSB_NODE_ID, CSB_WIPER_SPEED_INDEX, CSB_WIPER_SPEED_SUBINDEX, value);
}
