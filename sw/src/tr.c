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
#include "system_restore.h"


static languages_e current_lang = LANG_EN;

static langstr_st strs[STR_COUNT] = {
		{
				"English",
				"Suomi"
		},
		{
				"Back",
				"Takaisin"
		},
		{
				"Cancel",
				"Hylkaa"
		},
		{
				"Save",
				"Tallenna"
		},
		{
				"OK",
				"OK"
		},
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
				"Jarjestelma"
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
		},
		{
				"General",
				"Yleiset"
		},
		{
				"System",
				"Jarjestelma"
		},
		{
				"Select Implement",
				"Tyolaite"
		},
		{
				"Date and Time",
				"Paivamaara ja kellonaika"
		},
		{
				"Language",
				"Kieli"
		},
		{
				"Drive Light",
				"Ajovalot"
		},
		{
				"Work Light",
				"Tyovalot"
		},
		{
				"Engine power\nusage (%)",
				"Moottorin tehon\notto (%)"
		},
		{
				"Screen Brightness",
				"Nayton kirkkaus"
		},
		{
				"Oil Cooler\nTrigger Temp",
				"Oljynlauhduttimen\nliipaisulampotila"
		},
		{
				"Set Language\nAnd Reset",
				"Aseta Kieli\nja Kaynnista Uudelleen"
		},
		{
				"Implement not selected.\n"
				"Select implement from System settings.",
				"Tyolaitetta ei ole valittu.\n"
				"Valitse tyolaite jarjestelma-asetuksista."
		},
		{
				"Go to settings",
				"Siirry asetuksiin"
		},
		{
				"Forward Max Speed (mA)",
				"Max nopeus eteen (mA)"
		},
		{
				"Backward Max Speed (mA)",
				"Max nopeus taakse (mA)"
		},
		{
				"Forward Min Speed (mA)",
				"Min nopeus eteen (mA)"
		},
		{
				"Backward Min Speed (mA)",
				"Min nopeus taakse (mA)"
		},
		{
				"Acceleration (%)",
				"Kiihtyvyys (%)"
		},
		{
				"Deceleration (%)",
				"Hidastuvuus (%)"
		},
		{
				"Invert Direction",
				"Invertoi suunta"
		},
		{
				"Rotator",
				"Rotaattori"
		},
		{
				"Open / Close",
				"Auki / Kiinni"
		},
		{
				"Forward\nMax Speed (mA)",
				"Max Nopeus\nEteen (mA)"
		},
		{
				"Backward\nMax Speed (mA)",
				"Max Nopeus\nTaakse (mA)"
		},
		{
				"Acceleration\n(%)",
				"Kiihtyvyys\n(%)"
		},
		{
				"Deceleration\n(%)",
				"Hidastuvuus\n(%)"
		},
		{
				"Invert\nDirection",
				"Invertoi\nSuunta"
		},
		{
				"UW180S General",
				"UW180S Yleiset"
		},
		{
				"Rollers grab\ntime (ms)",
				"Rullien\npuristusaika (ms)"
		},
		{
				"Blades grab\ntime (ms)",
				"Terien\npuristusaika (ms)"
		},
		{
				"UW180S Valves",
				"UW180S venttiilit"
		},
		{
				"Wheels\nopen/close",
				"Rullat\nauki/kiinni"
		},
		{
				"Feeding",
				"Puun syotto"
		},
		{
				"Blades\nopen/close",
				"Terat\nauki/kiinni"
		},
		{
				"Saw",
				"saha"
		},
		{
				"Tilt",
				"tiltti"
		},
		{
				"Rotator",
				"Rotaattori"
		},
		{
				"UW180S Measurement",
				"UW180S mittalaite"
		},
		{
				"Enabled",
				"Kaytossa"
		},
		{
				"Log Length 1",
				"Puun pituus 1"
		},
		{
				"Log Length 2",
				"Puun pituus 2"
		},
		{
				"Length\nCalibration",
				"Pituus\nKalibrointi"
		},
		{
				"Volume\nCalibration",
				"Tilavuus\nKalibrointi"
		},
		{
				"Note: Calibration values are\n"
				"shared across all users",
				"Huomio: Kalibrointiarvot ovat\n"
				"samat kaikille kayttajille."
		},
		{
				"Reset\nVolume",
				"Tilavuuden\nnollaus"
		},
		{
				"General",
				"Yleiset"
		},
		{
				"Log\nMeasurement",
				"Mittalaite"
		},
		{
				"Valve\nConfigurations",
				"Venttiili-\nasetukset"
		},
		{
				"General",
				"Yleiset"
		},
		{
				"Valve\nConfigurations",
				"Venttiilen\nKonfigurointi"
		},
		{
				"Implement\nSettings",
				"Tyolaitteen\nAsetukset"
		},
		{
				"Settings",
				"Asetukset"
		},
		{
				"Boom Lift",
				"Puomi nosto"
		},
		{
				"Boom Fold",
				"Puomi Taitto"
		},
		{
				"Boom Rotate",
				"Puomi kaanto"
		},
		{
				"Boom Telescope",
				"Puomi Teleskooppi"
		},
		{
				"Drive",
				"Ajo"
		},
		{
				"Steer",
				"Ohjaus"
		},
		{
				"Back Steering",
				"Takaohjaus"
		},
		{
				"Loading Space Telescope",
				"Kuormatilan teleskooppi"
		},
		{
				"Left Leg",
				"Vasen Tukijalka"
		},
		{
				"Right Leg",
				"Oikea Tukijalka"
		},
		{
				"Cabin Rotate",
				"Hytin Pyoritys"
		},
		{
				"RPM",
				"RPM"
		},
		{
				"Pressure",
				"Paine"
		},
		{
				"Network\nDiagnostics",
				"Jarjestelman\nDiagnostiikka"
		},
		{
				"Log",
				"Loki"
		},
		{
				"System\nCalibration",
				"Jarjestelman\nKalibrointi"
		},
		{
				"System\nRestore",
				"Tehdasasetusten\nPalautus"
		},
		{
				"\x11\x16 Select a log entry to acknowledge",
				"\x11\x16 Valitse kuitattava lokitieto"
		},
		{
				"Acknowledge",
				"Kuittaa"
		},
		{
				"Previous Page",
				"Edellinen sivu"
		},
		{
				"Next Page",
				"Seuraava sivu"
		},
		{
				"Page %u/%u",
				"Sivu %u/%u"
		},
		{
				"UW180S Measurement calibration",
				"UW180S Mittalaitteen kalibrointi"
		},
		{
				"Calibrate\nMIN angles",
				"Kalibroi\nMIN kulmat"
		},
		{
				"Calibrate\nMAX angles",
				"Kalibroi\nMAX kulmat"
		},
		{
				"Joystick\nCalibration",
				"Ohjainkahvojen\nKalibrointi"
		},
		{
				"Left:\n"
				"x max\n"
				"x middle\n"
				"x min\n \n"
				"Right:\n"
				"x max\n"
				"x middle\n"
				"x min",
				"Vasen:\n"
				"x max\n"
				"x keski\n"
				"x min\n \n"
				"Oikea:\n"
				"x max\n"
				"x keski\n"
				"x min"
		},
		{
				"To calibrate the joysticks,\n"
				"rotate through all of their axes and thumb switches",
				"Kalibroi ohjauskahvat kaantamalla kahvaa siten,\n"
				"etta kaikkien akseleiden minimi ja maksimiarvot mitataan."
		},
		{
				"Press the button below for " STRINGIFY(RESTORE_DELAY_S) " seconds to\n"
				"restore the system to factory settings.\n"
				"The display will reboot after the restore.\n \n"
				"WARNING: ALL SETTINGS FROM ALL USERS WILL BE LOST",
				"Paina alla olevaa painiketta " STRINGIFY(RESTORE_DELAY_S) " sekunttia\n"
				"Palauttaaksesi tehdasasetukset.\n"
				"Naytto resetoi itsensa asetusten palautuksen jalkeen.\n \n"
				"VAROITUS: KAIKKIEN KAYTTAJIEN ASETUKSET MENETETAAN"
		},
		{
				"Restore System Defaults",
				"Palauta tehdasasetukset"
		},
		{
				"Left Keypad",
				"Vasen Nappaimisto"
		},
		{
				"Right Keypad",
				"Oikea Nappaimisto"
		},
		{
				"Pedal",
				"Poljin"
		},
		{
				"ESB",
				"ESB"
		},
		{
				"FSB",
				"FSB"
		},
		{
				"CSB",
				"CSB"
		},
		{
				"ECU",
				"ECU"
		},
		{
				"UW180S",
				"UW180S"
		},
		{
				"UW180S MB",
				"UW180S MB"
		},
		{
				"Connected\n"
				"Node ID",
				"Yhteys\n"
				"Node ID"
		},
		{
				"Total Current\n"
				"Glow State\n"
				"Starter State\n"
				"AC State\n"
				"MStart1 State\n"
				"MStart2 State\n"
				"Pump State\n"
				"Alt IG State\n"
				"Oil cooler State",
				"Virta yhteensa\n"
				"Hehkut\n"
				"Starttimoottori\n"
				"Ilmastointi\n"
				"Starttisolenoidi1\n"
				"Starttisolenoidi2\n"
				"Hydraulipumppu\n"
				"Laturi IG\n"
				"Oljynlauhdutin"
		},
		{
				"RPM\n"
				"Alt L\n"
				"Motor Water\n"
				"Motor Oil\n"
				"Motor Temp (C)\n"
				"Oil Temp (C)\n"
				"Oil Level (%)\n"
				"Fuel Level (%)\n"
				"Voltage (mV)\n"
				"OilC trig temp (C)",
				"RPM\n"
				"Laturi L\n"
				"Jaahdytinneste\n"
				"Moottorioljy\n"
				"Moottori T (C)\n"
				"Oljy T (C)\n"
				"Oljy M (%)\n"
				"Diesel M (%)\n"
				"Jannite (mV)\n"
				"Lauhdutin raja(C)"
		},
		{
				"Total Current\n"
				"Horn State\n"
				"Radio State\n"
				"Aux State\n"
				"Heater State",
				"Virta yhteensa\n"
				"Torvi\n"
				"Radio\n"
				"Tupakansytytin\n"
				"Lammitin"
		},
		{
				"Ignition key\n"
				"Heater Speed\n"
				"EMCY switch\n"
				"Bat Voltage\n"
				"Eber Fan\n"
				"Seat\n"
				"Door1\n"
				"Door2",
				"Virta-avain\n"
				"Lammitin\n"
				"Hataseis\n"
				"Akku\n"
				"Eber tuuletin\n"
				"Penkkikytkin\n"
				"Ovikytkin1\n"
				"Ovikytkin2"
		},
		{
				"Total Current\n"
				"Work Light State\n"
				"Drive Light State\n"
				"Back Light State\n"
				"In Light State\n"
				"Beacon State\n"
				"Wiper State\n"
				"Cooler State",
				"Virta Yhteensa\n"
				"Tyovalot\n"
				"Ajovalot\n"
				"Takavalo\n"
				"Sisavalo\n"
				"Majakka\n"
				"Pyyhin\n"
				"Ilmastointi"
		},
		{
				"Wiper Speed\n"
				"Cooler P\n"
				"Work Light (mA)\n"
				"Drive Light (mA)",
				"Pyyhin nopeus\n"
				"Ilmastointi P\n"
				"Tyovalot (mA)\n"
				"Ajovalot (mA)"
		},
		{
				"Controls moved\n"
				"Engine shut down\n"
				"Pump angle (ppt)\n"
				"Implement\n"
				"Legs Down\n"
				"Pressure (bar)",
				"Ohjaus tila\n"
				"Moottori tila\n"
				"Pumppu kulma (ppt)\n"
				"Tyolaite\n"
				"Jalat alhaalla\n"
				"Paine (bar)"
		},
