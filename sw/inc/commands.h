/*
 * dspl_commands.h
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_


#include <uv_terminal.h>
#include <stdarg.h>


/// @brief: Enum describing all commands
typedef enum {
	CMD_MSB_CONF,
	CMD_CSB_CONF,
	CMD_LKEYP_CONF,
	CMD_RKEYP_CONF,
	CMD_ECU_CONF,
	CMD_PEDAL_CONF,
	CMD_UW181S_CONF,
	CMD_UW181S_MB_CONF,
	CMD_GSM_CONF,
	CMD_EMC_WRITE,
	CMD_EMC_READ,
	CMD_EEPROM_WRITE,
	CMD_EEPROM_READ,
	CMD_COUNT
} dspl_commands_e;


/// @brief: Returns the pointer to terminal commands array
const uv_command_st * const commands(void);


/// @brief: Returns the count how many terminal commands are
unsigned int commands_count(void);



void emcwrite_callb(void *me, unsigned int cmd, unsigned int args, ...);
void emcread_callb(void *me, unsigned int cmd, unsigned int args, ...);
void eepromwrite_callb(void *me, unsigned int cmd, unsigned int args, ...);
void eepromread_callb(void *me, unsigned int cmd, unsigned int args, ...);



#endif /* COMMANDS_H_ */
