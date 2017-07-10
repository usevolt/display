/*
 * ecu.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "ecu.h"
#include "main.h"






void ecu_step(ecu_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

	if (this->legs_down_warning && (!this->read.legs_down)) {
		log_ack_type(LOG_LEGS_DOWN);
	}
}

void ecu_emcy(ecu_st *this, const canopen_emcy_msg_st *emcy) {
	if ((emcy->error_code == CANOPEN_EMCY_DEVICE_SPECIFIC) &&
			(emcy->data == EMCY_ECU_LEGS_DOWN)) {
		log_add(LOG_LEGS_DOWN, 0);
		this->legs_down_warning = true;
	}
}


#define this ((ecu_st*)me)

void ecu_update(void *me) {
	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		dspl.user->base_valves[i].setter(&dspl.user->base_valves[i]);
		uv_rtos_task_delay(10);
	}
	ecu_set_engine_power_usage(dspl.user->engine_power_usage);
	ecu_set_implement(dspl.user->active_implement);
	ecu_set_gear(ecu_get_gear(&dspl.network.ecu));

	uv_rtos_task_delay(10);
	ecu_set_uw180s_delimbers_params(dspl.user->uw180s.delimbers.max_speed_p,
			dspl.user->uw180s.delimbers.max_speed_n,
			dspl.user->uw180s.delimbers.invert);
	ecu_set_uw180s_rotator_params(dspl.user->uw180s.rotator.max_speed_p,
			dspl.user->uw180s.rotator.max_speed_n,
			dspl.user->uw180s.rotator.invert);
	uv_rtos_task_delay(10);
	ecu_set_uw180s_saw_params(dspl.user->uw180s.saw.max_speed_p,
			dspl.user->uw180s.saw.max_speed_n,
			dspl.user->uw180s.saw.invert);
	ecu_set_uw180s_tilt_params(dspl.user->uw180s.tilt.max_speed_p,
			dspl.user->uw180s.tilt.max_speed_n,
			dspl.user->uw180s.tilt.invert);
	uv_rtos_task_delay(10);
	ecu_set_uw180s_wheels_feed_params(dspl.user->uw180s.wheels_feed.max_speed_p,
			dspl.user->uw180s.wheels_feed.max_speed_n,
			dspl.user->uw180s.wheels_feed.invert);
	ecu_set_uw180s_wheels_params(dspl.user->uw180s.wheels.max_speed_p,
			dspl.user->uw180s.wheels.max_speed_n,
			dspl.user->uw180s.wheels.invert);
	uv_rtos_task_delay(10);
	ecu_set_uw100_open_params(dspl.user->uw100.open.max_speed_p,
			dspl.user->uw100.open.max_speed_n,
			dspl.user->uw100.open.acc, dspl.user->uw100.open.dec,
			dspl.user->uw100.open.invert);
	ecu_set_uw100_rotator_params(dspl.user->uw100.rotator.max_speed_p,
			dspl.user->uw100.rotator.max_speed_n,
			dspl.user->uw100.rotator.acc, dspl.user->uw100.rotator.dec,
			dspl.user->uw100.rotator.invert);
	uv_rtos_task_delay(10);
	ecu_set_uw50_saw_params(dspl.user->uw50.saw.max_speed_p,
			dspl.user->uw50.saw.max_speed_n, dspl.user->uw50.saw.acc,
			dspl.user->uw50.saw.dec, dspl.user->uw50.saw.invert);
	ecu_set_uw50_tilt_params(dspl.user->uw50.tilt.max_speed_p,
			dspl.user->uw50.tilt.max_speed_n, dspl.user->uw50.tilt.acc,
			dspl.user->uw50.tilt.dec, dspl.user->uw50.tilt.invert);
}




void ecu_set_boom_lift_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(ECU_NODE_ID, 0x2000, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2000, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2000, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2000, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write(ECU_NODE_ID, 0x2000, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2000, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2000, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_boom_fold_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2001, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2001, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2001, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2001, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2001, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2001, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2001, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_boom_rotate_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2002, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2002, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2002, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2002, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2002, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2002, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2002, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

#if FM

void ecu_set_drive_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	valve_st v = *valve;
	v.max_speed_n *= 2;
	v.max_speed_p *= 2;
	v.min_speed_n *= 2;
	v.min_speed_p *= 2;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 1, 2, &v.max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 2, 2, &v.min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 3, 2, &v.max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 4, 2, &v.min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 5, 2, &v.acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 6, 2, &v.dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 7, 1, &v.invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_steer_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

#elif LM

void ecu_set_drivefront_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	valve_st v = *valve;
	v.max_speed_n *= 2;
	v.max_speed_p *= 2;
	v.min_speed_n *= 2;
	v.min_speed_p *= 2;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 1, 2, &v.max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 2, 2, &v.min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 3, 2, &v.max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 4, 2, &v.min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 5, 2, &v.acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 6, 2, &v.dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 7, 1, &v.invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_steerfront_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_driveback_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_steerback_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2008, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2008, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2008, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2008, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2008, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2008, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2008, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_boom_telescope_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_cab_rot_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

#elif CM

void ecu_set_drivefront_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	valve_st v = *valve;
	v.max_speed_n *= 2;
	v.max_speed_p *= 2;
	v.min_speed_n *= 2;
	v.min_speed_p *= 2;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 1, 2, &v.max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 2, 2, &v.min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 3, 2, &v.max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 4, 2, &v.min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 5, 2, &v.acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 6, 2, &v.dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2003, 7, 1, &v.invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_steer_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2004, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_driveback_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2007, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_telescope_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200B, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200B, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200B, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200B, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200B, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200B, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200B, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_boom_telescope_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2009, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_cab_rot_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x200A, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

#endif

void ecu_set_left_leg_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2005, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2005, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2005, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2005, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2005, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2005, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2005, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_right_leg_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2006, 1, 2, &valve->max_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2006, 2, 2, &valve->min_speed_p));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2006, 3, 2, &valve->max_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2006, 4, 2, &valve->min_speed_n));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2006, 5, 2, &valve->acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2006, 6, 2, &valve->dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2006, 7, 1, &valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_engine_power_usage(uint16_t value) {
	if ((uv_canopen_sdo_write( ECU_NODE_ID, 0x2200, 0, 2, &value))) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_implement(uint8_t implement) {
	dspl.network.ecu.read.implement = implement;
	if ((uv_canopen_sdo_write( ECU_NODE_ID, 0x2201, 0, 1, &implement))) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_gear(uint8_t gear) {
	dspl.network.ecu.read.gear = gear;
	if ((uv_canopen_sdo_write( ECU_NODE_ID, 0x2202, 0, 1, &gear))) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}




void ecu_set_uw180s_wheels_feed_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	dspl.user->uw180s.wheels_feed.max_speed_p = speed_f;
	dspl.user->uw180s.wheels_feed.max_speed_n = speed_b;
	dspl.user->uw180s.wheels_feed.invert = invert;
	uv_errors_e e = ERR_NONE;
	speed_f *= 2;
	speed_b *= 2;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2011, 1, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2011, 2, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2013, 1, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw180s_delimbers_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	dspl.user->uw180s.delimbers.max_speed_p = speed_f;
	dspl.user->uw180s.delimbers.max_speed_n = speed_b;
	dspl.user->uw180s.delimbers.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2011, 7, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2011, 8, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2013, 3, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw180s_wheels_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	dspl.user->uw180s.wheels.max_speed_p = speed_f;
	dspl.user->uw180s.wheels.max_speed_n = speed_b;
	dspl.user->uw180s.wheels.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2012, 1, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2012, 2, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2013, 2, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw180s_saw_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	dspl.user->uw180s.saw.max_speed_p = speed_f;
	dspl.user->uw180s.saw.max_speed_n = speed_b;
	dspl.user->uw180s.saw.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2012, 3, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2012, 4, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2013, 4, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw180s_tilt_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	dspl.user->uw180s.tilt.max_speed_p = speed_f;
	dspl.user->uw180s.tilt.max_speed_n = speed_b;
	dspl.user->uw180s.tilt.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2011, 5, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2011, 6, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2013, 5, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw180s_rotator_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	dspl.user->uw180s.rotator.max_speed_p = speed_f;
	dspl.user->uw180s.rotator.max_speed_n = speed_b;
	dspl.user->uw180s.rotator.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2012, 5, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2012, 6, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2013, 6, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw180s_log_length(uint16_t value) {
	if (uv_canopen_sdo_write(ECU_NODE_ID, 0x2010, 8, 2, &value)) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}


void ecu_set_uw100_open_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	dspl.user->uw100.open.max_speed_p = speed_f;
	dspl.user->uw100.open.max_speed_n = speed_b;
	dspl.user->uw100.open.acc = acc;
	dspl.user->uw100.open.dec = dec;
	dspl.user->uw100.open.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2020, 1, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2020, 2, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2020, 3, 2, &acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2020, 4, 2, &dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2020, 5, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}


void ecu_set_uw100_rotator_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	dspl.user->uw100.rotator.max_speed_p = speed_f;
	dspl.user->uw100.rotator.max_speed_n = speed_b;
	dspl.user->uw100.rotator.acc = acc;
	dspl.user->uw100.rotator.dec = dec;
	dspl.user->uw100.rotator.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2021, 1, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2021, 2, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2021, 3, 2, &acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2021, 4, 2, &dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2021, 5, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw50_saw_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	dspl.user->uw50.saw.max_speed_p = speed_f;
	dspl.user->uw50.saw.max_speed_n = speed_b;
	dspl.user->uw50.saw.acc = acc;
	dspl.user->uw50.saw.dec = dec;
	dspl.user->uw50.saw.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2030, 1, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2030, 2, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2030, 3, 2, &acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2030, 4, 2, &dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2030, 5, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw50_tilt_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	uv_errors_e e = ERR_NONE;
	dspl.user->uw50.tilt.max_speed_p = speed_f;
	dspl.user->uw50.tilt.max_speed_n = speed_b;
	dspl.user->uw50.tilt.acc = acc;
	dspl.user->uw50.tilt.dec = dec;
	dspl.user->uw50.tilt.invert = invert;
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2031, 1, 2, &speed_f));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2031, 2, 2, &speed_b));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2031, 3, 2, &acc));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2031, 4, 2, &dec));
	e |= (uv_canopen_sdo_write( ECU_NODE_ID, 0x2031, 5, 1, &invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}


void ecu_save_params() {
	uint8_t c[4] = {
			's', 'a', 'v', 'e'
	};
	if (uv_canopen_sdo_write(ECU_NODE_ID, 0x1010, 1, 4, ((uint32_t*)(c)))) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}
