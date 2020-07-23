EESchema Schematic File Version 4
LIBS:projeto(2)-cache
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
Text Label 2000 1750 0    50   ~ 0
5V
$Comp
L Device:C_Small C5
U 1 1 5C83CCE6
P 2300 1850
F 0 "C5" H 2392 1896 50  0000 L CNN
F 1 "100nF" H 2392 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2300 1850 50  0001 C CNN
F 3 "~" H 2300 1850 50  0001 C CNN
	1    2300 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5C83CD1C
P 2700 1850
F 0 "C6" H 2792 1896 50  0000 L CNN
F 1 "100nF" H 2792 1805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2700 1850 50  0001 C CNN
F 3 "~" H 2700 1850 50  0001 C CNN
	1    2700 1850
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C8
U 1 1 5C83D000
P 4500 2400
F 0 "C8" H 4408 2354 50  0000 R CNN
F 1 "100nF" H 4408 2445 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4500 2400 50  0001 C CNN
F 3 "~" H 4500 2400 50  0001 C CNN
	1    4500 2400
	-1   0    0    1   
$EndComp
$Comp
L Connector:USB_B J2
U 1 1 5C83D11C
P 2450 3100
F 0 "J2" H 2450 3550 50  0000 C CNN
F 1 "USB_B" H 2450 3450 50  0000 C CNN
F 2 "Connectorss:USB_B" H 2600 3050 50  0001 C CNN
F 3 " ~" H 2600 3050 50  0001 C CNN
	1    2450 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3100 2800 3100
Wire Wire Line
	4800 3200 2950 3200
$Comp
L Device:R_Small R2
U 1 1 5C83D1BA
P 3100 3400
F 0 "R2" H 3159 3446 50  0000 L CNN
F 1 "4.7k" H 3159 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3100 3400 50  0001 C CNN
F 3 "~" H 3100 3400 50  0001 C CNN
	1    3100 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R3
U 1 1 5C83D226
P 3100 3700
F 0 "R3" H 3159 3746 50  0000 L CNN
F 1 "10k" H 3159 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3100 3700 50  0001 C CNN
F 3 "~" H 3100 3700 50  0001 C CNN
	1    3100 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 2900 3100 2900
Wire Wire Line
	3100 2900 3100 3300
Wire Wire Line
	3100 3500 3100 3550
Wire Wire Line
	2450 3500 2450 3650
Wire Wire Line
	2350 3500 2350 3650
Wire Wire Line
	2350 3650 2450 3650
Connection ~ 2450 3650
Wire Wire Line
	2450 3650 2450 3800
Wire Wire Line
	3100 3550 3750 3550
Wire Wire Line
	3750 3550 3750 3500
Wire Wire Line
	3750 3500 4600 3500
Connection ~ 3100 3550
Wire Wire Line
	3100 3550 3100 3600
Wire Wire Line
	2300 1750 2000 1750
Wire Wire Line
	2300 1750 2700 1750
Connection ~ 2300 1750
Connection ~ 2700 1750
Wire Wire Line
	4800 2800 4500 2800
Wire Wire Line
	4500 2800 4500 2500
Wire Wire Line
	2700 1950 2700 2050
Connection ~ 2700 2050
Wire Wire Line
	2700 2050 2700 2200
Wire Wire Line
	2300 1950 2300 2050
Wire Wire Line
	2300 2050 2700 2050
Wire Wire Line
	4800 4200 4750 4200
Wire Wire Line
	4750 4200 4750 4550
Wire Wire Line
	5400 4500 5400 4550
Wire Wire Line
	5400 4550 4750 4550
Connection ~ 4750 4550
Wire Wire Line
	4750 4550 4750 4600
Wire Wire Line
	5600 4500 5600 4600
Wire Wire Line
	5600 4600 4750 4600
Connection ~ 4750 4600
Wire Wire Line
	4750 4600 4750 4700
Wire Wire Line
	5700 4500 5700 4700
Wire Wire Line
	5700 4700 4750 4700
Connection ~ 4750 4700
Wire Wire Line
	4750 4700 4750 4800
Wire Wire Line
	5800 4500 5800 4800
Wire Wire Line
	5800 4800 4750 4800
Text HLabel 1600 2250 0    50   Input ~ 0
5V
Text Label 1800 2250 0    50   ~ 0
5V
Wire Wire Line
	1600 2250 1800 2250
$Comp
L Interface_USB:MCP2200-I-SO U4
U 1 1 5C8A9667
P 5450 6250
F 0 "U4" H 5450 6050 50  0000 C CNN
F 1 "MCP2200-I-SO" H 5450 6150 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 5450 5100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/200022228D.pdf" H 5450 5250 50  0001 C CNN
	1    5450 6250
	-1   0    0    1   
$EndComp
Wire Wire Line
	2950 3200 2950 6650
Wire Wire Line
	2950 6650 4550 6650
Connection ~ 2950 3200
Wire Wire Line
	2950 3200 2750 3200
