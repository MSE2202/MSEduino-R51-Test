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
"Test 1 out of 30\n"
" SMART LEDs Test         Next Test: Push Button 1 Test\n"
"Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-11 to ON, then enter \"C\" \n",
//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 1 continued  [2]
"\n"  
"Test 1 out of 30\n"
" SMART LEDs Test         Next Test: Push Button 1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - SMART LED1 (look for label on board) should change colours, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that DIP Switch S1-11 is toggled correctly to ON \n"
"   --- Check the LED power/ground pins and Din/Dout on LED for soldering or shorts\n"
"   --- Check the solder joints on S1-11, GPIO21 (physical pin 23), and SMART LED1\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n"
"   --- Use an oscilloscope to check signal coming from pin 23; look at SK2812 data sheet for signal specs\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 2 [3]
"\n"  
"Test 2 out of 30\n"
" Push Button 1 Test         Next Test: DIP Switch S1-5 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions: \n"
"   - Slide DIP Switch S1-11 to off then enter \"C\" \n",
//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 2 continued  [4]
"\n"  
"Test 2 out of 30\n"
" Push Button 1 Test         Next Test: DIP Switch S1-5 Test Test\n"
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
"Test 3 out of 30\n"
" DIP Switch S1-5 Test         Next Test: DIP Switch S1-6 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-5 to off then enter \"C\" \n",
//
//Test 3 continued [6]
"\n"  
"Test 5 out of 30\n"
" DIP Switch S1-5 Test         Next Test: DIP Switch S1-6 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on DIP Switch S1-5 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check the solder joints on the three pin header J3, (physical pin 15), Resistor 3 and DIP Switch S1-5\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 4 [7]
"\n"  
"Test 4 out of 30\n"
" DIP Switch S1-6 Test         Next Test: Potentiometer R1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-5 and S1-6 to off then enter \"C\" \n",
//
//Test 4 continued [8]
"\n"  
"Test 4 out of 30\n"
" DIP Switch S1-6 Test         Next Test: Potentiometer R1 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on DIP Switch S1-6 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check the solder joints on the three pin header J46, (physical pin 16), Resistor 10 and DIP Switch S1-6\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 5 [9]
"\n"  
"Test 5 out of 30\n"
" Potentiometer R1 Test        Next Test: Analog Input AD1-3 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-6 to off and DIP Switch S1-12 to on, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 5 continued [10]
"\n"  
"Test 5 out of 30\n"
" Potentiometer R1 Test        Next Test: Analog Input AD1-3 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed Potentiometer R1 values as you adjust the potentiometer, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that DIP Switch S1-12 is on\n"
"   --- Check the solder joints on the three pin header J39, AD1-0 (physical pin 39), Resistor 9 and Potentiometer R1\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 6 [11]
"\n"  
"Test 6 out of 30\n"
" Analog Input AD1-3 Test        Next Test: Analog Input AD1-4 Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave DIP Switch S1-12 on\n"
"   - Take one of your supplied receptacle to receptacle wires and put one end on the three pin header J1 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J4 pin closest to the inside of board, then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"             The Serial Monitor will display Potentiometer R1 values as you adjust the potentiometer.\n",
//
//Test 6 continued [12]
"\n"  
"Test 6 out of 30\n"
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
"Test 7 out of 30\n"
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
"Test 7 out of 30\n"
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
"Test 8 out of 30\n"
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
"Test 8 out of 30\n"
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
"Test 9 out of 30\n"
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
"Test 9 out of 30\n"
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
"Test 10 out of 30\n"
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
"Test 10 out of 30\n"
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
"Test 11 out of 30\n"
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
"Test 11 out of 30\n"
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
"Test 12 out of 30\n"
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
"Test 12 out of 30\n"
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
"Test 13 out of 30\n"
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
"Test 13 out of 30\n"
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
"Test 14 out of 30\n"
" Digital Input GPIO45 Test        Next Test: Digital Input GPIO43\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-12 to off and remove jumper wire\n"
"   - Take the receptacle to receptacle wire and put one end on the three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header J45 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 14 continued [28]
"\n"  
"Test 14 out of 30\n"
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
"Test 15 out of 30\n"
" Digital Input GPIO43 Test        Next Test: Digital Input GPIO44\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the receptacle to receptacle wire on the three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header Jp2 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 15 continued [30]
"\n"  
"Test 15 out of 30\n"
" Digital Input GPIO43 Test        Next Test: Digital Input GPIO44\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header JP2 pin closest to the inside of board\n"
"   --- Check the solder joints on the three pin header JP2, GPIO43 (physical pin 37)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 16 [31]
"\n"  
"Test 16 out of 30\n"
" Digital Input GPIO44 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switch S1-12 to off and remove jumper wire\n"
"   - Leave the receptacle to receptacle wire on three pin header J4 pin closest to the inside of board\n"
"   - Connect the other end to the three pin header JP2 pin in the middle of the header, then enter \"C\" \n",
//
//Test 16 continued [32]
"\n"  
"Test 16 out of 30\n"
" Digital Input GPIO44 Test        Next Test: I2C 3V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button PB1 change of state, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to three the pin header J4 pin closest inside of board\n"
"   --- Check that the other end is connected to the three pin header JP2 pin in the middle of the header\n"
"   --- Check the solder joints on the three pin header JP2, GPIO44 (physical pin 36)\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 17 [33]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                          !!\n"
"!!     NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5 V tolerant.                                                                                 !!\n"
"!!     You will DAMAGE the ESP32 if you connect 5 V to any of its pins (the only exception is the Vin pin)                                                                  !!\n"
"!!                                                                                                                                                                          !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 17 out of 30\n"
" I2C 3V Port Pin SDA Test        Next Test: I2C 3V Port Pin CLK\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow your ESP32 if you are not careful connecting to the correct pins!!!! \n" 
"   - Leave the wire jumper on the three pin header J4 pin closest to the inside of board connected\n"
"   - Move the other end to three pin header J47 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 17 continued [34]
"\n"  
"Test 17 out of 30\n"
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
//Test 18 [35]
"\n"  
"Test 18 out of 30\n"
" I2C 3V Port Pin CLK Test        Next Test: I2C 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Leave the wire jumper on the one end of the three pin header J4 pin closest to the inside of board\n"   
"   - Move the other end to three pin header J48 pin closest to the inside of board, then enter \"C\" \n",
//
//Test 18 continued [36]
"\n"  
"Test 18 out of 30\n"
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
//Test 19 [37]
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"!!                                                                                                                                                                          !!\n"
"!!     NOTE: Care must be taken when testing and using the ESP32 as IT IS NOT 5 V tolerant.                                                                                 !!\n"
"!!     You will DAMAGE the ESP32 if you connect 5 V to any of its pins (the only exception is the Vin pin)                                                                  !!\n"
"!!                                                                                                                                                                          !!\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
"\n"  
"Test 19 out of 30\n"
" I2C DA 5V Port Pin Test        Next Test: I2C CLK 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow you're ESP32 if your not careful connecting to the correct pins  !!!! \n" 
"   - Leave the wire jumper on the one end of the three pin header J4 pin closest to the inside of board\n"  
"   - Move the wire jumper from three pin header J48 to the four pin header JP1. Connect to pin closest to inside to board, Labeled DA\n"
"   - then enter \"C\" \n",
//
//Test 19 continued [38]
"\n"  
"Test 19 out of 30\n"
" I2C DA 5V Port Pin Test        Next Test: I2C CLK 5V Port Pin Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when Push Button 1 (PB1) is pressed, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to one end of the three pin header J4 pin closest to the inside of board\n"
"   --- Check that the other end is connected to four pin header JP1. Connect to pin closest to inside to board, Labeled DA\n"
"   --- Make sure that Transistor Q1 is soldered in the correct orientation\n"
"   --- Check the solder joints on the four pin header JP1, Transistor Q1, and Resistor R14\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 20 [39]
"\n"  
"Test 20 out of 30\n"
" I2C CLK 5V Port Pin Test        Next Test: Motor Pin test GPIO35\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"  !!! This is where you might blow you're ESP32 if your not careful connecting to the correct pins  !!!! \n" 
"   - Leave the wire jumper on the one end of the three pin header J4 pin closest to the inside of board\n"  
"   - Move the wire jumper from four pin header JP1 connect to pin closest to inside to board to the same\n"
"     four pin header JP1 pin down one from the pin closest to the inside of board, Labeled CLK\n"
"   - then enter \"C\" \n",
//
//Test 20 continued [40]
"\n"  
"Test 20 out of 30\n"
" I2C CLK 5V Port Pin Test        Next Test: Motor Pin test GPIO35\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update when wire jumper is removed from ground pin and replaced on ground pin, if working enter \"C\" \n"
"   - If not working, unplug the MSE-Duino from power sources (USB) and \n"
"   --- Check that the wire jumper is connected correctly to one end of the three pin header J4 pin closest to the inside of board\n"
"   --- Check that the other end is connected to four pin header JP1, one pin down from the pin closest to the inside of board, Labeled CLK\n"
"   --- Make sure that Transistor Q2 is soldered in the correct orientation\n"
"   --- Check the solder joints on the four pin header JP1, Transistor Q2, and Resistor R12\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 21 [41]
"\n"  
"Test 21 out of 30\n"
" Motor 1 A test GPIO35        Next Test: Motor 1 B test GPIO36\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Remove the receptacle to receptacle wire \n"
"   - Plug one of your small blue RC servos into the three pin header J35, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest\n"
"     to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 21 continued [42]
"\n"  
"Test 21 out of 30\n"
" Motor 1 A test GPIO35        Next Test: Motor 1 B test GPIO36\n"
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
//Test 22 [43]
"\n"  
"Test 22 out of 30\n"
" Motor 1 B test GPIO36        Next Test: Motor 2 A test GPIO37\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J36, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 22 continued [44]
"\n"  
"Test 22 out of 30\n"
" Motor 1 B test GPIO36        Next Test: Motor 2 A test GPIO37\n"
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
//Test 23 [45]
"\n"  
"Test 23 out of 30\n"
" Motor 2 A test GPIO37        Next Test: Motor 2 B test GPIO38\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J37, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 23 continued [46]
"\n"  
"Test 23 out of 30\n"
" Motor 2 A test GPIO37        Next Test: Motor 2 B test GPIO38\n"
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
//Test 24 [47]
"\n"  
"Test 24 out of 30\n"
" Motor 2 B test GPIO38        Next Test: Stepper DIR Pin test GPIO39\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J38, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 24 continued [48]
"\n"  
"Test 24 out of 30\n"
" Motor 2 B test GPIO38        Next Test: Stepper DIR Pin test GPIO39\n"
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
//Test 25 [49]
"\n"  
"Test 25 out of 30\n"
" Stepper DIR Pin test GPIO39        Next Test: Stepper CLK Pin test GPIO40\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J39, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 25 continued [50]
"\n"  
"Test 25 out of 30\n"
" Stepper DIR Pin test GPIO39        Next Test: Stepper CLK Pin test GPIO40\n"
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
//Test 26 [51]
"\n"  
"Test 26 out of 30\n"
" Stepper CLK Pin test GPIO40        Next Test: Servo 1 test GPIO41\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J40, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 26 continued [52]
"\n"  
"Test 26 out of 30\n"
" Stepper CLK Pin test GPIO40        Next Test: Servo 1 test GPIO41\n"
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
//Test 27 [53]
"\n"  
"Test 27 out of 30\n"
" Servo 1 test GPIO41       Next Test: Servo 2 test GPIO42\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J41, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 27 continued [54]
"\n"  
"Test 27 out of 30\n"
" Servo 1 test GPIO41       Next Test: Servo 2 test GPIO42\n"
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
//Test 28 [55]
"\n"  
"Test 28 out of 30\n"
" Servo 2 test GPIO42       Next Test: Left Encoder Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Move the RC servo to the three pin header J42, with the brown wire connected to the pin at edge of board and the orange wire to the pin closest to the inside of board\n"
"   - then enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 28 continued [56]
"\n"  
"Test 28 out of 30\n"
" Servo 2 test GPIO42       Next Test: Left Encoder Test\n"
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
//Test 29 [57]
"\n"  
"Test 29 out of 30\n"
" Left Encoder Test               Next Test: Right Encoder Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switches S1-1, S1-2, S1-3, S1-4 to ON position\n"
"   - Turn over the MSE-Duino board\n"
"   - Hold one of the encoder magnetic strips by one end (you can also use a flat fridge magnet for this test)\n"
"   - The Serial Monitor should display A, B, DIR, and SPD as you slowly drag the black part of the encoder magnetic strip across IC U1\n"
"     The direction to drag the strip is from one short end towards the other short end of the circuit board, if working enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n",
//
//Test 29 continued [58]
"\n"  
"Test 29 out of 30\n"
" Left Encoder Test               Next Test: Right Encoder Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed A, B, DIR, and SPD as you slowly dragged the black part of the encoder magnetic strip across IC U1\n"
"     The direction to drag the strip is from one short end towards the other short end of the circuit board (parallel to the long edge of the board)\n"
"     If working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources (USB) and \n"
"   --- Check that the DIP Switches S1-1, S1-2, S1-3, abd S1-4 are in the ON position\n"   
"   --- Check the solder joints of U1, DIP Switches S1-1, S1-2, S1-3, S1-4, and pins 8, 9, 10, and 11 of the ESP32.\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Test 30 [59]
"\n"  
"Test 30 out of 30       \n"
" Right Encoder Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"\n"
" Instructions:\n"
"   - Slide DIP Switches S1-1, S1-2, S1-3, and S1-4 to OFF position\n"
"   - Slide DIP Switches S1-7, S1-8, S1-9, and S1-10 to ON position\n"
"   - Turn over the MSE-Duino board\n"
"   - Hold one of the encoder magnetic strips by one end (you can also use a flat fridge magnet for this test)\n"
"   - The Serial Monitor should display A, B, DIR, and SPD as you slowly drag the black part of the encoder magnetic strip across IC U2\n"
"     The direction to drag the strip is from one short end towards the other short end of the circuit board, if working enter \"C\" \n"
"       NOTE: Once you are finished with this test you will need to enter \"C\" to stop the scrolling data.\n"
"\n",
//
//Test 30 continued [60]
"\n"  
"Test 30 out of 30\n"
" Right Encoder Test\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor should have displayed A, B, DIR, and SPD as you slowly dragged the black part of the encoder magnetic strip across IC U2\n"
"     The direction to drag the strip is from one short end towards the other short end of the circuit board (parallel to the long edge of the board)\n"
"     If working enter \"C\" \n"
"   - If not working: unplug ESP32 from power sources (USB) and \n"
"   --- Check that the DIP Switches S1-7, S1-8, S1-9, abd S1-10 are in the ON position\n"   
"   --- Check the solder joints of U2, DIP Switches S1-7, S1-8, S1-9, S1-10, and pins 19, 20, 21, and 22 of the ESP32.\n"
"   --- Use a multimeter to check continuity (beep test), to ground, to 3V3, and to points along the circuit path (use the schematic and board artwork as reference)\n",   

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//End [61]
"\n"
" Congratulations! You have finished the testing of your MSE-Duino.\n"
" If any of the tests failed and you didn't stop to repair along the way, hopefully you wrote down where the faults were so you that can repair and test again.\n"
" Enter \"Q\"uit\n" 
"\n"
" Happy Robot Building!! \n"
"\n"

};

#endif
