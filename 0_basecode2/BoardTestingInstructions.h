
/*
//Western Engineering base code 
Oct 10,2020
  
\Board Testing Instructions



*/

#ifndef BOARDTESTINGINSTRUCTIONS_H
#define BOARDTESTINGINSTRUCTIONS_H 1





const static char *BoardTesting_Instructions[] PROGMEM = 
{
//Test 1  [0]
" Board Testing \n"
"First Test: Blink on ESP32 LED\n"
"Enter \"C\"ontinue, \"S\"kip this test or \"Q\"uit \n",
//
//Test 1 continued  [1]
" Blink on ESP32 LED, Test 1/5 \n" 
"Enter \"C\"ontinue to next test,\"B\"ack to go beginning of Test, \"S\"kip to the next Test or \"Q\"uit \n"
"   - Blue LED on ESP32 board should be blinking, If working push \"C\' \n"
"   - If not working: unplug ESP32 from power sources. \n"
"      --- Use multimeter to check continuity ( beep test), to ground, to 3V3, on physical pin 4,  if beep find short and fix. (use the schematic and board artwork as reference \n"
"\n"
"Next Test 2/5: SMART LEDs Test",
//
//Test 2 [2]
" SMART LEDs Test, Test 2/5 \n"
"Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
"Next Test 3/5: Push Button Test\n"
"\n"
" Instructions:\n"
"   - Put jumper on JP5, then push \"C\" \n",
//
//Test 2 continued  [3]
" SMART LEDs Test, Test 2/5\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
" Next Test 3/5: Push Button Test\n"
"\n"
" Instructions:\n"
"   - SMART LED1 (look for label on board) should change colours, then SMART LED2should change colours,  then back to LED1, if working push \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check  jumper is connected correctly to JP5\n"
"   --- did only one light? If yes then the connections from ESP32 to SMART LEDS is good, check LED power/ground pins and Din/Dout on LED not working\n"
"   --- check  solder joints on JP5, D25 (physical pin – 23) and SMART LED1/LED2 \n"
"   --- Use multimeter to check continuity ( beep test), to ground, to 3V3, to points along the circuit path( use the schematic and board artwork as reference \n"
"   --- Use oscilloscope to check signal coming from pin 25 , look at SK2812 data sheet for  signal specs.\n",
//
//Test 3 [4]
" Push Button 1 Test, Test 3/5\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
" Next Test 4/5: Push Button 2 Test\n"
"\n"
" Instructions: \n"
"   - Put jumper on JP13, then push \"C\" \n",
//
//Test 3 continued  [5]
" Push Button 1 Test, Test 3/5\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip to the next Test or \"Q\"uit\n" 
" Next Test 4/5: Push Button 2 Test\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button's 1 change of state,, if working push \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check  jumper is connected correctly to JP13\n"
"   --- check  solder joints on JP13, D27 (physical pin – 25), Resistor 14 and Push Button 1\n"
"   --- Use multimeter to check continuity ( beep test), to ground, to 3V3, to points along the circuit path( use the schematic and board artwork as reference \n",
//
//Test 4 [6]
" Push Button 2 Test, Test 4/5\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of last Test, \"S\"kip to the next Test or \"Q\"uit\n" 
" Next Test 5/5: Slide Switch 1 Test\n"
"\n"
" Instructions:\n"
"   - Put jumper on JP14, then push \"C\" \n",
//
//Test 4 continued [7]
" Push Button 2 Test, Test 4/5\n"
" Enter \"C\"ontinue to next instruction,\"B\"ack to go beginning of this Test, \"S\"kip Next Test or \"Q\"uit\n"
" Next Test 4/5: Push Button 2 Test\n"
"\n"
" Instructions:\n"
"   - The Serial Monitor will update on Push Button's 2 change of state,, if working push \"C\" \n"
"   - If not working: unplug ESP32 from power sources. \n"
"   --- check  jumper is connected correctly to JP14\n"
"   --- check  solder joints on JP14, D26 (physical pin – 24), Resistor 14 and Push Button 2\n"
"   --- Use multimeter to check continuity ( beep test), to ground, to 3V3, to points along the circuit path( use the schematic and board artwork as reference \n"


};



#endif
