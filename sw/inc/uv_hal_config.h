/*
 * uv_hal_config.h
 *
 *  Created on: Mar 22, 2016
 *      Author: usevolt
 */

#ifndef UV_HAL_CONFIG_H_
#define UV_HAL_CONFIG_H_


/**** USER CONFIGURATIONS ****/


/* Defines the build target MCU family
 *
 * NOTE: Only one target MCU should be defined! */
#define CONFIG_TARGET_LPC11C14			0
#define CONFIG_TARGET_LPC1785			1





#define CONFIG_LOG_ERRORS				1
#define CONFIG_INFORMATIVE_ERRORS		1



#define CONFIG_RTC						1


#define CONFIG_EEPROM					1


#define CONFIG_SPI0						1


#define CONFIG_WDT						0
#define CONFIG_WDT_CYCLE_S				2


#define CONFIG_PWM						1
#define CONFIG_PWM_FREQ					10000
#define CONFIG_PWM0_1					1
#define CONFIG_PWM0_2					1


#define CONFIG_UI_DRAW_BOUDING_BOXES				0
#define WINDOW_STYLE_INDEX							0
#define TASKBAR_STYLE_INDEX							1
#define CONFIG_UI_WINDOW_STYLES_COUNT				2
#define CONFIG_UI_WINDOW_COLOR_2 					0x444444
#define CONFIG_UI_WINDOW_FRAME_COLOR_2				0x000000
#define CONFIG_UI_WINDOW_FRAME_THICKNESS_2			3

#define CONFIG_UI_BUTTON_STYLES_COUNT				2
#define CONFIG_UI_BUTTON_COLOR_2					0x000000
#define CONFIG_UI_BUTTON_FRAME_COLOR_2				0x444444
#define CONFIG_UI_BUTTON_FRAME_THICKNESS_2			3
#define CONFIG_UI_BUTTON_TEXT_COLOR_2				0xaaaaaa
#define CONFIG_UI_BUTTON_TEXT_FONT_2				font_5X12


/* Possible font sizes for uv_hal_config configuration file fonts */
#define  CONFIG_UI_FONT_4X6				0
#define  CONFIG_UI_FONT_5X8				0
#define  CONFIG_UI_FONT_5X12			1
#define  CONFIG_UI_FONT_6X8				0
#define  CONFIG_UI_FONT_6X10			0
#define  CONFIG_UI_FONT_7X12			0
#define  CONFIG_UI_FONT_8X8				0
#define  CONFIG_UI_FONT_8X12			0
#define  CONFIG_UI_FONT_8X14			1
#define  CONFIG_UI_FONT_10X16			0
#define  CONFIG_UI_FONT_12X16			0
#define  CONFIG_UI_FONT_12X20			0
#define  CONFIG_UI_FONT_16X26			1
#define  CONFIG_UI_FONT_22X36			0
#define  CONFIG_UI_FONT_24X40			0
#define  CONFIG_UI_FONT_32X53			0


