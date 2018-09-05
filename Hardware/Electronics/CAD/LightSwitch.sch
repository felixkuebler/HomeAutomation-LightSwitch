EESchema Schematic File Version 2
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
LIBS:74xgxx
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
LIBS:ESP8266
LIBS:HiLink
LIBS:SharpSSR
LIBS:SW_DPST_x2
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Light Switch"
Date "2018-02-10"
Rev "1.1.0"
Comp "Felix Kübler"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L HiLink U3
U 1 1 592BD6A6
P 7425 1475
F 0 "U3" H 7250 1775 60  0000 C CNN
F 1 "HLK-PM05" H 7425 1700 60  0000 C CNN
F 2 "HiLink:HLK-PM01" H 7425 1475 60  0001 C CNN
F 3 "" H 7425 1475 60  0001 C CNN
	1    7425 1475
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 J3
U 1 1 592BD89E
P 3425 4325
F 0 "J3" H 3425 4550 50  0000 C CNN
F 1 "MPE 087-1-002" H 3700 4475 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3425 4325 50  0001 C CNN
F 3 "" H 3425 4325 50  0001 C CNN
	1    3425 4325
	1    0    0    -1  
$EndComp
$Comp
L ESP-12E U4
U 1 1 592BD8DB
P 7600 3900
F 0 "U4" H 7600 4625 50  0000 C CNN
F 1 "ESP-12E" H 7600 4550 50  0000 C CNN
F 2 "ESP8266:ESP-12E_SMD" H 7600 3900 50  0001 C CNN
F 3 "" H 7600 3900 50  0001 C CNN
	1    7600 3900
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 592BDBEB
P 2975 4475
F 0 "R2" V 3150 4425 50  0000 C CNN
F 1 "RND 0805 1 10K" V 3075 4700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2905 4475 50  0001 C CNN
F 3 "" H 2975 4475 50  0001 C CNN
	1    2975 4475
	0    1    1    0   
$EndComp
$Comp
L CONN_01X06 J1
U 1 1 592BDEB8
P 3200 1525
F 0 "J1" H 3200 1950 50  0000 C CNN
F 1 "MPE 094-1-006" H 3475 1875 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 3200 1525 50  0001 C CNN
F 3 "" H 3200 1525 50  0001 C CNN
	1    3200 1525
	1    0    0    -1  
$EndComp
$Comp
L Screw_Terminal_1x02 J6
U 1 1 592BE1F1
P 6725 1475
F 0 "J6" H 6800 1175 50  0000 C TNN
F 1 "RND 205-00232" H 6525 1275 50  0000 C TNN
F 2 "Terminal:Terminal_1x2_2.54mm" H 6725 1250 50  0001 C CNN
F 3 "" H 6700 1475 50  0001 C CNN
	1    6725 1475
	1    0    0    1   
$EndComp
$Comp
L +3.3V #PWR01
U 1 1 592BFF6A
P 3125 4275
F 0 "#PWR01" H 3125 4125 50  0001 C CNN
F 1 "+3.3V" V 3175 4475 50  0000 C CNN
F 2 "" H 3125 4275 50  0001 C CNN
F 3 "" H 3125 4275 50  0001 C CNN
	1    3125 4275
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR02
U 1 1 592BFFF6
P 2725 4475
F 0 "#PWR02" H 2725 4225 50  0001 C CNN
F 1 "GND" V 2775 4325 50  0000 C CNN
F 2 "" H 2725 4475 50  0001 C CNN
F 3 "" H 2725 4475 50  0001 C CNN
	1    2725 4475
	0    1    1    0   
$EndComp
Text GLabel 2400 6375 0    60   Input ~ 0
OUTPUT_2
Text GLabel 2475 3725 0    60   Input ~ 0
INPUT_1
Text GLabel 2475 4375 0    60   Input ~ 0
INPUT_2
$Comp
L CONN_01X02 J2
U 1 1 592C0893
P 3425 3675
F 0 "J2" H 3425 3900 50  0000 C CNN
F 1 "MPE 087-1-002" H 3700 3825 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3425 3675 50  0001 C CNN
F 3 "" H 3425 3675 50  0001 C CNN
	1    3425 3675
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 592C0899
P 2975 3825
F 0 "R1" V 3150 3775 50  0000 C CNN
F 1 "RND 0805 1 10K" V 3075 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2905 3825 50  0001 C CNN
F 3 "" H 2975 3825 50  0001 C CNN
	1    2975 3825
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 592C08A1
P 3125 3625
F 0 "#PWR03" H 3125 3475 50  0001 C CNN
F 1 "+3.3V" V 3175 3825 50  0000 C CNN
F 2 "" H 3125 3625 50  0001 C CNN
F 3 "" H 3125 3625 50  0001 C CNN
	1    3125 3625
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR04
U 1 1 592C08A8
P 2725 3825
F 0 "#PWR04" H 2725 3575 50  0001 C CNN
F 1 "GND" V 2775 3675 50  0000 C CNN
F 2 "" H 2725 3825 50  0001 C CNN
F 3 "" H 2725 3825 50  0001 C CNN
	1    2725 3825
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x02 J5
U 1 1 592C0CDF
P 3900 6275
F 0 "J5" H 3950 6000 50  0000 C TNN
F 1 "RND 205-00232" H 3675 6075 50  0000 C TNN
F 2 "Terminal:Terminal_1x2_2.54mm" H 3900 6050 50  0001 C CNN
F 3 "" H 3875 6275 50  0001 C CNN
	1    3900 6275
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 592C0CF1
P 2800 6175
F 0 "#PWR05" H 2800 5925 50  0001 C CNN
F 1 "GND" V 2850 6000 50  0000 C CNN
F 2 "" H 2800 6175 50  0001 C CNN
F 3 "" H 2800 6175 50  0001 C CNN
	1    2800 6175
	0    1    1    0   
