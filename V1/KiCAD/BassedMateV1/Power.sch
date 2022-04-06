EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
L BassedMateV1-rescue:MC78L05_TO92-Regulator_Linear U?
U 1 1 60CE5B40
P 9750 1900
F 0 "U?" H 9750 2142 50  0000 C CNN
F 1 "LE33_TO92" H 9750 2051 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 9750 2125 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM78L05A.pdf" H 9750 1850 50  0001 C CNN
	1    9750 1900
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 60CE5B46
P 9300 2200
F 0 "C?" V 9048 2200 50  0000 C CNN
F 1 "C" V 9139 2200 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 9338 2050 50  0001 C CNN
F 3 "~" H 9300 2200 50  0001 C CNN
	1    9300 2200
	-1   0    0    1   
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 60CE5B4C
P 10200 2200
F 0 "C?" V 9948 2200 50  0000 C CNN
F 1 "C" V 10039 2200 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 10238 2050 50  0001 C CNN
F 3 "~" H 10200 2200 50  0001 C CNN
	1    10200 2200
	-1   0    0    1   
$EndComp
Wire Wire Line
	9300 2350 9300 2600
Wire Wire Line
	9300 2600 9750 2600
Wire Wire Line
	10200 2600 10200 2350
Wire Wire Line
	9750 2200 9750 2600
Connection ~ 9750 2600
Wire Wire Line
	9750 2600 10200 2600
$Comp
L BassedMateV1-rescue:GNDA-power #PWR?
U 1 1 60CE5B58
P 9750 3050
F 0 "#PWR?" H 9750 2800 50  0001 C CNN
F 1 "GNDA" H 9600 3000 50  0000 C CNN
F 2 "" H 9750 3050 50  0001 C CNN
F 3 "" H 9750 3050 50  0001 C CNN
	1    9750 3050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9450 1900 9300 1900
Wire Wire Line
	9300 1900 9300 1500
Wire Wire Line
	10050 1900 10200 1900
Wire Wire Line
	10200 1900 10200 1500
$Comp
L BassedMateV1-rescue:+3.3VA-power #PWR?
U 1 1 60CE5B63
P 10200 1500
F 0 "#PWR?" H 10200 1350 50  0001 C CNN
F 1 "+3.3VA" H 10215 1673 50  0000 C CNN
F 2 "" H 10200 1500 50  0001 C CNN
F 3 "" H 10200 1500 50  0001 C CNN
	1    10200 1500
	-1   0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:+5V-power #PWR?
U 1 1 60CE5B69
P 9300 1500
F 0 "#PWR?" H 9300 1350 50  0001 C CNN
F 1 "+5V" H 9315 1673 50  0000 C CNN
F 2 "" H 9300 1500 50  0001 C CNN
F 3 "" H 9300 1500 50  0001 C CNN
	1    9300 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 2050 9300 1900
Connection ~ 9300 1900
Wire Wire Line
	10200 2050 10200 1900
Connection ~ 10200 1900
$Comp
L BassedMateV1-rescue:GND-power #PWR?
U 1 1 60CE5B79
P 8900 3050
F 0 "#PWR?" H 8900 2800 50  0001 C CNN
F 1 "GND" H 8905 2877 50  0000 C CNN
F 2 "" H 8900 3050 50  0001 C CNN
F 3 "" H 8900 3050 50  0001 C CNN
	1    8900 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3050 8900 2850
Wire Wire Line
	9750 2850 8900 2850
Wire Wire Line
	9750 2850 9750 3050
Wire Wire Line
	9750 2600 9750 2850
Connection ~ 9750 2850
Wire Notes Line
	8400 6000 8400 950 
Wire Notes Line
	8600 950  8600 3550
Wire Notes Line
	8600 3550 10600 3550
Wire Notes Line
	10600 3550 10600 950 
Wire Notes Line
	10600 950  8600 950 
