/*
 * uw_hal_config.h
 *
 *  Created on: Mar 22, 2016
 *      Author: usevolt
 */

#ifndef UW_HAL_CONFIG_H_
#define UW_HAL_CONFIG_H_


/**** USER CONFIGURATIONS ****/


/* Defines the build target MCU family
 *
 * NOTE: Only one target MCU should be defined! */
#define CONFIG_TARGET_LPC11CXX			0
#define CONFIG_TARGET_LPC178X			1







/* Enables FreeRTOS implementation.
 * Note: RTOS is not available for Cortex-M0 based
 * MCU's and thus should be disabled when compiling
 * for them.*/
#define CONFIG_RTOS						1






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
#define CONFIG_PWM0						0
#define CONFIG_COUNTER0					0
#define CONFIG_TIMER1					0
#define CONFIG_PWM1						0
#define CONFIG_COUNTER1					0
#define CONFIG_TIMER2					0
#define CONFIG_PWM2						0
#define CONFIG_COUNTER2					0
#define CONFIG_TIMER3					0
#define CONFIG_PWM3						0
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
#define CONFIG_UART0_RX_BUFFER_SIZE		8

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







/*
 * Defines the terminal receive buffer size in bytes.
 * The buffer has to be big enough for terminal command
 * as well as all arguments.
 */
#define CONFIG_TERMINAL_BUFFER_SIZE		200
/*
 * Set's the maximum argument count for terminal
 */
#define CONFIG_TERMINAL_ARG_COUNT		4
/*
 * Enables instructions for terminal commands.
 * If disabled, terminal commands do not contain any usage instructions.
 */
#define CONFIG_TERMINAL_INSTRUCTIONS	0






/* Defines the ADC mode.
 * Note: Not both of these should be defined!
 *
 * in CONTINUOUS MODE the ADC runs in the background all the time and
 * reading the ADC values is fast since they can only be read from memory.
 * in STANDARD MODE, the conversion is started when calling uw_read_adc.
 * The function waits for the conversion to finish and returns the value retrieved.
 *
 * CONTINUOUS MODE is fast, but not precise since the output value is harder
 * to average. In ADC_STANDARD_MODE, conversion can be run multiple times and
 * average of the conversion can be taken.
 */
#define CONFIG_ADC_MODE_STANDARD		1
#define CONFIG_ADC_MODE_CONTINOUS		0

/* Enables ADC channels.
 * If a channel is not enabled here, it's not
 * configured as an analog input and
 * cannot be used as a ADC source.
 */
#define CONFIG_ADC_CHANNEL0				1
#define CONFIG_ADC_CHANNEL1				1
#define CONFIG_ADC_CHANNEL2				1
#define CONFIG_ADC_CHANNEL3				1
#define CONFIG_ADC_CHANNEL4				1
#define CONFIG_ADC_CHANNEL5				1
#define CONFIG_ADC_CHANNEL6				1
#define CONFIG_ADC_CHANNEL7				1







/* Enables all GPIO pins from specific ports.
 * GPIO pin functions cannot be used for specific port pins
 * if the port is not enabled with these or
 * pin is not enabled with configurations below.
 *
 * Refer to the MCU datasheet for PORTs available.*/
#define CONFIG_PORT0					0
#define CONFIG_PORT1					0
#define CONFIG_PORT2					0
#define CONFIG_PORT3					0
#define CONFIG_PORT4					0
#define CONFIG_PORT5					0


/* Enabled a individual port pin.
 * GPIO pin functions cannot be used for specific pins
 * if they or their port is not enabled.
 * Refer to the MCU datasheet for pins available.
 */