Wire Wire Line
	2800 3100 2800 6850
Wire Wire Line
	2800 6850 4550 6850
Connection ~ 2800 3100
Wire Wire Line
	2800 3100 2750 3100
$Comp
L Device:Crystal_Small Y1
U 1 1 5C8AC742
P 3850 5750
F 0 "Y1" V 3804 5838 50  0000 L CNN
F 1 "12MHz" V 3895 5838 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-4H_Vertical" H 3850 5750 50  0001 C CNN
F 3 "~" H 3850 5750 50  0001 C CNN
	1    3850 5750
	0    1    1    0   
$EndComp
$Comp
L Device:C_Small C9
U 1 1 5C8AC7A5
P 3550 5600
F 0 "C9" H 3642 5646 50  0000 L CNN
F 1 "22pF" H 3642 5555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3550 5600 50  0001 C CNN
F 3 "~" H 3550 5600 50  0001 C CNN
	1    3550 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C10
U 1 1 5C8AC7DB
P 3550 5900
F 0 "C10" H 3642 5946 50  0000 L CNN
F 1 "22pF" H 3642 5855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3550 5900 50  0001 C CNN
F 3 "~" H 3550 5900 50  0001 C CNN
	1    3550 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 5500 3550 5350
Wire Wire Line
	3550 5350 3850 5350
Wire Wire Line
	3850 5350 3850 5650
Wire Wire Line
	3550 6000 3550 6200
Wire Wire Line
	3550 6200 3850 6200
Wire Wire Line
	3850 6200 3850 5850
Wire Wire Line
	3550 5700 3550 5750
Wire Wire Line
	3550 5750 3250 5750
Connection ~ 3550 5750
Wire Wire Line
	3550 5750 3550 5800
Wire Wire Line
	3850 5350 4550 5350
Wire Wire Line
	4550 5350 4550 5650
Connection ~ 3850 5350
Wire Wire Line
	3850 6200 4550 6200
Wire Wire Line
	4550 6200 4550 5850
Connection ~ 3850 6200
$Comp
L Device:C_Small C11
U 1 1 5C9045F2
P 5450 5250
F 0 "C11" H 5200 5300 50  0000 L CNN
F 1 "100nF" H 5100 5200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5450 5250 50  0001 C CNN
F 3 "~" H 5450 5250 50  0001 C CNN
	1    5450 5250
	1    0    0    -1  
$EndComp
Text Label 4600 3400 1    50   ~ 0
RST
Wire Wire Line
	4600 3400 4600 3500
Connection ~ 4600 3500
Wire Wire Line
	4600 3500 4800 3500
Text Label 6450 6850 0    50   ~ 0
RST
Wire Wire Line
	6450 6850 6350 6850
Text Label 5550 7350 3    50   ~ 0
VDDmcp
NoConn ~ 6400 3000
NoConn ~ 6400 3100
NoConn ~ 6400 3200
NoConn ~ 6400 3300
NoConn ~ 6400 3400
NoConn ~ 6400 3500
NoConn ~ 6400 3800
NoConn ~ 6400 3900
NoConn ~ 6400 4000
NoConn ~ 6400 4100
NoConn ~ 6400 4200
NoConn ~ 6350 5650
NoConn ~ 6350 5750
NoConn ~ 6350 5850
NoConn ~ 6350 5950
NoConn ~ 6350 6050
NoConn ~ 6350 6150
NoConn ~ 6350 6250
NoConn ~ 6350 6350
NoConn ~ 6350 6450
NoConn ~ 6350 6550
Text HLabel 1550 2400 0    50   Input ~ 0
3.3V
Text Label 1800 2400 0    50   ~ 0
3.3V
Wire Wire Line
	1550 2400 1800 2400
Text Label 5500 2400 0    50   ~ 0
3.3V
Wire Wire Line
	5500 2400 5500 2500
NoConn ~ 4800 3700
NoConn ~ 4800 3900
$Comp
L power:GND #PWR0110
U 1 1 5C935DCA
P 2450 3800
F 0 "#PWR0110" H 2450 3550 50  0001 C CNN
F 1 "GND" H 2455 3627 50  0000 C CNN
F 2 "" H 2450 3800 50  0001 C CNN
F 3 "" H 2450 3800 50  0001 C CNN
	1    2450 3800
	1    0    0    -1  
$EndComp
Text HLabel 6600 2800 2    50   Input ~ 0
TX
Text HLabel 6600 2900 2    50   Input ~ 0
RX
Text HLabel 6500 6650 2    50   Input ~ 0
TX
Wire Wire Line
	6500 6650 6350 6650
$Comp
L projeto(2)-rescue:FT232RL-PBL_GuiKauMoc-rescue U3
U 1 1 5C94A64A
P 5600 3500
AR Path="/5C94A64A" Ref="U3"  Part="1" 
AR Path="/5C83CC04/5C94A64A" Ref="U3"  Part="1" 
F 0 "U3" H 5600 3550 50  0000 C CNN
F 1 "FT232RL" H 5600 3450 50  0000 C CNN
F 2 "Housings_SSOP:SSOP-28_5.3x10.2mm_Pitch0.65mm" H 5600 3500 50  0001 C CNN
F 3 "" H 5600 3500 50  0001 C CNN
	1    5600 3500
	1    0    0    -1  
