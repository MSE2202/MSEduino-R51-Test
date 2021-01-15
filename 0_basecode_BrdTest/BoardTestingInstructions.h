
/*
//Western Engineering base code board testing
Oct 10,2020
  
\Board Testing Instructions



*/

#ifndef BOARDTESTINGINSTRUCTIONS_H
#define BOARDTESTINGINSTRUCTIONS_H 1





const static char *BoardTesting_Instructions[] PROGMEM = 
{
//Test 1  [0]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                                     !!\n"
"!!  NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5V tolerant. You will Damage the ESP32 if you connect 5V to any of its pins (only exception is the Vin pin) !!\n"
"!!                                                                                                                                                                                     !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"
" Board Testing \n"
"Preform these tests with only USB cable, DO NOT connect battery unless otherwise noted\n"
"\n"  
"Test 1 out of 28\n"
" Blink on ESP32 LED Test         Next Test: SMART LEDs Test\n"
"First Test: Blink on ESP32 LED\n"
"Enter \"C\"ontinue, \"S\"kip this test or \"Q\"uit \n",
//
//Test 1 continued  [1]
" Blink on ESP32 LED, Test 1 out of 28 \n" 
"Enter \"C\"ontinue to next test,\"B\"ack to go beginning of Test, \"S\"kip to the next Test or \"Q\"uit \n"
"   - Blue LED on ESP32 board should be blinking, if working enter \"C\' \n"
"   - If not working: unplug ESP32 from power sources. \n"
"      --- Use multimeter to check continuity (beep test), to ground, to 3V3, on physical pin 4,  if beep find short and fix. (use the schematic and board artwork as reference \n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 2 [2]
"\n"  
"Test 2 out of 28\n"
" SMART LEDs Test         Next Test: Push Button 1 Test\n"
"Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP5 (labeled - LEDs), then enter \"C\" \n",
//
//Test 2 continued  [3]
"\n"  
"Test 2 out of 28\n"
" SMART LEDs Test         Next Test: Push Button 1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - SMART LED1 (look for label on board) should change colours, then SMART LED2 should change colours,  then back to LED1, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to JP5\n"
"   --- did only one light? If yes then the connections from ESP32 to SMART LEDS is good, check LED power/ground pins and Din/Dout on LED not working\n"
"   --- check solder joints on JP5, D25 (physical pin – 23) and SMART LED1/LED2 \n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n"
"   --- Use oscilloscope to check signal coming from pin 25 , look at SK2812 data sheet for signal specs.\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 3 [4]
"\n"  
"Test 3 out of 28\n"
" Push Button 1 Test         Next Test: Push Button 2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions: \n"
"   - Put jumper on two pin header JP13 (labeled - PB1), then enter \"C\" \n",
//
//Test 3 continued  [5]
"\n"  
"Test 3 out of 28\n"
" Push Button 1 Test         Next Test: Push Button 2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button 1 change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to two pin header JP13\n"
"   --- check solder joints on two pin header JP13, D27 (physical pin – 25), Resistor 14 and Push Button 1\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 4 [6]
"\n"  
"Test 4 out of 28\n"
" Push Button 2 Test         Next Test: Slide Switch 1a Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP14 (labeled - PB2), then enter \"C\" \n",
//
//Test 4 continued [7]
"\n"  
"Test 4 out of 28\n"
" Push Button 2 Test         Next Test: Slide Switch 1a Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button 2 change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to JP14\n"
"   --- check solder joints on JP14, D26 (physical pin – 24), Resistor 14 and Push Button 2\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 5 [8]
"\n"  
"Test 5 out of 28\n"
" Slide Switch 1a Test         Next Test: Slide Switch 1b Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP7 (labeled - a) , then enter \"C\" \n",
//
//Test 5 continued [9]
"\n"  
"Test 5 out of 28\n"
" Slide Switch 1a Test         Next Test: Slide Switch 1b Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1a change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to JP7\n"
"   --- check solder joints on JP7, D13 (physical pin – 28), Resistor 7 and Slide Switch 1a\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 6 [10]
"\n"  
"Test 6 out of 28\n"
" Slide Switch 1b Test         Next Test: Slide Switch 2a Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP8 (labeled - S1b), then enter \"C\" \n",
//
//Test 6 continued [11]
"\n"  
"Test 6 out of 28\n"
" Slide Switch 1b Test         Next Test: Slide Switch 2a Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to JP8\n"
"   --- check solder joints on JP8, D16 (physical pin – 6), Resistor 8 and Slide Switch 1b\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 7 [12]
"\n"  
"Test 7 out of 28\n"
" Slide Switch 2a Test         Next Test: Slide Switch 2b Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP6 (labeled - a), then enter \"C\" \n",
//
//Test 7 continued [13]
"\n"  
"Test 7 out of 28\n"
" Slide Switch 2a Test         Next Test: Slide Switch 2b Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 2a change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to JP6\n"
"   --- check solder joints on JP6, D14 (physical pin – 26), Resistor 5 and Slide Switch 2a\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 8 [14]
"\n"  
"Test 8 out of 28\n"
" Slide Switch 2b Test         Next Test: Potentiometer R1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP9 (labeled - S2b), then enter \"C\" \n",
//
//Test 8 continued [15]
"\n"  
"Test 8 out of 28\n"
" Slide Switch 2b Test         Next Test: Potentiometer R1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 2b change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to JP9\n"
"   --- check solder joints on JP9, D17 (physical pin – 7), Resistor 6 and Slide Switch 2b\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 9 [16]
"\n"  
"Test 9 out of 28\n"
" Potentiometer R1 Test        Next Test: Potentiometer R2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP2 (labeled - PR2), then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 9 continued [17]
"\n"  
"Test 9 out of 28\n"
" Potentiometer R1 Test        Next Test: Potentiometer R2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to JP2\n"
"   --- check solder joints on JP2, AD4 (physical pin – 21), Resistor 3 and Potentiometer R1\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 10 [18]
"\n"  
"Test 10 out of 28\n"
" Potentiometer R2 Test        Next Test: Analog Input AD0 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on JP3 (labeled - PR1), then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scolling data.\n"
"             The Serial Monitor will display Potentiometer R2 values as you adjust the potentiometer.\n",
//
//Test 10 continued [19]
"\n"  
"Test 10 out of 28\n"
" Potentiometer R2 Test        Next Test: Analog Input AD0 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R2 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check jumper is connected correctly to J32\n"
"   --- check solder joints on JP3, AD7 (physical pin – 20), Resistor 4 and Potentiometer R2\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n"
"   --- Note: Potentiometer R2 is a multi-turn pot, it will take 10 or more turns to reach one max/min resistance\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 11 [20]
"\n"  
"Test 11 out of 28\n"
" Analog Input AD0 Test        Next Test: Analog Input AD3 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Remove jumper on JP2 (labeled - PR2)\n"
"   - Take one of your supplied receptacles to receptacles wires and put one end on JP2 pin closest to ESP32\n"
"   - Connect the other end to J7 (labeled - AD0) pin closet to ESP32, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 11 continued [21]
"\n"  
"Test 11 out of 28\n"
" Analog Input AD0 Test        Next Test: Analog Input AD3 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to JP2 pin closest to ESP32 \n"
"   --- check the other end is connected to J7 (labeled - AD0) pin closet to ESP32\n"
"   --- check solder joints on J7, AD0 (physical pin – 17)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 12 [22]
"\n"  
"Test 12 out of 28\n"
" Analog Input AD3 Test        Next Test: Analog Input AD6 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave wire jumper on JP2 pin closest to ESP32 connected to wire jumper\n"
"   - Connect the other end to J6 (labeled - AD3) pin closet to ESP32, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 12 continued [23]
"\n"  
"Test 12 out of 28\n"
" Analog Input AD3 Test        Next Test: Analog Input AD6 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to JP2 pin closest to ESP32 \n"
"   --- check the other end is connected to J6 (labeled - AD3) pin closet to ESP32\n"
"   --- check solder joints on J6, AD3 (physical pin – 18)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 13 [24]
"\n"  
"Test 13 out of 28\n"
" Analog Input AD6 Test        Next Test: Analog Input AD5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave wire jumper on JP2 pin closest to ESP32 connected to wire jumper\n"
"   - Connect the other end to J5 (labeled - AD6) pin closet to ESP32, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 13 continued [25]
"\n"  
"Test 13 out of 28\n"
" Analog Input AD6 Test        Next Test: Analog Input AD5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to JP2 pin closest to ESP32 \n"
"   --- check the other end is connected to J5 (labeled - AD6) pin closet to ESP32\n"
"   --- check solder joints on J5, AD6 (physical pin – 19)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 14 [26]
"\n"  
"Test 14 out of 28\n"
" Analog Input AD5 Test        Next Test: Digital Input D2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave wire jumper on JP2 pin closest to ESP32 connected to wire jumper\n"
"   - Remove jumper on two pin header JP1\n"
"   - Connect the other end to J2 (labeled - AD5) pin closet to ESP32, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 14 continued [27]
"\n"  
"Test 14 out of 28\n"
" Analog Input AD5 Test        Next Test: Digital Input D2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer,\n"
"           if working remoe the wire jumper and enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to JP2 pin closest to ESP32 \n"
"   --- check the other end is connected to J2 (labeled - AD5) pin closet to ESP32\n"
"   --- check solder joints on J2, AD5 (physical pin – 22)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 15 [28]
"\n"  
"Test 15 out of 28\n"
" Digital Input D2 Test        Next Test: Digital Input D4 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Remove jumper on two pin header JP8 (labeled - S1b)\n"
"   - Take one of your supplied receptacles to wires and put one end on two pin header JP8 pin closest to four resistors\n"
"   - Connect the other end to J9 (in 3 Volt Digital area labeled - 2) pin closet to ESP32, then enter \"C\" \n",
//
//Test 15 continued [29]
"\n"  
"Test 15 out of 28\n"
" Digital Input D2 Test        Next Test: Digital Input D4 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J9 (in 3 Volt Digital area labeled - 2) pin closet to ESP32\n"
"   --- check solder joints on J9, D2 (physical pin – 4)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 15 [30]
"\n"  
"Test 15 out of 28\n"
" Digital Input D2 Test        Next Test: Digital Input D4 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J29 (in 5 Volt Digital area labeled - 2) pin closet to ESP32, then enter \"C\" \n",
//
//Test 15 continued [31]
"\n"  
"Test 15 out of 28\n"
" Digital Input D2 Test        Next Test: Digital Input D4 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J29 (in 5 Volt Digital area labeled - 2) pin closet to ESP32\n"
"   --- check solder joints on J29, D2 (physical pin – 4)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 16 [32]
"\n"  
"Test 16 out of 28\n"
" Digital Input D4 Test        Next Test: Digital Input D15 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Connect the other end to J10 (in 3 Volt Digital area labeled - 4) pin closet to ESP32, then enter \"C\" \n",
//
//Test 16 continued [33]
"\n"  
"Test 16 out of 28\n"
" Digital Input D4 Test        Next Test: Digital Input D15 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J10 (in 3 Volt Digital area labeled - 4) pin closet to ESP32\n"
"   --- check solder joints on J10, D4 (physical pin – 4)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 16 [34]
"\n"  
"Test 16 out of 28\n"
" Digital Input D4 Test        Next Test: Digital Input D15 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J28 (in 5 Volt Digital area labeled - 4) pin closet to ESP32, then enter \"C\" \n",
//
//Test 16 continued [35]
"\n"  
"Test 16 out of 28\n"
" Digital Input D4 Test        Next Test: Digital Input D15 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J28 (in 5 Volt Digital area labeled - 4) pin closet to ESP32\n"
"   --- check solder joints on J28, D4 (physical pin – 4)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 17 [36]
"\n"  
"Test 17 out of 28\n"
" Digital Input D15 Test        Next Test: Digital Input D12 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Connect the other end to J8 (in 3 Volt Digital area labeled - 15) pin closet to ESP32, then enter \"C\" \n",
//
//Test 17 continued [37]
"\n"  
"Test 17 out of 28\n"
" Digital Input D15 Test        Next Test: Digital Input D12 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J8 (in 3 Volt Digital area labeled - 15) pin closet to ESP32\n"
"   --- check solder joints on J8, D15 (physical pin – 3)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 17 [38]
"\n"  
"Test 17 out of 28\n"
" Digital Input D15 Test        Next Test: Digital Input D12 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J30 (in 5 Volt Digital area labeled - 4) pin closet to ESP32, then enter \"C\" \n",
//
//Test 17 continued [39]
"\n"  
"Test 17 out of 28\n"
" Digital Input D15 Test        Next Test: Digital Input D12 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"

"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J30 (in 5 Volt Digital area labeled - 15) pin closet to ESP32\n"
"   --- check solder joints on J30, D15 (physical pin – 3)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 18 [40]
"\n"  
"Test 18 out of 28\n"
" Digital Input D12 Test        Next Test: Digital Input D5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Connect the other end to J17 (in 3 Volt Digital area labeled - 12) pin closet to ESP32, then enter \"C\" \n",
//
//Test 18 continued [41]
"\n"  
"Test 18 out of 28\n"
" Digital Input D12 Test        Next Test: Digital Input D5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J17 (in 3 Volt Digital area labeled - 12) pin closet to ESP32\n"
"   --- check solder joints on J17, D12 (physical pin – 27)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 18 [42]
"\n"  
"Test 18 out of 28\n"
" Digital Input D12 Test        Next Test: Digital Input D5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J24 (in 5 Volt Digital area labeled - 12) pin closet to ESP32, then enter \"C\" \n",
//
//Test 18 continued [43]
"\n"  
"Test 18 out of 28\n"
" Digital Input D12 Test        Next Test: Digital Input D5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J24 (in 5 Volt Digital area labeled - 12) pin closet to ESP32\n"
"   --- check solder joints on J24, D12 (physical pin – 27)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 19 [44]
"\n"  
"Test 19 out of 28\n"
" Digital Input D5 Test        Next Test: Digital Input D18 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Connect the other end to J13 (in 3 Volt Digital area labeled - 5) pin closet to ESP32, then enter \"C\" \n",
//
//Test 19 continued [45]
"\n"  
"Test 19 out of 28\n"
" Digital Input D5 Test        Next Test: Digital Input D18 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J13 (in 3 Volt Digital area labeled - 5) pin closet to ESP32\n"
"   --- check solder joints on J13, D5 (physical pin – 8)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 19 [46]
"\n"  
"Test 19 out of 28\n"
" Digital Input D5 Test        Next Test: Digital Input D18 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J27 (in 5 Volt Digital area labeled - 5) pin closet to ESP32, then enter \"C\" \n",
//
//Test 19 continued [47]
"\n"  
"Test 19 out of 28\n"
" Digital Input D5 Test        Next Test: Digital Input D18 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J27 (in 5 Volt Digital area labeled - 5) pin closet to ESP32\n"
"   --- check solder joints on J27, D5 (physical pin – 8)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 20 [48]
"\n"  
"Test 20 out of 28\n"
" Digital Input D18 Test        Next Test: Digital Input D19 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Connect the other end to J14 (in 3 Volt Digital area labeled - 18) pin closet to ESP32, then enter \"C\" \n",
//
//Test 20 continued [49]
"\n"  
"Test 20 out of 28\n"
" Digital Input D18 Test        Next Test: Digital Input D19 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J14 (in 3 Volt Digital area labeled - 18) pin closet to ESP32\n"
"   --- check solder joints on J14, D18 (physical pin – 9)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 20 [50]
"\n"  
"Test 20 out of 28\n"
" Digital Input D18 Test        Next Test: Digital Input D19 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J26 (in 5 Volt Digital area labeled - 18) pin closet to ESP32, then enter \"C\" \n",
//
//Test 20 continued [51]
"\n"  
"Test 20 out of 28\n"
" Digital Input D18 Test        Next Test: Digital Input D19 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J26 (in 5 Volt Digital area labeled - 18) pin closet to ESP32\n"
"   --- check solder joints on J26, D18 (physical pin – 9)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 21 [52]
"\n"  
"Test 21 out of 28\n"
" Digital Input D19 Test        Next Test: Digital Input D23 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Connect the other end to J15 (in 3 Volt Digital area labeled - 19) pin closet to ESP32, then enter \"C\" \n",
//
//Test 21 continued [53]
"\n"  
"Test 21 out of 28\n"
" Digital Input D19 Test        Next Test: Digital Input D23 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J15 (in 3 Volt Digital area labeled - 19) pin closet to ESP32\n"
"   --- check solder joints on J15, D19 (physical pin – 10)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 21 [54]
"\n"  
"Test 21 out of 28\n"
" Digital Input D19 Test        Next Test: Digital Input D23 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J25 (in 5 Volt Digital area labeled - 19) pin closet to ESP32, then enter \"C\" \n",
//
//Test 21 continued [55]
"\n"  
"Test 21 out of 28\n"
" Digital Input D19 Test        Next Test: Digital Input D23 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J25 (in 5 Volt Digital area labeled - 19) pin closet to ESP32\n"
"   --- check solder joints on J25, D19 (physical pin – 10)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 22 [56]
"\n"  
"Test 22 out of 28\n"
" Digital Input D23 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Connect the other end to J21 (in 3 Volt Digital area labeled - 23) pin closet to ESP32, then enter \"C\" \n",
//
//Test 22 continued [57]
"\n"  
"Test 22 out of 28\n"
" Digital Input D23 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP8 pin closest four resistors\n"
"   --- check the other end is connected to J21 (in 3 Volt Digital area labeled - 23) pin closet to ESP32\n"
"   --- check solder joints on J21, D23 (physical pin – 15)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 22 [58]
"\n"  
"Test 22 out of 28\n"
" Digital Input D23 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on two pin header JP8 (labeled - S1b)\n"
"   - Move the other end to J23 (in 5 Volt Digital area labeled - 23) pin closet to ESP32, then enter \"C\" \n",
//
//Test 22 continued [59]
"\n"  
"Test 22 out of 28\n"
" Digital Input D23 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Slide Switch 1b  change of state, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to two pin header JP13, pin closest to Slide Switches\n"
"   --- check the other end is connected to two pin header J23 (in 5 Volt Digital area labeled - 23) pin closet to ESP32\n"
"   --- check solder joints on two pin header J23, D23 (physical pin – 15)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 23 [60]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                                     !!\n"
"!!  NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5V tolerant. You will Damage the ESP32 if you connect 5V to any of its pins (only exception is the Vin pin) !!\n"
"!!                                                                                                                                                                                     !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 23 out of 28\n"
" I2C 3V Port Pin SDA Test        Next Test: I2C 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow your ESP32 if you're not careful connecting to the correct pins  !!!! \n" 
"   - Disconnect you wire jumper (both ends) reconnect one end to the two pin header JP13, pin closest to the resistors\n"   
"   - Connect the other end to four pin header JP11 (has labels - Gnd, 3V, SCLK, SDA) to pin labeled SDA, then enter \"C\" \n",
//
//Test 23 continued [61]
"\n"  
"Test 23 out of 28\n"
" I2C 3V Port Pin SDA Test        Next Test: I2C 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when Push Botton 1 (PB1)is pressed, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to one end of the two pin header JP13, pin closest to the resistors\n"
"   --- check the other end is connected to four pin header JP11 (has labels - Gnd, 3V, SCLK, SDA) to pin labeled SDA,\n"
"   --- make sure Transistor Q3 soldered in the correct orientation\n"
"   --- check solder joints on four pin header J11, Transistor Q3, Resistor R12 and R13, D21/I2C_DA (physical pin – 11)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 23 [62]
"\n"  
"Test 23 out of 28\n"
" I2C 3V Port Pin SCLK Test        Next Test: I2C 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave wire jumper on the one end of the two pin header JP13, pin closest to the resistors\n"   
"   - Move the other end to four pin header JP11 (has labels - Gnd, 3V, SCLK, SDA) to pin labeled SCLK, then enter \"C\" \n",
//
//Test 23 continued [63]
"\n"  
"Test 23 out of 28\n"
" I2C 3V Port Pin Test        Next Test: I2C 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when Push Botton 1 (PB1)is pressed, if working enter \"C\" \n"
"   --- check wire jumper is connected correctly to the one end of the two pin header JP13, pin closest to the resistors\n"  
"   --- check the other end is connected to four pin header JP11 (has labels - Gnd, 3V, SCLK, SDA) to pin labeled SCLK,\n"
"   --- make sure Transistor Q4 soldered in the correct orientation\n"
"   --- check solder joints on four pin header J11, Transistor Q4, Resistor R15 and R16, D22/I2C_CLK (physical pin – 14)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 24 [64]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                                     !!\n"
"!!  NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5V tolerant. You will Damage the ESP32 if you connect 5V to any of its pins (only exception is the Vin pin) !!\n"
"!!                                                                                                                                                                                     !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 24 out of 28\n"
" I2C 5V Port Pin Test        Next Test: UART0 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow you're ESP32 if your not careful connecting to the correct pins  !!!! \n" 
"   - Move the wire jumper from JP13 to the four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled Gnd\n"
"   - Connect the other end to four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled SDA, then enter \"C\" \n",
//
//Test 24 continued [65]
"\n"  
"Test 24 out of 28\n"
" I2C 5V Port Pin Test        Next Test: UART0 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when wire jumper is removed from ground pin and replaced on ground pin, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to the four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled Gnd\n"  
"   --- check the other end is connected to four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled SDA,\n"
"   --- make sure Transistor Q3 soldered in the correct orientation\n"
"   --- check solder joints on four pin header J12, Transistor Q3, Resistor R12 and R13, D21/I2C_DA (physical pin – 11)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//
//Test 24 [66]
"\n"  
"Test 24 out of 28\n"
" I2C 5V Port Pin Test        Next Test: UART0 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - put wire jumper back to the four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled Gnd\n"  
"   - Move the other end to four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled SCLK, then enter \"C\" \n",
//
//Test 24 continued [67]
"\n"  
"Test 24 out of 28\n"
" I2C 5V Port Pin Test        Next Test: UART0 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when wire jumper is removed from ground pin and replaced on ground pin, if working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to the four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled Gnd\n"  
"   --- check the other end is connected to four pin header JP12 (has labels - Gnd, 5V, SCLK, SDA) to pin labeled SCLK,\n"
"   --- make sure Transistor Q4 soldered in the correct orientation\n"
"   --- check solder joints on four pin header J12, Transistor Q4, Resistor R15 and R16, D22/I2C_CLK (physical pin – 14)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 25 [68]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                                     !!\n"
"!!  NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5V tolerant. You will Damage the ESP32 if you connect 5V to any of its pins (only exception is the Vin pin) !!\n"
"!!                                                                                                                                                                                     !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 25 out of 28\n"
" UART0 3V Port Pin Test        Next Test: UART0 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow you're ESP32 if your not careful connecting to the correct pins  !!!! \n" 
"   - Disconnect the wire jumper( both ends), reconnect one end to the four pin header JP15 (has labels - Gnd, 3V, Tx, Rx) to pin labeled Tx.\n"   
"   - Using a 4K7 resistor put in the open end of the wire jumper, take a second jumer wire and connect to the other end of the 4k7 resistor.\n" 
"   - This test automatically counts from 1 to 10 then print an X.\n"
"   - During the 1 to 10 count (not before 1 or after 10), connect the free end of the second jumper wire to the four pin header JP15 (has labels - Gnd, 3V, Tx, Rx) to pin labeled Rx.\n"
"   - Enter \"C\" to start test.\n",
"\n"
//
//Test 25 continued [69]

"\n"  
"Test 25 out of 28\n"
" UART0 3V Port Pin Test        Next Test: UART0 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will display either error or worked, if worked disconnect the wire jumper ( both ends) and push \"C\" \n"
"\n"
"   - If error it's not working: unplug ESP32 from power sources. \n"
"   --- check the two wire jumpers is connected correctly to the four-pin header JP15 (has labels - Gnd, 3V, Tx, Rx) to pin labeled Rx and Tx\n"   
"   --- check the other ends are connected to a 4K7 resistor\n"
"   --- make sure Transistor Q5 and Q6 are soldered in the correct orientation\n"
"   --- check solder joints on four pin header J15, Transistor Q5 and Q6, Resistor R18, R19, R20 and R21, pins RX0 (physical pin – 12) and TX0 (physical pin – 13)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 26 [70]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                                     !!\n"
"!!  NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5V tolerant. You will Damage the ESP32 if you connect 5V to any of its pins (only exception is the Vin pin) !!\n"
"!!                                                                                                                                                                                     !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 26 out of 28\n"
" UART0 5V Port Pin Test        Next Test: Current Monitor Input Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow you're ESP32 if you're not careful connecting to the correct pins  !!!! \n" 
"   - Disconnect the wire jumper( both ends), reconnect one end to the four pin header JP16 (has labels - Gnd, 3V, Tx, Rx) to pin labeled Tx.\n"   
"   - Using a 4K7 resistor put in the open end of the wire jumper, take a second jumper wire and connect to the other end of the 4k7 resistor.\n" 
"   - This test automatically counts from 1 to 10 then print an X.\n"
"   - During the 1 to 10 count (not before 1 or after 10), connect the free end of the second jumper wire to the four-pin header JP16 (has labels - Gnd, 3V, Tx, Rx) to pin labeled Rx.\n"
"   - Enter \"C\" to start test.\n",
//
//Test 26 continued [71]
"\n"
"\n"
"\n"  
"Test 26 out of 28\n"
" UART0 5V Port Pin Test        Next Test: Current Monitor Input Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will display either error or worked, if worked disconnect the wire jumper ( both ends) and push \"C\" \n"
"\n"
"   - If error it's not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to the four-pin header JP16 (has labels - Gnd, 3V, Tx, Rx) to pin labeled Rx.\n"   
"   --- check the other end is connected to the same four pin header JP16 to pin labeled Tx,\n"
"   --- make sure Transistor Q5 and Q6 are soldered in the correct orientation\n"
"   --- check solder joints on four pin header J15, Transistor Q5 and Q6, Resistor R18, R19, R20 and R21, pins RX0 (physical pin – 12) and TX0 (physical pin – 13)\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 27 [72]

"\n"  
"Test 27 out of 28\n"
" Current Monitor Input Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Put jumper on Two pin header JP1 (labeled - IMon), then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display a value between 1900 and 2000, if it is working.\n",
"\n"
//
//Test 27 continued [73]
"\n"  
"Test 27 out of 28\n"
" Current Monitor Input Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed a value between 1900 and 2020, if it worked, push \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check wire jumper is connected correctly to the two-pin header JP1\n"   
"   --- check solder joints on two-pin header JP1, on all 8 pins of IC U3 \n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//Test 27 [74]

"\n"  
"Test 27 out of 28\n"
" Current Monitor Input Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - leave jumper on two pin header JP1 (labeled - IMon)\n"
"   - disassemble one of the off-white plastic cases with the metal geared motors in it.\n"
"   - Clean the terminals at the motor to remove any of the silicon glue around the solder terminals.\n"
"   - Take two receptacles  to pin jumper wires:\n"
"       - cut off pin end (right after black plastic)\n"
"       - strip ( ~3 mm) if the insulation\n"
"       - tin and solder to motor terminals\n"
"       - trim excess soldered wire\n"
"   - plug this motor in the Digital i/o three-pin header (closest to the push button end of board\n"
"   - one motor lead goes to the ground pin (closest to edge of board) and the other motor lead is connected to middle pin ( +5V pin)\n"   
"   - Plug Battery into underside of board on USB connector (ONLY DO THIS IF YOU TESTED AND PASSED battery connection without ESP32 installed, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display a value between greater than 2020, (you might need to provide a load on the motor with your fingers to register current change).\n",
"\n"
//
//Test 27 continued [75]
"\n"  
"Test 27 out of 28\n"
" Current Monitor Input Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed a value greater than 2020, if it worked, push \"C\" \n"
"   - If not working: unplug ESP32 from power sources (Battery and USB). \n"
"   --- was the motor turning? If not check soldered leads on motor and solder leads on three pin header.\n"
"   --- check wire jumper is connected correctly to the two-pin header JP1\n"   
"   --- check solder joints on two-pin header JP1, on all 8 pins of IC U3 \n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Test 28 [76]

"\n"  
"Test 28 out of 28\n"
" Encoder Board Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Remove Battery for this test\n"
"   - Make sure you have done a short test on the encoder board before plugging into the MSE-Duino board.\n"
"   - Take 4 receptacle to receptacle jumper wires and plug them into the 4-pin header on the encoder board.\n"
"   - The wire connected to the G pin on the endocder board, connect the other end to J8 (3-pin headers in 3 Volt Digital area) ground pin (pin closest to edge of board)\n"
"   - The wire connected to the + pin on the endocder board, connect the other end to J8 (3-pin headers in 3 Volt Digital area) 3 V pin (middle pin)\n"
"   - The wire connected to the A pin on the endocder board, connect the other end to J8 (3-pin headers in 3 Volt Digital area) signal pin (pin closet to the ESP32)\n"
"   - The wire connected to the B pin on the endocder board, connect the other end to J9 (3-pin headers in 3 Volt Digital area) signal pin (pin closet to the ESP32)\n"
"   - Place the encoder magnetic strips (they were taped to the plastic) on a flat surface close to the encoder board.  (you can also use a flat fridge magnet for this test)\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display a string of PH1 and PH2 high/low as you slooooowly move the encoder's hall sensor (small black four-legged chip) flat down the length \n"
"             of one of the magnetic strips. If you don't get a reading try the other side of the sensor\n",
"\n"
//
//Test 28 continued [78]
"\n"  
"Test 28 out of 28\n"
" Encoder Board Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed PH1 and PH2 high/low,Ther should be both high and low for both PH1 and PH2 if it worked, you can test the second \n"
"      encoder board by entering a \"B\" or to end enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources (USB). \n"
"   --- check wire jumper were wire correctly:\n"   
"          - The wire connected to the G pin on the encoder board, connect the other end to J8 (3-pin headers in 3 Volt Digital area) ground pin (pin closest to edge of board)\n"
"          - The wire connected to the + pin on the encoder board, connect the other end to J8 (3-pin headers in 3 Volt Digital area) 3 V pin (middle pin)\n"
"          - The wire connected to the A pin on the encoder board, connect the other end to J8 (3-pin headers in 3 Volt Digital area) signal pin (pin closet to the ESP32)\n"
"          - The wire connected to the B pin on the encoder board, connect the other end to J9 (3-pin headers in 3 Volt Digital area) signal pin (pin closet to the ESP32)\n"
"   --- check solder joints on encoder board.\n"
"   --- Use multimeter to check continuity (beep test), to ground, to 3V3, to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//End [79]

"\n"
" Congratulations! You have finished the testing.\n"
" If you didn't stop to repair on the way, hopefully you wrote down where the faults were so you can repair and test again\n"
" Enter \"Q\"uit\n" 
"\n"
" Happy Robot Building \n"
"\n"

};



#endif
