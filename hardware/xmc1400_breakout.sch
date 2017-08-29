EESchema Schematic File Version 2
LIBS:tinkerforge
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
LIBS:xmc1400_breakout-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "XMC1400 Breakout Board"
Date "2017-02-07"
Rev "1.0"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2017, B.Nordmeyer <bastian@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 550  7700 0    40   ~ 0
Copyright Tinkerforge GmbH 2017.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
$Comp
L DRILL U2
U 1 1 4C6050A5
P 10650 6150
F 0 "U2" H 10700 6200 60  0001 C CNN
F 1 "DRILL" H 10650 6150 60  0000 C CNN
F 2 "DRILL_NP" H 10650 6150 60  0001 C CNN
F 3 "" H 10650 6150 60  0001 C CNN
	1    10650 6150
	1    0    0    -1  
$EndComp
$Comp
L DRILL U3
U 1 1 4C6050A2
P 10650 6350
F 0 "U3" H 10700 6400 60  0001 C CNN
F 1 "DRILL" H 10650 6350 60  0000 C CNN
F 2 "DRILL_NP" H 10650 6350 60  0001 C CNN
F 3 "" H 10650 6350 60  0001 C CNN
	1    10650 6350
	1    0    0    -1  
$EndComp
$Comp
L DRILL U5
U 1 1 4C60509F
P 11000 6350
F 0 "U5" H 11050 6400 60  0001 C CNN
F 1 "DRILL" H 11000 6350 60  0000 C CNN
F 2 "DRILL_NP" H 11000 6350 60  0001 C CNN
F 3 "" H 11000 6350 60  0001 C CNN
	1    11000 6350
	1    0    0    -1  
$EndComp
$Comp
L DRILL U4
U 1 1 4C605099
P 11000 6150
F 0 "U4" H 11050 6200 60  0001 C CNN
F 1 "DRILL" H 11000 6150 60  0000 C CNN
F 2 "DRILL_NP" H 11000 6150 60  0001 C CNN
F 3 "" H 11000 6150 60  0001 C CNN
	1    11000 6150
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR01
U 1 1 4C5FCFB4
P 9650 1450
F 0 "#PWR01" H 9650 1550 30  0001 C CNN
F 1 "VCC" H 9650 1550 30  0000 C CNN
F 2 "" H 9650 1450 60  0001 C CNN
F 3 "" H 9650 1450 60  0001 C CNN
	1    9650 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 4C5FCF4F
P 8100 2850
F 0 "#PWR02" H 8100 2850 30  0001 C CNN
F 1 "GND" H 8100 2780 30  0001 C CNN
F 2 "" H 8100 2850 60  0001 C CNN
F 3 "" H 8100 2850 60  0001 C CNN
	1    8100 2850
	1    0    0    -1  
$EndComp
$Comp
L CON-SENSOR2 P1
U 1 1 4C5FCF27
P 8100 2300
F 0 "P1" H 8250 2700 60  0000 C CNN
F 1 "CON-SENSOR2" V 8250 2300 60  0000 C CNN
F 2 "CON-SENSOR2" H 8100 2300 60  0001 C CNN
F 3 "" H 8100 2300 60  0001 C CNN
	1    8100 2300
	-1   0    0    -1  
$EndComp
$Comp
L FILTER FB1
U 1 1 54F7633D
P 9050 1450
F 0 "FB1" H 9050 1600 60  0000 C CNN
F 1 "FILTER" H 9050 1350 60  0000 C CNN
F 2 "C0603F" H 9050 1450 60  0001 C CNN
F 3 "" H 9050 1450 60  0000 C CNN
	1    9050 1450
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 54F76B96
P 8700 1700
F 0 "C1" V 8800 1850 50  0000 L CNN
F 1 "1uF" V 8550 1700 50  0000 L CNN
F 2 "C0603F" H 8700 1700 60  0001 C CNN
F 3 "" H 8700 1700 60  0001 C CNN
	1    8700 1700
	-1   0    0    1   
