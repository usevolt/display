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
				"Svenska"
		},
		{
				"Back",
				"Takaisin",
				"Tillbaka"
		},
		{
				"Cancel",
				"Hylkaa",
				"Avbryt"
		},
		{
				"Save",
				"Tallenna",
				"Spara"
		},
		{
				"OK",
				"OK",
				"OK"
		},
		{
				"Dashboard",
				"Paneeli",
				"Instrumentbrada"
		},
		{
				"Settings",
				"Asetukset",
				"Installningar"
		},
		{
				"System",
				"Jarjestelma",
				"Systemet"
		},
		{
				"Log Out",
				"Kirjaudu\nulos",
				"Logga ut"
		},
		{
				"Select Driver",
				"Valitse kuljettaja",
				"Valj operator"
		},
		{
				"Log In",
				"Kirjaudu",
				"Logga in"
		},
		{
				"Add User",
				"Lisaa kujettaja",
				"Lagg till anvandare"
		},
		{
				"Copy User",
				"Kopioi kujettaja",
				"Kopiera anvandare"
		},
		{
				"Delete User",
				"Poista kuljettaja",
				"Radera anvandare"
		},
		{
				"Target Length:",
				"Tavoitepituus:",
				"Mallängd"
		},
		{
				"Length (cm)",
				"Pituus (cm)",
				"Langd (cm)"
		},
		{
				"Diameter (mm)",
				"Halkaisija (mm)",
				"Diameter (mm)"
		},
		{
				"Volume (m3)",
				"Tilavuus (m3)",
				"Volym (m3)"
		},
		{
				"Hours",
				"Tunnit",
				"Timmar"
		},
		{
				"Water",
				"Jaahdytyvesi",
				"Vatten"
		},
		{
				"Oil Press",
				"Oljyn paine",
				"Oljetryck"
		},
		{
				"Alternator",
				"Laturi",
				"Omformare"
		},
		{
				"Glow Plugs",
				"Hehku",
				"Glodstift"
		},
		{
				"EMCY",
				"EMCY",
				"EMCY"
		},
		{
				"Door",
				"Ovi",
				"Dorr"
		},
		{
				"Seat",
				"Istuin",
				"Stol"
		},
		{
				"Gear",
				"Vaihde",
				"Vaxel"
		},
		{
				"Horn",
				"Torvi",
				"Horn"
		},
		{
				"Wiper",
				"Pyyhin",
				"Torkare"
		},
		{
				"Heat",
				"Lampo",
				"Varm"
		},
		{
				"Bat V",
				"Akku",
				"Bat V"
		},
		{
				"Fuel L",
				"DieselM",
				"Bransle"
		},
		{
				"OIL L",
				"OljyM",
				"Olja"
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
				"Klicka for att stanga"
		},
		{
				"Click to go to the log",
				"Paina mennaksesi lokiin",
				"Klicka for att ga till loggen"
		},
		{
				"General",
				"Yleiset",
				"Allman"
		},
		{
				"System",
				"Jarjestelma",
				"Systemet"
		},
		{
				"Select Implement",
				"Tyolaite",
				"Valj verktyg"
		},
		{
				"Date and Time",
				"Paivamaara ja kellonaika",
				"Datum och tid"
		},
		{
				"Language",
				"Kieli",
				"Sprak"
		},
		{
				"Drive Light",
				"Ajovalot",
				"Kor lampa"
		},
		{
				"Work Light",
				"Tyovalot",
				"Arbete lampa"
		},
		{
				"Engine power\noutput (%)",
				"Moottorin tehon\nanto (%)",
				"Motoreffekt (%)"
		},
		{
				"Screen Brightness",
				"Nayton kirkkaus",
				"Displayens ljusstyrka"
		},
		{
				"Drive Forward\ncompensation",
				"Ajo eteen\nkompensointi",
				"kor framat\nersattning"
		},
		{
				"Drive Backward\ncompensation",
				"Ajo taakse\nkompensointi",
				"kor bakat\nersattning"
		},
		{
				"Oil Cooler\nTrigger Temp",
				"Oljynlauhduttimen\nliipaisulampotila",
				"Oljekylare utlosande\ntemperatur"
		},
		{
				"Set Language\nAnd Reset",
				"Aseta Kieli\nja Kaynnista Uudelleen",
				"stalla in sprak \noch reset"

		},
		{
				"Implement not selected.\n"
				"Select implement from System settings.",
				"Tyolaitetta ei ole valittu.\n"
				"Valitse tyolaite jarjestelma-asetuksista.",
				"Verktyget inte valt.\n"
				"Valj verktyg fran systemmenyn."
		},
		{
				"Go to settings",
				"Siirry asetuksiin",
				"ga till Installningar"
		},
		{
				"Forward Max Speed (mA)",
				"Max nopeus eteen (mA)",
				"Max hastighet framat (mA)"
		},
		{
				"Backward Max Speed (mA)",
				"Max nopeus taakse (mA)",
				"Max hastighet bakat (mA)"
		},
		{
				"Forward Min Speed (mA)",
				"Min nopeus eteen (mA)",
				"Min hastighet framat (mA)"
		},
		{
				"Backward Min Speed (mA)",
				"Min nopeus taakse (mA)",
				"Min hastighet bakat (mA)"
		},
		{
				"Acceleration (%)",
				"Kiihtyvyys (%)",
				"Acceleration (%)"
		},
		{
				"Deceleration (%)",
				"Hidastuvuus (%)",
				"Retardation (%)"
		},
		{
				"Invert Direction",
				"Invertoi suunta",
				"Invertera direktion"
		},
		{
				"System Invert",
				"Jarjestelma suunta",
				"System invert"
		},
		{
				"Rotator",
				"Rotaattori",
				"Rotator"
		},
		{
				"Open / Close",
				"Auki / Kiinni",
				"Oppen / Stanga"
		},
		{
				"Forward\nMax Speed (mA)",
				"Max Nopeus\nEteen (mA)",
				"Max hastighet\nframat (mA)"
		},
		{
				"Backward\nMax Speed (mA)",
				"Max Nopeus\nTaakse (mA)",
				"Max hastighet\nbakat (mA)"
		},
		{
				"Acceleration\n(%)",
				"Kiihtyvyys\n(%)",
				"Acceleration\n(%)"
		},
		{
				"Deceleration\n(%)",
				"Hidastuvuus\n(%)",
				"Retardation\n(%)"
		},
		{
				"Invert\nDirection",
				"Invertoi\nSuunta",
				"Invertera\ndirektion"
		},
		{
				"UW180S General",
				"UW180S Yleiset",
				"UW180S Allman"
		},
		{
				"Rollers grab\ntime (ms)",
				"Rullien\npuristusaika (ms)",
				"Rullar\nhugg tid (ms)"
		},
		{
				"Blades grab\ntime (ms)",
				"Terien\npuristusaika (ms)",
				"Blad\nhugg tid (ms)"
		},
		{
				"Tilt float\nenable",
				"Tiltin kellunta",
				"Tilt flyta\naktivera"
		},
		{
				"Tilt on\nleft thumb",
				"Tiltti\nvasemmalla\npeukalolla",
				"Tilt pa\nvanster tumme"
		},
		{
				"UW180S Valves",
				"UW180S Venttiilit",
				"UW180S Ventiler"
		},
		{
				"Wheels\nopen/close",
				"Rullat\nauki/kiinni",
				"Rullar\noppen/stanga"
		},
		{
				"Feeding",
				"Puun syotto",
				"Rullar rotera"
		},
		{
				"Blades\nopen/close",
				"Terat\nauki/kiinni",
				"Blad\noppen/stanga"
		},
		{
				"Saw",
				"Saha",
				"sag"
		},
		{
				"Tilt",
				"Tiltti",
				"Tilt"
		},
		{
				"Rotator",
				"Rotaattori",
				"Rotator"
		},
		{
				"All Open",
				"Kaikki Auki",
				"Oppen alla"
		},
		{
				"Implement 1",
				"Tyolaite 1",
				"Gerat 1"
		},
		{
				"Implement 2",
				"Tyolaite 2",
				"Verktyg 2"
		},
		{
				"UW180S Measurement",
				"UW180S mittalaite",
				"UW180S Matt system"
		},
		{
				"Enabled",
				"Kaytossa",
				"Aktivera"
		},
		{
				"Log Length 1",
				"Puun pituus 1",
				"Logglangd 1"
		},
		{
				"Log Length 2",
				"Puun pituus 2",
				"Logglangd 2"
		},
		{
				"Length\nCalibration",
				"Pituus\nKalibrointi",
				"Langt\nKalibrering"
		},
		{
				"Volume\nCalibration",
				"Tilavuus\nKalibrointi",
				"Volym\nKalibrering"
		},
		{
				"Note: Calibration values are\n"
				"shared across all users",
				"Huomio: Kalibrointiarvot ovat\n"
				"samat kaikille kayttajille.",
				"Notera: Kalibreringsvarden\n"
				"delas mellan alla anvandare."
		},
		{
				"Reset\nVolume",
				"Tilavuuden\nnollaus",
				"Reset\nvolym"
		},
		{
				"Width\nCalibration",
				"Paksuus\nkalibrointi",
				"Bredd\nKalibrering"
		},
		{
				"UW180S Width Calibration",
				"UW180S Paksuus kalibrointi",
				"UW180S Bredd Kalibrering"
		},
		{
				"General",
				"Yleiset",
				"Allman"
		},
		{
				"Log\nMeasurement",
				"Mittalaite",
				"loggmatning"
		},
		{
				"Valve\nConfigurations",
				"Venttiili-\nasetukset",
				"Ventil\nKonfigurationer"
		},
		{
				"General",
				"Yleiset",
				"Allman"
		},
		{
				"Valve\nConfigurations",
				"Venttiilen\nKonfigurointi",
				"Ventil\nKonfigurationer"
		},
		{
				"Implement\nSettings",
				"Tyolaitteen\nAsetukset",
				"Verktyg\nKonfigurationer."
		},
		{
				"Settings",
				"Asetukset",
				"Installningar"
		},
		{
				"Boom Lift",
				"Puomi nosto",
				"Ausleger heben"
		},
		{
				"Boom Fold",
				"Puomi Taitto",
				"Kran lyft"
		},
		{
				"Boom Rotate",
				"Puomi kaanto",
				"Kran rotera"
		},
		{
				"Boom Telescope",
				"Puomi Teleskooppi",
				"Kran teleskop"
		},
		{
				"Gear 1",
				"Vaihde 1",
				"Vaxel 1"
		},
		{
				"Gear 2",
				"Vaihde 2",
				"Vaxel 2"
		},
		{
				"Gear 3",
				"Vaihde 3",
				"Vaxel 3"
		},
		{
				"Steer",
				"Ohjaus",
				"Styrning"
		},
		{
				"Back Steering",
				"Takaohjaus",
				"bakre styrning"
		},
		{
				"Loading Space Telescope",
				"Kuormatilan teleskooppi",
				"laddar utrymme teleskop"
		},
		{
				"Left Leg",
				"Vasen Tukijalka",
				"Vanster ben"
		},
		{
				"Right Leg",
				"Oikea Tukijalka",
				"Hoger ben"
		},
		{
				"Cabin Rotate",
				"Hytin Pyoritys",
				"Hytten rotera"
		},
		{
				"Trailer drive",
				"Karry ajo",
				"Trailer koring"
		},
		{
				"Trailer telescope",
				"Karry teleskooppi",
				"Trailer teleskop"
		},
		{
				"RPM",
				"RPM",
				"RPM"
		},
		{
				"Pressure",
				"Paine",
				"Tryck"
		},
		{
				"System\nDiagnostics",
				"Jarjestelman\nDiagnostiikka",
				"systemdiagnostik"
		},
		{
				"Log",
				"Loki",
				"Log"
		},
		{
				"System\nCalibration",
				"Jarjestelman\nKalibrointi",
				"systemkalibrering"
		},
		{
				"System\nRestore",
				"Tehdasasetusten\nPalautus",
				"WerkS"
				"system\naterstallning"
		},
		{
				"\x11\x16 Select a log entry to acknowledge",
				"\x11\x16 Valitse kuitattava lokitieto",
				"\x11\x16 Valj en post for att bekrafta"
		},
		{
				"Acknowledge",
				"Kuittaa",
				"Erkanna"
		},
		{
				"Previous Page",
				"Edellinen sivu",
				"Foregaende sida"
		},
		{
				"Next Page",
				"Seuraava sivu",
				"Nasta sida"
		},
		{
				"Page %u/%u",
				"Sivu %u/%u",
				"Sidan %u/%u"
		},
		{
				"UW180S Measurement calibration",
				"UW180S Mittalaitteen kalibrointi",
				"UW180S Matkalibrering"
		},
		{
				"Calibrate\nMIN angles",
				"Kalibroi\nMIN kulmat",
				"Kalibrera\nMIN vinklar"
		},
		{
				"Calibrate\nMAX angles",
				"Kalibroi\nMAX kulmat",
				"Kalibrera\nMAX vinklar"
		},
		{
				"Joystick\nCalibration",
				"Ohjainkahvojen\nKalibrointi",
				"Joystick\nKalibrering"
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
				"Vanster:\n"
				"x max\n"
				"x mitten\n"
				"x min\n \n"
				"Hoger:\n"
				"x max\n"
				"x mitten\n"
				"x min"
		},
		{
				"To calibrate the joysticks,\n"
				"rotate through all of their axes and thumb switches",
				"Kalibroi ohjauskahvat kaantamalla kahvaa siten,\n"
				"etta kaikkien akseleiden minimi ja maksimiarvot mitataan.",
				"For att kalibrera joysticken, rotera genom\n"
				"alla deras axlar och tumomkopplare"
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
				"Tryck pa knappen nedan i " STRINGIFY(RESTORE_DELAY_S) " sekunder for\n"
				"att aterstalla systemet till fabriksinstallningar.\n"
				"Displayen startar om efter aterstallningen.\n \n"
				"VARNING: ALLA INSTALLNINGAR FRAN ALLA ANVANDARE KOMMER ATT TAPPAS"
		},
		{
				"Restore System Defaults",
				"Palauta tehdasasetukset",
				"Aterstall standardinstallningar"
		},
		{
				"Left Keypad",
				"Vasen Nappaimisto",
				"Vanster knappsats"
		},
		{
				"Right Keypad",
				"Oikea Nappaimisto",
				"Hoger knappsats"
		},
		{
				"Pedal",
				"Poljin",
				"Trampa"
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
				"HCU",
				"HCU",
				"HCU"
		},
		{
				"CCU",
				"CCU",
				"CCU"
		},
		{
				"ICU",
				"ICU",
				"ICU"
		},
		{
				"Connected\n"
				"Node ID",
				"Yhteys\n"
				"Node ID",
				"förbindelse\n"
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
				"Total strom\n"
				"Gluhstatus\n"
				"Glodstift stat\n"
				"startmotor stat\n"
				"MStart1 stat\n"
				"MStart2 stat\n"
				"hydraulpump Stat\n"
				"Omformare IG stat\n"
				"Oljekylare Stat\n"
				"Pump Vinkel (ppt)"
		},
		{
				"RPM\n"
				"Alt L\n"
				"Motor Water\n"
				"Motor Oil\n"
				"Motor Temp. (C)\n"
				"Oil Temp (C)\n"
				"Oil Level (%)\n"
				"Voltage (mV)\n"
				"Radiator state\n"
				"Stop cause\n",
				"RPM\n"
				"Laturi L\n"
				"Jaahdytinneste\n"
				"Moottorioljy\n"
				"Moottori T (C)\n"
				"Oljy T (C)\n"
				"Oljy M (%)\n"
				"Jannite (mV)\n"
				"Lauhdutin raja(C)\n"
				"Pysahdys syy",
				"RPM\n"
				"omformare L\n"
				"Motor vatten\n"
				"Motor olja\n"
				"Motor temp (C)\n"
				"Olja temp (C)\n"
				"Oljens hojd (%)\n"
				"Spanning (mV)\n"
				"Radiator temp (C)\n"
				"Sluta orsak"
		},
		{
				"Total current\n"
				"Horn State\n"
				"Radio State\n"
				"Aux State\n"
				"Heater State",
				"Virta yhteensa\n"
				"Torvi\n"
				"Radio\n"
				"Tupakansytytin\n"
				"Lammitin",
				"Total strom\n"
				"Horn Stat\n"
				"Radio Stat\n"
				"Aux Stat\n"
				"Värmare Stat"
		},
		{
				"Ignition key\n"
				"Heater Speed\n"
				"EMCY switch\n"
				"Bat Voltage\n"
				"Eber Fan\n"
				"Seat\n"
				"Door1\n"
				"Door2\n"
				"Fuel level",
				"Virta-avain\n"
				"Lammitin\n"
				"Hataseis\n"
				"Akku\n"
				"Eber tuuletin\n"
				"Penkkikytkin\n"
				"Ovikytkin1\n"
				"Ovikytkin2\n"
				"Polttoaine",
				"Startnyckel\n"
				"Varmare hastighet\n"
				"EMCY\n"
				"Batt. Spanning\n"
				"Eber flakt\n"
				"Stol\n"
				"Dorr 1\n"
				"Dorr 2\n"
				"Dieselhojd (%)"
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
				"Total strom\n"
				"Arbetsbelysning Stat\n"
				"Korbelysning Stat\n"
				"Bakbelysning Stat\n"
				"Inomlysning Stat\n"
				"Fyr Stat\n"
				"Torkare Stat\n"
				"Luftkond Stat"
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
				"torkarhastighet\n"
				"Luftkond P\n"
				"Arbetsbelysning (mA)\n"
				"Korbelysning (mA)"
		},
		{
				"Implement\n"
				"Left Leg State\n"
				"Right Leg State\n"
				"Pressure (bar)",
				"Vasen jalka\n"
				"Oikea jalka\n"
				"Paine (bar)",
				"Verktyg\n"
				"Vanster ben stat\n"
				"Hoger ben stat\n"
				"Truck (bar)"
		},
		{
				"Boom Lift (mA)\n"
				"Boom Fold (mA)\n"
				"Boom Rotate (mA)\n"
				"Boom Telescope (mA)\n"
				"Left Leg (mA)\n"
				"Right Leg (mA)\n"
				"Rotator (mA)\n"
				"Impl1 (mA)\n"
				"Impl2 (mA)",

				"Puomi Nosto (mA)\n"
				"Puomi Taitto (mA)\n"
				"Puomi Kaanto (mA)\n"
				"Puomi Tel (mA)\n"
				"Vasen Jalka (mA)\n"
				"Oikea Jalka (mA)\n"
				"Rotaattori (mA)\n"
				"Tyolaite1 (mA)\n"
				"Tyolaite2 (mA)",

				"Kran lyft (mA)\n"
				"Kran vik (mA)\n"
				"Kran roterar (mA)\n"
				"Kran teleskop (mA)\n"
				"Vanster ben (mA)\n"
				"Hoger ben (mA)\n"
				"Rotator (mA)\n"
				"Verktyg1 (mA)\n"
				"Verktyg2 (mA)"
		},
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
				"Placera"
		},
		{
				"",
				"",
				""
		},
		{
				"Cabin Dir\n"
				"Boom VDD state\n"
				"Boom VDD (mA)\n"
				"Gear",
				"Ohjaamo suunta\n"
				"Puomi VDD\n"
				"Puomi VDD (mA)\n"
				"Vaihde",
				"kabinriktning\n"
				"Kran VDD stat\n"
				"Kran VDD (mA)\n"
				"Vaxlan"
		},
		{
				"Drive1 (mA)\n"
				"Drive2 (mA)\n"
				"Drive3 (mA)\n"
				"brake (mA)\n"
				"Cabin brake (mA)\n"
				"Cabin Rot (mA)\n"
				"Telescope (mA)\n"
				"Steer (mA)\n"
				"Gear3 (mA)",

				"Ajo1 (mA)\n"
				"Ajo2 (mA)\n"
				"Ajo3 (mA)\n"
				"Jarru (mA)\n"
				"Hytti jarru (mA)\n"
				"Hytti kaanto (mA)\n"
				"Jatke (mA)\n"
				"Ohjaus (mA)\n"
				"3. vaihde(mA)",

				"Kor1 (mA)\n"
				"Kor2 (mA)\n"
				"Kor3 (mA)\n"
				"Broms (mA)\n"
				"Kabin broms (mA)\n"
				"Kabin rotate (mA)\n"
				"Teleskop (mA)\n"
				"Styrning (mA)\n"
				"Vaxlen3 (mA)"
		},
		{
				"Length\n"
				"Width\n"
				"Volume\n"
				"Rel width\n"
				"\n"
				"WSensor 1\n"
				"WSensor 2\n"
				"Saw in",

				"Pituus\n"
				"Paksuus\n"
				"Tilavuus\n"
				"Suht paksuus\n"
				"\n"
				"WAnturi 1\n"
				"WAnturi 2\n"
				"Saha kotona",

				"Langd\n"
				"Bredd\n"
				"Volym\n"
				"Rel bredd\n"
				"\n"
				"BSensor 1\n"
				"BSensor 2\n"
				"Saq inom"
		},
		{
				"Blades (mA)\n"
				"Feed open (mA)\n"
				"Tilt (mA)\n"
				"Saw (mA)\n"
				"Feed (mA)\n"
				"Tilt float (mA)\n"
				"Tilt dir",

				"Terat (mA)\n"
				"Rullat auki (mA)\n"
				"Tiltti (mA)\n"
				"Saha (mA)\n"
				"Rullat (mA)\n"
				"Tiltti kellunta (mA)\n"
				"Tiltin suunta",

				"Blad (mA)\n"
				"Rullar oppen (mA)\n"
				"Tilt (mA)\n"
				"Saq (mA)\n"
				"Rullar rotera (mA)\n"
				"Tilt flyta (mA)\n"
				"Tilt dir"
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
