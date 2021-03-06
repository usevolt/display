/*
 * uv_hal_config.h
 *
 *  Created on: Mar 22, 2016
 *      Author: usevolt
 */

#ifndef UV_HAL_CONFIG_H_
#define UV_HAL_CONFIG_H_

#include "vehicle.h"
#include "can_display.h"
#include "can_esb.h"
#include "can_csb.h"
#include "can_fsb.h"
#include "can_hcu.h"
#include "can_ccu.h"
#include "can_icu.h"
#include "can_keypad.h"
#include "can_pedal.h"


/**** USER CONFIGURATIONS ****/


#define CONFIG_INTERFACE_REVISION					1


/* Defines the build target MCU family
 *
 * NOTE: Only one target MCU should be defined! */
#define CONFIG_TARGET_LPC11C14						0
#define CONFIG_TARGET_LPC1549						0
#define CONFIG_TARGET_LPC1785						1


#define CONFIG_UV_BOOTLOADER						1

#define CONFIG_LOG_ERRORS							1
#define CONFIG_INFORMATIVE_ERRORS					0

#define CONFIG_DMA									1

#define CONFIG_RTC									1


#define CONFIG_EEPROM								1
#define CONFIG_EEPROM_RING_BUFFER_END_ADDR			4020


#define CONFIG_SPI0									0


#define CONFIG_WDT									0
#define CONFIG_WDT_CYCLE_S							2


#define CONFIG_PWM									1
#define CONFIG_PWM_FREQ								10000
#define CONFIG_PWM1_1								1
#define CONFIG_PWM1_1_IO_CONF()						do { LPC_IOCON->P3_24 = 0b010; } while (0)
#define CONFIG_PWM1_2								1
#define CONFIG_PWM1_2_IO_CONF()						do { LPC_IOCON->P3_25 = 0b010; } while (0)



#define CONFIG_UI									1
#define CONFIG_UI_TOUCHSCREEN						1
#define CONFIG_UI_LIST_ENTRY_HEIGHT					50
#define CONFIG_UI_SLIDER_WIDTH						50
#define CONFIG_UI_SLIDER_INC_DEC_WIDTH				50
#define CONFIG_UI_TABWINDOW_HEADER_HEIGHT			50
#define CONFIG_UI_TABWINDOW_HEADER_MIN_WIDTH		150
#define CONFIG_UI_PROGRESSBAR_WIDTH					4
#define CONFIG_UI_PROGRESSBAR_SPACE					3
#define CONFIG_UI_PROGRESSBAR_HEIGHT				30
#define CONFIG_UI_WINDOW_SCROLLBAR_WIDTH			7
#define CONFIG_UI_TREEVIEW_ITEM_HEIGHT				60
#define CONFIG_UI_TREEVIEW_ARROW_FONT				UI_FONT_BIG
#define CONFIG_UI_DISPLAY_H							"main.h"

#define CONFIG_UI_STYLES_COUNT						1
#define CONFIG_UI_STYLE_ACTIVE_BG_C_1				C(0x73571b)
#define CONFIG_UI_STYLE_ACTIVE_FG_C_1				C(0xb0780a)
#define CONFIG_UI_STYLE_ACTIVE_FRAME_C_1			C(0xffa302)
#define CONFIG_UI_STYLE_ACTIVE_FONT_C_1				C(0xFFFFFF)
#define CONFIG_UI_STYLE_INACTIVE_BG_C_1				C(0x2a2a04)
#define CONFIG_UI_STYLE_INACTIVE_FG_C_1				C(0x000000)
#define CONFIG_UI_STYLE_INACTIVE_FRAME_C_1			C(0xdf8302)
#define CONFIG_UI_STYLE_INACTIVE_FONT_C_1			C(0xFFFFFF)
#define CONFIG_UI_STYLE_FONT_1						UI_FONT_SMALL
#define CONFIG_UI_STYLE_TEXT_COLOR_1				C(0xFFFFFF)
#define CONFIG_UI_STYLE_WINDOW_C_1					C(0x000000)
#define CONFIG_UI_STYLE_DISPLAY_C_1					C(0x000000)
#define CONFIG_UI_STYLE_SHADOW_C_1					C(0x000000)
#define CONFIG_UI_STYLE_HIGHLIGHT_C_1				C(0x000000)

#define HOME_BUTTON_STYLE_INDEX						0
#define DEFAULT_BUTTON_STYLE_INDEX					0
#define CANCEL_OK_BUTTON_STYLE_INDEX				0