$EndComp
$Comp
L C C2
U 1 1 54F77AA5
P 9450 1700
F 0 "C2" V 9550 1850 50  0000 L CNN
F 1 "1uF" V 9300 1700 50  0000 L CNN
F 2 "C0603F" H 9450 1700 60  0001 C CNN
F 3 "" H 9450 1700 60  0001 C CNN
	1    9450 1700
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR03
U 1 1 54F77AEA
P 9450 2150
F 0 "#PWR03" H 9450 2150 30  0001 C CNN
F 1 "GND" H 9450 2080 30  0001 C CNN
F 2 "" H 9450 2150 60  0001 C CNN
F 3 "" H 9450 2150 60  0001 C CNN
	1    9450 2150
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX48 U1
U 2 1 5820E01A
P 5350 1750
F 0 "U1" H 5200 2700 60  0000 C CNN
F 1 "XMC1XXX48" H 5350 750 60  0000 C CNN
F 2 "kicad-libraries:QFN48-EP2" H 5500 2500 60  0001 C CNN
F 3 "" H 5500 2500 60  0000 C CNN
	2    5350 1750
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX48 U1
U 1 1 5820E0F1
P 9250 4300
F 0 "U1" H 9100 5250 60  0000 C CNN
F 1 "XMC1XXX48" H 9250 3300 60  0000 C CNN
F 2 "kicad-libraries:QFN48-EP2" H 9400 5050 60  0001 C CNN
F 3 "" H 9400 5050 60  0000 C CNN
	1    9250 4300
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX48 U1
U 4 1 5820E19E
P 5400 6200
F 0 "U1" H 5250 6850 60  0000 C CNN
F 1 "XMC1XXX48" H 5400 5200 60  0000 C CNN
F 2 "kicad-libraries:QFN48-EP2" H 5550 6950 60  0001 C CNN
F 3 "" H 5550 6950 60  0000 C CNN
	4    5400 6200
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX48 U1
U 3 1 5820E1ED
P 5400 4900
F 0 "U1" H 5300 5400 60  0000 C CNN
F 1 "XMC1XXX48" H 5400 4400 60  0000 C CNN
F 2 "kicad-libraries:QFN48-EP2" H 5550 5650 60  0001 C CNN
F 3 "" H 5550 5650 60  0000 C CNN
	3    5400 4900
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX48 U1
U 5 1 5820E256
P 5400 3450
F 0 "U1" H 5250 3900 60  0000 C CNN
F 1 "XMC1XXX48" H 5400 2850 60  0000 C CNN
F 2 "kicad-libraries:QFN48-EP2" H 5550 4200 60  0001 C CNN
F 3 "" H 5550 4200 60  0000 C CNN
	5    5400 3450
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5820F9DC
P 8450 3900
F 0 "C3" V 8500 3650 50  0000 L CNN
F 1 "100nF" V 8300 3800 50  0000 L CNN
F 2 "C0603F" H 8450 3900 60  0001 C CNN
F 3 "" H 8450 3900 60  0001 C CNN
	1    8450 3900
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 5820FDE6
P 8800 3900
F 0 "C5" V 8850 3650 50  0000 L CNN
F 1 "100nF" V 8650 3800 50  0000 L CNN
F 2 "C0603F" H 8800 3900 60  0001 C CNN
F 3 "" H 8800 3900 60  0001 C CNN
	1    8800 3900
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5821039E
P 8800 4850
F 0 "C6" V 8850 4600 50  0000 L CNN
F 1 "220nF" V 8650 4750 50  0000 L CNN
F 2 "C0603F" H 8800 4850 60  0001 C CNN
F 3 "" H 8800 4850 60  0001 C CNN
	1    8800 4850
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 582104B4
P 8450 4850
F 0 "C4" V 8500 4600 50  0000 L CNN
F 1 "100nF" V 8300 4750 50  0000 L CNN
F 2 "C0603F" H 8450 4850 60  0001 C CNN
F 3 "" H 8450 4850 60  0001 C CNN
	1    8450 4850
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR04
U 1 1 5821096B
P 8450 3500
F 0 "#PWR04" H 8450 3600 30  0001 C CNN
F 1 "VCC" H 8450 3600 30  0000 C CNN
F 2 "" H 8450 3500 60  0001 C CNN
F 3 "" H 8450 3500 60  0001 C CNN
	1    8450 3500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 58210A4E
