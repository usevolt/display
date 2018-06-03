/*
 * settings_general.c
 *
 *  Created on: Oct 29, 2016
 *      Author: usevolt
 */


#include <ui/uv_uilayout.h>
#include "settings_general.h"
#include "gui.h"

#define this (&gui.windows.settings.general)

#define GENERAL_HEIGHT		200
#define DISPLAY_HEIGHT		140
#define DATE_HEIGHT			160
#define IMPLEMENT_HEIGHT	200

uv_uiobject_ret_e settings_general_step(const uint16_t step_ms);
uv_uiobject_ret_e settings_volume_step(const uint16_t step_ms);
uv_uiobject_ret_e settings_implement_step(const uint16_t step_ms);
uv_uiobject_ret_e settings_date_step(const uint16_t step_ms);


void show_general_callb(uv_uitreeobject_st *obj);
void show_display_callb(uv_uitreeobject_st *obj);
void show_implement_callb(uv_uitreeobject_st *obj);
void show_date_callb(uv_uitreeobject_st *obj);


static void update_time() {
	snprintf(this->date.datestr, DATE_STR_LEN, "%04u-%02u-%02u %02u:%02u:%02u",
			this->date.date.year, this->date.date.month, this->date.date.day,
			this->date.date.hour, this->date.date.min, this->date.date.sec);
	uv_ui_refresh(&this->date.date_label);
	uv_rtc_set_time(&this->date.date);
	taskbar_update_clock();
}


void settings_general_show(void) {
	uv_uitabwindow_st* window = (uv_uitabwindow_st *) &gui.windows.settings.tabs;
	uv_uitabwindow_clear(window);

	uv_uitreeview_init(&this->treeview, this->objbuffer, &uv_uistyles[0]);
	uv_uitabwindow_add(window, &this->treeview, 0, 0,
			uv_uibb(window)->width, uv_uitabwindow_get_contentbb(window).height);


	uv_uitreeobject_init(&this->generalobj, this->buffer, "General",
			&show_general_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->generalobj, GENERAL_HEIGHT, false);

	uv_uitreeobject_init(&this->displayobj, this->buffer, "Display",
			&show_display_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->displayobj, DISPLAY_HEIGHT, false);

	uv_uitreeobject_init(&this->implementobj, this->buffer, "Select Implement",
			&show_implement_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->implementobj, IMPLEMENT_HEIGHT, false);

	uv_uitreeobject_init(&this->dateobj, this->buffer, "Date and Time",
			&show_date_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->dateobj, DATE_HEIGHT, false);
}


void show_general_callb(uv_uitreeobject_st *obj) {
	uv_uitreeobject_clear(&this->generalobj);
	uv_uitreeobject_set_step_callback(&this->generalobj, &settings_general_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(&this->generalobj).width,
			uv_uitreeobject_get_content_bb(&this->generalobj).height, 4, 1);
	uv_uigridlayout_set_padding(&grid, 5, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// drive lights
	uv_uitogglebutton_init(&this->general.drive_lights, csb_get_drive_light(&dspl.network.csb),
			"Drive Lights", &uv_uistyles[0]);
	uv_uitreeobject_add(&this->generalobj, &this->general.drive_lights, bb.x, bb.y,
			bb.width, bb.height / 2 - 5);

	// work lights
	uv_uitogglebutton_init(&this->general.work_lights, csb_get_work_light(&dspl.network.csb),
			"Work Lights", &uv_uistyles[0]);
	uv_uitreeobject_add(&this->generalobj, &this->general.work_lights, bb.x, bb.y + bb.height / 2 + 5,
			bb.width, bb.height / 2 - 5);

	// wiper
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->general.wiper, 0, CSB_WIPER_SPEED_COUNT - 1,
			csb_get_wiper(&dspl.network.csb), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->general.wiper);
	uv_uislider_set_title(&this->general.wiper, "Wiper");
	uv_uitreeobject_add(&this->generalobj, &this->general.wiper, bb.x, bb.y, bb.width, bb.height);

	// heater
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->general.heater, 0, MSB_HEATER_SPEED_COUNT - 1,
			msb_get_heater(&dspl.network.msb), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->general.heater);
	uv_uislider_set_title(&this->general.heater, "Heater");
	uv_uitreeobject_add(&this->generalobj, &this->general.heater, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->general.power_usage, 0, 100, dspl.user->engine_power_usage, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->general.power_usage);
	uv_uislider_set_title(&this->general.power_usage, "Engine power\nusage (%)");
	uv_uitreeobject_add(&this->generalobj, &this->general.power_usage, bb.x, bb.y, bb.width, bb.height);


}

