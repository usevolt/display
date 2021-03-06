/*
 * users.c
 *
 *  Created on: Oct 27, 2016
 *      Author: usevolt
 */


#include "users.h"
#include "vehicle.h"
#include "network.h"
#include <uv_eeprom.h>
#include <uv_uart.h>



static void user_init(userdata_st *this) {
	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		valve_init(&this->base_valves[i],
				&vehicle_valves[i]);
	}
	if (this->engine_power_usage > 100) {
		this->engine_power_usage = 100;
	}
	if (this->volume.volume > 100) {
		this->volume.volume = 100;
	}
	if (this->drivef_comp > 100  ||
			this->drivef_comp < -100) {
		this->drivef_comp = 0;
	}
	if (this->driveb_comp > 100  ||
			this->driveb_comp < -100) {
		this->driveb_comp = 0;
	}
	uw180s_init(&this->uw180s);
	uw100_init(&this->uw100);
	uw50_init(&this->uw50);
	hydout_init(&this->hydout);

}

static void user_reset(userdata_st *user) {
	// todo: initialize user variables to default settings

	strcpy(user->username, "Usewood");

	user->engine_power_usage = 35;
	user->driveb_comp = 0;
	user->drivef_comp = 0;

	user->volume.volume = 100;
	user->volume.notifications = true;
	user->volume.touch = true;
	user->volume.warnings = true;

	user->oilcooler_trigg_temp = 70;
	user->impl2_ain1_req = INT8_MAX / 2;
	user->impl2_ain2_req = INT8_MAX;

	user->idle_rpm = 500;
	user->work_rpm = 1700;
	user->drive_rpm = 2000;

	// base valves
	for (uint16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		user->base_valves[i] = vehicle_valves[i];
	}

	// implement valves
	uw180s_reset(&user->uw180s);
	uw100_reset(&user->uw100);
	uw50_reset(&user->uw50);
	hydout_reset(&user->hydout);

}



void users_init(void) {
	dspl.user = NULL;
	uv_eeprom_read((void*) &dspl.user_index, sizeof(dspl.user_index), CURRENT_USER_EEPROM_ADDR);
	if (dspl.user_index >= uv_vector_size(&dspl.users)) {
		dspl.user_index = 0;
	}
	for (int16_t i = 0; i < uv_vector_size(&dspl.users); i++) {
		user_init(uv_vector_at(&dspl.users, i));
	}
	users_set(((userdata_st*) uv_vector_at(&dspl.users, dspl.user_index))->username);
}



void users_reset(void) {
	uv_vector_init(&dspl.users, dspl.userdata,
			sizeof(dspl.userdata) / sizeof(userdata_st), sizeof(userdata_st));
	users_add("Usewood");
	users_set("Usewood");
}



bool users_add(char *username) {
	if (users_count() >= users_max_count()) {
		return false;
	}
	userdata_st data;
	uv_vector_push_back(&dspl.users, &data);

	userdata_st *d = uv_vector_at(&dspl.users, uv_vector_size(&dspl.users)- 1);
	user_reset(d);
	// username
	strncpy(d->username, username, USERNAME_MAX_LEN);
	d->username[USERNAME_MAX_LEN - 1] = '\0';


	uv_memory_save();

	return true;
}


bool users_copy(uint8_t index, char *username) {
	bool ret = true;
	if ((users_count() < users_max_count()) &&
			(index < users_count())) {
		userdata_st data = *((userdata_st*) uv_vector_at(&dspl.users, index));
		strncpy(data.username, username, USERNAME_MAX_LEN);
		data.username[USERNAME_MAX_LEN - 1] = '\0';
		uv_vector_push_back(&dspl.users, &data);

		uv_memory_save();
	}
	else {
		ret = false;
	}

	return ret;
}



bool users_delete(char *username) {
	if (users_count() <= 1) {
		return false;
	}
	uint8_t i;
	for (i = 0; i < uv_vector_size(&dspl.users); i++) {
		if (strcmp(((userdata_st*) uv_vector_at(&dspl.users, i))->username, username) == 0) {
			if (dspl.user == &dspl.userdata[i] && i >= uv_vector_size(&dspl.users) - 1) {
				dspl.user = dspl.userdata;
			}
			uv_vector_remove(&dspl.users, i, 1);
			uv_memory_save();
			break;
		}
	}
	return true;
}



bool users_set(char *username) {
	if ( dspl.user && strcmp(username, dspl.user->username) == 0) {
		return true;
	}
	uint8_t i;
	for (i = 0; i < uv_vector_size(&dspl.users); i++) {
		if (strcmp(((userdata_st*) uv_vector_at(&dspl.users, i))->username, username) == 0) {

			dspl.user = (userdata_st*) uv_vector_at(&dspl.users, i);
			dspl.user_index = i;
			uv_eeprom_write((unsigned char*) &dspl.user_index,
					sizeof(dspl.user_index), CURRENT_USER_EEPROM_ADDR);
			// update network parameters
			network_update_save(&dspl.network);
			return true;
		}
	}
	return false;

}

