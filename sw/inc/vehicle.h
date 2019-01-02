/*
 * vehicle.h
 *
 *  Created on: Nov 1, 2016
 *      Author: usevolt
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_


#include "valve.h"


/// @file: Defines the vehicle dependent settings, such as valves and their
/// default settings





/// @brief: Temperature warning limits
/// Warning will be generated when the value goes over these
#define MOTOR_TEMP_WARNING_LIMIT	96
#define OIL_TEMP_WARNING_LIMIT		80
#define VOLTAGE_WARNING_LIMIT		11800

/// @brief: Fuel & oil level warning limits
/// Warning will be generated when the value goes under these
#define FUEL_LEVEL_WARNING_LIMIT	40
#define OIL_LEVEL_WARNING_LIMIT		40


/// @brief: Defines the maximum and minimum valve current
#define VALVE_MIN_CURRENT_MA		40
#define VALVE_MAX_CURRENT_MA		2000
#define VALVE_ACC_MIN				5
#define VALVE_DEC_MIN				VALVE_ACC_MIN

#define UW180S_VALVE_MIN_SPEED		0
#define UW180S_VALVE_MAX_SPEED		100

#define RPM_MAX						3500
#define RPM_WARNING_LIMIT			3000

#define PRESSURE_MAX				250

#define VOLTAGE_MAX					14000
#define VOLTAGE_MIN					11000

#define UW180S_MB_LEN_CALIB_MAX		300
#define UW180S_MB_VOL_CALIB_MIN		-100
#define UW180S_MB_VOL_CALIB_MAX		100


#define BASE_VALVE_COUNT			12


/// @brief: Structure defining the vehicle's base
/// valve construction and factory values
extern const valve_st vehicle_valves[];



#endif /* VEHICLE_H_ */
