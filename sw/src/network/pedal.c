/*
 * pedal.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "pedal.h"


void pedal_step(pedal_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}

#define this ((pedal_st*)me)

void pedal_update(void *me) {

}
