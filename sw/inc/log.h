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


/// @brief: Different log entries are specified here
enum {
	// The device has just been booted up
	LOG_BOOT_UP = 0
};
typedef uint8_t log_entry_e;



/// @brief: A log entry data structure
typedef struct {
	/// @brief: Timestamp of the entry
	time_t		time;
	/// @brief: Custom data depending on the log type
	uint32_t	data;
	/// @brief: The type of this entry
	log_entry_e type;
} log_entry_st;


/// @brief: Defines the Log entry type instruction string type.
/// Used to display human understandable definitions of the log entry types
typedef struct {
	log_entry_e type;
	const char *str;
} log_entry_def_st;


extern const log_entry_def_st log_entry_defs[];


/// @brief: Returns the definition string of the log entry type
const char *log__entry_get_definition(log_entry_e type);

/// @brief: Returns the length of the log in entries
uint32_t log_size(void);


#endif /* LOG_H_ */
