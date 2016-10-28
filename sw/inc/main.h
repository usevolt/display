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
} userdata_st;

typedef struct {

	int step_delay;

	uint16_t hour_counter;
	uint8_t last_hour;

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
