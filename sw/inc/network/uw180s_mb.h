/*
 * uw180s_mb.h
 *
 *  Created on: Dec 26, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_UW180S_MB_H_
#define NETWORK_UW180S_MB_H_

#include <uv_utilities.h>
#include "netdev.h"
#include "vehicle.h"



typedef struct {
	EXTENDS(netdev_st);

	int32_t length;
	int32_t volume;
	int32_t width;

} mb_st;


static inline void mb_init(mb_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, UW180S_MB_NODE_ID);
	this->length = 0;
	this->volume = 0;
	this->width = 0;
}



static inline int32_t mb_get_length(mb_st *this) {
	return this->length;
}

static inline int32_t mb_get_volume(mb_st *this) {
	return this->volume;
}

static inline int32_t mb_get_width(mb_st *this) {
	return this->width;
}


void mb_step(mb_st *this, uint16_t step_ms);


void mb_update(mb_st *this);


#endif /* NETWORK_UW180S_MB_H_ */
