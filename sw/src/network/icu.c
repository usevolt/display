/*
 * uw180s.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#include <icu.h>
#include "netdev.h"
#include "main.h"


void icu_init(icu_st *this) {
	netdev_init(this, icu_update);
	netdev_set_node_id(this, ICU_NODE_ID);
	netdev_set_disconnected_type(this, LOG_ICU_DISCONNECTED);
	this->total_current = 0;
	this->length_um = 0;
	this->width_um = 0;
	this->vol_dm3 = 0;
}


void icu_step(icu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}



void icu_update(void *me) {
	// valve settings are updated in network.c if UW180S is selected
	icu_set_len_calib(&dspl.network.icu, dspl.user->uw180s.len_calib);
}


void icu_set_blades_grab_time(icu_st *this, uint16_t value) {
#warning "todo"
}

void icu_set_feed_grab_time(icu_st *this, uint16_t value) {
#warning "todo"
}


void icu_set_len_calib(icu_st *this, uint16_t value) {
	uv_canopen_sdo_write(ICU_NODE_ID, ICU_LEN_CALIB_INDEX,
			ICU_LEN_CALIB_SUBINDEX, CANOPEN_TYPE_LEN(ICU_LEN_CALIB_TYPE),
			&value);
}

void icu_set_target_len_um(icu_st *this, uint32_t value) {
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_TARGET_LEN_UM_INDEX, ICU_TARGET_LEN_UM_SUBINDEX,
			CANOPEN_TYPE_LEN(ICU_TARGET_LEN_UM_TYPE),
			&value);
}

#define this ((icu_st*)me)

void icu_set_bladeopen_params(valve_st *valve) {
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_BLADEOPEN_PARAM_INDEX, 1,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->max_speed_p);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_BLADEOPEN_PARAM_INDEX, 2,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->max_speed_n);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_BLADEOPEN_PARAM_INDEX, 3,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->invert);
}

void icu_set_saw_params(valve_st *valve) {
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_SAW_PARAM_INDEX, 1,
			CANOPEN_TYPE_LEN(ICU_SAW_PARAM_TYPE),
			&valve->max_speed_p);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_SAW_PARAM_INDEX, 2,
			CANOPEN_TYPE_LEN(ICU_SAW_PARAM_TYPE),
			&valve->max_speed_n);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_SAW_PARAM_INDEX, 3,
			CANOPEN_TYPE_LEN(ICU_SAW_PARAM_TYPE),
			&valve->invert);
}

void icu_set_tilt_params(valve_st *valve) {
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_TILT_PARAM_INDEX, 1,
			CANOPEN_TYPE_LEN(ICU_TILT_PARAM_TYPE),
			&valve->max_speed_p);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_TILT_PARAM_INDEX, 2,
			CANOPEN_TYPE_LEN(ICU_TILT_PARAM_TYPE),
			&valve->max_speed_n);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_TILT_PARAM_INDEX, 3,
			CANOPEN_TYPE_LEN(ICU_TILT_PARAM_TYPE),
			&valve->invert);
}

void icu_set_feed_params(valve_st *valve) {
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEED_PARAM_INDEX, 1,
			CANOPEN_TYPE_LEN(ICU_FEED_PARAM_TYPE),
			&valve->max_speed_p);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEED_PARAM_INDEX, 2,
			CANOPEN_TYPE_LEN(ICU_FEED_PARAM_TYPE),
			&valve->max_speed_n);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEED_PARAM_INDEX, 3,
			CANOPEN_TYPE_LEN(ICU_FEED_PARAM_TYPE),
			&valve->invert);

}

void icu_set_feedopen_params(valve_st *valve) {
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEEDOPEN_PARAM_INDEX, 1,
			CANOPEN_TYPE_LEN(ICU_FEEDOPEN_PARAM_TYPE),
			&valve->max_speed_p);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEEDOPEN_PARAM_INDEX, 2,
			CANOPEN_TYPE_LEN(ICU_FEEDOPEN_PARAM_TYPE),
			&valve->max_speed_n);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEEDOPEN_PARAM_INDEX, 3,
			CANOPEN_TYPE_LEN(ICU_FEEDOPEN_PARAM_TYPE),
			&valve->invert);

}

void icu_set_allopen_params(valve_st *valve) {
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_ALLOPEN_PARAM_INDEX, 1,
			CANOPEN_TYPE_LEN(ICU_ALLOPEN_PARAM_TYPE),
			&valve->max_speed_p);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_ALLOPEN_PARAM_INDEX, 2,
			CANOPEN_TYPE_LEN(ICU_ALLOPEN_PARAM_TYPE),
			&valve->max_speed_n);
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_ALLOPEN_PARAM_INDEX, 3,
			CANOPEN_TYPE_LEN(ICU_ALLOPEN_PARAM_TYPE),
			&valve->invert);

}
