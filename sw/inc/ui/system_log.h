/*
 * system_log.h
 *
 *  Created on: Jan 18, 2017
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_LOG_H_
#define UI_SYSTEM_LOG_H_

#include <uv_utilities.h>
#include <uv_ui.h>


#define SYSTEM_LOG_BUFFER_LEN			10
#define SYSTEM_LOG_ENTRIES_PER_PAGE		5


typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_LOG_BUFFER_LEN];

	char *entry_strs[SYSTEM_LOG_ENTRIES_PER_PAGE];
	uv_uilist_st entry_list;

	char page_str[16];
	uv_uilabel_st page_label;

	uv_uibutton_st ack;
	uv_uibutton_st next_page;
	uv_uibutton_st prev_page;

	uint8_t page;


} system_log_st;


void system_log_show(void);

void system_log_step(uint16_t step_ms);


#endif /* UI_SYSTEM_LOG_H_ */
