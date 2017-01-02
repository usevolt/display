/*
 * uw180s.h
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_UW180S_ECU_H_
#define NETWORK_UW180S_ECU_H_


#include "netdev.h"
#include "vehicle.h"

typedef struct {
	EXTENDS(netdev_st);


} uw180s_ecu_st;


void uw180s_ecu_update(void *me);


static inline void uw180s_ecu_init(uw180s_ecu_st *this) {
	netdev_init(this, uw180s_ecu_update);
	netdev_set_node_id(this, UW180S_ECU_NODE_ID);
}


void uw180s_ecu_step(uw180s_ecu_st *this, unsigned int step_ms);




#endif /* NETWORK_UW180S_ECU_H_ */
