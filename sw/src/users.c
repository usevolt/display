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
	implement_init(&this->uw180s, &uw180s);
	implement_init(&this->uw50, &uw50);
	for (int16_t i = 0; i < uv_vector_size(&this->generic_implements); i++) {
		implement_init(uv_vector_at(&this->generic_implements, i), &generic_implement);
	}

}



static void user_reset(userdata_st *user) {
	// todo: initialize user variables to default settings

	strcpy(user->username, "Usewood");


	// base valves
	for (uint16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		user->base_valves[i] = vehicle_valves[i];
	}

	// implement valves
	user->uw50 = uw50;
	user->uw180s = uw180s;
	uv_vector_init(&user->generic_implements, user->generic_impl_data,
			GENERIC_IMPLEMENT_COUNT, sizeof(generic_implement_st));
	user->implement = (void *) &user->uw180s;

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
	userdata_st d;
	user_reset(&d);

	// username
	strncpy(d.username, username, USERNAME_MAX_LEN);
	d.username[USERNAME_MAX_LEN - 1] = '\0';

	uv_vector_push_back(&dspl.users, &d);

	uv_memory_save(&dspl.data_start, &dspl.data_endl);

	return true;
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
			uv_vector_remove(&dspl.users, i);
			uv_memory_save(&dspl.data_start, &dspl.data_endl);
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
			network_update(&dspl.network);
			return true;
		}
	}
	return false;

}

