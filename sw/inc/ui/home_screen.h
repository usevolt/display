/*
 * home_screen.h
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */

#ifndef UI_HOME_SCREEN_H_
#define UI_HOME_SCREEN_H_


#include <uv_utilities.h>
#include <uv_ui.h>

/// @brief: Main display buffer length
#define HOME_BUF_LEN			2



typedef struct {
	uv_window_st home;
	/// @brief: The window buffer mandatory for uv_display_st
	uv_ui_object_st *home_buffer[HOME_BUF_LEN];

	uv_label_st test;

} home_screen_st;


void home_init(home_screen_st *this, uv_window_st *window);

void home_step(home_screen_st *this, uint32_t step_ms);

#endif /* UI_HOME_SCREEN_H_ */
