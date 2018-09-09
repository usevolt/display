EESchema Schematic File Version 4
LIBS:display-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3800 2500 0    50   BiDi ~ 0
SDA
Text HLabel 3800 2400 0    50   BiDi ~ 0
SCL
Wire Wire Line
	3800 2500 4050 2500
Wire Wire Line
	5100 2400 4350 2400
Wire Wire Line
	4050 2300 4050 2500
Connection ~ 4050 2500
Wire Wire Line
	4050 2500 5100 2500
Wire Wire Line
	4350 2300 4350 2400
Connection ~ 4350 2400
Wire Wire Line
	4350 2400 3800 2400
Wire Wire Line
	4050 1650 4050 1800
Wire Wire Line
	4050 1800 4350 1800
Wire Wire Line
	4350 1800 4350 2000
Connection ~ 4050 1800
Wire Wire Line
	4050 1800 4050 2000
Wire Wire Line
	4750 2650 4750 2200
Wire Wire Line
	4750 2200 5100 2200
Wire Wire Line
	5100 2300 5050 2300
Wire Wire Line
	5050 2300 5050 3100
Wire Wire Line
	5050 3100 4750 3100
Connection ~ 4750 3100
Wire Wire Line
	5750 2500 6000 2500
Wire Wire Line
	6000 2600 6000 2500
Connection ~ 6000 2500
Wire Wire Line
	6000 2500 6250 2500
Wire Wire Line
	6550 2500 6600 2500
Wire Wire Line
	6600 2500 6600 2400
Wire Wire Line
	6600 2400 5750 2400
$Comp
L yageo:1K R701
U 1 1 5B04FEE7
P 4050 2100
F 0 "R701" V 4058 2158 45  0000 L CNN
F 1 "1K" V 4142 2158 45  0000 L CNN
F 2 "yageo:0603" H 4080 2250 20  0001 C CNN
F 3 "" H 4019 2139 60  0001 C CNN
F 4 "" H 4419 2539 60  0001 C CNN "1st Source Part Number"
F 5 "Digikey" H 4319 2439 60  0001 C CNN "1st Source"
F 6 "RC0603FR-071KL" H 4219 2339 60  0001 C CNN "Manufacturer Part Number"
F 7 "YAGEO" H 4119 2239 60  0001 C CNN "Manufacturer"
	1    4050 2100
	0    1    1    0   
$EndComp
$Comp
L yageo:1K R702
U 1 1 5B04FF41
P 4350 2100
F 0 "R702" V 4358 2158 45  0000 L CNN
F 1 "1K" V 4442 2158 45  0000 L CNN
F 2 "yageo:0603" H 4380 2250 20  0001 C CNN
F 3 "" H 4319 2139 60  0001 C CNN
F 4 "" H 4719 2539 60  0001 C CNN "1st Source Part Number"
F 5 "Digikey" H 4619 2439 60  0001 C CNN "1st Source"
F 6 "RC0603FR-071KL" H 4519 2339 60  0001 C CNN "Manufacturer Part Number"
F 7 "YAGEO" H 4419 2239 60  0001 C CNN "Manufacturer"
	1    4350 2100
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 5B04FFCC
P 4050 1650
F 0 "#PWR0108" H 4050 1500 50  0001 C CNN
F 1 "+3V3" H 4065 1823 50  0000 C CNN
F 2 "" H 4050 1650 50  0000 C CNN
F 3 "" H 4050 1650 50  0000 C CNN
	1    4050 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3100 4750 3050
$Comp
L usevolt:BATTERY_HOLDER_CH7410-2032LFSMD BT701
U 1 1 5B0504C6
P 4750 3050
F 0 "BT701" H 4888 3250 45  0000 L CNN
F 1 "BATTERY_HOLDER_CH7410-2032LFSMD" H 4750 3050 45  0001 L BNN
F 2 "usevolt:BATTERY_HOLDER_CH7410-2032LF" H 4780 3200 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1505862.pdf?_ga=1.251637318.1948984246.1460023966" H 4800 3450 60  0001 C CNN
F 4 "2064724" H 5000 3650 60  0001 C CNN "Manufacturer Part Number"
F 5 "CH7410-2032LF" H 5200 3850 60  0001 C CNN "1st Source Part Number"
F 6 "Farnell" H 5100 3750 60  0001 C CNN "1st Source"
F 7 "MULTICOMP" H 4900 3550 60  0001 C CNN "Manufacturer"
	1    4750 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5B05055C
