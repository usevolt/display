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


/// @brief: Implement callback functino pointers.
/// Every implement should assing one of these to indicate
/// what functions will be used for UI.
typedef struct {
	void (*dashboard_show)(void);
	void (*dasboard_step)(uint16_t step_ms);
	void (*settings_show)(void);
	void (*settings_step)(uint16_t step_ms);
} implement_callbs_st;

/// @brief: Struct which describes a implements valve configurations
typedef struct {
	uint16_t max_speed_p;
	uint16_t max_speed_n;
	bool invert;
} impl_valve_st;

/// @brief: Structure for definenin extended implement valve configurations.
/// Contains also acceleration and deceleration.
typedef struct {
	uint16_t max_speed_p;
	uint16_t max_speed_n;
	bool invert;
	uint16_t acc;
	uint16_t dec;
} impl_valve_ext_st;




/// @brief: Defines the basic structure for implements. Pure virtual structure!
typedef struct {
	char *name;
	/// UI callback functions. With these no special implement related
	/// if-statements need to be put into UI side of the software
	const implement_callbs_st *callbacks;
} implement_st;


/// @brief: Initializes the implement.
///
/// @param initializer: Pointer to the implement_st structure
/// which is used to copy the initialization values
void implement_init(void *me, const void *initializer);



/// @brief: describes the structure for generic implements.
typedef struct {
	EXTENDS(implement_st);

	char name[GENERIC_IMPLEMENT_NAME_LEN];

	/// @brief: Base machine's implement valve settings
	valve_st valves[IMPLEMENT_VALVE_COUNT];
} generic_implement_st;
/// @brief: Generic implement factory settings. Same for all generic valves.
extern const generic_implement_st generic_implement;

void generic_implement_init(void *me);




/// @brief: Defines the structure for UW180S implement
typedef struct {
	EXTENDS(implement_st);

	impl_valve_st wheels;
	impl_valve_st wheels_feed;
	impl_valve_st delimbers;
	impl_valve_st saw;
	impl_valve_st tilt;
	impl_valve_st rotator;

} uw180s_st;
/// @brief: Uw180s factory settings
extern const uw180s_st uw180s;

static inline void uw180s_init(void *me) {
	implement_init(me, &uw180s);
}


typedef struct {
	EXTENDS(implement_st);

	impl_valve_ext_st rotator;
	impl_valve_ext_st open;
} uw100_st;
extern const uw100_st uw100;

static inline void uw100_init(void *me) {
	implement_init(me, &uw100);
}


/// @brief: defines the structure for UW50 implement
typedef struct {
	EXTENDS(implement_st);

	impl_valve_ext_st saw;
	impl_valve_ext_st tilt;

} uw50_st;
/// @brief: UW50 factory settings
extern const uw50_st uw50;

static inline void uw50_init(void *me) {
	implement_init(me, &uw50);
}


void implement_set(impl_type_e implement);


#endif /* IMPLEMENT_H_ */
