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
#include "home_screen.h"

/// @file: Graphical user interface module. Takes care of everything showing on the LCD display

#define GUI_STEP_MS		20
/// @brief: P-factor for backlight control
#define BACKLIGHT_KP		0.1f
#define BACKLIGHT_KP_MAX	10000

/// @brief: Main display buffer length
#define DISPLAY_BUF_LEN			2


typedef struct {
	/// @brief: Backlight target brightness as a 16-bit value
	uint16_t backlight_trg;
	/// @brief: Backlight current brightness as a 16-bit value
	uint16_t backlight_curr;
	/// @brief: Display is the main object of the UI
	uv_uidisplay_st display;
	/// @brief: The window buffer mandatory for uv_uidisplay_st
	uv_uiobject_st *display_buffer[DISPLAY_BUF_LEN];

	/// @brief: Main window is used as a container for main content of the screen
	uv_uiwindow_st main_window;
	uv_uiobject_st *main_window_buffer[DISPLAY_BUF_LEN];

	home_screen_st home;

	taskbar_st taskbar;
} gui_st;



/// @brief: Initializes the GUI. All volatile data should be initialized here
void gui_init(void *me);

/// @brief: Reset's the GUI to factory settings, also non-volatile data saved
/// in flash memory should be set here.
void gui_reset(void *me);

/// @brief: Step function which should run in a separate thread
void gui_step(void *me);

/// @brief: Sets the target value for LCD backlight brightness
///
/// @param value: percent value from 0...100
void gui_set_backlight(void *me, uint8_t value);

#endif /* GUI_H_ */
