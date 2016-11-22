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


/// @brief: Defiens the datatype for individual hydraulic valves





/// @brief: Struct for hydraulic valve settings
typedef struct {
	const char *name;
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



#endif /* VALVE_H_ */