P 8450 4450
F 0 "#PWR05" H 8450 4550 30  0001 C CNN
F 1 "VCC" H 8450 4550 30  0000 C CNN
F 2 "" H 8450 4450 60  0001 C CNN
F 3 "" H 8450 4450 60  0001 C CNN
	1    8450 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 58210B67
P 8450 4200
F 0 "#PWR06" H 8450 4200 30  0001 C CNN
F 1 "GND" H 8450 4130 30  0001 C CNN
F 2 "" H 8450 4200 60  0001 C CNN
F 3 "" H 8450 4200 60  0001 C CNN
	1    8450 4200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 58210C80
P 8450 5150
F 0 "#PWR07" H 8450 5150 30  0001 C CNN
F 1 "GND" H 8450 5080 30  0001 C CNN
F 2 "" H 8450 5150 60  0001 C CNN
F 3 "" H 8450 5150 60  0001 C CNN
	1    8450 5150
	1    0    0    -1  
$EndComp
Text GLabel 8750 2300 2    60   Output ~ 0
S-CS
Text GLabel 8750 2400 2    60   Output ~ 0
S-CLK
Text GLabel 8750 2500 2    60   Output ~ 0
S-MOSI
Text GLabel 8750 2600 2    60   Input ~ 0
S-MISO
Text GLabel 4700 4700 0    60   Input ~ 0
S-CS
Text GLabel 4700 4900 0    60   Input ~ 0
S-CLK
Text GLabel 4700 4800 0    60   Input ~ 0
S-MOSI
Text GLabel 4700 5200 0    60   Output ~ 0
S-MISO
$Comp
L LED D3
U 1 1 5823347E
P 3850 3450
F 0 "D3" H 3850 3550 50  0000 C CNN
F 1 "blue" H 3850 3350 50  0000 C CNN
F 2 "D0603E" H 3850 3450 50  0001 C CNN
F 3 "" H 3850 3450 50  0000 C CNN
	1    3850 3450
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P2
U 1 1 58233528
P 4550 3800
F 0 "P2" H 4550 3950 50  0000 C CNN
F 1 "BOOT" V 4650 3800 50  0000 C CNN
F 2 "kicad-libraries:SolderJumper" H 4550 3700 50  0001 C CNN
F 3 "" H 4550 3700 50  0000 C CNN
	1    4550 3800
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR08
U 1 1 5824794E
P 3600 3400
F 0 "#PWR08" H 3600 3500 30  0001 C CNN
F 1 "VCC" H 3600 3500 30  0000 C CNN
F 2 "" H 3600 3400 60  0001 C CNN
F 3 "" H 3600 3400 60  0001 C CNN
	1    3600 3400
	1    0    0    -1  
$EndComp
Text Notes 5800 5050 0    39   ~ 0
SPI Slave\nP1.1 : USIC0_CH1-DX2E : SEL\nP1.2 : USIC0_CH1-DX0B : MOSI\nP1.3 : USIC0_CH1-DX1A : CLK\nP1.6 : USIC0_CH1-DOUT0 : MISO
Text Notes 5700 7000 0    39   ~ 0
ASC\nP2.12 : USIC1_CH1.DOUT0\nP2.13 : USIC1_CH1.DX0D
$Comp
L C C8
U 1 1 58274693
P 3550 1750
F 0 "C8" V 3400 1700 50  0000 L CNN
F 1 "10pF" V 3700 1700 50  0000 L CNN
F 2 "C0603F" H 3550 1750 60  0001 C CNN
F 3 "" H 3550 1750 60  0001 C CNN
	1    3550 1750
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 582748D4
P 3550 2350
F 0 "C9" V 3400 2300 50  0000 L CNN
F 1 "10pF" V 3700 2300 50  0000 L CNN
F 2 "C0603F" H 3550 2350 60  0001 C CNN
F 3 "" H 3550 2350 60  0001 C CNN
	1    3550 2350
	0    1    1    0   
