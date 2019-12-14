/*
 * settings_general.c
 *
 *  Created on: Oct 29, 2016
 *      Author: usevolt
 */


#include <ui/uv_uilayout.h>
#include <uv_reset.h>
#include "settings_general.h"
#include "gui.h"
#include "tr.h"
#include "main.h"

#define this (&gui.windows.settings.general)

#define GENERAL_HEIGHT		180
#define DISPLAY_HEIGHT		200
#define IMPLEMENT_HEIGHT	220
#define DATE_HEIGHT			160
#define LANG_HEIGHT			180

uv_uiobject_ret_e settings_general_step(const uint16_t step_ms);
uv_uiobject_ret_e settings_system_step(const uint16_t step_ms);
uv_uiobject_ret_e settings_implement_step(const uint16_t step_ms);
uv_uiobject_ret_e settings_date_step(const uint16_t step_ms);
uv_uiobject_ret_e settings_lang_step(const uint16_t step_ms);


void show_general_callb(uv_uitreeobject_st *obj);
void show_system_callb(uv_uitreeobject_st *obj);
void show_implement_callb(uv_uitreeobject_st *obj);
void show_date_callb(uv_uitreeobject_st *obj);
void show_lang_callb(uv_uitreeobject_st *obj);


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


	uv_uitreeobject_init(&this->generalobj, this->buffer, uv_str(STR_SETTINGS_GENERAL_TREEGENERAL),
			&show_general_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->generalobj, GENERAL_HEIGHT, true);

	uv_uitreeobject_init(&this->displayobj, this->buffer, uv_str(STR_SETTINGS_GENERAL_TREESYSTEM),
			&show_system_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->displayobj, DISPLAY_HEIGHT, false);

	uv_uitreeobject_init(&this->implementobj, this->buffer, uv_str(STR_SETTINGS_GENERAL_TREESELIMPL),
			&show_implement_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->implementobj, IMPLEMENT_HEIGHT, false);

	uv_uitreeobject_init(&this->dateobj, this->buffer, uv_str(STR_SETTINGS_GENERAL_TREEDATETIME),
			&show_date_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->dateobj, DATE_HEIGHT, false);

	uv_uitreeobject_init(&this->langobj, this->buffer, uv_str(STR_SETTINGS_GENERAL_TREELANG),
			&show_lang_callb, &uv_uistyles[0]);
	uv_uitreeview_add(&this->treeview, &this->langobj, LANG_HEIGHT, false);
}


void show_general_callb(uv_uitreeobject_st *obj) {
	uv_uitreeobject_clear(&this->generalobj);
	uv_uitreeobject_set_step_callback(&this->generalobj, &settings_general_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(&this->generalobj).width,
			uv_uitreeobject_get_content_bb(&this->generalobj).height, 3, 1);
	uv_uigridlayout_set_padding(&grid, 5, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// drive lights
	uv_output_state_e state = uv_canopen_sdo_read8(CSB_NODE_ID,
			CSB_DRIVE_LIGHT_STATUS_INDEX, CSB_DRIVE_LIGHT_STATUS_SUBINDEX);
	uv_uitogglebutton_init(&this->general.drive_lights, (state == OUTPUT_STATE_ON),
			uv_str(STR_SETTINGS_GENERAL_BUTTONDRIVELIGHT), &uv_uistyles[0]);
	uv_uitreeobject_add(&this->generalobj, &this->general.drive_lights, bb.x, bb.y,
			bb.width, bb.height / 2 - 5);

	// work lights
	state = uv_canopen_sdo_read8(CSB_NODE_ID,
			CSB_WORK_LIGHT_STATUS_INDEX, CSB_WORK_LIGHT_STATUS_SUBINDEX);
	uv_uitogglebutton_init(&this->general.work_lights, (state == OUTPUT_STATE_ON),
			uv_str(STR_SETTINGS_GENERAL_BUTTONWORKLIGHT), &uv_uistyles[0]);
	uv_uitreeobject_add(&this->generalobj,
			&this->general.work_lights, bb.x, bb.y + bb.height / 2 + 5,
			bb.width, bb.height / 2 - 5);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->general.power_usage,
			0, 100, dspl.user->engine_power_usage, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->general.power_usage);
	uv_uislider_set_title(&this->general.power_usage,
			uv_str(STR_SETTINGS_GENERAL_SLIDERENGINEPOWER));
	uv_uitreeobject_add(&this->generalobj,
			&this->general.power_usage, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->general.radiator_enable, dspl.radiator_enabled,
			"Radiator enabled", &uv_uistyles[0]);
	uv_uitreeobject_add(&this->generalobj, &this->general.radiator_enable,
			bb.x, bb.y, bb.width - 10, bb.height);
}


