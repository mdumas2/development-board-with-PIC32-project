EESchema Schematic File Version 4
LIBS:projeto(2)-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 5500 3550 1250 1250
U 5C833FD6
F0 "microcontrolador" 50
F1 "microcontrolador.sch" 50
F2 "SCL" I R 6750 3950 50 
F3 "SDA" I R 6750 4050 50 
F4 "E" I R 6750 4150 50 
F5 "RS" I R 6750 4250 50 
F6 "TECLADO" I R 6750 4750 50 
F7 "3.3V" I L 5500 3650 50 
F8 "5V" I L 5500 3800 50 
F9 "IN1" I R 6750 3600 50 
F10 "IN2" I R 6750 3700 50 
F11 "TX" I L 5500 4450 50 
F12 "RX" I L 5500 4600 50 
F13 "IN3" I R 6750 3800 50 
F14 "PWM" I L 5500 3950 50 
F15 "RC4" I R 6750 4550 50 
F16 "RD0" I R 6750 4350 50 
F17 "RC5" I R 6750 4650 50 
F18 "RC3" I R 6750 4450 50 
$EndSheet
$Sheet
S 3400 4400 1450 400 
U 5C83CC04
F0 "Comunicação" 50
F1 "Comunicação.sch" 50
F2 "RX" I R 4850 4450 50 
F3 "TX" I R 4850 4600 50 
F4 "3.3V" I L 3400 4500 50 
F5 "5V" I L 3400 4650 50 
$EndSheet
$Sheet
S 3350 3550 1500 500 
U 5C84260A
F0 "Alimentação" 50
F1 "Alimentação.sch" 50
F2 "3.3V" I R 4850 3650 50 
F3 "5V" I R 4850 3800 50 
$EndSheet
$Sheet
S 7250 3900 1400 900 
U 5C845963
F0 "Periféricos" 50
F1 "Periféricos.sch" 50
F2 "SCL" I L 7250 3950 50 
F3 "SDA" I L 7250 4050 50 
F4 "E" I L 7250 4150 50 
F5 "RS" I L 7250 4250 50 
F6 "LCD1" I L 7250 4350 50 
F7 "LCD2" I L 7250 4450 50 
F8 "LCD3" I L 7250 4550 50 
F9 "LCD4" I L 7250 4650 50 
F10 "TECLADO" I L 7250 4750 50 
F11 "5V" I R 8650 4150 50 
F12 "3.3V" I R 8650 4300 50 
$EndSheet
Wire Wire Line
	6750 4150 7250 4150
Wire Wire Line
	6750 4250 7250 4250
Wire Wire Line
	7250 4350 6750 4350
Wire Wire Line
	7250 4450 6750 4450
Wire Wire Line
	7250 4550 6750 4550
Wire Wire Line
	7250 4650 6750 4650
Wire Wire Line
	6750 4050 7250 4050
$Sheet
S 7350 2700 1200 750 
U 5C845365
F0 "Interface" 50
F1 "Interface.sch" 50
F2 "PWM" I L 7350 2750 50 
F3 "IN1" I L 7350 2900 50 
F4 "IN2" I L 7350 3050 50 
F5 "5V" I R 8550 2950 50 
F6 "3.3V" I R 8550 3100 50 
F7 "IN3" I L 7350 3200 50 
$EndSheet
Wire Wire Line
	6750 4750 7250 4750
Text Label 4950 3650 0    50   ~ 0
3.3V
Text Label 4950 3800 0    50   ~ 0
5V
Text Label 5400 3650 2    50   ~ 0
3.3V
Text Label 5400 3800 2    50   ~ 0
5V
Text Label 3300 4500 2    50   ~ 0
3.3V
Text Label 3300 4650 2    50   ~ 0
5V
Text Label 8800 4150 0    50   ~ 0
5V
Text Label 8800 4300 0    50   ~ 0
3.3V
Text Label 8700 3100 0    50   ~ 0
3.3V
Text Label 8700 2950 0    50   ~ 0
5V
Wire Wire Line
	7250 3950 6750 3950
Wire Wire Line
	5400 3650 5500 3650
Wire Wire Line
	5400 3800 5500 3800
Wire Wire Line
	6750 3600 6950 3600
Wire Wire Line
	6950 3600 6950 2900
Wire Wire Line
	6950 2900 7350 2900
Wire Wire Line
	7050 3700 7050 3050
Wire Wire Line
	7050 3050 7350 3050
Wire Wire Line
	6750 3700 7050 3700
Wire Wire Line
	8800 4150 8650 4150
Wire Wire Line
	8800 4300 8650 4300
Wire Wire Line
	8700 2950 8550 2950
Wire Wire Line
	8700 3100 8550 3100
Wire Wire Line
	4850 4600 5500 4600
Wire Wire Line
	4850 4450 5500 4450
Wire Wire Line
	4850 3650 4950 3650
Wire Wire Line
	4850 3800 4950 3800
Wire Wire Line
	3300 4500 3400 4500
Wire Wire Line
	3300 4650 3400 4650
Wire Wire Line
	6750 3800 7200 3800
Wire Wire Line
	7200 3800 7200 3200
Wire Wire Line
	7200 3200 7350 3200
Wire Wire Line
	5500 3950 5200 3950
Wire Wire Line
	5200 3950 5200 2750
Wire Wire Line
	5200 2750 7350 2750
$EndSCHEMATC