$EndComp
Text HLabel 6500 6750 2    50   Input ~ 0
RX
Wire Wire Line
	6350 6750 6500 6750
Wire Wire Line
	6400 2800 6600 2800
Wire Wire Line
	6600 2900 6400 2900
$Comp
L power:GND #PWR0109
U 1 1 5C97AE95
P 2700 2200
F 0 "#PWR0109" H 2700 1950 50  0001 C CNN
F 1 "GND" H 2705 2027 50  0000 C CNN
F 2 "" H 2700 2200 50  0001 C CNN
F 3 "" H 2700 2200 50  0001 C CNN
	1    2700 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5C97AED1
P 4500 2150
F 0 "#PWR0111" H 4500 1900 50  0001 C CNN
F 1 "GND" H 4505 1977 50  0000 C CNN
F 2 "" H 4500 2150 50  0001 C CNN
F 3 "" H 4500 2150 50  0001 C CNN
	1    4500 2150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 2300 4500 2150
$Comp
L power:GND #PWR0112
U 1 1 5C97C7F4
P 3100 3950
F 0 "#PWR0112" H 3100 3700 50  0001 C CNN
F 1 "GND" H 3105 3777 50  0000 C CNN
F 2 "" H 3100 3950 50  0001 C CNN
F 3 "" H 3100 3950 50  0001 C CNN
	1    3100 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3800 3100 3950
$Comp
L power:GND #PWR0113
U 1 1 5C97DE26
P 4750 4950
F 0 "#PWR0113" H 4750 4700 50  0001 C CNN
F 1 "GND" H 4755 4777 50  0000 C CNN
F 2 "" H 4750 4950 50  0001 C CNN
F 3 "" H 4750 4950 50  0001 C CNN
	1    4750 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5C97DE62
P 5450 5150
F 0 "#PWR0114" H 5450 4900 50  0001 C CNN
F 1 "GND" H 5455 4977 50  0000 C CNN
F 2 "" H 5450 5150 50  0001 C CNN
F 3 "" H 5450 5150 50  0001 C CNN
	1    5450 5150
	-1   0    0    1   
$EndComp
Wire Wire Line
	4750 4950 4750 4800
Connection ~ 4750 4800
$Comp
L power:GND #PWR0120
U 1 1 5C982C4E
P 3250 5750
F 0 "#PWR0120" H 3250 5500 50  0001 C CNN
F 1 "GND" V 3255 5622 50  0000 R CNN
F 2 "" H 3250 5750 50  0001 C CNN
F 3 "" H 3250 5750 50  0001 C CNN
	1    3250 5750
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J12
U 1 1 5CC262A2
P 8400 4100
F 0 "J12" H 8480 4092 50  0000 L CNN
F 1 "TX/RX" H 8480 4001 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 8400 4100 50  0001 C CNN
F 3 "~" H 8400 4100 50  0001 C CNN
	1    8400 4100
	1    0    0    -1  
$EndComp
Text HLabel 7950 4100 0    50   Input ~ 0
TX
Text HLabel 7950 4200 0    50   Input ~ 0
RX
Wire Wire Line
	7950 4100 8200 4100
Wire Wire Line
	7950 4200 8200 4200
$Comp
L Device:C_Small C7
U 1 1 5CC486B2
P 2750 1200
F 0 "C7" H 2842 1246 50  0000 L CNN
F 1 "100nF" H 2842 1155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2750 1200 50  0001 C CNN
F 3 "~" H 2750 1200 50  0001 C CNN
	1    2750 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5CBD1584
P 2750 1400
F 0 "#PWR0115" H 2750 1150 50  0001 C CNN
F 1 "GND" H 2755 1227 50  0000 C CNN
F 2 "" H 2750 1400 50  0001 C CNN
F 3 "" H 2750 1400 50  0001 C CNN
	1    2750 1400
	1    0    0    -1  
$EndComp
Text Label 2050 950  0    50   ~ 0
3.3v
Wire Wire Line
	2700 1750 5700 1750
Text Label 3200 950  0    50   ~ 0
VDDmcp
Wire Wire Line
	2750 1400 2750 1300
Wire Wire Line
	2050 950  2750 950 
Wire Wire Line
	2750 1100 2750 950 
Connection ~ 2750 950 
Wire Wire Line
	2750 950  3200 950 
Wire Wire Line
	5700 1750 5700 2500
Wire Wire Line
	5550 7050 5550 7250
Wire Wire Line
	5550 7250 5350 7250
Wire Wire Line
	5350 7050 5350 7250
Connection ~ 5550 7250
Wire Wire Line
	5550 7250 5550 7350
Wire Wire Line
	5450 5350 5450 5450
$EndSCHEMATC
