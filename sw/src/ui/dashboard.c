/*
 * dashboard.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "dashboard.h"
#include "gui.h"
#include "home.h"

#define this (&gui.windows.dashboard)

#define PBAR_WIDTH			70
#define PBAR_LABEL_X		53
#define PBAR_LABEL_WIDTH	30


void dashboard_show(void) {
	uv_uiwindow_clear(&gui.main_window);

	gui.step_callb = dashboard_step;

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height,
			uv_uiwindow_step);

	TOPIC_INIT(&this->window, &this->topic, "Dashboard");

	CANCEL_INIT(&this->window, &this->cancel);

	OK_INIT(&this->window, &this->ok);

	uv_uiprogressbar_init(&this->rpm, 0, RPM_MAX, &uv_uistyles[0]);
	uv_uiprogressbar_set_vertical(&this->rpm);
	uv_uiprogressbar_set_limit(&this->rpm, UI_PROGRESSBAR_LIMIT_OVER, RPM_WARNING_LIMIT, C(0xFF0000));
	uv_uiprogressbar_set_title(&this->rpm, "RPM");
	uv_uiprogressbar_set_value(&this->rpm, msb_get_rpm(&dspl.network.msb));
	uv_uiwindow_add(&this->window, &this->rpm, 0, TOPIC_HEIGHT, PBAR_WIDTH,
			uv_uibb(&this->window)->height - TOPIC_HEIGHT, uv_uiprogressbar_step);

	uv_uilabel_init(&this->rpm_3000, &UI_FONT_SMALL, ALIGN_CENTER_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), "3000");
	uv_uiwindow_add(&this->window, &this->rpm_3000,
			PBAR_LABEL_X,
			uv_uibb(&this->rpm)->y +
			uv_lerpf(1.0f - 3000.0f / RPM_MAX, 0,
					uv_uibb(&this->rpm)->height - this->rpm.style->font->char_height),
			40, 0, uv_uilabel_step);

	uv_uilabel_init(&this->rpm_2000, &UI_FONT_SMALL, ALIGN_CENTER_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), "2000");
	uv_uiwindow_add(&this->window, &this->rpm_2000,
			PBAR_LABEL_X,
			uv_uibb(&this->rpm)->y +
			uv_lerpf(1.0f - 2000.0f / RPM_MAX, 0,
					uv_uibb(&this->rpm)->height - this->rpm.style->font->char_height),
			40, 0, uv_uilabel_step);

	uv_uilabel_init(&this->rpm_1000, &UI_FONT_SMALL, ALIGN_CENTER_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), "1000");
	uv_uiwindow_add(&this->window, &this->rpm_1000,
			PBAR_LABEL_X,
			uv_uibb(&this->rpm)->y +
			uv_lerpf(1.0f - 1000.0f / RPM_MAX, 0,
					uv_uibb(&this->rpm)->height - this->rpm.style->font->char_height),
			40, 0, uv_uilabel_step);

	uv_uiprogressbar_init(&this->pressure, 0, PRESSURE_MAX, &uv_uistyles[0]);
	uv_uiprogressbar_set_vertical(&this->pressure);
	uv_uiprogressbar_set_title(&this->pressure, "Pressure");
	uv_uiprogressbar_set_value(&this->pressure, ecu_get_pressure(&dspl.network.ecu));
	uv_uiwindow_add(&this->window, &this->pressure,
			uv_uibb(&this->window)->width - PBAR_WIDTH - CONFIG_UI_PROGRESSBAR_WIDTH,
			TOPIC_HEIGHT, PBAR_WIDTH,
			uv_uibb(&this->window)->height - TOPIC_HEIGHT, uv_uiprogressbar_step);

	uv_uilabel_init(&this->pressure_200, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT,
			C(0xFFFFFF), C(0xFFFFFFFF), "200");
	uv_uiwindow_add(&this->window, &this->pressure_200,
			uv_uibb(&this->window)->width - PBAR_LABEL_X,
			uv_uibb(&this->pressure)->y +
			uv_lerpf(1.0f - 200.0f / PRESSURE_MAX, 0,
					uv_uibb(&this->pressure)->height - this->rpm.style->font->char_height),
			-4, 0, uv_uilabel_step);

	uv_uilabel_init(&this->pressure_100, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT,
			C(0xFFFFFF), C(0xFFFFFFFF), "100");
	uv_uiwindow_add(&this->window, &this->pressure_100,
			uv_uibb(&this->window)->width - PBAR_LABEL_X,
			uv_uibb(&this->pressure)->y +
			uv_lerpf(1.0f - 100.0f / PRESSURE_MAX, 0,
					uv_uibb(&this->pressure)->height - this->rpm.style->font->char_height),
			-4, 0, uv_uilabel_step);

	uv_uiwindow_init(&this->impl_window, this->impl_buffer, &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->impl_window, PBAR_WIDTH + PBAR_LABEL_WIDTH, TOPIC_HEIGHT,
			uv_uibb(&this->window)->width - PBAR_WIDTH * 2 - PBAR_LABEL_WIDTH * 2,
			uv_uibb(&this->window)->height - TOPIC_HEIGHT,
			uv_uiwindow_step);

	// show the active implement's dashboard UI
	if (dspl.user->implement && dspl.user->implement->callbacks->dashboard_show) {
		dspl.user->implement->callbacks->dashboard_show();
	}
}


void dashboard_step(uint16_t step_ms) {

	uv_uiprogressbar_set_value(&this->rpm, msb_get_rpm(&dspl.network.msb));
	uv_uiprogressbar_set_value(&this->pressure, ecu_get_pressure(&dspl.network.ecu));

	if (uv_uibutton_clicked(&this->cancel)) {
		home_show();
		return;
	}
	else if (uv_uibutton_clicked(&this->ok)) {
		uv_memory_save(&dspl.data_start, &dspl.data_end);
		home_show();
		return;
	}
	// active implement dasboard step
	if (dspl.user->implement && dspl.user->implement->callbacks->dasboard_step) {
		dspl.user->implement->callbacks->dasboard_step(step_ms);
	}
}
