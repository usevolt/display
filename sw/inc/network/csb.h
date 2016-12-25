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
#include "netdev.h"


#define CSB_NODE_ID				7
#define CSB_WIPER_SPEED_COUNT	5


typedef struct {
	EXTENDS(netdev_st);
	uint8_t drive_light;
	uint8_t work_light;
	uint8_t wiper;
	uint8_t errors;
} csb_st;



static inline void csb_init(csb_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, CSB_NODE_ID);
}


void csb_step(csb_st *this, unsigned int step_ms);

void csb_update(csb_st *this);


static inline uint8_t csb_get_wiper(csb_st *csb) {
	return csb->wiper;
}

static inline uint8_t csb_get_drive_light(csb_st *csb) {
	return csb->drive_light;
}

static inline uint8_t csb_get_work_light(csb_st *csb) {
	return csb->work_light;
}

/// @brief: Sends the request to CSB to set the drive lights to *value*
void csb_set_drive_light(csb_st *csb, bool value);


/// @brief: Sends the request to CSB to set work lights to *value*
void csb_set_work_light(csb_st *csb, bool value);


#endif /* CSB_H_ */
