/*
 * login.h
 *
 *  Created on: Oct 24, 2016
 *      Author: usevolt
 */

#ifndef UI_LOGIN_H_
#define UI_LOGIN_H_

#include <uv_utilities.h>
#include <uv_ui.h>
#include "main.h"

#define LOGIN_BUFFER_LEN	5

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[LOGIN_BUFFER_LEN];

	uv_uilabel_st topic;

	uv_uilist_st users;
	char *users_buffer[USER_COUNT];

	uv_uibutton_st login;
	uv_uibutton_st add_user;
	uv_uibutton_st delete_user;

} login_st;




void login_show(void);


uv_uiobject_ret_e login_step(const uint16_t step_ms);

#endif /* UI_LOGIN_H_ */