void show_display_callb(uv_uitreeobject_st *obj) {
	uv_uitreeobject_clear(&this->displayobj);
	uv_uitreeobject_set_step_callback(&this->displayobj, &settings_volume_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(&this->displayobj).width,
			uv_uitreeobject_get_content_bb(&this->displayobj).height, 2, 1);
	uv_uigridlayout_set_padding(&grid, 30, 0);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// brightness
	uv_uislider_init(&this->display.brightness, 1, 100, gui_get_backlight(), &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->display.brightness);
	uv_uislider_set_title(&this->display.brightness, "Screen\nbrightness");
	uv_uitreeobject_add(&this->displayobj, &this->display.brightness,
			bb.x, bb.y, bb.width, bb.height);

	// volume
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->display.volume, 0, 100, alert_get_volume(&dspl.alert), &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->display.volume);
	uv_uislider_set_title(&this->display.volume, "Volume");
	uv_uitreeobject_add(&this->displayobj, &this->display.volume,
			bb.x, bb.y, bb.width, bb.height);

}


void show_implement_callb(uv_uitreeobject_st *obj) {
	uv_uitreeobject_clear(&this->implementobj);
	uv_uitreeobject_set_step_callback(&this->implementobj, &settings_implement_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(&this->implementobj).width,
			uv_uitreeobject_get_content_bb(&this->implementobj).height, 2, 1);
	uv_uigridlayout_set_padding(&grid, 2, 1);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// implement select
	uv_uilist_init(&this->implement.impls_list, this->implement.impl_names,
			UW_IMPLEMENT_COUNT, &uv_uistyles[0]);

	// todo: Add all implements here
	uv_uilist_push_back(&this->implement.impls_list, dspl.user->uw180s.super.name);
	uv_uilist_push_back(&this->implement.impls_list, dspl.user->uw100.super.name);
	uv_uilist_push_back(&this->implement.impls_list, dspl.user->uw50.super.name);

	uv_uilist_select(&this->implement.impls_list, dspl.user->active_implement);

	uv_uitreeobject_add(&this->implementobj, &this->implement.impls_list, bb.x, bb.y,
			bb.width, bb.height - UI_FONT_SMALL.char_height);


}

void show_date_callb(uv_uitreeobject_st *obj) {
	uv_uitreeobject_clear(&this->dateobj);
	uv_uitreeobject_set_step_callback(&this->dateobj, &settings_date_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(&this->dateobj).width,
			uv_uitreeobject_get_content_bb(&this->dateobj).height, 2, 1);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// set time
	uv_rtc_get_time(&this->date.date);
	update_time();

	int16_t fw = UI_FONT_BIG.char_width;
	int16_t fh = UI_FONT_BIG.char_height;

	uv_uilabel_init(&this->date.date_label, &UI_FONT_BIG, ALIGN_CENTER_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->date.datestr);
	uv_uitreeobject_add(&this->dateobj, &this->date.date_label,
			bb.x + bb.width / 2, bb.y + bb.height / 2 - fh / 2 - 10, bb.width, fh);

	int16_t datex = uv_uibb(&this->date.date_label)->x;
	int16_t datey = uv_uibb(&this->date.date_label)->y +
			uv_uibb(&this->date.date_label)->height / 2;

	uv_uibutton_init(&this->date.sec_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.sec_inc,
			datex + fw * 17, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->date.sec_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.sec_dec,
			datex + fw * 17, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->date.min_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.min_inc,
			datex + fw * 14, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->date.min_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.min_dec,
			datex + fw * 14, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->date.hour_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.hour_inc,
			datex + fw * 11, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->date.hour_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.hour_dec,
			datex + fw * 11, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->date.day_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.day_inc,
			datex + fw * 8, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->date.day_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.day_dec,
			datex + fw * 8, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->date.month_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.month_inc,
			datex + fw * 5, datey - fh * 2 - 8,
			fw * 2, fh * 1.5);
	uv_uibutton_init(&this->date.month_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.month_dec,
			datex + fw * 5, datey + fh / 2 + 8,
			fw * 2, fh * 1.5);

	uv_uibutton_init(&this->date.year_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.year_inc,
			datex, datey - fh * 2 - 8,
			fw * 4, fh * 1.5);
	uv_uibutton_init(&this->date.year_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uitreeobject_add(&this->dateobj, &this->date.year_dec,
			datex, datey + fh / 2 + 8,
			fw * 4, fh * 1.5);

}



uv_uiobject_ret_e settings_general_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	// drive lights
	if (uv_uitogglebutton_clicked(&this->general.drive_lights)) {
		csb_set_drive_light(&dspl.network.csb, uv_uitogglebutton_get_state(&this->general.drive_lights));
	}
	else {
		uv_uitogglebutton_set_state(&this->general.drive_lights, csb_get_drive_light(&dspl.network.csb));
	}

	// work lights
	if (uv_uitogglebutton_clicked(&this->general.work_lights)) {
		csb_set_work_light(&dspl.network.csb, uv_uitogglebutton_get_state(&this->general.work_lights));
		msb_set_crane_light(&dspl.network.msb, uv_uitogglebutton_get_state(&this->general.work_lights));
	}
	else {
		uv_uitogglebutton_set_state(&this->general.work_lights, csb_get_work_light(&dspl.network.csb));
	}

	// wiper
	if (uv_uislider_value_changed(&this->general.wiper)) {
		csb_set_wiper(&dspl.network.csb, uv_uislider_get_value(&this->general.wiper));
	}

	// heater
	if (uv_uislider_value_changed(&this->general.heater)) {
		msb_set_heater(&dspl.network.msb, uv_uislider_get_value(&this->general.heater));
	}

	// power usage
	if (uv_uislider_value_changed(&this->general.power_usage)) {
		dspl.user->engine_power_usage = uv_uislider_get_value(&this->general.power_usage);
		ecu_set_engine_power_usage(dspl.user->engine_power_usage);
	}


	return ret;
}


