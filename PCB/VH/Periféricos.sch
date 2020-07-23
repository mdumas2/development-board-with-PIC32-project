EESchema Schematic File Version 4
LIBS:projeto(2)-cache
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
L projeto(2)-rescue:JHD162A-PBL_GuiKauMoc-cache DS1
U 1 1 5C84598F
P 3400 2700
F 0 "DS1" H 3600 1850 50  0000 C CNN
F 1 "JHD162A" H 3600 1950 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x16_Pitch2.54mm" H 3400 1800 50  0001 C CIN
F 3 "" H 3600 2800 50  0001 C CNN
	1    3400 2700
	1    0    0    -1  
$EndComp
$Comp
L Memory_EEPROM:24LC512 U7
U 1 1 5C845A8A
P 8550 2800
F 0 "U7" H 8350 2550 50  0000 C CNN
F 1 "24LC512" H 8300 2450 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 8550 2800 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21754M.pdf" H 8550 2800 50  0001 C CNN
	1    8550 2800
	-1   0    0    1   
$EndComp
Text Label 6900 4250 0    50   ~ 0
5V
$Comp
L projeto(2)-rescue:1825910-6-PBL_GuiKauMoc-cache SW1
U 1 1 5C845B8A
P 4450 4850
F 0 "SW1" H 4450 5117 50  0000 C CNN
F 1 "1825910-6" H 4450 5026 50  0000 C CNN
F 2 "1825910-6:1825910-6" H 4450 4850 50  0001 C CNN
F 3 "" H 4450 4850 50  0001 C CNN
	1    4450 4850
	1    0    0    -1  
$EndComp
$Comp
L projeto(2)-rescue:1825910-6-PBL_GuiKauMoc-cache SW2
U 1 1 5C845BE0
P 5500 4850
F 0 "SW2" H 5500 5117 50  0000 C CNN
F 1 "1825910-6" H 5500 5026 50  0000 C CNN
F 2 "1825910-6:1825910-6" H 5500 4850 50  0001 C CNN
F 3 "" H 5500 4850 50  0001 C CNN
	1    5500 4850
	1    0    0    -1  
$EndComp
$Comp
L projeto(2)-rescue:1825910-6-PBL_GuiKauMoc-cache SW3
U 1 1 5C845C16
P 6650 4850
F 0 "SW3" H 6650 5117 50  0000 C CNN
F 1 "1825910-6" H 6650 5026 50  0000 C CNN
F 2 "1825910-6:1825910-6" H 6650 4850 50  0001 C CNN
F 3 "" H 6650 4850 50  0001 C CNN
	1    6650 4850
	1    0    0    -1  
$EndComp
$Comp
L projeto(2)-rescue:1825910-6-PBL_GuiKauMoc-cache SW4
U 1 1 5C845C50
P 7750 4850
F 0 "SW4" H 7750 5117 50  0000 C CNN
F 1 "1825910-6" H 7750 5026 50  0000 C CNN
F 2 "1825910-6:1825910-6" H 7750 4850 50  0001 C CNN
F 3 "" H 7750 4850 50  0001 C CNN
	1    7750 4850
	1    0    0    -1  
$EndComp
$Comp
L projeto(2)-rescue:1825910-6-PBL_GuiKauMoc-cache SW5
U 1 1 5C845C8A
P 8850 4850
F 0 "SW5" H 8850 5117 50  0000 C CNN
F 1 "1825910-6" H 8850 5026 50  0000 C CNN
F 2 "1825910-6:1825910-6" H 8850 4850 50  0001 C CNN
F 3 "" H 8850 4850 50  0001 C CNN
	1    8850 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R15
U 1 1 5C845D4D
P 4900 5200
F 0 "R15" H 4959 5246 50  0000 L CNN
F 1 "6.8k" H 4959 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4900 5200 50  0001 C CNN
F 3 "~" H 4900 5200 50  0001 C CNN
	1    4900 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R16
U 1 1 5C845D8D
P 5950 5200
F 0 "R16" H 6009 5246 50  0000 L CNN
F 1 "3,3k" H 6009 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5950 5200 50  0001 C CNN
F 3 "~" H 5950 5200 50  0001 C CNN
	1    5950 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R17
U 1 1 5C845DC7
P 7100 5200
F 0 "R17" H 7159 5246 50  0000 L CNN
F 1 "1k" H 7159 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7100 5200 50  0001 C CNN
F 3 "~" H 7100 5200 50  0001 C CNN
	1    7100 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R18
