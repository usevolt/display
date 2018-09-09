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
	uint16_t nack_count;
} _log_st;

static _log_st _this;
#define this ((&_this))


static void update_nack_count();



const log_entry_def_st log_entry_defs[] = {
		{
				.type = LOG_MEMORY_SAVE_FAILED | LOG_WARNING,
				.def = "Saving data to flash memory failed",
		},
		{
				.type = LOG_NETDEV_DISCONNECTED | LOG_WARNING,
				.def = "Netdev disconnected",
		},
		{
				.type = LOG_ESB_DISCONNECTED | LOG_WARNING,
				.def = "ESB disconnected",
		},
		{
				.type = LOG_FSB_DISCONNECTED | LOG_WARNING,
				.def = "FSB disconnected",
		},
		{
				.type = LOG_CSB_DISCONNECTED | LOG_WARNING,
				.def = "CSB disconnected",
		},
		{
				.type = LOG_LKEYPAD_DISCONNECTED | LOG_WARNING,
				.def = "Left keypad disconnected",
		},
		{
				.type = LOG_RKEYPAD_DISCONNECTED | LOG_WARNING,
				.def = "Right keypad disconnected",
		},
		{
				.type = LOG_PEDAL_DISCONNECTED | LOG_WARNING,
				.def = "Pedal disconnected",
		},
		{
				.type = LOG_ICU_DISCONNECTED | LOG_WARNING,
				.def = "ICU disconnected",
		},
		{
				.type = LOG_HCU_DISCONNECTED | LOG_WARNING,
				.def = "HCU disconnected",
		},
		{
				.type = LOG_CCU_DISCONNECTED | LOG_WARNING,
				.def = "CCU disconnected",
		},
		{
				.type = LOG_LEGS_DOWN | LOG_WARNING,
				.def = "Driving is not allowed when support legs are down",
		},
		{
				.type = LOG_ESB_GLOW_OVERLOAD | LOG_WARNING,
				.def = "Glow Plugs overload",
		},
		{
				.type = LOG_ESB_GLOW_OVERLOAD | LOG_ERROR,
				.def = "Glow Plugs short circuit or faulty",
		},
		{
				.type = LOG_ESB_STARTER_OVERLOAD | LOG_WARNING,
				.def = "Starter overload",
		},
		{
				.type = LOG_ESB_STARTER_FAULT | LOG_ERROR,
				.def = "Starter short circuit",
		},
		{
				.type = LOG_ESB_AC_OVERLOAD | LOG_WARNING,
				.def = "AC compressor overload",
		},
		{
				.type = LOG_ESB_AC_FAULT | LOG_ERROR,
				.def = "AC compressor short circuit",
		},
		{
				.type = LOG_ESB_ENGINE_STOP_OVERLOAD| LOG_WARNING,
				.def = "Engine stop solenoid overload",
		},
		{
				.type = LOG_ESB_ENGINE_STOP_FAULT| LOG_ERROR,
				.def = "Engine stop solenoid short circuit",
		},
		{
				.type = LOG_ESB_BEACON_OVERLOAD | LOG_WARNING,
				.def = "Beacon overload",
		},
		{
				.type = LOG_ESB_BEACON_FAULT | LOG_ERROR,
				.def = "Beacon short circuit",
		},
		{
				.type = LOG_ESB_PUMP_OVERLOAD | LOG_WARNING,
				.def = "Hydraulic pump solenoid overload",
		},
		{
				.type = LOG_ESB_PUMP_FAULT | LOG_ERROR,
				.def = "Hydraulic pump solenoid short circuit",
		},
		{
				.type = LOG_ESB_ALT_IG_OVERLOAD | LOG_WARNING,
				.def = "Alternator IG overload",
		},
		{
				.type = LOG_ESB_ALT_IG_FAULT | LOG_ERROR,
				.def = "Alternator IG short circuit",
		},
		{
				.type = LOG_ESB_MTEMP_WARNING | LOG_WARNING,
				.def = "Motor temperature high",
		},
		{
				.type = LOG_ESB_MTEMP_ERROR | LOG_ERROR,
				.def = "Motor temperature critically high",
		},
		{
				.type = LOG_ESB_MTEMP_SENSOR_FAULT | LOG_WARNING,
				.def = "Motor temperature sensor fault",
		},
		{
				.type = LOG_ESB_OTEMP_WARNING | LOG_WARNING,
				.def = "Hydraulic Oil temperature high",
		},
		{
				.type = LOG_ESB_OTEMP_ERROR | LOG_ERROR,
				.def = "Hydraulic Oil temperature critically high",
		},
		{
				.type = LOG_ESB_OTEMP_SENSOR_FAULT | LOG_WARNING,
				.def = "Hydraulic Oil temperature sensor fault",
		},
		{
				.type = LOG_ESB_OLEVEL_WARNING | LOG_WARNING,
				.def = "Hydraulic Oil level low",
		},
		{
				.type = LOG_ESB_OLEVEL_ERROR | LOG_ERROR,
				.def = "Hydraulic Oil level critically low",
		},
		{
				.type = LOG_ESB_OLEVEL_SENSOR_FAULT | LOG_WARNING,
				.def = "Hydraulic Oil level sensor fault",
		},
		{
				.type = LOG_ESB_FLEVEL_WARNING | LOG_WARNING,
				.def = "Fuel level low",
		},
		{
				.type = LOG_ESB_FLEVEL_ERROR | LOG_ERROR,
				.def = "Fuel level critically low",
		},
		{
				.type = LOG_ESB_FLEVEL_FAULT | LOG_WARNING,
				.def = "Fuel level sensor fault",
		},
		{
				.type = LOG_ESB_VDD_LOW_WARNING | LOG_WARNING,
				.def = "Battery voltage low",
		},
		{
				.type = LOG_ESB_ENGINE_STOP_MISMATCH | LOG_WARNING,
				.def = "Engine stop solenoid mismatch. Please restart the engine.",
		},
		{
				.type = LOG_ESB_ENGINE_PROTECTION_SHUTDOWN | LOG_ERROR,
				.def = "Engine protection shutdown. Check engine oil pressure & cooling liquid temperature",
		},
		{
				.type = LOG_FSB_HORN_OVERCURRENT | LOG_WARNING,
				.def = "Horn overload",
		},
		{
				.type = LOG_FSB_HORN_FAULT | LOG_ERROR,
				.def = "Horn short circuit",
		},
		{
				.type = LOG_FSB_RADIO_OVERCURRENT | LOG_WARNING,
				.def = "Radio supply overload",
		},
		{
				.type = LOG_FSB_RADIO_FAULT | LOG_ERROR,
				.def = "Radio short circuit",
		},
		{
				.type = LOG_FSB_AUX_OVERCURRENT | LOG_WARNING,
				.def = "Aux jack overload",
		},
		{
				.type = LOG_FSB_AUX_FAULT | LOG_ERROR,
				.def = "Aux jack short circuit",
		},
		{
				.type = LOG_FSB_HEATERVDD_OVERCURRENT | LOG_WARNING,
				.def = "Heater VDD supply overload",
		},
		{
				.type = LOG_FSB_HEATERVDD_FAULT | LOG_ERROR,
				.def = "Heater VDD supply short circuit",
		},
		{
				.type = LOG_FSB_HEATERBAT_OVERCURRENT | LOG_WARNING,
				.def = "Heater BAT supply overload",
		},
		{
				.type = LOG_FSB_HEATERBAT_FAULT | LOG_ERROR,
				.def = "Heater BAT supply short circuit",
		},
		{
				.type = LOG_FSB_BATFUSE_FAULT | LOG_ERROR,
				.def = "Battery fuse burned",
		},
		{
				.type = LOG_FSB_IGNKEY_FAULT | LOG_WARNING,
				.def = "Ignition key state error",
		},
		{
				.type = LOG_FSB_EMCY_NOTIFY | LOG_WARNING,
				.def = "Release emergency switch before starting the engine"
		},
		{
				.type = LOG_CSB_WORK_LIGHT_OVERCURRENT | LOG_WARNING,
				.def = "Work Light overload",
		},
		{
				.type = LOG_CSB_WORK_LIGHT_FAULT | LOG_ERROR,
				.def = "Work Light short circuit",
		},
		{
				.type = LOG_CSB_DRIVE_LIGHT_OVERCURRENT | LOG_WARNING,
				.def = "Drive Light overload",
		},
		{
				.type = LOG_CSB_DRIVE_LIGHT_FAULT | LOG_ERROR,
				.def = "Drive Light short circuit",
		},
		{
				.type = LOG_CSB_BACK_LIGHT_OVERCURRENT | LOG_WARNING,
				.def = "Back Light overload",
		},
		{
				.type = LOG_CSB_BACK_LIGHT_FAULT| LOG_ERROR,
				.def = "Back Light short circuit",
		},
		{
				.type = LOG_CSB_IN_LIGHT_OVERCURRENT | LOG_WARNING,
				.def = "In Light overload",
		},
		{
				.type = LOG_CSB_IN_LIGHT_FAULT | LOG_ERROR,
				.def = "In Light short circuit",
		},
		{
				.type = LOG_CSB_BEACON_OVERCURRENT | LOG_WARNING,
				.def = "Beacon overload",
		},
		{
				.type = LOG_CSB_BEACON_FAULT | LOG_ERROR,
				.def = "Beacon short circuit",
		},
		{
				.type = LOG_CSB_WIPER_OVERCURRENT | LOG_WARNING,
				.def = "Wiper overload",
		},
		{
				.type = LOG_CSB_WIPER_FAULT | LOG_ERROR,
				.def = "Wiper short circuit",
		},
		{
				.type = LOG_CSB_COOLER_OVERCURRENT | LOG_WARNING,
				.def = "Cooler overload",
		},
		{
				.type = LOG_CSB_COOLER_FAULT | LOG_ERROR,
				.def = "Cooler short circuit",
		},
		{
				.type = LOG_CSB_OILCOOLER_OVERCURRENT | LOG_WARNING,
				.def = "Oil Cooler overload",
		},
		{
				.type = LOG_CSB_OILCOOLER_FAULT | LOG_ERROR,
				.def = "Oil Cooler short circuit",
		},
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




void log_add(log_entry_e type) {
	// if older entries of this type were found, acknowledge them
	for (int i = 0; i < log_get_nack_count(); i++) {
		log_entry_st entry;
		log_get_nack(&entry, i);
		if (entry.type == type) {
			log_ack(i);
		}
	}
	log_entry_st entry = {
			.type = type,
			.ack = false
	};
	uv_rtc_get_time(&entry.time);
//	todo: logging disabled until no unnecessary errors happen in the system
//	uv_errors_e e = uv_eeprom_push_back((unsigned char *) &entry);
//
//	// returning an error means that the EEPROM was full. Remove the
//	// oldest log entry and write new one again.
//	if (e) {
//		uv_eeprom_pop_front(NULL);
//		uv_eeprom_push_back((unsigned char *) &entry);
//	}
	update_nack_count();
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
}

void log_ack_type(log_entry_e type) {
	log_entry_st entry;
	for (int i = 0; i < log_get_nack_count(); i++) {
		log_get_nack(&entry, i);
		if (entry.type == type) {
			log_ack(i);
			break;
		}
	}
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