Text Notes 8700 3450 0    50   ~ 0
Analog Supply
$Comp
L BassedMateV1-rescue:MC33179-Amplifier_Operational U?
U 1 1 61048ADD
P 2600 2000
AR Path="/61048ADD" Ref="U?"  Part="1" 
AR Path="/60CBB86D/61048ADD" Ref="U?"  Part="1" 
F 0 "U?" H 2750 1900 50  0000 C CNN
F 1 "MC33179" H 2850 2100 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 2550 2100 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/MC33178-D.PDF" H 2650 2200 50  0001 C CNN
	1    2600 2000
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R?
U 1 1 61048AE3
P 1850 1700
AR Path="/61048AE3" Ref="R?"  Part="1" 
AR Path="/60CBB86D/61048AE3" Ref="R?"  Part="1" 
F 0 "R?" H 1920 1746 50  0000 L CNN
F 1 "R" H 1920 1655 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1780 1700 50  0001 C CNN
F 3 "~" H 1850 1700 50  0001 C CNN
	1    1850 1700
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:R-Device R?
U 1 1 61048AE9
P 1850 2100
AR Path="/61048AE9" Ref="R?"  Part="1" 
AR Path="/60CBB86D/61048AE9" Ref="R?"  Part="1" 
F 0 "R?" H 1920 2146 50  0000 L CNN
F 1 "R" H 1920 2055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1780 2100 50  0001 C CNN
F 3 "~" H 1850 2100 50  0001 C CNN
	1    1850 2100
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:GNDA-power #PWR?
U 1 1 61048AEF
P 1850 2700
AR Path="/61048AEF" Ref="#PWR?"  Part="1" 
AR Path="/60CBB86D/61048AEF" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1850 2450 50  0001 C CNN
F 1 "GNDA" H 1855 2527 50  0000 C CNN
F 2 "" H 1850 2700 50  0001 C CNN
F 3 "" H 1850 2700 50  0001 C CNN
	1    1850 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 1850 1850 1900
Wire Wire Line
	1850 2250 1850 2300
Wire Wire Line
	1850 1900 1850 1950
Wire Wire Line
	3000 2300 3000 2000
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 61048AFE
P 1650 2100
AR Path="/61048AFE" Ref="C?"  Part="1" 
AR Path="/60CBB86D/61048AFE" Ref="C?"  Part="1" 
F 0 "C?" H 1765 2146 50  0000 L CNN
F 1 "C" H 1765 2055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 1688 1950 50  0001 C CNN
F 3 "~" H 1650 2100 50  0001 C CNN
	1    1650 2100
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:CP-Device C?
U 1 1 61048B04
P 1400 2100
AR Path="/61048B04" Ref="C?"  Part="1" 
AR Path="/60CBB86D/61048B04" Ref="C?"  Part="1" 
F 0 "C?" H 1518 2146 50  0000 L CNN
F 1 "CP" H 1518 2055 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 1438 1950 50  0001 C CNN
F 3 "~" H 1400 2100 50  0001 C CNN
	1    1400 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1950 1400 1900
Wire Wire Line
	1400 1900 1650 1900
Wire Wire Line
	1650 1950 1650 1900
Connection ~ 1650 1900
Wire Wire Line
	1650 1900 1850 1900
Wire Wire Line
	1650 2250 1650 2300
Wire Wire Line
	1650 2300 1850 2300
Wire Wire Line
	1650 2300 1400 2300
Wire Wire Line
	1400 2300 1400 2250
Connection ~ 1650 2300
$Comp
L BassedMateV1-rescue:MC33179-Amplifier_Operational U?
U 5 1 61048B16
P 9700 5000
AR Path="/61048B16" Ref="U?"  Part="5" 
AR Path="/60CBB86D/61048B16" Ref="U?"  Part="5" 
F 0 "U?" H 9658 5046 50  0000 L CNN
F 1 "MC33179" H 9658 4955 50  0000 L CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket_LongPads" H 9650 5100 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/MC33178-D.PDF" H 9750 5200 50  0001 C CNN
	5    9700 5000
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:C-Device C?
U 1 1 61048B1C
P 9800 5000
AR Path="/61048B1C" Ref="C?"  Part="1" 
AR Path="/60CBB86D/61048B1C" Ref="C?"  Part="1" 
F 0 "C?" H 9915 5046 50  0000 L CNN
F 1 "C" H 9915 4955 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P7.50mm" H 9838 4850 50  0001 C CNN
F 3 "~" H 9800 5000 50  0001 C CNN
	1    9800 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 5300 9600 5350
