EESchema Schematic File Version 2
LIBS:display-rescue
LIBS:kemet
LIBS:multicomp
LIBS:usevolt
LIBS:wurth_elektronik_LED
LIBS:power
LIBS:elt21300_kicad
LIBS:display-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L HEADER_MOLEX_54104-4031 J301
U 1 1 58FC4B22
P 9550 3250
F 0 "J301" H 9753 2808 60  0000 L CNN
F 1 "HEADER_MOLEX_54104-4031" H 9753 2702 60  0000 L CNN
F 2 "usevolt:HEADER_MOLEX_54104-4031" H 9650 4900 60  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1875244.pdf?_ga=1.223199835.1948984246.1460023966" H 9525 5225 60  0001 C CNN
F 4 "1757126" H 9425 5175 60  0001 C CNN "1st Source Part Number"
F 5 "54104-4031" H 9400 5050 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 9425 5125 60  0001 C CNN "1st Source"
F 7 "MOLEX" H 9425 4975 60  0001 C CNN "Manufacturer"
	1    9550 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1900 9400 1900
Wire Wire Line
	8900 2000 9400 2000
Wire Wire Line
	8800 2100 9400 2100
Wire Wire Line
	4050 2200 9400 2200
Wire Wire Line
	4050 2300 9400 2300
Wire Wire Line
	4050 2400 9400 2400
Wire Wire Line
	4050 2500 9400 2500
Wire Wire Line
	4050 2600 9400 2600
Wire Wire Line
	4050 2700 9400 2700
Wire Wire Line
	4050 2800 9400 2800
Wire Wire Line
	4050 2900 9400 2900
Wire Wire Line
	4050 3000 9400 3000
Wire Wire Line
	4050 3100 9400 3100
Wire Wire Line
	4050 3200 9400 3200
Wire Wire Line
	4050 3300 9400 3300
Wire Wire Line
	4050 3400 9400 3400
Wire Wire Line
	4050 3500 9400 3500
Wire Wire Line
	4050 3600 9400 3600
Wire Wire Line
	4050 3700 9400 3700
Wire Wire Line
	4050 3800 9400 3800
Wire Wire Line
	4050 3900 9400 3900
Wire Wire Line
	4050 4000 9400 4000
Wire Wire Line
	4050 4100 9400 4100
Wire Wire Line
	4050 4200 9400 4200
Wire Wire Line
	4050 4300 9400 4300
Wire Wire Line
	4050 4400 9400 4400
Wire Wire Line
	4050 4500 9400 4500
Wire Wire Line
	8900 4600 9400 4600
Wire Wire Line
	4050 4700 9400 4700
Wire Wire Line
	4050 4800 9400 4800
Wire Wire Line
	4050 4900 9400 4900
Wire Wire Line
	4050 5000 9400 5000
Wire Wire Line
	4050 5100 9400 5100
Wire Wire Line
	9400 5200 9050 5200
Wire Wire Line
	8900 5300 9400 5300
Text Label 9050 1800 0    60   ~ 0
LED-
Text Label 9050 1900 0    60   ~ 0
LED+
Text Label 9050 2000 0    60   ~ 0
GND
Text Label 9050 2200 0    60   ~ 0
R0
Text Label 9050 2300 0    60   ~ 0
R1
Text Label 9050 2400 0    60   ~ 0
R2
Text Label 9050 2500 0    60   ~ 0
R3
Text Label 9050 2600 0    60   ~ 0
R4
Text Label 9050 2700 0    60   ~ 0
R5
Text Label 9050 2800 0    60   ~ 0
R6
Text Label 9050 2900 0    60   ~ 0
R7
Text Label 9050 3000 0    60   ~ 0
G0
Text Label 9050 3100 0    60   ~ 0
G1
Text Label 9050 3200 0    60   ~ 0
G2
Text Label 9050 3300 0    60   ~ 0
G3
Text Label 9050 3400 0    60   ~ 0
G4
Text Label 9050 3500 0    60   ~ 0
G5
Text Label 9050 3600 0    60   ~ 0
G6
Text Label 9050 3700 0    60   ~ 0
G7
Text Label 9050 3800 0    60   ~ 0
B0
Text Label 9050 3900 0    60   ~ 0
B1
Text Label 9050 4000 0    60   ~ 0
B2
Text Label 9050 4100 0    60   ~ 0
B3
Text Label 9050 4200 0    60   ~ 0
B4
Text Label 9050 4300 0    60   ~ 0
B5
Text Label 9050 4400 0    60   ~ 0
B6
Text Label 9050 4500 0    60   ~ 0
B7
Text Label 9050 4600 0    60   ~ 0
GND
Text Label 9050 4700 0    60   ~ 0
CLK
Text Label 9050 4800 0    60   ~ 0
DISP
Text Label 9050 4900 0    60   ~ 0
HSYNC
Text Label 9050 5000 0    60   ~ 0
VSYNC
Text Label 9050 5100 0    60   ~ 0
DE
Text Label 9050 5200 0    60   ~ 0
NC
Text Label 9050 5300 0    60   ~ 0
GND
Text Label 7900 6050 0    60   ~ 0
XL
Text Label 7900 6150 0    60   ~ 0
YD
Text Label 7900 6250 0    60   ~ 0
XR
Text Label 7900 6350 0    60   ~ 0
YU
$Comp
L GND #PWR308
U 1 1 58FC5C8D
P 8900 5800
F 0 "#PWR308" H 8900 5550 50  0001 C CNN
F 1 "GND" H 8905 5627 50  0000 C CNN
F 2 "" H 8900 5800 50  0000 C CNN
F 3 "" H 8900 5800 50  0000 C CNN
	1    8900 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 2000 8900 5800
