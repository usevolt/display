/*
 * home_screen.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */



#include "home_screen.h"


void home_init(home_screen_st *this, uv_window_st *window) {
	uv_window_init(&this->home, this->home_buffer, &uv_window_styles[WINDOW_STYLE_INDEX]);
	uv_window_add(window, &this->home, 0, 0, uv_ui_get_bb(window)->width, uv_ui_get_bb(window)->height,
			true, uv_window_step);

	uv_label_init(&this->test, &font_16X26, ALIGN_CENTER, 0xFF0000, "N" auml "kyyk" ouml "h" auml "n "
			auml auml "kk" ouml "set\nnyt oikein\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n"
			"Lazy dog jumped over a grey fox\n");
	uv_window_add(window, &this->test, 0, 0, uv_ui_get_bb(window)->width, uv_ui_get_bb(window)->height,
			true, uv_label_step);
}



void home_step(home_screen_st *this, uint32_t step_ms) {
	uv_window_step(&this->home, step_ms);
}