#if FM
		{
				"Boom Lift (mA)\n"
				"Boom Fold (mA)\n"
				"Boom Rotate (mA)\n"
				"Drive (mA)\n"
				"Steer (mA)\n"
				"Left Leg (mA)\n"
				"Right Leg (mA)\n"
				"Impl valve (mA)",
				"Puomi nosto (mA)\n"
				"Puomi taitto (mA)\n"
				"Puomi kaanto (mA)\n"
				"Ajo (mA)\n"
				"Ohjaus (mA)\n"
				"Vasen jalka (mA)\n"
				"Oikea jalka (mA)\n"
				"Tyolaite (mA)"
		}
#elif CM
		{
			"Boom Lift (mA)\n"
			"Boom Fold (mA)\n"
			"Boom Rotate (mA)\n"
			"Drive (mA)\n"
			"Steer (mA)\n"
			"Body Telescope (mA)\n"
			"Left Leg (mA)\n"
			"Right Leg (mA)\n"
			"Cabin Rotate (mA)",
			"Puomi Nosto (mA)\n"
			"Puomi Taitto (mA)\n"
			"Puomi Kaanto (mA)\n"
			"Ajo (mA)\n"
			"Ohjaus (mA)\n"
			"Teleskooppi (mA)\n"
			"Vasen Jalka (mA)\n"
			"Oikea Jalka (mA)\n"
			"Hytin Pyoritys (mA)"
		},
