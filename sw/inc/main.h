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
//#include <canopen/canopen_obj_dict.h>
#include <uv_rtos.h>
#include "alert.h"
#include "vehicle.h"
#include "implement.h"
#include "network.h"

/// @brief: Defines the maximum count of the users
#define USER_COUNT		4
/// @brief: Maximum length of the username field
#define USERNAME_MAX_LEN	32


#define HOUR_COUNTER_EEPROM_ADDR	(CONFIG_EEPROM_RING_BUFFER_END_ADDR + 1)
#define CURRENT_USER_EEPROM_ADDR	(CONFIG_EEPROM_RING_BUFFER_END_ADDR)



typedef uint8_t user_e;
	/// @brief: User dependant system settings and data
typedef struct {
		char username[USERNAME_MAX_LEN];
		uint16_t engine_power_usage;
		valve_st base_valves[BASE_VALVE_COUNT];
		uw180s_st uw180s;
		uw50_st uw50;
		uw100_st uw100;
		/// @brief: Pointer to the currently active implement. Requires to be casted
		/// to the implement type.
		implement_st *implement;
		/// @brief: Tells the currently selected implement
		impl_type_e active_implement;
		struct {
			uint8_t volume;
			bool touch;
			bool notifications;
			bool warnings;
		} volume;
} userdata_st;


typedef struct _dspl_st {

	uint16_t hour_counter;
	uint16_t sec_counter;
	uint8_t last_sec;

	int canopen_heartbeat;

	/// @brief: Index telling the current user. This value
	/// is stored in EEPROM
	uint8_t user_index;
	/// @brief: Pointer to the current user data structure.
	userdata_st *user;

	/// @brief: Network module takes care of the data communication between
	/// other CAN network devices
	network_st network;

	alert_st alert;

	uv_data_start_t data_start;

	userdata_st userdata[USER_COUNT];

	uv_vector_st users;

	uv_data_end_t data_end;

} dspl_st;


void dspl_init(dspl_st *me);

void dspl_step(void *me);

#endif /* MAIN_H_ */
