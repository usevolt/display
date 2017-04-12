/*
 * system_settings.c
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */


#include "system_settings.h"
#include "gui.h"


#define this	(&gui.windows.system.windows.sys_settings)


static void update_time() {
	snprintf(this->datestr, DATE_STR_LEN, "%04u-%02u-%02u %02u:%02u:%02u",
			this->date.year, this->date.month, this->date.day,
			this->date.hour, this->date.min, this->date.sec);
	uv_ui_refresh(&this->date_label);
	uv_rtc_set_time(&this->date);
}


void system_settings_show(void) {
	uv_uiwindow_clear(&gui.windows.system.tabs);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_set_contentbb(&this->window, uv_uibb(&gui.windows.system.tabs)->width,
			uv_uibb(&gui.windows.system.tabs)->height * 1.8f);
	uv_uitabwindow_add(&gui.windows.system.tabs, &this->window, 0, 0,
			uv_uibb(&gui.windows.system.tabs)->width,
			uv_uitabwindow_get_contentbb(&gui.windows.system.tabs).height);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uiwindow_get_contentbb(&this->window).width,
			uv_uiwindow_get_contentbb(&this->window).height, 2, 3);
	uv_uigridlayout_set_padding(&grid, 10, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// implement select
	uv_uilabel_init(&this->impls_label, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Current implement");
	uv_uiwindow_add(&this->window, &this->impls_label, bb.x, bb.y,
			bb.width, bb.height);

	uv_uilist_init(&this->impls_list, this->impl_names,
			UW_IMPLEMENT_COUNT, &uv_uistyles[0]);

	// todo: Add all implements here
	uv_uilist_push_back(&this->impls_list, dspl.user->uw180s.super.name);
	uv_uilist_push_back(&this->impls_list, dspl.user->uw100.super.name);
	uv_uilist_push_back(&this->impls_list, dspl.user->uw50.super.name);

	uv_uilist_select(&this->impls_list, dspl.user->active_implement);

	uv_uiwindow_add(&this->window, &this->impls_list, bb.x, bb.y,
			bb.width, bb.height - UI_FONT_SMALL.char_height);


	// engine power usage
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->power_usage, 0, 100, dspl.user->engine_power_usage, &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->power_usage);
	uv_uislider_set_title(&this->power_usage, "Engine power\nusage (%)");
	uv_uiwindow_add(&this->window, &this->power_usage, bb.x, bb.y, bb.width, bb.height);

	// Joystick calibration
	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->calib_start, false,
			"Joystick\nCalibration", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->calib_start, bb.x, bb.y + bb.height / 6, bb.width / 2, bb.height / 3);

	int16_t calib_x = bb.x + bb.width / 2 + 5;
	int16_t calib_w = bb.width * 1.5f;
	int16_t calib_values_w = 70;

	uv_uilabel_init(&this->calib_labels1, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), "Left:\n"
					"x max\n"
					"x middle\n"
					"x min\n \n"
					"Right:\n"
					"x max\n"
					"x middle\n"
					"x min");
	uv_uiwindow_add(&this->window, &this->calib_labels1, calib_x, bb.y,
			calib_w / 3, bb.height);
	uv_uilabel_init(&this->calib_values1, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), uv_uistyles[0].window_c, this->calib_values1_str);
	uv_uiwindow_add(&this->window, &this->calib_values1,
			calib_x + calib_w / 3 - calib_values_w, bb.y + UI_FONT_SMALL.char_height,
			calib_values_w, bb.height - UI_FONT_SMALL.char_height * 3);
	snprintf(this->calib_values1_str, CALIB_LINE_LEN, "0\n0\n0\n \n \n0\n0\n0");

	uv_uilabel_init(&this->calib_labels2, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), " \ny max\n"
					"y middle\n"
					"y min\n"
					" \n"
					" \n"
					"y max\n"
					"y middle\n"
					"y min");
	uv_uiwindow_add(&this->window, &this->calib_labels2, calib_x + calib_w / 3, bb.y,
			calib_w / 3, bb.height);
	uv_uilabel_init(&this->calib_values2, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), uv_uistyles[0].window_c, this->calib_values2_str);
	uv_uiwindow_add(&this->window, &this->calib_values2,
			calib_x + calib_w * 2 / 3 - calib_values_w, bb.y + UI_FONT_SMALL.char_height,
			calib_values_w, bb.height - UI_FONT_SMALL.char_height * 3);
	snprintf(this->calib_values2_str, CALIB_LINE_LEN, "0\n0\n0\n \n \n0\n0\n0");

	uv_uilabel_init(&this->calib_labels3, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), " \nz max\n"
					"z middle\n"
					"z min\n"
					" \n"
					" \n"
					"z max\n"
					"z middle\n"
					"z min");
	uv_uiwindow_add(&this->window, &this->calib_labels3, calib_x + calib_w * 2 / 3,
			bb.y, calib_w / 3, bb.height);
	uv_uilabel_init(&this->calib_values3, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), uv_uistyles[0].window_c, this->calib_values3_str);
	uv_uiwindow_add(&this->window, &this->calib_values3,
			calib_x + calib_w - calib_values_w, bb.y + UI_FONT_SMALL.char_height,
			calib_values_w, bb.height - UI_FONT_SMALL.char_height * 3);
	snprintf(this->calib_values3_str, CALIB_LINE_LEN, "0\n0\n0\n \n \n0\n0\n0");



	uv_uilabel_init(&this->calib_help, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "To calibrate the joysticks,\n"
					"rotate through all of their axes and thumb switches");
	uv_uiwindow_add(&this->window, &this->calib_help, calib_x, bb.y + bb.height,
			calib_w, 0);


	bb = uv_uigridlayout_next(&grid);

	// set time
	bb = uv_uigridlayout_next(&grid);
	uv_rtc_get_time(&this->date);
	update_time();
	uv_uilabel_init(&this->time, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Date and time");
	uv_uiwindow_add(&this->window, &this->time,
			bb.x + bb.width / 2, bb.y + bb.height, bb.width, 0);

	int16_t fw = UI_FONT_BIG.char_width;
	int16_t fh = UI_FONT_BIG.char_height;

	uv_uilabel_init(&this->date_label, &UI_FONT_BIG, ALIGN_CENTER_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->datestr);
	uv_uiwindow_add(&this->window, &this->date_label,
			bb.x + bb.width / 2, bb.y + bb.height / 2 - fh / 2, bb.width, fh);

	int16_t datex = uv_uibb(&this->date_label)->x;
	int16_t datey = uv_uibb(&this->date_label)->y + uv_uibb(&this->date_label)->height / 2;

	uv_uibutton_init(&this->sec_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->sec_inc,
			datex + fw * 17, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->sec_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->sec_dec,
			datex + fw * 17, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->min_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->min_inc,
			datex + fw * 14, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->min_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->min_dec,
			datex + fw * 14, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->hour_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->hour_inc,
			datex + fw * 11, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->hour_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->hour_dec,
			datex + fw * 11, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->day_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->day_inc,
			datex + fw * 8, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->day_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->day_dec,
			datex + fw * 8, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->month_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->month_inc,
			datex + fw * 5, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->month_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->month_dec,
			datex + fw * 5, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->year_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->year_inc,
			datex, datey - fh * 2 - 8,
			fw * 4, fh * 1.5);
	uv_uibutton_init(&this->year_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->year_dec,
			datex, datey + fh / 2 + 8,
			fw * 4, fh * 1.5);
}




