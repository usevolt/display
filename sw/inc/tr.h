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



/// @file: Defines UI translations for all supported languages



/// @brief: Enumerations of all available languages
typedef enum {
	LANG_EN = 0,	// note: English is the default language and it should be the first in here
	LANG_FI,
	LANG_DE,
	LANG_COUNT
} languages_e;


/// @brief: Structure for a multi language string. Contains pointers to
/// all languages available.
typedef char* langstr_st[LANG_COUNT];


/// @brief: Indexes to all languages in the software
typedef enum {
	STR_LANG = 0,
	STR_BACK,
	STR_CANCEL,
	STR_SAVE,
	STR_OK,
	STR_HOME_BUTDASHBOARD,
	STR_HOME_BUTSETTINGS,
	STR_HOME_BUTSYSTEM,
	STR_HOME_BUTLOGOUT,
	STR_LOGIN_LABELSELECTDRIVER,
	STR_LOGIN_BUTLOGIN,
	STR_LOGIN_BUTADDUSER,
	STR_LOGIN_BUTCOPYUSER,
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
	STR_TASKBAR_LABELEMCY,
	STR_TASKBAR_LABELDOOR,
	STR_TASKBAR_LABELSEAT,
	STR_TASKBAR_LABELGEAR,
	STR_TASKBAR_HORN,
	STR_TASKBAR_WIPER,
	STR_TASKBAR_HEAT,
	STR_TASKBAR_BATV,
	STR_TASKBAR_FUELL,
	STR_TASKBAR_OILL,
	STR_TASKBAR_OILT,
	STR_TASKBAR_MOTORT,
	STR_TASKBAR_CLICKTOCLOSE,
	STR_TASKBAR_CLICKTOLOG,
	STR_SETTINGS_GENERAL_TREEGENERAL,
	STR_SETTINGS_GENERAL_TREESYSTEM,
	STR_SETTINGS_GENERAL_TREESELIMPL,
	STR_SETTINGS_GENERAL_TREEDATETIME,
	STR_SETTINGS_GENERAL_TREELANG,
	STR_SETTINGS_GENERAL_BUTTONDRIVELIGHT,
	STR_SETTINGS_GENERAL_BUTTONWORKLIGHT,
	STR_SETTINGS_GENERAL_SLIDERENGINEPOWER,
	STR_SETTINGS_GENERAL_SLIDERBRIGHTNESS,
	STR_SETTINGS_GENERAL_SLIDEROILCTEMP,
	STR_SETTINGS_GENERAL_BUTTONSETLANG,
	STR_SETTINGS_IMPL_LABELNOTSELECTED,
	STR_SETTINGS_IMPL_BUTTONGOTOSETTINGS,
	STR_SETTINGS_VALVES_SLIDERFORMAXSPEED,
	STR_SETTINGS_VALVES_SLIDERBACKMAXSPEED,
	STR_SETTINGS_VALVES_SLIDERFORMINSPEED,
	STR_SETTINGS_VALVES_SLIDERBACKMINSPEED,
	STR_SETTINGS_VALVES_SLIDERACC,
	STR_SETTINGS_VALVES_SLIDERDEC,
	STR_SETTINGS_VALVES_BUTTONINVERT,
	STR_SETTINGS_VALVES_BUTTONASSINV,
	STR_SETTINGS_UW100_BUTTONROTATOR,
	STR_SETTINGS_UW100_BUTTONOPENCLOSE,
	STR_SETTINGS_UW100_SLIDERFORMAXSPEED,
	STR_SETTINGS_UW100_SLIDERBACKMAXSPEED,
	STR_SETTINGS_UW100_SLIDERACC,
	STR_SETTINGS_UW100_SLIDERDEC,
	STR_SETTINGS_UW100_BUTTONINVERT,
	STR_SETTINGS_UW180S_LABELUW180SGENERAL,
	STR_SETTINGS_UW180S_SLIDERROLLERSGRABTIME,
	STR_SETTINGS_UW180S_SLIDERBLADESGRABTIME,
	STR_SETTINGS_UW180S_TOGGLETILTFLOAT,
	STR_SETTINGS_UW180S_LABELVALVES,
	STR_SETTINGS_UW180S_BUTTONFEEDOPEN,
	STR_SETTINGS_UW180S_BUTTONFEED,
	STR_SETTINGS_UW180S_BUTTONBLADESOPEN,
	STR_SETTINGS_UW180S_BUTTONSAW,
	STR_SETTINGS_UW180S_BUTTONTILT,
	STR_SETTINGS_UW180S_BUTTONROTATOR,
	STR_SETTINGS_UW180S_BUTTONALLOPEN,
	STR_SETTINGS_UW180S_BUTTONIMPL1,
	STR_SETTINGS_UW180S_BUTTONIMPL2,
	STR_SETTINGS_UW180S_LABELMEAS,
	STR_SETTINGS_UW180S_BUTTONENABLED,
	STR_SETTINGS_UW180S_SLIDERLOGLEN1,
	STR_SETTINGS_UW180S_SLIDERLOGLEN2,
	STR_SETTINGS_UW180S_SLIDERLENCAL,
	STR_SETTINGS_UW180S_SLIDERVOLCAL,
	STR_SETTINGS_UW180S_LABELCALVALS,
	STR_SETTINGS_UW180S_BUTTONRESETVOL,
	STR_SETTINGS_UW180S_BUTTONWCALIB,
	STR_SETTINGS_UW180S_LABELWCALIB,
	STR_SETTINGS_UW180S_LABELGENERAL,
	STR_SETTINGS_UW180S_LABELLOGMEAS,
	STR_SETTINGS_UW180S_LABELVALVECONFS,
	STR_SETTINGS_TABGENERAL,
	STR_SETTINGS_TABVALVECONFS,
	STR_SETTINGS_TABIMPLSETTINGS,
	STR_LABELSETTINGS,
	STR_SETTINGS_VALVES_TREEBOOMLIFT,
	STR_SETTINGS_VALVES_TREEBOOMFOLD,
	STR_SETTINGS_VALVES_TREEBOOMROTATE,
	STR_SETTINGS_VALVES_TREEBOOMTELESCOPE,
	STR_SETTINGS_VALVES_TREEGEAR1,
	STR_SETTINGS_VALVES_TREEGEAR2,
	STR_SETTINGS_VALVES_TREEGEAR3,
	STR_SETTINGS_VALVES_TREESTEER,
	STR_SETTINGS_VALVES_TREESTEERBACK,
	STR_SETTINGS_VALVES_TREETELESCOPE,
	STR_SETTINGS_VALVES_TREELEFTLEG,
	STR_SETTINGS_VALVES_TREERIGHTLEG,
	STR_SETTINGS_VALVES_TREECABROTATE,
	STR_BARRPM,
	STR_BARPRESSURE,
	STR_SYSTEM_TABNETWORK,
	STR_SYSTEM_TABLOG,
	STR_SYSTEM_TABCALIB,
	STR_SYSTEM_TABRESTORE,
	STR_SYSTEM_LOG_LABELSELECT,
	STR_SYSTEM_LOG_BUTTONACK,
	STR_SYSTEM_LOG_BUTTONPREVPAGE,
	STR_SYSTEM_LOG_BUTTONNEXTPAGE,
	STR_SYSTEM_LOG_LABELPAGE,
	STR_SYSTEM_CALIB_LABELUW180SCAL,
	STR_SYSTEM_CALIB_BUTTONCALIBMIN,
	STR_SYSTEM_CALIB_BUTTONCALIBMAX,
	STR_SYSTEM_CALIB_BUTTONJOYSTICK,
	STR_SYSTEM_CALIB_LABELAXES,
	STR_SYSTEM_CALIB_LABELINFO,
	STR_SYSTEM_RESTORE_LABELINFO,
	STR_SYSTEM_RESTORE_BUTTONRESTORE,
	STR_SYSTEM_DIAG_LABELLEFTKEYPAD,
	STR_SYSTEM_DIAG_LABELRIGHTKEYPAD,
	STR_SYSTEM_DIAG_LABELPEDAL,
	STR_SYSTEM_DIAG_LABELESB,
	STR_SYSTEM_DIAG_LABELFSB,
	STR_SYSTEM_DIAG_LABELCSB,
	STR_SYSTEM_DIAG_LABELHCU,
	STR_SYSTEM_DIAG_LABELCCU,
	STR_SYSTEM_DIAG_LABELICU,
	STR_SYSTEM_DIAG_LABELNETDEV,
	STR_SYSTEM_DIAG_LABELESBCOL1,
	STR_SYSTEM_DIAG_LABELESBCOL2,
	STR_SYSTEM_DIAG_LABELFSBCOL1,
	STR_SYSTEM_DIAG_LABELFSBCOL2,
	STR_SYSTEM_DIAG_LABELCSBCOL1,
	STR_SYSTEM_DIAG_LABELCSBCOL2,
	STR_SYSTEM_DIAG_LABELHCUCOL1,
	STR_SYSTEM_DIAG_LABELHCUCOL2,
	STR_SYSTEM_DIAG_LABELKEYPADCOL1,
	STR_SYSTEM_DIAG_LABELKEYPADCOL2,
	STR_SYSTEM_DIAG_LABELPEDALCOL1,
	STR_SYSTEM_DIAG_LABELPEDALCOL2,
	STR_SYSTEM_DIAG_LABELCCUCOL1,
	STR_SYSTEM_DIAG_LABELCCUCOL2,
	STR_SYSTEM_DIAG_LABELICUCOL1,
	STR_SYSTEM_DIAG_LABELICUCOL2,
	// counts the number of strings, should be the last in enum
	STR_COUNT
} langstr_e;



/// @brief: Returns the currently selected language
languages_e get_lang(void);



/// @brief: Sets the language. UI should be refreshed after calling this
void set_lang(const languages_e value);


/// @brief: Returns a pointer to the active language string.
///
/// @param index: Index to langstr_st array. User should keep track of
/// string index one way or another.
char *uv_str(langstr_e index);

/// @brief: Returns a pointer to the language string in language **lang**
char *uv_strlang(langstr_e index, languages_e lang);



#endif /* TR_H_ */
