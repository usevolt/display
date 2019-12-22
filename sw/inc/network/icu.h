/*
 * uw180s.h
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_ICU_H_
#define NETWORK_ICU_H_


#include "netdev.h"
#include "vehicle.h"
#include "can_icu.h"

#define ICU_UPDATE_DELAY_MS		2000

typedef struct {
	EXTENDS(netdev_st);

	uint16_t total_current;
	int32_t length_um;
	int32_t width_mm;
	int32_t vol_dm3;
	int update_delay;
} icu_st;


void icu_update(void *me);


void icu_init(icu_st *this);


void icu_step(icu_st *this, unsigned int step_ms);

static inline uint16_t icu_get_total_current(icu_st *this) {
	return this->total_current;
}

static inline int32_t icu_get_length_um(icu_st *this) {
	return this->length_um;
}

static inline int32_t icu_get_width_mm(icu_st *this) {
	return this->width_mm;
}

static inline int32_t icu_get_vol_dm3(icu_st *this) {
	return this->vol_dm3;
}

void icu_set_blades_grab_time(icu_st *this, uint16_t value);

void icu_set_feed_grab_time(icu_st *this, uint16_t value);

void icu_set_tiltfloat_enable(icu_st *this, uint8_t value);

void icu_set_tilt_onthumb(icu_st *this, uint8_t value);

void icu_set_len_calib(icu_st *this, uint16_t value);

void icu_set_target_len_um(icu_st *this, uint32_t value);

void icu_set_bladeopen_params(valve_st *valve);

void icu_set_saw_params(valve_st *valve);

void icu_set_tilt_params(valve_st *valve);

void icu_set_feed_params(valve_st *valve);

void icu_set_feedopen_params(valve_st *valve);

void icu_set_allopen_params(valve_st *valve);

void icu_width_calib_max(void);

void icu_width_calib_min(void);

void icu_set_width_calib_max_mm(uint16_t value_mm);

void icu_set_width_calib_min_mm(uint16_t value_mm);

#endif /* NETWORK_ICU_H_ */
