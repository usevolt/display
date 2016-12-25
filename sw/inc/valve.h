/*
 * valve.h
 *
 *  Created on: Nov 1, 2016
 *      Author: usevolt
 */

#ifndef VALVE_H_
#define VALVE_H_

#include <stdint.h>
#include <stdbool.h>
#include <uv_canopen.h>


/// @brief: Defines the datatype for individual hydraulic valves




/// @brief: Struct for hydraulic valve settings
typedef struct valve_st {
	/// @brief: valve name
	const char *name;
	/// @brief: Pointer to a function which will apply the valve settings
	/// over the can bus
	void (*setter)(struct valve_st *this);
	int16_t min_speed_p;
	int16_t min_speed_n;
	int16_t max_speed_p;
	int16_t max_speed_n;
	int16_t acc;
	int16_t dec;
	int16_t invert;
} valve_st;



/// @brief: Resets the valve to default settings
static inline void valve_reset(valve_st *this, const valve_st *defaults) {
	*this = *defaults;
}

/// @brief: Initializes the valve.
///
/// @param initializer: Pointer to the valve_st structure
/// which is used to copy the initialization values
static inline void valve_init(valve_st *this, const valve_st *initializer) {
	this->name = initializer->name;
	this->setter = initializer->setter;
}

#endif /* VALVE_H_ */