U 1 1 5C845E03
P 8200 5200
F 0 "R18" H 8259 5246 50  0000 L CNN
F 1 "470" H 8259 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8200 5200 50  0001 C CNN
F 3 "~" H 8200 5200 50  0001 C CNN
	1    8200 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R19
U 1 1 5C845E67
P 9350 5200
F 0 "R19" H 9409 5246 50  0000 L CNN
F 1 "100" H 9409 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9350 5200 50  0001 C CNN
F 3 "~" H 9350 5200 50  0001 C CNN
	1    9350 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R20
U 1 1 5C845EAE
P 6650 5800
F 0 "R20" V 6846 5800 50  0000 C CNN
F 1 "1k" V 6755 5800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6650 5800 50  0001 C CNN
F 3 "~" H 6650 5800 50  0001 C CNN
	1    6650 5800
	0    -1   -1   0   
$EndComp
Text HLabel 7250 5800 2    50   Input ~ 0
TECLADO
Wire Wire Line
	4800 4800 4900 4800
Wire Wire Line
	4900 4800 4900 4900
Wire Wire Line
	4800 4900 4900 4900
Connection ~ 4900 4900
Wire Wire Line
	4900 4900 4900 5100
Wire Wire Line
	5850 4900 5950 4900
Wire Wire Line
	5950 4900 5950 5100
Wire Wire Line
	5850 4800 5950 4800
Wire Wire Line
	5950 4800 5950 4900
Connection ~ 5950 4900
Wire Wire Line
	7000 4900 7100 4900
Wire Wire Line
	7100 4900 7100 5100
Wire Wire Line
	7000 4800 7100 4800
Wire Wire Line
	7100 4800 7100 4900
Connection ~ 7100 4900
Wire Wire Line
	8100 4900 8200 4900
Wire Wire Line
	8200 4900 8200 5100
Wire Wire Line
	8100 4800 8200 4800
Wire Wire Line
	8200 4800 8200 4900
Connection ~ 8200 4900
Wire Wire Line
	9200 4900 9350 4900
Wire Wire Line
	9350 4900 9350 5100
Wire Wire Line
	9200 4800 9350 4800
Wire Wire Line
	9350 4800 9350 4900
Connection ~ 9350 4900
Wire Wire Line
	4100 4800 4100 4400
Wire Wire Line
	4100 4400 5050 4400
Wire Wire Line
	6900 4400 6900 4250
Wire Wire Line
	4100 4900 4100 4800
Connection ~ 4100 4800
Wire Wire Line
	5150 4800 5050 4800
Wire Wire Line
	5050 4800 5050 4400
Connection ~ 5050 4400
Wire Wire Line
	5050 4400 6150 4400
Wire Wire Line
	5150 4900 5050 4900
Wire Wire Line
	5050 4900 5050 4800
Connection ~ 5050 4800
Wire Wire Line
	6300 4800 6150 4800
Wire Wire Line
	6150 4800 6150 4400
Connection ~ 6150 4400
Wire Wire Line
	6150 4400 6900 4400
Wire Wire Line
	6300 4900 6150 4900
Wire Wire Line
	6150 4900 6150 4800
Connection ~ 6150 4800
Wire Wire Line
	7400 4800 7250 4800
Wire Wire Line
	7250 4800 7250 4400
Wire Wire Line
	7250 4400 6900 4400
Connection ~ 6900 4400
Wire Wire Line
	7400 4900 7250 4900
Wire Wire Line
	7250 4900 7250 4800
Connection ~ 7250 4800
Wire Wire Line
	8500 4800 8400 4800
Wire Wire Line
	8400 4800 8400 4400
Wire Wire Line
	8400 4400 7250 4400
Connection ~ 7250 4400
Wire Wire Line
	8500 4900 8400 4900
Wire Wire Line
	8400 4900 8400 4800
Connection ~ 8400 4800
Wire Wire Line
	7100 5300 7100 5400
Wire Wire Line
	7100 5800 7250 5800
Wire Wire Line
	5950 5300 5950 5400
Wire Wire Line
	5950 5400 7100 5400
Connection ~ 7100 5400
Wire Wire Line
	7100 5400 7100 5800
Wire Wire Line
	4900 5300 4900 5400
Wire Wire Line
	4900 5400 5950 5400
Connection ~ 5950 5400
Wire Wire Line
	8200 5300 8200 5400
Wire Wire Line
	8200 5400 7100 5400
Wire Wire Line
	9350 5300 9350 5400
Wire Wire Line
	9350 5400 8200 5400
Connection ~ 8200 5400
Wire Wire Line
	7100 5800 6750 5800
