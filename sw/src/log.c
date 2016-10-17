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
	uv_eeprom_clear();
}
