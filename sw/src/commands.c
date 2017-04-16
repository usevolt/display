/*
 * dspl_commands.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include <LPC177x_8x.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv_emc.h>
#include <uv_utilities.h>
#include <uv_eeprom.h>
#include <uv_lcd.h>
#include <uv_pwm.h>
#include <uv_rtc.h>
#include <time.h>
#include "commands.h"
#include "pin_mappings.h"
#include "main.h"
#include "users.h"
#include "log.h"
#include "gui.h"
#include "alert.h"
#include "vehicle.h"


#define this ((dspl_st*)me)


// Local duplication of the terminal command string. This is needed
// for the application specific command parsing
char arg_str[CONFIG_TERMINAL_BUFFER_SIZE] = "";


const uv_command_st terminal_commands[] = {
		{
				.id = CMD_EMC_WRITE,
				.str = "emcwrite",
				.instructions= "Write data to eternal SDRAM.\n"
						"Usage: emcwrite <addr> <count> <value>",
				.callback = emcwrite_callb
		},
		{
				.id = CMD_EMC_READ,
				.str = "emcread",
				.instructions= "Read data from external SDRAM.\n"
						"Usage: emcread <addr> <count>",
				.callback = emcread_callb
		},
		{
				.id = CMD_BACKLIGHT,
				.str = "backlight",
				.instructions = "Sets the display's backlight brightness PWM value.\n"
						"Usage: backlight <0...100>",
				.callback = lcdbacklight_callb
		},
		{
				.id = CMD_REFRESH,
				.str = "refresh",
				.instructions = "Refreshes the screen.\n"
						"Usage: refresh",
				.callback = refresh_callb
		},
		{
				.id = CMD_LOG_CLEAR,
				.str = "logclear",
				.instructions = "Clears the log\n"
						"Usage: logclear",
				.callback = logclear_callb
		},
		{
				.id = CMD_LOG_SHOW,
				.str = "logshow",
				.instructions = "Shows all log entries\n"
						"Usage: logshow",
				.callback = logshow_callb
		},
		{
				.id = CMD_ALERT,
				.str = "alert",
				.instructions = "Plays different alert sounds with the buzzer depending\n"
						"on the parameter given.\n"
						"Usage: alert <alert_enum>",
				.callback = alert_callb
		},
		{
				.id = CMD_VOLUME,
				.str = "volume",
				.instructions = "Sets the buzzer volume in percents\n"
						"Usage: volume <0...100>",
				.callback = volume_callb
		},
		{
				.id = CMD_TIME,
				.str = "time",
				.instructions = "Sets or gets the time from the RTC.\n"
						"Usage: time (year) (month) (day) (hour) (min) (sec)",
				.callback = time_callb
		},
		{
				.id = CMD_USER,
				.str = "user",
				.instructions = "Adds or deletes users, or sets the current user.\n"
						"Usage: user (\"add\"/\"remove\"/\"set\"/\"clear\") (username)",
				.callback = user_callb
		},
		{
				.id = CMD_HOURS,
				.str = "hours",
				.instructions = "Displays or sets the usage calculator hours.\n"
						"Usage: hours (set_hours) (password)",
				.callback = hours_callb
		},
		{
				.id = CMD_SHOW,
				.str = "show",
				.instructions = "Shows the given UI window on the display.\n"
						"Usage: show <\"login\"/\"home\"/...>",
				.callback = show_callb
		}
};



/// @brief: Returns the count how many terminal commands are
unsigned int commands_count(void) {
	return sizeof(terminal_commands) / sizeof(uv_command_st);
}




void emcwrite_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 3) {
		printf("Give 3 arguments\n");
		return;
	}
	uint8_t data = (uint8_t) argv[2].number;
	uint8_t* addr = (uint8_t*) (EMC_SDRAM_1 + (uint32_t) argv[0].value);
	uint32_t len = (uint32_t) argv[1].value;

	memset(addr, data, len);
	printf("wrote %u bytes of 0x%x to address 0x%x\n", (unsigned int) len,
			(unsigned int) data, (unsigned int) addr);
}

void emcread_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 2) {
		printf("Give 2 arguments\n");
		return;
	}
	volatile uint8_t data;
	uint8_t *addr = (uint8_t*) (EMC_SDRAM_1 + (uint32_t) argv[0].number);
	uint32_t len = (uint32_t) argv[1].value;
	int i;

	printf("len: %u, args: %u\n", (unsigned int) len, (unsigned int) args);
	printf("data: ");
	for (i = 0; i < len; i++) {
		data = *(addr + i);
		printf("0x%x ", data);
	}
	printf("\n");
}


void lcdbacklight_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	uint16_t b = gui_get_backlight();
	if (args && argv[0].type == ARG_INTEGER) {
		b = argv[0].number;
		if (b > 100) {
			b = 100;
		}
		gui_set_backlight(b);
	}

	printf("Backlight %u\n", b);
}

void refresh_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	printf("Refreshing the display\n");
	uv_ui_refresh_parent(&gui.display);
}


void logclear_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	log_clear();
	printf("log cleared\n");
}

void logshow_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	uint16_t i = 0;
	while (true) {
		log_entry_st entry;
		bool p = log_get(&entry, i);
		if (!p) {
			break;
		}
		const log_entry_def_st *def = log_entry_get_definition(entry.type);
		uv_time_st *tim = &entry.time;
		printf("%u: %u-%u-%u %u:%u:%u ack: %u %s",
				i, tim->year, tim->month, tim->day,
				tim->hour, tim->min, tim->sec, entry.ack, def->def);
		if (strlen(def->param_def)) {
			printf(": %s %i\n", def->param_def, (int) entry.data);
		}
		else {
			printf("\n");
		}
		i++;
	}
}

void alert_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args) {
		printf("Give 1 argument\n");
		return;
	}
	if (argv[0].number < ALERT_COUNT) {
		alert_play(&this->alert, argv[0].number);
	}
}

void volume_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args && argv[0].number <= 100) {
		alert_set_volume(&this->alert, argv[0].number);
	}
	printf("Volume: %u\n", alert_get_volume(&this->alert));
}


void time_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	uv_time_st time;
	if (!args) {
		uv_rtc_get_time(&time);
	}
	else if (args < 6) {
		printf("Give 6 arguments\n");
		return;
	}
	else {
		time.year = argv[0].number;
		time.month = argv[1].number;
		time.day = argv[2].number;
		time.hour = argv[3].number;
		time.min = argv[4].number;
		time.sec = argv[5].number;
		uv_rtc_set_time(&time);
	}
	printf("%i-%i-%i %i:%i:%i\n", time.year, time.month, time.day,
			time.hour, time.min, time.sec);
}


void user_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args) {
		printf("User count: %u/%u\n", uv_vector_size(&this->users), uv_vector_max_size(&this->users));
		printf("Users:\n");
		user_e i;
		for (i = 0; i < uv_vector_size(&this->users); i++) {
			if (strlen(((userdata_st*) uv_vector_at(&this->users, i))->username)) {
				printf("'%s'\n", ((userdata_st*) uv_vector_at(&this->users, i))->username);
			}
		}
		if (users_count()) {
			printf("Active user: %s\n", this->user->username);
		}
	}
	else if (strcmp(argv[0].str, "add") == 0 && args >= 2) {
		if (!users_add(argv[1].str)) {
			printf("Too many users\n");
			return;
		}
		printf("Added %s\n", argv[1].str);
	}
	else if (strcmp(argv[0].str, "remove") == 0 && args >= 2) {
		if (users_delete(argv[1].str)) {
			printf("Removed %s\n", argv[1].str);
		}
	}
	else if (strcmp(argv[0].str, "set") == 0 && args >= 2) {
		if (users_set(argv[1].str)) {
			printf("Current user: %s\n", this->user->username);
		}
	}
	else if (strcmp(argv[0].str, "clear") == 0) {
		users_clear();
	}
}

void hours_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args >= 2) {
		if (strcmp(argv[1].str, "usewoodfi") == 0) {
			this->hour_counter = argv[0].number;
			uv_eeprom_write((unsigned char*) &this->hour_counter,
					sizeof(this->hour_counter), HOUR_COUNTER_EEPROM_ADDR);
		}
		else {
			printf("Wrong password\n");
		}
	}
	printf("Hours: %u\n", this->hour_counter);
}

void show_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args) {
		printf("Give 1 argument\n");
		return;
	}
	else if (strcmp(argv[0].str, "login") == 0) {
		login_show();
	}
	else if (strcmp(argv[0].str, "home") == 0 || strcmp(argv[0].str, "menu") == 0) {
		home_show();
	}
	else if (strcmp(argv[0].str, "system") == 0) {
		system_show();
	}
	else if (strcmp(argv[0].str, "settings") == 0) {
		settings_show();
	}
}




