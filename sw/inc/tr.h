/* 
 * This file is part of the uv_hal distribution (www.usevolt.fi).
 * Copyright (c) 2017 Usevolt Oy.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef TR_H_
#define TR_H_

#include <uv_utilities.h>


/// @file: Defines UI translations for all supported languages

/// @brief: Defines how many languages are available
#define LANG_COUNT	2



/// @brief: Structure for a multi language string. Contains pointers to
/// all languages available.
typedef char* langstr_st[LANG_COUNT];



/// @brief: Enumerations of all available languages
typedef enum {
	LANG_EN = 0,
	LANG_FI
} languages_e;


/// @brief: Indexes to all languages in the software
enum {
	STR_HOME_BUTDASHBOARD = 0,
	STR_HOME_BUTSETTINGS,
	STR_HOME_BUTSYSTEM,
	STR_HOME_BUTLOGOUT,
	STR_LOGIN_LABELSELECTDRIVER,
	STR_LOGIN_BUTLOGIN,
	STR_LOGIN_BUTADDUSER,
	STR_LOGIN_BUTDELETEUSER,
	STR_DASHBOARD_UW180S_LABELTARGETLENGTH,
	STR_DASHBOARD_UW180S_LABELLENGTH,
	STR_DASHBOARD_UW180S_LABELDIAMETER,
	STR_DASHBOARD_UW180S_LABELVOLUME,
	STR_TASKBAR_LABELHOURS,
	STR_TASKBAR_LABELWATER,
	STR_TASKBAR_LABELOILPRESS,
	STR_TASKBAR_LABELALTERNATOR,
	STR_TASKBAR_LABELGLOW,
	STR_TASKBAR_LABELSTOP,
	STR_TASKBAR_LABELGEAR,
	STR_TASKBAR_HORN,
	STR_TASKBAR_BATV,
	STR_TASKBAR_FUELL,
	STR_TASKBAR_OILL,
	STR_TASKBAR_OILT,
	STR_TASKBAR_MOTORT,
	STR_TASKBAR_CLICKTOCLOSE,
	STR_TASKBAR_CLICKTOLOG,
	// counts the number of strings, should be the last in enum
	STR_COUNT
};



/// @brief: Returns the currently selected language
languages_e get_lang(void);



/// @brief: Sets the language. UI should be refreshed after calling this
void set_lang(const languages_e value);


/// @brief: Returns a pointer to the active language string.
///
/// @param index: Index to langstr_st array. User should keep track of
/// string index one way or another.
char *uv_str(uint16_t index);



#endif /* TR_H_ */
