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
Sheet 1 5
Title "UV0A_hds"
Date "2017-04-22"
Rev "1"
Comp "Usevolt Oy"
Comment1 "Olli Usenius"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 2400 1100 1200 600 
U 58FBDAFF
F0 "power_supply" 60
F1 "pwr_supply_sheet.sch" 60
F2 "VIN" I L 2400 1200 60 
F3 "+5V" O R 3600 1400 60 
F4 "+3V3" O R 3600 1600 60 
F5 "GND" I L 2400 1600 60 
F6 "VDD" I R 3600 1300 60 
F7 "VLCD" O R 3600 1200 60 
$EndSheet
$Comp
L GND #PWR01
U 1 1 58FBFAD2
P 1900 2050
F 0 "#PWR01" H 1900 1800 50  0001 C CNN
F 1 "GND" H 1905 1877 50  0000 C CNN
F 2 "" H 1900 2050 50  0000 C CNN
F 3 "" H 1900 2050 50  0000 C CNN
	1    1900 2050
	1    0    0    -1  
$EndComp
$Comp
L 100nF C101
U 1 1 58FBFBBE
P 3050 2600
F 0 "C101" V 3058 2673 45  0000 L CNN
F 1 "100nF" V 3142 2673 45  0000 L CNN
F 2 "kemet:0603" H 3080 2750 20  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2062872.pdf?_ga=1.250530118.1948984246.1460023966" H 2954 2609 60  0001 C CNN
F 4 "1288255" H 3354 3009 60  0001 C CNN "1st Source Part Number"
F 5 "C0603C104K5RACTU" H 3154 2809 60  0001 C CNN "Manufacturer Part Number"
F 6 "Farnell" H 3254 2909 60  0001 C CNN "1st Source"
F 7 "KEMET" H 3054 2709 60  0001 C CNN "Manufacturer"
	1    3050 2600
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 58FC1671
P 3050 2850
F 0 "#PWR02" H 3050 2600 50  0001 C CNN
F 1 "GND" H 3055 2677 50  0000 C CNN
F 2 "" H 3050 2850 50  0000 C CNN
F 3 "" H 3050 2850 50  0000 C CNN
	1    3050 2850
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 58FC16F6
P 3050 2400
F 0 "#PWR03" H 3050 2250 50  0001 C CNN
F 1 "+5V" H 3065 2573 50  0000 C CNN
F 2 "" H 3050 2400 50  0000 C CNN
F 3 "" H 3050 2400 50  0000 C CNN
	1    3050 2400
	-1   0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 58FC1761
P 4000 1400
F 0 "#PWR04" H 4000 1250 50  0001 C CNN
F 1 "+5V" H 4015 1573 50  0000 C CNN
F 2 "" H 4000 1400 50  0000 C CNN
F 3 "" H 4000 1400 50  0000 C CNN
	1    4000 1400
	1    0    0    -1  
$EndComp
$Comp
L +3V3 #PWR05
U 1 1 58FC17CE
P 4150 1600
F 0 "#PWR05" H 4150 1450 50  0001 C CNN
F 1 "+3V3" H 4165 1773 50  0000 C CNN
F 2 "" H 4150 1600 50  0000 C CNN
F 3 "" H 4150 1600 50  0000 C CNN
	1    4150 1600
	1    0    0    -1  
$EndComp
Text Label 1300 2350 0    60   ~ 0
CANH
Text Label 1300 2500 0    60   ~ 0
CANL
$Sheet
S 8050 3200 750  850 
U 58FC4AA8
F0 "TFT-LCD" 60
F1 "tft-lcd.sch" 60
F2 "SCK" I L 8050 3600 60 
F3 "MISO" O L 8050 3400 60 
F4 "MOSI" I L 8050 3500 60 
F5 "CS" I L 8050 3700 60 
F6 "PD" I L 8050 3800 60 
$EndSheet
$Sheet
S 4200 2800 2200 1300
U 58FC1DA6
F0 "lpc1549" 60
F1 "lpc1549.sch" 60
F2 "CAN_RX" I L 4200 3150 60 
F3 "CAN_TX" O L 4200 3250 60 
F4 "LCD_MISO" I R 6400 3400 60 
F5 "LCD_MOSI" O R 6400 3500 60 
F6 "LCD_SCK" O R 6400 3600 60 
F7 "LCD_PD" O R 6400 3800 60 
F8 "LCD_CS" O R 6400 3700 60 
F9 "FLASH_CS" O R 6400 3200 60 
F10 "FLASH_MISO" I R 6400 2900 60 
F11 "FLASH_MOSI" O R 6400 3000 60 
F12 "FLASH_CLK" O R 6400 3100 60 
$EndSheet
Wire Wire Line
	1050 2050 1900 2050
