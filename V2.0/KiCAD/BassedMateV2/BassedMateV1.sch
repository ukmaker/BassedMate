EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
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
L BassedMateV1-rescue:Conn_Coaxial-Connector J1
U 1 1 60A6169F
P 850 1000
F 0 "J1" H 778 1238 50  0000 C CNN
F 1 "Conn_Coaxial" H 778 1147 50  0000 C CNN
F 2 "Connector_Wire:SolderWirePad_1x02_P5.08mm_Drill1.5mm" H 850 1000 50  0001 C CNN
F 3 " ~" H 850 1000 50  0001 C CNN
	1    850  1000
	-1   0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R4
U 1 1 60A62CAB
P 1650 1000
F 0 "R4" V 1443 1000 50  0000 C CNN
F 1 "25K" V 1534 1000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1580 1000 50  0001 C CNN
F 3 "~" H 1650 1000 50  0001 C CNN
	1    1650 1000
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R5
U 1 1 60A63B15
P 1950 1950
F 0 "R5" H 2020 1996 50  0000 L CNN
F 1 "2M" H 2020 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1880 1950 50  0001 C CNN
F 3 "~" H 1950 1950 50  0001 C CNN
	1    1950 1950
	1    0    0    -1  
$EndComp
$Comp
L UKMaker:AD5204 U1
U 1 1 60A6EF10
P 1750 6550
F 0 "U1" H 1700 7000 50  0000 L CNN
F 1 "AD5204" H 1600 6050 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 1750 6800 50  0001 C CNN
F 3 "" H 1750 6800 50  0001 C CNN
	1    1750 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 1000 1950 1800
Wire Wire Line
	1950 2100 1950 2300
$Comp
L BassedMateV1-rescue:GNDA-power #PWR01
U 1 1 60A91E98
P 1100 1950
F 0 "#PWR01" H 1100 1700 50  0001 C CNN
F 1 "GNDA" H 950 1900 50  0000 C CNN
F 2 "" H 1100 1950 50  0001 C CNN
F 3 "" H 1100 1950 50  0001 C CNN
	1    1100 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1950 1100 1850
Wire Wire Line
	1800 1000 1950 1000
$Comp
L BassedMateV1-rescue:C-Device C2
U 1 1 60A950E4
P 1300 1000
F 0 "C2" V 1048 1000 50  0000 C CNN
F 1 "4n7" V 1139 1000 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 1338 850 50  0001 C CNN
F 3 "~" H 1300 1000 50  0001 C CNN
	1    1300 1000
	0    1    1    0   
$EndComp
Wire Wire Line
	1050 1000 1100 1000
Wire Wire Line
	1450 1000 1500 1000
$Comp
L UKMaker:PAM8403_Module U6
U 1 1 60AE61B4
P 10200 2150
F 0 "U6" H 10200 2665 50  0000 C CNN
F 1 "PAM8403_Module" H 10200 2574 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 9750 1950 50  0001 C CNN
F 3 "" H 9750 1950 50  0001 C CNN
	1    10200 2150
	1    0    0    -1  
$EndComp
$Comp
L UKMaker:AD5204 U1
U 2 1 60B3537C
P 9200 2050
F 0 "U1" V 9050 2200 50  0000 L CNN
F 1 "AD5204" V 9500 2100 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 9200 2300 50  0001 C CNN
F 3 "" H 9200 2300 50  0001 C CNN
	2    9200 2050
	0    -1   -1   0   
$EndComp
$Comp
L UKMaker:AD5204 U1
U 4 1 60B0E228
P 9200 1950
F 0 "U1" V 9100 1650 50  0000 L CNN
F 1 "AD5204" V 9350 1600 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 9200 2200 50  0001 C CNN
F 3 "" H 9200 2200 50  0001 C CNN
	4    9200 1950
	0    1    1    0   
$EndComp
$Comp
L UKMaker:AD5204 U1
U 5 1 60A72539
P 3750 1950
F 0 "U1" H 3550 1750 50  0000 L CNN
F 1 "AD5204" H 3400 2050 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 3750 2200 50  0001 C CNN
F 3 "" H 3750 2200 50  0001 C CNN
	5    3750 1950
	-1   0    0    1   
$EndComp
$Comp
L BassedMateV1-rescue:Screw_Terminal_01x02-Connector J5
U 1 1 60C9BC3B
P 10850 1900
F 0 "J5" H 10930 1892 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 10450 2000 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x02_P5.08mm_Drill1.5mm" H 10850 1900 50  0001 C CNN
F 3 "~" H 10850 1900 50  0001 C CNN
	1    10850 1900
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:Screw_Terminal_01x02-Connector J6
U 1 1 60C9C490
P 10850 2150
F 0 "J6" H 10930 2142 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 10450 1950 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x02_P5.08mm_Drill1.5mm" H 10850 2150 50  0001 C CNN
F 3 "~" H 10850 2150 50  0001 C CNN
	1    10850 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10600 1900 10650 1900
Wire Wire Line
	10600 2000 10650 2000
Wire Wire Line
	10600 2150 10650 2150
Wire Wire Line
	10600 2250 10650 2250
$Comp
L UKMaker:TFT_LCD_SPI_160X128 U3
U 1 1 60D09313
P 2050 5000
F 0 "U3" H 2000 4850 50  0000 L CNN
F 1 "TFT_LCD_SPI_160X128" H 1700 5550 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2050 5000 50  0001 C CNN
F 3 "" H 2050 5000 50  0001 C CNN
	1    2050 5000
	1    0    0    -1  
$EndComp
$Sheet
S 9050 3650 1150 350 
U 60B3D04D
F0 "ButtonsAndSwitches" 50
F1 "ButtonsAndSwitches.sch" 50
$EndSheet
$Comp
L BassedMateV1-rescue:+3V3-power #PWR05
U 1 1 60C24319
P 1500 4550
F 0 "#PWR05" H 1500 4400 50  0001 C CNN
F 1 "+3V3" H 1300 4650 50  0000 C CNN
F 2 "" H 1500 4550 50  0001 C CNN
F 3 "" H 1500 4550 50  0001 C CNN
	1    1500 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 4550 1500 4650
Wire Wire Line
	1500 4650 1600 4650
Wire Wire Line
	1600 5250 1500 5250
Wire Wire Line
	1500 5250 1500 4650
Connection ~ 1500 4650
Wire Wire Line
	1600 5350 1500 5350
Wire Wire Line
	1500 5350 1500 5450
$Comp
L BassedMateV1-rescue:GND-power #PWR06
U 1 1 60C32C3F
P 1500 5450
F 0 "#PWR06" H 1500 5200 50  0001 C CNN
F 1 "GND" H 1505 5277 50  0000 C CNN
F 2 "" H 1500 5450 50  0001 C CNN
F 3 "" H 1500 5450 50  0001 C CNN
	1    1500 5450
	1    0    0    -1  
$EndComp
Text GLabel 1350 5050 0    50   Input ~ 0
SC_SDA
Text GLabel 1350 5150 0    50   Input ~ 0
SC_SCL
Text GLabel 1350 4850 0    50   Input ~ 0
SC_DC
Text GLabel 1350 4950 0    50   Input ~ 0
SC_RESET
Text GLabel 1350 4750 0    50   Input ~ 0
SC_CS
Wire Wire Line
	1350 4750 1600 4750
Wire Wire Line
	1600 4850 1350 4850
Wire Wire Line
	1350 4950 1600 4950
Wire Wire Line
	1600 5050 1350 5050
Wire Wire Line
	1350 5150 1600 5150
Wire Wire Line
	1400 6250 1250 6250
Wire Wire Line
	1250 6250 1250 6050
Wire Wire Line
	1400 6350 1250 6350