void show_system_callb(uv_uitreeobject_st *obj) {
	uv_uitreeobject_clear(&this->displayobj);
	uv_uitreeobject_set_step_callback(&this->displayobj, &settings_system_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(&this->displayobj).width - 10,
			uv_uitreeobject_get_content_bb(&this->displayobj).height - 20, 2, 2);
	uv_uigridlayout_set_padding(&grid, 5, 0);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// brightness
	uv_uislider_init(&this->system.brightness, 1, 100, gui_get_backlight(), &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->system.brightness);
	uv_uislider_set_title(&this->system.brightness,
			uv_str(STR_SETTINGS_GENERAL_SLIDERBRIGHTNESS));
	uv_uitreeobject_add(&this->displayobj, &this->system.brightness,
			bb.x, bb.y, bb.width, bb.height);

	// drivef comp
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->system.drivef_comp, -100, 100,
			dspl.user->drivef_comp, &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->system.drivef_comp);
	uv_uislider_set_title(&this->system.drivef_comp,
			uv_str(STR_SETTINGS_GENERAL_SLIDERDRIVEFCOMP));
	uv_uitreeobject_add(&this->displayobj, &this->system.drivef_comp,
			bb.x, bb.y, bb.width, bb.height);

	// oil cooler trigger temp
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->system.oilcooler_trigger, 0, 90,
			dspl.user->oilcooler_trigg_temp, &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->system.oilcooler_trigger);
	uv_uislider_set_title(&this->system.oilcooler_trigger,
			uv_str(STR_SETTINGS_GENERAL_SLIDEROILCTEMP));
	uv_uitreeobject_add(&this->displayobj, &this->system.oilcooler_trigger,
			bb.x, bb.y, bb.width, bb.height);

	// driveb comp
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->system.driveb_comp, -100, 100,
			dspl.user->driveb_comp, &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->system.driveb_comp);
	uv_uislider_set_title(&this->system.driveb_comp,
			uv_str(STR_SETTINGS_GENERAL_SLIDERDRIVEBCOMP));
	uv_uitreeobject_add(&this->displayobj, &this->system.driveb_comp,
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
			HCU_IMPLEMENT_COUNT, &uv_uistyles[0]);

	// todo: Add all implements here
	uv_uilist_push_back(&this->implement.impls_list, dspl.user->uw180s.super.name);
	uv_uilist_push_back(&this->implement.impls_list, dspl.user->uw100.super.name);
	uv_uilist_push_back(&this->implement.impls_list, dspl.user->uw50.super.name);
	uv_uilist_push_back(&this->implement.impls_list, dspl.user->hydout.super.name);

	uv_uilist_select(&this->implement.impls_list, hcu_get_implement(&dspl.network.hcu));

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


