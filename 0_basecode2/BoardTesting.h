/*
//Western Engineering base code 
Oct 10,2020
  
\Board Testing code

Usage either through serial Monitor or WEB PAGE 192.168.128.1

*/

#ifndef BOARDTESTING_H
#define BOARDTESTING_H 1

#include <Adafruit_NeoPixel.h>
#include "BoardTestingInstructions.h"


//pins
#define BRDTST_INDICATORLED 2     //pin 2 has a LED connected on ESP32 Board

#define BRDTST_PB1 27             //when JP13 has jumper installed pin D27 i sconnected to push Buttton 1
#define BRDTST_PB2 26             //when JP14 has jumper installed pin D26 i sconnected to push Buttton 2
#define BRDTST_LED_PIN     25     //when JP5 has jumper installed pin D25 is connected to SMART LEDs

#define BRSTST_LED_COUNT 2       //number of SMART LEDs in use



// Declare our SK6812 SMART LED object:
Adafruit_NeoPixel SmartLEDs(BRSTST_LED_COUNT, BRDTST_LED_PIN, NEO_GRB + NEO_KHZ400);
// Argument 1 = Number of LEDs (pixels) in use
// Argument 2 = ESP32 pin number 
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)



//Variables
boolean   brdtst_BoardTestingActive = true;
unsigned char brdtst_LEDBrightness = 25;
unsigned char brstst_ucMaxNumberofTestSteps = 10;
unsigned char brstst_ucMaxNumberofTests = 15;
unsigned char brdtst_ucIncrementTestStep = 0;
unsigned char brdtst_ucTestID = 0;

unsigned char brdtst_TempLoopVariable = 0;
unsigned char brdtst_TempLoopVariable2 = 0;

unsigned int brdtst_uiTimeCount;


void Testing()
{

 while (Serial.available() > 0)
 {

     switch(Serial.read())
     {
      case 'C':
      case 'c':
      {
        if(brdtst_ucIncrementTestStep < brstst_ucMaxNumberofTestSteps)
        {
          brdtst_ucIncrementTestStep = brdtst_ucIncrementTestStep + 1;
        }
        else
        {
          brdtst_ucTestID = brdtst_ucTestID + 1;
          if(brdtst_ucTestID > brstst_ucMaxNumberofTests)
          {
            brdtst_ucTestID = brstst_ucMaxNumberofTests;
          }
          brdtst_ucIncrementTestStep = 0;
        }
        
        break;
      }
      case 'B':
      case 'b':
      {
        if(brdtst_ucIncrementTestStep != brstst_ucMaxNumberofTestSteps)
        {
          brdtst_ucIncrementTestStep = 0;
          if(brdtst_ucTestID > 0)
          {
            brdtst_ucTestID = brdtst_ucTestID - 1;
          }
        }
        else
        {
          brdtst_ucIncrementTestStep = 0;
        }
        
        break;
      }
      case 'S':
      case 's':
      {
        brdtst_ucIncrementTestStep = 0;
        brdtst_ucTestID = brdtst_ucTestID + 1;
        if(brdtst_ucTestID > brstst_ucMaxNumberofTests)
          {
            brdtst_ucTestID = brstst_ucMaxNumberofTests;
          }
        break;
      }
      case 'Q':
      case 'q':
      {
        brdtst_BoardTestingActive = false;
        brdtst_ucIncrementTestStep = 0;
        brdtst_ucTestID = 0;
        Serial.println(F("Quiting - Board Testing ( to restart reset esp32"));
        
        break;
      }
     }
   
 }
 
  
  WSVR_BreakPoint(2);
 switch((brdtst_ucTestID * 10) + brdtst_ucIncrementTestStep)
 {
  case 0: //setup for board testing
  {
     SmartLEDs.clear(); // Set all pixel colors to 'off'
     SmartLEDs.show();   // Send the updated pixel colors to the hardware.
     brstst_ucMaxNumberofTestSteps = 3;
     
     Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
     Serial.printf("%s",BoardTesting_Instructions[0]);
     Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
     //ESP32 Blink Test
     pinMode(BRDTST_INDICATORLED, OUTPUT);
    
     
     brdtst_ucIncrementTestStep = 1;
    break;
  }
  case 1:
  {
    //waiting for user input
    break;
  }
  case 2:  //display instructions
  {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[1]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    break;
  }  
  case 3:  //repeat test until user sends response
  {
    
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
    if(brdtst_uiTimeCount >= 25)
    {
      brdtst_uiTimeCount = 0;
      digitalWrite(BRDTST_INDICATORLED,!digitalRead(BRDTST_INDICATORLED));
    }
    break;
  }
  case 10:
  {
   digitalWrite(BRDTST_INDICATORLED,false);
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[2]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    //SMART LED Testing
     SmartLEDs.begin(); // INITIALIZE SMART LEDs object (REQUIRED)
     SmartLEDs.clear(); // Set all pixel colors to 'off'
     SmartLEDs.show();   // Send the updated pixel colors to the hardware.
     brdtst_ucIncrementTestStep = 1;
    break;
  }
  case 11:
  {
    // waiting for user input
    break;
  }
  case 12:
  {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[3]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiTimeCount = 0;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 13:
   {
     brstst_ucMaxNumberofTestSteps = 3;
     brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 50)
     {
        brdtst_uiTimeCount = 0;
        switch(brdtst_TempLoopVariable)
        {
          case 0:
          {
            // SmartLEDs.Color() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(brdtst_TempLoopVariable2,5,0,0);
            brdtst_TempLoopVariable = 1;
            break;
          }
          case 1:
          {
            // SmartLEDs.Color() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(brdtst_TempLoopVariable2,0,5,0);
            brdtst_TempLoopVariable = 2;
            break;
          }
          case 2:
          {
            // SmartLEDs.Color() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(brdtst_TempLoopVariable2,0,0,5);
            brdtst_TempLoopVariable = 3;
            break;
          }
          case 3:
          {
            // SmartLEDs.Color() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(brdtst_TempLoopVariable2,0,0,0);
            if(brdtst_TempLoopVariable2)
            {
              brdtst_TempLoopVariable2 = 0;
            }
            else
            {
              brdtst_TempLoopVariable2 = 1;
            }
            brdtst_TempLoopVariable = 0;
            break;
          }
        }
       
        SmartLEDs.show();   // Send the updated pixel colors to the hardware.
     } 
    break;
   }
   case 20:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    SmartLEDs.clear(); // Set all pixel colors to 'off'
    SmartLEDs.show();   // Send the updated pixel colors to the hardware.
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[4]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_PB1, INPUT_PULLUP); // set D27 as input and turn on pull up to use push button
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 21:
   {
    // waiting for user input
    break;
   }
   case 22:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[5]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 23:
   {
    if(digitalRead(BRDTST_PB1) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_PB1);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Push Button 1 released"));
      }
      else
      {
        Serial.println(F("Push Button 1 pressed"));
      }
    }
    break;
   }
   case 30:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    SmartLEDs.clear(); // Set all pixel colors to 'off'
    SmartLEDs.show();   // Send the updated pixel colors to the hardware.
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[6]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_PB2, INPUT_PULLUP); // set D26 as input and turn on pull up to use push button
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 31:
   {
    // waiting for user input
    break;
   }
   case 32:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[7]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 33:
   {
   
    if(digitalRead(BRDTST_PB2) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_PB2);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Push Button 2 released"));
      }
      else
      {
        Serial.println(F("Push Button 2 pressed"));
      }
    }
    break;
   }
   
 }

  
}









#endif
