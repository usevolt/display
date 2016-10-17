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
#include "network.h"
#include "pin_mappings.h"
#include "main.h"
#include "log.h"
#include "alert.h"


#define this ((dspl_st*)me)


// Local duplication of the terminal command string. This is needed
// for the application specific command parsing
char arg_str[CONFIG_TERMINAL_BUFFER_SIZE] = "";


const uv_command_st terminal_commands[] = {
		{
				.id = CMD_MSB_CONF,
				.str = "msbconf",
				.instructions= "Configures Usewood MSB settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"msbconf <enable on/off> <node_id>",
				.callback = network_msb_conf
		},
		{
				.id = CMD_CSB_CONF,
				.str = "csbconf",
				.instructions= "Configures Usewood CSB settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"csbconf <enable on/off> <node_id>",
				.callback = network_csb_conf
		},
		{
				.id = CMD_LKEYP_CONF,
				.str = "lkeypconf",
				.instructions= "Configures Usevolt Left keypad settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"lkeypconf <enable on/off> <node_id>",
						.callback = network_lkeyp_conf
		},
		{
				.id = CMD_RKEYP_CONF,
				.str = "rkeypconf",
				.instructions= "Configures Usevolt Right keypad settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"rkeypconf <enable on/off> <node_id>",
						.callback = network_rkeyp_conf
		},
		{
				.id = CMD_ECU_CONF,
				.str = "ecuconf",
				.instructions= "Configures Rexroth ECU settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"ecuconf <enable on/off> <node_id>",
						.callback = network_ecu_conf
		},
		{
				.id = CMD_PEDAL_CONF,
				.str = "pedalconf",
				.instructions= "Configures the drive pedal settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"pedalconf <enable on/off> <node_id>",
						.callback = network_pedal_conf
		},
		{
				.id = CMD_UW181S_CONF,
				.str = "uw181sconf",
				.instructions= "Configures Usewood UW181S ecu settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"uw181sconf <enable on/off> <node_id>",
						.callback = network_uw181s_conf
		},
		{
				.id = CMD_UW181S_MB_CONF,
				.str = "uw181smbconf",
				.instructions= "Configures Usewood UW181S measurement device settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"uw181smbconf <enable on/off> <node_id>",
						.callback = network_uw181smb_conf
		},
		{
				.id = CMD_GSM_CONF,
				.str = "gsmconf",
				.instructions= "Configures Usevolt GSM board settings. Give without any arguments\n\r"
						"to display the settings without modifying them. Usage:\n\r"
						"gsmconf <enable on/off> <node_id>",
						.callback = network_gsm_conf
		},
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
				.instructions = "Sets the buzzer volume in ppt\n\r"
						"Usage: volume <0...1000>",
				.callback = volume_callb
		},
		{
				.id = CMD_TIME,
				.str = "time",
				.instructions = "Sets or gets the time from the RTC.\n\r"
						"Usage: time (year) (month) (day) (hour) (min) (sec)",
				.callback = time_callb
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
	printf("wrote %u bytes of 0x%x to address 0x%x\n\r", len, data, addr);
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

	printf("len: %u, args: %u\n\r", len, args);
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
			x, y, width, height, (uint32_t) argv[4].value);
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
			x, y, width, height, (uint32_t) argv[5].value, (uint32_t) argv[4].value);
	uv_lcd_draw_frame(x, y, width, height, (uint32_t) argv[4].value, (color_t) argv[5].value);
}


void lcdbacklight_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	if (!args || argv[0].type != INTEGER) {
		printf("Give argument between 0...100\n\r");
		return;
	}
	uint16_t b = argv[0].number;
	if (b > 100) {
		b = 100;
	}
	printf("Setting backlight PWM to %u percent\n\r", b);

	gui_set_backlight(this, b);
}

void refresh_callb(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	printf("Refreshing the display\n\r");
	uv_ui_refresh(&this->gui.display.super.super);
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
	printf("%u %u added to log %u times.\n\r", argv[0].number, argv[1].number, count);
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
			printf(": %s %i\n\r", def->param_def, entry.data);
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
	if (args && argv[0].number <= 1000) {
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