$EndComp
$Comp
L GND #PWR06
U 1 1 592C1574
P 7925 1375
F 0 "#PWR06" H 7925 1125 50  0001 C CNN
F 1 "GND" V 7975 1225 50  0000 C CNN
F 2 "" H 7925 1375 50  0001 C CNN
F 3 "" H 7925 1375 50  0001 C CNN
	1    7925 1375
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR07
U 1 1 592C2849
P 8700 4300
F 0 "#PWR07" H 8700 4050 50  0001 C CNN
F 1 "GND" V 8600 4225 50  0000 C CNN
F 2 "" H 8700 4300 50  0001 C CNN
F 3 "" H 8700 4300 50  0001 C CNN
	1    8700 4300
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR08
U 1 1 592C2C75
P 6500 4300
F 0 "#PWR08" H 6500 4150 50  0001 C CNN
F 1 "+3.3V" V 6400 4375 50  0000 C CNN
F 2 "" H 6500 4300 50  0001 C CNN
F 3 "" H 6500 4300 50  0001 C CNN
	1    6500 4300
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR09
U 1 1 592C2CAB
P 6500 3800
F 0 "#PWR09" H 6500 3650 50  0001 C CNN
F 1 "+3.3V" V 6575 3900 50  0000 C CNN
F 2 "" H 6500 3800 50  0001 C CNN
F 3 "" H 6500 3800 50  0001 C CNN
	1    6500 3800
	0    -1   -1   0   
$EndComp
Text GLabel 8750 3575 2    60   Input ~ 0
TX
Text GLabel 8750 3725 2    60   Input ~ 0
RX
Text GLabel 8650 4000 2    60   Input ~ 0
MODE
Text GLabel 6050 3800 0    60   Input ~ 0
INPUT_1
Text GLabel 6050 3950 0    60   Input ~ 0
INPUT_2
Text GLabel 6050 4150 0    60   Input ~ 0
OUTPUT_1
Text GLabel 6050 4300 0    60   Input ~ 0
OUTPUT_2
NoConn ~ 8500 3800
NoConn ~ 6700 3600
NoConn ~ 6700 3700
NoConn ~ 7350 4800
NoConn ~ 7450 4800
NoConn ~ 7550 4800
NoConn ~ 7650 4800
NoConn ~ 7750 4800
NoConn ~ 7850 4800
$Comp
L GND #PWR010
U 1 1 592C460C
P 2850 1775
F 0 "#PWR010" H 2850 1525 50  0001 C CNN
F 1 "GND" V 2900 1575 50  0000 C CNN
F 2 "" H 2850 1775 50  0001 C CNN
F 3 "" H 2850 1775 50  0001 C CNN
	1    2850 1775
	0    1    1    0   
$EndComp
Text GLabel 2600 1475 0    60   Input ~ 0
RX
Text GLabel 2600 1325 0    60   Input ~ 0
TX
NoConn ~ 3000 1275
NoConn ~ 3000 1675
Text GLabel 3225 2800 2    60   Input ~ 0
MODE
$Comp
L GND #PWR011
U 1 1 592C5F8F
P 3200 2625
F 0 "#PWR011" H 3200 2375 50  0001 C CNN
F 1 "GND" V 3250 2475 50  0000 C CNN
F 2 "" H 3200 2625 50  0001 C CNN
F 3 "" H 3200 2625 50  0001 C CNN
	1    3200 2625
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR012
U 1 1 592C600F
P 3200 2975
F 0 "#PWR012" H 3200 2825 50  0001 C CNN
F 1 "+3.3V" V 3250 3150 50  0000 C CNN
F 2 "" H 3200 2975 50  0001 C CNN
F 3 "" H 3200 2975 50  0001 C CNN
	1    3200 2975
	0    1    1    0   
