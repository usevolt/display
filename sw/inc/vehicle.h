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


#define LKEYPAD_NODE_ID			3
#define RKEYPAD_NODE_ID			4
#define MSB_NODE_ID				6
#define CSB_NODE_ID				7
#define ECU_NODE_ID				0x10
#define PEDAL_NODE_ID			0x1E
#define UW180S_ECU_NODE_ID		0xA
#define UW180S_MB_NODE_ID		0xD




/// @brief: Temperature warning limits
/// Warning will be generated when the value goes over these
#define MOTOR_TEMP_WARNING_LIMIT	90
#define OIL_TEMP_WARNING_LIMIT		75
#define VOLTAGE_WARNING_LIMIT		11800

/// @brief: Fuel & oil level warning limits
/// Warning will be generated when the value goes under these
#define FUEL_LEVEL_WARNING_LIMIT	40
#define OIL_LEVEL_WARNING_LIMIT		40


/// @brief: Defines the maximum and minimum valve current
#define VALVE_MIN_CURRENT_MA		100
#define VALVE_MAX_CURRENT_MA		1000

#define RPM_MAX						3500
#define RPM_WARNING_LIMIT			3000

#define PRESSURE_MAX				250

#define VOLTAGE_MAX					15000
#define VOLTAGE_MIN					10000

#define UW180S_MB_LEN_CALIB_MAX		300
#define UW180S_MB_VOL_CALIB_MIN		-100
#define UW180S_MB_VOL_CALIB_MAX		100


// a work around for eclipse cdt code analysis bug in project symbols.
// All project symbols are parsed into empty symbols. Thus, this
// replaces them with the right values.
#if defined(FM)
#undef FM
#define FM 1
#elif defined(LM)
#undef LM
#define LM 1
#endif


/// @brief: Defines the vehicle's base valve count. Base valve settings
/// are shown on "valve configuration"-screen
#if FM
#define BASE_VALVE_COUNT			7
#elif LM
#define BASE_VALVE_COUNT			11
#endif

/// @brief: Vehicle's implement valve count. Implement valve settings
/// are shown on "implement valve configuration"-screen
#define IMPLEMENT_VALVE_COUNT		3

/// @brief: Amount of Usewood implements
#define UW_IMPLEMENT_COUNT			3

/// @brief: Defines the available implements
enum {
	IMPL_UW180S = 0,
	IMPL_UW100,
	IMPL_UW50,
	IMPL_COUNT
};
typedef uint8_t impl_type_e;

/// @brief: Structure defining the vehicle's base
/// valve construction and factory values
extern const valve_st vehicle_valves[];



#endif /* VEHICLE_H_ */
