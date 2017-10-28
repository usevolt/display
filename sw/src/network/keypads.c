/*
 * keypads.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "keypads.h"

void keypad_step(keypad_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

	if (this->calib) {
		uv_canopen_sdo_read(this->super.node_id, 0x2120, 3, 2, &this->read.x_calib[0]);
		uv_canopen_sdo_read(this->super.node_id, 0x2120, 4, 2, &this->read.x_calib[1]);
		uv_canopen_sdo_read(this->super.node_id, 0x2120, 2, 2, &this->read.x_calib[2]);
		uv_canopen_sdo_read(this->super.node_id, 0x2121, 3, 2, &this->read.y_calib[0]);
		uv_canopen_sdo_read(this->super.node_id, 0x2121, 4, 2, &this->read.y_calib[1]);
		uv_canopen_sdo_read(this->super.node_id, 0x2121, 2, 2, &this->read.y_calib[2]);
		uv_canopen_sdo_read(this->super.node_id, 0x2122, 3, 2, &this->read.z_calib[0]);
		uv_canopen_sdo_read(this->super.node_id, 0x2122, 4, 2, &this->read.z_calib[1]);
		uv_canopen_sdo_read(this->super.node_id, 0x2122, 2, 2, &this->read.z_calib[2]);
	}
}


void keypad_calib_start(keypad_st *this) {
	this->calib = true;
	keypad_axis_calib_e req = KEYPAD_CALIB_START;
	uv_canopen_sdo_write(this->super.node_id, 0x21F0, 0, 1, &req);
}

void keypad_calib_end(keypad_st *this) {
	this->calib = false;
	keypad_axis_calib_e req = KEYPAD_CALIB_END;
	uv_canopen_sdo_write(this->super.node_id, 0x21F0, 0, 1, &req);
}


#define this ((keypad_st*)me)

void keypad_update(void *me) {

}


