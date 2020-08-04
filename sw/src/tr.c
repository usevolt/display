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
				"Suomi",
				"Deutsch"
		},
		{
				"Back",
				"Takaisin",
				"Zuruck"
		},
		{
				"Cancel",
				"Hylkaa",
				"Ablehnen"
		},
		{
				"Save",
				"Tallenna",
				"Speichern"
		},
		{
				"OK",
				"OK",
				"OK"
		},
		{
				"Dashboard",
				"Paneeli",
				"Dashboard"
		},
		{
				"Settings",
				"Asetukset",
				"Einstellungen"
		},
		{
				"System",
				"Jarjestelma",
				"System"
		},
		{
				"Log Out",
				"Kirjaudu\nulos",
				"Aus loggen"
		},
		{
				"Select Driver",
				"Valitse kuljettaja",
				"Fahrerauswahl"
		},
		{
				"Log In",
				"Kirjaudu",
				"Ein loggen"
		},
		{
				"Add User",
				"Lisaa kujettaja",
				"Fahrer zugeben"
		},
		{
				"Delete User",
				"Poista kuljettaja",
				"Fahrer entfernen"
		},
		{
				"Target Length:",
				"Tavoitepituus:",
				"Ziellange"
		},
		{
				"Length (cm)",
				"Pituus (cm)",
				"Lange (cm)"
		},
		{
				"Diameter (mm)",
				"Halkaisija (mm)",
				"Durchmesser (mm)"
		},
		{
				"Volume (m3)",
				"Tilavuus (m3)",
				"Volumen (m3)"
		},
		{
				"Hours",
				"Tunnit",
				"Stunden"
		},
		{
				"Water",
				"Jaahdytyvesi",
				"Kuhlwasser"
		},
		{
				"Oil Press",
				"Oljyn paine",
				"Oldruck"
		},
		{
				"Alternator",
				"Laturi",
				"Lichtmaschine"
		},
		{
				"Glow Plugs",
				"Hehku",
				"Gluhkerzen"
		},
		{
				"EMCY",
				"Hata",
				"Notfall"
		},
		{
				"Door",
				"Ovi",
				"Tur"
		},
		{
				"Seat",
				"Istuin",
				"Sitz"
		},
		{
				"Gear",
				"Vaihde",
				"Gang"
		},
		{
				"Horn",
				"Torvi",
				"Hupe"
		},
		{
				"Wiper",
				"Pyyhin",
				"Wischer"
		},
		{
				"Heat",
				"Lampo",
				"Heizung"
		},
		{
				"Bat V",
				"Akku",
				"Akku"
		},
		{
				"Fuel L",
				"DieselM",
				"DieselM"
		},
		{
				"OIL L",
				"OljyM",
				"Ol M"
		},
		{
				"Oil T",
				"OljyL",
				"Ol T"
		},
		{
				"Motor T",
				"KubotaL",
				"Motor T"
		},
		{
				"Click to close",
				"Paina sulkeaksesi",
				"Zum Schliessen klicken"
		},
		{
				"Click to go to the log",
				"Paina mennaksesi lokiin",
				"Klicke um Log Zu Offnen"
		},
		{
				"General",
				"Yleiset",
				"Allgemeines"
		},
		{
				"System",
				"Jarjestelma",
				"System"
		},
		{
				"Select Implement",
				"Tyolaite",
				"Arbeitsgerat"
		},
		{
				"Date and Time",
				"Paivamaara ja kellonaika",
				"Datum und Uhrzeit"
		},
		{
				"Language",
				"Kieli",
				"Sprache"
		},
		{
				"Drive Light",
				"Ajovalot",
				"Fahrlicht"
		},
		{
				"Work Light",
				"Tyovalot",
				"Arbeitslicht"
		},
		{
				"Engine power\noutput (%)",
				"Moottorin tehon\nanto (%)",
				"Motor Kraftabgabe (%)"
		},
		{
				"Screen Brightness",
				"Nayton kirkkaus",
				"Display Helligkeit"
		},
		{
				"Oil Cooler\nTrigger Temp",
				"Oljynlauhduttimen\nliipaisulampotila",
				"Olkuhler Auslos\ntemperatur"
		},
		{
				"Set Language\nAnd Reset",
				"Aseta Kieli\nja Kaynnista Uudelleen",
				"Sprache einstellen \nund resetieren"

		},
		{
				"Implement not selected.\n"
				"Select implement from System settings.",
				"Tyolaitetta ei ole valittu.\n"
				"Valitse tyolaite jarjestelma-asetuksista.",
				"Arbeitsgerat nicht gewahlt.\n"
				"Wahle ein gerat bei Systemeinstellungen."		},
		{
				"Go to settings",
				"Siirry asetuksiin",
				"Zu den Einstellungen"
		},
		{
				"Forward Max Speed (mA)",
				"Max nopeus eteen (mA)",
				"Vorw. max. Geschw. (mA)"
		},
		{
				"Backward Max Speed (mA)",
				"Max nopeus taakse (mA)",
				"Ruckw. max. Geschw. (mA)"
		},
		{
				"Forward Min Speed (mA)",
				"Min nopeus eteen (mA)",
				"Vorw. min. Geschw. (mA)"
		},
		{
				"Backward Min Speed (mA)",
				"Min nopeus taakse (mA)",
				"Ruckw. min. Geschw. (mA)"
		},
		{
				"Acceleration (%)",
				"Kiihtyvyys (%)",
				"Beschleunigung (%)"
		},
		{
				"Deceleration (%)",
				"Hidastuvuus (%)",
				"Verzogerung (%)"
		},
		{
				"Invert Direction",
				"Invertoi suunta",
				"Richtung umstellen"
		},
		{
				"Rotator",
				"Rotaattori",
				"Rotator"
		},
		{
				"Open / Close",
				"Auki / Kiinni",
				"Auf / Zu"
		},
		{
				"Forward\nMax Speed (mA)",
				"Max Nopeus\nEteen (mA)",
				"Vorw. max.\nGeschw. (mA)"
		},
		{
				"Backward\nMax Speed (mA)",
				"Max Nopeus\nTaakse (mA)",
				"Ruckw. max.\nGeschw. (mA)"
		},
		{
				"Acceleration\n(%)",
				"Kiihtyvyys\n(%)",
				"Beschleunigung (%)"
		},
		{
				"Deceleration\n(%)",
				"Hidastuvuus\n(%)",
				"Verzogerung (%)"
		},
		{
				"Invert\nDirection",
				"Invertoi\nSuunta",
				"Richtung \numstellen"
		},
		{
				"UW180S General",
				"UW180S Yleiset",
				"UW180S Allgemeines"
		},
		{
				"Rollers grab\ntime (ms)",
				"Rullien\npuristusaika (ms)",
				"Rollen\nGreifzeit (ms)"
		},
		{
				"Blades grab\ntime (ms)",
				"Terien\npuristusaika (ms)",
				"Klingen\nGreifzeit (ms)"
		},
		{
				"UW180S Valves",
				"UW180S venttiilit",
				"UW180S Ventile"
		},
		{
				"Wheels\nopen/close",
				"Rullat\nauki/kiinni",
				"Rollen\noffen/zu"
		},
		{
				"Feeding",
				"Puun syotto",
				"Futterung"
		},
		{
				"Blades\nopen/close",
				"Terat\nauki/kiinni",
				"Klingen\noffen/zu"
		},
		{
				"Saw",
				"Saha",
				"Sage"
		},
		{
				"Tilt",
				"Tiltti",
				"Neigung"
		},
		{
				"Rotator",
				"Rotaattori",
				"Rotator"
		},
		{
				"UW180S Measurement",
				"UW180S mittalaite",
				"UW180S Messgerat"
		},
		{
				"Enabled",
				"Kaytossa",
				"Aktiviert"
		},
		{
				"Log Length 1",
				"Puun pituus 1",
				"Holtz Lange 1"
		},
		{
				"Log Length 2",
				"Puun pituus 2",
				"Holtz Lange 2"
		},
		{
				"Length\nCalibration",
				"Pituus\nKalibrointi",
				"Lange\nKalibration"
		},
		{
				"Volume\nCalibration",
				"Tilavuus\nKalibrointi",
				"Volumen\nKalibration"
		},
		{
				"Note: Calibration values are\n"
				"shared across all users",
				"Huomio: Kalibrointiarvot ovat\n"
				"samat kaikille kayttajille.",
				"Achtung: Kalibrationswarte sind\n"
				"gleich fur alle Benutzer."
		},
		{
				"Reset\nVolume",
				"Tilavuuden\nnollaus",
				"Volumen\nResetieren"
		},
		{
				"General",
				"Yleiset",
				"Allgemeines"
		},
		{
				"Log\nMeasurement",
				"Mittalaite",
				"Messgerat"
		},
		{
				"Valve\nConfigurations",
				"Venttiili-\nasetukset",
				"Ventil\nEinstellungen"
		},
		{
				"General",
				"Yleiset",
				"Allgemeines"
		},
		{
				"Valve\nConfigurations",
				"Venttiilen\nKonfigurointi",
				"Ventil\nEinstellungen"
		},
		{
				"Implement\nSettings",
				"Tyolaitteen\nAsetukset",
				"Arbeitsgerat\nEinstelungen."
		},
		{
				"Settings",
				"Asetukset",
				"Einstellungen"
		},
		{
				"Boom Lift",
				"Puomi nosto",
				"Ausleger heben"
		},
		{
				"Boom Fold",
				"Puomi Taitto",
				"Ausleger falten"
		},
		{
				"Boom Rotate",
				"Puomi kaanto",
				"Ausleger drehen"
		},
		{
				"Boom Telescope",
				"Puomi Teleskooppi",
				"Ausleger verlangerung"
		},
		{
				"Drive",
				"Ajo",
				"Fur"
		},
		{
				"Drive Back",
				"Ajo takaporat",
				"Fur back"
		},
		{
				"Steer",
				"Ohjaus",
				"Steuerung"
		},
		{
				"Back Steering",
				"Takaohjaus",
				"Hinterrad Steuerung"
		},
		{
				"Loading Space Telescope",
				"Kuormatilan teleskooppi",
				"Laderaum verlangerung"
		},
		{
				"Left Leg",
				"Vasen Tukijalka",
				"Stutze links"
		},
		{
				"Right Leg",
				"Oikea Tukijalka",
				"Stutze rechts"
		},
		{
				"Cabin Rotate",
				"Hytin Pyoritys",
				"Kabine Drehen"
		},
		{
				"RPM",
				"RPM",
				"RPM"
		},
		{
				"Pressure",
				"Paine",
				"Druck"
		},
		{
				"System\nDiagnostics",
				"Jarjestelman\nDiagnostiikka",
				"Systemdiagnose"
		},
		{
				"Log",
				"Loki",
				"Logbuch"
		},
		{
				"System\nCalibration",
				"Jarjestelman\nKalibrointi",
				"Systemkalibration"
		},
		{
				"System\nRestore",
				"Tehdasasetusten\nPalautus",
				"WerkS"
				"einstellungen\nzurucksetzen"
		},
		{
				"\x11\x16 Select a log entry to acknowledge",
				"\x11\x16 Valitse kuitattava lokitieto",
				"\x11\x16 Wahle einen log-eintrag zur bestatikung"
		},
		{
				"Acknowledge",
				"Kuittaa",
				"Bestatigen"
		},
		{
				"Previous Page",
				"Edellinen sivu",
				"Vorherige Seite"
		},
		{
				"Next Page",
				"Seuraava sivu",
				"Nächste Seite"
		},
		{
				"Page %u/%u",
				"Sivu %u/%u",
				"Seite %u/%u"
		},
		{
				"UW180S Measurement calibration",
				"UW180S Mittalaitteen kalibrointi",
				"UW180S Messgerat Kalibration"
		},
		{
				"Calibrate\nMIN angles",
				"Kalibroi\nMIN kulmat",
				"Kalbriere\nMIN Winkel"
		},
		{
				"Calibrate\nMAX angles",
				"Kalibroi\nMAX kulmat",
				"Kalbriere\nMAX Winkel"
		},
		{
				"Joystick\nCalibration",
				"Ohjainkahvojen\nKalibrointi",
				"Joystick\nKalibration"
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
				"x min",
				"Links:\n"
				"x max\n"
				"x mitte\n"
				"x min\n \n"
				"Rechts:\n"
				"x max\n"
				"x mitte\n"
				"x min"
		},
		{
				"To calibrate the joysticks,\n"
				"rotate through all of their axes and thumb switches",
				"Kalibroi ohjauskahvat kaantamalla kahvaa siten,\n"
				"etta kaikkien akseleiden minimi ja maksimiarvot mitataan.",
				"Um die Joysticks zu Kalibrieren,drehen sie bitte\n"
				"den Joystick und Daumenschalter um alle Achsen herum"
		},
		{
				"Press the button below for " STRINGIFY(RESTORE_DELAY_S) " seconds to\n"
				"restore the system to factory settings.\n"
				"The display will reboot after the restore.\n \n"
				"WARNING: ALL SETTINGS FROM ALL USERS WILL BE LOST",
				"Paina alla olevaa painiketta " STRINGIFY(RESTORE_DELAY_S) " sekuntia\n"
				"Palauttaaksesi tehdasasetukset.\n"
				"Naytto resetoi itsensa asetusten palautuksen jalkeen.\n \n"
				"VAROITUS: KAIKKIEN KAYTTAJIEN ASETUKSET MENETETAAN",
				"Drucken sie den unteren Knopf fur " STRINGIFY(RESTORE_DELAY_S) " Sekunden um\n"
				"das System auf Werkseinstellungen zurückzusetzen.\n"
				"Das Display startet neu nach den Reboot.\n \n"
				"ACHTUNG: ALLE EINSTELLUNGEN FUR ALLE BENUZER WERDEN GELOSCHT"
		},
		{
				"Restore System Defaults",
				"Palauta tehdasasetukset",
				"Auf Werkseinstellungen zurücksetzen"
		},
		{
				"Left Keypad",
				"Vasen Nappaimisto",
				"Linke Tastatur"
		},
		{
				"Right Keypad",
				"Oikea Nappaimisto",
				"Rechte Tastatur"
		},
		{
				"Pedal",
				"Poljin",
				"Pedal"
		},
		{
				"ESB",
				"ESB",
				"ESB"
		},
		{
				"FSB",
				"FSB",
				"FSB"
		},
		{
				"CSB",
				"CSB",
				"CSB"
		},
		{
				"ECU",
				"ECU",
				"ECU"
		},
		{
				"UW180S",
				"UW180S",
				"UW180S"
		},
		{
				"UW180S MB",
				"UW180S MB",
				"UW180S MB"
		},
		{
				"Connected\n"
				"Node ID",
				"Yhteys\n"
				"Node ID",
				"Verbunden\n"
				"Node ID"
		},
		{
				"Total Current\n"
				"Glow State\n"
				"Starter State\n"
				"AC State\n"
				"MStart1 State\n"
				"MStart2 State\n"
				"Hydr.Pump State\n"
				"Alt IG State\n"
				"Oil cooler State\n"
				"Pump angle (ppt)",
				"Virta yhteensa\n"
				"Hehkut\n"
				"Starttimoottori\n"
				"Ilmastointi\n"
				"Starttisolenoidi1\n"
				"Starttisolenoidi2\n"
				"Hydraulipumppu\n"
				"Laturi IG\n"
				"Oljynlauhdutin\n"
				"Pumpun kulma",
				"Gesamtspannung\n"
				"Gluhstatus\n"
				"Starterstatus\n"
				"Klimaanlage status\n"
				"MStart1 status\n"
				"MStart2 status\n"
				"Hydr. Pumpe Status\n"
				"Lichtm. status\n"
				"Olkuhler Status\n"
				"Pumpe Winkel (ppt)"
		},
		{
				"RPM\n"
				"Alt L\n"
				"Motor Water\n"
				"Motor Oil\n"
				"Motor Temp. (C)\n"
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
				"Lauhdutin raja(C)",
				"U/min\n"
				"Lichtm. L\n"
				"Kuhlflussigheit\n"
				"Motorol\n"
				"Motortemp. (C)\n"
				"Oltemp. (C)\n"
				"Olstand (%)\n"
				"Dieselstand (%)\n"
				"Spannung (mV)\n"
				"Kuhler Auslostemp. (C)"
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
				"Lammitin",
				"Gesamtspannung\n"
				"Hupe Status\n"
				"Radio Status\n"
				"Aux Status\n"
				"Heizung State"
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
				"Ovikytkin2",
				"Zundschlussel\n"
				"Heizgebl. Geschw.\n"
				"Notfall Schalt.\n"
				"Batt. Spannung\n"
				"Eber Geblase\n"
				"Sitzschalter\n"
				"Turschalter 1\n"
				"Turschalter 2"
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
				"Ilmastointi",
				"Gesamtspannung\n"
				"Arbeitslicht Status\n"
				"Fahrlicht Status\n"
				"Rucklicht Status\n"
				"Innenlicht Status\n"
				"Belinklicht Status\n"
				"Wischer Status\n"
				"Kuhler Status"
		},
		{
				"Wiper Speed\n"
				"Cooler P\n"
				"Work Light (mA)\n"
				"Drive Light (mA)",
				"Pyyhin nopeus\n"
				"Ilmastointi P\n"
				"Tyovalot (mA)\n"
				"Ajovalot (mA)",
				"Wischer Geschw.\n"
				"Kuhler P\n"
				"Arbeitslicht (mA)\n"
				"Fahrlicht (mA)"
		},
		{
				"Controls moved\n"
				"Engine shut down\n"
				"Implement\n"
				"Legs Down\n"
				"Pressure (bar)",
				"Ohjaus tila\n"
				"Moottori tila\n"
				"Tyolaite\n"
				"Jalat alhaalla\n"
				"Paine (bar)",
				"Steuerung benutzt\n"
				"Motor abschalten\n"
				"Arbeitsmaschine\n"
				"Stutze unten\n"
				"Druck (bar)"
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
				"Tyolaite (mA)",
				"Ausleger Hebung (mA)\n"
				"Ausleger Faltung (mA)\n"
				"Ausleger Drehung (mA)\n"
				"Fahrt (mA)\n"
				"Lenkung (mA)\n"
				"Linke Stutze (mA)\n"
				"Rechte Stutze (mA)\n"
				"Arbeitsmaschine (mA)"
		},
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
			"Hytin Pyoritys (mA)",
			"Ausleger Hebung (mA)\n"
			"Ausleger Faltung (mA)\n"
			"Ausleger Drehung (mA)\n"
			"Fahrt (mA)\n"
			"Lenkung (mA)\n"
			"Verlangerung (mA)\n"
			"Linke Stutze (mA)\n"
			"Rechte Stutze (mA)\n"
			"Kabine Drehung (mA)"
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
				"Hytin Pyoritys (mA)",
				"Ausleger Hebung (mA)\n"
				"Ausleger Faltung (mA)\n"
				"Ausleger Drehung (mA)\n"
				"Verlangerung (mA)\n"
				"Fahrt (mA)\n"
				"Lenkung (mA)\n"
				"Hintere Steuerung (mA)\n"
				"Linke Stutze (mA)\n"
				"Rechte Stutze (mA)\n"
				"Kabine Drehung (mA)"

		},
#endif
		{
				"x\nx err\ny\ny err\nz\nz err\nv\nv err",
				"x\nx err\ny\ny err\nz\nz err\nv\nv err",
				"x\nx err\ny\ny err\nz\nz err\nv\nv err"
		},
		{
				"b1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nb9\nb10",
				"b1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nb9\nb10",
				"b1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nb9\nb10"
		},
		{
				"Position",
				"Asento",
				"Position"
		},
		{
				"",
				"",
				""
		},
		{
				"",
				"",
				""
		},
		{
				"",
				"",
				""
		},
		{
				"Length\nWidth\nVolume\nRel width\n\nWSensor 1\nWSensor 2",
				"Pituus\nPaksuus\nTilavuus\nSuht paksuus\n\nWAnturi 1\nWAnturi 2",
				"Lange\nDurchm.\nVolumen\nRel Durchm.\n\nWSensor 1\nWSensor 2"
		},
		{
				"",
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
