EESchema Schematic File Version 2  date gio 28 nov 2013 12:00:48 CET
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:poliStyle
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "28 nov 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	4100 3300 4100 4750
Wire Wire Line
	5300 3300 4100 3300
Wire Wire Line
	5300 3750 5300 3300
Wire Wire Line
	7950 3950 7950 3300
Connection ~ 6750 3550
Wire Wire Line
	7150 3300 6750 3300
Wire Wire Line
	7750 3850 7850 3850
Connection ~ 8100 3950
Connection ~ 7950 3950
Wire Wire Line
	8100 3950 7750 3950
Connection ~ 6750 3850
Wire Wire Line
	6750 3550 7150 3550
Wire Wire Line
	7050 4350 7050 4050
Wire Wire Line
	7050 3950 6850 3950
Wire Wire Line
	6850 3950 6850 4550
Wire Wire Line
	6350 4650 6350 4550
Wire Wire Line
	6150 4450 6600 4450
Wire Wire Line
	4750 4550 5500 4550
Wire Wire Line
	6600 4450 6600 3650
Wire Wire Line
	5700 4450 5600 4450
Wire Wire Line
	5600 4450 5600 4650
Wire Wire Line
	5400 3600 5500 3600
Wire Wire Line
	5150 3600 5200 3600
Wire Wire Line
	5800 4650 5700 4650
Wire Wire Line
	5700 4650 5700 4750
Wire Wire Line
	5050 3550 5050 3750
Wire Wire Line
	4400 4100 4400 4450
Wire Wire Line
	4400 4450 4450 4450
Wire Wire Line
	4550 4750 4550 3750
Wire Wire Line
	4850 3750 4850 3600
Wire Wire Line
	5450 3850 5450 3650
Wire Wire Line
	5450 3850 5700 3850
Connection ~ 4550 4750
Connection ~ 5300 3750
Connection ~ 4950 4450
Wire Wire Line
	5050 4450 4850 4450
Wire Wire Line
	5250 3750 5350 3750
Connection ~ 6150 4150
Wire Wire Line
	5700 4050 5700 4250
Wire Wire Line
	6150 4250 6150 4050
Connection ~ 5700 4150
Connection ~ 6600 3850
Wire Wire Line
	4750 4550 4750 4450
Wire Wire Line
	5050 3750 4950 3750
Wire Wire Line
	4550 3750 4650 3750
Wire Wire Line
	4750 3750 4750 3700
Wire Wire Line
	4750 3700 4400 3700
Wire Wire Line
	4400 3700 4400 3800
Wire Wire Line
	5150 3750 5150 3650
Wire Wire Line
	5500 3600 5500 3650
Wire Wire Line
	5500 3650 5700 3650
Wire Wire Line
	5150 3650 5200 3650
Wire Wire Line
	5450 3650 5400 3650
Wire Wire Line
	5500 4550 5500 4150
Wire Wire Line
	5500 4150 5700 4150
Connection ~ 6600 4150
Wire Wire Line
	4850 3600 4950 3600
Wire Wire Line
	5600 4650 5150 4650
Wire Wire Line
	5700 4750 4100 4750
Wire Wire Line
	6600 3650 6150 3650
Wire Wire Line
	6350 4550 6850 4550
Connection ~ 6350 4650
Wire Wire Line
	6150 4150 6750 4150
Wire Wire Line
	6750 3850 7050 3850
Wire Wire Line
	7600 4650 6100 4650
Wire Wire Line
	7950 3550 7600 3550
Wire Wire Line
	7850 4050 7850 4350
Wire Wire Line
	7850 4350 7350 4350
Wire Wire Line
	7950 3300 7600 3300
Connection ~ 7950 3550
Wire Wire Line
	6750 4150 6750 3300
$Comp
L RESISTORE 5,6~KOhm
U 1 1 529720BE
P 7350 3300
F 0 "5,6 KOhm" V 7250 3300 40  0000 C CNN
F 1 "RESISTORE" H 7350 3350 60  0001 C CNN
F 2 "~" H 7350 3350 60  0000 C CNN
F 3 "~" H 7350 3350 60  0000 C CNN
	1    7350 3300
	0    1    1    0   
$EndComp
Text Notes 8150 3950 0    60   ~ 0
Vu
$Comp
L SALTO U?
U 1 1 52971FDA
P 7850 3950
F 0 "U?" H 7900 4000 60  0001 C CNN
F 1 "SALTO" H 7850 3950 60  0001 C CNN
	1    7850 3950
	-1   0    0    1   