$EndComp
$Comp
L GND #PWR09
U 1 1 58275257
P 3350 2500
F 0 "#PWR09" H 3350 2500 30  0001 C CNN
F 1 "GND" H 3350 2430 30  0001 C CNN
F 2 "" H 3350 2500 60  0001 C CNN
F 3 "" H 3350 2500 60  0001 C CNN
	1    3350 2500
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 58275F18
P 4550 2100
F 0 "R9" V 4630 2100 50  0000 C CNN
F 1 "TBD" V 4550 2100 50  0000 C CNN
F 2 "R0402E" H 4550 2100 60  0001 C CNN
F 3 "" H 4550 2100 60  0000 C CNN
	1    4550 2100
	0    1    1    0   
$EndComp
$Comp
L CRYSTAL_3225 X1
U 1 1 58276FBA
P 4100 2050
F 0 "X1" V 3850 1850 60  0000 C CNN
F 1 "16MHz" V 4550 2050 60  0000 C CNN
F 2 "kicad-libraries:CRYSTAL_3225" H 4100 2050 60  0001 C CNN
F 3 "" H 4100 2050 60  0000 C CNN
	1    4100 2050
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR010
U 1 1 5827815F
P 3350 1900
F 0 "#PWR010" H 3350 1900 30  0001 C CNN
F 1 "GND" H 3350 1830 30  0001 C CNN
F 2 "" H 3350 1900 60  0001 C CNN
F 3 "" H 3350 1900 60  0001 C CNN
	1    3350 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 58278535
P 4400 2300
F 0 "#PWR011" H 4400 2300 30  0001 C CNN
F 1 "GND" H 4400 2230 30  0001 C CNN
F 2 "" H 4400 2300 60  0001 C CNN
F 3 "" H 4400 2300 60  0001 C CNN
	1    4400 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 5828358D
P 4850 3850
F 0 "#PWR012" H 4850 3850 30  0001 C CNN
F 1 "GND" H 4850 3780 30  0001 C CNN
F 2 "" H 4850 3850 60  0001 C CNN
F 3 "" H 4850 3850 60  0001 C CNN
	1    4850 3850
	0    -1   -1   0   
$EndComp
Text Notes 3750 2800 0    39   ~ 0
TSX-3225 16.0000MF18X-AC0\nno C - 1,00017\n3pF - 1,00008\n4.7pF - 1,00005\n9pF - 1,00001\n10pF - 1,00000MHz
NoConn ~ 8450 2000
$Comp
L CONN_01X12 P5
U 1 1 58986EB4
P 1600 4600
F 0 "P5" H 1600 5250 50  0000 C CNN
F 1 "CONN_01X12" V 1700 4600 50  0000 C CNN
F 2 "kicad-libraries:pin_array_12" H 1600 4600 50  0001 C CNN
F 3 "" H 1600 4600 50  0000 C CNN
	1    1600 4600
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X12 P6
U 1 1 5898A34A
P 1600 6200
F 0 "P6" H 1600 6850 50  0000 C CNN
F 1 "CONN_01X12" V 1700 6200 50  0000 C CNN
F 2 "kicad-libraries:pin_array_12" H 1600 6200 50  0001 C CNN
F 3 "" H 1600 6200 50  0000 C CNN
	1    1600 6200
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X12 P3
U 1 1 5898A46E
P 1600 1400
F 0 "P3" H 1600 2050 50  0000 C CNN
F 1 "CONN_01X12" V 1700 1400 50  0000 C CNN
F 2 "kicad-libraries:pin_array_12" H 1600 1400 50  0001 C CNN
F 3 "" H 1600 1400 50  0000 C CNN
	1    1600 1400
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X12 P4
U 1 1 5898A50F
P 1600 3000
F 0 "P4" H 1600 3650 50  0000 C CNN
F 1 "CONN_01X12" V 1700 3000 50  0000 C CNN
F 2 "kicad-libraries:pin_array_12" H 1600 3000 50  0001 C CNN
F 3 "" H 1600 3000 50  0000 C CNN
	1    1600 3000
	-1   0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5898C45C
