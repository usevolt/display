/*
 * uw180s.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#include <uw180s_ecu.h>
#include <ecu.h>
#include "main.h"
#include "netdev.h"


void uw180s_ecu_step(uw180s_ecu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);
}


#define this ((uw180s_ecu_st*)me)

void uw180s_ecu_update(void *me) {

	icu_set_wheels_feed_params(dspl.user->uw180s.wheels_feed.max_speed_p,
			dspl.user->uw180s.wheels_feed.max_speed_n, dspl.user->uw180s.wheels_feed.invert);
	uv_rtos_task_delay(10);
	icu_set_delimbers_params(dspl.user->uw180s.delimbers.max_speed_p,
			dspl.user->uw180s.delimbers.max_speed_n, dspl.user->uw180s.delimbers.invert);
	uv_rtos_task_delay(10);
	icu_set_wheels_params(dspl.user->uw180s.wheels.max_speed_p,
			dspl.user->uw180s.wheels.max_speed_n, dspl.user->uw180s.wheels.invert);
	uv_rtos_task_delay(10);
	icu_set_saw_params(dspl.user->uw180s.saw.max_speed_p,
			dspl.user->uw180s.saw.max_speed_n, dspl.user->uw180s.saw.invert);
	uv_rtos_task_delay(10);
	icu_set_tilt_params(dspl.user->uw180s.tilt.max_speed_p,
			dspl.user->uw180s.tilt.max_speed_n, dspl.user->uw180s.tilt.invert);
	int32_t len = (int32_t) dspl.user->uw180s.log_len1 * 10000;
	uv_canopen_sdo_write(0xA, 0x2102, 0, CANOPEN_UNSIGNED32, &len);


}