#define WINDOW_STYLE_INDEX							0
#define TASKBAR_STYLE_INDEX							1

#define UI_LOG_WARNING_BG_C							C(0xFFFF00)
#define UI_LOG_ERROR_BG_C							C(0xFF0000)

/* Possible font sizes for uv_hal_config configuration file fonts */
#define UI_FONT_SMALL								font_8X14
#define UI_FONT_BIG									font_16X26
#define UI_DIGIT_BIG								num_32X53
#define CONFIG_UI_FONT_4X6							0
#define CONFIG_UI_FONT_5X8							0
#define CONFIG_UI_FONT_5X12							0
#define CONFIG_UI_FONT_6X8							0
#define CONFIG_UI_FONT_6X10							0
#define CONFIG_UI_FONT_7X12							0
#define CONFIG_UI_FONT_8X8							0
#define CONFIG_UI_FONT_8X12							0
#define CONFIG_UI_FONT_8X14							1
#define CONFIG_UI_FONT_10X16						0
#define CONFIG_UI_FONT_12X16						0
#define CONFIG_UI_FONT_12X20						0
#define CONFIG_UI_FONT_16X26						1
#define CONFIG_UI_FONT_22X36						0
#define CONFIG_UI_FONT_24X40						0
#define CONFIG_UI_FONT_32X53						0

#define CONFIG_UI_NUM_12X20							0
#define CONFIG_UI_NUM_16X26							0
#define CONFIG_UI_NUM_22X36							0
#define CONFIG_UI_NUM_24X40							0
#define CONFIG_UI_NUM_32X53							1

#define CONFIG_UI_CLICK_THRESHOLD					20


#define CONFIG_LCD									1
#define CONFIG_LCD_FREQ								45000000
#define CONFIG_LCD_DOUBLE_BUFFER					0
#define CONFIG_LCD_BUFFER_ADDRESS					EMC_SDRAM_1
#define CONFIG_LCD_DOUBLE_BUFFER_ADDRESS			(EMC_SDRAM_1 + CONFIG_LCD_PIXELS_PER_LINE * \
														CONFIG_LCD_LINES_PER_PANEL * sizeof(LCD_PIXEL_TYPE))
#define CONFIG_LCD_PIXELS_PER_LINE					800
#define CONFIG_LCD_HSYNC_PULSE_WIDTH				48
#define CONFIG_LCD_H_FRONT_PORCH					40
#define CONFIG_LCD_H_BACK_PORCH						88
#define CONFIG_LCD_LINES_PER_PANEL					480
#define CONFIG_LCD_VSYNC_PULSE_WIDTH				3
#define CONFIG_LCD_V_FRONT_PORCH					13
#define CONFIG_LCD_V_BACK_PORCH						32
#define CONFIG_LCD_INVERT_PANEL_CLOCK				1
#define CONFIG_LCD_INVERT_HSYNC						1
#define CONFIG_LCD_INVERT_VSYNC						1
#define CONFIG_LCD_RGB_TO_BGR						1
#define CONFIG_LCD_BITS_PER_PIXEL					LCD_16_BPP_RGB565
#define CONFIG_LCD_PWR_IOCON						LPC_IOCON->P2_0 = 0x7 | (1 << 9)
#define CONFIG_LCD_DCLK_IOCON						LPC_IOCON->P2_2 = 0x7 | (1 << 9)
#define CONFIG_LCD_ENAB_M_IOCON						LPC_IOCON->P2_4 = 0x7 | (1 << 9)
#define CONFIG_LCD_VSYNC_IOCON						LPC_IOCON->P2_3 = 0x7 | (1 << 9)
#define CONFIG_LCD_HSYNC_IOCON						LPC_IOCON->P2_5 = 0x7 | (1 << 9)
#define CONFIG_LCD_LE_IOCON
#define CONFIG_LCD_CLKIN_IOCON
#define CONFIG_LCD_VD0_IOCON						LPC_IOCON->P0_4 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD1_IOCON						LPC_IOCON->P0_5 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD2_IOCON						LPC_IOCON->P4_28 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD3_IOCON						LPC_IOCON->P4_29 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD4_IOCON						LPC_IOCON->P2_6 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD5_IOCON						LPC_IOCON->P2_7 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD6_IOCON						LPC_IOCON->P2_8 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD7_IOCON						LPC_IOCON->P2_9 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD8_IOCON						LPC_IOCON->P0_6 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD9_IOCON						LPC_IOCON->P0_7 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD10_IOCON						LPC_IOCON->P1_20 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD11_IOCON						LPC_IOCON->P1_21 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD12_IOCON						LPC_IOCON->P1_22 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD13_IOCON						LPC_IOCON->P1_23 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD14_IOCON						LPC_IOCON->P1_24 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD15_IOCON						LPC_IOCON->P1_25 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD16_IOCON						LPC_IOCON->P0_8 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD17_IOCON						LPC_IOCON->P0_9 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD18_IOCON						LPC_IOCON->P2_12 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD19_IOCON						LPC_IOCON->P2_13 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD20_IOCON						LPC_IOCON->P1_26 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD21_IOCON						LPC_IOCON->P1_27 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD22_IOCON						LPC_IOCON->P1_28 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD23_IOCON						LPC_IOCON->P1_29 = 0x7 | (1 << 9)

