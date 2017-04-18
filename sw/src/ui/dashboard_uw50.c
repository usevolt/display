/*
 * dashboard_uw50.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#include "dashboard_uw50.h"
#include "gui.h"

#define this (&gui.windows.settings.implements.uw50)



void dashboard_uw50_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.dashboard.impl_window;
	uv_uiwindow_clear(window);



}

uv_uiobject_ret_e dashboard_uw50_step(uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;


	return ret;
}