Connection ~ 7100 5800
Text HLabel 2600 2100 0    49   Input ~ 0
E
Text HLabel 2600 2400 0    49   Input ~ 0
RS
Text HLabel 2600 3000 0    49   Input ~ 0
LCD1
Text HLabel 2600 3100 0    49   Input ~ 0
LCD2
Text HLabel 2600 3200 0    49   Input ~ 0
LCD3
Text HLabel 2600 3300 0    49   Input ~ 0
LCD4
Wire Wire Line
	2600 2400 3000 2400
Wire Wire Line
	2600 2100 3000 2100
Wire Wire Line
	2600 3000 3000 3000
Wire Wire Line
	2600 3100 3000 3100
Wire Wire Line
	2600 3200 3000 3200
Wire Wire Line
	2600 3300 3000 3300
Wire Wire Line
	3000 2300 2700 2300
Text Label 3400 1650 0    49   ~ 0
5V
Wire Wire Line
	3400 1650 3400 1800
Wire Wire Line
	3400 3500 3400 3600
$Comp
L Device:C_Small C22
U 1 1 5C8653BF
P 2050 2650
F 0 "C22" H 2142 2696 50  0000 L CNN
F 1 "100nF" H 2142 2605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2050 2650 50  0001 C CNN
F 3 "~" H 2050 2650 50  0001 C CNN
	1    2050 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 1800 2050 1800
Wire Wire Line
	2050 1800 2050 2550
Connection ~ 3400 1800
Wire Wire Line
	3400 1800 3400 1900
Wire Wire Line
	2050 2750 2050 3600
Wire Wire Line
	2050 3600 3400 3600
Connection ~ 3400 3600
Wire Wire Line
	3400 3600 3400 3700
Text Label 4250 1750 0    49   ~ 0
5V
$Comp
L projeto(2)-rescue:POT-PBL_GuiKauMoc-rescue POT2
U 1 1 5C86840D
P 4250 2100
F 0 "POT2" H 4181 2054 50  0000 R CNN
F 1 "10k" H 4181 2145 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 4250 2100 50  0001 C CNN
F 3 "" H 4250 2100 50  0001 C CNN
	1    4250 2100
	-1   0    0    1   
$EndComp
Wire Wire Line
	3800 2100 4100 2100
Wire Wire Line
	4250 1750 4250 1950
Wire Wire Line
	4250 2250 4250 2450
$Comp
L Device:R_Small R12
U 1 1 5C86DB3D
P 4050 3000
F 0 "R12" H 4109 3046 50  0000 L CNN
F 1 "470" H 4109 2955 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4050 3000 50  0001 C CNN
F 3 "~" H 4050 3000 50  0001 C CNN
	1    4050 3000
	1    0    0    -1  
$EndComp
Text Label 4050 3300 0    49   ~ 0
5V
Wire Wire Line
	3800 2800 4050 2800
Wire Wire Line
	4050 2800 4050 2900
Wire Wire Line
	4050 3100 4050 3300
Text Label 7250 1900 0    49   ~ 0
5V
$Comp
L Device:R_Small R14
U 1 1 5C87D7D7
P 7600 2300
F 0 "R14" H 7659 2346 50  0000 L CNN
F 1 "10k" H 7659 2255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7600 2300 50  0001 C CNN
F 3 "~" H 7600 2300 50  0001 C CNN
	1    7600 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R13
U 1 1 5C87D879
P 7250 2300
F 0 "R13" H 7309 2346 50  0000 L CNN
F 1 "10k" H 7309 2255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7250 2300 50  0001 C CNN
F 3 "~" H 7250 2300 50  0001 C CNN
	1    7250 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 1900 7250 2050
Wire Wire Line
	7250 2050 7600 2050
Wire Wire Line
	7600 2050 7600 2200
Connection ~ 7250 2050
Wire Wire Line
	7250 2050 7250 2200
Text HLabel 6850 2800 0    49   Input ~ 0
SCL
Text HLabel 6850 2900 0    49   Input ~ 0
SDA
Wire Wire Line
	6850 2800 7250 2800
Wire Wire Line
	6850 2900 7600 2900
Wire Wire Line
	7250 2400 7250 2800
Connection ~ 7250 2800
Wire Wire Line
	7250 2800 8150 2800
Wire Wire Line
	7600 2400 7600 2900
Connection ~ 7600 2900
Wire Wire Line
	7600 2900 8150 2900
Text Label 8550 3400 0    49   ~ 0
3.3V
Wire Wire Line
	8550 3100 8550 3200
