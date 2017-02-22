/*
 * dashboard_uw100.c
 *
 *  Created on: Feb 21, 2017
 *      Author: usevolt
 */



#include "dashboard_uw100.h"
#include "gui.h"

#define this (&gui.windows.settings.implements.uw100)



void dashboard_uw100_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.dashboard.impl_window;
	uv_uiwindow_clear(window);



}

void dashboard_uw100_step(uint16_t step_ms) {

}
