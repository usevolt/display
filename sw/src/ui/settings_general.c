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


void general_show(void);
void general_step(const uint16_t step_ms);
void volume_show(void);
void volume_step(const uint16_t step_ms);

const uv_uitreeobject_st treeobjects[] = {
		{
				.name = "Driving",
				.window = &this->window,
				.show_callb = &general_show,
		},
		{
				.name = "Volume",
				.window = &this->window,
				.show_callb = &volume_show
		}
};



void settings_general_show(void) {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.settings.tabs;
	uv_uiwindow_clear(window);

	uv_uitreeview_init(&this->treeview, treeobjects,
			sizeof(treeobjects) / sizeof(uv_uitreeobject_st),
			&UI_FONT_BIG, &uv_uistyles[0]);
	uv_uitreeview_set_active(&this->treeview, 0);

	uv_uitabwindow_add(window, &this->treeview, 0, 0,
			uv_uibb(window)->width, uv_uitabwindow_get_contentbb(window).height);
}



void general_show(void) {

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_set_contentbb(&this->window, uv_uibb(&this->treeview)->width,
			uv_uibb(&this->treeview)->height);
	uv_uiwindow_set_step_callb(&this->window, &general_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uiwindow_get_contentbb(&this->window).width,
			uv_uiwindow_get_contentbb(&this->window).height, 5, 1);
	uv_uigridlayout_set_padding(&grid, 5,30);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);


	// brightness
	uv_uislider_init(&this->general.brightness, 1, 100,
			gui_get_backlight(), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->general.brightness);
	uv_uislider_set_title(&this->general.brightness, "Screen\nBrightness");
	uv_uislider_set_inc_step(&this->general.brightness, 10);
	uv_uiwindow_add(&this->window, &this->general.brightness,
			bb.x, bb.y, bb.width, bb.height);

	// drive lights
	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->general.drive_lights,
			csb_get_drive_light(&dspl.network.csb),
			"Drive Lights", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->general.drive_lights, bb.x, bb.y,
			bb.width, bb.height / 2 - 5);

	// work lights
	uv_uitogglebutton_init(&this->general.work_lights,
			csb_get_work_light(&dspl.network.csb),
			"Work Lights", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->general.work_lights,
			bb.x, bb.y + bb.height / 2 + 5,
			bb.width, bb.height / 2 - 5);

	// wiper
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->general.wiper, 0, CSB_WIPER_SPEED_COUNT - 1,
			csb_get_wiper(&dspl.network.csb), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->general.wiper);
	uv_uislider_set_title(&this->general.wiper, "Wiper");
	uv_uiwindow_add(&this->window, &this->general.wiper, bb.x, bb.y, bb.width, bb.height);

	// heater
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->general.heater, 0, MSB_HEATER_SPEED_COUNT - 1,
			msb_get_heater(&dspl.network.msb), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->general.heater);
	uv_uislider_set_title(&this->general.heater, "Heater");
	uv_uiwindow_add(&this->window, &this->general.heater, bb.x, bb.y, bb.width, bb.height);
}



void volume_show(void) {

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_set_step_callb(&this->window, &volume_step);
	uv_uiwindow_set_contentbb(&this->window, uv_uibb(&this->treeview)->width,
			uv_uibb(&this->treeview)->height);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uiwindow_get_contentbb(&this->window).width,
			uv_uiwindow_get_contentbb(&this->window).height, 5, 1);
	uv_uigridlayout_set_padding(&grid, 5,30);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);


	// volume
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->volume, 0, 100, alert_get_volume(&dspl.alert), &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->volume);
	uv_uislider_set_title(&this->volume, "Volume");
	uv_uislider_set_inc_step(&this->volume, 10);
	uv_uiwindow_add(&this->window, &this->volume,
			bb.x, bb.y, bb.width, bb.height);

}



void general_step(const uint16_t step_ms) {
	// brightness
	if (uv_uislider_value_changed(&this->general.brightness)) {
		gui_set_backlight(uv_uislider_get_value(&this->general.brightness));
	}
	else {
		uv_uislider_set_value(&this->general.brightness, gui_get_backlight());
	}

	// drive lights
	if (uv_uitogglebutton_clicked(&this->general.drive_lights)) {
		csb_set_drive_light(&dspl.network.csb,
				uv_uitogglebutton_get_state(&this->general.drive_lights));
	}
	else {
		uv_uitogglebutton_set_state(&this->general.drive_lights,
				csb_get_drive_light(&dspl.network.csb));
	}

	// work lights
	if (uv_uitogglebutton_clicked(&this->general.work_lights)) {
		csb_set_work_light(&dspl.network.csb,
				uv_uitogglebutton_get_state(&this->general.work_lights));
		msb_set_crane_light(&dspl.network.msb,
				uv_uitogglebutton_get_state(&this->general.work_lights));
	}
	else {
		uv_uitogglebutton_set_state(&this->general.work_lights,
				csb_get_work_light(&dspl.network.csb));
	}

	// wiper
	if (uv_uislider_value_changed(&this->general.wiper)) {
		csb_set_wiper(&dspl.network.csb,
				uv_uislider_get_value(&this->general.wiper));
	}

	// heater
	if (uv_uislider_value_changed(&this->general.heater)) {
		msb_set_heater(&dspl.network.msb,
				uv_uislider_get_value(&this->general.heater));
	}
}

void volume_step(const uint16_t step_ms) {
	// volume
	if (uv_uislider_value_changed(&this->volume)) {
		alert_set_volume(&dspl.alert, uv_uislider_get_value(&this->volume));
	}
	else {
		uv_uislider_set_value(&this->volume, alert_get_volume(&dspl.alert));
	}
}




