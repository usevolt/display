/*
 * implement.h
 *
 *  Created on: Nov 3, 2016
 *      Author: usevolt
 */

#ifndef IMPLEMENT_H_
#define IMPLEMENT_H_

#include <uv_utilities.h>
#include <stdbool.h>
#include "vehicle.h"

#define GENERIC_IMPLEMENT_NAME_LEN		20


/// @brief: Defines the basic structure for implements. Pure virtual structure!
typedef struct {
	char *name;
	/// @brief: Base machine's implement valve settings
	valve_st valves[IMPLEMENT_VALVE_COUNT];

} implement_st;



/// @brief: describes the structure for generic implements.
typedef struct {
	EXTENDS(implement_st);

	char name[GENERIC_IMPLEMENT_NAME_LEN];
} generic_implement_st;
/// @brief: Generic implement factory settings. Same for all generic valves.
extern const generic_implement_st generic_implement;



/// @brief: Defines the structure for UW180S implement
typedef struct {
	EXTENDS(implement_st);

} uw180s_st;
/// @brief: Uw180s factory settings
extern const uw180s_st uw180s;



/// @brief: defines the structure for UW40 implement
typedef struct {
	EXTENDS(implement_st);

} uw40_st;
/// @brief: UW40 factory settings
extern const uw40_st uw40;




#endif /* IMPLEMENT_H_ */
