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
#include <uv_ui.h>
#include "vehicle.h"


/// @brief: Implement callback functino pointers.
/// Every implement should assing one of these to indicate
/// what functions will be used for UI.
typedef struct {
	void (*dashboard_show)(void);
	uv_uiobject_ret_e (*dasboard_step)(uint16_t step_ms);
	void (*settings_show)(void);
	uv_uiobject_ret_e (*settings_step)(uint16_t step_ms);
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



#define LOG_TYPE_COUNT		4
#define TREE_TYPE_COUNT		4
#define LOG_NAME_LEN		16

/// @brief: Structure for a single log type
typedef struct {
	int16_t length_mm;
	int16_t max_dia_mm;
	int16_t min_dia_mm;
	char name[LOG_NAME_LEN];
} log_type_st;


typedef struct {
	char name[LOG_NAME_LEN];
} tree_type_st;

/// @brief: Defines the structure for UW180S implement
typedef struct {
	EXTENDS(implement_st);

	impl_valve_st wheels;
	impl_valve_st wheels_feed;
	impl_valve_st delimbers;
	impl_valve_st saw;
	impl_valve_st tilt;
	impl_valve_st rotator;
	bool mb_enabled;
	int16_t len_calib;
	int16_t vol_calib;
	int16_t log_len1;
	int16_t log_len2;
	uint16_t roller_grab_time;
	uint16_t blades_grab_time;
} uw180s_st;
/// @brief: Uw180s factory settings
extern const uw180s_st uw180s;

static inline void uw180s_reset(uw180s_st *this);


void uw180s_init(uw180s_st *this);

static inline void uw180s_reset(uw180s_st *this) {
	*this = uw180s;
	uw180s_init(this);
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

static inline void uw100_reset(uw100_st *this) {
	*this = uw100;
	uw100_init(this);
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

static inline void uw50_reset(uw50_st *this) {
	*this = uw50;
	uw50_init(this);
}


void implement_set(impl_type_e implement);


#endif /* IMPLEMENT_H_ */
