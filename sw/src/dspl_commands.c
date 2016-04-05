/*
 * dspl_commands.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include "dspl_commands.h"
#include <uw_utilities.h>
#include <stdio.h>
#include <stdlib.h>

#define this ((dspl_st*)me)

const uw_command_st terminal_commands[] = {
		{
				.id = CMD_STEP_TIME,
				.str = "step",
				.instructions = "Sets the application step cycle time."
		}
};


/// @brief: Returns the pointer to terminal commands array
const uw_command_st * const dspl_commands(void) {
	return terminal_commands;
}


/// @brief: Returns the count how many terminal commands are
unsigned int dspl_commands_count(void) {
	return sizeof(terminal_commands) / sizeof(uw_command_st);
}


void dspl_command_callback(void *me, int command, char **args) {
	switch (command) {
	case CMD_STEP_TIME:
		if (*(args[0])) {
			this->step_cycle_ms = atoi(args[0]);
		}
		printf("%u\n\r", this->step_cycle_ms);
		break;
	default:
		break;
	}
}