P 4400 3450
F 0 "R1" V 4480 3450 50  0000 C CNN
F 1 "1k" V 4400 3450 50  0000 C CNN
F 2 "R0603F" H 4400 3450 60  0001 C CNN
F 3 "" H 4400 3450 60  0000 C CNN
	1    4400 3450
	0    1    1    0   
$EndComp
Text GLabel 5050 6700 0    39   Input ~ 0
Pin13
Text GLabel 1800 4050 2    39   Input ~ 0
Pin13
Text GLabel 5050 6800 0    39   Input ~ 0
Pin14
Text GLabel 1800 4150 2    39   Input ~ 0
Pin14
Text GLabel 5050 6900 0    39   Input ~ 0
Pin15
Text GLabel 1800 4250 2    39   Input ~ 0
Pin15
Text GLabel 5050 7000 0    39   Input ~ 0
Pin16
Text GLabel 1800 4350 2    39   Input ~ 0
Pin16
$Comp
L GND #PWR013
U 1 1 5898E65D
P 2250 4500
F 0 "#PWR013" H 2250 4500 30  0001 C CNN
F 1 "GND" H 2250 4430 30  0001 C CNN
F 2 "" H 2250 4500 60  0001 C CNN
F 3 "" H 2250 4500 60  0001 C CNN
	1    2250 4500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR014
U 1 1 5898E867
P 2100 4400
F 0 "#PWR014" H 2100 4500 30  0001 C CNN
F 1 "VCC" H 2100 4500 30  0000 C CNN
F 2 "" H 2100 4400 60  0001 C CNN
F 3 "" H 2100 4400 60  0001 C CNN
	1    2100 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2850 8100 2750
Wire Wire Line
	9450 2100 8450 2100
Wire Wire Line
	8550 1450 8700 1450
Wire Wire Line
	9400 1450 9650 1450
Wire Wire Line
	8550 2200 8550 1450
Wire Wire Line
	9450 1900 9450 2150
Wire Wire Line
	8700 1450 8700 1500
Wire Wire Line
	9450 1500 9450 1450
Connection ~ 9450 1450
Connection ~ 8700 1450
Wire Wire Line
	8700 2100 8700 1900
Connection ~ 8700 2100
Wire Wire Line
	8900 4150 8450 4150
Wire Wire Line
	8450 4100 8450 4200
Wire Wire Line
	8900 3550 8450 3550
Wire Wire Line
	8450 3500 8450 3700
Wire Wire Line
	8800 4100 8800 4250
Connection ~ 8800 4150
Wire Wire Line
	8450 3650 8900 3650
Wire Wire Line
	8800 3650 8800 3700
Connection ~ 8450 3650
Connection ~ 8800 3650
Wire Wire Line
	8800 4250 8900 4250
Wire Wire Line
	8450 5100 8900 5100
Wire Wire Line
	8800 5100 8800 5050
Wire Wire Line
	8450 4600 8900 4600
Wire Wire Line
	8800 4600 8800 4650
Wire Wire Line
	8450 5050 8450 5150
Connection ~ 8800 5100
Wire Wire Line
	8900 4500 8450 4500
Wire Wire Line
	8450 4450 8450 4650
Connection ~ 8450 4600
Connection ~ 8800 4600
Connection ~ 8450 5100
Connection ~ 8450 4150
Connection ~ 8450 4500
Connection ~ 8450 3550
Connection ~ 9450 2100
Wire Wire Line
	8450 2300 8750 2300
Wire Wire Line
	8450 2400 8750 2400
Wire Wire Line
	8450 2500 8750 2500
Wire Wire Line
	8450 2600 8750 2600
Wire Wire Line
	4300 2350 4300 2100
Wire Wire Line
	4300 2000 5000 2000
Wire Wire Line
	4300 1750 4300 2000
Wire Wire Line
	5000 2100 4800 2100
Wire Wire Line
	3750 1750 4300 1750
Wire Wire Line
	3750 2350 4300 2350
Connection ~ 4100 2350
Connection ~ 4100 1750
Wire Wire Line
	3350 2500 3350 2350
Wire Wire Line
	3350 1900 3350 1750
Wire Wire Line
	4400 2300 4400 2200
Wire Wire Line
	4700 4700 5050 4700
