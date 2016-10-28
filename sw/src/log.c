/*
 * log.c
 *
 *  Created on: Aug 25, 2016
 *      Author: usevolt
 */


#include "log.h"
#include <uv_eeprom.h>
#include <uv_rtc.h>



const log_entry_def_st log_entry_defs[] = {
		{
				.type = LOG_BOOT_UP,
				.def = "Boot up",
				.param_def = "Reset source"
		},
		{
				.type = LOG_TIME_SET,
				.def = "Local time set",
				.param_def = "From command line:"
		},
		{
				.type = LOG_DRIVER_SET,
				.def = "Driver selected",
				.param_def = "Driver ID:"
		},
		{
				.type = LOG_DRIVER_DELETED,
				.def = "Driver deleted",
				.param_def = "Driver ID:"
		},
		{
				.type = LOG_DRIVER_ADDED,
				.def = "New driver added",
				.param_def = "Driver ID:"
		},
		{
				.type = LOG_DRIVER_CLEAR,
				.def = "All divers cleared",
				.param_def = ""
		}
};


static inline uint16_t log_entry_defs_count(void) {
	return (sizeof(log_entry_defs) / sizeof(log_entry_def_st));
}



const log_entry_def_st *log_entry_get_definition(log_entry_e type) {
	uint16_t i;
	for (i = 0; i < log_entry_defs_count(); i++) {
		if (log_entry_defs[i].type == type) {
			return &log_entry_defs[i];
		}
	}
	return NULL;
}




void log_add(log_entry_e type, int32_t data) {
	log_entry_st entry = {
			.data = data,
			.type = type
	};
	uv_rtc_get_time(&entry.time);
	uv_errors_e e = uv_eeprom_push_back((unsigned char *) &entry);
	// returning an error means that the EEPROM was full. Remove the
	// oldest log entry and write new one again.
	if (e) {
		uv_eeprom_pop_front(NULL);
		uv_eeprom_push_back((unsigned char *) &entry);
	}
}


bool log_get(log_entry_st *dest, uint16_t index) {
	uv_errors_e e = uv_eeprom_at((unsigned char *) dest, index);
	return e ? false : true;
}


void log_clear(void) {
	unsigned char p = 0;
	for (int i = 0; i < CONFIG_EEPROM_RING_BUFFER_END_ADDR; i++) {
		uv_eeprom_write(&p, sizeof(unsigned char), i);
	}
}
