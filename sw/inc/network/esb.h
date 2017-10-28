/*
 * esb.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef ESB_H_
#define ESB_H_

#include <uv_utilities.h>
#include "vehicle.h"
#include "netdev.h"
#include "can_esb.h"


/// @file: Defines the communication interface with Main Supply Board
typedef struct {
	EXTENDS(netdev_st);

	// READ
	struct {
		uint8_t fuel_level;
		uint8_t oil_level;
		int8_t oil_temp;
		int8_t motor_temp;
		int16_t rpm;
		int16_t voltage;
		uint8_t alt_l;
		uint8_t motor_water;
		uint8_t motor_oil_press;
		uint8_t glow_plugs;
	} read;
} esb_st;


/// @brief: Download the most recent data to the esb
void esb_update(void *me);


void esb_init(esb_st *this);


void esb_step(esb_st *this, unsigned int step_ms);


static inline uint8_t esb_get_fuel_level(esb_st *this) {
	return this->read.fuel_level;
}

static inline uint8_t esb_get_oil_level(esb_st *this) {
	return this->read.oil_level;
}

static inline int8_t esb_get_oil_temp(esb_st *this) {
	return this->read.oil_temp;
}

static inline int8_t esb_get_motor_temp(esb_st *this) {
	return this->read.motor_temp;
}

static inline int16_t esb_get_rpm(esb_st *this) {
	return this->read.rpm;
}

static inline int16_t esb_get_voltage(esb_st *this) {
	return this->read.voltage;
}

static inline uint8_t esb_get_alt_l(esb_st *this) {
	return this->read.alt_l;
}

static inline uint8_t esb_get_motor_water(esb_st *this) {
	return this->read.motor_water;
}

static inline uint8_t esb_get_motor_oil_press(esb_st *this) {
	return this->read.motor_oil_press;
}

static inline uint8_t esb_get_glow_plugs(esb_st *this) {
	return this->read.glow_plugs;
}


#endif /* ESB_H_ */
