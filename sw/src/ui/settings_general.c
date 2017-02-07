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
	uv_uiwindow_clear(window);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_add(window, &this->window, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uibb(window)->width, uv_uibb(window)->height - CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uiwindow_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height, 5, 1);
	uv_uigridlayout_set_padding(&grid, 10, 40);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// brightness
	uv_uislider_init(&this->brightness, 1, 100, gui_get_backlight(), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->brightness);
	uv_uislider_set_title(&this->brightness, "Screen\nbrightness");
	uv_uiwindow_add(&this->window, &this->brightness,
			bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	// volume
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->volume, 0, 100, alert_get_volume(&dspl.alert), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->volume);
	uv_uislider_set_title(&this->volume, "Volume");
	uv_uiwindow_add(&this->window, &this->volume,
			bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

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
	uv_uislider_set_title(&this->wiper, "Wiper");
	uv_uiwindow_add(&this->window, &this->wiper, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	// heater
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->heater, 0, MSB_HEATER_SPEED_COUNT - 1,
			msb_get_power_heater(&dspl.network.msb), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->heater);
	uv_uislider_set_title(&this->heater, "Heater");
	uv_uiwindow_add(&this->window, &this->heater, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

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

	// wiper
	if (uv_uislider_value_changed(&this->wiper)) {
		csb_set_wiper(&dspl.network.csb, uv_uislider_get_value(&this->wiper));
	}
}




