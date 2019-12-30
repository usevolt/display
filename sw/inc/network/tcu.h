/*
 * uw180s.h
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_TCU_H_
#define NETWORK_TCU_H_


#include "netdev.h"
#include "vehicle.h"
#include "can_tcu.h"

typedef struct {
	EXTENDS(netdev_st);

} tcu_st;


void tcu_update(void *me);

void tcu_init(tcu_st *this);

void tcu_step(tcu_st *this, unsigned int step_ms);


void tcu_set_drive_params(valve_st *valve);

void tcu_set_telescope_params(valve_st *valve);


#endif /* NETWORK_TCU_H_ */
