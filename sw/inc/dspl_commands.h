/*
 * dspl_commands.h
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#ifndef DSPL_COMMANDS_H_
#define DSPL_COMMANDS_H_


#include "dspl_main.h"
#include <uw_terminal.h>

/// @brief: Enum describing all commands
typedef enum {
	CMD_STEP_TIME,
	CMD_COUNT
} dspl_commands_e;


/// @brief: Returns the pointer to terminal commands array
const uw_command_st * const dspl_commands(void);


/// @brief: Returns the count how many terminal commands are
unsigned int dspl_commands_count(void);


/// @brife: Command callback
void dspl_command_callback(void *me, int command, char **args);



#endif /* DSPL_COMMANDS_H_ */
