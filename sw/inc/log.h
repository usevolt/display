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
	LOG_NETDEV_DISCONNECTED
};
typedef uint32_t log_entry_e;



/// @brief: A log entry data structure
typedef struct {
	/// @brief: Timestamp of the entry
	uv_time_st time;
	/// @brief: Custom data depending on the log type
	int32_t	data;
	/// @brief: The type of this entry
	log_entry_e type;
} log_entry_st;


/// @brief: Defines the Log entry type instruction string type.
/// Used to display human understandable definitions of the log entry types
typedef struct {
	log_entry_e type;
	const char *def;
	const char *param_def;
} log_entry_def_st;


extern const log_entry_def_st log_entry_defs[];


/// @brief: Returns the definition structure of the log entry.
/// If no match was found, returns NULL
const log_entry_def_st *log_entry_get_definition(log_entry_e type);



/// @brief: Save a log entry to the log. The time and index are
/// calculated automatically
void log_add(log_entry_e type, int32_t data);



/// @brief: Returns a log entry. Index determines which entry is returned.
/// 0 means the most latest entry, 1 means second latest entry, etc...
///
/// @return true if entry was found, false if *index* was bigger than the entry count
bool log_get(log_entry_st *dest, uint16_t index);



/// @brief: Clears the whole log. The use of this should be prevented, since
/// the intention of log is to see what happened in the past!
void log_clear(void);


#endif /* LOG_H_ */
