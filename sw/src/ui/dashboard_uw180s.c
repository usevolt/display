/*
 * dashboard_uw180s.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "dashboard_uw180s.h"
#include "gui.h"


#define this (&gui.windows.settings.general)



void dashboard_uw180s_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.settings.tabs;
	uv_uiwindow_clear(window);



}

void dashboard_uw180s_step(uint16_t step_ms) {

}
