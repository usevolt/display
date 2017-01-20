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
				.type = LOG_MEMORY_SAVE_FAILED,
				.def = "Saving data to flash memory failed",
				.param_def = "uv_memory_save return: "
		},
		{
				.type = LOG_NETDEV_DISCONNECTED,
				.def = "Netdev disconnected",
				.param_def = "node ID: "
		},
		{
				.type = LOG_MSB_DISCONNECTED,
				.def = "MSB disconnected",
				.param_def = ""
		},
		{
				.type = LOG_CSB_DISCONNECTED,
				.def = "CSB disconnected",
				.param_def = ""
		},
		{
				.type = LOG_ECU_DISCONNECTED,
				.def = "ECU disconnected",
				.param_def = ""
		},
		{
				.type = LOG_LKEYPAD_DISCONNECTED,
				.def = "Left keypad disconnected",
				.param_def = ""
		},
		{
				.type = LOG_RKEYPAD_DISCONNECTED,
				.def = "Right keypad disconnected",
				.param_def = ""
		},
		{
				.type = LOG_PEDAL_DISCONNECTED,
				.def = "Pedal disconnected",
				.param_def = ""
		},
		{
				.type = LOG_UW180S_ECU_DISCONNECTED,
				.def = "UW180s ECU disconnected",
				.param_def = ""
		},
		{
				.type = LOG_UW180S_MB_DISCONNECTED,
				.def = "UW180s MB disconnected",
				.param_def = ""
		}
};


static inline uint16_t log_entry_defs_count(void) {
	return (sizeof(log_entry_defs) / sizeof(log_entry_def_st));
}


static log_entry_type_e type(log_entry_st *entry) {
	return (entry->type & LOG_ERROR) ? LOG_ERROR : LOG_WARNING;
}



const log_entry_def_st *log_entry_get_definition(log_entry_e type) {
	uint16_t i;
	for (i = 0; i < log_entry_defs_count(); i++) {
		if ((log_entry_defs[i].type & (~LOG_ERROR)) == (type & (~LOG_ERROR))) {
			return &log_entry_defs[i];
		}
	}
	return NULL;
}




static void log_add(log_entry_e type, int32_t data) {
	log_entry_st entry = {
			.data = data,
			.type = type,
			.ack = false
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


void log_warning(log_entry_e type, int32_t data) {
	log_add(type | LOG_WARNING, data);
}


void log_error(log_entry_e type, int32_t data) {
	log_add(type | LOG_ERROR, data);
}

void log_ack(log_entry_e type) {

}

uint16_t log_get_nack_count() {
	printf("log_get_nack_count not implemented\n\r");
	return 0;
}


const log_entry_def_st *log_get_nack_def(uint16_t index) {
	printf("log_get_nack_def not implement\n\r");
	return &log_entry_defs[0];
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