Wire Wire Line
	1250 6350 1250 6250
Connection ~ 1250 6250
Wire Wire Line
	2100 6850 2150 6850
Wire Wire Line
	1400 6550 1250 6550
Wire Wire Line
	1400 6650 1250 6650
Wire Wire Line
	1400 6750 1250 6750
NoConn ~ 1400 6850
Text GLabel 1250 6750 0    50   Input ~ 0
DP_SDI
Text GLabel 1250 6650 0    50   Input ~ 0
DP_CLK
Text GLabel 1250 6550 0    50   Input ~ 0
DP_CS
$Comp
L BassedMateV1-rescue:GND-power #PWR08
U 1 1 60C770FA
P 2150 7000
F 0 "#PWR08" H 2150 6750 50  0001 C CNN
F 1 "GND" H 2155 6827 50  0000 C CNN
F 2 "" H 2150 7000 50  0001 C CNN
F 3 "" H 2150 7000 50  0001 C CNN
	1    2150 7000
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:+3V3-power #PWR07
U 1 1 60C777DF
P 2150 6050
F 0 "#PWR07" H 2150 5900 50  0001 C CNN
F 1 "+3V3" H 2165 6223 50  0000 C CNN
F 2 "" H 2150 6050 50  0001 C CNN
F 3 "" H 2150 6050 50  0001 C CNN
	1    2150 6050
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C4
U 1 1 60C7DBFC
P 2300 6650
F 0 "C4" H 2415 6696 50  0000 L CNN
F 1 "C" H 2415 6605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 2338 6500 50  0001 C CNN
F 3 "~" H 2300 6650 50  0001 C CNN
	1    2300 6650
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 6850 2150 7000
$Comp
L BassedMateV1-rescue:+5V-power #PWR020
U 1 1 60C8C99B
P 9700 1750
F 0 "#PWR020" H 9700 1600 50  0001 C CNN
F 1 "+5V" H 9800 1800 50  0000 C CNN
F 2 "" H 9700 1750 50  0001 C CNN
F 3 "" H 9700 1750 50  0001 C CNN
	1    9700 1750
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:GNDA-power #PWR018
U 1 1 60C8DA7D
P 9650 2600
F 0 "#PWR018" H 9650 2350 50  0001 C CNN
F 1 "GNDA" H 9650 2400 50  0000 C CNN
F 2 "" H 9650 2600 50  0001 C CNN
F 3 "" H 9650 2600 50  0001 C CNN
	1    9650 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 2600 9650 2400
Wire Wire Line
	9650 2400 9800 2400
Wire Wire Line
	9800 2300 9700 2300
Wire Wire Line
	9700 2300 9700 1750
Text GLabel 8100 3050 2    50   Input ~ 0
MP_DCS
Text GLabel 8100 2650 2    50   Input ~ 0
MP_MOSI
Text GLabel 8100 2550 2    50   Input ~ 0
MP_MISO
Text GLabel 8100 2750 2    50   Input ~ 0
MP_SCK
Text GLabel 8100 2950 2    50   Input ~ 0
MP_CS
Text GLabel 8100 2850 2    50   Input ~ 0
MP_RESET
Wire Wire Line
	850  1850 850  1200
Text GLabel 1700 2300 0    50   Input ~ 0
VREF
Wire Notes Line
	650  650  6050 650 
Wire Notes Line
	6050 650  6050 2600
Wire Notes Line
	6050 2600 650  2600
Wire Notes Line
	650  2600 650  650 
Text Notes 700  2550 0    50   ~ 0
Guitar Input Buffer Amplifier
Wire Notes Line
	6150 650  6150 3400
Wire Notes Line
	650  5800 2850 5800
Wire Notes Line
	2850 5800 2850 7300
Wire Notes Line
	2850 7300 650  7300
Wire Notes Line
	650  7300 650  5800
Wire Wire Line
	2100 6650 2150 6650
Connection ~ 2150 6650
Wire Wire Line
	2150 6850 2450 6850
Wire Wire Line
	2450 6850 2450 6650
Connection ~ 2150 6850
Wire Wire Line
	2150 6050 2150 6650
$Comp
L BassedMateV1-rescue:+3V3-power #PWR04
U 1 1 614B98DE
P 1250 6050
F 0 "#PWR04" H 1250 5900 50  0001 C CNN
F 1 "+3V3" H 1265 6223 50  0000 C CNN
F 2 "" H 1250 6050 50  0001 C CNN
F 3 "" H 1250 6050 50  0001 C CNN
	1    1250 6050
	1    0    0    -1  
$EndComp
Wire Notes Line
	650  4300 2850 4300
Wire Notes Line
	2850 4300 2850 5700
Wire Notes Line
	650  5700 650  4300
Wire Notes Line
	650  5700 2850 5700
Text Notes 750  5600 0    50   ~ 0
Screen
Text Notes 750  7200 0    50   ~ 0
Digipot
Text Notes 8850 3350 0    50   ~ 0
Volume Control and Power Amplifier
Wire Notes Line
	6150 3400 8700 3400
Wire Notes Line
	8800 3400 11050 3400
$Comp
L BassedMateV1-rescue:R-Device R1
U 1 1 60E9BEBE
P 1100 1550
F 0 "R1" H 1170 1596 50  0000 L CNN
F 1 "2M" H 1170 1505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1030 1550 50  0001 C CNN
F 3 "~" H 1100 1550 50  0001 C CNN
	1    1100 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1400 1100 1000
Connection ~ 1100 1000
Wire Wire Line
	1100 1000 1150 1000
Wire Wire Line
	1100 1700 1100 1850
Connection ~ 1100 1850
Wire Wire Line
	1100 1850 850  1850
Wire Wire Line
	1700 2300 1950 2300
$Comp
L BassedMateV1-rescue:R-Device R6
U 1 1 60F5FD53
P 2250 1950
F 0 "R6" H 2320 1996 50  0000 L CNN
F 1 "470" H 2320 1905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2180 1950 50  0001 C CNN
F 3 "~" H 2250 1950 50  0001 C CNN
	1    2250 1950
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R7
U 1 1 60F60036
P 2750 1350
F 0 "R7" V 2850 1100 50  0000 L CNN
F 1 "4K7" V 2850 1450 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2680 1350 50  0001 C CNN
F 3 "~" H 2750 1350 50  0001 C CNN
	1    2750 1350
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C5
U 1 1 60F606D8
P 2750 1550
F 0 "C5" V 2800 1400 50  0000 C CNN
F 1 "4n7" V 2800 1700 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 2788 1400 50  0001 C CNN
F 3 "~" H 2750 1550 50  0001 C CNN
	1    2750 1550
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R8
U 1 1 60F60D47
P 3300 1450
F 0 "R8" H 3370 1496 50  0000 L CNN
F 1 "1K" H 3370 1405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3230 1450 50  0001 C CNN
F 3 "~" H 3300 1450 50  0001 C CNN
	1    3300 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:D D1
U 1 1 60F61C79
P 3300 1950
F 0 "D1" V 3254 2030 50  0000 L CNN
F 1 "D" V 3345 2030 50  0000 L CNN
F 2 "" H 3300 1950 50  0001 C CNN
F 3 "~" H 3300 1950 50  0001 C CNN
	1    3300 1950
	0    1    1    0   
$EndComp
$Comp
L Device:D_Schottky D2
U 1 1 60F624F9
P 3550 1950
F 0 "D2" V 3596 1870 50  0000 R CNN
F 1 "D_Schottky" V 3450 1850 50  0000 R CNN
F 2 "" H 3550 1950 50  0001 C CNN
F 3 "~" H 3550 1950 50  0001 C CNN
	1    3550 1950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 2300 2250 2300
