/*
 * uv_hal_config.h
 *
 *  Created on: Mar 22, 2016
 *      Author: usevolt
 */

#ifndef UV_HAL_CONFIG_H_
#define UV_HAL_CONFIG_H_

#include "vehicle.h"

/**** USER CONFIGURATIONS ****/


/* Defines the build target MCU family
 *
 * NOTE: Only one target MCU should be defined! */
#define CONFIG_TARGET_LPC11C14			0
#define CONFIG_TARGET_LPC1549			0
#define CONFIG_TARGET_LPC1785			1





#define CONFIG_LOG_ERRORS				1
#define CONFIG_INFORMATIVE_ERRORS		0



#define CONFIG_RTC						1


#define CONFIG_EEPROM					1
#define CONFIG_EEPROM_RING_BUFFER_END_ADDR	4024


#define CONFIG_SPI0						1


#define CONFIG_WDT						0
#define CONFIG_WDT_CYCLE_S				2


#define CONFIG_PWM						1
#define CONFIG_PWM_FREQ					10000
#define CONFIG_PWM0_2					1
#define CONFIG_PWM1_3					1


#define HOME_BUTTON_STYLE_INDEX						0
#define DEFAULT_BUTTON_STYLE_INDEX					0
#define CANCEL_OK_BUTTON_STYLE_INDEX				0

#define CONFIG_UI_LIST_ENTRY_HEIGHT					50

#define CONFIG_UI_SLIDER_WIDTH						50
#define CONFIG_UI_SLIDER_INC_DEC_WIDTH				50

#define CONFIG_UI_TABWINDOW_HEADER_HEIGHT			50
#define CONFIG_UI_TABWINDOW_HEADER_MIN_WIDTH		150

#define WINDOW_STYLE_INDEX							0
#define TASKBAR_STYLE_INDEX							1

#define CONFIG_UI_PROGRESSBAR_WIDTH					4
#define CONFIG_UI_PROGRESSBAR_SPACE					3
#define CONFIG_UI_PROGRESSBAR_HEIGHT				30


#define CONFIG_UI_STYLES_COUNT					1
#define CONFIG_UI_STYLE_ACTIVE_BG_C_1			C(0x009900)
#define CONFIG_UI_STYLE_ACTIVE_FG_C_1			C(0x00BB00)
#define CONFIG_UI_STYLE_ACTIVE_FRAME_C_1		C(0x66FF66)
#define CONFIG_UI_STYLE_ACTIVE_FONT_C_1			C(0xFFFFFF)
#define CONFIG_UI_STYLE_INACTIVE_BG_C_1			C(0x2a2a11)
#define CONFIG_UI_STYLE_INACTIVE_FG_C_1			C(0x444444)
#define CONFIG_UI_STYLE_INACTIVE_FRAME_C_1		C(0x888888)
#define CONFIG_UI_STYLE_INACTIVE_FONT_C_1		C(0xFFFFFF)
#define CONFIG_UI_STYLE_FONT_1					UI_FONT_SMALL
#define CONFIG_UI_STYLE_TEXT_COLOR_1			C(0xFFFFFF)
#define CONFIG_UI_STYLE_WINDOW_C_1				C(0x000000)



#define UI_LOG_WARNING_BG_C						C(0xFFFF00)
#define UI_LOG_ERROR_BG_C						C(0xFF0000)

/* Possible font sizes for uv_hal_config configuration file fonts */
#define UI_FONT_SMALL					font_8X14
#define UI_FONT_BIG						font_16X26
#define UI_DIGIT_BIG					num_32X53
#define CONFIG_UI_FONT_4X6				0
#define CONFIG_UI_FONT_5X8				0
#define CONFIG_UI_FONT_5X12				0
#define CONFIG_UI_FONT_6X8				0
#define CONFIG_UI_FONT_6X10				0
#define CONFIG_UI_FONT_7X12				0
#define CONFIG_UI_FONT_8X8				0
#define CONFIG_UI_FONT_8X12				0
#define CONFIG_UI_FONT_8X14				1
#define CONFIG_UI_FONT_10X16			0
#define CONFIG_UI_FONT_12X16			0
#define CONFIG_UI_FONT_12X20			0
#define CONFIG_UI_FONT_16X26			1
#define CONFIG_UI_FONT_22X36			0
#define CONFIG_UI_FONT_24X40			0
#define CONFIG_UI_FONT_32X53			0

