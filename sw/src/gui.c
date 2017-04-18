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


#define this (&gui)

gui_st gui;

#define PBAR_WIDTH			70
#define PBAR_LABEL_X		53
#define PBAR_LABEL_WIDTH	25


/// @brief: Defines a single point which are used to
/// calculate the current PWM output for the LCD backlight.
typedef struct {
	/// @brief: Supply voltage as millivoltages
	int16_t voltage;
	/// @brief: parts per thousand (0...1000) indicating the max PWM value
	int16_t ppt;
} backlight_point_st;

/// @brief: Array of points which are used to calculate current
/// backlight brightness. The measured supply coltage is used
/// to linearily interpolate value from these points.
static const backlight_point_st backlight_points[] = {
		{10000, 1000},
		{12000, 1000},
		{13000, 900},
		{14000, 800},
		{15000, 600},
		{16000, 400},
		{17000, 0}

};
#define BACKLIGHT_POINT_COUNT	(sizeof(backlight_points) / sizeof(backlight_point_st))


/// @brief: Returns the supply voltage as millivolts
int16_t get_vdd_mv() {
	int i = uv_adc_read_average(VDD_SENSE, 10);
	// convert i into millivolts.
	// controller supply voltage is assumed to be 3.3V constant
	i = i * 3300 / ADC_MAX_VALUE;
	i = i * VDD_VOLTAGE_DIV_VAL;
	return uv_moving_aver_step(&this->vdd_mv, i);
}


void gui_init() {
	this->backlight_curr = 100;
	uv_moving_aver_init(&this->vdd_mv, VDD_MOVING_AVER_COUNT);

	gui_set_backlight(this->backlight_curr);
	uv_uidisplay_init(&this->display, this->display_buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);


	uv_uiwindow_init(&this->main_window, this->main_buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uidisplay_add(&this->display, &this->main_window, PBAR_WIDTH + PBAR_LABEL_WIDTH, 0,
			LCD_W(1) - ((PBAR_LABEL_WIDTH + PBAR_WIDTH) * 2), LCD_H(0.86));

	uv_uiprogressbar_init(&this->rpm, 0, RPM_MAX, &uv_uistyles[0]);
	uv_uiprogressbar_set_vertical(&this->rpm);
	uv_uiprogressbar_set_limit(&this->rpm, UI_PROGRESSBAR_LIMIT_OVER, RPM_WARNING_LIMIT, C(0xFF0000));
	uv_uiprogressbar_set_title(&this->rpm, "RPM");
	uv_uiprogressbar_set_value(&this->rpm, msb_get_rpm(&dspl.network.msb));
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
	uv_uiprogressbar_set_title(&this->pressure, "Pressure");
	uv_uiprogressbar_set_value(&this->pressure, ecu_get_pressure(&dspl.network.ecu));
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

	uv_rtos_task_create(gui_step, "gui", UV_RTOS_MIN_STACK_SIZE * 16,
			NULL, UV_RTOS_IDLE_PRIORITY + 1, NULL);

	this->step_callb = NULL;

	// by default show the login screen
	login_show();
}



void gui_step(void *nullptr) {
	uint16_t step_ms = GUI_STEP_MS;

	while (true) {

		// adjust the screen brightness
		int16_t vdd = get_vdd_mv();

		// find out which backlight points to use for the calculations
		int16_t smaller = 0, result;
#define BIGGER		(smaller + 1)

		if (vdd <= backlight_points[0].voltage) {
			result = backlight_points[0].ppt;
		}
		else if (vdd >= backlight_points[BACKLIGHT_POINT_COUNT - 1].voltage) {
			result = backlight_points[BACKLIGHT_POINT_COUNT - 1].ppt;
		}
		else {
			// find out the closest smaller point
			for (int16_t i = BACKLIGHT_POINT_COUNT - 1; i >= 0; i--) {
				if (backlight_points[i].voltage < vdd) {
					smaller = i;
					// closest bigger point has to be one bigger than *smaller*
					break;
				}
			}
			// lerp the value from between
			int16_t lerp = uv_reli(vdd, backlight_points[smaller].voltage, backlight_points[BIGGER].voltage);
			result = uv_lerpi(lerp, backlight_points[smaller].ppt, backlight_points[BIGGER].ppt);
		}
		int16_t pwm_max_val = PWM_MAX_VALUE * result / 1000;
		int32_t delta = this->backlight_trg - this->backlight_curr;
		if (delta > BACKLIGHT_KP_MAX) delta = BACKLIGHT_KP_MAX;
		else if (delta < -BACKLIGHT_KP_MAX) delta = -BACKLIGHT_KP_MAX;
		this->backlight_curr += delta * BACKLIGHT_KP;
		int p = PWM_MAX_VALUE - (this->backlight_curr * pwm_max_val / 0xFFFF);
//		printf("voltage: %i, pwm: %i\n", vdd, p);
		uv_pwm_set(LCD_BACKLIGHT, p);

		// active window step function
		if (this->step_callb)
			this->step_callb(step_ms);

		// taskbar step function
		taskbar_step(step_ms);

		uv_uiprogressbar_set_value(&this->rpm, msb_get_rpm(&dspl.network.msb));
		uv_uiprogressbar_set_value(&this->pressure, ecu_get_pressure(&dspl.network.ecu));

		// display step function
		uv_uidisplay_step(&this->display, step_ms);

		uv_rtos_task_delay(step_ms);
	}
}


void gui_set_backlight(uint8_t value) {
	if (value > 100) value = 100;
	this->backlight_trg = (value / 100.0f) * 0xFFFF + 0.5f;
}


int16_t gui_get_backlight() {
	return this->backlight_trg * (100.0f / 0xFFFF) + 0.5f;
}