#elif LM
		{
				"Boom Lift (mA)\n"
				"Boom Fold (mA)\n"
				"Boom Rotate (mA)\n"
				"Boom Telescope (mA)\n"
				"Drive (mA)\n"
				"Steer (mA)\n"
				"Steer Back (mA)\n"
				"Left Leg (mA)\n"
				"Right Leg (mA)\n"
				"Cabin Rotate (mA)",
				"Puomi Nosto (mA)\n"
				"Puomi Taitto (mA)\n"
				"Puomi Kaanto (mA)\n"
				"Puomi Teleskooppi (mA)\n"
				"Ajo (mA)\n"
				"Ohjaus (mA)\n"
				"Takaohjaus (mA)\n"
				"Vasen Jalka (mA)\n"
				"Oikea Jalka (mA)\n"
				"Hytin Pyoritys (mA)"

		},
#endif
		{
				"x\nx err\ny\ny err\nz\nz err\nv\nv err",
				"x\nx err\ny\ny err\nz\nz err\nv\nv err"
		},
		{
				"b1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nb9\nb10",
				"b1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nb9\nb10"
		},
		{
				"Position",
				"Asento"
		},
		{
				"",
				""
		},
		{
				"",
				""
		},
		{
				"",
				""
		},
		{
				"Length\nWidth\nVolume\nRel width\n\nWSensor 1\nWSensor 2",
				"Pituus\nPaksuus\nTilavuus\nSuht paksuus\n\nWAnturi 1\nWAnturi 2"
		},
		{
				"",
				""
		}
};

languages_e get_lang(void) {
	return current_lang;
}

void set_lang(const languages_e value) {
	current_lang = value;
	if (current_lang >= LANG_COUNT) {
		current_lang = LANG_EN;
	}
}


char *uv_str(langstr_e index) {
	return strs[index][current_lang];
}

char *uv_strlang(langstr_e index, languages_e lang) {
	return strs[index][lang];
}