Wire Wire Line
	5200 2300 5200 2000
Wire Wire Line
	5200 2000 5300 2000
Connection ~ 1950 2300
Wire Wire Line
	1950 1000 2400 1000
Connection ~ 1950 1000
Wire Wire Line
	2400 1200 2250 1200
Wire Wire Line
	2250 1200 2250 1350
Wire Wire Line
	2250 2100 2250 2300
Connection ~ 2250 2300
Wire Wire Line
	2250 2300 3300 2300
Wire Wire Line
	2600 1350 2250 1350
Connection ~ 2250 1350
Wire Wire Line
	2250 1350 2250 1550
Wire Wire Line
	2600 1550 2250 1550
Connection ~ 2250 1550
Wire Wire Line
	2250 1550 2250 1800
Wire Wire Line
	2900 1550 3150 1550
Wire Wire Line
	3150 1550 3150 1350
Wire Wire Line
	3150 1100 3000 1100
Wire Wire Line
	2900 1350 3150 1350
Connection ~ 3150 1350
Wire Wire Line
	3150 1350 3150 1100
Wire Wire Line
	3150 1100 3300 1100
Connection ~ 3150 1100
Wire Wire Line
	3300 1300 3300 1100
Wire Wire Line
	3300 1600 3300 1650
Wire Wire Line
	3300 1650 3550 1650
Wire Wire Line
	3550 1650 3550 1800
Connection ~ 3300 1650
Wire Wire Line
	3300 1650 3300 1800
Wire Wire Line
	3300 2100 3300 2300
Connection ~ 3300 2300
Wire Wire Line
	3300 2300 3550 2300
Wire Wire Line
	3550 2100 3550 2300
Connection ~ 3550 2300
Wire Wire Line
	3550 2300 3750 2300
Wire Wire Line
	3750 2150 3750 2300
$Comp
L BassedMateV1-rescue:R-Device R15
U 1 1 61117877
P 4800 1650
F 0 "R15" V 4593 1650 50  0000 C CNN
F 1 "47K" V 4684 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4730 1650 50  0001 C CNN
F 3 "~" H 4800 1650 50  0001 C CNN
	1    4800 1650
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R16
U 1 1 611180EE
P 4800 1950
F 0 "R16" V 4593 1950 50  0000 C CNN
F 1 "15K" V 4684 1950 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4730 1950 50  0001 C CNN
F 3 "~" H 4800 1950 50  0001 C CNN
	1    4800 1950
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R20
U 1 1 611182F1
P 5600 1600
F 0 "R20" V 5550 1350 50  0000 C CNN
F 1 "47K" V 5550 1850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5530 1600 50  0001 C CNN
F 3 "~" H 5600 1600 50  0001 C CNN
	1    5600 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 1600 5950 1600
Wire Wire Line
	5950 1600 5950 1900
Wire Wire Line
	5950 1900 5900 1900
Text Notes 3150 2550 0    50   ~ 0
Fuzz / Limiting
Text Notes 4050 2550 0    50   ~ 0
Wet / Dry Mixing And Level
Wire Wire Line
	4950 1950 5000 1950
Wire Wire Line
	5000 1950 5000 1800
Wire Wire Line
	4950 1650 5000 1650
Wire Wire Line
	5000 1650 5000 1800
Wire Wire Line
	5300 1800 5200 1800
Connection ~ 5000 1800
Wire Wire Line
	5200 1800 5200 1600
Wire Wire Line
	5200 1600 5450 1600
Connection ~ 5200 1800
Wire Wire Line
	5200 1800 5000 1800
$Comp
L BassedMateV1-rescue:GNDA-power #PWR011
U 1 1 61520A2E
P 3800 3900
F 0 "#PWR011" H 3800 3650 50  0001 C CNN
F 1 "GNDA" H 3650 3850 50  0000 C CNN
F 2 "" H 3800 3900 50  0001 C CNN
F 3 "" H 3800 3900 50  0001 C CNN
	1    3800 3900
	1    0    0    -1  
$EndComp
Wire Notes Line
	3300 2700 6050 2700
Wire Notes Line
	6050 2700 6050 4200
Wire Notes Line
	6050 4200 3300 4200
Wire Notes Line
	3300 4200 3300 2700
Text Notes 3350 4150 0    50   ~ 0
Aux Input Buffer
$Comp
L BassedMateV1-rescue:AudioJack3_Switch-Connector J2
U 1 1 61538152
P 3600 3350
F 0 "J2" V 3350 2850 50  0000 L CNN
F 1 "AudioJack3_Switch" V 3200 2950 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x04_P5.08mm_Drill1.5mm" H 3600 3350 50  0001 C CNN
F 3 "~" H 3600 3350 50  0001 C CNN
	1    3600 3350
	1    0    0    1   
$EndComp
Wire Wire Line
	5200 3800 5200 3450
Wire Wire Line
	5200 3450 5300 3450
$Comp
L BassedMateV1-rescue:R-Device R21
U 1 1 615E51C9
P 5600 3050
F 0 "R21" V 5550 2850 50  0000 C CNN
F 1 "47K" V 5550 3250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5530 3050 50  0001 C CNN
F 3 "~" H 5600 3050 50  0001 C CNN
	1    5600 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 3050 5950 3050
Wire Wire Line
	5950 3050 5950 3350
Wire Wire Line
	5950 3350 5900 3350
Wire Wire Line
	4950 3800 5200 3800
Wire Wire Line
	5300 3250 5200 3250
Wire Wire Line
	5200 3250 5200 3050
Wire Wire Line
	5200 3050 5450 3050
Text GLabel 4950 3800 0    50   Input ~ 0
VREF
$Comp
L BassedMateV1-rescue:C-Device C8
U 1 1 61688F85
P 4400 3350
F 0 "C8" V 4350 3250 50  0000 C CNN
F 1 "100n" V 4550 3350 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 4438 3200 50  0001 C CNN
F 3 "~" H 4400 3350 50  0001 C CNN
	1    4400 3350
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C7
U 1 1 6168837D
P 4400 3150
F 0 "C7" V 4350 3050 50  0000 C CNN
F 1 "100n" V 4239 3150 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 4438 3000 50  0001 C CNN
F 3 "~" H 4400 3150 50  0001 C CNN
	1    4400 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 3150 4600 3150
$Comp
L BassedMateV1-rescue:R-Device R17
U 1 1 615E51BD
P 4750 3150
F 0 "R17" V 4543 3150 50  0000 C CNN
F 1 "47K" V 4634 3150 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 3150 50  0001 C CNN
F 3 "~" H 4750 3150 50  0001 C CNN
	1    4750 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 3150 5000 3150
Wire Wire Line
	5000 3150 5000 3250
Wire Wire Line
	5000 3350 4900 3350
Wire Wire Line
	5000 3250 5200 3250
Connection ~ 5000 3250
Wire Wire Line
	5000 3250 5000 3350
Connection ~ 5200 3250
Wire Wire Line
	4550 3350 4600 3350
$Comp
L BassedMateV1-rescue:R-Device R11
U 1 1 617497D5
P 4000 3600
F 0 "R11" H 4100 3450 50  0000 C CNN
F 1 "10K" H 4100 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3930 3600 50  0001 C CNN
F 3 "~" H 4000 3600 50  0001 C CNN
	1    4000 3600
	-1   0    0    1   
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R12
U 1 1 6174A883
P 4150 3600
F 0 "R12" H 4050 3450 50  0000 C CNN
F 1 "10K" H 4050 3750 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4080 3600 50  0001 C CNN
F 3 "~" H 4150 3600 50  0001 C CNN
	1    4150 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4150 3850 4150 3750
Wire Wire Line
	4000 3750 4000 3850