#define CONFIG_UI_NUM_12X20				0
#define CONFIG_UI_NUM_16X26				0
#define CONFIG_UI_NUM_22X36				0
#define CONFIG_UI_NUM_24X40				0
#define CONFIG_UI_NUM_32X53				1

#define CONFIG_UI_CLICK_THRESHOLD		20


#define CONFIG_LCD							1
#define CONFIG_LCD_FREQ						45000000
#define CONFIG_LCD_BUFFER_ADDRESS			EMC_SDRAM_1
#define CONFIG_LCD_PIXELS_PER_LINE			800
#define CONFIG_LCD_HSYNC_PULSE_WIDTH		48
#define CONFIG_LCD_H_FRONT_PORCH			40
#define CONFIG_LCD_H_BACK_PORCH				88
#define CONFIG_LCD_LINES_PER_PANEL			480
#define CONFIG_LCD_VSYNC_PULSE_WIDTH		3
#define CONFIG_LCD_V_FRONT_PORCH			13
#define CONFIG_LCD_V_BACK_PORCH				32
#define CONFIG_LCD_INVERT_PANEL_CLOCK		1
#define CONFIG_LCD_INVERT_HSYNC				1
#define CONFIG_LCD_INVERT_VSYNC				1
#define CONFIG_LCD_RGB_TO_BGR				1
#define CONFIG_LCD_BITS_PER_PIXEL			LCD_16_BPP_RGB565
#define CONFIG_LCD_PWR_IOCON				LPC_IOCON->P2_0 = 0x7 | (1 << 9)
#define CONFIG_LCD_DCLK_IOCON				LPC_IOCON->P2_2 = 0x7 | (1 << 9)
#define CONFIG_LCD_ENAB_M_IOCON				LPC_IOCON->P2_4 = 0x7 | (1 << 9)
#define CONFIG_LCD_VSYNC_IOCON				LPC_IOCON->P2_3 = 0x7 | (1 << 9)
#define CONFIG_LCD_HSYNC_IOCON				LPC_IOCON->P2_5 = 0x7 | (1 << 9)
#define CONFIG_LCD_LE_IOCON
#define CONFIG_LCD_CLKIN_IOCON
#define CONFIG_LCD_VD0_IOCON				LPC_IOCON->P0_4 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD1_IOCON				LPC_IOCON->P0_5 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD2_IOCON				LPC_IOCON->P4_28 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD3_IOCON				LPC_IOCON->P4_29 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD4_IOCON				LPC_IOCON->P2_6 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD5_IOCON				LPC_IOCON->P2_7 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD6_IOCON				LPC_IOCON->P2_8 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD7_IOCON				LPC_IOCON->P2_9 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD8_IOCON				LPC_IOCON->P0_6 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD9_IOCON				LPC_IOCON->P0_7 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD10_IOCON				LPC_IOCON->P1_20 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD11_IOCON				LPC_IOCON->P1_21 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD12_IOCON				LPC_IOCON->P1_22 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD13_IOCON				LPC_IOCON->P1_23 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD14_IOCON				LPC_IOCON->P1_24 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD15_IOCON				LPC_IOCON->P1_25 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD16_IOCON				LPC_IOCON->P0_8 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD17_IOCON				LPC_IOCON->P0_9 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD18_IOCON				LPC_IOCON->P2_12 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD19_IOCON				LPC_IOCON->P2_13 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD20_IOCON				LPC_IOCON->P1_26 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD21_IOCON				LPC_IOCON->P1_27 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD22_IOCON				LPC_IOCON->P1_28 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD23_IOCON				LPC_IOCON->P1_29 = 0x7 | (1 << 9)

