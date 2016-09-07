/*
 * log.c
 *
 *  Created on: Aug 25, 2016
 *      Author: usevolt
 */


#include "log.h"


const log_entry_def_st log_entry_defs[] = {
		{
				.type = LOG_BOOT_UP,
				.str = "Power on"
		}
};


static inline uint16_t log_entry_defs_count(void) {
	return (sizeof(log_entry_defs) / sizeof(log_entry_def_st));
}


const char *log__entry_get_definition(log_entry_e type) {
	uint16_t i;
	for (i = 0; i < log_entry_defs_count(); i++) {
		if (log_entry_defs[i].type == type) {
			return log_entry_defs[i].str;
		}
	}
	return "Unknown";
}