Connection ~ 8900 5300
Connection ~ 8900 4600
Wire Wire Line
	8800 1500 8800 2100
$Comp
L +3V3 #PWR303
U 1 1 58FC70E1
P 2650 2100
F 0 "#PWR303" H 2650 1950 50  0001 C CNN
F 1 "+3V3" H 2665 2273 50  0000 C CNN
F 2 "" H 2650 2100 50  0000 C CNN
F 3 "" H 2650 2100 50  0000 C CNN
	1    2650 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 2100 2650 2500
Wire Wire Line
	1300 2200 2850 2200
Wire Wire Line
	2650 2300 2850 2300
Connection ~ 2650 2200
Wire Wire Line
	2650 2400 2850 2400
Connection ~ 2650 2300
Wire Wire Line
	2650 2500 2850 2500
Connection ~ 2650 2400
Text HLabel 2450 3200 0    60   Input ~ 0
SCK
Text HLabel 2450 3300 0    60   Output ~ 0
MISO
Text HLabel 2450 3400 0    60   Input ~ 0
MOSI
Text HLabel 2450 3500 0    60   Input ~ 0
CS
Text HLabel 2450 3700 0    60   Input ~ 0
PD
Wire Wire Line
	2450 3700 2850 3700
Wire Wire Line
	2850 3500 2450 3500
Wire Wire Line
	2450 3400 2850 3400
Wire Wire Line
	2850 3300 2450 3300
Wire Wire Line
	2450 3200 2850 3200
$Comp
L GND #PWR304
U 1 1 58FC8063
P 2650 5800
F 0 "#PWR304" H 2650 5550 50  0001 C CNN
F 1 "GND" H 2655 5627 50  0000 C CNN
F 2 "" H 2650 5800 50  0000 C CNN
F 3 "" H 2650 5800 50  0000 C CNN
	1    2650 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5300 2650 5800
Wire Wire Line
	2650 5700 2850 5700
Wire Wire Line
	2650 5600 2850 5600
Connection ~ 2650 5700
Wire Wire Line
	2650 5500 2850 5500
Connection ~ 2650 5600
Wire Wire Line
	2650 5400 2850 5400
Connection ~ 2650 5500
Wire Wire Line
	2650 5300 2850 5300
Connection ~ 2650 5400
$Comp
L 100nF C302
U 1 1 58FC823D
P 1650 2300
F 0 "C302" V 1658 2373 45  0000 L CNN
F 1 "100nF" V 1742 2373 45  0000 L CNN
F 2 "kemet:0603" H 1680 2450 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2062872.pdf?_ga=1.250530118.1948984246.1460023966" H 1554 2309 60  0001 C CNN
F 4 "1288255" H 1954 2709 60  0001 C CNN "1st Source Part Number"
F 5 "C0603C104K5RACTU" H 1754 2509 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 1854 2609 60  0001 C CNN "1st Source"
F 7 "KEMET" H 1654 2409 60  0001 C CNN "Manufacturer"
	1    1650 2300
	0    1    1    0   
