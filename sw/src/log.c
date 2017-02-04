/*
 * log.c
 *
 *  Created on: Aug 25, 2016
 *      Author: usevolt
 */


#include "log.h"
#include <uv_eeprom.h>
#include <uv_rtc.h>


typedef struct {
	int16_t nack_count;
} _log_st;

static _log_st _this;
#define this ((&_this))


static void update_nack_count();



const log_entry_def_st log_entry_defs[] = {
		{
				.type = LOG_MEMORY_SAVE_FAILED | LOG_WARNING,
				.def = "Saving data to flash memory failed",
				.param_def = "uv_memory_save return: "
		},
		{
				.type = LOG_NETDEV_DISCONNECTED | LOG_WARNING,
				.def = "Netdev disconnected",
				.param_def = "node ID: "
		},
		{
				.type = LOG_MSB_DISCONNECTED | LOG_WARNING,
				.def = "MSB disconnected",
				.param_def = ""
		},
		{
				.type = LOG_CSB_DISCONNECTED | LOG_WARNING,
				.def = "CSB disconnected",
				.param_def = ""
		},
		{
				.type = LOG_ECU_DISCONNECTED | LOG_WARNING,
				.def = "ECU disconnected",
				.param_def = ""
		},
		{
				.type = LOG_LKEYPAD_DISCONNECTED | LOG_WARNING,
				.def = "Left keypad disconnected",
				.param_def = ""
		},
		{
				.type = LOG_RKEYPAD_DISCONNECTED | LOG_WARNING,
				.def = "Right keypad disconnected",
				.param_def = ""
		},
		{
				.type = LOG_PEDAL_DISCONNECTED | LOG_WARNING,
				.def = "Pedal disconnected",
				.param_def = ""
		},
		{
				.type = LOG_UW180S_ECU_DISCONNECTED | LOG_WARNING,
				.def = "UW180s ECU disconnected",
				.param_def = ""
		},
		{
				.type = LOG_UW180S_MB_DISCONNECTED | LOG_WARNING,
				.def = "UW180s MB disconnected",
				.param_def = ""
		},
		{
				.type = LOG_CAN_BUS_OFF | LOG_WARNING,
				.def = "CAN-bus: No connection",
				.param_def = ""
		},
		{
				.type = LOG_OIL_LEVEL_WARNING | LOG_WARNING,
				.def = "Oil level low",
				.param_def = "level: "
		},
		{
				.type = LOG_OIL_LEVEL_ERROR | LOG_ERROR,
				.def = "Oil level critically low",
				.param_def = "level: "
		},
		{
				.type = LOG_FUEL_LEVEL_WARNING | LOG_WARNING,
				.def = "Fuel level low",
				.param_def = "level: "
		},
		{
				.type = LOG_MOTOR_TEMP_WARNING | LOG_WARNING,
				.def = "Motor temperature high",
				.param_def = "temp: "
		},
		{
				.type = LOG_MOTOR_TEMP_ERROR | LOG_ERROR,
				.def = "Motor temperature critically high",
				.param_def = "temp: "
		},
		{
				.type = LOG_OIL_TEMP_WARNING | LOG_WARNING,
				.def = "Oil temperature high",
				.param_def = "temp: "
		},
		{
				.type = LOG_OIL_TEMP_ERROR | LOG_ERROR,
				.def = "Oil level critically high",
				.param_def = "temp: "
		},
		{
				.type = LOG_BAT_V_WARNING | LOG_WARNING,
				.def = "Battery voltage low",
				.param_def = "voltage: "
		},
		{
				.type = LOG_BAT_V_ERROR | LOG_ERROR,
				.def = "Battery voltage critically low",
				.param_def = "voltage: "
		}
};


static inline uint16_t log_entry_defs_count(void) {
	return (sizeof(log_entry_defs) / sizeof(log_entry_def_st));
}



void log_init() {
	update_nack_count();
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




void log_add(log_entry_e type, int32_t data) {
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



void log_ack(uint16_t index) {
	log_entry_st entry;
	uint16_t addr;
	int16_t count = -1;
	uint16_t i = 0;
	uv_errors_e e = uv_eeprom_at((void*) &entry, &addr, i);
	while (!e) {
		if (!entry.ack) {
			count++;
		}

		if ((uint16_t) count == index) {
			entry.ack = true;
			uv_eeprom_write((void*) &entry, sizeof(entry), addr);
			update_nack_count();
			return;
		}

		i++;
		e = uv_eeprom_at((void*) &entry, &addr, i);
	}
	return;


}

uint16_t log_get_nack_count() {
	return this->nack_count;
}

static void update_nack_count() {
	uint16_t count = 0;
	uint16_t i = 0;
	log_entry_st entry;
	uv_errors_e e = uv_eeprom_at((void*) &entry, NULL, i);
	while (!e) {
		if (!entry.ack) {
			count++;
		}
		i++;
		e = uv_eeprom_at((void*) &entry, NULL, i);
	}
	this->nack_count = count;
}


const log_entry_def_st *log_get_nack_def(uint16_t index) {
	log_entry_st entry;
	if (log_get_nack(&entry, index)) {
		return log_entry_get_definition(entry.type);
	}
	return NULL;
}


bool log_get_nack(log_entry_st *dest, uint16_t index) {
	int16_t count = -1;
	uint16_t i = 0;
	uv_errors_e e = uv_eeprom_at((void*) dest, NULL, i);
	while (!e) {
		if (!dest->ack) {
			count++;
		}

		if ((uint16_t) count == index) {
			return true;
		}

		i++;
		e = uv_eeprom_at((void*) dest, NULL, i);
	}
	return false;
}

bool log_get(log_entry_st *dest, uint16_t index) {
	uv_errors_e e = uv_eeprom_at((unsigned char *) dest, NULL, index);
	return e ? false : true;
}


void log_clear(void) {
	unsigned char p = 0;
	for (int i = 0; i < CONFIG_EEPROM_RING_BUFFER_END_ADDR; i++) {
		uv_eeprom_write(&p, sizeof(unsigned char), i);
	}
}