#define CONFIG_LCD						1
#define CONFIG_LCD_FREQ					45000000
#define CONFIG_LCD_BUFFER_ADDRESS		EMC_SDRAM_1
#define CONFIG_LCD_PIXELS_PER_LINE		800
#define CONFIG_LCD_HSYNC_PULSE_WIDTH	48
#define CONFIG_LCD_H_FRONT_PORCH		40
#define CONFIG_LCD_H_BACK_PORCH			88
#define CONFIG_LCD_LINES_PER_PANEL		480
#define CONFIG_LCD_VSYNC_PULSE_WIDTH	3
#define CONFIG_LCD_V_FRONT_PORCH		13
#define CONFIG_LCD_V_BACK_PORCH			32
#define CONFIG_LCD_INVERT_PANEL_CLOCK	1
#define CONFIG_LCD_INVERT_HSYNC			1
#define CONFIG_LCD_INVERT_VSYNC			1
#define CONFIG_LCD_RGB_TO_BGR			1
#define CONFIG_LCD_BITS_PER_PIXEL		LCD_24_BPP
#define CONFIG_LCD_PWR_IOCON			LPC_IOCON->P2_0 = 0x7 | (1 << 9)
#define CONFIG_LCD_DCLK_IOCON			LPC_IOCON->P2_2 = 0x7 | (1 << 9)
#define CONFIG_LCD_ENAB_M_IOCON			LPC_IOCON->P2_4 = 0x7 | (1 << 9)
#define CONFIG_LCD_VSYNC_IOCON			LPC_IOCON->P2_3 = 0x7 | (1 << 9)
#define CONFIG_LCD_HSYNC_IOCON			LPC_IOCON->P2_5 = 0x7 | (1 << 9)
#define CONFIG_LCD_LE_IOCON
#define CONFIG_LCD_CLKIN_IOCON
#define CONFIG_LCD_VD0_IOCON			LPC_IOCON->P0_4 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD1_IOCON			LPC_IOCON->P0_5 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD2_IOCON			LPC_IOCON->P4_28 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD3_IOCON			LPC_IOCON->P4_29 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD4_IOCON			LPC_IOCON->P2_6 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD5_IOCON			LPC_IOCON->P2_7 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD6_IOCON			LPC_IOCON->P2_8 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD7_IOCON			LPC_IOCON->P2_9 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD8_IOCON			LPC_IOCON->P0_6 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD9_IOCON			LPC_IOCON->P0_7 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD10_IOCON			LPC_IOCON->P1_20 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD11_IOCON			LPC_IOCON->P1_21 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD12_IOCON			LPC_IOCON->P1_22 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD13_IOCON			LPC_IOCON->P1_23 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD14_IOCON			LPC_IOCON->P1_24 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD15_IOCON			LPC_IOCON->P1_25 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD16_IOCON			LPC_IOCON->P0_8 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD17_IOCON			LPC_IOCON->P0_9 = 0x7 | (0b111 << 7)
#define CONFIG_LCD_VD18_IOCON			LPC_IOCON->P2_12 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD19_IOCON			LPC_IOCON->P2_13 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD20_IOCON			LPC_IOCON->P1_26 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD21_IOCON			LPC_IOCON->P1_27 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD22_IOCON			LPC_IOCON->P1_28 = 0x7 | (1 << 9)
#define CONFIG_LCD_VD23_IOCON			LPC_IOCON->P1_29 = 0x7 | (1 << 9)

#define CONFIG_LCD_TOUCHSCREEN			0
#define CONFIG_LCD_Y_B_ADC				ADC_2
#define CONFIG_LCD_Y_B_GPIO				PIO0_25
#define CONFIG_LCD_Y_T_ADC				ADC_0
#define CONFIG_LCD_Y_T_GPIO				PIO0_23
#define CONFIG_LCD_X_R_ADC				ADC_3
#define CONFIG_LCD_X_R_GPIO				PIO0_26
#define CONFIG_LCD_X_L_ADC				ADC_1
#define CONFIG_LCD_X_L_GPIO				PIO0_24
#define CONFIG_LCD_TOUCH_THRESHOLD		200



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
#define CONFIG_RTOS_HEAP_SIZE			10000


#define CONFIG_NON_VOLATILE_MEMORY		1
#define CONFIG_NON_VOLATILE_START_ADDR	0x0001000



/* Enables timer modules.
 * On LPC11Cxx, TIMER0 == TMR16B0,
 * 				TIMER1 == TMR16B1,
 * 				TIMER2 == TMR32B0,
 * 				TIMER3 == TMR32B1
 *
 * Note that the mode of the timer is configured
 * by enabling TIMERx, COUNTERx or PWMx.
 * This means that depending on hardware, TIMER1 and COUNTER1,
 * for example, cannot be enabled at the same time.
 * NOTE: LPC17xx has own PWM0 and PWM1 modules
 * which are separate from timers. These can be enabled
 * alongside TIMER0 and TIMER1.
 */
#define CONFIG_TIMER0					0
#define CONFIG_COUNTER0					0
#define CONFIG_TIMER1					0
#define CONFIG_COUNTER1					0
#define CONFIG_TIMER2					0
#define CONFIG_COUNTER2					0
#define CONFIG_TIMER3					0
#define CONFIG_COUNTER3					0


