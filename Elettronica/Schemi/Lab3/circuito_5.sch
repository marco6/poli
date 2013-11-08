EESchema Schematic File Version 2  date ven 08 nov 2013 11:33:05 CET
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
Date "8 nov 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 6750 4350
Wire Wire Line
	7200 4350 7200 4300
Wire Wire Line
	7200 4350 5850 4350
Wire Wire Line
	6750 4350 6750 4100
Connection ~ 6300 4350
Wire Wire Line
	5200 3900 5200 4050
Wire Wire Line
	5850 4350 5850 4100
Wire Wire Line
	6950 3900 7200 3900
$Comp
L C C?
U 1 1 527CBD6B
P 7200 4100
F 0 "C?" H 7250 4200 50  0001 L CNN
F 1 "1 nF" H 7250 4000 50  0000 L CNN
	1    7200 4100
	1    0    0    -1  
$EndComp
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
L TERRA GND?
U 1 1 527CB749
P 5200 4550
F 0 "GND?" H 5500 4550 60  0001 C CNN
F 1 "TERRA" H 5200 4550 60  0001 C CNN
F 2 "~" H 5200 4550 60  0000 C CNN
F 3 "~" H 5200 4550 60  0000 C CNN
	1    5200 4550
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
P 5200 4250
F 0 "2 V" V 5050 4250 60  0000 C CNN
F 1 "GENERATORE_DI_ONDA_QUADRA" H 5200 4250 60  0001 C CNN
F 2 "~" H 5200 4250 60  0000 C CNN
F 3 "200 KHz" V 5380 4250 40  0000 C CNN
	1    5200 4250
	1    0    0    -1  
$EndComp
$EndSCHEMATC
