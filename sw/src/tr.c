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
				"Mallangd"
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
				"Generator"
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
				"Tuta"
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
				"Olja T"
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
				"System"
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
				"Korljus"
		},
		{
				"Work Light",
				"Tyovalot",
				"Arbetsljus"
		},
		{
				"Engine power\noutput (%)",
				"Moottorin tehon\nanto (%)",
				"Motoreffekt (%)"
		},
		{
				"Screen Brightness",
				"Nayton kirkkaus",
				"Skarmens ljusstyrka"
		},
		{
				"Drive Forward\ncompensation",
				"Ajo eteen\nkompensointi",
				"kor framat\nkompensering"
		},
		{
				"Drive Backward\ncompensation",
				"Ajo taakse\nkompensointi",
				"kor bakat\nkompensering"
		},
		{
				"Oil Cooler\nTrigger Temp",
				"Oljynlauhduttimen\nliipaisulampotila",
				"Oljekylare utlosande\ntemperatur"
		},
		{
				"Set Language\nAnd Reset",
				"Aseta Kieli\nja Kaynnista Uudelleen",
				"stalla in sprak \noch aterstall"

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
				"ga till installningar"
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
				"Invertera riktning"
		},
		{
				"System Invert",
				"Jarjestelma suunta",
				"System invertera"
		},
		{
				"Rotator",
				"Rotaattori",
				"Rotator"
		},
		{
				"Open / Close",
				"Auki / Kiinni",
				"Oppen / Stangd"
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
				"Invertera\nriktning"
		},
		{
				"UW180S General",
				"UW180S Yleiset",
				"UW180S Allman"
		},
		{
				"Rollers grab\ntime (ms)",
				"Rullien\npuristusaika (ms)",
				"Rullar\ngriptid (ms)"
		},
		{
				"Blades grab\ntime (ms)",
				"Terien\npuristusaika (ms)",
				"Blad\ngriptid (ms)"
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
				"Rullar\noppna/stanga"
		},
		{
				"Feeding",
				"Puun syotto",
				"Matning"
		},
		{
				"Blades\nopen/close",
				"Terat\nauki/kiinni",
				"Blad\noppna/stanga"
		},
		{
				"Saw",
				"Saha",
				"Sag"
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
				"Oppna alla"
		},
		{
				"Implement 1",
				"Tyolaite 1",
				"Verktyg 1"
		},
		{
				"Implement 2",
				"Tyolaite 2",
				"Verktyg 2"
		},
		{
				"UW180S Measurement",
				"UW180S mittalaite",
				"UW180S Matsystem"
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
				"Langd\nKalibrering"
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
				"Nollstall\nvolym"
		},
		{
				"Width\nCalibration",
				"Paksuus\nkalibrointi",
				"Bredd\nKalibrering"
		},
		{
				"UW180S Width Calibration",
				"UW180S Paksuus kalibrointi",
				"UW180S Breddkalibrering"
		},
		{
				"General",
				"Yleiset",
				"Allman"
		},
		{
				"Log\nMeasurement",
				"Mittalaite",
				"Loggmatning"
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
				"Kranlyft"
		},
		{
				"Boom Fold",
				"Puomi Taitto",
				"Kran vik"
		},
		{
				"Boom Rotate",
				"Puomi kaanto",
				"Kranrotation"
		},
		{
				"Boom Telescope",
				"Puomi Teleskooppi",
				"Kranteleskop"
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
				"Bakre styrning"
		},
		{
				"Loading Space Telescope",
				"Kuormatilan teleskooppi",
				"Lastutrymme teleskop"
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
				"Hyttrotation"
		},
		{
				"Trailer drive",
				"Karry ajo",
				"Trailer drivning"
		},
		{
				"Trailer telescope",
				"Karry teleskooppi",
				"Trailerteleskop"
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
				"Systemkalibrering"
		},
		{
				"System\nRestore",
				"Tehdasasetusten\nPalautus",
				"WerkS"
				"System\naterstallning"
		},
		{
				"\x11\x16 Select a log entry to acknowledge",
				"\x11\x16 Valitse kuitattava lokitieto",
				"\x11\x16 Valj en post for att bekrafta"
		},
		{
				"Acknowledge",
				"Kuittaa",
				"Bekrafta"
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
				"Sida %u/%u"
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
				"Aterstall till standardinstallningar"
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
				"Forbindelse\n"
				"Node ID"
		},
		{
				"Total Current\n"
				"Glow State\n"
				"Starter State\n"
				"AC State\n"
				"Engine Main State\n"
				"Engine Start State\n"
				"Hydr.Pump State\n"
				"Engine IG State\n"
				"Oil cooler State\n"
				"Pump angle (ppt)",
				"Virta yhteensa\n"
				"Hehkut\n"
				"Starttimoottori\n"
				"Ilmastointi\n"
				"Moottori main\n"
				"Moottori start\n"
				"Hydraulipumppu\n"
				"Moottori IG\n"
				"Oljynlauhdutin\n"
				"Pumpun kulma",
				"Total strom\n"
				"Glodstift\n"
				"Glodstift stat\n"
				"Startmotor stat\n"
				"Motor main stat\n"
				"Motor start stat\n"
				"Hydraulpump Stat\n"
				"Motor IG stat\n"
				"Oljekylare Stat\n"
				"Pumpvinkel (ppt)"
		},
		{
				"RPM\n"
				"Alt L\n"
				"Engine main i\n"
				"Engine start i\n"
				"Motor Temp. (C)\n"
				"Oil Temp (C)\n"
				"Oil Level (%)\n"
				"Voltage (mV)\n"
				"Radiator state\n"
				"Stop cause\n",
				"RPM\n"
				"Laturi L\n"
				"Moottori main i\n"
				"Moottori start i\n"
				"Moottori T (C)\n"
				"Oljy T (C)\n"
				"Oljy M (%)\n"
				"Jannite (mV)\n"
				"Lauhdutin raja(C)\n"
				"Pysahdys syy",
				"RPM\n"
				"Generator L\n"
				"Motor main i\n"
				"Motor start i\n"
				"Motor temp (C)\n"
				"Olja temp (C)\n"
				"Olja niva (%)\n"
				"Spanning (mV)\n"
				"Radiator temp (C)\n"
				"Stop orsak"
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
				"Total spanning\n"
				"Tuta Stat\n"
				"Radio Stat\n"
				"Aux Stat\n"
				"Varmare Stat"
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
				"Batt. spanning\n"
				"Eber flakt\n"
				"Stol\n"
				"Dorr 1\n"
				"Dorr 2\n"
				"Bransleniva (%)"
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
				"Total spanning\n"
				"Arbetsbelysning Stat\n"
				"Korbelysning Stat\n"
				"Bakbelysning Stat\n"
				"Hyttbelysning Stat\n"
				"Varningsljus Stat\n"
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
				"Tryck (bar)"
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
				"Impl2 (mA)\n"
				"4WD (mA)",

				"Puomi Nosto (mA)\n"
				"Puomi Taitto (mA)\n"
				"Puomi Kaanto (mA)\n"
				"Puomi Tel (mA)\n"
				"Vasen Jalka (mA)\n"
				"Oikea Jalka (mA)\n"
				"Rotaattori (mA)\n"
				"Tyolaite1 (mA)\n"
				"Tyolaite2 (mA)\n"
				"4WD (mA)",

				"Kran lyft (mA)\n"
				"Kran vik (mA)\n"
				"Kran rotera (mA)\n"
				"Kran teleskop (mA)\n"
				"Vanster ben (mA)\n"
				"Hoger ben (mA)\n"
				"Rotator (mA)\n"
				"Verktyg1 (mA)\n"
				"Verktyg2 (mA\n"
				"4WD (mA))"
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
				"Position"
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
				"Hyttriktning\n"
				"Kran VDD stat\n"
				"Kran VDD (mA)\n"
				"Vaxel"
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
				"Hyttbroms (mA)\n"
				"Hyttrotation (mA)\n"
				"Teleskop (mA)\n"
				"Styrning (mA)\n"
				"Vaxel3 (mA)"
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
				"Diameter\n"
				"Volym\n"
				"Rel bredd\n"
				"\n"
				"BSensor 1\n"
				"BSensor 2\n"
				"Sag in"
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

				"Knivar (mA)\n"
				"Rullar oppna (mA)\n"
				"Tilt (mA)\n"
				"Sag (mA)\n"
				"Rullar roterar (mA)\n"
				"Tilt flyt (mA)\n"
				"Tilt riktning"
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
