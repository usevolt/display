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

}

#define this ((ecu_st*)me)

void ecu_update(void *me) {
	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		dspl.user->base_valves[i].setter(&dspl.user->base_valves[i]);
		uv_rtos_task_delay(10);
	}
	ecu_set_engine_power_usage(dspl.user->engine_power_usage);
	ecu_set_implement(dspl.user->active_implement);

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
	ecu_set_uw50_saw_params(dspl.user->uw50.saw.max_speed_p,
			dspl.user->uw50.saw.max_speed_n, dspl.user->uw50.saw.acc,
			dspl.user->uw50.saw.dec, dspl.user->uw50.saw.invert);
	ecu_set_uw50_tilt_params(dspl.user->uw50.tilt.max_speed_p,
			dspl.user->uw50.tilt.max_speed_n, dspl.user->uw50.tilt.acc,
			dspl.user->uw50.tilt.dec, dspl.user->uw50.tilt.invert);
}




void ecu_set_boom_lift_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2000, 1, valve->max_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2000, 2, valve->min_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2000, 3, valve->max_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2000, 4, valve->min_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2000, 5, valve->acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2000, 6, valve->dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2000, 7, valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_boom_fold_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2001, 1, valve->max_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2001, 2, valve->min_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2001, 3, valve->max_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2001, 4, valve->min_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2001, 5, valve->acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2001, 6, valve->dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2001, 7, valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_boom_rotate_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2002, 1, valve->max_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2002, 2, valve->min_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2002, 3, valve->max_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2002, 4, valve->min_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2002, 5, valve->acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2002, 6, valve->dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2002, 7, valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_drive_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2003, 1, valve->max_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2003, 2, valve->min_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2003, 3, valve->max_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2003, 4, valve->min_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2003, 5, valve->acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2003, 6, valve->dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2003, 7, valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_steer_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2004, 1, valve->max_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2004, 2, valve->min_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2004, 3, valve->max_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2004, 4, valve->min_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2004, 5, valve->acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2004, 6, valve->dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2004, 7, valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_left_leg_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2005, 1, valve->max_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2005, 2, valve->min_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2005, 3, valve->max_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2005, 4, valve->min_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2005, 5, valve->acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2005, 6, valve->dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2005, 7, valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_right_leg_params(valve_st *valve) {
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2006, 1, valve->max_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2006, 2, valve->min_speed_p));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2006, 3, valve->max_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2006, 4, valve->min_speed_n));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2006, 5, valve->acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2006, 6, valve->dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2006, 7, valve->invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_engine_power_usage(uint16_t value) {
	if ((uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2200, 0, value))) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_implement(uint8_t implement) {
	if ((uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2201, 0, implement))) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}



void ecu_set_uw180s_wheels_feed_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	dspl.user->uw180s.wheels_feed.max_speed_p = speed_f;
	dspl.user->uw180s.wheels_feed.max_speed_n = speed_b;
	dspl.user->uw180s.wheels_feed.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2011, 1, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2011, 2, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2013, 1, invert));
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
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2011, 7, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2011, 8, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2013, 3, invert));
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
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2012, 1, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2012, 2, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2013, 2, invert));
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
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2012, 3, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2012, 4, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2013, 4, invert));
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
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2011, 5, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2011, 6, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2013, 5, invert));
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
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2012, 5, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2012, 6, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2013, 6, invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw50_saw_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	dspl.user->uw50.saw.max_speed_p = speed_f;
	dspl.user->uw50.saw.max_speed_n = speed_b;
	dspl.user->uw50.saw.invert = invert;
	uv_errors_e e = ERR_NONE;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2030, 1, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2030, 2, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2030, 3, acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2030, 4, dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2030, 5, invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}

void ecu_set_uw50_tilt_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	uv_errors_e e = ERR_NONE;
	dspl.user->uw50.tilt.max_speed_p = speed_f;
	dspl.user->uw50.tilt.max_speed_n = speed_b;
	dspl.user->uw50.tilt.invert = invert;
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2031, 1, speed_f));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2031, 2, speed_b));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2031, 3, acc));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES,
			ECU_NODE_ID, 0x2031, 4, dec));
	e |= (uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE,
			ECU_NODE_ID, 0x2031, 5, invert));
	if (e) {
		netdev_set_transmit_failure(&dspl.network.ecu);
	}
}
