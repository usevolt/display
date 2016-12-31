/*
 * csb.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef CSB_H_
#define CSB_H_


#include <uv_utilities.h>
#include <uv_canopen.h>
#include "vehicle.h"
#include "netdev.h"


#define CSB_WIPER_SPEED_COUNT	5


typedef struct {
	EXTENDS(netdev_st);
	struct {
		uint8_t drive_light;
		uint8_t work_light;
		uint8_t cabin_light;
		uint8_t beacon;
	} lights;
	uint8_t wiper;
	uint8_t errors;
} csb_st;



static inline void csb_init(csb_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, CSB_NODE_ID);
	this->wiper = 0;
	this->errors = 0;
	this->lights.beacon = 0;
	this->lights.cabin_light = 0;
	this->lights.drive_light = 0;
	this->lights.work_light = 0;
}


void csb_step(csb_st *this, unsigned int step_ms);

void csb_update(csb_st *this);


static inline uint8_t csb_get_drive_light(csb_st *csb) {
	return csb->lights.drive_light;
}

static inline uint8_t csb_get_work_light(csb_st *csb) {
	return csb->lights.work_light;
}

static inline uint8_t csb_get_cabin_light(csb_st *csb) {
	return csb->lights.cabin_light;
}

static inline uint8_t csb_get_beacon(csb_st *csb) {
	return csb->lights.beacon;
}

static inline uint8_t csb_get_wiper(csb_st *csb) {
	return csb->wiper;
}

/// @brief: Sends the request to CSB to set the drive lights to *value*
void csb_set_drive_light(csb_st *csb, bool value);


/// @brief: Sends the request to CSB to set work lights to *value*
void csb_set_work_light(csb_st *csb, bool value);


#endif /* CSB_H_ */
