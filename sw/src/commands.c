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
				.instructions= "Write data to eternal SDRAM.\n\r"
						"Usage: emcwrite <addr> <count> <value>",
				.callback = emcwrite_callb
		},
		{
				.id = CMD_EMC_READ,
				.str = "emcread",
				.instructions= "Read data from external SDRAM.\n\r"
						"Usage: emcread <addr> <count>",
				.callback = emcread_callb
		},
		{
				.id = CMD_EEPROM_WRITE,
				.str = "eepromwrite",
				.instructions = "Write data to EEPROM.\n\r"
						"Usage: eepromwrite <addr> <count> <data>",
				.callback = eepromwrite_callb
		},
		{
				.id = CMD_EEPROM_READ,
				.str = "eepromread",
				.instructions = "Read data from EEPROM.\n\r"
						"Usage: eepromread <addr> <count>",
				.callback = eepromread_callb
		},
		{
				.id = CMD_LCD_RECT,
				.str = "drawrect",
				.instructions = "Draws a rectangle to the screen.\n\r"
						"Optional 6th argument specifies if the coordinates are to be interpreted \n\r"
						"as pixels or percents. Pixels are the default value.\n\r"
						"Usage: drawrect <x> <y> <width> <height> <color> (\"px\"/\"%\")",
				.callback = lcddrawrect_callb
		},
		{
				.id = CMD_LCD_FRAME,
				.str = "drawframe",
				.instructions = "Draws a frame to the screen.\n\r"
						"Optional 7th argument specifies if the coordinates are to be interpreted \n\r"
						"as pixels or percents. Pixels are the default value.\n\r"
						"Usage: drawrect <x> <y> <width> <height> <border> <color> (\"px\"/\"%\")",
				.callback = lcddrawframe_callb
		},
		{
				.id = CMD_BACKLIGHT,
				.str = "backlight",
				.instructions = "Sets the display's backlight brightness PWM value.\n\r"
						"Usage: backlight <0...100>",
				.callback = lcdbacklight_callb
		},
		{
				.id = CMD_REFRESH,
				.str = "refresh",
				.instructions = "Refreshes the screen.\n\r"
						"Usage: refresh",
				.callback = refresh_callb
		},
		{
				.id = CMD_LOG_CLEAR,
				.str = "logclear",
				.instructions = "Clears the log\n\r"
						"Usage: logclear",
				.callback = logclear_callb
		},
		{
				.id = CMD_LOG_ADD,
				.str = "logadd",
				.instructions = "Adds a new entry to the log.\n\r"
						"Optional 3rd argument can be used to add multiple entries at the same time.\n\r"
						"Usage: logadd <log_entry_enum> (data) (count)",
				.callback = logadd_callb
		},
		{
				.id = CMD_LOG_SHOW,
				.str = "logshow",
				.instructions = "Shows all log entries\n\r"
						"Usage: logshow",
				.callback = logshow_callb
		},
		{
				.id = CMD_ALERT,
				.str = "alert",
				.instructions = "Plays different alert sounds with the buzzer depending\n\r"
						"on the parameter given.\n\r"
						"Usage: alert <alert_enum>",
				.callback = alert_callb
		},
		{
				.id = CMD_VOLUME,
				.str = "volume",
				.instructions = "Sets the buzzer volume in percents\n\r"
						"Usage: volume <0...100>",
				.callback = volume_callb
		},
		{
				.id = CMD_TIME,
				.str = "time",
				.instructions = "Sets or gets the time from the RTC.\n\r"
						"Usage: time (year) (month) (day) (hour) (min) (sec)",
				.callback = time_callb
		},
		{
				.id = CMD_USER,
				.str = "user",
				.instructions = "Adds or deletes users, or sets the current user.\n\r"
						"Usage: user (\"add\"/\"remove\"/\"set\"/\"clear\") (username)",
				.callback = user_callb
		},
		{
				.id = CMD_HOURS,
				.str = "hours",
				.instructions = "Displays or sets the usage calculator hours.\n\r"
						"Usage: hours (set_hours) (password)",
				.callback = hours_callb
		},
		{
				.id = CMD_SHOW,
				.str = "show",
				.instructions = "Shows the given UI window on the display.\n\r"
						"Usage: show <\"login\"/\"home\"/...>",
				.callback = show_callb
		},
		{
				.id = CMD_VALVECFG,
				.str = "valve",
				.instructions = "Configures the valve. First parameter specifies\n\r"
						"the valve according to its name and second parameter\n\r"
						"specifies the parameter to be configured.\n\r"
						"Usage: valve <\"name\"> <\"pmin/pmax/nmin/nmax/acc/dec/invert\"> (value)",
				.callback = valvecfg_callb
		},
		{
				.id = CMD_SENSORS,
				.str = "sensors",
				.instructions = "Shows the values of oil level, fuel level,\n\r"
						"oil temp and motor temp sensors.\n\r"
						"Usage: sensors",
				.callback = sensors_callb
		}
};



