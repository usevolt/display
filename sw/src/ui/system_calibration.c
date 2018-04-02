/*
 * system_settings.c
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */


#include "../../inc/ui/system_calibration.h"

#include "gui.h"


#define this	(&gui.windows.system.windows.sys_calib)


void system_calib_show(void) {
	uv_uiwindow_clear(&gui.windows.system.tabs);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_set_stepcallback(&this->window, &system_calib_step);
	uv_uitabwindow_add(&gui.windows.system.tabs, &this->window, 0, 0,
			uv_uibb(&gui.windows.system.tabs)->width,
			uv_uitabwindow_get_contentbb(&gui.windows.system.tabs).height);
	uv_uiwindow_set_contentbb(&this->window, uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height * 1.2);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uiwindow_get_contentbb(&this->window).width,
			uv_uiwindow_get_contentbb(&this->window).height, 2, 2);
	uv_uigridlayout_set_padding(&grid, 10, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// uw180s mb calibration
	uv_uilabel_init(&this->mb_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_SYSTEM_CALIB_LABELUW180SCAL));
	uv_uiwindow_add(&this->window, &this->mb_label,
			bb.x, bb.y, bb.width * 2, UI_FONT_SMALL.char_height);

	uv_uibutton_init(&this->mb_calib_min, uv_str(STR_SYSTEM_CALIB_BUTTONCALIBMIN), &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->mb_calib_min, bb.x + bb.width / 4, bb.y + UI_FONT_SMALL.char_height,
			bb.width / 2, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->mb_calib_max, uv_str(STR_SYSTEM_CALIB_BUTTONCALIBMAX), &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->mb_calib_max, bb.x + bb.width / 4,
			bb.y + UI_FONT_SMALL.char_height, bb.width / 2, bb.height / 2);

	// Joystick calibration
	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->calib_help, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_SYSTEM_CALIB_LABELINFO));
	uv_uiwindow_add(&this->window, &this->calib_help, bb.x, bb.y - UI_FONT_SMALL.char_height * 3,
			uv_uiwindow_get_contentbb(&this->window).width, 0);

	uv_uitogglebutton_init(&this->calib_start, false,
			uv_str(STR_SYSTEM_CALIB_BUTTONJOYSTICK), &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->calib_start,
			bb.x, bb.y + bb.height / 6, bb.width / 2, bb.height / 3);

	int16_t calib_x = bb.x + bb.width / 2 + 5;
	int16_t calib_w = bb.width * 1.5f;
	int16_t calib_values_w = 70;


	uv_uilabel_init(&this->calib_labels1, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_SYSTEM_CALIB_LABELAXES));
	uv_uiwindow_add(&this->window, &this->calib_labels1, calib_x, bb.y,
			calib_w / 3, bb.height);
	uv_uilabel_init(&this->calib_values1, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), uv_uistyles[0].window_c, this->calib_values1_str);
	uv_uiwindow_add(&this->window, &this->calib_values1,
			calib_x + calib_w / 3 - calib_values_w, bb.y + UI_FONT_SMALL.char_height,
			calib_values_w, bb.height - UI_FONT_SMALL.char_height * 3);
	snprintf(this->calib_values1_str, CALIB_LINE_LEN, "0\n0\n0\n \n \n0\n0\n0");

	uv_uilabel_init(&this->calib_labels2, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_SYSTEM_CALIB_LABELAXES));
	uv_uiwindow_add(&this->window, &this->calib_labels2, calib_x + calib_w / 3, bb.y,
			calib_w / 3, bb.height);
	uv_uilabel_init(&this->calib_values2, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), uv_uistyles[0].window_c, this->calib_values2_str);
	uv_uiwindow_add(&this->window, &this->calib_values2,
			calib_x + calib_w * 2 / 3 - calib_values_w, bb.y + UI_FONT_SMALL.char_height,
			calib_values_w, bb.height - UI_FONT_SMALL.char_height * 3);
	snprintf(this->calib_values2_str, CALIB_LINE_LEN, "0\n0\n0\n \n \n0\n0\n0");

	uv_uilabel_init(&this->calib_labels3, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_SYSTEM_CALIB_LABELAXES));
	uv_uiwindow_add(&this->window, &this->calib_labels3, calib_x + calib_w * 2 / 3,
			bb.y, calib_w / 3, bb.height);
	uv_uilabel_init(&this->calib_values3, &UI_FONT_SMALL, ALIGN_TOP_LEFT,
			C(0xFFFFFF), uv_uistyles[0].window_c, this->calib_values3_str);
	uv_uiwindow_add(&this->window, &this->calib_values3,
			calib_x + calib_w - calib_values_w, bb.y + UI_FONT_SMALL.char_height,
			calib_values_w, bb.height - UI_FONT_SMALL.char_height * 3);
	snprintf(this->calib_values3_str, CALIB_LINE_LEN, "0\n0\n0\n \n \n0\n0\n0");




}




uv_uiobject_ret_e system_calib_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (uv_uibutton_clicked(&this->mb_calib_min)) {
		uv_canopen_sdo_write8(UW180S_MB_NODE_ID, 0x2007, 2, 1);
	}
	else if (uv_uibutton_clicked(&this->mb_calib_max)) {
		uv_canopen_sdo_write8(UW180S_MB_NODE_ID, 0x2007, 3, 1);
	}

	if (uv_uitogglebutton_clicked(&this->calib_start)) {
		if (uv_uitogglebutton_get_state(&this->calib_start)) {
			keypad_calib_start(&dspl.network.l_keypad);
			keypad_calib_start(&dspl.network.r_keypad);
		}
		else {
			keypad_calib_end(&dspl.network.l_keypad);
			keypad_calib_end(&dspl.network.r_keypad);
		}
	}
	else if (uv_uitogglebutton_get_state(&this->calib_start)) {
		uint16_t *l_calib_data = keypad_get_x_calib(&dspl.network.l_keypad);
		uint16_t *r_calib_data = keypad_get_x_calib(&dspl.network.r_keypad);

		snprintf(this->calib_values1_str, CALIB_LINE_LEN, "%i\n%i\n%i\n \n \n%i\n%i\n%i",
				l_calib_data[0], l_calib_data[1], l_calib_data[2],
				r_calib_data[0], r_calib_data[1], r_calib_data[2]);
		uv_ui_refresh(&this->calib_values1);

		l_calib_data = keypad_get_y_calib(&dspl.network.l_keypad);
		r_calib_data = keypad_get_y_calib(&dspl.network.r_keypad);
		snprintf(this->calib_values2_str, CALIB_LINE_LEN, "%i\n%i\n%i\n \n \n%i\n%i\n%i",
				l_calib_data[0], l_calib_data[1], l_calib_data[2],
				r_calib_data[0], r_calib_data[1], r_calib_data[2]);
		uv_ui_refresh(&this->calib_values2);

		l_calib_data = keypad_get_z_calib(&dspl.network.l_keypad);
		r_calib_data = keypad_get_z_calib(&dspl.network.r_keypad);
		snprintf(this->calib_values3_str, CALIB_LINE_LEN, "%i\n%i\n%i\n \n \n%i\n%i\n%i",
				l_calib_data[0], l_calib_data[1], l_calib_data[2],
				r_calib_data[0], r_calib_data[1], r_calib_data[2]);
		uv_ui_refresh(&this->calib_values3);
	}
	else {

	}

	return ret;
}
