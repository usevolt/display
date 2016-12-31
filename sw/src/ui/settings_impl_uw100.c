/*
 * settings_uw100.c
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#include <settings_impl_uw100.h>
#include "gui.h"


#define this	(&gui.windows.settings.implements.uw100)



void settings_impl_uw100_show(void) {
	uv_uiwindow_st *window = &gui.windows.settings.implements.window;
	uv_uiwindow_clear(window);
}

void settings_impl_uw100_step(uint16_t step_ms) {

}
