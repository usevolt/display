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
Sheet 5 6
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
L WINDBOND_W25Q128JVSIQ_SOIC8_W U501
U 1 1 59C65DF2
P 6100 2750
F 0 "U501" H 6200 3104 45  0000 C CNN
F 1 "WINDBOND_W25Q128JVSIQ_SOIC8_W" H 6200 3020 45  0000 C CNN
F 2 "usevolt:SOIC8_W" H 6130 2900 20  0001 C CNN
F 3 "http://www.winbond.com/resource-files/w25q128jv%20spi%20revc%2011162016.pdf" H 5700 2970 60  0001 C CNN
F 4 "Digi-Key" H 6000 3270 60  0001 C CNN "1st Source"
F 5 "W25Q128JVSIQ" H 5900 3170 60  0001 C CNN "Manufacturer Part Number"
F 6 "W25Q128JVSIQ-ND" H 6100 3370 60  0001 C CNN "1st Source Part Number"
F 7 "Winbond Electronics" H 5800 3070 60  0001 C CNN "Manufacturer"
	1    6100 2750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR501
U 1 1 59C661EF
P 5450 3050
F 0 "#PWR501" H 5450 2800 50  0001 C CNN
F 1 "GND" H 5455 2877 50  0000 C CNN
F 2 "" H 5450 3050 50  0000 C CNN
F 3 "" H 5450 3050 50  0000 C CNN
	1    5450 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 3050 5450 2950
Wire Wire Line
	5450 2950 5600 2950
$Comp
L +3V3 #PWR502
U 1 1 59C66208
P 7600 2450
F 0 "#PWR502" H 7600 2300 50  0001 C CNN
F 1 "+3V3" H 7615 2623 50  0000 C CNN
F 2 "" H 7600 2450 50  0000 C CNN
F 3 "" H 7600 2450 50  0000 C CNN
	1    7600 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2650 7600 2650
Wire Wire Line
	7600 2450 7600 2700
$Comp
L 100nF C501
U 1 1 59C66223
P 7600 2800
F 0 "C501" V 7608 2873 45  0000 L CNN
F 1 "100nF" V 7692 2873 45  0000 L CNN
F 2 "kemet:0603" H 7630 2950 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2062872.pdf?_ga=1.250530118.1948984246.1460023966" H 7504 2809 60  0001 C CNN
F 4 "1288255" H 7904 3209 60  0001 C CNN "1st Source Part Number"
F 5 "C0603C104K5RACTU" H 7704 3009 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 7804 3109 60  0001 C CNN "1st Source"
F 7 "KEMET" H 7604 2909 60  0001 C CNN "Manufacturer"
	1    7600 2800
	0    1    1    0   
$EndComp
Connection ~ 7600 2650
$Comp
L GND #PWR503
U 1 1 59C6628B
P 7600 3100
F 0 "#PWR503" H 7600 2850 50  0001 C CNN
F 1 "GND" H 7605 2927 50  0000 C CNN
F 2 "" H 7600 3100 50  0000 C CNN
F 3 "" H 7600 3100 50  0000 C CNN
	1    7600 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 3100 7600 3000
Wire Wire Line
	6800 2850 7100 2850
Text HLabel 7100 2850 2    60   Output ~ 0
CLK
Text HLabel 7100 2950 2    60   Input ~ 0
MOSI
Wire Wire Line
	7100 2950 6800 2950
Text HLabel 5350 2750 0    60   Output ~ 0
MISO
Wire Wire Line
	5350 2750 5600 2750
Wire Wire Line
	5600 2650 5350 2650
Text HLabel 5350 2650 0    60   Input ~ 0
CS
$EndSCHEMATC
