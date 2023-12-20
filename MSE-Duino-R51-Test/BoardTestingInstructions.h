//
//  MSE-Duino V4.2 Board Testing Instructions
//  Update: Jan 2023
//


#ifndef BOARDTESTINGINSTRUCTIONS_H
#define BOARDTESTINGINSTRUCTIONS_H 1

const static char *BoardTesting_Instructions[] PROGMEM = 
{
//Test 1  [0]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                          !!\n"
"!!     NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5 V tolerant.                                                                                 !!\n"
"!!     You will DAMAGE the ESP32 if you connect 5 V to any of its pins (the only exception is the Vin pin)                                                                  !!\n"
"!!                                                                                                                                                                          !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"
" Board Testing \n"
" Perform these tests with only a USB cable, DO NOT connect battery unless otherwise noted\n"
" To start, slide all DIP Switches (S1) off (slide towards resistors)\n" 
" Enter \"C\"ontinue to next instruction\n",  
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 1 [1]
"\n"  
"Test 1 out of 36\n"
" SMART LEDs Test         Next Test: Push Button 1 Test\n"
"Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-4 to ON, then enter \"C\" \n",
//

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 1 continued  [2]
"\n"  
"Test 1 out of 36\n"
" SMART LEDs Test         Next Test: Push Button 1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - SMART LED1 (look for label on board) should change colours, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that DIP Switch S1-4 is toggled correctly to ON \n"
"   --- Check the LED power/ground pins and Din/Dout on LED for soldering or shorts\n"
"   --- Check the solder joints on S1-4, GPIO21 (physical pin 23), and SMART LED1\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n"
"   --- Use an oscilloscope to check signal coming from pin 23; look at SK2812 data sheet for signal specs\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 2 [3]
"\n"  
"Test 2 out of 36\n"
" Push Button 1 Test         Next Test: DIP Switch S1-1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions: \n"
"   - Slide DIP Switch S1-4 to off then enter \"C\" \n",
//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 2 continued  [4]
"\n"  
"Test 2 out of 36\n"
" Push Button 1 Test         Next Test: DIP Switch S1-1 Test Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button 1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check the solder joints on GPIO0 (physical pin 27) and Push Button 1\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 3 [5]
"\n"  
"Test 3 out of 36\n"
" DIP Switch S1-1 Test         Next Test: DIP Switch S1-2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-1 to off then enter \"C\" \n",
//
//Test 3 continued [6]
"\n"  
"Test 5 out of 36\n"
" DIP Switch S1-1 Test         Next Test: DIP Switch S1-2 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on DIP Switch S1-1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check the solder joints on the three pin header J3, (physical pin 15), Resistor 3 and DIP Switch S1-5\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 4 [7]
"\n"  
"Test 4 out of 36\n"
" DIP Switch S1-2 Test         Next Test: Potentiometer R1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-1 and S1-2 to off then enter \"C\" \n",
//
//Test 4 continued [8]
"\n"  
"Test 4 out of 36\n"
" DIP Switch S1-2 Test         Next Test: Potentiometer R1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on DIP Switch S1-2 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check the solder joints on the three pin header J46, (physical pin 16), Resistor 10 and DIP Switch S1-6\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 5 [9]
"\n"  
"Test 5 out of 36\n"
" Potentiometer R1 Test        Next Test: Analog Input AD1-3 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-2 to off and DIP Switch S1-3 to on, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 5 continued [10]
"\n"  
"Test 5 out of 36\n"
" Potentiometer R1 Test        Next Test: Analog Input AD1-3 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that DIP Switch S1-3 is on\n"
"   --- Check the solder joints on the three pin header J39, AD1-0 (physical pin 39), Resistor 9 and Potentiometer R1\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 6 [11]
"\n"  
"Test 6 out of 36\n"
" Analog Input AD1-3 Test        Next Test: Analog Input AD1-4 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave DIP Switch S1-3 on\n"
"   - Take one of your supplied receptacle to receptacle wires and put one end on the three pin header J1 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J4 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 6 continued [12]
"\n"  
"Test 6 out of 36\n"
" Analog Input AD1-3 Test        Next Test: Analog Input AD1-4 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J4 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J4, and AD1-3 (physical pin 4)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 7 [13]
"\n"  
"Test 7 out of 36\n"
" Analog Input AD1-4 Test        Next Test: Analog Input AD1-5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the three pin header J1 pin closest to the inside of board connected\n"
"   - Connect the other end to the three pin header J5 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 7 continued [14]
"\n"  
"Test 7 out of 36\n"
" Analog Input AD1-4 Test        Next Test: Analog Input AD1-5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J5 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J5, and AD1-4 (physical pin 5)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 8 [15]
"\n"  
"Test 8 out of 36\n"
" Analog Input AD1-5 Test        Next Test: Analog Input AD1-6 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the three pin header J1 pin closest to the inside of board connected\n"
"   - Connect the other end to the three pin header J6 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 8 continued [16]
"\n"  
"Test 8 out of 36\n"
" Analog Input AD1-5 Test        Next Test: Analog Input AD1-6 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J6 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J6, and AD1-5 (physical pin 6)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 9 [17]
"\n"  
"Test 9 out of 36\n"
" Analog Input AD1-6 Test        Next Test: Analog Input AD1-7 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on J1 pin closest to the inside of board connected\n"
"   - Connect the other end to J7 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 9 continued [18]
"\n"  
"Test 9 out of 36\n"
" Analog Input AD1-6 Test        Next Test: Analog Input AD1-7 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer,\n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J7 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J7, and AD1-6 (physical pin 7)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 10 [19]
"\n"  
"Test 10 out of 36\n"
" Analog Input AD1-7 Test        Next Test: Analog Input AD1-8 Tes\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the three pin header J1 pin closest to the inside of board connected\n"
"   - Connect the other end to the three pin header J8 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 10 continued [20]
"\n"  
"Test 10 out of 36\n"
" Analog Input AD1-7 Test        Next Test: Analog Input AD1-8 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer,\n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J8 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J8, and AD1-7 (physical pin 12)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 11 [21]
"\n"  
"Test 11 out of 36\n"
" Analog Input AD1-8 Test        Next Test: Analog Input AD1-9 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the three pin header J1 pin closest to the inside of board connected\n"
"   - Connect the other end to the three pin header J9 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 11 continued [22]
"\n"  
"Test 11 out of 36\n"
" Analog Input AD1-8 Test        Next Test: Analog Input AD1-9 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer,\n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J9 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J9, and AD1-8 (physical pin 17)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 12 [23]
"\n"  
"Test 12 out of 36\n"
" Analog Input AD1-9 Test        Next Test: Analog Input AD1-1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the three pin header J1 pin closest to the inside of board connected\n"
"   - Connect the other end to the three pin header J10 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 12 continued [24]
"\n"  
"Test 12 out of 36\n"
" Analog Input AD1-9 Test        Next Test: Analog Input AD1-1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer,\n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J10 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J10, and AD1-9 (physical pin 18)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 13 [25]
"\n"  
"Test 13 out of 36\n"
" Analog Input AD1-1 Test        Next Test: Digital Input GPIO45 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the three pin header J1 pin closest to the inside of board connected\n"
"   - Connect the other end to the three pin header J2 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 13 continued [26]
"\n"  
"Test 13 out of 36\n"
" Analog Input AD1-1 Test        Next Test: Digital Input GPIO45 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer,\n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J1 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J2 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J2, and AD1-1 (physical pin 38)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 14 [27]
"\n"  
"Test 14 out of 36\n"
" Digital Input GPIO45 Test        Next Test: Digital Input GPIO43\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-3 to off and remove jumper wire\n"
"   - Take the receptacle to receptacle wire and put one end on the three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J45 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 14 continued [28]
"\n"  
"Test 14 out of 36\n"
" Digital Input GPIO45 Test        Next Test: Digital Input GPIO43\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J45 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J45, GPIO45 (physical pin 26)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 15 [29]
"\n"  
"Test 15 out of 36\n"
" Digital Input GPIO43 Test        Next Test: Digital Input GPIO44\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on the three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J43 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 15 continued [30]
"\n"  
"Test 15 out of 36\n"
" Digital Input GPIO43 Test        Next Test: Digital Input GPIO44\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J43 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J43, GPIO43 (physical pin 37)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 16 [31]
"\n"  
"Test 16 out of 36\n"
" Digital Input GPIO44 Test        Next Test: Digital Input GPIO11\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J44 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 16 continued [32]
"\n"  
"Test 16 out of 36\n"
" Digital Input GPIO44 Test        Next Test: Digital Input GPIO11\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J44 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J44, GPIO44 (physical pin 36)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 17 [33]
"\n"  
"Test 17 out of 36\n"
" Digital Input GPIO11 Test        Next Test: Digital Input GPIO12\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J11 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 16 continued [34]
"\n"  
"Test 17 out of 36\n"
" Digital Input GPIO11 Test        Next Test: Digital Input GPIO12\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J11 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J11, GPIO11 (physical pin 19)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 18 [35]
"\n"  
"Test 18 out of 36\n"
" Digital Input GPIO12 Test        Next Test: Digital Input GPIO13\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J12 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 18 continued [36]
"\n"  
"Test 18 out of 36\n"
" Digital Input GPIO12 Test        Next Test: Digital Input GPIO13\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J12 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J12, GPIO12 (physical pin 20)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 19 [37]
"\n"  
"Test 19 out of 36\n"
" Digital Input GPIO13 Test        Next Test: Digital Input GPIO14\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J13 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 19 continued [38]
"\n"  
"Test 19 out of 36\n"
" Digital Input GPIO13 Test        Next Test: Digital Input GPIO14\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J13 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J13, GPIO13 (physical pin 21)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 20 [39]
"\n"  
"Test 20 out of 36\n"
" Digital Input GPIO14 Test        Next Test: Digital Input GPIO15\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J14 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 20 continued [40]
"\n"  
"Test 20 out of 36\n"
" Digital Input GPIO14 Test        Next Test: Digital Input GPIO15\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J14 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J14, GPIO14 (physical pin 22)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 21 [41]
"\n"  
"Test 21 out of 36\n"
" Digital Input GPIO15 Test        Next Test: Digital Input GPIO16\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J15 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 21 continued [42]
"\n"  
"Test 21 out of 36\n"
" Digital Input GPIO15 Test        Next Test: Digital Input GPIO16\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J15 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J15, GPIO15 (physical pin 8)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 22 [43]
"\n"  
"Test 22 out of 36\n"
" Digital Input GPIO16 Test        Next Test: Digital Input GPIO17\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J16 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 22 continued [44]
"\n"  
"Test 22 out of 36\n"
" Digital Input GPIO16 Test        Next Test: Digital Input GPIO17\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J16 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J16, GPIO16 (physical pin 9)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 23 [45]
"\n"  
"Test 23 out of 36\n"
" Digital Input GPIO17 Test        Next Test: Digital Input GPIO18\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J17 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 23 continued [46]
"\n"  
"Test 23 out of 36\n"
" Digital Input GPIO17 Test        Next Test: Digital Input GPIO18\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J17 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J17, GPIO17 (physical pin 10)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 24 [47]
"\n"  
"Test 24 out of 36\n"
" Digital Input GPIO18 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J18 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 24 continued [48]
"\n"  
"Test 24 out of 36\n"
" Digital Input GPIO18 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header J18 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J18, GPIO18 (physical pin 11)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 25 [49]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                          !!\n"
"!!     NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5 V tolerant.                                                                                 !!\n"
"!!     You will DAMAGE the ESP32 if you connect 5 V to any of its pins (the only exception is the Vin pin)                                                                  !!\n"
"!!                                                                                                                                                                          !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 25 out of 36\n"
" I2C 3V Port Pin SDA Test        Next Test: I2C 3V Port Pin CLK\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow your ESP32 if you are not careful connecting to the correct pins!!!! \n" 
"   - Leave the wire jumper on the three pin header J4 pin closest to the inside of board connected\n"
"   - Move the other end to three pin header J47 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 25 continued [50]
"\n"  
"Test 25 out of 36\n"
" I2C 3V Port Pin SDA Test        Next Test:I2C 3V Port Pin CLK\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when Push Button 1 (PB1) is pressed, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to one end of the three pin header J4 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J47 pin closest to the inside of board,\n"
"   --- Make sure that Transistor Q1 is soldered in the correct orientation\n"
"   --- Check the solder joints on the three pin header J47, Transistor Q1, Resistor R11, and I2C SDA (physical pin 24)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 26 [51]
"\n"  
"Test 26 out of 36\n"
" I2C 3V Port Pin CLK Test        Next Test: I2C 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the one end of the three pin header J4 pin closest to the inside of board\n"   
"   - Move the other end to three pin header J48 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 26 continued [52]
"\n"  
"Test 26 out of 36\n"
" I2C 3V Port Pin CLK Test        Next Test: I2C 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when Push Button 1 (PB1) is pressed, if working enter \"C\" \n"
"   --- Check that the wire jumper is connected correctly to one end of the three pin header J4 pin closest to the inside of board\n"
"   --- Check that the other end is connected to the three pin header J48 pin closest to the inside of board,\n"
"   --- Make sure that Transistor Q2 is soldered in the correct orientation\n"
"   --- Check the solder joints on the three pin header J48, Transistor Q2, Resistor R13, and I2C CLK (physical pin 25)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 27 [53]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                          !!\n"
"!!     NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5 V tolerant.                                                                                 !!\n"
"!!     You will DAMAGE the ESP32 if you connect 5 V to any of its pins (the only exception is the Vin pin)                                                                  !!\n"
"!!                                                                                                                                                                          !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 27 out of 36\n"
" I2C DA 5V Port Pin Test        Next Test: I2C CLK 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow you're ESP32 if your not careful connecting to the correct pins  !!!! \n" 
"   - Move the wire jumper from the one end of the three pin header J4 pin closest to the inside of board to the three pin jumper J47-5 pin closest to the inside of board\n"  
"   - Move the wire jumper from three pin header J48 to the three pin header J47-5, connect to pin on outside of board.\n"
"   - then enter \"C\" \n",
//
//Test 27 continued [54]
"\n"  
"Test 27 out of 36\n"
" I2C DA 5V Port Pin Test        Next Test: I2C CLK 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when wire jumper is removed from ground pin and replaced on ground pin (pin 47-5 outside), if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to outside pin of the three pin header J47-5.\n"
"   --- Check that the other end is connected to fhree pin header J47-5, connect to pin closest to inside to board.\n"
"   --- Make sure that Transistor Q1 is soldered in the correct orientation\n"
"   --- Check the solder joints on the three pin header J47-5, Transistor Q1, and Resistor R14\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 28 [55]
"\n"  
"Test 28 out of 36\n"
" I2C CLK 5V Port Pin Test        Next Test:Servo test GPIO35\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow you're ESP32 if your not careful connecting to the correct pins  !!!! \n" 
"   - Move the wire jumper from the one end of the three pin header J47-5 pin closest to the inside of board to the three pin jumper J48-5 pin closest to the inside of board\n"  
"   - Leave the wire jumper on three pin header J47-5 pin on outside of board.\n"
"   - then enter \"C\" \n",
//
//Test 28 continued [56]
"\n"  
"Test 28 out of 36\n"
" I2C CLK 5V Port Pin Test        Next Test: Servo test GPIO35\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when wire jumper is removed from ground pin and replaced on ground pin (pin 48-5 outside), if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to outside pin of the three pin header J48-5.\n"
"   --- Check that the other end is connected to fhree pin header J48-5, connect to pin closest to inside to board.\n"
"   --- Make sure that Transistor Q2 is soldered in the correct orientation\n"
"   --- Check the solder joints on the three pin header J48-5, Transistor Q2, and Resistor R12\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 29 [57]
"\n"  
"Test 29 out of 36\n"
" Servo test GPIO35        Next Test: Servo test GPIO36\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Remove the receptacle to receptacle wire \n"
"   - Plug one of your small blue RC servos into the three pin header J35, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"     to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 29 continued [58]
"\n"  
"Test 29 out of 36\n"
" Servo test GPIO35        Next Test: Servo test GPIO36\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J35, with the brown wire connected to the pin at edge of board and the orange wire to the pin\n"
"       closest to the inside of board\n"
"   --- Check the solder joints on the three pin header J35, and GPIO35 (physical pin 28)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 30 [59]
"\n"  
"Test 30 out of 36\n"
" Servo test GPIO36        Next Test: Servo test GPIO37\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J36, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 30 continued [60]
"\n"  
"Test 30 out of 36\n"
" Servo test GPIO36        Next Test: Servo test GPIO37\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J36, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"       to the inside of board\n"
"   --- Check the solder joints on the three pin header J36, and GPIO36 (physical pin 29)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 31 [61]
"\n"  
"Test 31 out of 36\n"
" Servo test GPIO37        Next Test: Servo test GPIO38\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J37, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 31 continued [62]
"\n"  
"Test 31 out of 36\n"
" Servo test GPIO37        Next Test: Servo test GPIO38\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J37, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"       to the inside of board\n"
"   --- Check the solder joints on the three pin header J37, and GPIO37 (physical pin 30)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 32 [63]
"\n"  
"Test 32 out of 36\n"
" Servo test GPIO38        Next Test: Servo test GPIO39\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J38, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 32 continued [64]
"\n"  
"Test 32 out of 36\n"
" Servo test GPIO38        Next Test: Servo test GPIO39\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J38, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"       to the inside of board\n"
"   --- Check the solder joints on the three pin header J38, and GPIO38 (physical pin 31)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 33 [65]
"\n"  
"Test 33 out of 36\n"
" Servo test GPIO39        Next Test: Servo test GPIO40\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J39, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 33 continued [66]
"\n"  
"Test 33 out of 36\n"
" Servo test GPIO39        Next Test: Servo test GPIO40\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J39, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"       to the inside of board\n"
"   --- Check the solder joints on the three pin header J39, and GPIO39 (physical pin 32)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 34 [67]
"\n"  
"Test 34 out of 36\n"
" Servo test GPIO40        Next Test: Servo test GPIO41\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J40, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 34 continued [68]
"\n"  
"Test 34 out of 36\n"
" Servo test GPIO40        Next Test: Servo test GPIO41\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J40, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"       to the inside of board\n"
"   --- Check the solder joints on the three pin header J40, and GPIO40 (physical pin 33)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 35 [69]
"\n"  
"Test 35 out of 36\n"
" Servo test GPIO41       Next Test: Servo test GPIO42\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J41, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 35 continued [70]
"\n"  
"Test 35 out of 36\n"
" Servo test GPIO41       Next Test: Servo test GPIO42\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J41, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"       to the inside of board\n"
"   --- Check the solder joints on the three pin header J41, and GPIO41 (physical pin 34)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 36 [71]
"\n"  
"Test 36 out of 36\n"
" Servo test GPIO42       Next Test: Encoder/Motor Controller A Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J42, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 36 continued [72]
"\n"  
"Test 36 out of 36\n"
" Servo test GPIO42       Next Test: Encoder/Motor Controller A Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the servo angle and the servo should swing forward then backwards, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the servo is properly connected to the three pin header J42, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"       to the inside of board\n"
"   --- Check the solder joints on the three pin header J42, and GPIO42 (physical pin 35)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 37 [73]
"\n"  
"Test 37 out of 36\n"
"Test: Encoder/Motor Controller A Test    Next Test: Encoder/Motor Controller B Test\n"  \n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Remove servo.\n"
"   - Plug Motor Controller Board into the two pin and 4 pins receptacle on the board (around the mounter hole)\n".
"   - Using one of the metal gear motors, plug the motor wires M1 and M2 into MOTOR_A header on Motor Control Board.\n"
"   - Plug the motor encoder wires into MSE-Duino board as per the following. Plug encoder wire C1 into header Jumper 11 top pin (closest to inside of board).\n"
"   - Plug the encoder VCC wire into the middle pin of Jumper 11 and encoder ground wire into the bottom (outside) pin Jumper 11.\n"
"   - Plug encoder C2 wire into top pin in Jumper 12 (closest to inside of board).\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//
//Test 37 continued [74]
"\n"  
"Test 37 out of 36\n"
"Test: Encoder/Motor Controller A Test     Next Test: Encoder/Motor Controller B Test\n"  \n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the Encode count and the motor should be spinning, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the Motor M1, M2 were connected to the MOTOR_A header on Motor Control Board.\n"
"   --- Check the solder joints on the motor  and encoder wires.\n"
"   --- Doulbe check the encoder was connedted correctly and to Jumper 11 and 12.\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, to 5V.(use the schematic and board artwork as reference)\n"
"   --- ",


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 38 [75]
"\n"  
"Test: Encoder/Motor Controller B Test\n"
" Right Motor Test       \n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the motor wires M1 and M2 to the MOTOR_B header on Motor Control Board.\n"
"   - Move encoder wire C1 on to header Jumper 15 top pin (closest to inside of board).\n"
"   - Move the encoder VCC wire to the middle pin of Jumper 15 and encoder ground wire into the bottom (outside) pin Jumper 15.\n"
"   - Move encoder C2 wire to top pin on Jumper 16 (closest to inside of board).\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 38 continued [76]
"\n"  
"Test 38 out of 36\n"
""Test: Encoder/Motor Controller B Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should display the Encode count and the motor should be spinning, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the Motor M1, M2 were connected to the MOTOR_B header on Motor Control Board.\n"
"   --- Check the solder joints on the motor  and encoder wires.\n"
"   --- Doulbe check the encoder was connedted correctly and to Jumper 15 and 16.\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, to 5V.(use the schematic and board artwork as reference)\n"
"   --- ",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//End [77]
"\n"
" Congratulations! You have finished the testing of your MSE-Duino.\n"
" If any of the tests failed and you didn't stop to repair along the way, hopefully you wrote down where the faults were so you that can repair and test again.\n"
" Enter \"Q\"uit\n" 
"\n"
" Happy Robot Building!! \n"
"\n"

};

#endif