#define CONFIG_LCD_TOUCHSCREEN				1
#define CONFIG_LCD_TOUCH_THRESHOLD			200
#define CONFIG_LCD_X_R_ADC					ADC_1
#define CONFIG_LCD_X_R_GPIO					PIO0_24
#define CONFIG_LCD_X_L_ADC					ADC_3
#define CONFIG_LCD_X_L_GPIO					PIO0_26
#define CONFIG_LCD_Y_B_ADC					ADC_0
#define CONFIG_LCD_Y_B_GPIO					PIO0_23
#define CONFIG_LCD_Y_T_ADC					ADC_2
#define CONFIG_LCD_Y_T_GPIO					PIO0_25
#define CONFIG_LCD_X_MIN					540
#define CONFIG_LCD_Y_MIN					980
#define CONFIG_LCD_X_MAX					3776
#define CONFIG_LCD_Y_MAX					3228



#define CONFIG_EMC						1
#define CONFIG_EMC_DYNAMIC_RAM			1
#define CONFIG_EMC_SDRAM_1				1
#define CONFIG_EMC_SDRAM_2				0
#define CONFIG_EMC_SDRAM_3				0
#define CONFIG_EMC_SDRAM_4				0
#define CONFIG_EMC_STATIC_RAM			0
#define CONFIG_EMC_CHIP_COUNT			1
#define CONFIG_EMC_CLOCK_DIV_HALF		0
#define CONFIG_EMC_SDRAM_MODE_REGISTER	(0x33 << (2 + 8 + 1))
#define CONFIG_EMC_SDRAM_AM0			0b000101
#define CONFIG_EMC_SDRAM_AM1			0
#define CONFIG_EMC_SDRAM_RAS			3
#define CONFIG_EMC_SDRAM_CAS			3
#define CONFIG_EMC_SDRAM_REFRESH		54




/* Enables FreeRTOS implementation.
 * Note: RTOS is not available for Cortex-M0 based
 * MCU's and thus should be disabled when compiling
 * for them.*/
#define CONFIG_RTOS						1
#define CONFIG_RTOS_HEAP_SIZE			26000


#define CONFIG_NON_VOLATILE_MEMORY		1
#define CONFIG_APP_ST					struct _dspl_st dspl
#define CONFIG_MAIN_H					"main.h"
#define CONFIG_NON_VOLATILE_START		dspl.data_start
#define CONFIG_NON_VOLATILE_END			dspl.data_end
#define CONFIG_NON_VOLATILE_START_ADDR	0x0001000




/* Enables the UART modules.
 * Note: Refer to the MCU's datasheet for available UARTs.
 */
#define CONFIG_UART0					1
#define CONFIG_UART1					0
#define CONFIG_UART2					0
#define CONFIG_UART3					0
#define CONFIG_UART4					0

/*
 * on LPC178x UART pins are multiplexed.
 * Use these to select which pins are configured as RX and TX for each UART.
 */
#if (!CONFIG_TARGET_LPC11CXX)
#define CONFIG_UART0_TX_PIO0_0			0
#define CONFIG_UART0_TX_PIO0_2			1

#define CONFIG_UART0_RX_PIO0_1			0
#define CONFIG_UART0_RX_PIO0_3			1

#define CONFIG_UART1_TX_PIO0_15			0
#define CONFIG_UART1_TX_PIO2_0			0
#define CONFIG_UART1_TX_PIO3_16			0

#define CONFIG_UART1_RX_PIO0_16			0
#define CONFIG_UART1_RX_PIO2_1			0
#define CONFIG_UART1_RX_PIO3_17			0

#define CONFIG_UART2_TX_PIO0_10			0
#define CONFIG_UART2_TX_PIO2_8			0
#define CONFIG_UART2_TX_PIO4_22			0

#define CONFIG_UART2_RX_PIO0_11			0
#define CONFIG_UART2_RX_PIO2_9			0
#define CONFIG_UART2_RX_PIO4_23			0

#define CONFIG_UART3_TX_PIO0_0			0
#define CONFIG_UART3_TX_PIO0_2			0
#define CONFIG_UART3_TX_PIO4_28			0

