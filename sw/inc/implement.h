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
#include "can_hcu.h"


/// @brief: Implement callback functino pointers.
/// Every implement should assing one of these to indicate
/// what functions will be used for UI.
typedef struct {
	void (*dashboard_show)(void);
	uv_uiobject_ret_e (*dasboard_step)(uint16_t step_ms);
	void (*settings_show)(void);
	uv_uiobject_ret_e (*settings_step)(uint16_t step_ms);
} implement_callbs_st;




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

	valve_st feedopen;
	valve_st feed;
	valve_st bladesopen;
	valve_st saw;
	valve_st tilt;
	valve_st rotator;
	valve_st all_open;
	valve_st impl1;
	valve_st impl2;
	bool len_enabled;
	bool width_enabled;
	bool vol_enabled;
	int16_t len_calib;
	int16_t vol_calib;
	uint16_t max_width_mm;
	uint16_t min_width_mm;
	int16_t log_len1;
	int16_t log_len2;
	uint16_t roller_grab_time;
	uint16_t blades_grab_time;
	uint8_t tiltfloat_enable;
	uint8_t tilt_onthumb;
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

	valve_st rotator;
	valve_st open;
	valve_st impl2;
} uw100_st;
extern const uw100_st uw100;

void uw100_init(uw100_st *this);

static inline void uw100_reset(uw100_st *this) {
	*this = uw100;
	uw100_init(this);
}


/// @brief: defines the structure for UW50 implement
typedef struct {
	EXTENDS(implement_st);

	valve_st saw;
	valve_st tilt;

} uw50_st;
/// @brief: UW50 factory settings
extern const uw50_st uw50;

void uw50_init(uw50_st *this);

static inline void uw50_reset(uw50_st *this) {
	*this = uw50;
	uw50_init(this);
}




typedef struct {
	EXTENDS(implement_st);

	valve_st impl2;
} hydout_st;
extern const hydout_st hydout;

void hydout_init(hydout_st *this);

static inline void hydout_reset(hydout_st *this) {
	*this = hydout;
	hydout_init(this);
}


void implement_set(hcu_impls_e implement);


#endif /* IMPLEMENT_H_ */
