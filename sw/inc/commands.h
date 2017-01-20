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
	CMD_EMC_WRITE = 0,
	CMD_EMC_READ,
	CMD_BACKLIGHT,
	CMD_REFRESH,
	CMD_LOG_CLEAR,
	CMD_LOG_SHOW,
	CMD_ALERT,
	CMD_VOLUME,
	CMD_TIME,
	CMD_USER,
	CMD_HOURS,
	CMD_SHOW,
	CMD_COUNT
} dspl_commands_e;


/// @brief: pointer to terminal commands array
extern const uv_command_st terminal_commands[];


/// @brief: Returns the count how many terminal commands are
unsigned int commands_count(void);



void emcwrite_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void emcread_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void eepromwrite_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void eepromread_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void lcddrawrect_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void lcddrawframe_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void lcdbacklight_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void refresh_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void logclear_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void logshow_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void alert_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void volume_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void time_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void user_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void hours_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void show_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);
void valvecfg_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv);


#endif /* COMMANDS_H_ */