#define CONFIG_UART3_RX_PIO0_1			0
#define CONFIG_UART3_RX_PIO0_3			0
#define CONFIG_UART3_RX_PIO4_29			0

#define CONFIG_UART4_TX_PIO0_22			0
#define CONFIG_UART4_TX_PIO1_29			0
#define CONFIG_UART4_TX_PIO5_4			0

#define CONFIG_UART4_RX_PIO2_9			0
#define CONFIG_UART4_RX_PIO5_3			0
#endif

/* Configurations for each UART data transfer.
 * These same configurations apply for each UART used.
 * Example: If CONFIG_UARTx_ENABLE is 1,
 * then corresponding CONFIG_UARTx_DATA_*_BYTES etc.
 * should be set.
 */

/*
 * The receive buffer size for each enabled UART module
 */
#define CONFIG_UART0_RX_BUFFER_SIZE		10

/*
 * The baud rate for each enabled UART module
 */
#define CONFIG_UART0_BAUDRATE			115200
/*
 * The number of data bytes in transmission
 */
#define CONFIG_UART0_DATA_8_BYTES		1
#define CONFIG_UART0_DATA_7_BYTES		0
#define CONFIG_UART0_DATA_6_BYTES		0
#define CONFIG_UART0_DATA_5_BYTES		0

/*
 * Parity bit: set NONE if parity checking is not used,
 * or if it's used, define either ODD or EVEN parity.
 */
#define CONFIG_UART0_PARITY_NONE		1
#define CONFIG_UART0_PARITY_ODD			0
#define CONFIG_UART0_PARITY_EVEN		0

/*
 * The number of stop bytes in a one frame (byte).
 */
#define CONFIG_UART0_STOP_BITS_1		1
#define CONFIG_UART0_STOP_BITS_2		0






#define CONFIG_TERMINAL_UART				1
#define CONFIG_TERMINAL_CAN					1
#define CONFIG_TERMINAL_BUFFER_SIZE			200
#define CONFIG_TERMINAL_ARG_COUNT			9
#define CONFIG_TERMINAL_INSTRUCTIONS		1
#define CONFIG_TERMINAL_DEDICATED_CALLBACKS 1



#define CONFIG_CAN							1
#define CONFIG_CAN1							1
#define CONFIG_CAN1_TX_PIN					PIO0_1
#define CONFIG_CAN1_RX_PIN					PIO0_0
#define CONFIG_CAN2							0

#define CONFIG_CAN_LOG						0
#define CONFIG_CAN_ERROR_LOG				0
/*
 * Defines the corresponding CAN channel's baud rate
 */
#define CONFIG_CAN1_BAUDRATE				250000
#define CONFIG_CAN2_BAUDRATE				250000

/* Defines the corresponding CAN channel's
 * transmit buffer size in CAN messages
 */
#define CONFIG_CAN1_TX_BUFFER_SIZE			200
#define CONFIG_CAN2_TX_BUFFER_SIZE			3

/* Defines the corresponding CAN channel's
 * receive buffer size in CAN messages
 */
#define CONFIG_CAN1_RX_BUFFER_SIZE			20
#define CONFIG_CAN2_RX_BUFFER_SIZE			3





/*
 * Enabled or disables the CANopen module.
 */
#define CONFIG_CANOPEN								1
#define CONFIG_CANOPEN_LOG							0
#define CONFIG_CANOPEN_CHANNEL						CAN1
#define CONFIG_CANOPEN_RXPDO_COUNT					12
#define CONFIG_CANOPEN_TXPDO_COUNT					0
#define CONFIG_CANOPEN_OBJ_DICT_APP_PARAMS			obj_dict
#define CONFIG_CANOPEN_OBJ_DICT_APP_PARAMS_COUNT	object_dictionary_size
#define CONFIG_CANOPEN_SDO_SYNC						1
#define CONFIG_CANOPEN_SDO_SEGMENTED				0

