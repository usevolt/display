/*
 * uw180s.h
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_CCU_H_
#define NETWORK_CCU_H_


#include "netdev.h"
#include "vehicle.h"
#include "can_ccu.h"

typedef struct {
	EXTENDS(netdev_st);

	uint16_t total_current;
	ccu_gear_e gear;
	uint8_t drivef_comp;
	uint8_t driveb_comp;

} ccu_st;


void ccu_update(void *me);

void ccu_init(ccu_st *this);

void ccu_step(ccu_st *this, unsigned int step_ms);


static inline uint16_t ccu_get_total_current(ccu_st *this) {
	return this->total_current;
}

static inline ccu_gear_e ccu_get_gear(ccu_st *this) {
	return this->gear;
}

void ccu_set_gear(ccu_gear_e gear);

void ccu_set_gear1_params(valve_st *valve);

void ccu_set_gear2_params(valve_st *valve);

void ccu_set_gear3_params(valve_st *valve);

void ccu_set_steer_params(valve_st *valve);

void ccu_set_telescope_params(valve_st *valve);

void ccu_set_cab_rot_params(valve_st *valve);

void ccu_set_impl2_reqs(int8_t ain1_value, int8_t ain2_value);


#endif /* NETWORK_CCU_H_ */