Connection ~ 4000 3850
Wire Wire Line
	4000 3850 4150 3850
Wire Wire Line
	4000 3350 4000 3450
Wire Wire Line
	4150 3150 4150 3450
$Comp
L UKMaker:Adafruit_VS1053_Module U4
U 1 1 6180DE38
P 7450 2400
F 0 "U4" H 7450 2450 50  0000 C CNN
F 1 "Adafruit_VS1053_Module" H 7450 3350 50  0000 C CNN
F 2 "" H 7700 2200 50  0001 C CNN
F 3 "" H 7700 2200 50  0001 C CNN
	1    7450 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 2400 9650 2000
Wire Wire Line
	9650 2000 9800 2000
Connection ~ 9650 2400
Text GLabel 9350 2500 0    50   Input ~ 0
AREF
$Comp
L BassedMateV1-rescue:AudioJack3_Switch-Connector J4
U 1 1 61AE891F
P 10550 1100
F 0 "J4" V 10300 600 50  0000 L CNN
F 1 "AudioJack3_Switch" V 10150 700 50  0000 L CNN
F 2 "Connector_Wire:SolderWirePad_1x04_P5.08mm_Drill1.5mm" H 10550 1100 50  0001 C CNN
F 3 "~" H 10550 1100 50  0001 C CNN
	1    10550 1100
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 2050 8100 2050
Wire Wire Line
	8100 2050 8100 1950
Wire Wire Line
	8100 1850 7950 1850
Wire Wire Line
	7950 1950 8100 1950
Connection ~ 8100 1950
Wire Wire Line
	8100 1950 8100 1850
$Comp
L BassedMateV1-rescue:GNDA-power #PWR017
U 1 1 61B1780B
P 8550 2200
F 0 "#PWR017" H 8550 1950 50  0001 C CNN
F 1 "GNDA" H 8550 2000 50  0000 C CNN
F 2 "" H 8550 2200 50  0001 C CNN
F 3 "" H 8550 2200 50  0001 C CNN
	1    8550 2200
	1    0    0    -1  
$EndComp
Text GLabel 9800 1200 0    50   Output ~ 0
HPHONE
$Sheet
S 7500 3650 1150 350 
U 61C297BA
F0 "MCU" 50
F1 "MCU.sch" 50
$EndSheet
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 61C6BC05
P 5750 6250
AR Path="/60CBB86D/61C6BC05" Ref="Q?"  Part="1" 
AR Path="/61C6BC05" Ref="Q6"  Part="1" 
F 0 "Q6" H 5941 6296 50  0000 L CNN
F 1 "Q_NPN_BCE" H 5941 6205 50  0000 L CNN
F 2 "" H 5950 6350 50  0001 C CNN
F 3 "~" H 5750 6250 50  0001 C CNN
	1    5750 6250
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61C6BC0B
P 5150 5350
AR Path="/60CBB86D/61C6BC0B" Ref="R?"  Part="1" 
AR Path="/61C6BC0B" Ref="R19"  Part="1" 
F 0 "R19" H 5220 5396 50  0000 L CNN
F 1 "R" H 5220 5305 50  0000 L CNN
F 2 "" V 5080 5350 50  0001 C CNN
F 3 "~" H 5150 5350 50  0001 C CNN
	1    5150 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 61C6BC11
P 5400 6600
AR Path="/60CBB86D/61C6BC11" Ref="C?"  Part="1" 
AR Path="/61C6BC11" Ref="C9"  Part="1" 
F 0 "C9" H 5518 6646 50  0000 L CNN
F 1 "CP" H 5518 6555 50  0000 L CNN
F 2 "" H 5438 6450 50  0001 C CNN
F 3 "~" H 5400 6600 50  0001 C CNN
	1    5400 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61C6BC1D
P 6200 6250
AR Path="/60CBB86D/61C6BC1D" Ref="R?"  Part="1" 
AR Path="/61C6BC1D" Ref="R24"  Part="1" 
F 0 "R24" V 5993 6250 50  0000 C CNN
F 1 "R" V 6084 6250 50  0000 C CNN
F 2 "" V 6130 6250 50  0001 C CNN
F 3 "~" H 6200 6250 50  0001 C CNN
	1    6200 6250
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61C6BC23
P 6000 6600
AR Path="/60CBB86D/61C6BC23" Ref="R?"  Part="1" 
AR Path="/61C6BC23" Ref="R23"  Part="1" 
F 0 "R23" H 5930 6554 50  0000 R CNN
F 1 "R" H 5930 6645 50  0000 R CNN
F 2 "" V 5930 6600 50  0001 C CNN
F 3 "~" H 6000 6600 50  0001 C CNN
	1    6000 6600
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 5200 5150 5100
Wire Wire Line
	5400 5550 5650 5550
Wire Wire Line
	5600 5100 5750 5100
Wire Wire Line
	6000 6450 6000 6250
Wire Wire Line
	6000 6250 6050 6250
Wire Wire Line
	6000 6250 5950 6250
Connection ~ 6000 6250
Wire Wire Line
	6350 6250 6400 6250
Text GLabel 3400 5950 0    50   Input ~ 0
FE_B
Text GLabel 3400 6250 0    50   Output ~ 0
FE_B_B
Text GLabel 6400 6250 2    50   Input ~ 0
POWERON
Wire Notes Line
	3000 4300 3000 7550
$Comp
L BassedMateV1-rescue:R-Device R2
U 1 1 61C6BC66
P 1100 3200
AR Path="/61C6BC66" Ref="R2"  Part="1" 
AR Path="/60CBB86D/61C6BC66" Ref="R?"  Part="1" 
F 0 "R2" H 1170 3246 50  0000 L CNN
F 1 "100K" H 1170 3155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1030 3200 50  0001 C CNN
F 3 "~" H 1100 3200 50  0001 C CNN
	1    1100 3200
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R3
U 1 1 61C6BC6C
P 1100 3600
AR Path="/61C6BC6C" Ref="R3"  Part="1" 
AR Path="/60CBB86D/61C6BC6C" Ref="R?"  Part="1" 
F 0 "R3" H 950 3700 50  0000 L CNN
F 1 "100K" H 900 3450 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1030 3600 50  0001 C CNN
F 3 "~" H 1100 3600 50  0001 C CNN
	1    1100 3600
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:GNDA-power #PWR03
U 1 1 61C6BC72
P 1100 3950
AR Path="/61C6BC72" Ref="#PWR03"  Part="1" 
AR Path="/60CBB86D/61C6BC72" Ref="#PWR?"  Part="1" 
F 0 "#PWR03" H 1100 3700 50  0001 C CNN
F 1 "GNDA" H 1105 3777 50  0000 C CNN
F 2 "" H 1100 3950 50  0001 C CNN
F 3 "" H 1100 3950 50  0001 C CNN
	1    1100 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 3350 1100 3400
Wire Wire Line
	1100 3750 1100 3800
Wire Wire Line
	1100 3400 1100 3450
Wire Wire Line
	2300 3800 2300 3500
$Comp
L BassedMateV1-rescue:C-Device C3
U 1 1 61C6BC7C
P 1350 3600
AR Path="/61C6BC7C" Ref="C3"  Part="1" 
AR Path="/60CBB86D/61C6BC7C" Ref="C?"  Part="1" 
F 0 "C3" H 1250 3700 50  0000 L CNN
F 1 "100n" H 1150 3450 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 1388 3450 50  0001 C CNN
F 3 "~" H 1350 3600 50  0001 C CNN
	1    1350 3600
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:CP-Device C1
U 1 1 61C6BC82
P 850 3600
AR Path="/61C6BC82" Ref="C1"  Part="1" 
AR Path="/60CBB86D/61C6BC82" Ref="C?"  Part="1" 
F 0 "C1" H 850 3700 50  0000 L CNN
F 1 "10u" H 850 3500 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 888 3450 50  0001 C CNN
F 3 "~" H 850 3600 50  0001 C CNN
	1    850  3600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	850  3450 850  3400