/* Enables Capture inputs on specific timer modules.
 * Use to select which I/O pins will be used for Capture input.
 * Setting these to 1 enables the counter to be initialized in
 * capture mode.
 */
#define CONFIG_TIMER0_CAP0_PIO3_23			0
#define CONFIG_TIMER0_CAP1_PIO3_24			0

#define CONFIG_TIMER1_CAP0_PIO3_27			0
#define CONFIG_TIMER1_CAP1_PIO1_19			0
#define CONFIG_TIMER1_CAP1_PIO3_28			0

#define CONFIG_TIMER2_CAP0_PIO0_4			0
#define CONFIG_TIMER2_CAP0_PIO1_14			0
#define CONFIG_TIMER2_CAP0_PIO2_6			0
#define CONFIG_TIMER2_CAP0_PIO2_14			0
#define CONFIG_TIMER2_CAP1_PIO0_5			0
#define CONFIG_TIMER2_CAP1_PIO2_15			0

#define CONFIG_TIMER3_CAP0_PIO1_10			0
#define CONFIG_TIMER3_CAP0_PIO2_22			0
#define CONFIG_TIMER3_CAP1_PIO2_23			0

/* Configures timer capture inputs to capture either rising, falling,
 * or both edges.
 */
#define CONFIG_TIMER0_CAP0_RISING_EDGES		0
#define CONFIG_TIMER0_CAP0_FALLING_EDGES	0
#define CONFIG_TIMER0_CAP1_RISING_EDGES		0
#define CONFIG_TIMER0_CAP1_FALLING_EDGES	0

#define CONFIG_TIMER1_CAP0_RISING_EDGES		0
#define CONFIG_TIMER1_CAP0_FALLING_EDGES	0
#define CONFIG_TIMER1_CAP1_RISING_EDGES		0
#define CONFIG_TIMER1_CAP1_FALLING_EDGES	0

#define CONFIG_TIMER2_CAP0_RISING_EDGES		0
#define CONFIG_TIMER2_CAP0_FALLING_EDGES	0
#define CONFIG_TIMER2_CAP1_RISING_EDGES		0
#define CONFIG_TIMER2_CAP1_FALLING_EDGES	0

#define CONFIG_TIMER3_CAP0_RISING_EDGES		0
#define CONFIG_TIMER3_CAP0_FALLING_EDGES	0
#define CONFIG_TIMER3_CAP1_RISING_EDGES		0
#define CONFIG_TIMER3_CAP1_FALLING_EDGES	0

/* Enables PWM channels for PWM modules.
 * On LPC11Cxx, Timers are used as PWM modules and they contain 3 PWM channels.
 * On LPC17xx, PWM modules are separate from timers and they contain 6 PWM channels.
 */
#define CONFIG_PWM0_CHANNEL1				0
#define CONFIG_PWM0_CHANNEL2				0
#define CONFIG_PWM0_CHANNEL3				0
#define CONFIG_PWM0_CHANNEL4				0
#define CONFIG_PWM0_CHANNEL5				0
#define CONFIG_PWM0_CHANNEL6				0

#define CONFIG_PWM1_CHANNEL1				0
#define CONFIG_PWM1_CHANNEL2				0
#define CONFIG_PWM1_CHANNEL3				0
#define CONFIG_PWM1_CHANNEL4				0
#define CONFIG_PWM1_CHANNEL5				0
#define CONFIG_PWM1_CHANNEL6				0

#define CONFIG_PWM2_CHANNEL1				0
#define CONFIG_PWM2_CHANNEL2				0
#define CONFIG_PWM2_CHANNEL3				0

#define CONFIG_PWM3_CHANNEL1				0
#define CONFIG_PWM3_CHANNEL2				0
#define CONFIG_PWM3_CHANNEL3				0




#define CONFIG_I2C							0




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
#define CONFIG_UART0_TX_PIO0_0			1
#define CONFIG_UART0_TX_PIO0_2			0

