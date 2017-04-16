/*
 * pin_mappings.h
 *
 *  Created on: Jul 20, 2016
 *      Author: usevolt
 */

#ifndef PIN_MAPPINGS_H_
#define PIN_MAPPINGS_H_

#include <uv_gpio.h>
#include <uv_pwm.h>


#define LED_PIN				PIO2_31

#define LCD_BACKLIGHT		PWM0_2

#define BUZZER				PWM1_4

#define FLASH_CS			PIO0_19
#define FLASH_RESET			PIO0_16

#define VDD_SENSE			ADC_4


#endif /* PIN_MAPPINGS_H_ */
