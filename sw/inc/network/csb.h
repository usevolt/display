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
} csb_st;


void csb_update(void *me);


void csb_init(csb_st *this);


void csb_step(csb_st *this, unsigned int step_ms);


#endif /* CSB_H_ */
