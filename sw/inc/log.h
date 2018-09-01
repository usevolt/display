/*
 * log.h
 *
 *  Created on: Aug 25, 2016
 *      Author: usevolt
 */

#ifndef LOG_H_
#define LOG_H_


#include <uv_utilities.h>
#include <time.h>
#include <uv_rtc.h>


/// @file: Manages the device specific LOG, which is common for all
/// users (singleton). The log is saved in EEPROM, allowing any kind of
/// action to be easily saved or removed from it.




/// @brief: Different log entries are specified here
enum {
	// Saving the settings to flash memory failed
	// param: Return value from uv_memory_save
	LOG_MEMORY_SAVE_FAILED = 0,
	LOG_NETDEV_DISCONNECTED,
	LOG_ESB_DISCONNECTED,
	LOG_FSB_DISCONNECTED,
	LOG_CSB_DISCONNECTED,
	LOG_LKEYPAD_DISCONNECTED,
	LOG_RKEYPAD_DISCONNECTED,
	LOG_PEDAL_DISCONNECTED,
	LOG_ICU_DISCONNECTED,
	LOG_HCU_DISCONNECTED,
	LOG_CCU_DISCONNECTED,
	LOG_LEGS_DOWN,
	LOG_ESB_GLOW_OVERLOAD,
	LOG_ESB_GLOW_FAULT,
	LOG_ESB_STARTER_OVERLOAD,
	LOG_ESB_STARTER_FAULT,
	LOG_ESB_AC_OVERLOAD,
	LOG_ESB_AC_FAULT,
	LOG_ESB_ENGINE_STOP_OVERLOAD,
	LOG_ESB_ENGINE_STOP_FAULT,
	LOG_ESB_BEACON_OVERLOAD,
	LOG_ESB_BEACON_FAULT,
	LOG_ESB_PUMP_OVERLOAD,
	LOG_ESB_PUMP_FAULT,
	LOG_ESB_ALT_IG_OVERLOAD,
	LOG_ESB_ALT_IG_FAULT,
	LOG_ESB_MTEMP_WARNING,
	LOG_ESB_MTEMP_ERROR,
	LOG_ESB_MTEMP_SENSOR_FAULT,
	LOG_ESB_OTEMP_WARNING,
	LOG_ESB_OTEMP_ERROR,
	LOG_ESB_OTEMP_SENSOR_FAULT,
	LOG_ESB_OLEVEL_WARNING,
	LOG_ESB_OLEVEL_ERROR,
	LOG_ESB_OLEVEL_SENSOR_FAULT,
	LOG_ESB_FLEVEL_WARNING,
	LOG_ESB_FLEVEL_ERROR,
	LOG_ESB_FLEVEL_FAULT,
	LOG_ESB_VDD_LOW_WARNING,
	LOG_ESB_ENGINE_STOP_MISMATCH,
	LOG_ESB_ENGINE_PROTECTION_SHUTDOWN,

	LOG_FSB_HORN_OVERCURRENT,
	LOG_FSB_HORN_FAULT,
	LOG_FSB_RADIO_OVERCURRENT,
	LOG_FSB_RADIO_FAULT,
	LOG_FSB_AUX_OVERCURRENT,
	LOG_FSB_AUX_FAULT,
	LOG_FSB_HEATERVDD_OVERCURRENT,
	LOG_FSB_HEATERVDD_FAULT,
	LOG_FSB_HEATERBAT_OVERCURRENT,
	LOG_FSB_HEATERBAT_FAULT,
	LOG_FSB_BATFUSE_FAULT,
	LOG_FSB_IGNKEY_FAULT,
	LOG_FSB_EMCY_NOTIFY,

	LOG_CSB_WORK_LIGHT_OVERCURRENT,
	LOG_CSB_WORK_LIGHT_FAULT,
	LOG_CSB_DRIVE_LIGHT_OVERCURRENT,
	LOG_CSB_DRIVE_LIGHT_FAULT,
	LOG_CSB_BACK_LIGHT_OVERCURRENT,
	LOG_CSB_BACK_LIGHT_FAULT,
	LOG_CSB_IN_LIGHT_OVERCURRENT,
	LOG_CSB_IN_LIGHT_FAULT,
	LOG_CSB_BEACON_OVERCURRENT,
	LOG_CSB_BEACON_FAULT,
	LOG_CSB_WIPER_OVERCURRENT,
	LOG_CSB_WIPER_FAULT,
	LOG_CSB_COOLER_OVERCURRENT,
	LOG_CSB_COOLER_FAULT,
	LOG_CSB_OILCOOLER_OVERCURRENT,
	LOG_CSB_OILCOOLER_FAULT


};
typedef uint8_t log_entry_e;

enum {
	LOG_WARNING = 0,
	LOG_ERROR = (1 << 7)
};
typedef uint8_t log_entry_type_e;



/// @brief: A log entry data structure
typedef struct {
	/// @brief: Timestamp of the entry
	uv_time_st time;
	/// @brief: The type of this entry. The most significant bit
	/// indicates if the log entry is a warning or an error.
	log_entry_e type;
	/// @brief: Acknowledge byte. If true, this entry is ack'ed.
	/// Otherwise it's still active.
	bool ack;

} log_entry_st;


/// @brief: Defines the Log entry type instruction string type.
/// Used to display human understandable definitions of the log entry types
typedef struct {
	log_entry_e type;
	const char *def;
} log_entry_def_st;


extern const log_entry_def_st log_entry_defs[];


void log_init();

/// @brief: Returns the definition structure of the log entry.
/// If no match was found, returns NULL
const log_entry_def_st *log_entry_get_definition(log_entry_e type);




/// @brief: Displays a new log message. Message type will determine if it's warning or an error.
void log_add(log_entry_e type);

static inline log_entry_type_e log_get_type(log_entry_st *entry) {
	return entry->type & LOG_ERROR;
}



/// @brief: Acknowledges an active **index**'th warning or error message. 0 is the most recent message.
void log_ack(uint16_t index);

/// @brief: ACknowledges the most recent log entry with the typ of **type**
void log_ack_type(log_entry_e type);

/// @brief: Returns how many entries are not acknowledged
uint16_t log_get_nack_count();

/// @brief: Returns the **index**'th not acknowledged entry's definition
const log_entry_def_st *log_get_nack_def(uint16_t index);

/// @brief: Returns the **index**'th not acknowledged entry
bool log_get_nack(log_entry_st *dest, uint16_t index);


/// @brief: Returns a log entry. Index determines which entry is returned.
/// 0 means the most latest entry, 1 means second latest entry, etc...
///
/// @return true if entry was found, false if *index* was bigger than the entry count
bool log_get(log_entry_st *dest, uint16_t index);



/// @brief: Clears the whole log. The use of this should be prevented, since
/// the intention of log is to see what happened in the past!
void log_clear(void);


#endif /* LOG_H_ */
