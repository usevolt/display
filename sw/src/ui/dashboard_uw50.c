/*
 * dashboard_uw50.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#include "dashboard_uw50.h"
#include "gui.h"

#define this (&gui.windows.dashboard.implements.dashboard_uw50)

static char log_length_str[32];


void dashboard_uw50_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st *) &gui.windows.dashboard.impl_window;
	uv_uiwindow_clear(window);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(window)->width, uv_uibb(window)->height, 2, 3);
	uv_uigridlayout_set_padding(&grid, 10, 10);
	uv_uigridlayout_next(&grid);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

//	uv_uilabel_init(&this->tree_type, &UI_FONT_BIG, ALIGN_TOP_CENTER,
//			C(0xFFFFFF), uv_uistyles[0].window_c, "");
//	uv_uiwindow_add(window, &this->tree_type, bb.x - bb.width / 2, bb.y + bb.height / 2,
//			bb.width, UI_FONT_BIG.char_height, uv_uilabel_step);
	strcpy(log_length_str, "Log length: ");
	char str[10];
	snprintf(str, 10, "%03i", dspl.user->uw180s.log_len1);
	strcat(log_length_str, str);
	strcat(log_length_str, " cm");
	uv_uibutton_init(&this->log_length, log_length_str, &uv_uistyles[0]);
	uv_uiwindow_add(window, &this->log_length, bb.x - bb.width / 2, bb.y,
						bb.width, bb.height * 0.8);

	uv_uilabel_init(&this->log_type, &UI_FONT_BIG, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "");
	uv_uiwindow_add(window, &this->log_type, bb.x - bb.width / 2,
			uv_uibb(&this->tree_type)->y + uv_uibb(&this->tree_type)->height + 5,
			bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->len_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Length (cm)");
	uv_uiwindow_add(window, &this->len_label, bb.x, bb.y, bb.width,
			UI_FONT_SMALL.char_height);

	uv_uidigit_init(&this->len, &UI_DIGIT_BIG, ALIGN_TOP_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "%03i", mb_get_length(&dspl.network.uw180s_mb) / 10);
	uv_uidigit_set_scale(&this->len, 2.0f);
	uv_uiwindow_add(window, &this->len, bb.x, bb.y + uv_uibb(&this->len_label)->height,
			bb.width, bb.height - uv_uibb(&this->len_label)->height);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->wid_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Diameter (mm)");
	uv_uiwindow_add(window, &this->wid_label, bb.x, bb.y, bb.width,
			UI_FONT_SMALL.char_height);

	uv_uidigit_init(&this->wid, &UI_DIGIT_BIG, ALIGN_TOP_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "%03i", 0);
	uv_uidigit_set_scale(&this->wid, 2.0f);
	uv_uiwindow_add(window, &this->wid, bb.x, bb.y + uv_uibb(&this->wid_label)->height,
			bb.width, bb.height - uv_uibb(&this->wid_label)->height);

	uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->vol_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Volume (m3)");
	uv_uiwindow_add(window, &this->vol_label, bb.x - bb.width / 2, bb.y, bb.width,
			UI_FONT_SMALL.char_height);

	uv_uidigit_init(&this->vol, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "%i,%01u", 0);
	uv_uidigit_set_divider(&this->vol, 1000);
	uv_uiwindow_add(window, &this->vol, bb.x - bb.width / 2, bb.y + uv_uibb(&this->vol_label)->height,
			bb.width, bb.height - uv_uibb(&this->vol_label)->height);

	strcpy(this->saw_str, "Saw: ?");
	uv_uilabel_init(&this->saw_pos, &UI_FONT_SMALL, ALIGN_BOTTOM_RIGHT, C(0xFFFFFF),
			C(0x000000), this->saw_str);
	uv_uiwindow_add(window, &this->saw_pos,
			bb.x + bb.width / 2, bb.y + bb.height / 2, bb.width / 2, bb.height / 2);

	this->active_len = 1;

	int32_t len = (int32_t) dspl.user->uw180s.log_len1 * 10000;
	uv_canopen_sdo_write(0xA, 0x2102, 0, CANOPEN_UNSIGNED32, &len);



}

uv_uiobject_ret_e dashboard_uw50_step(uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	int32_t len;
	uv_canopen_sdo_read_sync(0xA, 0x2105, 0, CANOPEN_SIGNED32, &len, 100);
	uv_uidigit_set_value(&this->len, len / 10000);
	uv_uidigit_set_value(&this->wid, 0);

	uint8_t saw_pos = 0;
	static uint8_t saw_last_pos = 0;
	static uint8_t saw_pos_unknown = 1;
	uv_canopen_sdo_read_sync(0xA, 0x2120, 0, CANOPEN_UNSIGNED8, &saw_pos, 100);
	uv_canopen_sdo_read_sync(0xA, 0x2121, 0, CANOPEN_UNSIGNED8, &saw_pos_unknown, 100);

	if (!saw_pos_unknown) {
		sprintf(this->saw_str, "Saw: %u %%", saw_pos);
		if (saw_pos != saw_last_pos) {
			uv_ui_refresh(&this->saw_pos);
		}
	}
	if (saw_pos_unknown) {
		saw_last_pos = 255;
	}
	else {
		saw_last_pos = saw_pos;
	}

	if (uv_uibutton_clicked(&this->log_length)) {
		if (this->active_len == 1) {
			this->active_len = 2;
			strcpy(log_length_str, "Log length: ");
			char str[10];
			snprintf(str, 10, "%03i", dspl.user->uw180s.log_len2);
			strcat(log_length_str, str);
			strcat(log_length_str, " cm");
			int32_t len = (int32_t) dspl.user->uw180s.log_len2 * 10000;
			uv_canopen_sdo_write(0xA, 0x2102, 0, CANOPEN_UNSIGNED32, &len);
		}
		else {
			this->active_len = 1;
			strcpy(log_length_str, "Log length: ");
			char str[10];
			snprintf(str, 10, "%03i", dspl.user->uw180s.log_len1);
			strcat(log_length_str, str);
			strcat(log_length_str, " cm");
			int32_t len = (int32_t) dspl.user->uw180s.log_len1 * 10000;
			uv_canopen_sdo_write(0xA, 0x2102, 0, CANOPEN_UNSIGNED32, &len);
		}
	}

	return ret;
}
