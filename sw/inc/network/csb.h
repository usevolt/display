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
#include <can_csb.h>
#include "vehicle.h"
#include "netdev.h"



typedef struct {
	EXTENDS(netdev_st);

	struct {
		uint16_t total_current;
		uint8_t wiper_speed;
	} read;
} csb_st;


void csb_update(void *me);


void csb_init(csb_st *this);


void csb_step(csb_st *this, unsigned int step_ms);

static inline uint16_t csb_get_total_current(csb_st *this) {
	return this->read.total_current;
}

static inline uint8_t csb_get_wiper_speed(csb_st *this) {
	return this->read.wiper_speed;
}

void csb_set_wiper_speed(csb_st *this, uint8_t value);

#endif /* CSB_H_ */