$EndComp
$Comp
L 100nF C301
U 1 1 58FC82A4
P 1300 2300
F 0 "C301" V 1308 2373 45  0000 L CNN
F 1 "100nF" V 1392 2373 45  0000 L CNN
F 2 "kemet:0603" H 1330 2450 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2062872.pdf?_ga=1.250530118.1948984246.1460023966" H 1204 2309 60  0001 C CNN
F 4 "1288255" H 1604 2709 60  0001 C CNN "1st Source Part Number"
F 5 "C0603C104K5RACTU" H 1404 2509 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 1504 2609 60  0001 C CNN "1st Source"
F 7 "KEMET" H 1304 2409 60  0001 C CNN "Manufacturer"
	1    1300 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	1300 2500 1650 2500
Connection ~ 1650 2200
$Comp
L GND #PWR301
U 1 1 58FC846A
P 1300 2550
F 0 "#PWR301" H 1300 2300 50  0001 C CNN
F 1 "GND" H 1305 2377 50  0000 C CNN
F 2 "" H 1300 2550 50  0000 C CNN
F 3 "" H 1300 2550 50  0000 C CNN
	1    1300 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 2550 1300 2500
$Comp
L +3V3 #PWR302
U 1 1 5900C7EB
P 1400 3150
F 0 "#PWR302" H 1400 3000 50  0001 C CNN
F 1 "+3V3" H 1415 3323 50  0000 C CNN
F 2 "" H 1400 3150 50  0000 C CNN
F 3 "" H 1400 3150 50  0000 C CNN
	1    1400 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 3150 1400 3250
Wire Wire Line
	1400 3550 1400 3600
Wire Wire Line
	1400 3600 2850 3600
Wire Wire Line
	4050 5200 4700 5200
Text Label 4700 5200 2    60   ~ 0
BACKLIGHT
Wire Wire Line
	6800 1400 5450 1400
Text Label 5450 1400 0    60   ~ 0
BACKLIGHT
Wire Wire Line
	8450 1800 9400 1800
$Comp
L +3V3 #PWR307
U 1 1 590237EC
P 8800 1500
F 0 "#PWR307" H 8800 1350 50  0001 C CNN
F 1 "+3V3" H 8815 1673 50  0000 C CNN
F 2 "" H 8800 1500 50  0000 C CNN
F 3 "" H 8800 1500 50  0000 C CNN
	1    8800 1500
	1    0    0    -1  
$EndComp
$Comp
L FT812 U301
U 1 1 59252681
P 3450 3800
F 0 "U301" H 3450 5647 60  0000 C CNN
F 1 "FT812" H 3450 5541 60  0000 C CNN
F 2 "usevolt:QFN-56" H 3200 5600 60  0001 C CNN
F 3 "http://www.ftdichip.com/Support/Documents/DataSheets/ICs/DS_FT81x.pdf" H 3300 5700 60  0001 C CNN
F 4 "2500981" H 3900 6300 60  0001 C CNN "2nd Source Part Number"
F 5 "768-1259-ND" H 3700 6100 60  0001 C CNN "1st Source Part Number"
F 6 "Digikey" H 3600 6000 60  0001 C CNN "1st Source"
F 7 "Farnell" H 3800 6200 60  0001 C CNN "2nd Source"
F 8 "FT812Q-T" H 3500 5900 60  0001 C CNN "Manufacturer Part Number"
F 9 "FTDI CHIP" H 3400 5800 60  0001 C CNN "Manufacturer"
	1    3450 3800
	1    0    0    -1  
$EndComp
$Comp
L 10K R301
U 1 1 59C66325
P 1400 3350
F 0 "R301" V 1408 3408 45  0000 L CNN
F 1 "10K" V 1492 3408 45  0000 L CNN
F 2 "multicomp:0603" H 1430 3500 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1788326.pdf?_ga=1.214208087.1948984246.1460023966" H 1369 3389 60  0001 C CNN
F 4 "9330399" H 1769 3789 60  0001 C CNN "1st Source Part Number"
F 5 "Farnell" H 1669 3689 60  0001 C CNN "1st Source"
F 6 "MC0063W0603110K" H 1569 3589 60  0001 C CNN "Manufacturer Part Number"
F 7 "MULTICOMP" H 1469 3489 60  0001 C CNN "Manufacturer"
	1    1400 3350
	0    1    1    0   
