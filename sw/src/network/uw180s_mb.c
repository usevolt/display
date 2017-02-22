/*
 * uw180s_mb.c
 *
 *  Created on: Dec 26, 2016
 *      Author: usevolt
 */


#include "uw180s_mb.h"
#include "main.h"


void mb_step(mb_st *this, uint16_t step_ms) {
	if (dspl.user->uw180s.mb_enabled) {
		netdev_step(this, step_ms);
	}

}

#define this ((mb_st*)me)

void mb_update(void *me) {

}