Wire Wire Line
	9600 4700 9600 4650
Wire Wire Line
	9800 4850 9800 4650
Wire Wire Line
	9800 4650 9600 4650
Connection ~ 9600 4650
Wire Wire Line
	9600 4650 9600 4300
Wire Wire Line
	9800 5150 9800 5350
Wire Wire Line
	9800 5350 9600 5350
Connection ~ 9600 5350
$Comp
L BassedMateV1-rescue:+3.3VA-power #PWR?
U 1 1 61067D50
P 1850 1350
AR Path="/61067D50" Ref="#PWR?"  Part="1" 
AR Path="/60CBB86D/61067D50" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1850 1200 50  0001 C CNN
F 1 "+3.3VA" H 1865 1523 50  0000 C CNN
F 2 "" H 1850 1350 50  0001 C CNN
F 3 "" H 1850 1350 50  0001 C CNN
	1    1850 1350
	1    0    0    -1  
$EndComp
Text GLabel 3200 2000 2    50   Input ~ 0
VREF
Wire Wire Line
	3000 2000 3200 2000
Connection ~ 1850 1900
Wire Wire Line
	1850 2300 1850 2700
Connection ~ 1850 2300
Wire Wire Line
	1850 1350 1850 1550
Connection ~ 3000 2000
Wire Wire Line
	2900 2000 3000 2000
Wire Wire Line
	1850 1900 2300 1900
Wire Wire Line
	2300 2100 2150 2100
Wire Wire Line
	2150 2100 2150 2300
Wire Wire Line
	2150 2300 3000 2300
$Comp
L BassedMateV1-rescue:+3.3VA-power #PWR?
U 1 1 61091BD7
P 9600 4300
AR Path="/61091BD7" Ref="#PWR?"  Part="1" 
AR Path="/60CBB86D/61091BD7" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 9600 4150 50  0001 C CNN
F 1 "+3.3VA" H 9615 4473 50  0000 C CNN
F 2 "" H 9600 4300 50  0001 C CNN
F 3 "" H 9600 4300 50  0001 C CNN
	1    9600 4300
	1    0    0    -1  
$EndComp
$Comp
L BassedMateV1-rescue:GNDA-power #PWR?
U 1 1 61093E9C
P 9600 5650
AR Path="/61093E9C" Ref="#PWR?"  Part="1" 
AR Path="/60CBB86D/61093E9C" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 9600 5400 50  0001 C CNN
F 1 "GNDA" H 9605 5477 50  0000 C CNN
F 2 "" H 9600 5650 50  0001 C CNN
F 3 "" H 9600 5650 50  0001 C CNN
	1    9600 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 5350 9600 5650
Wire Notes Line
	650  950  3850 950 
Wire Notes Line
	3850 950  3850 3050
Wire Notes Line
	650  3050 650  950 
Wire Notes Line
	3850 3050 650  3050
Wire Notes Line
	8600 3900 10600 3900
Wire Notes Line
	10600 3900 10600 6000
Wire Notes Line
	10600 6000 8600 6000
Wire Notes Line
	8600 6000 8600 3900
Text Notes 750  2950 0    50   ~ 0
Reference Voltage
Text Notes 8700 5900 0    50   ~ 0
Decoupling
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 6194AA11
P 6400 3600
F 0 "Q?" V 6742 3600 50  0000 C CNN
F 1 "IRFU5305" V 6651 3600 50  0000 C CNN
F 2 "" H 6600 3700 50  0001 C CNN
F 3 "~" H 6400 3600 50  0001 C CNN
	1    6400 3600
	0    1    -1   0   