Wire Wire Line
	850  3400 1100 3400
Wire Wire Line
	850  3750 850  3800
Wire Wire Line
	850  3800 1100 3800
$Comp
L BassedMateV1-rescue:C-Device C6
U 1 1 61C6BC98
P 3000 3450
AR Path="/61C6BC98" Ref="C6"  Part="1" 
AR Path="/60CBB86D/61C6BC98" Ref="C?"  Part="1" 
F 0 "C6" H 3050 3600 50  0000 L CNN
F 1 "100n" H 3000 3350 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 3038 3300 50  0001 C CNN
F 3 "~" H 3000 3450 50  0001 C CNN
	1    3000 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 3750 2800 3800
Wire Wire Line
	2800 3150 2800 3100
Wire Wire Line
	3000 3300 3000 3100
Wire Wire Line
	3000 3100 2800 3100
Connection ~ 2800 3100
Wire Wire Line
	2800 3100 2800 2950
Wire Wire Line
	3000 3600 3000 3800
Wire Wire Line
	3000 3800 2800 3800
Connection ~ 2800 3800
$Comp
L BassedMateV1-rescue:+3.3VA-power #PWR02
U 1 1 61C6BCA7
P 1100 2950
AR Path="/61C6BCA7" Ref="#PWR02"  Part="1" 
AR Path="/60CBB86D/61C6BCA7" Ref="#PWR?"  Part="1" 
F 0 "#PWR02" H 1100 2800 50  0001 C CNN
F 1 "+3.3VA" H 1115 3123 50  0000 C CNN
F 2 "" H 1100 2950 50  0001 C CNN
F 3 "" H 1100 2950 50  0001 C CNN
	1    1100 2950
	1    0    0    -1  
$EndComp
Text GLabel 2400 3500 2    50   Input ~ 0
VREF
Wire Wire Line
	2300 3500 2400 3500
Connection ~ 1100 3400
Wire Wire Line
	1100 3800 1100 3950
Connection ~ 1100 3800
Wire Wire Line
	1100 2950 1100 3050
Connection ~ 2300 3500
Wire Wire Line
	2200 3500 2300 3500
Wire Wire Line
	1100 3400 1350 3400
Wire Wire Line
	1600 3600 1550 3600
Wire Wire Line
	1550 3600 1550 3800
Wire Wire Line
	1550 3800 2300 3800
$Comp
L BassedMateV1-rescue:+3.3VA-power #PWR09
U 1 1 61C6BCB9
P 2800 2950
AR Path="/61C6BCB9" Ref="#PWR09"  Part="1" 
AR Path="/60CBB86D/61C6BCB9" Ref="#PWR?"  Part="1" 
F 0 "#PWR09" H 2800 2800 50  0001 C CNN
F 1 "+3.3VA" H 2815 3123 50  0000 C CNN
F 2 "" H 2800 2950 50  0001 C CNN
F 3 "" H 2800 2950 50  0001 C CNN
	1    2800 2950
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:GNDA-power #PWR010
U 1 1 61C6BCBF
P 2800 3950
AR Path="/61C6BCBF" Ref="#PWR010"  Part="1" 
AR Path="/60CBB86D/61C6BCBF" Ref="#PWR?"  Part="1" 
F 0 "#PWR010" H 2800 3700 50  0001 C CNN
F 1 "GNDA" H 2805 3777 50  0000 C CNN
F 2 "" H 2800 3950 50  0001 C CNN
F 3 "" H 2800 3950 50  0001 C CNN
	1    2800 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 3800 2800 3950
Text Notes 1650 4150 0    50   ~ 0
Reference Voltage
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 61C6BCD0
P 5400 5200
AR Path="/60CBB86D/61C6BCD0" Ref="Q?"  Part="1" 
AR Path="/61C6BCD0" Ref="Q5"  Part="1" 
F 0 "Q5" V 5742 5200 50  0000 C CNN
F 1 "IRFU5305" V 5651 5200 50  0000 C CNN
F 2 "" H 5600 5300 50  0001 C CNN
F 3 "~" H 5400 5200 50  0001 C CNN
	1    5400 5200
	0    1    -1   0   
$EndComp
Wire Notes Line
	650  2700 3200 2700
Wire Notes Line
	3200 2700 3200 4200
Wire Notes Line
	3200 4200 650  4200
Wire Notes Line
	650  4200 650  2700
$Comp
L Device:Q_PNP_BEC Q4
U 1 1 61DC938C
P 5400 4700
F 0 "Q4" V 5728 4700 50  0000 C CNN
F 1 "Q_PNP_BEC" V 5637 4700 50  0000 C CNN
F 2 "" H 5600 4800 50  0001 C CNN
F 3 "~" H 5400 4700 50  0001 C CNN
	1    5400 4700
	0    1    -1   0   
$EndComp
Wire Wire Line
	5200 4600 5050 4600
Wire Wire Line
	5050 4600 5050 4850
Wire Wire Line
	5600 4600 5750 4600
Wire Wire Line
	5400 4900 5650 4900
Wire Wire Line
	5650 4900 5650 5200
$Comp
L Device:R R?
U 1 1 61DED9B5
P 5650 5350
AR Path="/60CBB86D/61DED9B5" Ref="R?"  Part="1" 
AR Path="/61DED9B5" Ref="R22"  Part="1" 
F 0 "R22" H 5720 5396 50  0000 L CNN
F 1 "R" H 5720 5305 50  0000 L CNN
F 2 "" V 5580 5350 50  0001 C CNN
F 3 "~" H 5650 5350 50  0001 C CNN
	1    5650 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 5500 5650 5550
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 61E29284
P 5050 6250
AR Path="/60CBB86D/61E29284" Ref="Q?"  Part="1" 
AR Path="/61E29284" Ref="Q3"  Part="1" 
F 0 "Q3" H 5241 6296 50  0000 L CNN
F 1 "Q_NPN_BCE" H 5241 6205 50  0000 L CNN
F 2 "" H 5250 6350 50  0001 C CNN
F 3 "~" H 5050 6250 50  0001 C CNN
	1    5050 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 5550 5400 5550
Wire Wire Line
	4300 5550 5150 5550
Connection ~ 5150 5100
Wire Wire Line
	5150 5100 5200 5100
Wire Wire Line
	5050 5100 5150 5100
Wire Wire Line
	5150 5500 5150 5550
Connection ~ 5050 4850
Wire Wire Line
	5050 4850 5050 5100
$Comp
L Device:Q_PNP_BEC Q2
U 1 1 61EF05BC
P 4200 5950
F 0 "Q2" H 4390 5904 50  0000 L CNN
F 1 "Q_PNP_BEC" H 4390 5995 50  0000 L CNN
F 2 "" H 4400 6050 50  0001 C CNN
F 3 "~" H 4200 5950 50  0001 C CNN
	1    4200 5950
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 61F1599E
P 4600 6250
AR Path="/60CBB86D/61F1599E" Ref="R?"  Part="1" 
AR Path="/61F1599E" Ref="R14"  Part="1" 
F 0 "R14" V 4393 6250 50  0000 C CNN
F 1 "R" V 4484 6250 50  0000 C CNN
F 2 "" V 4530 6250 50  0001 C CNN
F 3 "~" H 4600 6250 50  0001 C CNN
	1    4600 6250
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61F466C3
P 4800 6600
AR Path="/60CBB86D/61F466C3" Ref="R?"  Part="1" 
AR Path="/61F466C3" Ref="R18"  Part="1" 
F 0 "R18" H 4730 6554 50  0000 R CNN
F 1 "R" H 4730 6645 50  0000 R CNN
F 2 "" V 4730 6600 50  0001 C CNN
F 3 "~" H 4800 6600 50  0001 C CNN
	1    4800 6600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4800 6450 4800 6250