Wire Wire Line
	4700 4800 5050 4800
Wire Wire Line
	4700 4900 5050 4900
Wire Wire Line
	4700 5200 5050 5200
Wire Wire Line
	4800 3450 4800 3650
Wire Wire Line
	4300 3650 5050 3650
Wire Wire Line
	4750 3850 4850 3850
Wire Wire Line
	5050 3750 4750 3750
Wire Wire Line
	8450 2200 8550 2200
Wire Wire Line
	4800 3450 4650 3450
Wire Wire Line
	4150 3450 4050 3450
Wire Wire Line
	3650 3450 3600 3450
Wire Wire Line
	3600 3450 3600 3400
Wire Wire Line
	1800 4450 2250 4450
Wire Wire Line
	2250 4450 2250 4500
Wire Wire Line
	1800 4550 2100 4550
Wire Wire Line
	2100 4400 2100 4650
Wire Wire Line
	2100 4650 1800 4650
Connection ~ 2100 4550
Text GLabel 1800 5050 2    60   Output ~ 0
S-MISO
Text GLabel 1800 4750 2    60   Input ~ 0
S-CS
Text GLabel 1800 4850 2    60   Input ~ 0
S-CLK
Text GLabel 1800 4950 2    60   Input ~ 0
S-MOSI
Text GLabel 5050 5100 0    39   Input ~ 0
Pin21
Text GLabel 1800 5150 2    39   Input ~ 0
Pin21
Text GLabel 5050 5000 0    39   Input ~ 0
Pin22
Text GLabel 1800 5650 2    39   Input ~ 0
Pin22
Text GLabel 4950 4000 3    39   Input ~ 0
Pin1
Text GLabel 5050 4000 3    39   Input ~ 0
Pin2
Wire Wire Line
	5050 4000 5050 3850
Wire Wire Line
	4950 4000 4950 3750
