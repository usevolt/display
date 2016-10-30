/*
 * gui.h
 *
 *  Created on: Sep 23, 2016
 *      Author: usevolt
 */

#ifndef GUI_H_
#define GUI_H_


#include <uv_utilities.h>
#include <uv_terminal.h>
#include <uv_ui.h>
#include "taskbar.h"
#include "home.h"
#include "login.h"
#include "system.h"
#include "settings.h"

/// @file: Graphical user interface module. Takes care of everything showing on the LCD display

#define GUI_STEP_MS		20
/// @brief: P-factor for backlight control
#define BACKLIGHT_KP		0.1f
#define BACKLIGHT_KP_MAX	10000

/// @brief: Main display buffer length
#define DISPLAY_BUF_LEN			2


/// @brief: Height of the topic-section. Not mandatory for all windows...
#define TOPIC_HEIGHT		50

#define TOPIC_INIT(parent_ptr, this_ptr, text) \
	uv_uilabel_init(this_ptr, &UI_FONT_BIG, ALIGN_CENTER, \
		C(0xFFFFFF), C(0xFFFFFFFF), text); \
	uv_uiwindow_add(parent_ptr, this_ptr, \
			uv_uibb(parent_ptr)->width / 2, 0, 0, TOPIC_HEIGHT, uv_uilabel_step)


/// @brief: Initializes the cancel button. Macro for quick and same kind
/// initialization for all windows
#define CANCEL_INIT(parent_ptr, this_ptr, callb)		\
	uv_uibutton_init((this_ptr), "Cancel", &uv_uistyles[CANCEL_OK_BUTTON_STYLE_INDEX], callb); \
	uv_uiwindow_add((parent_ptr), (this_ptr), 0, 0, 200, TOPIC_HEIGHT, uv_uibutton_step)

/// @brief: Initializes the OK button. Macro for quick and same kind
/// initialization for all windows
#define OK_INIT(parent_ptr, this_ptr, callb)		\
	uv_uibutton_init((this_ptr), "OK", &uv_uistyles[CANCEL_OK_BUTTON_STYLE_INDEX], callb); \
	uv_uiwindow_add((parent_ptr), (this_ptr), \
	uv_uibb(parent_ptr)->width - 200, 0, \
	200, TOPIC_HEIGHT, uv_uibutton_step)





/// @brief: Singleton structure representing the graphical user interface
typedef struct {
	/// @brief: Backlight target brightness as a 16-bit value
	uint16_t backlight_trg;
	/// @brief: Backlight current brightness as a 16-bit value
	uint16_t backlight_curr;
	/// @brief: Display is the main object of the UI
	uv_uidisplay_st display;
	/// @brief: The window buffer mandatory for uv_uidisplay_st
	uv_uiobject_st *display_buffer[DISPLAY_BUF_LEN];

	uv_uiwindow_st main_window;
	uv_uiobject_st *main_buffer[1];

	/// @brief: Window step function. The windows below can register
	/// their own step functions here which will get called every step cycle
	void (*step_callb)(uint16_t step_ms);

	/// @brief: Union which holds all the other windows
	union {
		// todo: Add new windows here...
		home_st home;
		login_st login;
		system_st system;
		settings_st settings;
	} windows;


	taskbar_st taskbar;
} gui_st;
extern gui_st gui;


/// @brief: Initializes the GUI. All volatile data should be initialized
void gui_init();

/// @brief: Step function which should run in a separate thread
void gui_step(void *);

/// @brief: Sets the target value for LCD backlight brightness
///
/// @param value: percent value from 0...100
void gui_set_backlight(uint8_t value);

/// @brief: Returns the current backlight
int16_t gui_get_backlight();

#endif /* GUI_H_ */