#define CONFIG_CANOPEN_DEFAULT_NODE_ID				0xE
#define CONFIG_CANOPEN_PRODUCER_HEARTBEAT_TIME_MS	1000
#define CONFIG_CANOPEN_CONSUMER_HEARTBEAT_COUNT		10
#define CONFIG_CANOPEN_DEVICE_TYPE					0
#define CONFIG_CANOPEN_VENDOR_ID					0
#define CONFIG_CANOPEN_PRODUCT_CODE					0x00A60000
#define CONFIG_CANOPEN_REVISION_CODE				2

#define CONFIG_CANOPEN_RXPDO1_ID					(CANOPEN_TXPDO1_ID + MSB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO1_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_MAIN_INDEX	0x2000
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_LEN			1
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_MAIN_INDEX	0x2001
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_LEN			1
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_MAIN_INDEX	0x2002
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_LEN			1
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_MAIN_INDEX	0x2003
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_LEN			1
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_MAIN_INDEX	0x2004
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_LEN			2
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_MAIN_INDEX	0x2005
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_LEN			2
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO2_ID					(CANOPEN_TXPDO2_ID + MSB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO2_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_LEN			1
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_LEN			1
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_SUB_INDEX	3
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_LEN			1
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_SUB_INDEX	4
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_LEN			1
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_SUB_INDEX	5
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_LEN			1
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_SUB_INDEX	6
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_LEN			1
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_SUB_INDEX	7
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_LEN			1
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_MAIN_INDEX	0x2007
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_LEN			1

#define CONFIG_CANOPEN_RXPDO3_ID					(CANOPEN_TXPDO3_ID + MSB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO3_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO3_MAPPING1_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING1_LEN			0
#define CONFIG_CANOPEN_RXPDO3_MAPPING2_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING2_LEN			0
#define CONFIG_CANOPEN_RXPDO3_MAPPING3_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING3_LEN			0
#define CONFIG_CANOPEN_RXPDO3_MAPPING4_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING4_LEN			0
#define CONFIG_CANOPEN_RXPDO3_MAPPING5_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO3_MAPPING6_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO3_MAPPING7_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO3_MAPPING8_MAIN_INDEX	0x2006
#define CONFIG_CANOPEN_RXPDO3_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO3_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO4_ID					(CANOPEN_TXPDO1_ID + CSB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO4_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO4_MAPPING1_MAIN_INDEX	0x2100
#define CONFIG_CANOPEN_RXPDO4_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO4_MAPPING1_LEN			1
#define CONFIG_CANOPEN_RXPDO4_MAPPING2_MAIN_INDEX	0x2100
#define CONFIG_CANOPEN_RXPDO4_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO4_MAPPING2_LEN			1
#define CONFIG_CANOPEN_RXPDO4_MAPPING3_MAIN_INDEX	0x2100
#define CONFIG_CANOPEN_RXPDO4_MAPPING3_SUB_INDEX	3
#define CONFIG_CANOPEN_RXPDO4_MAPPING3_LEN			1
#define CONFIG_CANOPEN_RXPDO4_MAPPING4_MAIN_INDEX	0x2100
#define CONFIG_CANOPEN_RXPDO4_MAPPING4_SUB_INDEX	4
#define CONFIG_CANOPEN_RXPDO4_MAPPING4_LEN			1
#define CONFIG_CANOPEN_RXPDO4_MAPPING5_MAIN_INDEX	0x2101
#define CONFIG_CANOPEN_RXPDO4_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING5_LEN			1
#define CONFIG_CANOPEN_RXPDO4_MAPPING6_MAIN_INDEX	0x2102
#define CONFIG_CANOPEN_RXPDO4_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING6_LEN			1
#define CONFIG_CANOPEN_RXPDO4_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO4_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO4_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO5_ID					(CANOPEN_TXPDO1_ID + ECU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO5_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO5_MAPPING1_MAIN_INDEX	0x2200
#define CONFIG_CANOPEN_RXPDO5_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING1_LEN			1
#define CONFIG_CANOPEN_RXPDO5_MAPPING2_MAIN_INDEX	0x2201
#define CONFIG_CANOPEN_RXPDO5_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING2_LEN			1
#define CONFIG_CANOPEN_RXPDO5_MAPPING3_MAIN_INDEX	0x2202
#define CONFIG_CANOPEN_RXPDO5_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING3_LEN			2
#define CONFIG_CANOPEN_RXPDO5_MAPPING4_MAIN_INDEX	0x2203
#define CONFIG_CANOPEN_RXPDO5_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING4_LEN			1
#define CONFIG_CANOPEN_RXPDO5_MAPPING5_MAIN_INDEX	0x2204
#define CONFIG_CANOPEN_RXPDO5_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING5_LEN			1
#define CONFIG_CANOPEN_RXPDO5_MAPPING6_MAIN_INDEX	0x2205
#define CONFIG_CANOPEN_RXPDO5_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING6_LEN			2
#define CONFIG_CANOPEN_RXPDO5_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO5_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO5_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO6_ID					(CANOPEN_TXPDO2_ID + ECU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO6_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO6_MAPPING1_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO6_MAPPING1_SUB_INDEX	1
#define CONFIG_CANOPEN_RXPDO6_MAPPING1_LEN			2
#define CONFIG_CANOPEN_RXPDO6_MAPPING2_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO6_MAPPING2_SUB_INDEX	2
#define CONFIG_CANOPEN_RXPDO6_MAPPING2_LEN			2
#define CONFIG_CANOPEN_RXPDO6_MAPPING3_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO6_MAPPING3_SUB_INDEX	3
#define CONFIG_CANOPEN_RXPDO6_MAPPING3_LEN			2
#define CONFIG_CANOPEN_RXPDO6_MAPPING4_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO6_MAPPING4_SUB_INDEX	4
#define CONFIG_CANOPEN_RXPDO6_MAPPING4_LEN			2
#define CONFIG_CANOPEN_RXPDO6_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO6_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO6_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO6_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO6_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO7_ID					(CANOPEN_TXPDO3_ID + ECU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO7_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO7_MAPPING1_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO7_MAPPING1_SUB_INDEX	5
#define CONFIG_CANOPEN_RXPDO7_MAPPING1_LEN			2
#define CONFIG_CANOPEN_RXPDO7_MAPPING2_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO7_MAPPING2_SUB_INDEX	6
#define CONFIG_CANOPEN_RXPDO7_MAPPING2_LEN			2
#define CONFIG_CANOPEN_RXPDO7_MAPPING3_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO7_MAPPING3_SUB_INDEX	7
#define CONFIG_CANOPEN_RXPDO7_MAPPING3_LEN			2
#if FM
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_SUB_INDEX	8
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_LEN			2
#elif LM
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_MAIN_INDEX	0x2207
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO7_MAPPING4_LEN			1
#endif
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

#define CONFIG_CANOPEN_RXPDO8_ID					(CANOPEN_TXPDO4_ID + ECU_NODE_ID)
#define CONFIG_CANOPEN_RXPDO8_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO8_MAPPING1_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO8_MAPPING1_SUB_INDEX	8
#define CONFIG_CANOPEN_RXPDO8_MAPPING1_LEN			2
#define CONFIG_CANOPEN_RXPDO8_MAPPING2_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO8_MAPPING2_SUB_INDEX	9
#define CONFIG_CANOPEN_RXPDO8_MAPPING2_LEN			2
#define CONFIG_CANOPEN_RXPDO8_MAPPING3_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO8_MAPPING3_SUB_INDEX	10
#define CONFIG_CANOPEN_RXPDO8_MAPPING3_LEN			2
#define CONFIG_CANOPEN_RXPDO8_MAPPING4_MAIN_INDEX	0x2206
#define CONFIG_CANOPEN_RXPDO8_MAPPING4_SUB_INDEX	11
#define CONFIG_CANOPEN_RXPDO8_MAPPING4_LEN			2
#define CONFIG_CANOPEN_RXPDO8_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO8_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO8_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO8_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO8_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO9_ID					(CANOPEN_TXPDO1_ID + LKEYPAD_NODE_ID)
#define CONFIG_CANOPEN_RXPDO9_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO9_MAPPING1_MAIN_INDEX	0x2300
#define CONFIG_CANOPEN_RXPDO9_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING1_LEN			2
#define CONFIG_CANOPEN_RXPDO9_MAPPING2_MAIN_INDEX	0x2301
#define CONFIG_CANOPEN_RXPDO9_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING2_LEN			2
#define CONFIG_CANOPEN_RXPDO9_MAPPING3_MAIN_INDEX	0x2302
#define CONFIG_CANOPEN_RXPDO9_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING3_LEN			2
#define CONFIG_CANOPEN_RXPDO9_MAPPING4_MAIN_INDEX	0x2303
#define CONFIG_CANOPEN_RXPDO9_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING4_LEN			2
#define CONFIG_CANOPEN_RXPDO9_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO9_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO9_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO9_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO9_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO10_ID					(CANOPEN_TXPDO1_ID + RKEYPAD_NODE_ID)
#define CONFIG_CANOPEN_RXPDO10_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO10_MAPPING1_MAIN_INDEX	0x2400
#define CONFIG_CANOPEN_RXPDO10_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING1_LEN			2
#define CONFIG_CANOPEN_RXPDO10_MAPPING2_MAIN_INDEX	0x2401
#define CONFIG_CANOPEN_RXPDO10_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING2_LEN			2
#define CONFIG_CANOPEN_RXPDO10_MAPPING3_MAIN_INDEX	0x2402
#define CONFIG_CANOPEN_RXPDO10_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING3_LEN			2
#define CONFIG_CANOPEN_RXPDO10_MAPPING4_MAIN_INDEX	0x2403
#define CONFIG_CANOPEN_RXPDO10_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING4_LEN			2
#define CONFIG_CANOPEN_RXPDO10_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO10_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO10_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO10_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO10_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO11_ID					(CANOPEN_TXPDO2_ID + PEDAL_NODE_ID)
#define CONFIG_CANOPEN_RXPDO11_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO11_MAPPING1_MAIN_INDEX	0x2500
#define CONFIG_CANOPEN_RXPDO11_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING1_LEN			2
#define CONFIG_CANOPEN_RXPDO11_MAPPING2_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING2_LEN			0
#define CONFIG_CANOPEN_RXPDO11_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING3_LEN			0
#define CONFIG_CANOPEN_RXPDO11_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING4_LEN			0
#define CONFIG_CANOPEN_RXPDO11_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO11_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO11_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO11_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO11_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO12_ID					(CANOPEN_TXPDO1_ID + UW180S_MB_NODE_ID)
#define CONFIG_CANOPEN_RXPDO12_TRANSMISSION_TYPE	CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO12_MAPPING1_MAIN_INDEX	0x2600
#define CONFIG_CANOPEN_RXPDO12_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING1_LEN			2
#define CONFIG_CANOPEN_RXPDO12_MAPPING2_MAIN_INDEX	0x2601
#define CONFIG_CANOPEN_RXPDO12_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING2_LEN			2
#define CONFIG_CANOPEN_RXPDO12_MAPPING3_MAIN_INDEX	0x2602
#define CONFIG_CANOPEN_RXPDO12_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING3_LEN			2
#define CONFIG_CANOPEN_RXPDO12_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING4_LEN			0
#define CONFIG_CANOPEN_RXPDO12_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO12_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO12_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO12_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO12_MAPPING8_LEN			0


#define CONFIG_ADC						1
#define CONFIG_ADC_MODE_STANDARD		1
#define CONFIG_ADC_MODE_CONTINOUS		0

#define CONFIG_ADC_CHANNEL0				1
#define CONFIG_ADC_CHANNEL1				1
#define CONFIG_ADC_CHANNEL2				1
#define CONFIG_ADC_CHANNEL3				1
#define CONFIG_ADC_CHANNEL4				1
#define CONFIG_ADC_CHANNEL5				0
#define CONFIG_ADC_CHANNEL6				0
#define CONFIG_ADC_CHANNEL7				0








/**** END OF USER CONFIGURATIONS ****/




#endif /* UV_HAL_CONFIG_H_ */
