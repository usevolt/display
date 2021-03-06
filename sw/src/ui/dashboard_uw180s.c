/*
 * dashboard_uw180s.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "dashboard_uw180s.h"
#include "gui.h"
#include "network.h"
#include "tr.h"


#define this (&gui.windows.dashboard.implements.dashboard_uw180s)


static char log_length_str[32];

void dashboard_uw180s_show() {
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
	strcpy(log_length_str, uv_str(STR_DASHBOARD_UW180S_LABELTARGETLENGTH));
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
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_DASHBOARD_UW180S_LABELLENGTH));
	uv_uiwindow_add(window, &this->len_label,
			bb.x + ((dspl.user->uw180s.width_enabled) ? 0 : (bb.width / 2)),
			bb.y, bb.width, UI_FONT_SMALL.char_height);

	uv_uidigit_init(&this->len, &UI_DIGIT_BIG, ALIGN_TOP_CENTER, C(0xFFFFFF),
			uv_uistyles[0].window_c, "%03i", icu_get_length_um(&dspl.network.icu) / 10000);
	uv_uidigit_set_scale(&this->len, 2.0f);
	uv_uiwindow_add(window, &this->len, bb.x + ((dspl.user->uw180s.width_enabled) ? 0 : (bb.width / 2)),
			bb.y + uv_uibb(&this->len_label)->height,
			bb.width, bb.height - uv_uibb(&this->len_label)->height);

	if (dspl.user->uw180s.width_enabled) {
		bb = uv_uigridlayout_next(&grid);
		uv_uilabel_init(&this->wid_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
				C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_DASHBOARD_UW180S_LABELDIAMETER));
		uv_uiwindow_add(window, &this->wid_label, bb.x, bb.y, bb.width,
				UI_FONT_SMALL.char_height);

		uv_uidigit_init(&this->wid, &UI_DIGIT_BIG, ALIGN_TOP_CENTER, C(0xFFFFFF),
				uv_uistyles[0].window_c, "%03i", icu_get_width_mm(&dspl.network.icu));
		uv_uidigit_set_scale(&this->wid, 2.0f);
		uv_uiwindow_add(window, &this->wid, bb.x, bb.y + uv_uibb(&this->wid_label)->height,
				bb.width, bb.height - uv_uibb(&this->wid_label)->height);

		if (dspl.user->uw180s.vol_enabled) {
			uv_uigridlayout_next(&grid);
			bb = uv_uigridlayout_next(&grid);
			uv_uilabel_init(&this->vol_label, &UI_FONT_SMALL, ALIGN_CENTER,
					C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_DASHBOARD_UW180S_LABELVOLUME));
			uv_uiwindow_add(window, &this->vol_label, bb.x - bb.width / 2, bb.y, bb.width,
					UI_FONT_SMALL.char_height);

			uv_uidigit_init(&this->vol, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
					uv_uistyles[0].window_c, "%i,%01u", icu_get_vol_dm3(&dspl.network.icu) / 1000);
			uv_uidigit_set_divider(&this->vol, 1000);
			uv_uiwindow_add(window, &this->vol, bb.x - bb.width / 2, bb.y + uv_uibb(&this->vol_label)->height,
					bb.width, bb.height - uv_uibb(&this->vol_label)->height);
		}
	}

	this->active_len = 1;
	this->last_len_change_req = 0;

	icu_set_target_len_um(&dspl.network.icu, dspl.user->uw180s.log_len1 * 10000);
}



uv_uiobject_ret_e dashboard_uw180s_step(uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	uv_uidigit_set_value(&this->len, icu_get_length_um(&dspl.network.icu) / 10000);
	if (dspl.user->uw180s.width_enabled) {
		uv_uidigit_set_value(&this->wid, icu_get_width_mm(&dspl.network.icu));
		if (dspl.user->uw180s.vol_enabled) {
			uv_uidigit_set_value(&this->vol, icu_get_vol_dm3(&dspl.network.icu));
		}
	}

	int8_t change_req = dspl.network.r_keypad.b[3];
	if (uv_uibutton_clicked(&this->log_length) ||
			(change_req && !this->last_len_change_req)) {
		if (this->active_len == 1) {
			this->active_len = 2;
			strcpy(log_length_str, uv_str(STR_DASHBOARD_UW180S_LABELTARGETLENGTH));
			char str[10];
			snprintf(str, 10, "%03i", dspl.user->uw180s.log_len2);
			strcat(log_length_str, str);
			strcat(log_length_str, " cm");
			icu_set_target_len_um(&dspl.network.icu, dspl.user->uw180s.log_len2 * 10000);
		}
		else {
			this->active_len = 1;
			strcpy(log_length_str, uv_str(STR_DASHBOARD_UW180S_LABELTARGETLENGTH));
			char str[10];
			snprintf(str, 10, "%03i", dspl.user->uw180s.log_len1);
			strcat(log_length_str, str);
			strcat(log_length_str, " cm");
			icu_set_target_len_um(&dspl.network.icu, dspl.user->uw180s.log_len1 * 10000);
		}
		uv_ui_refresh(&this->log_length);
	}

	this->last_len_change_req = change_req;
	return ret;
}