#define CONFIG_UART0_RX_PIO0_1			1
#define CONFIG_UART0_RX_PIO0_3			0

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
#define CONFIG_TERMINAL_CAN					0
#define CONFIG_TERMINAL_BUFFER_SIZE			200
#define CONFIG_TERMINAL_ARG_COUNT			9
#define CONFIG_TERMINAL_INSTRUCTIONS		1
#define CONFIG_TERMINAL_DEDICATED_CALLBACKS 1



#define CONFIG_CAN							1
#define CONFIG_CAN1							1
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
#define CONFIG_CAN1_TX_BUFFER_SIZE			3
#define CONFIG_CAN2_TX_BUFFER_SIZE			3

/* Defines the corresponding CAN channel's
 * receive buffer size in CAN messages
 */
#define CONFIG_CAN1_RX_BUFFER_SIZE			3
#define CONFIG_CAN2_RX_BUFFER_SIZE			3





/*
 * Enabled or disables the CANopen module.
 */
#define CONFIG_CANOPEN								1
#define CONFIG_CANOPEN_LOG							0
#define CONFIG_CANOPEN_DEVICE_TYPE_INDEX			0x1000
#define CONFIG_CANOPEN_ERROR_REGISTER_INDEX 		0x1001
#define CONFIG_CANOPEN_PREDEFINED_ERROR_FIELD_INDEX	0x1003
#define CONFIG_CANOPEN_PREDEFINED_ERROR_SIZE		4
#define CONFIG_CANOPEN_STORE_PARAMS_INDEX			0x1010
#define CONFIG_CANOPEN_RESTORE_PARAMS_INDEX			0x1011
#define CONFIG_CANOPEN_IDENTITY_INDEX				0x1018
#define CONFIG_CANOPEN_NODEID_INDEX					0x100B
#define CONFIG_CANOPEN_HEARTBEAT_INDEX				0x1017
#define CONFIG_CANOPEN_RXPDO_COM_INDEX				0x1400
#define CONFIG_CANOPEN_RXPDO_MAP_INDEX				0x1600
#define CONFIG_CANOPEN_TXPDO_COM_INDEX				0x1800
#define CONFIG_CANOPEN_TXPDO_MAP_INDEX				0x1A00
#define CONFIG_CANOPEN_RXPDO_COUNT					2
#define CONFIG_CANOPEN_TXPDO_COUNT					3
#define CONFIG_CANOPEN_PDO_MAPPING_COUNT			8

#define CONFIG_CANOPEN_DEFAULT_NODE_ID				0xD
#define CONFIG_CANOPEN_DEFAULT_HEARTBEAT_TIME		1000
#define CONFIG_CANOPEN_DEVICE_TYPE					0
#define CONFIG_CANOPEN_VENDOR_ID					0
#define CONFIG_CANOPEN_PRODUCT_CODE					0x00A60000
#define CONFIG_CANOPEN_REVISION_CODE				2

#define CONFIG_CANOPEN_RXPDO1_ID					(CANOPEN_RXPDO1_ID | CONFIG_CANOPEN_DEFAULT_NODE_ID | CANOPEN_PDO_DISABLED)
#define CONFIG_CANOPEN_RXPDO1_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING1_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING2_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING3_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING4_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO1_MAPPING8_LEN			0

#define CONFIG_CANOPEN_RXPDO2_ID					(CANOPEN_RXPDO2_ID | CONFIG_CANOPEN_DEFAULT_NODE_ID | CANOPEN_PDO_DISABLED)
#define CONFIG_CANOPEN_RXPDO2_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING1_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING2_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING3_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING4_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING5_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING6_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING7_LEN			0
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_RXPDO2_MAPPING8_LEN			0

