/*
 * esb.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include <esb.h>
#include "main.h"
#include <uv_canopen.h>


void esb_init(esb_st *this) {
	netdev_init(this, esb_update);
	netdev_set_node_id(this, ESB_NODE_ID);
	netdev_set_disconnected_type(this, LOG_ESB_DISCONNECTED);
	this->read.fuel_level = 0;
	this->read.motor_temp = 0;
	this->read.oil_level = 0;
	this->read.oil_temp = 0;
	this->read.rpm = 0;
	this->read.voltage = 0;
	this->read.alt_l = 0;
	this->read.motor_oil_press = 0;
	this->read.motor_water = 0;
	this->read.glow_plugs = 0;

	printf("esb toilc trig: %i\n", dspl.user->oilcooler_trig_temp);
	uv_canopen_sdo_write(ESB_NODE_ID, ESB_OILCOOLER_TRIGGER_INDEX,
			ESB_OILCOOLER_TRIGGER_SUBINDEX, CANOPEN_TYPE_LEN(ESB_OILCOOLER_TRIGGER_TYPE),
			&dspl.user->oilcooler_trig_temp);
}


void esb_step(esb_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

}

#define this ((esb_st*)me)
void esb_update(void *me) {

}
#undef this

