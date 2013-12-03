EESchema Schematic File Version 2  date gio 28 nov 2013 11:37:43 CET
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
Text Notes 6120 4180 0    60   ~ 0
ck
Text Notes 6040 4190 0    60   ~ 0
>\n
Wire Wire Line
	5850 4150 6050 4150
Wire Wire Line
	5550 3700 5500 3700
Wire Wire Line
	5500 3700 5500 4350
Connection ~ 5500 4150
Wire Wire Line
	6050 4000 6050 4300
$Comp
L GENERATORE_DI_TENSIONE 5
U 1 1 52971BD5
P 5700 3700
F 0 "5 V" V 5575 3700 60  0000 C CNN
F 1 "GENERATORE_DI_TENSIONE" H 5650 3700 60  0001 C CNN
F 2 "~" H 5650 3700 60  0000 C CNN
F 3 "~" H 5650 3700 60  0000 C CNN
	1    5700 3700
	0    1    1    0   
$EndComp
$Comp
L TERRA GND?
U 1 1 52971BBE
P 5500 4400
F 0 "GND?" H 5800 4400 60  0001 C CNN
F 1 "TERRA" H 5500 4400 60  0001 C CNN
F 2 "~" H 5500 4400 60  0000 C CNN
F 3 "~" H 5500 4400 60  0000 C CNN
	1    5500 4400
	1    0    0    -1  
$EndComp
$Comp
L RESISTORE 10
U 1 1 52971BB3
P 5850 3950
F 0 "10 KOhm" V 5750 3950 40  0000 C CNN
F 1 "RESISTORE" H 5850 4000 60  0001 C CNN
F 2 "~" H 5850 4000 60  0000 C CNN
F 3 "~" H 5850 4000 60  0000 C CNN
	1    5850 3950
	1    0    0    -1  
$EndComp
$Comp
L INTERRUTTORE U?
U 1 1 52971B8E
P 5650 4150
F 0 "U?" H 5600 4250 60  0001 C CNN
F 1 "INTERRUTTORE" H 5600 4250 60  0001 C CNN
	1    5650 4150
	-1   0    0    1   
$EndComp
$EndSCHEMATC
