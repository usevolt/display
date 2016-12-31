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


static inline void uw180s_ecu_init(uw180s_ecu_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, UW180S_ECU_NODE_ID);
}


void uw180s_ecu_step(uw180s_ecu_st *this, unsigned int step_ms);

void uw180s_ecu_update(uw180s_ecu_st *this);



#endif /* NETWORK_UW180S_ECU_H_ */