#define CONFIG_LCD_TOUCHSCREEN						1
#define CONFIG_LCD_TOUCH_THRESHOLD					200
#define CONFIG_LCD_X_R_ADC							ADC_1
#define CONFIG_LCD_X_R_GPIO							PIO0_24
#define CONFIG_LCD_X_L_ADC							ADC_3
#define CONFIG_LCD_X_L_GPIO							PIO0_26
#define CONFIG_LCD_Y_B_ADC							ADC_0
#define CONFIG_LCD_Y_B_GPIO							PIO0_23
#define CONFIG_LCD_Y_T_ADC							ADC_2
#define CONFIG_LCD_Y_T_GPIO							PIO0_25
#define CONFIG_LCD_X_MIN							540
#define CONFIG_LCD_Y_MIN							980
#define CONFIG_LCD_X_MAX							3776
#define CONFIG_LCD_Y_MAX							3228



#define CONFIG_EMC									1
#define CONFIG_EMC_DYNAMIC_RAM						1
#define CONFIG_EMC_SDRAM_1							1
#define CONFIG_EMC_SDRAM_2							0
#define CONFIG_EMC_SDRAM_3							0
#define CONFIG_EMC_SDRAM_4							0
#define CONFIG_EMC_STATIC_RAM						0
#define CONFIG_EMC_CHIP_COUNT						1
#define CONFIG_EMC_CLOCK_DIV_HALF					0
#define CONFIG_EMC_SDRAM_MODE_REGISTER				(0x33 << (2 + 8 + 1))
#define CONFIG_EMC_SDRAM_AM0						0b000101
#define CONFIG_EMC_SDRAM_AM1						0
#define CONFIG_EMC_SDRAM_RAS						3
#define CONFIG_EMC_SDRAM_CAS						3
#define CONFIG_EMC_SDRAM_REFRESH					54



#define CONFIG_RTOS									1
#define CONFIG_RTOS_HEAP_SIZE						26000


#define CONFIG_NON_VOLATILE_MEMORY					1
#define CONFIG_APP_ST								struct _dspl_st dspl
#define CONFIG_MAIN_H								"main.h"
#define CONFIG_NON_VOLATILE_START					dspl.data_start
#define CONFIG_NON_VOLATILE_END						dspl.data_end
#define CONFIG_NON_VOLATILE_START_ADDR				0x0001000






#define CONFIG_TERMINAL_UART						0
#define CONFIG_TERMINAL_CAN							1
#define CONFIG_TERMINAL_BUFFER_SIZE					200
#define CONFIG_TERMINAL_ARG_COUNT					9
#define CONFIG_TERMINAL_INSTRUCTIONS				1
#define CONFIG_TERMINAL_DEDICATED_CALLBACKS 		1



#define CONFIG_CAN									1
#define CONFIG_CAN0									1
#define CONFIG_CAN0_TX_PIN							PIO0_1
#define CONFIG_CAN0_RX_PIN							PIO0_0
#define CONFIG_CAN1									0
#define CONFIG_CAN_LOG								0
#define CONFIG_CAN_ERROR_LOG						0
#define CONFIG_CAN0_BAUDRATE						250000
#define CONFIG_CAN0_TX_BUFFER_SIZE					200
#define CONFIG_CAN0_RX_BUFFER_SIZE					400
#define CONFIG_CAN1_BAUDRATE						250000
#define CONFIG_CAN1_TX_BUFFER_SIZE					1
#define CONFIG_CAN1_RX_BUFFER_SIZE					1