$EndComp
$Comp
L Device:Q_PNP_BCE Q?
U 1 1 6194CD6D
P 5500 4000
F 0 "Q?" H 5690 3954 50  0000 L CNN
F 1 "Q_PNP_BCE" H 5690 4045 50  0000 L CNN
F 2 "" H 5700 4100 50  0001 C CNN
F 3 "~" H 5500 4000 50  0001 C CNN
	1    5500 4000
	1    0    0    1   
$EndComp
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 6194DE90
P 6000 4850
F 0 "Q?" H 6191 4896 50  0000 L CNN
F 1 "Q_NPN_BCE" H 5650 5000 50  0000 L CNN
F 2 "" H 6200 4950 50  0001 C CNN
F 3 "~" H 6000 4850 50  0001 C CNN
	1    6000 4850
	1    0    0    -1  
$EndComp
$Comp
L UKMaker:ChargeBoost_Module U?
U 1 1 6195BA13
P 6050 2200
F 0 "U?" H 6000 2300 50  0000 L CNN
F 1 "ChargeBoost_Module" H 5650 2150 50  0000 L CNN
F 2 "" H 6050 2275 50  0001 C CNN
F 3 "" H 6050 2275 50  0001 C CNN
	1    6050 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 2750 5450 3000
$Comp
L SparkFun:M02JST-PTH-2 JP?
U 1 1 6197084C
P 4550 3100
F 0 "JP?" H 4658 3465 50  0000 C CNN
F 1 "M02JST-PTH-2" H 4658 3374 50  0000 C CNN
F 2 "SparkFun-JST-2-PTH" H 4550 3250 50  0001 C CNN
F 3 "" H 4550 3100 60  0000 C CNN
	1    4550 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3100 5750 3100
Wire Wire Line
	5750 3100 5750 2750
Connection ~ 5750 3100
Wire Wire Line
	5750 3100 5750 3500
$Comp
L Device:R R?
U 1 1 61979F10
P 5250 3750
F 0 "R?" H 5320 3796 50  0000 L CNN
F 1 "R" H 5320 3705 50  0000 L CNN
F 2 "" V 5180 3750 50  0001 C CNN
F 3 "~" H 5250 3750 50  0001 C CNN
	1    5250 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 3500 5750 3500
Connection ~ 5750 3500
Wire Wire Line
	5250 3900 5250 4000
Wire Wire Line
	5250 4000 5300 4000
Text GLabel 4600 4000 0    50   Input ~ 0
FE_B
$Comp
L Device:R R?
U 1 1 6198B06D
P 5000 4000
F 0 "R?" H 5070 4046 50  0000 L CNN
F 1 "R" H 5070 3955 50  0000 L CNN
F 2 "" V 4930 4000 50  0001 C CNN
F 3 "~" H 5000 4000 50  0001 C CNN
	1    5000 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 4000 4850 4000
Wire Wire Line
	5150 4000 5250 4000
Connection ~ 5250 4000
Wire Wire Line
	5450 1650 5450 1550
Wire Wire Line
	4800 1550 4800 1950
$Comp
L power:GND #PWR?
U 1 1 6199EA10
P 4800 1950
F 0 "#PWR?" H 4800 1700 50  0001 C CNN
F 1 "GND" H 4805 1777 50  0000 C CNN
F 2 "" H 4800 1950 50  0001 C CNN
F 3 "" H 4800 1950 50  0001 C CNN
	1    4800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 1650 6350 1550
Wire Wire Line
	6350 1550 5450 1550
Connection ~ 5450 1550
$Comp
L power:GND #PWR?
U 1 1 619AD2B6
P 6400 5400
F 0 "#PWR?" H 6400 5150 50  0001 C CNN
F 1 "GND" H 6405 5227 50  0000 C CNN
F 2 "" H 6400 5400 50  0001 C CNN
F 3 "" H 6400 5400 50  0001 C CNN
	1    6400 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3500 6100 3500
Wire Wire Line
	6600 3500 6650 3500
Wire Wire Line
	6650 3500 6650 2800
$Comp
L Device:CP C?
U 1 1 619D0AF3
P 6400 4850
F 0 "C?" H 6518 4896 50  0000 L CNN
F 1 "CP" H 6518 4805 50  0000 L CNN
F 2 "" H 6438 4700 50  0001 C CNN
F 3 "~" H 6400 4850 50  0001 C CNN
	1    6400 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 619D15F4
