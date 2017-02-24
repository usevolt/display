/*
 * uw180s_mb.c
 *
 *  Created on: Dec 26, 2016
 *      Author: usevolt
 */


#include "uw180s_mb.h"
#include "main.h"


void mb_step(mb_st *this, uint16_t step_ms) {
	if (dspl.user->uw180s.mb_enabled) {
		netdev_step(this, step_ms);
	}

}

void mb_set_length_calib(mb_st *this, int16_t value) {
	// length calibration is shared across the users
	for (int16_t i = 0; i < uv_vector_size(&dspl.users); i++) {
		((userdata_st*) uv_vector_at(&dspl.users, i))->uw180s.len_calib = value;
	}
	if (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, this->super.node_id,
			0x2007, 0, value)) {
		netdev_set_transmit_failure(this);
	}
}

void mb_set_vol_calib(mb_st *this, int16_t value) {
	// vol calibration is shared across the users
	for (int16_t i = 0; i < uv_vector_size(&dspl.users); i++) {
		((userdata_st*) uv_vector_at(&dspl.users, i))->uw180s.vol_calib = value;
	}
	if (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, this->super.node_id,
			0x2008, 0, value)) {
		netdev_set_transmit_failure(this);
	}
}


#define this ((mb_st*)me)

void mb_update(void *me) {
	mb_set_length_calib(this, dspl.user->uw180s.len_calib);
}