/// @brief: Returns the count how many terminal commands are
unsigned int commands_count(void) {
	return sizeof(terminal_commands) / sizeof(uv_command_st);
}




void emcwrite_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 3) {
		printf("Give 3 arguments\n\r");
		return;
	}
	uint8_t data = (uint8_t) argv[2].number;
	uint8_t* addr = (uint8_t*) (EMC_SDRAM_1 + (uint32_t) argv[0].value);
	uint32_t len = (uint32_t) argv[1].value;

	memset(addr, data, len);
	printf("wrote %u bytes of 0x%x to address 0x%x\n\r", (unsigned int) len,
			(unsigned int) data, (unsigned int) addr);
}

void emcread_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 2) {
		printf("Give 2 arguments\n\r");
		return;
	}
	volatile uint8_t data;
	uint8_t *addr = (uint8_t*) (EMC_SDRAM_1 + (uint32_t) argv[0].number);
	uint32_t len = (uint32_t) argv[1].value;
	int i;

	printf("len: %u, args: %u\n\r", (unsigned int) len, (unsigned int) args);
	printf("data: ");
	for (i = 0; i < len; i++) {
		data = *(addr + i);
		printf("0x%x ", data);
	}
	printf("\n\r");
}
void eepromwrite_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 3) {
		printf("Give at least 3 arguments\n\r");
		return;
	}
	uint16_t addr = (uint32_t) argv[0].number;
	uint16_t len = (uint32_t) argv[1].number;
	uint8_t data = (uint32_t) argv[2].number;
	uint8_t d[len];
	memset(d, data, len);
	uv_errors_e e = uv_eeprom_write(d, len, addr);
	printf("Return: %u\n\r", UV_ERR_GET(e));
}
void eepromread_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 2) {
		printf("Give 2 arguments\n\r");
		return;
	}
	uint16_t addr = (uint32_t) argv[0].value;
	uint16_t len = (uint32_t) argv[1].value;
	uint8_t data[len];
	uv_eeprom_read(data, len, addr);
	printf("data: ");
	uint16_t i;
	for (i = 0; i < len; i++) {
		printf("%x ", data[i]);
	}
	printf("\n\r");
}

void lcddrawrect_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 5) {
		printf("Give at least 5 arguments\n\r");
		return;
	}
	uint32_t x, y, width, height;
	if (args >= 6 && strcmp(argv[5].value, "%") == 0) {

		x = LCD_W((int) argv[0].value / 100.0f);
		y = LCD_H((int) argv[1].value / 100.0f);
		width = LCD_W((int) argv[2].value / 100.0f);
		height = LCD_H((int) argv[3].value / 100.0f);
	}
	else {
		x = (uint32_t) argv[0].value;
		y = (uint32_t) argv[1].value;
		width = (uint32_t) argv[2].value;
		height = (uint32_t) argv[3].value;
	}
	printf("drawing rectangle from (%u, %u) to (%u, %u) with color %x\n\r",
			(unsigned int) x, (unsigned int) y, (unsigned int) width, (unsigned int) height,
			(unsigned int) argv[4].value);
	uv_lcd_draw_rect(x, y, width, height, (uint32_t) argv[4].value);
}

void lcddrawframe_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 6) {
		printf("Give at least 5 arguments\n\r");
		return;
	}
	uint32_t x, y, width, height;
	if (args > 6 && strcmp(argv[6].str, "%") == 0) {

		x = LCD_W(argv[0].number / 100.0f);
		y = LCD_H(argv[1].number / 100.0f);
		width = LCD_W(argv[2].number / 100.0f) - x;
		height = LCD_H(argv[3].number / 100.0f) - y;
	}
	else {
		x = (uint32_t) argv[0].value;
		y = (uint32_t) argv[1].value;
		width = (uint32_t) argv[2].value;
		height = (uint32_t) argv[3].value;
	}
	printf("drawing frame from (%u, %u) to (%u, %u) with color %x and border of %u\n\r",
			(unsigned int) x, (unsigned int) y, (unsigned int) width, (unsigned int) height,
			(unsigned int) argv[5].value, (unsigned int) argv[4].value);
	uv_lcd_draw_frame(x, y, width, height, (uint32_t) argv[4].value, (color_t) argv[5].value);
}


void lcdbacklight_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	uint16_t b = gui_get_backlight();
	if (args && argv[0].type == INTEGER) {
		b = argv[0].number;
		if (b > 100) {
			b = 100;
		}
		gui_set_backlight(b);
	}

	printf("Backlight %u\n\r", b);
}