uv_uiobject_ret_e settings_volume_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	// brightness
	if (uv_uislider_value_changed(&this->display.brightness)) {
		gui_set_backlight(uv_uislider_get_value(&this->display.brightness));
	}
	else {
		uv_uislider_set_value(&this->display.brightness, gui_get_backlight());
	}

	// volume
	if (uv_uislider_value_changed(&this->display.volume)) {
		alert_set_volume(&dspl.alert, uv_uislider_get_value(&this->display.volume));
	}
	else {
		uv_uislider_set_value(&this->display.volume, alert_get_volume(&dspl.alert));
	}


	return ret;
}



uv_uiobject_ret_e settings_implement_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (uv_uilist_get_selected(&this->implement.impls_list) != dspl.user->active_implement) {
		implement_set(uv_uilist_get_selected(&this->implement.impls_list));
	}


	return ret;
}


uv_uiobject_ret_e settings_date_step(const uint16_t step_ms) {
	if (uv_uibutton_clicked(&this->date.year_inc)) {
		this->date.date.year++;
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.year_dec)) {
		this->date.date.year--;
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.month_inc)) {
		this->date.date.month++;
		if (this->date.date.month > 12) { this->date.date.month = 1; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.month_dec)) {
		if (this->date.date.month > 1) { this->date.date.month--; }
		else { this->date.date.month = 12; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.day_inc)) {
		if (this->date.date.day == 31) { this->date.date.day = 1; }
		else { this->date.date.day++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.day_dec)) {
		if (this->date.date.day > 1) { this->date.date.day--; }
		else { this->date.date.day = 31; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.hour_inc)) {
		if (this->date.date.hour == 24) { this->date.date.hour = 0; }
		else { this->date.date.hour++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.hour_dec)) {
		if (this->date.date.hour == 0) { this->date.date.hour = 23; }
		else { this->date.date.hour--; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.min_inc)) {
		if (this->date.date.min == 59) { this->date.date.min = 0; }
		else { this->date.date.min++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.min_dec)) {
		if (this->date.date.min == 0) { this->date.date.min = 59; }
		else { this->date.date.min--; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.sec_inc)) {
		if (this->date.date.sec == 59) { this->date.date.sec = 0; }
		else { this->date.date.sec++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->date.sec_dec)) {
		if (this->date.date.sec == 0) { this->date.date.sec = 59; }
		else { this->date.date.sec--; }
		update_time();
	}
	else {

	}

	return UIOBJECT_RETURN_ALIVE;
}

