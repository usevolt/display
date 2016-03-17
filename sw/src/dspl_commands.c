/*
 * dspl_commands.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include "dspl_commands.h"

#define this ((dspl_st*)me)

const uw_command_st terminal_commands[] = {

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

}
