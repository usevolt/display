/*
 * uw180s.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#include "icu.h"
#include "fsb.h"
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
	uv_delay_init(ICU_UPDATE_DELAY_MS, &this->update_delay);
}


void icu_step(icu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

	// update the icu parameters after the ignkey is switched on
	if (fsb_get_ignkey_state(&dspl.network.fsb) != FSB_IGNKEY_STATE_ON) {
		uv_delay_init(ICU_UPDATE_DELAY_MS, &this->update_delay);
	}
	else {
		if (uv_delay(step_ms, &this->update_delay) && !dspl.network.update_disabled) {
			if (hcu_get_implement(&dspl.network.hcu) == HCU_IMPLEMENT_UW180S) {
				icu_update(this);
			}
		}
	}
}



void icu_update(void *me) {
	// valve settings are updated in network.c if UW180S is selected
	icu_set_len_calib(&dspl.network.icu, dspl.user->uw180s.len_calib);
	icu_set_target_len_um(&dspl.network.icu, dspl.user->uw180s.log_len1);
	icu_set_feed_grab_time(&dspl.network.icu, dspl.user->uw180s.roller_grab_time);
	uv_rtos_task_delay(10);
	dspl.user->uw180s.bladesopen.setter(&dspl.user->uw180s.bladesopen);
	dspl.user->uw180s.impl1.setter(&dspl.user->uw180s.impl1);
	dspl.user->uw180s.impl2.setter(&dspl.user->uw180s.impl2);
	dspl.user->uw180s.rotator.setter(&dspl.user->uw180s.rotator);
	dspl.user->uw180s.saw.setter(&dspl.user->uw180s.saw);
	uv_rtos_task_delay(10);
	dspl.user->uw180s.tilt.setter(&dspl.user->uw180s.tilt);
	dspl.user->uw180s.feedopen.setter(&dspl.user->uw180s.feedopen);
	dspl.user->uw180s.feed.setter(&dspl.user->uw180s.feed);
	dspl.user->uw180s.all_open.setter(&dspl.user->uw180s.all_open);
}


void icu_set_blades_grab_time(icu_st *this, uint16_t value) {
}

void icu_set_feed_grab_time(icu_st *this, uint16_t value) {
	uv_canopen_sdo_write(ICU_NODE_ID, ICU_FEED_PARAM_INDEX,
			7, CANOPEN_TYPE_LEN(ICU_FEED_PARAM_TYPE), &value);
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
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_BLADEOPEN_PARAM_INDEX, 6,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->assembly_invert);
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
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_SAW_PARAM_INDEX, 6,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->assembly_invert);
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
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_TILT_PARAM_INDEX, 6,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->assembly_invert);
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
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEED_PARAM_INDEX, 6,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->assembly_invert);

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
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_FEEDOPEN_PARAM_INDEX, 6,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->assembly_invert);

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
	uv_canopen_sdo_write(ICU_NODE_ID,
			ICU_ALLOPEN_PARAM_INDEX, 6,
			CANOPEN_TYPE_LEN(ICU_BLADEOPEN_PARAM_TYPE),
			&valve->assembly_invert);

}