Wire Wire Line
	1900 2050 1900 1600
Wire Wire Line
	1900 1600 2400 1600
Connection ~ 1900 2050
Wire Wire Line
	2950 2700 2950 2800
Wire Wire Line
	2950 2800 3050 2800
Wire Wire Line
	3050 2800 3050 2850
Wire Wire Line
	3050 2400 3050 2500
Wire Wire Line
	3600 1400 4000 1400
Wire Wire Line
	4150 1600 3600 1600
Wire Wire Line
	3050 2500 2950 2500
Wire Wire Line
	2250 2500 1650 2500
Wire Wire Line
	1650 2500 1650 2350
Wire Wire Line
	1650 2350 1050 2350
Wire Wire Line
	1050 2500 1550 2500
Wire Wire Line
	1550 2500 1550 2600
Wire Wire Line
	1550 2600 2250 2600
Wire Wire Line
	4200 3150 2250 3150
Wire Wire Line
	2250 3150 2250 2800
Wire Wire Line
	2250 2700 2150 2700
Wire Wire Line
	2150 2700 2150 3250
Wire Wire Line
	2150 3250 4200 3250
Wire Wire Line
	8050 3400 6400 3400
Wire Wire Line
	6400 3500 8050 3500
Wire Wire Line
	8050 3600 6400 3600
Wire Wire Line
	6400 3700 8050 3700
Wire Wire Line
	8050 3800 6400 3800
Wire Wire Line
	1750 1900 1050 1900
Wire Wire Line
	2400 1200 1750 1200
$Sheet
S 8050 2400 1050 500 
U 59C68158
F0 "Sheet59C68157" 60
F1 "flashmemory.sch" 60
F2 "CLK" O L 8050 2700 60 
F3 "MOSI" I L 8050 2600 60 
F4 "MISO" O L 8050 2500 60 
F5 "CS" I L 8050 2800 60 
$EndSheet
Wire Wire Line
	6400 3200 7200 3200
Wire Wire Line
	7200 3200 7200 2800
Wire Wire Line
	7200 2800 8050 2800
Wire Wire Line
	8050 2700 7100 2700
Wire Wire Line
	7100 2700 7100 3100
Wire Wire Line
	7100 3100 6400 3100
Wire Wire Line
	6400 3000 7000 3000
Wire Wire Line
	7000 3000 7000 2600
Wire Wire Line
	7000 2600 8050 2600
Wire Wire Line
	8050 2500 6900 2500
Wire Wire Line
	6900 2500 6900 2900
Wire Wire Line
	6900 2900 6400 2900
