/*
 * uw180s.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#include <uw180s_ecu.h>
#include "netdev.h"


void uw180s_ecu_step(uw180s_ecu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}

void uw180s_ecu_update(uw180s_ecu_st *this) {

}
