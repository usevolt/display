/*
 * system_restore.c
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#include "system_restore.h"
#include "gui.h"
#include <uv_memory.h>
#include <uv_reset.h>


#define this (&gui.windows.system.windows.sys_restore)



void system_restore_show(void) {
	uv_uiwindow_clear(&gui.windows.system.tabs);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uitabwindow_add(&gui.windows.system.tabs, &this->window,
			uv_uibb(&gui.windows.system.tabs)->x, 0,
			uv_uibb(&gui.windows.system.tabs)->width,
			uv_uitabwindow_get_contentbb(&gui.windows.system.tabs).height);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height, 1, 3);
	uv_uigridlayout_set_padding(&grid, 20, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->info, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Press the button below for " STRINGIFY(RESTORE_DELAY_S)
			" seconds to\n" "restore the system to factory settings.\n"
			"The display will reboot after the restore.\n \n"
			"WARNING: ALL SETTINGS FROM ALL USERS WILL BE LOST");
	uv_uiwindow_add(&this->window, &this->info, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->timer, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "10");
	uv_ui_hide(&this->timer);
	uv_uiwindow_add(&this->window, &this->timer, bb.x, bb.y, bb.width, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->restore, "Restore system defaults", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->restore, bb.x + bb.width / 4, bb.y - bb.height / 2,
			bb.width / 2, bb.height * 1.5f);

	uv_delay_init(RESTORE_DELAY_S * 1000, &this->delay);
}

extern uv_errors_e __uv_clear_previous_non_volatile_data();


void system_restore_step(uint16_t step_ms) {
	if (uv_uibutton_is_down(&this->restore)) {
		if (uv_delay(step_ms, &this->delay)) {
			uv_memory_clear();
			uv_system_reset(false);
			return;
		}
		else {
			sprintf(this->timer_value, "%u", this->delay / 1000 + 1);
			uv_uilabel_set_text(&this->timer, this->timer_value);

			if (this->delay / 1000 < 5) {
				uv_uilabel_set_color(&this->timer, C(0xFF0000));
			}
		}
	}
	else {
		uv_uilabel_set_text(&this->timer, "");
		uv_uilabel_set_color(&this->timer, C(0xFFFFFF));
		uv_delay_init(RESTORE_DELAY_S * 1000, &this->delay);
	}

}

