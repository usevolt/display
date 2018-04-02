/*
 * settings_implements.c
 *
 *  Created on: Nov 3, 2016
 *      Author: usevolt
 */


#include "settings_implements.h"
#include "gui.h"
#include "vehicle.h"
#include "log.h"
#include "tr.h"


#define this (&gui.windows.settings.implements)


#define BW	200
#define BY 	80


void settings_implements_show(void) {
	uv_uiwindow_st *window = (uv_uiwindow_st*) &gui.windows.settings.tabs;
	uv_uiwindow_clear(window);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_set_stepcallback(&this->window, &settings_implements_step);
	uv_uitabwindow_add(window, &this->window, 0, 0,
			uv_uibb(window)->width,
			uv_uitabwindow_get_contentbb(window).height);

	if (dspl.user->implement) {
		dspl.user->implement->callbacks->settings_show();
	}
	else {
		uv_uilabel_init(&this->info, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
				C(0xFFFFFFFF), uv_str(STR_SETTINGS_IMPL_LABELNOTSELECTED));
		uv_uiwindow_add(&this->window, &this->info, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
				uv_uibb(&this->window)->width, uv_uibb(&this->window)->height);

		uv_uibutton_init(&this->goto_settings, uv_str(STR_SETTINGS_IMPL_BUTTONGOTOSETTINGS), &uv_uistyles[0]);
		uv_uiwindow_add(&this->window, &this->goto_settings,
				uv_uibb(&this->window)->width / 2 - BW / 2,
				uv_uibb(&this->window)->height / 2 + CONFIG_UI_TABWINDOW_HEADER_HEIGHT - BY / 2, BW, BY);
	}
}


uv_uiobject_ret_e settings_implements_step(uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	// if active implement settings dialog is visible, call it's step function.
	// otherwise continue with this module's step function.
	if (dspl.user->implement) {
		ret = dspl.user->implement->callbacks->settings_step(step_ms);
	}
	return ret;
}

