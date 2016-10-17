/*
 * home_screen.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */



#include "home_screen.h"


void home_init(home_screen_st *this, uv_uiwindow_st *window) {
	uv_uiwindow_init(&this->home, this->home_buffer, &uv_uiwindow_styles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(window, &this->home, 0, 0, uv_ui_get_bb(window)->width, uv_ui_get_bb(window)->height,
			true, uv_uiwindow_step);

	uv_uilabel_init(&this->test, &font_16X26, ALIGN_CENTER, 0xFF0000, "N" auml "kyyk" ouml "h" auml "n "
			auml auml "kk" ouml "set\nnyt oikein\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n");
	uv_uiwindow_add(window, &this->test, 0, 0, uv_ui_get_bb(window)->width, uv_ui_get_bb(window)->height,
			true, uv_uilabel_step);
}



