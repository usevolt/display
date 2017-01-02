/*
 * uw180s_mb.c
 *
 *  Created on: Dec 26, 2016
 *      Author: usevolt
 */


#include "uw180s_mb.h"


void mb_step(mb_st *this, uint16_t step_ms) {
	netdev_step(this, step_ms);


}

#define this ((mb_st*)me)

void mb_update(void *me) {

}