void show_lang_callb(uv_uitreeobject_st *obj) {
	uv_uitreeobject_clear(&this->langobj);
	uv_uitreeobject_set_step_callback(&this->langobj, &settings_lang_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(&this->langobj).width,
			uv_uitreeobject_get_content_bb(&this->langobj).height, 2, 1);
	uv_uigridlayout_set_padding(&grid, 10, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uilist_init(&this->lang.languages, this->lang.lang_list, LANG_COUNT, &uv_uistyles[0]);
	uint8_t index = 0;
	for (languages_e i = LANG_EN; i < LANG_COUNT; i++) {
		this->lang.lang_list[index] = uv_strlang(STR_LANG, i);
		uv_uilist_push_back(&this->lang.languages, this->lang.lang_list[index]);
		index++;
	}
	uv_uilist_select(&this->lang.languages, get_lang() - LANG_EN);
	uv_uitreeobject_add(&this->langobj, &this->lang.languages, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->lang.setlang,
			uv_str(STR_SETTINGS_GENERAL_BUTTONSETLANG), &uv_uistyles[0]);
	uv_uitreeobject_add(&this->langobj, &this->lang.setlang,
			bb.x, bb.y, bb.width, bb.height / 2);

}



uv_uiobject_ret_e settings_general_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	// drive lights
	if (uv_uitogglebutton_clicked(&this->general.drive_lights)) {
		uv_output_state_e state = (uv_uitogglebutton_get_state(&this->general.drive_lights)) ?
				OUTPUT_STATE_ON : OUTPUT_STATE_OFF;
		uv_canopen_sdo_write(CSB_NODE_ID, CSB_DRIVE_LIGHT_STATUS_INDEX,
				CSB_DRIVE_LIGHT_STATUS_SUBINDEX,
				CANOPEN_TYPE_LEN(CSB_DRIVE_LIGHT_STATUS_TYPE), &state);
	}

	// work lights
	if (uv_uitogglebutton_clicked(&this->general.work_lights)) {
		uv_output_state_e state = (uv_uitogglebutton_get_state(&this->general.work_lights)) ?
				OUTPUT_STATE_ON : OUTPUT_STATE_OFF;
		uv_canopen_sdo_write(CSB_NODE_ID, CSB_WORK_LIGHT_STATUS_INDEX,
				CSB_WORK_LIGHT_STATUS_SUBINDEX,
				CANOPEN_TYPE_LEN(CSB_WORK_LIGHT_STATUS_TYPE), &state);
	}

	// power usage
	if (uv_uislider_value_changed(&this->general.power_usage)) {
		dspl.user->engine_power_usage = uv_uislider_get_value(&this->general.power_usage);
		uv_canopen_sdo_write(ESB_NODE_ID, ESB_ENGINE_POWER_USAGE_INDEX,
				ESB_ENGINE_POWER_USAGE_SUBINDEX, CANOPEN_TYPE_LEN(ESB_ENGINE_POWER_USAGE_TYPE),
				&dspl.user->engine_power_usage);
	}

	// radiator enable
	if (uv_uitogglebutton_clicked(&this->general.radiator_enable)) {
		uint8_t val = uv_uitogglebutton_get_state(&this->general.radiator_enable);
		uv_canopen_sdo_write(ESB_NODE_ID, ESB_RADIATOR_ENABLED_INDEX,
				ESB_RADIATOR_ENABLED__SUBINDEX, 1, &val);
		uv_uitogglebutton_set_text(&this->general.radiator_enable, val ?
				"Radiator enabled" : "Radiator disabled");
	}


	return ret;
}


uv_uiobject_ret_e settings_system_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	// brightness
	if (uv_uislider_value_changed(&this->system.brightness)) {
		gui_set_backlight(uv_uislider_get_value(&this->system.brightness));
	}
	else {
		uv_uislider_set_value(&this->system.brightness, gui_get_backlight());
	}

	// oil cooler trigger temp
	if (uv_uislider_value_changed(&this->system.oilcooler_trigger)) {
		dspl.user->oilcooler_trigg_temp = uv_uislider_get_value(&this->system.oilcooler_trigger);
		uv_canopen_sdo_write8(ESB_NODE_ID,
				ESB_OILCOOLER_TRIGGER_INDEX, ESB_OILCOOLER_TRIGGER_SUBINDEX,
				uv_uislider_get_value(&this->system.oilcooler_trigger));
	}
	else if (uv_uislider_value_changed(&this->system.drivef_comp)) {
		dspl.user->drivef_comp = uv_uislider_get_value(&this->system.drivef_comp);
		uv_canopen_sdo_write8(CCU_NODE_ID,
				CCU_DRIVE_COMP_INDEX, 1,
				(int8_t) uv_uislider_get_value(&this->system.drivef_comp));
	}
	else if (uv_uislider_value_changed(&this->system.driveb_comp)) {
		dspl.user->driveb_comp = uv_uislider_get_value(&this->system.driveb_comp);
		uv_canopen_sdo_write8(CCU_NODE_ID,
				CCU_DRIVE_COMP_INDEX, 2,
				(int8_t) uv_uislider_get_value(&this->system.driveb_comp));
	}
	else {

	}



	return ret;
}



uv_uiobject_ret_e settings_implement_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (uv_uilist_get_selected(&this->implement.impls_list) !=
			hcu_get_implement(&dspl.network.hcu)) {
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


uv_uiobject_ret_e settings_lang_step(const uint16_t step_ms) {

	if (uv_uibutton_clicked(&this->lang.setlang)) {
		if (dspl.lang != (uv_uilist_get_selected(&this->lang.languages) + LANG_EN)) {
			dspl.lang = uv_uilist_get_selected(&this->lang.languages) + LANG_EN;
			uv_memory_save();
			uv_system_reset();
		}
	}
	else {

	}

	return UIOBJECT_RETURN_ALIVE;
}


