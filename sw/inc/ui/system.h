/*
 * system.h
 *
 *  Created on: Oct 28, 2016
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_H_
#define UI_SYSTEM_H_

#include <uv_utilities.h>
#include <uv_ui.h>


#define SYSTEM_BUFFER_LEN	4
#define ABOUT_STR_LEN		70

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_BUFFER_LEN];

	uv_uibutton_st cancel;
	uv_uibutton_st ok;

	uv_uilabel_st topic;
	uv_uilabel_st about;
	char about_str[ABOUT_STR_LEN];

} system_st;


void system_show();

void system_step(uint16_t step_ms);

#endif /* UI_SYSTEM_H_ */