Wire Wire Line
	4800 6250 4850 6250
$Comp
L Device:R R?
U 1 1 61FCB4C7
P 3900 5750
AR Path="/60CBB86D/61FCB4C7" Ref="R?"  Part="1" 
AR Path="/61FCB4C7" Ref="R10"  Part="1" 
F 0 "R10" H 3830 5704 50  0000 R CNN
F 1 "R" H 3830 5795 50  0000 R CNN
F 2 "" V 3830 5750 50  0001 C CNN
F 3 "~" H 3900 5750 50  0001 C CNN
	1    3900 5750
	-1   0    0    1   
$EndComp
Connection ~ 5150 5550
Connection ~ 5400 5550
Wire Wire Line
	5400 5550 5400 5400
Wire Wire Line
	5150 5550 5150 6050
Connection ~ 5650 5550
Wire Wire Line
	5400 5550 5400 6450
Wire Wire Line
	5650 5550 5650 6050
Wire Wire Line
	4300 5550 4300 5750
Wire Wire Line
	3900 5600 3900 5550
Wire Wire Line
	3900 5550 4300 5550
Connection ~ 4300 5550
Wire Wire Line
	4000 5950 3900 5950
Wire Wire Line
	3900 5950 3900 5900
$Comp
L Device:R R?
U 1 1 6203FF6F
P 3650 5950
AR Path="/60CBB86D/6203FF6F" Ref="R?"  Part="1" 
AR Path="/6203FF6F" Ref="R9"  Part="1" 
F 0 "R9" V 3443 5950 50  0000 C CNN
F 1 "R" V 3534 5950 50  0000 C CNN
F 2 "" V 3580 5950 50  0001 C CNN
F 3 "~" H 3650 5950 50  0001 C CNN
	1    3650 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	3400 5950 3500 5950
Wire Wire Line
	3800 5950 3900 5950
Connection ~ 3900 5950
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 6206960A
P 4000 6850
AR Path="/60CBB86D/6206960A" Ref="Q?"  Part="1" 
AR Path="/6206960A" Ref="Q1"  Part="1" 
F 0 "Q1" H 4191 6896 50  0000 L CNN
F 1 "Q_NPN_BCE" H 4191 6805 50  0000 L CNN
F 2 "" H 4200 6950 50  0001 C CNN
F 3 "~" H 4000 6850 50  0001 C CNN
	1    4000 6850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3900 6650 3900 6250
Wire Wire Line
	3900 6250 3400 6250
$Comp
L Device:R R?
U 1 1 62086DFB
P 4300 6600
AR Path="/60CBB86D/62086DFB" Ref="R?"  Part="1" 
AR Path="/62086DFB" Ref="R13"  Part="1" 
F 0 "R13" H 4230 6554 50  0000 R CNN
F 1 "R" H 4230 6645 50  0000 R CNN
F 2 "" V 4230 6600 50  0001 C CNN
F 3 "~" H 4300 6600 50  0001 C CNN
	1    4300 6600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4300 6450 4300 6250
Wire Wire Line
	4450 6250 4300 6250
Connection ~ 4300 6250
Wire Wire Line
	4300 6250 4300 6150
Wire Wire Line
	4750 6250 4800 6250
Connection ~ 4800 6250
Connection ~ 4800 7150
Wire Wire Line
	3900 7150 3900 7050
Wire Wire Line
	4800 7150 3900 7150
Wire Wire Line
	4800 7150 5150 7150
Wire Wire Line
	4800 7150 4800 6750
Wire Wire Line
	5650 7150 6000 7150
Wire Wire Line
	5150 7150 5400 7150
Connection ~ 5150 7150
Wire Wire Line
	5650 7150 5400 7150
Connection ~ 5650 7150
Wire Wire Line
	5150 6450 5150 7150
Text Notes 3100 7500 0    50   ~ 0
Power On Control
$Comp
L BassedMateV1-rescue:GND-power #PWR?
U 1 1 61C6BC52
P 5400 7300
AR Path="/60CBB86D/61C6BC52" Ref="#PWR?"  Part="1" 
AR Path="/61C6BC52" Ref="#PWR012"  Part="1" 
F 0 "#PWR012" H 5400 7050 50  0001 C CNN
F 1 "GND" H 5405 7127 50  0000 C CNN
F 2 "" H 5400 7300 50  0001 C CNN
F 3 "" H 5400 7300 50  0001 C CNN
	1    5400 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 7150 5400 7300
Connection ~ 5400 7150
Wire Wire Line
	5650 6450 5650 7150
Wire Wire Line
	5400 7150 5400 6750
Wire Wire Line
	6000 6750 6000 7150
Wire Wire Line
	4200 6850 4300 6850
Wire Wire Line
	4300 6850 4300 6750
Wire Notes Line
	3000 7550 6850 7550
Wire Notes Line
	6850 7550 6850 4300
Wire Notes Line
	3000 4300 6850 4300
Wire Wire Line
	4850 4850 5050 4850
Text GLabel 4850 4850 0    50   Input ~ 0
VBAT
Wire Wire Line
	5750 4600 5750 4850
Text GLabel 6000 4850 2    50   Output ~ 0
VBOOST
Wire Wire Line
	5750 4850 6000 4850
Connection ~ 5750 4850
Wire Wire Line
	5750 4850 5750 5100
Wire Notes Line
	6150 3500 6150 4200
Wire Notes Line
	6150 4200 11050 4200
Wire Notes Line
	11050 4200 11050 3500
Wire Notes Line
	11050 3500 6150 3500
Text Notes 6200 4150 0    50   ~ 0
MCU, Buttons and Blinkenlights
$Comp
L UKMaker:ChargeBoost_Module U5
U 1 1 62374314
P 9000 5400
F 0 "U5" H 8950 5400 50  0000 L CNN
F 1 "ChargeBoost_Module" H 8400 5950 50  0000 L CNN
F 2 "" H 9000 5475 50  0001 C CNN
F 3 "" H 9000 5475 50  0001 C CNN
	1    9000 5400
	1    0    0    -1  
$EndComp
Text GLabel 9400 5750 2    50   Output ~ 0
VBOOST
Text GLabel 7700 4750 0    50   Input ~ 0
+5V_USB
$Comp
L Device:D_Schottky D3
U 1 1 623967F5
P 8050 4750
F 0 "D3" H 8100 4600 50  0000 R CNN
F 1 "D_Schottky" H 7900 4650 50  0000 R CNN
F 2 "" H 8050 4750 50  0001 C CNN
F 3 "~" H 8050 4750 50  0001 C CNN
	1    8050 4750
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 623975E9
P 7800 5150
AR Path="/60CBB86D/623975E9" Ref="R?"  Part="1" 
AR Path="/623975E9" Ref="R25"  Part="1" 
F 0 "R25" H 7730 5104 50  0000 R CNN
F 1 "R" H 7730 5195 50  0000 R CNN
F 2 "" V 7730 5150 50  0001 C CNN
F 3 "~" H 7800 5150 50  0001 C CNN
	1    7800 5150
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62397EDE
P 7800 5550
AR Path="/60CBB86D/62397EDE" Ref="R?"  Part="1" 
AR Path="/62397EDE" Ref="R26"  Part="1" 
F 0 "R26" H 7730 5504 50  0000 R CNN
F 1 "R" H 7730 5595 50  0000 R CNN
F 2 "" V 7730 5550 50  0001 C CNN
F 3 "~" H 7800 5550 50  0001 C CNN
	1    7800 5550
	-1   0    0    1   
