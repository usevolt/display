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
#include "commands.h"
#include "network.h"

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
						"Usage: emcwrite <value> <addr> <count>",
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
						"Usage: eepromwrite <data> <addr> <count>",
				.callback = eepromwrite_callb
		},
		{
				.id = CMD_EEPROM_READ,
				.str = "eepromread",
				.instructions = "Read data from EEPROM.\n\r"
						"Usage: eepromread <addr> <count>",
				.callback = eepromread_callb
		}
};


/// @brief: Returns the pointer to terminal commands array
const uv_command_st * const commands(void) {
	return terminal_commands;
}


/// @brief: Returns the count how many terminal commands are
unsigned int commands_count(void) {
	return sizeof(terminal_commands) / sizeof(uv_command_st);
}




void emcwrite_callb(void *me, unsigned int cmd, unsigned int args, ...) {
	if (args < 2) {
		printf("Give at least 2 arguments\n\r");
		return;
	}
	va_list l;
	va_start(l, args);
	uint32_t data = va_arg(l, int);
	uint32_t* addr = (uint32_t*) (EMC_SDRAM_1 + va_arg(l, int) * sizeof(*addr));
	uint32_t len = 1;
	if (args == 3) {
		len = va_arg(l, int);
	}
	va_end(l);
	memset(addr, data, len * 4);
	printf("wrote %u bytes of 0x%x to address 0x%x\n\r", len, data, addr);
}

void emcread_callb(void *me, unsigned int cmd, unsigned int args, ...) {
	if (args < 1) {
		printf("Give 1 argument\n\r");
		return;
	}
	va_list l;
	va_start(l, args);
	volatile uint32_t data;
	uint32_t *addr = (uint32_t*) (EMC_SDRAM_1 + va_arg(l, int) * sizeof(*addr));
	int32_t len = 1;
	if (args == 2) {
		len = va_arg(l, int);
	}
	va_end(l);
	int i;

	printf("len: %u, args: %u\n\r", len, args);
	printf("data: ");
	for (i = 0; i < len; i++) {
		data = *(addr + i);
		printf("0x%x ", data);
	}
	printf("\n\r");
}
void eepromwrite_callb(void *me, unsigned int cmd, unsigned int args, ...) {
	if (args < 2) {
		printf("Give at least 2 arguments\n\r");
		return;
	}
	va_list l;
	va_start(l, args);
	uint8_t data = va_arg(l, int);
	uint16_t addr = va_arg(l, int);
	uint16_t len = 1;
	if (args >= 3) len = va_arg(l, int);
	va_end(l);
	uint8_t d[len];
	memset(d, data, len);
	uv_errors_e e = uv_eeprom_write(d, len, addr);
	printf("Return: %u\n\r", UV_ERR_GET(e));
}
void eepromread_callb(void *me, unsigned int cmd, unsigned int args, ...) {
	if (args < 2) {
		printf("Give 2 arguments\n\r");
	}
	va_list l;
	va_start(l, args);
	uint16_t addr = va_arg(l, int);
	uint16_t len = va_arg(l, int);
	va_end(l);
	uint8_t data[len];
	uv_eeprom_read(data, len, addr);
	printf("data: ");
	uint16_t i;
	for (i = 0; i < len; i++) {
		printf("%x ", data[i]);
	}
	printf("\n\r");
}



