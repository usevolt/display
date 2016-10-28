/*
 * login.c
 *
 *  Created on: Oct 24, 2016
 *      Author: usevolt
 */


#include "login.h"
#include "gui.h"
#include "log.h"
#include "users.h"

#define this (&gui.login)


static void login_callb(void *me, uibutton_state_e state);
static void adduser_callb(void *me, uibutton_state_e state);
static void deleteuser_callb(void *me, uibutton_state_e state);

#define BUTTON_H		75
#define BUTTON_SPACE	20


void login_show(void) {
	uv_rtos_mutex_lock(&gui_mutex);

	uv_uiwindow_clear(&gui.main_window);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uiwindow_styles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_ui_get_bb(&gui.main_window)->width, uv_ui_get_bb(&gui.main_window)->height, uv_uiwindow_step);

	uv_uilabel_init(&this->topic, & UI_FONT_BIG, ALIGN_TOP_CENTER,
			C(0xFFFFFF), uv_uiwindow_styles[WINDOW_STYLE_INDEX].main_color, "Select driver");
	uv_uiwindow_add(&this->window, &this->topic, uv_uibb(&this->window)->width / 2, 0, 0, 20, uv_uilabel_step);

	uv_uilist_init(&this->users, this->users_buffer, USER_COUNT, &uv_uilist_styles[0]);
	for (uint8_t i = 0; i < uv_vector_size(&dspl.users); i++) {
		uv_uilist_push_back(&this->users, ((userdata_st*) uv_vector_at(&dspl.users, i))->username);
	}
	uv_uilist_select(&this->users, usertoi(dspl.user));
	uint16_t height = uv_uibb(&this->users)->height;
	uv_uiwindow_add(&this->window, &this->users, LCD_W(0.1), uv_uibb(&this->window)->height / 2 - height / 2,
			LCD_W(0.5), height, uv_uilist_step);

	uv_uibutton_init(&this->login, "Log In", &uv_uibutton_styles[DEFAULT_BUTTON_STYLE_INDEX], login_callb);
	uv_uiwindow_add(&this->window, &this->login,
			LCD_W(0.75), uv_ui_get_bb(&this->window)->height / 2 - BUTTON_H / 2 - BUTTON_H - BUTTON_SPACE,
			150, BUTTON_H, uv_uibutton_step);

	uv_uibutton_init(&this->add_user, "Add user",
			&uv_uibutton_styles[DEFAULT_BUTTON_STYLE_INDEX], adduser_callb);
	uv_uiwindow_add(&this->window, &this->add_user,
			LCD_W(0.75), uv_uibb(&this->window)->height / 2 - BUTTON_H / 2,
			150, BUTTON_H, uv_uibutton_step);

	uv_uibutton_init(&this->delete_user, "Delete user",
			&uv_uibutton_styles[DEFAULT_BUTTON_STYLE_INDEX], deleteuser_callb);
	uv_uiwindow_add(&this->window, &this->delete_user,
			LCD_W(0.75), uv_uibb(&this->window)->height / 2 + BUTTON_H / 2 + BUTTON_SPACE,
			150, BUTTON_H, uv_uibutton_step);

	uv_rtos_mutex_unlock(&gui_mutex);
}



static void login_callb(void *me, uibutton_state_e state) {
	// if the user was changed, save it to the flash memory
	if (usertoi(dspl.user) != uv_uilist_get_selected(&this->users)) {
		dspl.user = (userdata_st*) uv_vector_at(&dspl.users, uv_uilist_get_selected(&this->users));
		uv_memory_save(&dspl.data_start, &dspl.data_endl);
	}
	// add driver selection to log
	log_add(LOG_DRIVER_SET, usertoi(dspl.user));

	// show home page
	home_show();
}

static void adduser_callb(void *me, uibutton_state_e state) {
	char str[USERNAME_MAX_LEN];
	if (uv_vector_size(&dspl.users) == uv_vector_max_size(&dspl.users)) {

	}
	if (uv_uikeyboard_show("Add user", str, USERNAME_MAX_LEN, &uv_uikeyboard_styles[0])) {
		users_add(str);
	}
}

static void deleteuser_callb(void *me, uibutton_state_e state) {

}
