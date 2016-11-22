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
#define MOTOR_TEMP_WARNING_LIMIT	75
#define OIL_TEMP_WARNING_LIMIT		75

/// @brief: Fule & oil level warning limits
/// Warning will be generated when the value goes under these
#define FUEL_LEVEL_WARNING_LIMIT	30
#define OIL_LEVEL_WARNING_LIMIT		30


/// @brief: Defines the maximum and minimum valve current
#define VALVE_MIN_CURRENT_MA		0
#define VALVE_MAX_CURRENT_MA		1000


/// @brief: Defines the vehicle's base valve count. Base valve settings
/// are shown on "valve configuration"-screen
#define BASE_VALVE_COUNT			7

/// @brief: Vehicle's implement valve count. Implement valve settings
/// are shown on "implement valve configuration"-screen
#define IMPLEMENT_VALVE_COUNT		3

/// @brief: Describes the generic implement count
#define GENERIC_IMPLEMENT_COUNT		2

/// @brief: Structure defining the vehicle's base
/// valve construction and factory values
extern const valve_st vehicle_valves[];





#endif /* VEHICLE_H_ */