$EndComp
$Comp
L SSR U2
U 1 1 592BFDC3
P 3250 6275
F 0 "U2" H 3000 6600 60  0000 C CNN
F 1 "IXYS CPC1966Y" H 3300 6525 60  0000 C CNN
F 2 "SSR:CPC1966Y" H 3375 6275 60  0001 C CNN
F 3 "" H 3375 6275 60  0001 C CNN
	1    3250 6275
	1    0    0    1   
$EndComp
$Comp
L +3.3V #PWR013
U 1 1 595EB4E9
P 9050 4100
F 0 "#PWR013" H 9050 3950 50  0001 C CNN
F 1 "+3.3V" V 9100 4300 50  0000 C CNN
F 2 "" H 9050 4100 50  0001 C CNN
F 3 "" H 9050 4100 50  0001 C CNN
	1    9050 4100
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 595F9F36
P 2650 6375
F 0 "R4" V 2850 6375 50  0000 C CNN
F 1 "RND 0805 1 220" V 2750 6225 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2580 6375 50  0001 C CNN
F 3 "" H 2650 6375 50  0001 C CNN
	1    2650 6375
	0    1    1    0   
$EndComp
Text GLabel 2400 5725 0    60   Input ~ 0
OUTPUT_1
$Comp
L Screw_Terminal_1x02 J4
U 1 1 595FA2AF
P 3900 5625
F 0 "J4" H 3950 5975 50  0000 C TNN
F 1 "RND 205-00232" H 3675 5900 50  0000 C TNN
F 2 "Terminal:Terminal_1x2_2.54mm" H 3900 5400 50  0001 C CNN
F 3 "" H 3875 5625 50  0001 C CNN
	1    3900 5625
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR014
U 1 1 595FA2B5
P 2800 5525
F 0 "#PWR014" H 2800 5275 50  0001 C CNN
F 1 "GND" V 2850 5350 50  0000 C CNN
F 2 "" H 2800 5525 50  0001 C CNN
F 3 "" H 2800 5525 50  0001 C CNN
	1    2800 5525
	0    1    1    0   
$EndComp
$Comp
L SSR U1
U 1 1 595FA2BD
P 3250 5625
F 0 "U1" H 3000 5950 60  0000 C CNN
F 1 "IXYS CPC1966Y" H 3300 5875 60  0000 C CNN
F 2 "SSR:CPC1966Y" H 3375 5625 60  0001 C CNN
F 3 "" H 3375 5625 60  0001 C CNN
	1    3250 5625
	1    0    0    1   
$EndComp
$Comp
L R R3
U 1 1 595FA2C4
P 2650 5725
F 0 "R3" V 2825 5725 50  0000 C CNN
F 1 "RND 0805 1 220" V 2750 5575 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 2580 5725 50  0001 C CNN
F 3 "" H 2650 5725 50  0001 C CNN
	1    2650 5725
	0    1    1    0   
$EndComp
$Comp
L SW_DPST_x2 SW2
U 1 1 599EBC5A
P 6900 2500
F 0 "SW2" H 6900 2400 50  0000 C CNN
F 1 "SMD 4x4mm Button" H 6900 2300 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_TL3342" H 6900 2500 50  0001 C CNN
F 3 "" H 6900 2500 50  0001 C CNN
	1    6900 2500
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR015
U 1 1 599EBD49
P 6400 2500
F 0 "#PWR015" H 6400 2350 50  0001 C CNN
F 1 "+3.3V" V 6400 2750 50  0000 C CNN
F 2 "" H 6400 2500 50  0001 C CNN
F 3 "" H 6400 2500 50  0001 C CNN
	1    6400 2500
	0    -1   -1   0   
$EndComp
$Comp
L R R5
U 1 1 599EC273
P 7600 2650
F 0 "R5" V 7680 2650 50  0000 C CNN
F 1 "RND 0805 1 10K" V 7750 2925 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7530 2650 50  0001 C CNN
F 3 "" H 7600 2650 50  0001 C CNN
	1    7600 2650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR016
U 1 1 599EC69C
P 7900 2650
F 0 "#PWR016" H 7900 2400 50  0001 C CNN
F 1 "GND" V 7900 2450 50  0000 C CNN
F 2 "" H 7900 2650 50  0001 C CNN
F 3 "" H 7900 2650 50  0001 C CNN
	1    7900 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3125 4475 3225 4475
Wire Wire Line
	3225 4475 3225 4375
Wire Wire Line
	3125 4275 3225 4275
Wire Wire Line
	2725 4475 2825 4475
Wire Wire Line
	3125 3825 3225 3825
Wire Wire Line
	3225 3825 3225 3725
Wire Wire Line
	3125 3625 3225 3625
