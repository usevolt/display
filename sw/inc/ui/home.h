/*
 * home.h
 *
 *  Created on: Oct 24, 2016
 *      Author: usevolt
 */

#ifndef UI_HOME_H_
#define UI_HOME_H_


#include <uv_utilities.h>
#include <uv_ui.h>
#include "uv_hal_config.h"
#include "main.h"

#define HOME_BUFFER_LEN	4

/// @brief: home screen
typedef struct {

	uv_uiwindow_st window;
	uv_uiobject_st *buffer[HOME_BUFFER_LEN];

	uv_uibutton_st dashboard;
	uv_uibutton_st settings;
	uv_uibutton_st system;
	uv_uibutton_st logout;

} home_st;


/// @brief: Shows the home window
void home_show(void);

uv_uiobject_ret_e home_step(const uint16_t step_ms);


#endif /* UI_HOME_H_ */