void refresh_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	printf("Refreshing the display\n\r");
	uv_ui_refresh_parent(&gui.display);
}


void logclear_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	log_clear();
	printf("log cleared\n\r");
}
void logadd_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args) {
		printf("Give 1 argument\n\r");
		return;
	}
	uint16_t count = 1, i;
	if (args >= 3) count = argv[2].number;
	for (i = 0; i < count; i++) {
		log_add(argv[0].number, argv[1].number);
	}
	printf("%u %u added to log %u times.\n\r", (unsigned int) argv[0].number, (unsigned int) argv[1].number, count);
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
		printf("%u: %u-%u-%u %u:%u:%u %s",
				i, tim->year, tim->month, tim->day,
				tim->hour, tim->min, tim->sec, def->def);
		if (strlen(def->param_def)) {
			printf(": %s %i\n\r", def->param_def, (int) entry.data);
		}
		else {
			printf("\n\r");
		}
		i++;
	}
}

void alert_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args) {
		printf("Give 1 argument\n\r");
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
	printf("Volume: %u\n\r", alert_get_volume(&this->alert));
}


void time_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	uv_time_st time;
	if (!args) {
		uv_rtc_get_time(&time);
	}
	else if (args < 6) {
		printf("Give 6 arguments\n\r");
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
		log_add(LOG_TIME_SET, true);
	}
	printf("%i-%i-%i %i:%i:%i\n\r", time.year, time.month, time.day,
			time.hour, time.min, time.sec);
}


void user_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args) {
		printf("User count: %u/%u\n\r", uv_vector_size(&this->users), uv_vector_max_size(&this->users));
		printf("Users:\n\r");
		user_e i;
		for (i = 0; i < uv_vector_size(&this->users); i++) {
			if (strlen(((userdata_st*) uv_vector_at(&this->users, i))->username)) {
				printf("'%s'\n\r", ((userdata_st*) uv_vector_at(&this->users, i))->username);
			}
		}
		if (users_count()) {
			printf("Active user: %s\n\r", this->user->username);
		}

	}
	else if (strcmp(argv[0].str, "add") == 0 && args >= 2) {
		if (!users_add(argv[1].str)) {
			printf("Too many users\n\r");
			return;
		}
		printf("Added %s\n\r", argv[1].str);
	}
	else if (strcmp(argv[0].str, "remove") == 0 && args >= 2) {
		if (users_delete(argv[1].str)) {
			printf("Removed %s\n\r", argv[1].str);
		}
	}
	else if (strcmp(argv[0].str, "set") == 0 && args >= 2) {
		if (users_set(argv[1].str)) {
			printf("Current user: %s\n\r", this->user->username);
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
					sizeof(this->hour_counter), CONFIG_EEPROM_RING_BUFFER_END_ADDR);
		}
		else {
			printf("Wrong password\n\r");
		}
	}
	printf("Hours: %u\n\r", this->hour_counter);
}

void show_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args) {
		printf("Give 1 argument\n\r");
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
		int16_t i = 0;
		if (args >= 2) i = argv[1].number;
		settings_show(i);
	}
}

void valvecfg_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (args < 2) {
		printf("Give at least 2 arguments\n\r");
		return;
	}
	valve_st *valve = NULL;
	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		if (strcmp(this->user->base_valves[i].name, argv[0].str) == 0) {
			valve = &this->user->base_valves[i];
			break;
		}
	}
	if (!valve) {
		printf("No valve %s found\n\r", argv[0].str);
		return;
	}
	int16_t *value;
	if (strcmp(argv[1].str, "pmax") == 0) {
		value = &valve->max_speed_p;
	}
	else if (strcmp(argv[1].str, "pmin") == 0) {
		value = &valve->min_speed_p;
	}
	else if (strcmp(argv[1].str, "nmax") == 0) {
		value = &valve->max_speed_n;
	}
	else if (strcmp(argv[1].str, "nmin") == 0) {
		value = &valve->min_speed_n;
	}
	else if (strcmp(argv[1].str, "acc") == 0) {
		value = &valve->acc;
	}
	else if (strcmp(argv[1].str, "dec") == 0) {
		value = &valve->dec;
	}
	else if (strcmp(argv[1].str, "invert") == 0) {
		value = &valve->invert;
	}
	else {
		printf("Invalid valve parameter '%s'\n\r", argv[1].str);
		return;
	}
	if (args >= 3) {
		*value = argv[2].number;
	}
	printf("%u\n\r", *value);

}

void sensors_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	printf("Oil level: %i\n\rFuel level: %i\n\rOil temp: %i\n\rMotor temp: %i\n\r",
			this->oil_level, this->fuel_level, this->oil_temp, this->motor_temp);
}