P 7300 4850
F 0 "R?" H 7370 4896 50  0000 L CNN
F 1 "R" H 7370 4805 50  0000 L CNN
F 2 "" V 7230 4850 50  0001 C CNN
F 3 "~" H 7300 4850 50  0001 C CNN
	1    7300 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 3800 6400 3950
$Comp
L Device:R R?
U 1 1 619F038F
P 6100 3750
F 0 "R?" H 6170 3796 50  0000 L CNN
F 1 "R" H 6170 3705 50  0000 L CNN
F 2 "" V 6030 3750 50  0001 C CNN
F 3 "~" H 6100 3750 50  0001 C CNN
	1    6100 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3600 6100 3500
Connection ~ 6100 3500
Wire Wire Line
	6100 3500 6200 3500
Wire Wire Line
	6100 4400 6400 4400
Text GLabel 7650 4850 2    50   Input ~ 0
BATTERY_ENABLE
Wire Wire Line
	6650 1650 6650 1550
Text GLabel 8000 1550 2    50   Output ~ 0
+5V
Wire Wire Line
	5750 1650 5750 1350
$Comp
L Device:D_Schottky D?
U 1 1 61C01F57
P 7400 1350
F 0 "D?" H 7400 1133 50  0000 C CNN
F 1 "D_Schottky" H 7400 1224 50  0000 C CNN
F 2 "" H 7400 1350 50  0001 C CNN
F 3 "~" H 7400 1350 50  0001 C CNN
	1    7400 1350
	-1   0    0    1   
$EndComp
Wire Wire Line
	5750 1350 7250 1350
Wire Wire Line
	7550 1350 7750 1350
Wire Wire Line
	7750 1350 7750 1550
Connection ~ 7750 1550
Wire Wire Line
	7750 1550 8000 1550
$Comp
L Device:R R?
U 1 1 61C112FA
P 5500 1350
F 0 "R?" H 5570 1396 50  0000 L CNN
F 1 "R" H 5570 1305 50  0000 L CNN
F 2 "" V 5430 1350 50  0001 C CNN
F 3 "~" H 5500 1350 50  0001 C CNN
	1    5500 1350
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 61C11FDA
P 5000 1350
F 0 "R?" H 5070 1396 50  0000 L CNN
F 1 "R" H 5070 1305 50  0000 L CNN
F 2 "" V 4930 1350 50  0001 C CNN
F 3 "~" H 5000 1350 50  0001 C CNN
	1    5000 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 1350 4800 1350
Wire Wire Line
	4800 1350 4800 1550
Connection ~ 4800 1550
Wire Wire Line
	5150 1350 5250 1350
Wire Wire Line
	5650 1350 5750 1350
Connection ~ 5750 1350
Wire Wire Line
	5250 1350 5250 1200
Wire Wire Line
	5250 1200 4800 1200
Connection ~ 5250 1350
Wire Wire Line
	5250 1350 5350 1350
Text GLabel 4800 1200 0    50   Output ~ 0
USB_POWER
Text GLabel 4600 4650 0    50   Output ~ 0
FE_BOC
Text Notes 4250 3300 0    50   ~ 0
Battery connector
Text Notes 4250 5900 0    50   ~ 0
Power On Control
Wire Notes Line
	8400 950  4150 950 
Wire Notes Line
	4150 6000 8400 6000
Wire Notes Line
	4150 950  4150 6000
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 61D93833
P 6800 4850
F 0 "Q?" H 6991 4896 50  0000 L CNN
F 1 "Q_NPN_BCE" H 6400 5000 50  0000 L CNN
F 2 "" H 7000 4950 50  0001 C CNN
F 3 "~" H 6800 4850 50  0001 C CNN
	1    6800 4850
	-1   0    0    -1  
$EndComp
Connection ~ 6400 4400
Wire Wire Line
	6100 5400 6400 5400
Wire Wire Line
	6400 5400 6700 5400