$EndComp
$Comp
L AL8805W5-7_LED_DRIVER U302
U 1 1 5A0D49FC
P 7100 1400
F 0 "U302" H 7100 1747 60  0000 C CNN
F 1 "AL8805W5-7_LED_DRIVER" H 7100 1641 60  0000 C CNN
F 2 "usevolt:SOT-25" H 7050 1300 60  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2100145.pdf?_ga=1.157560186.1561825231.1484148445" H 7050 1300 60  0001 C CNN
F 4 "1904023" H 7500 2150 60  0001 C CNN "1st Source Part Number"
F 5 "AL8805W5-7" H 7300 1950 60  0001 C CNN "Manufacturer Part Number"
F 6 "AL8805W5-7DICT-ND" H 7700 2350 60  0001 C CNN "2nd Source Part Number"
F 7 "DIGIKEY" H 7600 2250 60  0001 C CNN "2nd Source"
F 8 "DIODES INC" H 7200 1850 60  0001 C CNN "Manufacturer"
F 9 "Farnell" H 7400 2050 60  0001 C CNN "1st Source"
	1    7100 1400
	1    0    0    -1  
$EndComp
$Comp
L 100nF C303
U 1 1 5A0D4AC7
P 6500 1350
F 0 "C303" V 6508 1423 45  0000 L CNN
F 1 "100nF" V 6592 1423 45  0000 L CNN
F 2 "kemet:0603" H 6530 1500 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2062872.pdf?_ga=1.250530118.1948984246.1460023966" H 6404 1359 60  0001 C CNN
F 4 "1288255" H 6804 1759 60  0001 C CNN "1st Source Part Number"
F 5 "C0603C104K5RACTU" H 6604 1559 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 6704 1659 60  0001 C CNN "1st Source"
F 7 "KEMET" H 6504 1459 60  0001 C CNN "Manufacturer"
	1    6500 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 1300 6700 1300
Wire Wire Line
	6700 1300 6700 1250
Wire Wire Line
	6700 1250 6250 1250
Wire Wire Line
	6800 1500 6700 1500
Wire Wire Line
	6700 1500 6700 1550
Wire Wire Line
	6700 1550 6250 1550
$Comp
L GND #PWR306
U 1 1 5A0D4BEC
P 6500 1650
F 0 "#PWR306" H 6500 1400 50  0001 C CNN
F 1 "GND" H 6505 1477 50  0000 C CNN
F 2 "" H 6500 1650 50  0000 C CNN
F 3 "" H 6500 1650 50  0000 C CNN
	1    6500 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 1550 6500 1650
Connection ~ 6500 1550
Connection ~ 6500 1250
Wire Wire Line
	6500 1250 6500 750 
Wire Wire Line
	8250 1300 8250 1900
Wire Wire Line
	7400 1300 8250 1300
$Comp
L R_0.33OHM R302
U 1 1 5A0D50A7
P 7800 1100
F 0 "R302" V 7747 1178 60  0000 L CNN
F 1 "R_0.33OHM" V 7853 1178 60  0000 L CNN
F 2 "usevolt:0603" H 7700 1200 60  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2197344.pdf?_ga=1.191579498.1561825231.1484148445" H 7800 1300 60  0001 C CNN
F 4 "1717766" H 8200 1700 60  0001 C CNN "1st Source Part Number"
F 5 "Digikey" H 8300 1800 60  0001 C CNN "2nd Source"
F 6 "ERJ3RQFR33V" H 8000 1500 60  0001 C CNN "Manufacturer Part Number"
F 7 "Farnell" H 8100 1600 60  0001 C CNN "1st Source"
F 8 "P.33AJCT-ND" H 8400 1900 60  0001 C CNN "2nd Source Part Number"
F 9 "PANASONIC ELECTRONIC COMPONENTS" H 7900 1400 60  0001 C CNN "Manufacturer"
	1    7800 1100
	0    1    1    0   
$EndComp
Connection ~ 7800 1300
$Comp
L DIODE_RS07J-GS18 D301
U 1 1 5A0D515C
P 8450 1100
F 0 "D301" V 8400 1002 45  0000 R CNN
F 1 "DIODE_RS07J-GS18" H 8470 1040 45  0001 L BNN
F 2 "usevolt:DO219AB" H 8480 1250 20  0001 C CNN
F 3 "http://www.vishay.com/docs/85742/rs07b.pdf" H 8470 1120 60  0001 C CNN
F 4 "1864882" H 9070 1720 60  0001 C CNN "2nd Source Part Number"
F 5 "Digi-Key" H 8770 1420 60  0001 C CNN "1st Source"
F 6 "Farnell" H 8970 1620 60  0001 C CNN "2nd Source"
F 7 "RS07J-GS18" H 8670 1320 60  0001 C CNN "Manufacturer Part Number"
F 8 "RS07J-GS18-ND" H 8870 1520 60  0001 C CNN "1st Source Part Number"
F 9 "Vishay Semiconductor Diodes Division" H 8570 1220 60  0001 C CNN "Manufacturer"
	1    8450 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8450 1300 8450 1800