$Comp
L Device:C_Small C23
U 1 1 5C88E8F0
P 9550 2800
F 0 "C23" H 9642 2846 50  0000 L CNN
F 1 "100nF" H 9642 2755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9550 2800 50  0001 C CNN
F 3 "~" H 9550 2800 50  0001 C CNN
	1    9550 2800
	1    0    0    -1  
$EndComp
Connection ~ 8550 3200
Wire Wire Line
	8550 3200 8550 3400
Wire Wire Line
	8550 2300 8550 2500
Wire Wire Line
	8550 2300 8550 2100
Connection ~ 8550 2300
Wire Wire Line
	8150 2700 8050 2700
Wire Wire Line
	8050 2700 8050 2500
Wire Wire Line
	9550 3200 9550 2900
Wire Wire Line
	8550 3200 9550 3200
Wire Wire Line
	9550 2300 9550 2700
Wire Wire Line
	8550 2300 9150 2300
NoConn ~ 3000 2900
NoConn ~ 3000 2800
NoConn ~ 3000 2700
NoConn ~ 3000 2600
Wire Wire Line
	8950 2700 9150 2700
Wire Wire Line
	9150 2700 9150 2300
Connection ~ 9150 2300
Wire Wire Line
	9150 2300 9550 2300
Wire Wire Line
	8950 2800 9150 2800
Wire Wire Line
	9150 2800 9150 2700
Connection ~ 9150 2700
Wire Wire Line
	8950 2900 9150 2900
Wire Wire Line
	9150 2900 9150 2800
Connection ~ 9150 2800
Text HLabel 1850 4100 0    50   Input ~ 0
5V
Text HLabel 1850 4300 0    50   Input ~ 0
3.3V
Text Label 2250 4100 0    50   ~ 0
5V
Text Label 2250 4300 0    50   ~ 0
3.3V
Wire Wire Line
	1850 4300 2250 4300
Wire Wire Line
	1850 4100 2250 4100
$Comp
L power:GND #PWR0121
U 1 1 5C98DDB1
P 2700 2300
F 0 "#PWR0121" H 2700 2050 50  0001 C CNN
F 1 "GND" V 2705 2172 50  0000 R CNN
F 2 "" H 2700 2300 50  0001 C CNN
F 3 "" H 2700 2300 50  0001 C CNN
	1    2700 2300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5C98DE0C
P 3400 3700
F 0 "#PWR0122" H 3400 3450 50  0001 C CNN
F 1 "GND" H 3405 3527 50  0000 C CNN
F 2 "" H 3400 3700 50  0001 C CNN
F 3 "" H 3400 3700 50  0001 C CNN
	1    3400 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5C98DE54
P 4250 2450
F 0 "#PWR0123" H 4250 2200 50  0001 C CNN
F 1 "GND" H 4255 2277 50  0000 C CNN
F 2 "" H 4250 2450 50  0001 C CNN
F 3 "" H 4250 2450 50  0001 C CNN
	1    4250 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5C98DE9C
P 3900 2700
F 0 "#PWR0124" H 3900 2450 50  0001 C CNN
F 1 "GND" V 3905 2572 50  0000 R CNN
F 2 "" H 3900 2700 50  0001 C CNN
F 3 "" H 3900 2700 50  0001 C CNN
	1    3900 2700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3800 2700 3900 2700
$Comp
L power:GND #PWR0125
U 1 1 5C991682
P 8550 2100
F 0 "#PWR0125" H 8550 1850 50  0001 C CNN
F 1 "GND" H 8555 1927 50  0000 C CNN
F 2 "" H 8550 2100 50  0001 C CNN
F 3 "" H 8550 2100 50  0001 C CNN
	1    8550 2100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0126
U 1 1 5C99170C
P 8050 2500
F 0 "#PWR0126" H 8050 2250 50  0001 C CNN
F 1 "GND" H 8055 2327 50  0000 C CNN
F 2 "" H 8050 2500 50  0001 C CNN
F 3 "" H 8050 2500 50  0001 C CNN
	1    8050 2500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0127
U 1 1 5C995214
P 6150 5800
F 0 "#PWR0127" H 6150 5550 50  0001 C CNN
F 1 "GND" V 6155 5672 50  0000 R CNN
F 2 "" H 6150 5800 50  0001 C CNN
F 3 "" H 6150 5800 50  0001 C CNN
	1    6150 5800
	0    1    1    0   
$EndComp
Wire Wire Line
	6150 5800 6550 5800
$EndSCHEMATC
