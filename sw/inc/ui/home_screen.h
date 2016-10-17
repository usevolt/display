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
	uv_uiwindow_st home;
	/// @brief: The window buffer mandatory for uv_uidisplay_st
	uv_uiobject_st *home_buffer[HOME_BUF_LEN];

	uv_uilabel_st test;

} home_screen_st;


void home_init(home_screen_st *this, uv_uiwindow_st *window);


#endif /* UI_HOME_SCREEN_H_ */