Wire Wire Line
	8450 900  8450 1000
Wire Wire Line
	6500 900  8450 900 
Connection ~ 7800 900 
Connection ~ 6500 900 
$Comp
L IND_744045210 L301
U 1 1 5A0D53A4
P 7750 1500
F 0 "L301" H 7750 1691 45  0000 C CNN
F 1 "IND_744045210" H 7750 1607 45  0000 C CNN
F 2 "usevolt:IND_744045210" H 7780 1650 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1735442.pdf?_ga=1.223184091.1948984246.1460023966" H 7650 1440 60  0001 C CNN
F 4 "1800416" H 8050 1840 60  0001 C CNN "1st Source Part Number"
F 5 "WURTH ELEKTRONIK" H 7750 1540 60  0001 C CNN "Manufacturer"
F 6 "Digi-Key" H 8150 1940 60  0001 C CNN "2nd Source"
F 7 "Farnell" H 7950 1740 60  0001 C CNN "1st Source"
F 8 "744045210" H 7850 1640 60  0001 C CNN "Manufacturer Part Number"
F 9 "732-3072-1-ND" H 8250 2040 60  0001 C CNN "2nd Source Part Number"
	1    7750 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 1500 7400 1500
Wire Wire Line
	7950 1500 8450 1500
Connection ~ 8450 1500
$Comp
L VEE #PWR305
U 1 1 5A0D7248
P 6500 750
F 0 "#PWR305" H 6500 600 50  0001 C CNN
F 1 "VEE" H 6517 923 50  0000 C CNN
F 2 "" H 6500 750 50  0000 C CNN
F 3 "" H 6500 750 50  0000 C CNN
	1    6500 750 
	1    0    0    -1  
$EndComp
$Comp
L HEADER_MOLEX_52207-0433 J302
U 1 1 5A1297ED
P 8250 6150
F 0 "J302" H 8453 6158 60  0000 L CNN
F 1 "HEADER_MOLEX_52207-0433" H 8453 6052 60  0000 L CNN
F 2 "usevolt:HEADER_MOLEX_52207-0433" H 8075 6475 60  0001 C CNN
F 3 "http://www.farnell.com/datasheets/1752208.pdf?_ga=1.260476365.1948984246.1460023966" H 8200 6800 60  0001 C CNN
F 4 "2361288" H 8300 6750 60  0001 C CNN "1st Source Part Number"
F 5 "52207-0433" H 8325 6625 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 8300 6700 60  0001 C CNN "1st Source"
F 7 "MOLEX" H 8300 6550 60  0001 C CNN "Manufacturer"
	1    8250 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 6050 6550 6050
Wire Wire Line
	6550 6050 6550 5400
Wire Wire Line
	6550 5400 4050 5400
Wire Wire Line
	4050 5500 6450 5500
Wire Wire Line
	6450 5500 6450 6150
Wire Wire Line
	6450 6150 8150 6150
Wire Wire Line
	8150 6250 6350 6250
Wire Wire Line
	6350 6250 6350 5600
Wire Wire Line
	6350 5600 4050 5600
Wire Wire Line
	4050 5700 6250 5700
Wire Wire Line
	6250 5700 6250 6350
Wire Wire Line
	6250 6350 8150 6350
$Comp
L CAP_EEE-FK1H470P C304
U 1 1 5A12F27F
P 6250 1450
F 0 "C304" V 6158 1553 45  0000 L CNN
F 1 "CAP_EEE-FK1H470P" V 6300 700 45  0000 L CNN
F 2 "usevolt:CAP_EEE-FK1H470P" H 6280 1600 20  0001 C CNN
F 3 "http://industrial.panasonic.com/www-cgi/jvcr13pz.cgi?E+PZ+3+ABA0120+EEEFK1H470P+7+WW" H 6250 1390 60  0001 C CNN
F 4 "667-EEE-FK1H470P" H 6850 1990 60  0001 C CNN "2nd Source Part Number"
F 5 "Digi-Key" H 6550 1690 60  0001 C CNN "1st Source"
F 6 "EEE-FK1H470P" H 6450 1590 60  0001 C CNN "Manufacturer Part Number"
F 7 "Mouser" H 6750 1890 60  0001 C CNN "2nd Source"
F 8 "Panasonic Electronic Components" H 6350 1490 60  0001 C CNN "Manufacturer"
F 9 "PCE3815CT-ND" H 6650 1790 60  0001 C CNN "1st Source Part Number"
	1    6250 1450
	0    1    1    0   
$EndComp
$EndSCHEMATC
