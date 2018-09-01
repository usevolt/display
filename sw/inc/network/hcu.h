/*
 * uw180s.h
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_HCU_H_
#define NETWORK_HCU_H_


#include "netdev.h"
#include "vehicle.h"
#include "can_hcu.h"

typedef struct {
	EXTENDS(netdev_st);

	uint16_t total_current;
	hcu_impls_e implement;
	uint16_t pressure;

} hcu_st;


void hcu_update(void *me);


void hcu_init(hcu_st *this);


void hcu_step(hcu_st *this, unsigned int step_ms);


static inline uint16_t hcu_get_total_current(hcu_st *this) {
	return this->total_current;
}

static inline hcu_impls_e hcu_get_implement(hcu_st *this) {
	return this->implement;
}

static inline uint16_t hcu_get_pressure(hcu_st *this) {
	return this->pressure;
}


void hcu_set_boom_lift_params(valve_st *valve);

void hcu_set_boom_fold_params(valve_st *valve);

void hcu_set_boom_rotate_params(valve_st *valve);

void hcu_set_boom_telescope_params(valve_st *valve);

void hcu_set_left_leg_params(valve_st *valve);

void hcu_set_right_leg_params(valve_st *valve);

void hcu_set_rotator_params(valve_st *valve);

void hcu_set_impl1_params(valve_st *valve);

void hcu_set_impl2_params(valve_st *valve);

void hcu_set_implement(hcu_impls_e impl);


#endif /* NETWORK_HCU_H_ */