Wire Wire Line
	6700 5400 6700 5050
Connection ~ 6400 5400
Wire Wire Line
	6400 5000 6400 5400
Wire Wire Line
	6400 4400 6400 4700
Wire Wire Line
	6100 5050 6100 5400
Wire Wire Line
	6100 4650 6100 4400
Wire Wire Line
	6400 4400 6700 4400
Wire Wire Line
	6700 4400 6700 4650
Wire Wire Line
	7000 4850 7150 4850
Wire Wire Line
	7450 4850 7650 4850
Wire Wire Line
	5600 3500 5600 3800
$Comp
L Device:R R?
U 1 1 61DF1FB8
P 5600 4450
F 0 "R?" H 5670 4496 50  0000 L CNN
F 1 "R" H 5670 4405 50  0000 L CNN
F 2 "" V 5530 4450 50  0001 C CNN
F 3 "~" H 5600 4450 50  0001 C CNN
	1    5600 4450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61DF29DC
P 5600 5150
F 0 "R?" H 5670 5196 50  0000 L CNN
F 1 "R" H 5670 5105 50  0000 L CNN
F 2 "" V 5530 5150 50  0001 C CNN
F 3 "~" H 5600 5150 50  0001 C CNN
	1    5600 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 5400 5600 5400
Wire Wire Line
	5600 5400 5600 5300
Connection ~ 6100 5400
Wire Wire Line
	5600 5000 5600 4850
Wire Wire Line
	5600 4850 5800 4850
Connection ~ 5600 4850
Wire Wire Line
	5600 3500 5250 3500
Wire Wire Line
	5250 3500 5250 3600
Connection ~ 5600 3500
Wire Wire Line
	5600 4600 5600 4850
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 61E4C2FB
P 4850 4850
F 0 "Q?" H 5041 4896 50  0000 L CNN
F 1 "Q_NPN_BCE" H 4450 5000 50  0000 L CNN
F 2 "" H 5050 4950 50  0001 C CNN
F 3 "~" H 4850 4850 50  0001 C CNN
	1    4850 4850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4600 4650 4750 4650
Wire Wire Line
	5600 5400 5300 5400
Wire Wire Line
	4750 5400 4750 5050
Connection ~ 5600 5400
Wire Wire Line
	5600 4200 5600 4250
Wire Wire Line
	6100 3900 6100 3950
Wire Wire Line
	6100 3950 6400 3950
Connection ~ 6400 3950
Wire Wire Line
	6400 3950 6400 4400
Wire Wire Line
	4800 1550 5450 1550
Wire Wire Line
	4850 3000 5450 3000
Wire Wire Line
	6350 2750 6350 2800
Wire Wire Line
	6350 2800 6650 2800
Connection ~ 6650 2800
Wire Wire Line
	6650 2800 6650 2750
Wire Wire Line
	6650 1550 7750 1550
$Comp
L Device:R R?
U 1 1 621E4AF9
P 5300 4450
F 0 "R?" H 5370 4496 50  0000 L CNN
F 1 "R" H 5370 4405 50  0000 L CNN
F 2 "" V 5230 4450 50  0001 C CNN
F 3 "~" H 5300 4450 50  0001 C CNN
	1    5300 4450
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 621FB5BD
P 5300 5150
F 0 "R?" H 5370 5196 50  0000 L CNN
F 1 "R" H 5370 5105 50  0000 L CNN
F 2 "" V 5230 5150 50  0001 C CNN
F 3 "~" H 5300 5150 50  0001 C CNN
	1    5300 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 4850 5300 5000
Wire Wire Line
	5050 4850 5300 4850
Wire Wire Line
	5300 5300 5300 5400
Connection ~ 5300 5400
Wire Wire Line
	5300 5400 4750 5400
Wire Wire Line
	5300 4850 5300 4600
Connection ~ 5300 4850
Wire Wire Line
	5300 4300 5300 4250
Wire Wire Line
	5300 4250 5600 4250
Connection ~ 5600 4250
Wire Wire Line
	5600 4250 5600 4300
$EndSCHEMATC