#define CONFIG_CANOPEN_TXPDO1_ID					(CANOPEN_TXPDO1_ID | CONFIG_CANOPEN_DEFAULT_NODE_ID)
#define CONFIG_CANOPEN_TXPDO1_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_TXPDO1_EVENT_TIMER			1000
#define CONFIG_CANOPEN_TXPDO1_MAPPING1_MAIN_INDEX	0x1000
#define CONFIG_CANOPEN_TXPDO1_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING1_LEN			2
#define CONFIG_CANOPEN_TXPDO1_MAPPING2_MAIN_INDEX	0x1001
#define CONFIG_CANOPEN_TXPDO1_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING2_LEN			2
#define CONFIG_CANOPEN_TXPDO1_MAPPING3_MAIN_INDEX	0x1002
#define CONFIG_CANOPEN_TXPDO1_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING3_LEN			2
#define CONFIG_CANOPEN_TXPDO1_MAPPING4_MAIN_INDEX	0x1003
#define CONFIG_CANOPEN_TXPDO1_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING4_LEN			2
#define CONFIG_CANOPEN_TXPDO1_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING5_LEN			0
#define CONFIG_CANOPEN_TXPDO1_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING6_LEN			0
#define CONFIG_CANOPEN_TXPDO1_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING7_LEN			0
#define CONFIG_CANOPEN_TXPDO1_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO1_MAPPING8_LEN			0


#define CONFIG_CANOPEN_TXPDO2_ID					(CANOPEN_TXPDO2_ID | CONFIG_CANOPEN_DEFAULT_NODE_ID | CANOPEN_PDO_DISABLED)
#define CONFIG_CANOPEN_TXPDO2_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_TXPDO2_EVENT_TIMER			1000
#define CONFIG_CANOPEN_TXPDO2_MAPPING1_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING1_LEN			0
#define CONFIG_CANOPEN_TXPDO2_MAPPING2_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING2_LEN			0
#define CONFIG_CANOPEN_TXPDO2_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING3_LEN			0
#define CONFIG_CANOPEN_TXPDO2_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING4_LEN			0
#define CONFIG_CANOPEN_TXPDO2_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING5_LEN			0
#define CONFIG_CANOPEN_TXPDO2_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING6_LEN			0
#define CONFIG_CANOPEN_TXPDO2_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING7_LEN			0
#define CONFIG_CANOPEN_TXPDO2_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO2_MAPPING8_LEN			0

#define CONFIG_CANOPEN_TXPDO3_ID					(CANOPEN_TXPDO3_ID | CONFIG_CANOPEN_DEFAULT_NODE_ID | CANOPEN_PDO_DISABLED)
#define CONFIG_CANOPEN_TXPDO3_TRANSMISSION_TYPE		CANOPEN_PDO_TRANSMISSION_ASYNC
#define CONFIG_CANOPEN_TXPDO3_EVENT_TIMER			1000
#define CONFIG_CANOPEN_TXPDO3_MAPPING1_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING1_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING1_LEN			0
#define CONFIG_CANOPEN_TXPDO3_MAPPING2_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING2_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING2_LEN			0
#define CONFIG_CANOPEN_TXPDO3_MAPPING3_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING3_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING3_LEN			0
#define CONFIG_CANOPEN_TXPDO3_MAPPING4_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING4_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING4_LEN			0
#define CONFIG_CANOPEN_TXPDO3_MAPPING5_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING5_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING5_LEN			0
#define CONFIG_CANOPEN_TXPDO3_MAPPING6_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING6_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING6_LEN			0
#define CONFIG_CANOPEN_TXPDO3_MAPPING7_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING7_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING7_LEN			0
#define CONFIG_CANOPEN_TXPDO3_MAPPING8_MAIN_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING8_SUB_INDEX	0
#define CONFIG_CANOPEN_TXPDO3_MAPPING8_LEN			0




#define CONFIG_ADC						1
#define CONFIG_ADC_MODE_STANDARD		1
#define CONFIG_ADC_MODE_CONTINOUS		0

#define CONFIG_ADC_CHANNEL0				1
#define CONFIG_ADC_CHANNEL1				1
#define CONFIG_ADC_CHANNEL2				1
#define CONFIG_ADC_CHANNEL3				1
#define CONFIG_ADC_CHANNEL4				1
#define CONFIG_ADC_CHANNEL5				1
#define CONFIG_ADC_CHANNEL6				1
#define CONFIG_ADC_CHANNEL7				1






#define I2C								0





/**** END OF USER CONFIGURATIONS ****/




#endif /* UV_HAL_CONFIG_H_ */