$EndComp
$Comp
L RESISTORE 5,6~KOhm
U 1 1 52971F80
P 7350 3550
F 0 "5,6 KOhm" V 7250 3550 40  0000 C CNN
F 1 "RESISTORE" H 7350 3600 60  0001 C CNN
F 2 "~" H 7350 3600 60  0000 C CNN
F 3 "~" H 7350 3600 60  0000 C CNN
	1    7350 3550
	0    1    1    0   
$EndComp
$Comp
L GENERATORE_DI_TENSIONE 10~V
U 1 1 52971F15
P 7350 4500
F 0 "10 V" V 7475 4500 40  0000 C CNN
F 1 "GENERATORE_DI_TENSIONE" H 7300 4500 60  0001 C CNN
F 2 "~" H 7300 4500 60  0000 C CNN
F 3 "~" H 7300 4500 60  0000 C CNN
	1    7350 4500
	1    0    0    -1  
$EndComp
$Comp
L GENERATORE_DI_TENSIONE 10~V
U 1 1 52971F11
P 7050 4500
F 0 "10 V" V 6925 4500 40  0000 C CNN
F 1 "GENERATORE_DI_TENSIONE" H 7000 4500 60  0001 C CNN
F 2 "~" H 7000 4500 60  0000 C CNN
F 3 "~" H 7000 4500 60  0000 C CNN
	1    7050 4500
	-1   0    0    1   
$EndComp
$Comp
L LM748 U?
U 1 1 52971DC2
P 7400 3900
F 0 "U?" H 7400 3650 60  0001 C CNN
F 1 "LM748" H 7400 3650 60  0000 C CNN
F 2 "~" H 7400 3650 60  0000 C CNN
F 3 "~" H 7400 3650 60  0000 C CNN
	1    7400 3900
	1    0    0    -1  
$EndComp
$Comp
L TERRA GND?
U 1 1 529369E5
P 7650 4650
F 0 "GND?" H 7950 4650 60  0001 C CNN
F 1 "TERRA" H 7650 4650 60  0001 C CNN
F 2 "~" H 7650 4650 60  0000 C CNN
F 3 "~" H 7650 4650 60  0000 C CNN
	1    7650 4650
	0    -1   -1   0   
$EndComp
$Comp
L GENERATORE_DI_TENSIONE 5~V
U 1 1 529369D6
P 5950 4650
F 0 "5 V" V 5825 4650 40  0000 C CNN
F 1 "GENERATORE_DI_TENSIONE" H 5900 4650 60  0001 C CNN
F 2 "~" H 5900 4650 60  0000 C CNN
F 3 "~" H 5900 4650 60  0000 C CNN
	1    5950 4650
	0    -1   -1   0   
$EndComp
$Comp
L TERRA GND?
U 1 1 529365CF
P 5050 3500
F 0 "GND?" H 5350 3500 60  0001 C CNN
F 1 "TERRA" H 5050 3500 60  0001 C CNN
F 2 "~" H 5050 3500 60  0000 C CNN
F 3 "~" H 5050 3500 60  0000 C CNN
	1    5050 3500
	-1   0    0    1   
$EndComp
$Comp
L TERRA GND?
U 1 1 52936597
P 5400 4450
F 0 "GND?" H 5700 4450 60  0001 C CNN
F 1 "TERRA" H 5400 4450 60  0001 C CNN
F 2 "~" H 5400 4450 60  0000 C CNN
F 3 "~" H 5400 4450 60  0000 C CNN
	1    5400 4450
	0    -1   -1   0   
$EndComp
$Comp
L SALTO U?
U 1 1 5293656E
P 4550 4450
F 0 "U?" H 4600 4500 60  0001 C CNN
F 1 "SALTO" H 4550 4450 60  0001 C CNN
	1    4550 4450
	0    -1   -1   0   
$EndComp
$Comp
L TERRA GND?
U 1 1 52936550
P 4350 4450
F 0 "GND?" H 4650 4450 60  0001 C CNN
F 1 "TERRA" H 4350 4450 60  0001 C CNN
F 2 "~" H 4350 4450 60  0000 C CNN
F 3 "~" H 4350 4450 60  0000 C CNN
	1    4350 4450
	0    1    1    0   
$EndComp
$Comp
L GENERATORE_DI_ONDA_QUADRA 0~-~4,5~V
U 1 1 52936356
P 4400 3950
F 0 "0 - 4,5 V" V 4275 3950 40  0000 C CNN
F 1 "GENERATORE_DI_ONDA_QUADRA" H 4350 3950 60  0001 C CNN
F 2 "~" H 4350 3950 60  0000 C CNN
F 3 "~" H 4350 3950 60  0000 C CNN
	1    4400 3950
	1    0    0    -1  