#define CONFIG_CANOPEN								1
#define CONFIG_CANOPEN_LOG							0
#define CONFIG_CANOPEN_CHANNEL						CAN0
#define CONFIG_CANOPEN_RXPDO_COUNT					14
#define CONFIG_CANOPEN_TXPDO_COUNT					0
#define CONFIG_CANOPEN_OBJ_DICT_APP_PARAMS			obj_dict
#define CONFIG_CANOPEN_OBJ_DICT_APP_PARAMS_COUNT	object_dictionary_size
#define CONFIG_CANOPEN_SDO_SYNC						1
#define CONFIG_CANOPEN_SDO_SEGMENTED				0
#define CONFIG_CANOPEN_SDO_TIMEOUT_MS				80
#define CONFIG_CANOPEN_EMCY_RX_BUFFER_SIZE			5
#define CONFIG_CANOPEN_EMCY_MSG_COUNT				1
#define CONFIG_CANOPEN_EMCY_MSG_ID_1				0x90


#define CONFIG_CANOPEN_DEFAULT_NODE_ID				0xE
#define CONFIG_CANOPEN_PRODUCER_HEARTBEAT_TIME_MS	1000
#define CONFIG_CANOPEN_CONSUMER_HEARTBEAT_COUNT		11
#define CONFIG_CANOPEN_DEVICE_TYPE					0
#define CONFIG_CANOPEN_VENDOR_ID					0
#define CONFIG_CANOPEN_PRODUCT_CODE					0x00A60000
#define CONFIG_CANOPEN_REVISION_CODE				2

