/*
 * users.c
 *
 *  Created on: Oct 27, 2016
 *      Author: usevolt
 */


#include "users.h"
#include "vehicle.h"
#include <uv_uart.h>

void user_reset(userdata_st *user) {
	// todo: initialize user variables to default settings

	strcpy(user->username, "Usewood");


	// base valves
	for (uint16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		user->base_valves[i] = vehicle_valves[i];
	}

	// implement valves
	user->uw40 = uw40;
	user->uw180s = uw180s;
	uv_vector_init(&user->generic_implements, user->generic_impl_data,
			GENERIC_IMPLEMENT_COUNT, sizeof(generic_implement_st));
	user->implement = (void *) &user->uw180s;

}


bool users_add(char *username) {
	if (users_count() >= users_max_count()) {
		return false;
	}
	userdata_st d;

	// username
	strncpy(d.username, username, USERNAME_MAX_LEN);
	d.username[USERNAME_MAX_LEN - 1] = '\0';

	uv_vector_push_back(&dspl.users, &d);

	user_reset(uv_vector_at(&dspl.users, uv_vector_size(&dspl.users) - 1));

	log_add(LOG_DRIVER_ADDED, uv_vector_size(&dspl.users));
	return true;
}

bool users_delete(char *username) {
	if (users_count() <= 1) {
		return false;
	}
	uint8_t i;
	for (i = 0; i < uv_vector_max_size(&dspl.users); i++) {
		if (strcmp(((userdata_st*) uv_vector_at(&dspl.users, i))->username, username) == 0) {
			if (dspl.user == &dspl.userdata[i] && i >= uv_vector_size(&dspl.users) - 1) {
				dspl.user = dspl.userdata;
			}
			uv_vector_remove(&dspl.users, i);
			log_add(LOG_DRIVER_DELETED, i);
			break;
		}
	}
	return true;
}

bool users_set(char *username) {
	uint8_t i;
	for (i = 0; i < uv_vector_size(&dspl.users); i++) {
		if (strcmp(((userdata_st*) uv_vector_at(&dspl.users, i))->username, username) == 0) {
			dspl.user = (userdata_st*) uv_vector_at(&dspl.users, i);
			log_add(LOG_DRIVER_SET, i);
			return true;
		}
	}
	return false;

}

