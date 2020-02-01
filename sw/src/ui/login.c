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
#include "tr.h"



#define this (&gui.windows.login)


#define BUTTON_H		75
#define BUTTON_W		200
#define BUTTON_SPACE	20


void login_show(void) {

	uv_uiwindow_clear(&gui.main_window);
	uv_uiwindow_set_stepcallback(&gui.main_window, &login_step);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_ui_get_bb(&gui.main_window)->width, uv_ui_get_bb(&gui.main_window)->height);

	uv_uilabel_init(&this->topic, & UI_FONT_BIG, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_LOGIN_LABELSELECTDRIVER));
	uv_uiwindow_add(&this->window, &this->topic, uv_uibb(&this->window)->width / 2, 0, 0, 20);

	uv_uilist_init(&this->users, this->users_buffer, USER_COUNT, &uv_uistyles[0]);
	for (uint8_t i = 0; i < uv_vector_size(&dspl.users); i++) {
		uv_uilist_push_back(&this->users, ((userdata_st*) uv_vector_at(&dspl.users, i))->username);
	}
	uv_uilist_select(&this->users, usertoi(dspl.user));
	uint16_t height = uv_uibb(&this->users)->height;
	uv_uiwindow_add(&this->window, &this->users, 0, uv_uibb(&this->window)->height / 2 - height / 2,
			uv_uibb(&this->window)->width / 2, height);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, uv_uibb(&this->window)->width - BUTTON_W, 0,
			BUTTON_W, uv_uibb(&this->window)->height, 1, 4);
	uv_uigridlayout_set_padding(&grid, 0, 5);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->login, uv_str(STR_LOGIN_BUTLOGIN), &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->login, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->add_user, uv_str(STR_LOGIN_BUTADDUSER),
			&uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->add_user,
			bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->copy_user, uv_str(STR_LOGIN_BUTCOPYUSER),
			&uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->copy_user,
			bb.x, bb.y, bb.width, bb.height);


	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->delete_user, uv_str(STR_LOGIN_BUTDELETEUSER),
			&uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->delete_user,
			bb.x, bb.y, bb.width, bb.height);

}




uv_uiobject_ret_e login_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (uv_uibutton_clicked(&this->login)) {
		users_set(uv_uilist_at(&this->users, uv_uilist_get_selected(&this->users)));
		// save changed user parameters to all devices
		network_save_params(&dspl.network);

		// show home page
		home_show();
		ret = UIOBJECT_RETURN_KILLED;
	}
	else if (uv_uibutton_clicked(&this->add_user)) {
		char str[USERNAME_MAX_LEN];
		strcpy(str, "");
		if (uv_vector_size(&dspl.users) < uv_vector_max_size(&dspl.users)) {
			if (uv_uikeyboard_show(uv_str(STR_LOGIN_BUTADDUSER), str, USERNAME_MAX_LEN, &uv_uistyles[0])) {
				users_add(str);
				uv_ui_refresh(&gui.display);
				login_show();
				ret = UIOBJECT_RETURN_KILLED;
			}
			else {
				uv_ui_refresh(&gui.display);
			}
		}
	}
	else if (uv_uibutton_clicked(&this->copy_user)) {
		char str[USERNAME_MAX_LEN] = {};
		if (uv_vector_size(&dspl.users) < uv_vector_max_size(&dspl.users)) {
			if (uv_uikeyboard_show(uv_str(STR_LOGIN_BUTADDUSER), str, USERNAME_MAX_LEN, &uv_uistyles[0])) {
				users_copy(uv_uilist_get_selected(&this->users), str);
				uv_ui_refresh(&gui.display);
				login_show();
				ret = UIOBJECT_RETURN_KILLED;
			}
			else {
				uv_ui_refresh(&gui.display);
			}
		}

	}
	else if (uv_uibutton_clicked(&this->delete_user)) {
		if (users_delete(uv_uilist_at(&this->users, uv_uilist_get_selected(&this->users)))) {
			uv_uilist_pop_back(&this->users, NULL);
		}
	}
	else {

	}

	return ret;


}