#define CONFIG_CANOPEN_RXPDO1_ID					(CANOPEN_TXPDO1_ID + ESB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO1_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_TOTAL_CURRENT_INDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_SUB_INDEX	ESB_TOTAL_CURRENT_SUBINDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_LEN			CANOPEN_TYPE_LEN(ESB_TOTAL_CURRENT_TYPE)
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_RPM_INDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_SUB_INDEX	ESB_RPM_SUBINDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_LEN			CANOPEN_TYPE_LEN(ESB_RPM_TYPE)
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_ALT_L_INDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_SUB_INDEX	ESB_ALT_L_SUBINDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_LEN			CANOPEN_TYPE_LEN(ESB_ALT_L_TYPE)
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_MOTOR_WATER_TEMP_INDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_SUB_INDEX	ESB_MOTOR_WATER_TEMP_SUBINDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_LEN			CANOPEN_TYPE_LEN(ESB_MOTOR_WATER_TEMP_TYPE)
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_MOTOR_OIL_PRESS_INDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_SUB_INDEX	ESB_MOTOR_OIL_PRESS_SUBINDEX
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_LEN			CANOPEN_TYPE_LEN(ESB_MOTOR_OIL_PRESS_TYPE)
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO2_ID					(CANOPEN_TXPDO2_ID + ESB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO2_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_MOTOR_TEMP_INDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_SUB_INDEX	ESB_MOTOR_TEMP_SUBINDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_LEN			CANOPEN_TYPE_LEN(ESB_MOTOR_TEMP_TYPE)
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_OIL_TEMP_INDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_SUB_INDEX	ESB_OIL_TEMP_SUBINDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_LEN			CANOPEN_TYPE_LEN(ESB_OIL_TEMP_TYPE)
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_OIL_LEVEL_INDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_SUB_INDEX	ESB_OIL_LEVEL_SUBINDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_LEN			CANOPEN_TYPE_LEN(ESB_OIL_LEVEL_TYPE)
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_LEN			CANOPEN_TYPE_LEN(ESB_OIL_LEVEL_TYPE)
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_VDD_INDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_SUB_INDEX	ESB_VDD_SUBINDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_LEN			CANOPEN_TYPE_LEN(ESB_VDD_TYPE)
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_MAIN_INDEX	DSPL_ESB_OFFSET + ESB_GLOW_STATUS_INDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_SUB_INDEX	ESB_GLOW_STATUS_SUBINDEX
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_LEN			CANOPEN_TYPE_LEN(ESB_GLOW_STATUS_TYPE)
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO3_ID					(CANOPEN_TXPDO1_ID + LKEYPAD_NODE_ID)
#define CONFIG_CANOPEN_RXPDO3_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO3_MAPPING1_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYX_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO3_MAPPING1_LEN			CANOPEN_TYPE_LEN(KEYP_JOYX_TYPE)
#define CONFIG_CANOPEN_RXPDO3_MAPPING2_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYX_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO3_MAPPING2_LEN			CANOPEN_TYPE_LEN(KEYP_JOYX_TYPE)
#define CONFIG_CANOPEN_RXPDO3_MAPPING3_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYY_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING3_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO3_MAPPING3_LEN			CANOPEN_TYPE_LEN(KEYP_JOYY_TYPE)
#define CONFIG_CANOPEN_RXPDO3_MAPPING4_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYY_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING4_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO3_MAPPING4_LEN			CANOPEN_TYPE_LEN(KEYP_JOYY_TYPE)
#define CONFIG_CANOPEN_RXPDO3_MAPPING5_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYZ_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING5_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO3_MAPPING5_LEN			CANOPEN_TYPE_LEN(KEYP_JOYZ_TYPE)
#define CONFIG_CANOPEN_RXPDO3_MAPPING6_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYZ_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING6_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO3_MAPPING6_LEN			CANOPEN_TYPE_LEN(KEYP_JOYZ_TYPE)
#define CONFIG_CANOPEN_RXPDO3_MAPPING7_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYV_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING7_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO3_MAPPING7_LEN			CANOPEN_TYPE_LEN(KEYP_JOYV_TYPE)
#define CONFIG_CANOPEN_RXPDO3_MAPPING8_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_JOYV_INDEX
#define CONFIG_CANOPEN_RXPDO3_MAPPING8_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO3_MAPPING8_LEN			CANOPEN_TYPE_LEN(KEYP_JOYV_TYPE)

#define CONFIG_CANOPEN_RXPDO4_ID					(CANOPEN_TXPDO2_ID + LKEYPAD_NODE_ID)
#define CONFIG_CANOPEN_RXPDO4_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO4_MAPPING1_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO4_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO4_MAPPING1_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO4_MAPPING2_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO4_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO4_MAPPING2_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO4_MAPPING3_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO4_MAPPING3_SUB_INDEX	3
#define CONFIG_CANOPEN_RXPDO4_MAPPING3_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO4_MAPPING4_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO4_MAPPING4_SUB_INDEX	4
#define CONFIG_CANOPEN_RXPDO4_MAPPING4_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO4_MAPPING5_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO4_MAPPING5_SUB_INDEX	5
#define CONFIG_CANOPEN_RXPDO4_MAPPING5_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO4_MAPPING6_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO4_MAPPING6_SUB_INDEX	6
#define CONFIG_CANOPEN_RXPDO4_MAPPING6_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO4_MAPPING7_MAIN_INDEX	DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO4_MAPPING7_SUB_INDEX	7
#define CONFIG_CANOPEN_RXPDO4_MAPPING7_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO4_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO5_ID					(CANOPEN_TXPDO1_ID + RKEYPAD_NODE_ID)
#define CONFIG_CANOPEN_RXPDO5_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO5_MAPPING1_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYX_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO5_MAPPING1_LEN			CANOPEN_TYPE_LEN(KEYP_JOYX_TYPE)
#define CONFIG_CANOPEN_RXPDO5_MAPPING2_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYX_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO5_MAPPING2_LEN			CANOPEN_TYPE_LEN(KEYP_JOYX_TYPE)
#define CONFIG_CANOPEN_RXPDO5_MAPPING3_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYY_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING3_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO5_MAPPING3_LEN			CANOPEN_TYPE_LEN(KEYP_JOYY_TYPE)
#define CONFIG_CANOPEN_RXPDO5_MAPPING4_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYY_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING4_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO5_MAPPING4_LEN			CANOPEN_TYPE_LEN(KEYP_JOYY_TYPE)
#define CONFIG_CANOPEN_RXPDO5_MAPPING5_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYZ_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING5_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO5_MAPPING5_LEN			CANOPEN_TYPE_LEN(KEYP_JOYZ_TYPE)
#define CONFIG_CANOPEN_RXPDO5_MAPPING6_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYZ_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING6_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO5_MAPPING6_LEN			CANOPEN_TYPE_LEN(KEYP_JOYZ_TYPE)
#define CONFIG_CANOPEN_RXPDO5_MAPPING7_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYV_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING7_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO5_MAPPING7_LEN			CANOPEN_TYPE_LEN(KEYP_JOYV_TYPE)
#define CONFIG_CANOPEN_RXPDO5_MAPPING8_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_JOYV_INDEX
#define CONFIG_CANOPEN_RXPDO5_MAPPING8_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO5_MAPPING8_LEN			CANOPEN_TYPE_LEN(KEYP_JOYV_TYPE)

#define CONFIG_CANOPEN_RXPDO6_ID					(CANOPEN_TXPDO2_ID + RKEYPAD_NODE_ID)
#define CONFIG_CANOPEN_RXPDO6_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO6_MAPPING1_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO6_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO6_MAPPING1_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO6_MAPPING2_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO6_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO6_MAPPING2_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO6_MAPPING3_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO6_MAPPING3_SUB_INDEX	3
#define CONFIG_CANOPEN_RXPDO6_MAPPING3_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO6_MAPPING4_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO6_MAPPING4_SUB_INDEX	4
#define CONFIG_CANOPEN_RXPDO6_MAPPING4_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO6_MAPPING5_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO6_MAPPING5_SUB_INDEX	5
#define CONFIG_CANOPEN_RXPDO6_MAPPING5_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO6_MAPPING6_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO6_MAPPING6_SUB_INDEX	6
#define CONFIG_CANOPEN_RXPDO6_MAPPING6_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO6_MAPPING7_MAIN_INDEX	DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX
#define CONFIG_CANOPEN_RXPDO6_MAPPING7_SUB_INDEX	7
#define CONFIG_CANOPEN_RXPDO6_MAPPING7_LEN			CANOPEN_TYPE_LEN(KEYP_BUTTON1_TYPE)
#define CONFIG_CANOPEN_RXPDO6_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO7_ID					(CANOPEN_TXPDO2_ID + PEDAL_NODE_ID)
#define CONFIG_CANOPEN_RXPDO7_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO7_MAPPING1_MAIN_INDEX	DSPL_PEDAL_OFFSET + DSPL_PEDAL_VALUE_INDEX
#define CONFIG_CANOPEN_RXPDO7_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO7_MAPPING1_LEN			CANOPEN_TYPE_LEN(DSPL_PEDAL_VALUE_TYPE)
#define CONFIG_CANOPEN_RXPDO7_MAPPING2_MAIN_INDEX	DSPL_PEDAL_OFFSET + DSPL_PEDAL_VALUE_INDEX
#define CONFIG_CANOPEN_RXPDO7_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO7_MAPPING2_LEN			CANOPEN_TYPE_LEN(DSPL_PEDAL_VALUE_TYPE)
#define CONFIG_CANOPEN_RXPDO7_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING3_LEN			0
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_LEN			0
#define CONFIG_CANOPEN_RXPDO7_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO7_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO7_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO7_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO8_ID					(CANOPEN_TXPDO1_ID + FSB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO8_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO8_MAPPING1_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_TOTAL_CURRENT_INDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING1_SUB_INDEX	FSB_TOTAL_CURRENT_SUBINDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING1_LEN			CANOPEN_TYPE_LEN(FSB_TOTAL_CURRENT_TYPE)
#define CONFIG_CANOPEN_RXPDO8_MAPPING2_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_IGNKEY_INDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING2_SUB_INDEX	FSB_IGNKEY_SUBINDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING2_LEN			CANOPEN_TYPE_LEN(FSB_IGNKEY_TYPE)
#define CONFIG_CANOPEN_RXPDO8_MAPPING3_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_EMCY_INDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING3_SUB_INDEX	FSB_EMCY_SUBINDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING3_LEN			CANOPEN_TYPE_LEN(FSB_EMCY_TYPE)
#define CONFIG_CANOPEN_RXPDO8_MAPPING4_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_DOORSW1_INDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING4_SUB_INDEX	FSB_DOORSW1_SUBINDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING4_LEN			CANOPEN_TYPE_LEN(FSB_DOORSW1_TYPE)
#define CONFIG_CANOPEN_RXPDO8_MAPPING5_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_DOORSW2_INDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING5_SUB_INDEX	FSB_DOORSW2_SUBINDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING5_LEN			CANOPEN_TYPE_LEN(FSB_DOORSW2_TYPE)
#define CONFIG_CANOPEN_RXPDO8_MAPPING6_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_SEATSW_INDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING6_SUB_INDEX	FSB_SEATSW_SUBINDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING6_LEN			CANOPEN_TYPE_LEN(FSB_SEATSW_TYPE)
#define CONFIG_CANOPEN_RXPDO8_MAPPING7_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_HEATER_SPEED_INDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING7_SUB_INDEX	FSB_HEATER_SPEED_SUBINDEX
#define CONFIG_CANOPEN_RXPDO8_MAPPING7_LEN			CANOPEN_TYPE_LEN(FSB_HEATER_SPEED_TYPE)
#define CONFIG_CANOPEN_RXPDO8_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO9_ID					(CANOPEN_TXPDO2_ID + FSB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO9_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO9_MAPPING1_MAIN_INDEX	DSPL_FSB_OFFSET + FSB_FUEL_LEVEL_INDEX
#define CONFIG_CANOPEN_RXPDO9_MAPPING1_SUB_INDEX	FSB_FUEL_LEVEL_SUBINDEX
#define CONFIG_CANOPEN_RXPDO9_MAPPING1_LEN			CANOPEN_TYPE_LEN(FSB_FUEL_LEVEL_TYPE)
#define CONFIG_CANOPEN_RXPDO9_MAPPING2_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING2_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO9_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING3_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO9_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING4_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO9_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING5_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO9_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING6_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO9_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING7_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO9_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO10_ID					(CANOPEN_TXPDO1_ID + CSB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO10_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO10_MAPPING1_MAIN_INDEX	DSPL_CSB_OFFSET + CSB_TOTAL_CURRENT_INDEX
#define CONFIG_CANOPEN_RXPDO10_MAPPING1_SUB_INDEX	CSB_TOTAL_CURRENT_SUBINDEX
#define CONFIG_CANOPEN_RXPDO10_MAPPING1_LEN			CANOPEN_TYPE_LEN(CSB_TOTAL_CURRENT_TYPE)
#define CONFIG_CANOPEN_RXPDO10_MAPPING2_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING2_LEN			CANOPEN_TYPE_LEN(CSB_COOLER_P_TYPE)
#define CONFIG_CANOPEN_RXPDO10_MAPPING3_MAIN_INDEX	DSPL_CSB_OFFSET + CSB_WIPER_SPEED_INDEX
#define CONFIG_CANOPEN_RXPDO10_MAPPING3_SUB_INDEX	CSB_WIPER_SPEED_SUBINDEX
#define CONFIG_CANOPEN_RXPDO10_MAPPING3_LEN			CANOPEN_TYPE_LEN(CSB_WIPER_SPEED_TYPE)
#define CONFIG_CANOPEN_RXPDO10_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING4_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO10_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING5_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO10_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING6_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO10_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING7_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO10_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING8_LEN			CANOPEN_TYPE_LEN(0)

#define CONFIG_CANOPEN_RXPDO11_ID					(CANOPEN_TXPDO1_ID + HCU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO11_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO11_MAPPING1_MAIN_INDEX	DSPL_HCU_OFFSET + HCU_TOTAL_CURRENT_INDEX
#define CONFIG_CANOPEN_RXPDO11_MAPPING1_SUB_INDEX	HCU_TOTAL_CURRENT_SUBINDEX
#define CONFIG_CANOPEN_RXPDO11_MAPPING1_LEN			CANOPEN_TYPE_LEN(HCU_TOTAL_CURRENT_TYPE)
#define CONFIG_CANOPEN_RXPDO11_MAPPING2_MAIN_INDEX	DSPL_HCU_OFFSET + HCU_IMPLEMENT_INDEX
#define CONFIG_CANOPEN_RXPDO11_MAPPING2_SUB_INDEX	HCU_IMPLEMENT_SUBINDEX
#define CONFIG_CANOPEN_RXPDO11_MAPPING2_LEN			CANOPEN_TYPE_LEN(HCU_IMPLEMENT_TYPE)
#define CONFIG_CANOPEN_RXPDO11_MAPPING3_MAIN_INDEX	DSPL_HCU_OFFSET + HCU_PRESSURE_INDEX
#define CONFIG_CANOPEN_RXPDO11_MAPPING3_SUB_INDEX	HCU_PRESSURE_SUBINDEX
#define CONFIG_CANOPEN_RXPDO11_MAPPING3_LEN			CANOPEN_TYPE_LEN(HCU_PRESSURE_TYPE)
#define CONFIG_CANOPEN_RXPDO11_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING4_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO11_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING5_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO11_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING6_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO11_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING7_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO11_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING8_LEN			CANOPEN_TYPE_LEN(0)

#define CONFIG_CANOPEN_RXPDO12_ID					(CANOPEN_TXPDO1_ID + CCU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO12_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO12_MAPPING1_MAIN_INDEX	DSPL_CCU_OFFSET + CCU_TOTAL_CURRENT_INDEX
#define CONFIG_CANOPEN_RXPDO12_MAPPING1_SUB_INDEX	CCU_TOTAL_CURRENT_SUBINDEX
#define CONFIG_CANOPEN_RXPDO12_MAPPING1_LEN			CANOPEN_TYPE_LEN(CCU_TOTAL_CURRENT_TYPE)
#define CONFIG_CANOPEN_RXPDO12_MAPPING2_MAIN_INDEX	DSPL_CCU_OFFSET + CCU_GEAR_INDEX
#define CONFIG_CANOPEN_RXPDO12_MAPPING2_SUB_INDEX	CCU_GEAR_SUBINDEX
#define CONFIG_CANOPEN_RXPDO12_MAPPING2_LEN			CANOPEN_TYPE_LEN(CCU_GEAR_TYPE)
#define CONFIG_CANOPEN_RXPDO12_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING3_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO12_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING4_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO12_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING5_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO12_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING6_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO12_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING7_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO12_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING8_LEN			CANOPEN_TYPE_LEN(0)

#define CONFIG_CANOPEN_RXPDO13_ID					(CANOPEN_TXPDO1_ID + ICU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO13_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO13_MAPPING1_MAIN_INDEX	DSPL_ICU_OFFSET + ICU_TOTAL_CURRENT_INDEX
#define CONFIG_CANOPEN_RXPDO13_MAPPING1_SUB_INDEX	ICU_TOTAL_CURRENT_SUBINDEX
#define CONFIG_CANOPEN_RXPDO13_MAPPING1_LEN			CANOPEN_TYPE_LEN(ICU_TOTAL_CURRENT_TYPE)
#define CONFIG_CANOPEN_RXPDO13_MAPPING2_MAIN_INDEX	DSPL_ICU_OFFSET + ICU_LENGTH_UM_INDEX
#define CONFIG_CANOPEN_RXPDO13_MAPPING2_SUB_INDEX	ICU_LENGTH_UM_SUBINDEX
#define CONFIG_CANOPEN_RXPDO13_MAPPING2_LEN			CANOPEN_TYPE_LEN(ICU_LENGTH_UM_TYPE)
#define CONFIG_CANOPEN_RXPDO13_MAPPING3_MAIN_INDEX	DSPL_ICU_OFFSET + ICU_WIDTH_MM_INDEX
#define CONFIG_CANOPEN_RXPDO13_MAPPING3_SUB_INDEX	ICU_WIDTH_MM_SUBINDEX
#define CONFIG_CANOPEN_RXPDO13_MAPPING3_LEN			CANOPEN_TYPE_LEN(ICU_WIDTH_MM_TYPE)
#define CONFIG_CANOPEN_RXPDO13_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING4_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO13_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING5_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO13_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING6_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO13_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING7_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO13_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO13_MAPPING8_LEN			CANOPEN_TYPE_LEN(0)

#define CONFIG_CANOPEN_RXPDO14_ID					(CANOPEN_TXPDO2_ID + ICU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO14_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO14_MAPPING1_MAIN_INDEX	DSPL_ICU_OFFSET + ICU_VOL_DM3_INDEX
#define CONFIG_CANOPEN_RXPDO14_MAPPING1_SUB_INDEX	ICU_VOL_DM3_SUBINDEX
#define CONFIG_CANOPEN_RXPDO14_MAPPING1_LEN			CANOPEN_TYPE_LEN(ICU_VOL_DM3_TYPE)
#define CONFIG_CANOPEN_RXPDO14_MAPPING2_MAIN_INDEX	DSPL_ICU_OFFSET + 0
#define CONFIG_CANOPEN_RXPDO14_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING2_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO14_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING3_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO14_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING4_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO14_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING5_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO14_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING6_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO14_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING7_LEN			CANOPEN_TYPE_LEN(0)
#define CONFIG_CANOPEN_RXPDO14_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO14_MAPPING8_LEN			CANOPEN_TYPE_LEN(0)


#define CONFIG_ADC									1
#define CONFIG_ADC_MODE								ADC_MODE_SYNC
#define CONFIG_ADC_CONVERSION_FREQ					1000

#define CONFIG_ADC_CHANNEL0							1
#define CONFIG_ADC_CHANNEL1							1
#define CONFIG_ADC_CHANNEL2							1
#define CONFIG_ADC_CHANNEL3							1
#define CONFIG_ADC_CHANNEL4							1
#define CONFIG_ADC_CHANNEL5							0
#define CONFIG_ADC_CHANNEL6							0
#define CONFIG_ADC_CHANNEL7							0




#define CONFIG_OUTPUT								0


/**** END OF USER CONFIGURATIONS ****/




#endif /* UV_HAL_CONFIG_H_ */