$EndComp
$Comp
L SALTO U?
U 1 1 52936520
P 5150 4550
F 0 "U?" H 5200 4600 60  0001 C CNN
F 1 "SALTO" H 5150 4550 60  0001 C CNN
	1    5150 4550
	1    0    0    -1  
$EndComp
$Comp
L SALTO U?
U 1 1 52935FAC
P 5050 3600
F 0 "U?" H 5100 3650 60  0001 C CNN
F 1 "SALTO" H 5050 3600 60  0001 C CNN
	1    5050 3600
	0    1    1    0   
$EndComp
$Comp
L SALTO U?
U 1 1 52935BB0
P 5300 3600
F 0 "U?" H 5350 3650 60  0001 C CNN
F 1 "SALTO" H 5300 3600 60  0001 C CNN
	1    5300 3600
	0    1    1    0   
$EndComp
$Comp
L SALTO U?
U 1 1 52935BAA
P 5300 3650
F 0 "U?" H 5350 3700 60  0001 C CNN
F 1 "SALTO" H 5300 3650 60  0001 C CNN
	1    5300 3650
	0    1    1    0   
$EndComp
$Comp
L SALTO U?
U 1 1 52935B69
P 4750 4450
F 0 "U?" H 4800 4500 60  0001 C CNN
F 1 "SALTO" H 4750 4450 60  0001 C CNN
	1    4750 4450
	0    -1   -1   0   
$EndComp
$Comp
L RESISTORE 10~KOhm
U 1 1 528F4901
P 5900 3650
F 0 "10 KOhm" V 5800 3650 40  0000 C CNN
F 1 "RESISTORE" H 5900 3700 60  0001 C CNN
F 2 "~" H 5900 3700 60  0000 C CNN
F 3 "~" H 5900 3700 60  0000 C CNN
	1    5900 3650
	0    1    1    0   
$EndComp
$Comp
L RESISTORE 10~KOhm
U 1 1 528F48C0
P 5900 4250
F 0 "10 KOhm" V 5800 4250 40  0000 C CNN
F 1 "RESISTORE" H 5900 4300 60  0001 C CNN
F 2 "~" H 5900 4300 60  0000 C CNN
F 3 "~" H 5900 4300 60  0000 C CNN
	1    5900 4250
	0    1    1    0   
$EndComp
$Comp
L RESISTORE 10~KOhm
U 1 1 528F48A3
P 5900 4050
F 0 "10 KOhm" V 5800 4050 40  0000 C CNN
F 1 "RESISTORE" H 5900 4100 60  0001 C CNN
F 2 "~" H 5900 4100 60  0000 C CNN
F 3 "~" H 5900 4100 60  0000 C CNN
	1    5900 4050
	0    1    1    0   
$EndComp
$Comp
L RESISTORE 10~KOhm
U 1 1 528F44E5
P 6350 3850
F 0 "10 KOhm" V 6250 3850 40  0000 C CNN
F 1 "RESISTORE" H 6350 3900 60  0001 C CNN
F 2 "~" H 6350 3900 60  0000 C CNN
F 3 "~" H 6350 3900 60  0000 C CNN
	1    6350 3850
	0    1    1    0   
$EndComp
$Comp
L RESISTORE 10~KOhm
U 1 1 528F44DC
P 5900 3850
F 0 "10 KOhm" V 5800 3850 40  0000 C CNN
F 1 "RESISTORE" H 5900 3900 60  0001 C CNN
F 2 "~" H 5900 3900 60  0000 C CNN
F 3 "~" H 5900 3900 60  0000 C CNN
	1    5900 3850
	0    1    1    0   
$EndComp
$Comp
L RESISTORE 39~KOhm
U 1 1 528F44C7
P 5900 4450
F 0 "39 KOhm" V 5800 4450 40  0000 C CNN
F 1 "RESISTORE" H 5900 4500 60  0001 C CNN
F 2 "~" H 5900 4500 60  0000 C CNN
F 3 "~" H 5900 4500 60  0000 C CNN
	1    5900 4450
	0    1    1    0   
$EndComp
$Comp
L CD4029 U?
U 1 1 528F4149
P 5000 4100
F 0 "U?" H 5000 4150 60  0001 C CNN
F 1 "CD4029" V 5000 4150 60  0000 C CNN
F 2 "~" H 5000 4150 60  0000 C CNN
F 3 "~" H 5000 4150 60  0000 C CNN
	1    5000 4100
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
