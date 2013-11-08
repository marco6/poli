EESchema Schematic File Version 2  date ven 08 nov 2013 12:14:00 CET
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
LIBS:circuito_1-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "8 nov 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5050 3900 5200 3900
Wire Wire Line
	6750 4350 6750 4100
Connection ~ 6300 4350
Wire Wire Line
	6950 3900 7250 3900
Wire Wire Line
	5850 4100 5850 4350
Wire Wire Line
	5850 4350 7250 4350
Connection ~ 6750 4350
Text Notes 5600 3850 0    60   ~ 0
VB
Text Notes 6900 3850 0    60   ~ 0
VC
$Comp
L TERRA GND?
U 1 1 527CB77E
P 6300 4450
F 0 "GND?" H 6600 4450 60  0001 C CNN
F 1 "TERRA" H 6300 4450 60  0001 C CNN
F 2 "~" H 6300 4450 60  0000 C CNN
F 3 "~" H 6300 4450 60  0000 C CNN
	1    6300 4450
	1    0    0    -1  
$EndComp
$Comp
L RESISTORE R?
U 1 1 527CB772
P 5400 3900
F 0 "R?" H 5300 3900 60  0001 C CNN
F 1 "Ro" V 5300 3900 60  0000 C CNN
F 2 "~" H 5400 3950 60  0000 C CNN
F 3 "~" H 5400 3950 60  0000 C CNN
	1    5400 3900
	0    1    1    0   
$EndComp
$Comp
L RESISTORE 50~Ohm
U 1 1 527CB763
P 7250 4150
F 0 "50 Ohm" V 7125 4150 60  0000 C CNN
F 1 "Rt" V 7375 4150 60  0000 C CNN
F 2 "~" H 7250 4200 60  0000 C CNN
F 3 "~" H 7250 4200 60  0000 C CNN
	1    7250 4150
	-1   0    0    -1  
$EndComp
$Comp
L TERRA GND?
U 1 1 527CB749
P 5050 4400
F 0 "GND?" H 5350 4400 60  0001 C CNN
F 1 "TERRA" H 5050 4400 60  0001 C CNN
F 2 "~" H 5050 4400 60  0000 C CNN
F 3 "~" H 5050 4400 60  0000 C CNN
	1    5050 4400
	1    0    0    -1  
$EndComp
$Comp
L CAVO_COASSIALE_LUNGO 50~Ohm
U 1 1 527CB729
P 6250 3900
F 0 "50 Ohm" H 6250 3900 60  0000 C CNN
F 1 "CAVO_COASSIALE_LUNGO" H 6250 3900 60  0001 C CNN
	1    6250 3900
	1    0    0    -1  
$EndComp
$Comp
L GENERATORE_DI_ONDA_QUADRA 2~V
U 1 1 527CB719
P 5050 4100
F 0 "2 V" V 4900 4100 60  0000 C CNN
F 1 "GENERATORE_DI_ONDA_QUADRA" H 5050 4100 60  0001 C CNN
F 2 "~" H 5050 4100 60  0000 C CNN
F 3 "200 KHz" V 5230 4100 40  0000 C CNN
	1    5050 4100
	1    0    0    -1  
$EndComp
$EndSCHEMATC
