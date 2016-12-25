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

#define this (&gui.windows.login)


#define BUTTON_H		100
#define BUTTON_W		200
#define BUTTON_SPACE	20


void login_show(void) {

	uv_uiwindow_clear(&gui.main_window);
	gui.step_callb = login_step;

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_ui_get_bb(&gui.main_window)->width, uv_ui_get_bb(&gui.main_window)->height, uv_uiwindow_step);

	uv_uilabel_init(&this->topic, & UI_FONT_BIG, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Select driver");
	uv_uiwindow_add(&this->window, &this->topic, uv_uibb(&this->window)->width / 2, 0, 0, 20, uv_uilabel_step);

	uv_uilist_init(&this->users, this->users_buffer, USER_COUNT, &uv_uistyles[0]);
	for (uint8_t i = 0; i < uv_vector_size(&dspl.users); i++) {
		uv_uilist_push_back(&this->users, ((userdata_st*) uv_vector_at(&dspl.users, i))->username);
	}
	uv_uilist_select(&this->users, usertoi(dspl.user));
	uint16_t height = uv_uibb(&this->users)->height;
	uv_uiwindow_add(&this->window, &this->users, LCD_W(0.1), uv_uibb(&this->window)->height / 2 - height / 2,
			LCD_W(0.5), height, uv_uilist_step);

	uv_uibutton_init(&this->login, "Log In", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->login,
			LCD_W(0.8) - BUTTON_W / 2,
			uv_ui_get_bb(&this->window)->height / 2 - BUTTON_H / 2 - BUTTON_H - BUTTON_SPACE,
			BUTTON_W, BUTTON_H, uv_uibutton_step);

	uv_uibutton_init(&this->add_user, "Add user",
			&uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->add_user,
			LCD_W(0.8) - BUTTON_W / 2,
			uv_uibb(&this->window)->height / 2 - BUTTON_H / 2,
			BUTTON_W, BUTTON_H, uv_uibutton_step);

	uv_uibutton_init(&this->delete_user, "Delete user",
			&uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->delete_user,
			LCD_W(0.8) - BUTTON_W / 2,
			uv_uibb(&this->window)->height / 2 + BUTTON_H / 2 + BUTTON_SPACE,
			BUTTON_W, BUTTON_H, uv_uibutton_step);

}




void login_step(uint16_t step_ms) {
	if (uv_uibutton_clicked(&this->login)) {
		users_set(uv_uilist_at(&this->users, uv_uilist_get_selected(&this->users)));

		// show home page
		home_show();
	}
	else if (uv_uibutton_clicked(&this->add_user)) {
		char str[USERNAME_MAX_LEN];
		if (uv_vector_size(&dspl.users) == uv_vector_max_size(&dspl.users)) {

		}
		if (uv_uikeyboard_show("Add user", str, USERNAME_MAX_LEN, &uv_uikeyboard_styles[0])) {
			users_add(str);
		}
	}
	else if (uv_uibutton_clicked(&this->delete_user)) {
		if (users_delete(uv_uilist_at(&this->users, uv_uilist_get_selected(&this->users)))) {
			uv_uilist_remove(&this->users, uv_uilist_get_selected(&this->users));
		}
	}


}
