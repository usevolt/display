/*
 * system_restore.h
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_RESTORE_H_
#define UI_SYSTEM_RESTORE_H_


#include <uv_utilities.h>
#include <uv_ui.h>

#define SYSTEM_RESTORE_BUFFER_LEN		3

#define RESTORE_DELAY_S				10

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_RESTORE_BUFFER_LEN];

	uv_uilabel_st info;
	uv_uilabel_st timer;
	uv_uibutton_st restore;

	char timer_value[3];

	int delay;

} system_restore_st;


void system_restore_show(void);

void system_restore_step(const uint16_t step_ms);


#endif /* UI_SYSTEM_RESTORE_H_ */