Connection ~ 4950 3750
Text GLabel 1800 3550 2    39   Input ~ 0
Pin1
Text GLabel 1800 3450 2    39   Input ~ 0
Pin2
Text GLabel 1800 3350 2    39   Input ~ 0
Pin3
Text GLabel 1800 3250 2    39   Input ~ 0
Pin4
Text GLabel 1800 3150 2    39   Input ~ 0
Pin5
Text GLabel 1800 3050 2    39   Input ~ 0
Pin6
Text GLabel 1800 2950 2    39   Input ~ 0
Pin7
Text GLabel 1800 2850 2    39   Input ~ 0
Pin8
Text GLabel 1800 2750 2    39   Input ~ 0
Pin9
Text GLabel 1800 2650 2    39   Input ~ 0
Pin10
Text GLabel 1800 2550 2    39   Input ~ 0
Pin11
Text GLabel 1800 2450 2    39   Input ~ 0
Pin12
Text GLabel 5050 6600 0    39   Input ~ 0
Pin12
Text GLabel 5050 6500 0    39   Input ~ 0
Pin11
Text GLabel 5050 6400 0    39   Input ~ 0
Pin10
Text GLabel 5050 6300 0    39   Input ~ 0
Pin9
Text GLabel 5050 6200 0    39   Input ~ 0
Pin8
Text GLabel 5050 6100 0    39   Input ~ 0
Pin7
Text GLabel 5050 6000 0    39   Input ~ 0
Pin6
Text GLabel 5050 5900 0    39   Input ~ 0
Pin5
Text GLabel 5050 5800 0    39   Input ~ 0
Pin4
Text GLabel 5050 5700 0    39   Input ~ 0
Pin3
Text GLabel 4300 3650 0    39   Input ~ 0
Pin48
Connection ~ 4800 3650
Text GLabel 5050 3550 0    39   Input ~ 0
Pin47
Text GLabel 5000 2500 0    39   Input ~ 0
Pin46
Text GLabel 5000 2400 0    39   Input ~ 0
Pin45
Text GLabel 5000 2300 0    39   Input ~ 0
Pin44
Text GLabel 5000 2200 0    39   Input ~ 0
Pin43
Text GLabel 5000 1900 0    39   Input ~ 0
Pin40
Text GLabel 5000 1800 0    39   Input ~ 0
Pin39
Text GLabel 1800 850  2    39   Input ~ 0
Pin48
Text GLabel 1800 950  2    39   Input ~ 0
Pin47
Text GLabel 1800 1050 2    39   Input ~ 0
Pin46
Text GLabel 1800 1150 2    39   Input ~ 0
Pin45
Text GLabel 1800 1250 2    39   Input ~ 0
Pin44
Text GLabel 1800 1350 2    39   Input ~ 0
Pin43
Text GLabel 1800 1450 2    39   Input ~ 0
Pin42
Text GLabel 1800 1550 2    39   Input ~ 0
Pin41
Text GLabel 1800 1650 2    39   Input ~ 0
Pin40
Text GLabel 1800 1750 2    39   Input ~ 0
Pin39
Text GLabel 1800 6750 2    39   Input ~ 0
Pin36
Text GLabel 5000 1700 0    39   Input ~ 0
Pin36
Text GLabel 5000 1600 0    39   Input ~ 0
Pin35
Text GLabel 5000 1500 0    39   Input ~ 0
Pin34
Text GLabel 5000 1400 0    39   Input ~ 0
Pin33
Text GLabel 5000 1300 0    39   Input ~ 0
Pin32
Text GLabel 5000 1200 0    39   Input ~ 0
Pin31
Text GLabel 5000 1100 0    39   Input ~ 0
Pin30
Text GLabel 5000 1000 0    39   Input ~ 0
Pin29
Text GLabel 1800 6650 2    39   Input ~ 0
Pin35
Text GLabel 1800 6550 2    39   Input ~ 0
Pin34
Text GLabel 1800 6450 2    39   Input ~ 0
Pin33
Text GLabel 1800 6350 2    39   Input ~ 0
Pin32
Text GLabel 1800 6250 2    39   Input ~ 0
Pin31
Text GLabel 1800 6150 2    39   Input ~ 0
Pin30
Text GLabel 1800 6050 2    39   Input ~ 0
Pin29
Text GLabel 5050 3150 0    39   Input ~ 0
Pin28
Text GLabel 5050 4600 0    39   Input ~ 0
Pin26
Text GLabel 1800 5950 2    39   Input ~ 0
Pin28
Text GLabel 1800 5750 2    39   Input ~ 0
Pin26
Wire Wire Line
	1800 5850 2150 5850
$Comp
L VCC #PWR015
U 1 1 58998009
P 2150 5800
F 0 "#PWR015" H 2150 5900 30  0001 C CNN
F 1 "VCC" H 2150 5900 30  0000 C CNN
F 2 "" H 2150 5800 60  0001 C CNN
F 3 "" H 2150 5800 60  0001 C CNN
	1    2150 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 5850 2150 5800
$Comp
L GND #PWR016
U 1 1 58998AD2
P 2150 2000
F 0 "#PWR016" H 2150 2000 30  0001 C CNN
F 1 "GND" H 2150 1930 30  0001 C CNN
F 2 "" H 2150 2000 60  0001 C CNN
F 3 "" H 2150 2000 60  0001 C CNN
	1    2150 2000
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR017
U 1 1 58998B25
P 2150 1800
F 0 "#PWR017" H 2150 1900 30  0001 C CNN
F 1 "VCC" H 2150 1900 30  0000 C CNN
F 2 "" H 2150 1800 60  0001 C CNN
F 3 "" H 2150 1800 60  0001 C CNN
	1    2150 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 1950 2150 1950
Wire Wire Line
	2150 1950 2150 2000
Wire Wire Line
	1800 1850 2150 1850
Wire Wire Line
	2150 1850 2150 1800
Text GLabel 4550 1900 1    39   Input ~ 0
Pin41
Wire Wire Line
	4550 1900 4550 2000
Connection ~ 4550 2000
Wire Wire Line
	4800 2100 4800 2150
Wire Wire Line
	4800 2150 4750 2150
Wire Wire Line
	4750 2150 4750 2250
Wire Wire Line
	4750 2250 4700 2250
Text GLabel 4700 2250 0    39   Input ~ 0
Pin42
$EndSCHEMATC
