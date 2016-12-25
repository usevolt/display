/*
 * dashboard_uw50.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#include "dashboard_uw50.h"
#include "gui.h"

#define this (&gui.windows.settings.general)



void dashboard_uw50_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.settings.tabs;
	uv_uiwindow_clear(window);



}

void dashboard_uw50_step(uint16_t step_ms) {

}
