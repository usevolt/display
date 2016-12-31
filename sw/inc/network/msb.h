/*
 * msb.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef MSB_H_
#define MSB_H_

#include <uv_utilities.h>
#include "vehicle.h"
#include "netdev.h"


#define MSB_HEATER_SPEED_COUNT	2


/// @file: Defines the communication interface with Main Supply Board
typedef struct {
	EXTENDS(netdev_st);

	uint8_t fuel_level;
	uint8_t oil_level;
	int8_t oil_temp;
	int8_t motor_temp;
	int16_t rpm;
	int16_t voltage;
	struct {
		uint8_t glow_plugs;
		uint8_t starter;
		uint8_t engine_stop;
		uint8_t crane_light;
		uint8_t camera;
		uint8_t aux;
		uint8_t heater;
		uint8_t oil_cooler;
	} power;
} msb_st;


static inline void msb_init(msb_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, MSB_NODE_ID);
	this->fuel_level = 0;
	this->motor_temp = 0;
	this->oil_level = 0;
	this->oil_temp = 0;
	this->rpm = 0;
	this->voltage = 0;
	this->power.aux = 0;
	this->power.camera = 0;
	this->power.crane_light = 0;
	this->power.engine_stop = 0;
	this->power.glow_plugs = 0;
	this->power.heater = 0;
	this->power.oil_cooler = 0;
	this->power.starter = 0;
}


void msb_step(msb_st *this, unsigned int step_ms);

/// @brief: Download the most recent data to the msb
void msb_update(msb_st *this);


static inline uint8_t msb_get_fuel_level(msb_st *msb) {
	return msb->fuel_level;
}

static inline uint8_t msb_get_oil_level(msb_st *msb) {
	return msb->oil_level;
}

static inline int8_t msb_get_oil_temp(msb_st *msb) {
	return msb->oil_temp;
}

static inline int8_t msb_get_motor_temp(msb_st *msb) {
	return msb->motor_temp;
}

static inline int16_t msb_get_rpm(msb_st *msb) {
	return msb->rpm;
}

static inline int16_t msb_get_voltage(msb_st *msb) {
	return msb->voltage;
}

static inline bool msb_get_aux(msb_st *msb) {
	return msb->power.aux;
}

static inline bool msb_get_camera(msb_st *msb) {
	return msb->power.camera;
}

static inline bool msb_get_crane_light(msb_st *msb) {
	return msb->power.crane_light;
}

static inline bool msb_get_engine_stop(msb_st *msb) {
	return msb->power.engine_stop;
}

static inline bool msb_get_glow_plugs(msb_st *msb) {
	return msb->power.glow_plugs;
}

static inline bool msb_get_heater(msb_st *msb) {
	return msb->power.heater;
}

static inline bool msb_get_oil_cooler(msb_st *msb) {
	return msb->power.oil_cooler;
}

static inline bool msb_get_starter(msb_st *msb) {
	return msb->power.starter;
}

#endif /* MSB_H_ */