#define CONFIG_PIO0_0					0
#define CONFIG_PIO0_1					0
#define CONFIG_PIO0_2					0
#define CONFIG_PIO0_3					0
#define CONFIG_PIO0_4					0
#define CONFIG_PIO0_5					0
#define CONFIG_PIO0_6					0
#define CONFIG_PIO0_7					0
#define CONFIG_PIO0_8					0
#define CONFIG_PIO0_9					0
#define CONFIG_PIO0_10					0
#define CONFIG_PIO0_11					0
#define CONFIG_PIO0_12					0
#define CONFIG_PIO0_13					0
#define CONFIG_PIO0_14					0
#define CONFIG_PIO0_15					0
#define CONFIG_PIO0_16					0
#define CONFIG_PIO0_17					0
#define CONFIG_PIO0_18					0
#define CONFIG_PIO0_19					0
#define CONFIG_PIO0_20					0
#define CONFIG_PIO0_21					0
#define CONFIG_PIO0_22					0
#define CONFIG_PIO0_23					0
#define CONFIG_PIO0_24					0
#define CONFIG_PIO0_25					0
#define CONFIG_PIO0_26					0
#define CONFIG_PIO0_27					0
#define CONFIG_PIO0_28					0
#define CONFIG_PIO0_29					0
#define CONFIG_PIO0_30					0
#define CONFIG_PIO0_31					0
#define CONFIG_PIO0_32					0
#define CONFIG_PIO0_33					0
#define CONFIG_PIO1_0					0
#define CONFIG_PIO1_1					0
#define CONFIG_PIO1_2					0
#define CONFIG_PIO1_3					0
#define CONFIG_PIO1_4					0
#define CONFIG_PIO1_5					0
#define CONFIG_PIO1_6					0
#define CONFIG_PIO1_7					0
#define CONFIG_PIO1_8					0
#define CONFIG_PIO1_9					0
#define CONFIG_PIO1_10					0
#define CONFIG_PIO1_11					0
#define CONFIG_PIO1_12					0
#define CONFIG_PIO1_13					0
#define CONFIG_PIO1_14					0
#define CONFIG_PIO1_15					0
#define CONFIG_PIO1_16					0
#define CONFIG_PIO1_17					0
#define CONFIG_PIO1_18					0
#define CONFIG_PIO1_19					0
#define CONFIG_PIO1_20					0
#define CONFIG_PIO1_21					0
#define CONFIG_PIO1_22					0
#define CONFIG_PIO1_23					0
#define CONFIG_PIO1_24					0
#define CONFIG_PIO1_25					0
#define CONFIG_PIO1_26					0
#define CONFIG_PIO1_27					0
#define CONFIG_PIO1_28					0
#define CONFIG_PIO1_29					0
#define CONFIG_PIO1_30					0
#define CONFIG_PIO1_31					0
#define CONFIG_PIO1_32					0
#define CONFIG_PIO1_33					0
#define CONFIG_PIO2_0					0
#define CONFIG_PIO2_1					0
#define CONFIG_PIO2_2					0
#define CONFIG_PIO2_3					0
#define CONFIG_PIO2_4					0
#define CONFIG_PIO2_5					0
#define CONFIG_PIO2_6					0
#define CONFIG_PIO2_7					0
#define CONFIG_PIO2_8					0
#define CONFIG_PIO2_9					0
#define CONFIG_PIO2_10					0
#define CONFIG_PIO2_11					0
#define CONFIG_PIO2_12					0
#define CONFIG_PIO2_13					0
#define CONFIG_PIO2_14					0
#define CONFIG_PIO2_15					0
#define CONFIG_PIO2_16					0
#define CONFIG_PIO2_17					0
#define CONFIG_PIO2_18					0
#define CONFIG_PIO2_19					0
#define CONFIG_PIO2_20					0
#define CONFIG_PIO2_21					0
#define CONFIG_PIO2_22					0
#define CONFIG_PIO2_23					0
#define CONFIG_PIO2_24					0
#define CONFIG_PIO2_25					0
#define CONFIG_PIO2_26					0
#define CONFIG_PIO2_27					0
#define CONFIG_PIO2_28					0
#define CONFIG_PIO2_29					0
#define CONFIG_PIO2_30					0
#define CONFIG_PIO2_31					1
#define CONFIG_PIO2_32					0
#define CONFIG_PIO2_33					0
#define CONFIG_PIO3_0					0
#define CONFIG_PIO3_1					0
#define CONFIG_PIO3_2					0
#define CONFIG_PIO3_3					0
#define CONFIG_PIO3_4					0
#define CONFIG_PIO3_5					0
#define CONFIG_PIO3_6					0
#define CONFIG_PIO3_7					0
#define CONFIG_PIO3_8					0
#define CONFIG_PIO3_9					0
#define CONFIG_PIO3_10					0
#define CONFIG_PIO3_11					0
#define CONFIG_PIO3_12					0
#define CONFIG_PIO3_13					0
#define CONFIG_PIO3_14					0
#define CONFIG_PIO3_15					0
#define CONFIG_PIO3_16					0
#define CONFIG_PIO3_17					0
#define CONFIG_PIO3_18					0
#define CONFIG_PIO3_19					0
#define CONFIG_PIO3_20					0
#define CONFIG_PIO3_21					0
#define CONFIG_PIO3_22					0
#define CONFIG_PIO3_23					0
#define CONFIG_PIO3_24					0
#define CONFIG_PIO3_25					0
#define CONFIG_PIO3_26					0
#define CONFIG_PIO3_27					0
#define CONFIG_PIO3_28					0
#define CONFIG_PIO3_29					0
#define CONFIG_PIO3_30					0
#define CONFIG_PIO3_31					0
#define CONFIG_PIO3_32					0
#define CONFIG_PIO3_33					0
#define CONFIG_PIO4_0					0
#define CONFIG_PIO4_1					0
#define CONFIG_PIO4_2					0
#define CONFIG_PIO4_3					0
#define CONFIG_PIO4_4					0
#define CONFIG_PIO4_5					0
#define CONFIG_PIO4_6					0
#define CONFIG_PIO4_7					0
#define CONFIG_PIO4_8					0
#define CONFIG_PIO4_9					0
#define CONFIG_PIO4_10					0
#define CONFIG_PIO4_11					0
#define CONFIG_PIO4_12					0
#define CONFIG_PIO4_13					0
#define CONFIG_PIO4_14					0
#define CONFIG_PIO4_15					0
#define CONFIG_PIO4_16					0
#define CONFIG_PIO4_17					0
#define CONFIG_PIO4_18					0
#define CONFIG_PIO4_19					0
#define CONFIG_PIO4_20					0
#define CONFIG_PIO4_21					0
#define CONFIG_PIO4_22					0
#define CONFIG_PIO4_23					0
#define CONFIG_PIO4_24					0
#define CONFIG_PIO4_25					0
#define CONFIG_PIO4_26					0
#define CONFIG_PIO4_27					0
#define CONFIG_PIO4_28					0
#define CONFIG_PIO4_29					0
#define CONFIG_PIO4_30					0
#define CONFIG_PIO4_31					0
#define CONFIG_PIO4_32					0
#define CONFIG_PIO4_33					0
#define CONFIG_PIO5_0					0
#define CONFIG_PIO5_1					0
#define CONFIG_PIO5_2					0
#define CONFIG_PIO5_3					0
#define CONFIG_PIO5_4					0
#define CONFIG_PIO5_5					0




/**** END OF USER CONFIGURATIONS ****/




#endif /* UW_HAL_CONFIG_H_ */
