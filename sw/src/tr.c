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



#include <uv_utilities.h>
#include "tr.h"


static languages_e lang = LANG_EN;

static langstr_st strs[STR_COUNT] = {
		{
				"Dashboard",
				"Paneeli"
		},
		{
				"Settings",
				"Asetukset"
		},
		{
				"System",
				"Järjestelmä"
		},
		{
				"Log Out",
				"Kirjaudu\nulos"
		},
		{
				"Select Driver",
				"Valitse kuljettaja"
		},
		{
				"Log In",
				"Kirjaudu"
		},
		{
				"Add User",
				"Lisaa kujettaja"
		},
		{
				"Delete User",
				"Poista kuljettaja"
		},
		{
				"Target Length:",
				"Tavoitepituus:"
		},
		{
				"Length (cm)",
				"Pituus (cm)"
		},
		{
				"Diameter (mm)",
				"Halkaisija (mm)"
		},
		{
				"Volume (m3)",
				"Tilavuus (m3)"
		},
		{
				"Hours",
				"Tunnit"
		},
		{
				"Water",
				"Jaahdytyvesi"
		},
		{
				"Oil Press",
				"Oljyn paine"
		},
		{
				"Alternator",
				"Laturi"
		},
		{
				"Glow Plugs",
				"Hehku"
		},
		{
				"EMCY",
				"Hata"
		},
		{
				"Door",
				"Ovi"
		},
		{
				"Seat",
				"Istuin"
		},
		{
				"Gear",
				"Vaihde"
		},
		{
				"Horn",
				"Torvi"
		},
		{
				"Wiper",
				"Pyyhin"
		},
		{
				"Heat",
				"Lampo"
		},
		{
				"Bat V",
				"Akku"
		},
		{
				"Fuel L",
				"DieselM"
		},
		{
				"OIL L",
				"OljyM"
		},
		{
				"Oil T",
				"OljyL"
		},
		{
				"Motor T",
				"KubotaL"
		},
		{
				"Click to close",
				"Paina sulkeaksesi"
		},
		{
				"Click to go to the log",
				"Paina mennaksesi lokiin"
		}
};

languages_e get_lang(void) {
	return lang;
}

void set_lang(const languages_e value) {
	lang = value;
}


char *uv_str(uint16_t index) {
	return strs[index][lang];
}
