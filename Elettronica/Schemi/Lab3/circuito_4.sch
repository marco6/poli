EESchema Schematic File Version 2  date ven 08 nov 2013 11:27:47 CET
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
Connection ~ 6550 4350
Wire Wire Line
	6100 4350 7450 4350
Wire Wire Line
	6550 4350 6550 4100
Wire Wire Line
	5200 3900 5200 4050
Connection ~ 7000 4350
Wire Wire Line
	7450 4350 7450 4100
Wire Wire Line
	5650 3900 6350 3900
$Comp
L RESISTORE 33
U 1 1 527CB9E3
P 6100 4150
F 0 "33 Ohm" V 6000 4150 60  0000 C CNN
F 1 "Rs" V 6225 4150 60  0000 C CNN
F 2 "~" H 6100 4200 60  0000 C CNN
F 3 "~" H 6100 4200 60  0000 C CNN
	1    6100 4150
	1    0    0    -1  
$EndComp
Text Notes 6300 3850 0    60   ~ 0
VB
Text Notes 7600 3850 0    60   ~ 0
VC
$Comp
L TERRA GND?
U 1 1 527CB77E
P 7000 4450
F 0 "GND?" H 7300 4450 60  0001 C CNN
F 1 "TERRA" H 7000 4450 60  0001 C CNN
F 2 "~" H 7000 4450 60  0000 C CNN
F 3 "~" H 7000 4450 60  0000 C CNN
	1    7000 4450
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
P 6950 3900
F 0 "50 Ohm" H 6950 3900 60  0000 C CNN
F 1 "CAVO_COASSIALE_LUNGO" H 6950 3900 60  0001 C CNN
	1    6950 3900
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