$EndComp
Wire Wire Line
	7700 4750 7800 4750
Wire Wire Line
	7800 4750 7800 5000
Wire Wire Line
	7800 4750 7900 4750
Connection ~ 7800 4750
Wire Wire Line
	7800 5300 7800 5350
$Comp
L BassedMateV1-rescue:GND-power #PWR?
U 1 1 623D3B25
P 7800 5900
AR Path="/60CBB86D/623D3B25" Ref="#PWR?"  Part="1" 
AR Path="/623D3B25" Ref="#PWR014"  Part="1" 
F 0 "#PWR014" H 7800 5650 50  0001 C CNN
F 1 "GND" H 7805 5727 50  0000 C CNN
F 2 "" H 7800 5900 50  0001 C CNN
F 3 "" H 7800 5900 50  0001 C CNN
	1    7800 5900
	1    0    0    -1  
$EndComp
Text GLabel 7700 5350 0    50   Output ~ 0
USB_POWER
Wire Wire Line
	7700 5350 7800 5350
Connection ~ 7800 5350
Wire Wire Line
	7800 5350 7800 5400
Wire Wire Line
	7800 5700 7800 5850
Wire Wire Line
	8750 5100 8750 4950
Wire Wire Line
	8750 4950 9150 4950
Wire Wire Line
	9150 4950 9150 5100
Wire Wire Line
	8750 4950 8050 4950
Wire Wire Line
	8050 4950 8050 5850
Wire Wire Line
	8050 5850 7800 5850
Connection ~ 8750 4950
Connection ~ 7800 5850
Wire Wire Line
	7800 5850 7800 5900
Wire Wire Line
	8200 4750 9250 4750
Wire Wire Line
	9650 4750 9650 4650
Wire Wire Line
	9250 5100 9250 4750
Connection ~ 9250 4750
Wire Wire Line
	9250 4750 9650 4750
$Comp
L Connector_Generic:Conn_01x02 J3
U 1 1 62444CF2
P 8850 6150
F 0 "J3" V 8722 6230 50  0000 L CNN
F 1 "Conn_01x02" V 8950 5900 50  0000 L CNN
F 2 "" H 8850 6150 50  0001 C CNN
F 3 "~" H 8850 6150 50  0001 C CNN
	1    8850 6150
	0    1    1    0   
$EndComp
Text GLabel 9400 5900 2    50   Input ~ 0
VBAT
Wire Wire Line
	8050 5850 8750 5850
Wire Wire Line
	8750 5850 8750 5700
Connection ~ 8050 5850
Wire Wire Line
	8750 5950 8750 5850
Connection ~ 8750 5850
Wire Wire Line
	8850 5950 8850 5900
Wire Wire Line
	9400 5900 8850 5900
Connection ~ 8850 5900
Wire Wire Line
	8850 5900 8850 5700
Wire Wire Line
	9400 5750 9250 5750
Wire Wire Line
	9150 5700 9150 5750
Wire Wire Line
	9150 5750 9250 5750
Connection ~ 9250 5750
Wire Wire Line
	9250 5750 9250 5700
$Comp
L power:+5V #PWR019
U 1 1 624BDB48
P 9650 4650
F 0 "#PWR019" H 9650 4500 50  0001 C CNN
F 1 "+5V" H 9665 4823 50  0000 C CNN
F 2 "" H 9650 4650 50  0001 C CNN
F 3 "" H 9650 4650 50  0001 C CNN
	1    9650 4650
	1    0    0    -1  
$EndComp
Wire Notes Line
	7000 4300 7000 6350
Wire Notes Line
	7000 6350 9900 6350
Wire Notes Line
	9900 6350 9900 4300
Wire Notes Line
	9900 4300 7000 4300
Text Notes 6500 3350 0    50   ~ 0
MIDI Module
Wire Wire Line
	5950 1900 6200 1900
Wire Wire Line
	6200 1900 6200 1650
Wire Wire Line
	6200 1650 6900 1650
Connection ~ 5950 1900
Wire Wire Line
	5950 3350 6300 3350
Wire Wire Line
	6300 3350 6300 1750
Wire Wire Line
	6300 1750 6900 1750
Connection ~ 5950 3350
Wire Wire Line
	3750 1650 3750 1750
Wire Wire Line
	4000 1850 4000 2300
Wire Wire Line
	4000 1100 4000 1450
$Comp
L UKMaker:AD5204 U1
U 3 1 6102F586
P 4000 1650
F 0 "U1" H 3800 1450 50  0000 L CNN
F 1 "AD5204" H 3650 1750 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket_LongPads" H 4000 1900 50  0001 C CNN
F 3 "" H 4000 1900 50  0001 C CNN
	3    4000 1650
	-1   0    0    1   
$EndComp
Wire Wire Line
	9450 2500 9350 2500
Wire Wire Line
	9400 1950 9450 1950
Wire Wire Line
	9450 1950 9450 2050
Wire Wire Line
	9400 2050 9450 2050
Connection ~ 9450 2050
Wire Wire Line
	9450 2050 9450 2500
Wire Wire Line
	9550 2250 9550 2100
Wire Wire Line
	9550 2100 9800 2100
Wire Wire Line
	9200 2250 9550 2250
Wire Wire Line
	9550 1750 9550 1900
Wire Wire Line
	9550 1900 9800 1900
Wire Wire Line
	9200 1750 9550 1750
Wire Wire Line
	10350 1300 10200 1300
Connection ~ 8100 2050
$Comp
L BassedMateV1-rescue:GNDA-power #PWR021
U 1 1 62AA330A
P 10200 1350
F 0 "#PWR021" H 10200 1100 50  0001 C CNN
F 1 "GNDA" H 10200 1150 50  0000 C CNN
F 2 "" H 10200 1350 50  0001 C CNN
F 3 "" H 10200 1350 50  0001 C CNN
	1    10200 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10200 1300 10200 1350
Wire Wire Line
	10350 1200 9800 1200
Wire Wire Line
	9000 2050 8500 2050
Wire Wire Line
	8500 2050 8500 1750
Wire Wire Line
	8500 1750 7950 1750
Wire Wire Line
	8600 1950 8600 1650
Wire Wire Line
	8600 1650 7950 1650
Wire Wire Line
	8600 1950 9000 1950
Wire Wire Line
	8600 1650 8600 1100
Wire Wire Line
	8600 1100 10350 1100
Connection ~ 8600 1650
Wire Wire Line
	8500 1750 8500 900 
Wire Wire Line
	8500 900  10350 900 
Connection ~ 8500 1750
Wire Notes Line
	8800 3400 8800 1600
Wire Notes Line
	8800 1600 11050 1600
Wire Notes Line
	11050 3400 11050 1600
Wire Notes Line
	11050 1500 8800 1500
Wire Notes Line
	8800 1500 8800 650 
Wire Notes Line
	6150 650  8700 650 
Wire Notes Line
	8700 3400 8700 650 
Wire Notes Line
	8800 650  11050 650 
Wire Notes Line
	11050 650  11050 1500
Text Notes 8850 1450 0    50   ~ 0
Headphone Socket and Detect
Text GLabel 6750 3050 0    50   Input ~ 0
MP_RXD
Wire Wire Line
	6750 3050 6900 3050
NoConn ~ 7950 2150
Wire Wire Line
	7950 2450 8100 2450
Wire Wire Line
	8100 2450 8100 2150
Wire Wire Line
	8550 2200 8550 2150
Wire Wire Line
	8550 2150 8100 2150
Connection ~ 8100 2150
Wire Wire Line
	8100 2150 8100 2050
