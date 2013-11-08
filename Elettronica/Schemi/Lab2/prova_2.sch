EESchema Schematic File Version 2  date gio 07 nov 2013 10:50:30 CET
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
LIBS:prova_2-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "7 nov 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5750 3350 5750 3650
Wire Wire Line
	5750 3350 6000 3350
Wire Wire Line
	4950 3850 4650 3850
Wire Wire Line
	4950 3650 4850 3650
Wire Wire Line
	5650 3950 6000 3950
Wire Wire Line
	5750 3650 5650 3650
Wire Wire Line
	3900 4600 6000 4600
Wire Wire Line
	4850 3700 4850 3750
Wire Wire Line
	4850 3700 4650 3700
Wire Wire Line
	3900 4200 4300 4200
Connection ~ 6000 4150
Connection ~ 4800 4600
Wire Wire Line
	4800 4600 4800 4050
Connection ~ 4300 4600
Wire Wire Line
	4950 4600 4950 4250
Connection ~ 4300 4200
Wire Wire Line
	4650 3850 4650 4600
Connection ~ 4650 4600
Connection ~ 4950 4600
Wire Wire Line
	6000 4600 6000 3750
Connection ~ 6000 3950
Connection ~ 4100 4200
Wire Wire Line
	4100 4200 4100 3450
Wire Wire Line
	4100 3450 4850 3450
Wire Wire Line
	4850 3450 4850 3650
Wire Wire Line
	4200 3700 4100 3700
Connection ~ 4100 3700
Wire Wire Line
	6000 3750 5650 3750
Wire Wire Line
	5650 4150 6000 4150
Wire Wire Line
	4850 3750 4950 3750
Wire Wire Line
	4800 4050 4950 4050
$Comp
L TERRA GND?
U 1 1 527A7C7D
P 4100 4700
F 0 "GND?" H 4400 4700 60  0001 C CNN
F 1 "TERRA" H 4100 4700 60  0001 C CNN
F 2 "~" H 4100 4700 60  0000 C CNN
F 3 "~" H 4100 4700 60  0000 C CNN
	1    4100 4700
	1    0    0    -1  
$EndComp
$Comp
L RESISTORE 100~K~Ohm
U 1 1 527A7C6B
P 4450 3700
F 0 "100 K Ohm" V 4550 3700 60  0000 C CNN
F 1 "RESISTORE" H 4450 3750 60  0001 C CNN
F 2 "~" H 4450 3750 60  0000 C CNN
F 3 "~" H 4450 3750 60  0000 C CNN
	1    4450 3700
	0    -1   -1   0   
$EndComp
$Comp
L 74HC14P U?
U 1 1 527A7C5F
P 5300 4000
F 0 "U?" H 5300 4050 60  0001 C CNN
F 1 "74HC14" V 5300 4050 60  0000 C CNN
F 2 "~" H 5300 4050 60  0000 C CNN
F 3 "~" H 5300 4050 60  0000 C CNN
	1    5300 4000
	1    0    0    -1  
$EndComp
$Comp
L GENERATORE_DI_VOLTAGGIO 5~V
U 1 1 527A7C53
P 6000 3550
F 0 "5 V" V 5800 3550 60  0000 C CNN
F 1 "GENERATORE_DI_VOLTAGGIO" H 6000 3550 60  0001 C CNN
F 2 "~" H 6000 3550 60  0000 C CNN
F 3 "~" H 6000 3550 60  0000 C CNN
	1    6000 3550
	-1   0    0    -1  
$EndComp
$Comp
L C 0.2~nF
U 1 1 527A1EDF
P 3900 4400
F 0 "0.2 nF" H 3950 4500 50  0000 L CNN
F 1 "0.2 nF" H 3950 4300 50  0001 L CNN
	1    3900 4400
	1    0    0    -1  
$EndComp
$Comp
L C 1~nF
U 1 1 527A1ED1
P 4300 4400
F 0 "1 nF" H 4350 4500 50  0000 L CNN
F 1 "C" H 4350 4300 50  0001 L CNN
	1    4300 4400
	1    0    0    -1  
$EndComp
$EndSCHEMATC
