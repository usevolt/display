/*
 * dspl_main.h
 *
 *  Created on: Mar 8, 2016
 *      Author: usevolt
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <uv_gpio.h>
#include <uv_memory.h>
#include <uv_canopen.h>
#include <uv_utilities.h>
#include <uv_rtos.h>
#include "alert.h"
#include "vehicle.h"
#include "implement.h"

/// @brief: Defines the maximum count of the users
#define USER_COUNT		4
/// @brief: Maximum length of the username field
#define USERNAME_MAX_LEN	32




/// @brief: Mutex which should be used when calling to UI functions
///
/// @note: All UI windows should lock this mutex in their _show()-functions
extern uv_mutex_ptr gui_mutex;


typedef uint8_t user_e;
	/// @brief: User dependant system settings and data
typedef struct {
		char username[USERNAME_MAX_LEN];
		valve_st base_valves[BASE_VALVE_COUNT];
		uw180s_st uw180s;
		uw40_st uw40;
		generic_implement_st generic_impl_data[GENERIC_IMPLEMENT_COUNT];
		uv_vector_st generic_implements;
		/// @brief: Pointer to the currently active implement. Requires to be casted
		/// to the implement type.
		implement_st *implement;
} userdata_st;


typedef struct {

	int step_delay;

	uint16_t hour_counter;
	uint8_t last_hour;
	int8_t oil_level;
	int8_t fuel_level;
	int8_t motor_temp;
	int8_t oil_temp;

	uv_data_start_t data_start;

	uv_canopen_st canopen;

	alert_st alert;

	userdata_st userdata[USER_COUNT];
	uv_vector_st users;
	/// @brief: Pointer to the current user data structure.
	userdata_st *user;

	uv_data_end_t data_endl;

} dspl_st;

extern dspl_st dspl;

void dspl_init(dspl_st *me);

void dspl_step(void *me);

#endif /* MAIN_H_ */