Wire Wire Line
	2725 3825 2825 3825
Wire Wire Line
	3225 4375 2475 4375
Wire Wire Line
	3225 3725 2475 3725
Connection ~ 3225 3725
Connection ~ 3225 4375
Wire Wire Line
	3600 6175 3700 6175
Wire Wire Line
	3700 6375 3600 6375
Wire Wire Line
	6925 1375 7025 1375
Wire Wire Line
	7025 1575 6925 1575
Wire Wire Line
	8500 4300 8700 4300
Wire Wire Line
	8500 4200 8600 4200
Wire Wire Line
	8600 4200 8600 4300
Connection ~ 8600 4300
Wire Wire Line
	6700 3800 6500 3800
Wire Wire Line
	6500 4300 6700 4300
Wire Wire Line
	6050 3800 6250 3800
Wire Wire Line
	6250 3800 6250 3900
Wire Wire Line
	6250 3900 6700 3900
Wire Wire Line
	6700 4000 6200 4000
Wire Wire Line
	6200 4000 6200 3950
Wire Wire Line
	6200 3950 6050 3950
Wire Wire Line
	6700 4100 6200 4100
Wire Wire Line
	6200 4100 6200 4150
Wire Wire Line
	6250 4300 6250 4200
Wire Wire Line
	6250 4200 6700 4200
Wire Wire Line
	6200 4150 6050 4150
Wire Wire Line
	6050 4300 6250 4300
Wire Wire Line
	8500 3600 8650 3600
Wire Wire Line
	8650 3600 8650 3575
Wire Wire Line
	8650 3575 8750 3575
Wire Wire Line
	8750 3725 8650 3725
Wire Wire Line
	8650 3725 8650 3700
Wire Wire Line
	8650 3700 8500 3700
Wire Wire Line
	8650 4000 8500 4000
Wire Wire Line
	3000 1475 2600 1475
Wire Wire Line
	3000 1375 2750 1375
Wire Wire Line
	2750 1375 2750 1325
Wire Wire Line
	2750 1325 2600 1325
Wire Wire Line
	2850 1575 3000 1575
Wire Wire Line
	3000 1775 2850 1775
Wire Wire Line
	3100 2625 3200 2625
Wire Wire Line
	3200 2975 3100 2975
Wire Wire Line
	7925 1375 7825 1375
Wire Wire Line
	8500 4100 9050 4100
Wire Wire Line
	2900 6175 2800 6175
Wire Wire Line
	2900 6375 2800 6375
Wire Wire Line
	2500 6375 2400 6375
Wire Wire Line
	3600 5525 3700 5525
Wire Wire Line
	3700 5725 3600 5725
Wire Wire Line
	2900 5525 2800 5525
Wire Wire Line
	2900 5725 2800 5725
Wire Wire Line
	2500 5725 2400 5725
Wire Wire Line
	6400 2500 6550 2500
Text GLabel 7700 2500 2    60   Input ~ 0
reset
Wire Wire Line
	7750 2650 7900 2650
Wire Wire Line
	7700 2500 7250 2500
Wire Wire Line
	7450 2650 7450 2500
Connection ~ 7450 2500
Text GLabel 9050 3900 2    60   Input ~ 0
reset
Wire Wire Line
	9050 3900 8500 3900
$Comp
L +3.3V #PWR017
U 1 1 5A1410F1
P 7925 1575
F 0 "#PWR017" H 7925 1425 50  0001 C CNN
F 1 "+3.3V" V 7975 1725 50  0000 C CNN
F 2 "" H 7925 1575 50  0001 C CNN
F 3 "" H 7925 1575 50  0001 C CNN
	1    7925 1575
	0    1    1    0   
$EndComp
Wire Wire Line
	7825 1575 7925 1575
$Comp
L +3.3V #PWR018
U 1 1 5A16AF86
P 2850 1575
F 0 "#PWR018" H 2850 1425 50  0001 C CNN
F 1 "+3.3V" V 2775 1750 50  0000 C CNN
F 2 "" H 2850 1575 50  0001 C CNN
F 3 "" H 2850 1575 50  0001 C CNN
	1    2850 1575
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X03 J7
U 1 1 5A7F4921
P 2725 2800
F 0 "J7" H 2725 2500 50  0000 C CNN
F 1 "MPE 087-1-003" H 3000 2575 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 2725 2800 50  0001 C CNN
F 3 "" H 2725 2800 50  0001 C CNN
	1    2725 2800
	-1   0    0    1   
$EndComp
Wire Wire Line
	2925 2800 3225 2800
Wire Wire Line
	2925 2700 3100 2700
Wire Wire Line
	3100 2700 3100 2625
Wire Wire Line
	2925 2900 3100 2900
Wire Wire Line
	3100 2900 3100 2975
$EndSCHEMATC
