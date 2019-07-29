/*
 * gui.c
 *
 *  Created on: Sep 23, 2016
 *      Author: usevolt
 */



#include "gui.h"
#include "pin_mappings.h"
#include "main.h"
#include <uv_pwm.h>
#include <uv_rtos.h>
#include <uv_uart.h>
#include <uv_adc.h>
#include <uv_eeprom.h>


#define this (&gui)

gui_st gui;

#define PBAR_WIDTH			70
#define PBAR_LABEL_X		53
#define PBAR_LABEL_WIDTH	25



static void display_touch_callback(const uv_touch_st *touch);




static void display_touch_callback(const uv_touch_st *touch) {
	if ((touch->action == TOUCH_PRESSED) && (dspl.user->volume.touch)) {
		alert_play(&dspl.alert, ALERT_CLICK);
	}
}

void gui_init() {
	uv_eeprom_read((unsigned char*) &this->backlight, sizeof(this->backlight), BRIGHTNESS_EEPROM_ADDR);
	gui_set_backlight(this->backlight);
	this->backlight_delay = -1;

	uv_uidisplay_init(&this->display, this->display_buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uidisplay_set_touch_callb(&this->display, &display_touch_callback);


	uv_uiwindow_init(&this->main_window, this->main_buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uidisplay_add(&this->display, &this->main_window, PBAR_WIDTH + PBAR_LABEL_WIDTH, 0,
			LCD_W(1) - ((PBAR_LABEL_WIDTH + PBAR_WIDTH) * 2), LCD_H(0.86f));

	uv_uiprogressbar_init(&this->rpm, 0, RPM_MAX, &uv_uistyles[0]);
	uv_uiprogressbar_set_vertical(&this->rpm);
	uv_uiprogressbar_set_limit(&this->rpm, UI_PROGRESSBAR_LIMIT_OVER, RPM_WARNING_LIMIT, C(0xFF0000));
	uv_uiprogressbar_set_title(&this->rpm, uv_str(STR_BARRPM));
	uv_uiprogressbar_set_value(&this->rpm, esb_get_rpm(&dspl.network.esb));
	uv_uiwindow_add(&this->display, &this->rpm, 0, 0,
			PBAR_WIDTH, uv_uibb(&this->main_window)->height);

	uv_uilabel_init(&this->rpm_3000, &UI_FONT_SMALL, ALIGN_CENTER_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), "3000");
	uv_uiwindow_add(&this->display, &this->rpm_3000,
			PBAR_LABEL_X,
			uv_uibb(&this->rpm)->y +
			uv_lerpf(1.0f - 3000.0f / RPM_MAX, 0,
					uv_uibb(&this->rpm)->height - this->rpm.style->font->char_height),
			PBAR_LABEL_WIDTH, 0);

	uv_uilabel_init(&this->rpm_2000, &UI_FONT_SMALL, ALIGN_CENTER_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), "2000");
	uv_uiwindow_add(&this->display, &this->rpm_2000,
			PBAR_LABEL_X,
			uv_uibb(&this->rpm)->y +
			uv_lerpf(1.0f - 2000.0f / RPM_MAX, 0,
					uv_uibb(&this->rpm)->height - this->rpm.style->font->char_height),
					PBAR_LABEL_WIDTH, 0);

	uv_uilabel_init(&this->rpm_1000, &UI_FONT_SMALL, ALIGN_CENTER_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), "1000");
	uv_uiwindow_add(&this->display, &this->rpm_1000,
			PBAR_LABEL_X,
			uv_uibb(&this->rpm)->y +
			uv_lerpf(1.0f - 1000.0f / RPM_MAX, 0,
					uv_uibb(&this->rpm)->height - this->rpm.style->font->char_height),
					PBAR_LABEL_WIDTH, 0);

	uv_uiprogressbar_init(&this->pressure, 0, PRESSURE_MAX, &uv_uistyles[0]);
	uv_uiprogressbar_set_vertical(&this->pressure);
	uv_uiprogressbar_set_title(&this->pressure, uv_str(STR_BARPRESSURE));
	uv_uiprogressbar_set_value(&this->pressure, hcu_get_pressure(&dspl.network.hcu));
	uv_uiwindow_add(&this->display, &this->pressure,
			uv_uibb(&this->display)->width - PBAR_WIDTH - CONFIG_UI_PROGRESSBAR_WIDTH, 0,
			PBAR_WIDTH, uv_uibb(&this->main_window)->height);

	uv_uilabel_init(&this->pressure_200, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT,
			C(0xFFFFFF), C(0xFFFFFFFF), "200");
	uv_uiwindow_add(&this->display, &this->pressure_200,
			uv_uibb(&this->display)->width - PBAR_LABEL_X,
			uv_uibb(&this->pressure)->y +
			uv_lerpf(1.0f - 200.0f / PRESSURE_MAX, 0,
					uv_uibb(&this->pressure)->height - this->rpm.style->font->char_height), -4, 0);

	uv_uilabel_init(&this->pressure_100, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT,
			C(0xFFFFFF), C(0xFFFFFFFF), "100");
	uv_uiwindow_add(&this->display, &this->pressure_100,
			uv_uibb(&this->display)->width - PBAR_LABEL_X,
			uv_uibb(&this->pressure)->y +
			uv_lerpf(1.0f - 100.0f / PRESSURE_MAX, 0,
					uv_uibb(&this->pressure)->height - this->rpm.style->font->char_height), -4, 0);


	taskbar_init(&this->display);

	uv_rtos_task_create(gui_step, "gui", UV_RTOS_MIN_STACK_SIZE * 21,
			NULL, UV_RTOS_IDLE_PRIORITY + 1, NULL);

	// by default show the login screen
	login_show();
}



void gui_step(void *nullptr) {
	uint16_t step_ms = GUI_STEP_MS;

	while (true) {

		// write brightness to EEPROM if modification delay has passed
		if (uv_delay(step_ms, &this->backlight_delay)) {
			uv_eeprom_write(&this->backlight, sizeof(this->backlight), BRIGHTNESS_EEPROM_ADDR);
		}

		// note: not full scale of duty cycle is used, since the fuse on pcb cannot hold full current
		uv_pwm_set(LCD_BACKLIGHT, DUTY_CYCLE(((float) 100 - this->backlight * this->backlight / 100)
				/ 105));

		uv_uiprogressbar_set_value(&this->rpm, esb_get_rpm(&dspl.network.esb));
		uv_uiprogressbar_set_value(&this->pressure, hcu_get_pressure(&dspl.network.hcu));

		// display step function
		uv_uidisplay_step(&this->display, step_ms);

		uv_rtos_task_delay(step_ms);
	}
}


void gui_reset(void) {
	this->backlight = BRIGHTNESS_DEFAULT_VALUE;
	uv_eeprom_write(&this->backlight, sizeof(this->backlight), BRIGHTNESS_EEPROM_ADDR);
}

void gui_set_backlight(uint8_t value) {
	if (value > 100) {
		value = 100;
	}
	else if (value == 0) {
		value = 1;
	}
	// if brightness has been changed, start delay for writing it to EEPROM
	if (this->backlight != value) {
		uv_delay_init(BACKLIGHT_DELAY_MS, &this->backlight_delay);
	}
	this->backlight = value;
}


int16_t gui_get_backlight() {
	return this->backlight;
}
