/*
 * dashboard_uw180s.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "dashboard_uw180s.h"
#include "gui.h"
#include "network.h"


#define this (&gui.windows.dashboard.implements.dashboard_uw180s)



void dashboard_uw180s_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.dashboard.impl_window;
	uv_uiwindow_clear(window);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(window)->width, uv_uibb(window)->height, 2, 3);
	uv_uigridlayout_set_padding(&grid, 10, 10);
	uv_uigridlayout_next(&grid);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->tree_type, &UI_FONT_BIG, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "");
	uv_uiwindow_add(window, &this->tree_type, bb.x - bb.width / 2, bb.y + bb.height / 2,
			bb.width, UI_FONT_BIG.char_height, uv_uilabel_step);

	uv_uilabel_init(&this->log_type, &UI_FONT_BIG, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "");
	uv_uiwindow_add(window, &this->log_type, bb.x - bb.width / 2,
			uv_uibb(&this->tree_type)->y + uv_uibb(&this->tree_type)->height + 5,
			bb.width, bb.height, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->len_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Length (cm)");
	uv_uiwindow_add(window, &this->len_label, bb.x, bb.y, bb.width,
			UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uidigit_init(&this->len, &UI_DIGIT_BIG, ALIGN_TOP_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "%03i", 0);
	uv_uidigit_set_scale(&this->len, 2.0f);
	uv_uiwindow_add(window, &this->len, bb.x, bb.y + uv_uibb(&this->len_label)->height,
			bb.width, bb.height - uv_uibb(&this->len_label)->height, uv_uidigit_step);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->wid_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Diameter (cm)");
	uv_uiwindow_add(window, &this->wid_label, bb.x, bb.y, bb.width,
			UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uidigit_init(&this->wid, &UI_DIGIT_BIG, ALIGN_TOP_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "%03i", 0);
	uv_uidigit_set_scale(&this->wid, 2.0f);
	uv_uiwindow_add(window, &this->wid, bb.x, bb.y + uv_uibb(&this->wid_label)->height,
			bb.width, bb.height - uv_uibb(&this->wid_label)->height, uv_uidigit_step);

	uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->vol_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Volume (m3)");
	uv_uiwindow_add(window, &this->vol_label, bb.x - bb.width / 2, bb.y, bb.width,
			UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uidigit_init(&this->vol, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "%i,%01u", 0);
	uv_uidigit_set_divider(&this->vol, 1000);
	uv_uiwindow_add(window, &this->vol, bb.x - bb.width / 2, bb.y + uv_uibb(&this->vol_label)->height,
			bb.width, bb.height - uv_uibb(&this->vol_label)->height, uv_uilabel_step);

}



void dashboard_uw180s_step(uint16_t step_ms) {

}