$Comp
L BassedMateV1-rescue:+5V-power #PWR015
U 1 1 62D079D7
P 8300 1550
F 0 "#PWR015" H 8300 1400 50  0001 C CNN
F 1 "+5V" H 8400 1600 50  0000 C CNN
F 2 "" H 8300 1550 50  0001 C CNN
F 3 "" H 8300 1550 50  0001 C CNN
	1    8300 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 2250 8300 2250
Wire Wire Line
	8300 2250 8300 1550
Wire Wire Line
	7950 2350 8400 2350
Wire Wire Line
	8400 2350 8400 2050
$Comp
L power:+3.3VA #PWR016
U 1 1 62D2EB90
P 8400 2050
F 0 "#PWR016" H 8400 1900 50  0001 C CNN
F 1 "+3.3VA" H 8415 2223 50  0000 C CNN
F 2 "" H 8400 2050 50  0001 C CNN
F 3 "" H 8400 2050 50  0001 C CNN
	1    8400 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 2550 8100 2550
Wire Wire Line
	7950 2650 8100 2650
Wire Wire Line
	7950 2750 8100 2750
Wire Wire Line
	7950 2850 8100 2850
Wire Wire Line
	7950 2950 8100 2950
Wire Wire Line
	7950 3050 8100 3050
NoConn ~ 7950 3150
NoConn ~ 6900 2950
NoConn ~ 6900 3150
NoConn ~ 6900 2850
NoConn ~ 6900 2750
NoConn ~ 6900 2650
NoConn ~ 6900 2550
NoConn ~ 6900 2450
NoConn ~ 6900 2350
$Comp
L BassedMateV1-rescue:GNDA-power #PWR013
U 1 1 62E7B262
P 6500 2300
F 0 "#PWR013" H 6500 2050 50  0001 C CNN
F 1 "GNDA" H 6500 2100 50  0000 C CNN
F 2 "" H 6500 2300 50  0001 C CNN
F 3 "" H 6500 2300 50  0001 C CNN
	1    6500 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 1950 6500 1950
Wire Wire Line
	6500 1950 6500 2150
Wire Wire Line
	6900 2150 6500 2150
Connection ~ 6500 2150
Wire Wire Line
	6500 2150 6500 2300
Wire Wire Line
	6900 2050 6750 2050
Wire Wire Line
	6750 2050 6750 2250
Wire Wire Line
	6750 2250 6900 2250
NoConn ~ 6900 1850
Text Notes 7100 6250 0    50   ~ 0
Battery Charger and Boost
Wire Wire Line
	1100 3800 1350 3800
Wire Wire Line
	1350 3800 1350 3750
Wire Wire Line
	1350 3450 1350 3400
Connection ~ 1350 3400
Wire Wire Line
	1350 3400 1600 3400
Connection ~ 4000 3350
Wire Wire Line
	4000 3350 4250 3350
Connection ~ 4150 3150
Wire Wire Line
	4150 3150 4250 3150
Wire Wire Line
	3800 3550 3800 3850
Wire Wire Line
	3800 3350 4000 3350
Wire Wire Line
	3800 3150 4150 3150
Wire Wire Line
	3800 3850 4000 3850
Connection ~ 3800 3850
Wire Wire Line
	3800 3850 3800 3900
$Comp
L UKMaker:MCP6024 U2
U 1 1 630B0550
P 2700 1100
F 0 "U2" H 2700 1467 50  0000 C CNN
F 1 "MCP6024" H 2700 1376 50  0000 C CNN
F 2 "" H 2650 1200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 2750 1300 50  0001 C CNN
	1    2700 1100
	1    0    0    -1  
$EndComp
$Comp
L UKMaker:MCP6024 U2
U 2 1 630B2CB7
P 5600 1900
F 0 "U2" H 5700 2050 50  0000 C CNN
F 1 "MCP6024" H 5600 2150 50  0000 C CNN
F 2 "" H 5550 2000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 5650 2100 50  0001 C CNN
	2    5600 1900
	1    0    0    1   
$EndComp
$Comp
L UKMaker:MCP6024 U2
U 3 1 630B493D
P 1900 3500
F 0 "U2" H 1900 3867 50  0000 C CNN
F 1 "MCP6024" H 1900 3776 50  0000 C CNN
F 2 "" H 1850 3600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 1950 3700 50  0001 C CNN
	3    1900 3500
	1    0    0    -1  
$EndComp
$Comp
L UKMaker:MCP6024 U2
U 5 1 630B65D7
P 2900 3450
F 0 "U2" H 2858 3496 50  0000 L CNN
F 1 "MCP6024" H 2858 3405 50  0000 L CNN
F 2 "" H 2850 3550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 2950 3650 50  0001 C CNN
	5    2900 3450
	1    0    0    -1  
$EndComp
$Comp
L UKMaker:MCP6024 U2
U 4 1 630B7947
P 5600 3350
F 0 "U2" H 5700 3500 50  0000 C CNN
F 1 "MCP6024" H 5600 3600 50  0000 C CNN
F 2 "" H 5550 3450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm2902-n.pdf" H 5650 3550 50  0001 C CNN
	4    5600 3350
	1    0    0    1   
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R40
U 1 1 630E6023
P 4750 3350
F 0 "R40" V 4650 3350 50  0000 C CNN
F 1 "47K" V 4850 3350 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 3350 50  0001 C CNN
F 3 "~" H 4750 3350 50  0001 C CNN
	1    4750 3350
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 6313DC3C
P 4400 1650
F 0 "C?" V 4350 1550 50  0000 C CNN
F 1 "100n" V 4239 1650 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 4438 1500 50  0001 C CNN
F 3 "~" H 4400 1650 50  0001 C CNN
	1    4400 1650
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 6313E10E
P 4400 1950
F 0 "C?" V 4350 1850 50  0000 C CNN
F 1 "100n" V 4239 1950 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 4438 1800 50  0001 C CNN
F 3 "~" H 4400 1950 50  0001 C CNN
	1    4400 1950
	0    1    1    0   
$EndComp
Connection ~ 3300 1100
Connection ~ 3550 1650
Connection ~ 3750 2300
Wire Wire Line
	3750 2300 4000 2300
Connection ~ 4000 2300
Wire Wire Line
	3300 1100 4000 1100
Wire Wire Line
	3550 1650 3750 1650
Wire Wire Line
	4000 2300 5200 2300
Wire Wire Line
	3950 1950 4250 1950
Wire Wire Line
	4200 1650 4250 1650
Wire Wire Line
	4550 1950 4650 1950
Wire Wire Line
	4550 1650 4650 1650
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 63333672
P 5600 2850
F 0 "C?" V 5550 2750 50  0000 C CNN
F 1 "180p" V 5439 2850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 5638 2700 50  0001 C CNN
F 3 "~" H 5600 2850 50  0001 C CNN
	1    5600 2850
	0    1    1    0   
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 63333A88
P 5600 1400
F 0 "C?" V 5550 1300 50  0000 C CNN
F 1 "220p" V 5439 1400 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 5638 1250 50  0001 C CNN
F 3 "~" H 5600 1400 50  0001 C CNN
	1    5600 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	5200 1600 5200 1400
Wire Wire Line
	5200 1400 5450 1400
Connection ~ 5200 1600
Wire Wire Line
	5750 1400 5950 1400
Wire Wire Line
	5950 1400 5950 1600
Connection ~ 5950 1600
Wire Wire Line
	5750 2850 5950 2850
Wire Wire Line
	5950 2850 5950 3050
Connection ~ 5950 3050
Wire Wire Line
	5450 2850 5200 2850
Wire Wire Line
	5200 2850 5200 3050
Connection ~ 5200 3050
$EndSCHEMATC
