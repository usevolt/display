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



void settings_general_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.settings.tabs;

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_add(window, &this->window, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uibb(window)->width, uv_uibb(window)->height - CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uiwindow_step);

	// brightness
	uv_uilabel_init(&this->brightness_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Screen\n\rbrightness");
	uv_uiwindow_add(&this->window, &this->brightness_label,
			uv_uibb(&this->window)->width / 6, uv_uibb(&this->window)->height/2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uislider_init(&this->brightness, 1, 100, gui_get_backlight(), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->brightness);
	uv_uiwindow_add(&this->window, &this->brightness,
			UI_ALIGN_CENTER(
					uv_uibb(&this->brightness_label)->x,
					uv_uibb(&this->brightness_label)->y - 110,
					50,
					200),
			uv_uislider_step);

	// volume
	uv_uilabel_init(&this->volume_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Volume");
	uv_uiwindow_add(&this->window, &this->volume_label,
			uv_uibb(&this->window)->width / 8 * 3, uv_uibb(&this->window)->height/2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uislider_init(&this->volume, 0, 100, alert_get_volume(&dspl.alert), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->volume);
	uv_uiwindow_add(&this->window, &this->volume,
			UI_ALIGN_CENTER(
					uv_uibb(&this->volume_label)->x,
					uv_uibb(&this->volume_label)->y - 110,
					50,
					200),
			uv_uislider_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, uv_uibb(&this->volume)->x + uv_uibb(&this->volume)->width + 10, 0,
			uv_uibb(&this->window)->width - uv_uibb(&this->volume)->x - uv_uibb(&this->volume)->width - 10,
			uv_uibb(&this->window)->height, 3, 1);
	uv_uigridlayout_set_padding(&grid, 10, 40);
	uv_bounding_box_st bb;

	// drive lights
	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->drive_lights, csb_get_drive_light(&dspl.network.csb),
			"Drive Lights", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->drive_lights, bb.x, bb.y,
			bb.width, bb.height / 2 - 5, uv_uitogglebutton_step);

	// work lights
	uv_uitogglebutton_init(&this->work_lights, csb_get_work_light(&dspl.network.csb),
			"Work Lights", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->work_lights, bb.x, bb.y + bb.height / 2 + 5,
			bb.width, bb.height / 2 - 5, uv_uitogglebutton_step);

	// wiper
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->wiper, 0, CSB_WIPER_SPEED_COUNT - 1,
			csb_get_wiper(&dspl.network.csb), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->wiper);
	uv_uiwindow_add(&this->window, &this->wiper, bb.x, bb.y, bb.width, 200, uv_uislider_step);

	uv_uilabel_init(&this->wiper_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "Wiper");
	uv_uiwindow_add(&this->window, &this->wiper_label,
			uv_uibb(&this->wiper)->x,
			uv_uibb(&this->wiper)->y + uv_uibb(&this->wiper)->height + 10,
			bb.width, UI_FONT_SMALL.char_height, uv_uilabel_step);

	// heater
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->heater, 0, MSB_HEATER_SPEED_COUNT - 1,
			msb_get_heater(&dspl.network.msb), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->heater);
	uv_uiwindow_add(&this->window, &this->heater, bb.x, bb.y, bb.width, 200, uv_uislider_step);

	uv_uilabel_init(&this->heater_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "Heater");
	uv_uiwindow_add(&this->window, &this->heater_label,
			uv_uibb(&this->heater)->x,
			uv_uibb(&this->heater)->y + uv_uibb(&this->heater)->height + 10,
			bb.width, UI_FONT_SMALL.char_height, uv_uilabel_step);

}



void settings_general_step(uint16_t step_ms) {
	// volume
	if (uv_uislider_value_changed(&this->volume)) {
		alert_set_volume(&dspl.alert, uv_uislider_get_value(&this->volume));
	}
	else {
		uv_uislider_set_value(&this->volume, alert_get_volume(&dspl.alert));
	}

	// brightness
	if (uv_uislider_value_changed(&this->brightness)) {
		gui_set_backlight(uv_uislider_get_value(&this->brightness));
	}
	else {
		uv_uislider_set_value(&this->brightness, gui_get_backlight());
	}

	// drive lights
	if (uv_uitogglebutton_clicked(&this->drive_lights)) {
		csb_set_drive_light(&dspl.network.csb, uv_uitogglebutton_get_state(&this->drive_lights));
	}
	else {
		uv_uitogglebutton_set_state(&this->drive_lights, csb_get_drive_light(&dspl.network.csb));
	}

	// work lights
	if (uv_uitogglebutton_clicked(&this->work_lights)) {
		csb_set_work_light(&dspl.network.csb, uv_uitogglebutton_get_state(&this->work_lights));
	}
	else {
		uv_uitogglebutton_set_state(&this->work_lights, csb_get_work_light(&dspl.network.csb));
	}
}




