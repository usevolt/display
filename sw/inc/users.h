/*
 * users.h
 *
 *  Created on: Oct 27, 2016
 *      Author: usevolt
 */

#ifndef USERS_H_
#define USERS_H_

#include "main.h"
#include "log.h"
#include <string.h>

/// @file: Small macros for handling the user input and removal


/// @brief: Returns the max count of users
static inline int16_t users_max_count() {
	return USER_COUNT;
}

/// @brief: Returns the current count of users.
static inline int16_t users_count() {
	return uv_vector_size(&dspl.users);
}

/// @brief: Initializes the user data
void users_init(void);

/// @brief: Adds a new user. Returns false if adding failed.
bool users_add(char *username);

/// @brief: Deletes a user. Returns false if deleting failed.
bool users_delete(char *username);

/// @brief: Sets the current user. Returns false if setting failed.
bool users_set(char *username);

/// @brief: Clears all users
static inline void users_clear() {
	uv_vector_clear(&dspl.users);
	dspl.user = 0;
}

/// @brief: Converts userdata pointer to the index number in users-vector
static inline uint16_t usertoi(userdata_st *user) {
	for (uint8_t i = 0; i < users_count(); i++) {
		if (dspl.user == uv_vector_at(&dspl.users, i)) {
			return i;
		}
	}
	return 0;
}


/// @brief: Resets the userdata to system defaults
void users_reset(void);

#endif /* USERS_H_ */
