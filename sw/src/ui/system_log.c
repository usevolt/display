/*
 * system_log.c
 *
 *  Created on: Jan 18, 2017
 *      Author: usevolt
 */


#include "system_log.h"
#include "gui.h"

#define this (&gui.windows.system.windows.sys_log)


static void show_page(int8_t page);

static int8_t page_count() {
	uint16_t nack_count = log_get_nack_count();
	int16_t page_count = nack_count / SYSTEM_LOG_ENTRIES_PER_PAGE + (nack_count % 5 != 0);
	if (!page_count) { page_count++; }
	return page_count;
}

void system_log_show(void) {
	uv_uiwindow_clear(&gui.windows.system.tabs);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_add(&gui.windows.system.tabs, &this->window, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uibb(&gui.windows.system.tabs)->width,
			uv_uibb(&gui.windows.system.tabs)->height - CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uiwindow_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height, 2, 4);
	uv_uigridlayout_set_padding(&grid, 20, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	for (int i = 0; i < SYSTEM_LOG_ENTRIES_PER_PAGE; i++) {
		this->entry_strs[i] = "";
	}

	this->page = 0;

	uv_uilist_init(&this->entry_list, this->entry_strs, SYSTEM_LOG_ENTRIES_PER_PAGE, &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->entry_list, bb.x, bb.y,
			bb.width, uv_uibb(&this->window)->height - bb.y, uv_uilist_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->info_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "\x11\x16 Select a log entry to acknowledge");
	uv_uiwindow_add(&this->window, &this->info_label, bb.x, bb.y, bb.width, bb.height, uv_uilabel_step);
	uv_ui_set_enabled(&this->info_label, false);

	bb = uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->ack, "Acknowledge", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->ack, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);
	strcpy(this->page_str, "");
	uv_uilabel_init(&this->page_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF), uv_uistyles[0].window_c,
			this->page_str);
	uv_uiwindow_add(&this->window, &this->page_label, bb.x, bb.y, bb.width, bb.height, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->prev_page, "Previous page", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->prev_page, bb.x, bb.y, bb.width / 2 - 5, bb.height, uv_uibutton_step);

	uv_uibutton_init(&this->next_page, "Next page", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->next_page, bb.x + bb.width / 2 + 5,
			bb.y, bb.width / 2 - 5, bb.height, uv_uibutton_step);

	show_page(this->page);
}


static void show_page(int8_t page) {
	if (page >= page_count() || page < 0) {
		return;
	}
	this->page = page;
	snprintf(this->page_str, SYSTEM_LOG_PAGE_STR_LEN,
			"page %u/%u", this->page + 1, page_count());
	this->page_str[15] = '\0';
	uv_uilabel_set_text(&this->page_label, this->page_str);

	uv_uilist_clear(&this->entry_list);
	for (int i = this->page * SYSTEM_LOG_ENTRIES_PER_PAGE;
			(i < log_get_nack_count()) &&
					(i < this->page * SYSTEM_LOG_ENTRIES_PER_PAGE + SYSTEM_LOG_ENTRIES_PER_PAGE); i++) {
		uv_uilist_push_back(&this->entry_list, (char*) log_get_nack_def(i)->def);
	}

}

void system_log_step(uint16_t step_ms) {

	if (uv_uibutton_clicked(&this->ack)) {
		uv_ui_set_enabled(&this->info_label, uv_uilist_get_selected(&this->entry_list) == -1);

		int16_t i = uv_uilist_get_selected(&this->entry_list);
		if (i > -1) {
			log_ack(this->page * SYSTEM_LOG_ENTRIES_PER_PAGE + i);
			show_page(this->page);
		}
	}
	else if (uv_uibutton_clicked(&this->next_page)) {
		show_page(this->page + 1);
	}
	else if (uv_uibutton_clicked(&this->prev_page)) {
		show_page(this->page - 1);
	}

}