void system_settings_step(uint16_t step_ms) {
	if (uv_uilist_get_selected(&this->impls_list) != dspl.user->active_implement) {
		implement_set(uv_uilist_get_selected(&this->impls_list));
	}

	if (uv_uislider_value_changed(&this->power_usage)) {
		dspl.user->engine_power_usage = uv_uislider_get_value(&this->power_usage);
		ecu_set_engine_power_usage(dspl.user->engine_power_usage);
	}
	else if (uv_uibutton_clicked(&this->year_inc)) {
		this->date.year++;
		update_time();
	}
	else if (uv_uibutton_clicked(&this->year_dec)) {
		this->date.year--;
		update_time();
	}
	else if (uv_uibutton_clicked(&this->month_inc)) {
		this->date.month++;
		if (this->date.month > 12) { this->date.month = 1; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->month_dec)) {
		if (this->date.month > 1) { this->date.month--; }
		else { this->date.month = 12; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->day_inc)) {
		if (this->date.day == 31) { this->date.day = 1; }
		else { this->date.day++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->day_dec)) {
		if (this->date.day > 1) { this->date.day--; }
		else { this->date.day = 31; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->hour_inc)) {
		if (this->date.hour == 24) { this->date.hour = 0; }
		else { this->date.hour++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->hour_dec)) {
		if (this->date.hour == 0) { this->date.hour = 23; }
		else { this->date.hour--; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->min_inc)) {
		if (this->date.min == 59) { this->date.min = 0; }
		else { this->date.min++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->min_dec)) {
		if (this->date.min == 0) { this->date.min = 59; }
		else { this->date.min--; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->sec_inc)) {
		if (this->date.sec == 59) { this->date.sec = 0; }
		else { this->date.sec++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->sec_dec)) {
		if (this->date.sec == 0) { this->date.sec = 59; }
		else { this->date.sec--; }
		update_time();
	}
	else {

	}

	if (uv_uitogglebutton_clicked(&this->calib_start)) {
		if (uv_uitogglebutton_get_state(&this->calib_start)) {
			keypad_calib_start(&dspl.network.l_keypad);
			keypad_calib_start(&dspl.network.r_keypad);
		}
		else {
			keypad_calib_end(&dspl.network.l_keypad);
			keypad_calib_end(&dspl.network.r_keypad);
		}
	}
	else if (uv_uitogglebutton_get_state(&this->calib_start)) {
		uint16_t *l_calib_data = keypad_get_x_calib(&dspl.network.l_keypad);
		uint16_t *r_calib_data = keypad_get_x_calib(&dspl.network.r_keypad);

		snprintf(this->calib_values1_str, CALIB_LINE_LEN, "%i\n%i\n%i\n \n \n%i\n%i\n%i",
				l_calib_data[0], l_calib_data[1], l_calib_data[2],
				r_calib_data[0], r_calib_data[1], r_calib_data[2]);
		uv_ui_refresh(&this->calib_values1);

		l_calib_data = keypad_get_y_calib(&dspl.network.l_keypad);
		r_calib_data = keypad_get_y_calib(&dspl.network.r_keypad);
		snprintf(this->calib_values2_str, CALIB_LINE_LEN, "%i\n%i\n%i\n \n \n%i\n%i\n%i",
				l_calib_data[0], l_calib_data[1], l_calib_data[2],
				r_calib_data[0], r_calib_data[1], r_calib_data[2]);
		uv_ui_refresh(&this->calib_values2);

		l_calib_data = keypad_get_z_calib(&dspl.network.l_keypad);
		r_calib_data = keypad_get_z_calib(&dspl.network.r_keypad);
		snprintf(this->calib_values3_str, CALIB_LINE_LEN, "%i\n%i\n%i\n \n \n%i\n%i\n%i",
				l_calib_data[0], l_calib_data[1], l_calib_data[2],
				r_calib_data[0], r_calib_data[1], r_calib_data[2]);
		uv_ui_refresh(&this->calib_values3);
	}

}