P 4750 3300
F 0 "#PWR0109" H 4750 3050 50  0001 C CNN
F 1 "GND" H 4755 3127 50  0000 C CNN
F 2 "" H 4750 3300 50  0000 C CNN
F 3 "" H 4750 3300 50  0000 C CNN
	1    4750 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3100 4750 3300
$Comp
L power:GND #PWR0110
U 1 1 5B0507D3
P 6000 3150
F 0 "#PWR0110" H 6000 2900 50  0001 C CNN
F 1 "GND" H 6005 2977 50  0000 C CNN
F 2 "" H 6000 3150 50  0000 C CNN
F 3 "" H 6000 3150 50  0000 C CNN
	1    6000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2900 6000 3150
$Comp
L usevolt:XTAL_ABS25-32.768KHZ-T X701
U 1 1 5B050BA9
P 6450 2500
F 0 "X701" H 6400 2724 45  0000 C CNN
F 1 "XTAL_ABS25-32.768KHZ-T" H 6400 2640 45  0000 C CNN
F 2 "usevolt:XTAL_32.768KHZ-T" H 6480 2650 20  0001 C CNN
F 3 "http://www.abracon.com/Resonators/abs25.pdf" H 6470 2520 60  0001 C CNN
F 4 "1611824" H 7070 3120 60  0001 C CNN "2nd Source Part Number"
F 5 "535-9166-1-ND" H 6870 2920 60  0001 C CNN "1st Source Part Number"
F 6 "Abracon LLC" H 6570 2620 60  0001 C CNN "Manufacturer"
F 7 "ABS25-32.768KHZ-T" H 6670 2720 60  0001 C CNN "Manufacturer Part Number"
F 8 "Digi-Key" H 6770 2820 60  0001 C CNN "1st Source"
F 9 "Farnell" H 6970 3020 60  0001 C CNN "2nd Source"
	1    6450 2500
	1    0    0    -1  
$EndComp
$Comp
L kemet:18pF C701
U 1 1 5B051E8D
P 6000 2700
F 0 "C701" V 6008 2773 45  0000 L CNN
F 1 "18pF" V 6092 2773 45  0000 L CNN
F 2 "kemet:0603" H 6030 2850 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2111569.pdf?_ga=1.260538573.1948984246.1460023966" H 5904 2709 60  0001 C CNN
F 4 "1865514" H 6304 3109 60  0001 C CNN "1st Source Part Number"
F 5 "C0603C180J2GACTU" H 6104 2909 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 6204 3009 60  0001 C CNN "1st Source"
F 7 "KEMET" H 6004 2809 60  0001 C CNN "Manufacturer"
	1    6000 2700
	0    1    1    0   
$EndComp
$Comp
L usevolt:RTC_S-35390A-J8T1G U701
U 1 1 5B052658
P 5400 2300
F 0 "U701" H 5425 2625 50  0000 C CNN
F 1 "RTC_S-35390A-J8T1G" H 5425 2534 50  0000 C CNN
F 2 "usevolt:SOIC8" H 5500 2800 50  0001 C CNN
F 3 "http://datasheet.sii-ic.com/en/real_time_clock/S35390A_E.pdf" H 5600 2950 50  0001 C CNN
F 4 "ABLIC U.S.A. Inc." H 5450 2750 50  0001 C CNN "Manufacturer"
F 5 "S-35390A-J8T1G" H 5550 2850 50  0001 C CNN "Manufacturer Part Number"
F 6 "Digikey" H 5650 2950 50  0001 C CNN "1st Source"
F 7 "728-1006-1-ND" H 5800 2950 50  0001 C CNN "1st Source Part Number"
	1    5400 2300
	1    0    0    -1  
$EndComp
$EndSCHEMATC