$Comp
L MCP2551_SOIC8 U101
U 1 1 5A0A3632
P 2650 2600
F 0 "U101" H 2700 2904 45  0000 C CNN
F 1 "MCP2551_SOIC8" H 2700 2820 45  0000 C CNN
F 2 "usevolt:SOIC8" H 2530 2750 20  0001 C CNN
F 3 "http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en011797" H 2250 3050 60  0001 C CNN
F 4 "9758569" H 3250 3420 60  0001 C CNN "2nd Source Part Number"
F 5 "Digi-Key" H 2950 3120 60  0001 C CNN "1st Source"
F 6 "Farnell" H 3150 3320 60  0001 C CNN "2nd Source"
F 7 "MCP2551-I/SN" H 2850 3020 60  0001 C CNN "Manufacturer Part Number"
F 8 "MCP2551-I/SN-ND" H 3050 3220 60  0001 C CNN "1st Source Part Number"
F 9 "MICROCHIP" H 2800 2900 60  0001 C CNN "Manufacturer"
	1    2650 2600
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 1 1 5A0C087E
P 950 1900
F 0 "J101" H 978 1882 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 1900 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 2050 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 1870 60  0001 C CNN
F 4 "A106572-ND" H 1650 2470 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 2370 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 2270 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 2070 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 2170 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 1970 60  0001 C CNN "Manufacturer"
	1    950  1900
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 2 1 5A0C0C0A
P 950 2050
F 0 "J101" H 979 2032 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 2050 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 2200 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 2020 60  0001 C CNN
F 4 "A106572-ND" H 1650 2620 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 2520 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 2420 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 2220 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 2320 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 2120 60  0001 C CNN "Manufacturer"
	2    950  2050
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 3 1 5A0C0D57
P 950 2200
F 0 "J101" H 979 2182 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 2200 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 2350 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 2170 60  0001 C CNN
F 4 "A106572-ND" H 1650 2770 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 2670 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 2570 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 2370 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 2470 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 2270 60  0001 C CNN "Manufacturer"
	3    950  2200
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 4 1 5A0C0EAB
P 950 2350
F 0 "J101" H 979 2332 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 2350 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 2500 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 2320 60  0001 C CNN
F 4 "A106572-ND" H 1650 2920 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 2820 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 2720 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 2520 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 2620 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 2420 60  0001 C CNN "Manufacturer"
	4    950  2350
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 5 1 5A0C1002
P 950 2500
F 0 "J101" H 979 2482 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 2500 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 2650 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 2470 60  0001 C CNN
F 4 "A106572-ND" H 1650 3070 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 2970 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 2870 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 2670 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 2770 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 2570 60  0001 C CNN "Manufacturer"
	5    950  2500
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 6 1 5A0C115C
P 950 2650
F 0 "J101" H 978 2632 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 2650 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 2800 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 2620 60  0001 C CNN
F 4 "A106572-ND" H 1650 3220 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 3120 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 3020 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 2820 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 2920 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 2720 60  0001 C CNN "Manufacturer"
	6    950  2650
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 7 1 5A0C12B9
P 950 2800
F 0 "J101" H 979 2782 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 2800 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 2950 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 2770 60  0001 C CNN
F 4 "A106572-ND" H 1650 3370 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 3270 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 3170 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 2970 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 3070 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 2870 60  0001 C CNN "Manufacturer"
	7    950  2800
	-1   0    0    -1  
$EndComp
$Comp
L AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1 J101
U 8 1 5A0C167F
P 950 2950
F 0 "J101" H 979 2932 45  0000 L CNN
F 1 "AMPSEAL_8_POS_VERT_BLACK_SEALED_1-776276-1" H 1050 2950 45  0001 L BNN
F 2 "usevolt:AMPSEAL_8_POS_776275-1" H 980 3100 20  0001 C CNN
F 3 "http://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=776276&DocType=Customer+Drawing&DocLang=English" H 1050 2920 60  0001 C CNN
F 4 "A106572-ND" H 1650 3520 60  0001 C CNN "2nd Source Part Number"
F 5 "Digikey" H 1550 3420 60  0001 C CNN "2nd Source"
F 6 "571-1-776276-1" H 1450 3320 60  0001 C CNN "1st Source Part Number"
F 7 "1-776276-1" H 1250 3120 60  0001 C CNN "Manufacturer Part Number"
F 8 "Mouser" H 1350 3220 60  0001 C CNN "1st Source"
F 9 "TE Connectivity" H 1150 3020 60  0001 C CNN "Manufacturer"
	8    950  2950
	-1   0    0    -1  
$EndComp
$Comp
L VDD #PWR06
U 1 1 5A0D6E53
P 3900 1200
F 0 "#PWR06" H 3900 1050 50  0001 C CNN
F 1 "VDD" H 3917 1373 50  0000 C CNN
F 2 "" H 3900 1200 50  0000 C CNN
F 3 "" H 3900 1200 50  0000 C CNN
	1    3900 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1200 3900 1300
Wire Wire Line
	3900 1300 3600 1300
$Comp
L VEE #PWR07
U 1 1 5A0D70BB
P 3750 1000
F 0 "#PWR07" H 3750 850 50  0001 C CNN
F 1 "VEE" H 3767 1173 50  0000 C CNN
F 2 "" H 3750 1000 50  0000 C CNN
F 3 "" H 3750 1000 50  0000 C CNN
	1    3750 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1000 3750 1200
Wire Wire Line
	3750 1200 3600 1200
Wire Wire Line
	1750 1200 1750 1900
$EndSCHEMATC
