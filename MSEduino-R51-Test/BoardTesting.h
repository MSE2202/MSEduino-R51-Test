//
//  MSEduino V5.1 Board Testing Code
//  Update: Dec 2023
//


#ifndef BOARDTESTING_H
#define BOARDTESTING_H 1

#include <Adafruit_NeoPixel.h>
#include "BoardTestingInstructions.h"
#include <MSE2202_Lib.h>

//pins
#define BRDTST_GPIO4  4            //pin 4 not connected to other devices (J4); also is analog AD1-3
#define BRDTST_GPIO5  5            //pin 5 not connected to other devices (J5); also is analog AD1-4
#define BRDTST_GPIO6  6            //pin 6 not connected to other devices (J6); also is analog AD1-5
#define BRDTST_GPIO7  7            //pin 7 not connected to other devices (J7); also is analog AD1-6

#define BRDTST_GPIO15 15    
#define BRDTST_GPIO16 16    
#define BRDTST_GPIO17 17  
#define BRDTST_GPIO18 18  

#define BRDTST_GPIO8     8         //pin 12 not connected to other devices (J8); also is analog AD1-7

#define ESP32s3_USB_DM   19         //pin 13 use only for USB connection (GPIO19)
#define ESP32s3_USB_DP   20         //pin 14 use only for USB connection (GPIO20)

#define BRDTST_DIP_SW_S1_1 3     //DIP Switch S1-1 pulls Digital pin D3 to ground when ON; pin 15 GPIO3 (J3); When DIP Switch S1-1 is off can be used as analog AD1-2
#define BRDTST_DIP_SW_S1_2 46    //DIP Switch S1-2 pulls Digital pin D46 to ground when ON; pin 16 GPIO46 (J46)

#define BRDTST_GPIO9     9         //pin 17 not connected to other devices (J9); also is analog AD1-8
#define BRDTST_GPIO10    10        //pin 18 not connected to other devices (J10); also is analog AD1-9

#define BRDTST_GPIO11 11   
#define BRDTST_GPIO12 12    
#define BRDTST_GPIO13 13  
#define BRDTST_GPIO14 14  

#define BRDTST_SMART_LED     21     //when DIP Switch S1-4 is ON, Smart LED is connected to pin 23 GPIO21 (J21)

#define BRDTST_I2C_DA      47      //GPIO47 pin 24 I2C Data at (J47) (3V) and JP1 (5V)
#define BRDTST_I2C_CLK     48      //GPIO48 pin 25 I2C CLK at (J48) (3V) and JP1 (5V)

#define BRDTST_GPIO45    45        //GPIO45 (J45)pin 26 DO NOT TIE HIGH

#define BRDTST_PB1    0        //GPIO0 pin 27 Push Button 1

#define BRDTST_MOTOR_2_A 35    //GPIO35 pin 28 (J35) Motor 2 A
#define BRDTST_MOTOR_2_B 36    //GPIO36 pin 29 (J36) Motor 2 B
#define BRDTST_MOTOR_1_A 37    //GPIO37 pin 30 (J37) Motor 1 A
#define BRDTST_MOTOR_1_B 38    //GPIO38 pin 31 (J38) Motor 1 B

#define BRDTST_STEPPER_DIR 39    //GPIO39 pin 32 (J39) STEPPER Motor direction pin
#define BRDTST_STEPPER_CLK 40    //GPIO40 pin 33 (J40) stepper motor clock pin

#define BRDTST_SERVO_1 41    //GPIO41 pin 34 (J41) Servo 1
#define BRDTST_SERVO_2 42    //GPIO42 pin 35 (J42) Servo 2

#define BRDTST_RX 44        //GPIO44 pin 36 (JP2) SCI Rx in pin
#define BRDTST_GPIO43 43        //GPIO43 pin 37 (JP2) SCI Tx in pin
#define BRDTST_GPIO44 44        //GPIO44 pin 36 (JP2) SCI Rx in pin
#define BRDTST_TX 43        //GPIO43 pin 37 (JP2) SCI Tx in pin


#define BRDTST_GPIO2 2    //GPIO2 pin 38 not connected to other devices (J2); also is analog AD1-1

#define BRDTST_POT_R1  1  //when DIP Switch S1-3 is ON, Analog AD0 (pin 39, GPIO1 is connected to Poteniometer R1



#define BRDTST_LED_COUNT    1       //number of SMART LEDs in use


extern long GetPosition(int Which_Encoder);

// Declare our SK6812 SMART LED object:
Adafruit_NeoPixel SmartLEDs(BRDTST_LED_COUNT, BRDTST_SMART_LED, NEO_RGB + NEO_KHZ800);
// Argument 1 = Number of LEDs (pixels) in use
// Argument 2 = ESP32 pin number 
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)



//Variables
boolean brdtst_BoardTestingActive = true;
unsigned char brdtst_LEDBrightness = 25;
unsigned char brstst_ucMaxNumberofTestSteps = 10;
unsigned char brstst_ucMaxNumberofTests = 40;
unsigned char brdtst_ucIncrementTestStep = 0;
unsigned char brdtst_ucTestID = 0;

unsigned char brdtst_TempLoopVariable = 0;
unsigned char brdtst_TempLoopVariable2 = 0;

unsigned char brdtst_EncoderTest = 0;
unsigned char brdtst_EncoderTest2 = 0;

unsigned int brdtst_uiPCMTest;

unsigned int brdtst_uiTimeCount;
unsigned int brdtst_uiTestIndex;

signed int brdtst_iCounter;

Motion Bot = Motion(); 


void BRD_Testing()
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
        Serial.println(F("Quitting - Board Testing (to restart reset ESP32)"));
        
        break;
      }
      case 'X':
      {
        if((((brdtst_ucTestID * 10) + brdtst_ucIncrementTestStep) == 242) || (((brdtst_ucTestID * 10) + brdtst_ucIncrementTestStep) == 252))
        {
           brdtst_ucIncrementTestStep = 3;
           Serial.println(F("UART Pin test worked"));
        }
        
        break;
      }
     }
   
 }
 
 brdtst_uiTestIndex = (unsigned int)((brdtst_ucTestID * 10) + brdtst_ucIncrementTestStep);
 switch(brdtst_uiTestIndex)
 {
  case 0: //setup for board testing
  {
  
     SmartLEDs.begin(); // INITIALIZE SMART LEDs object (REQUIRED)
     SmartLEDs.clear();
     SmartLEDs.setPixelColor(0,SmartLEDs.Color(0,0,0));// Set pixel colors to 'off'
     SmartLEDs.show();   // Send the updated pixel colors to the hardware.
     brstst_ucMaxNumberofTestSteps = 1;
     
     Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
     Serial.printf("%s",BoardTesting_Instructions[0]);
     Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
     
    brdtst_ucIncrementTestStep = 1;
        
    break;
  }
 case 1:
  {
    //waiting for user input
   
    break;
  }
  // ***********************************************************************************************************************************************************************************************************************
  //Smart LEDs
  case 10:
  {
   //digitalWrite(BRDTST_INDICATORLED,false);
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[1]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    //SMART LED Testing
     //SmartLEDs.begin(); // INITIALIZE SMART LEDs object (REQUIRED)
     SmartLEDs.clear();
     SmartLEDs.setPixelColor(0,SmartLEDs.Color(0,0,0));// Set pixel colors to 'off'
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
    Serial.printf("%s",BoardTesting_Instructions[2]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiTimeCount = 0;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 13:
   {
     
     brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 500)
     {
        brdtst_uiTimeCount = 0;
        switch(brdtst_TempLoopVariable)
        {
          case 0:
          {
            
            // SmartLEDs.setPixelColor() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(0,SmartLEDs.Color(5,0,0));  // Red
            Serial.printf("red");
            Serial.println(F(" "));
            brdtst_TempLoopVariable = 1;
            break;
          }
          case 1:
          {
            
            // SmartLEDs.setPixelColor() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(0,SmartLEDs.Color(0,5,0));  // Green
            Serial.printf("grn");
            Serial.println(F(" "));
            brdtst_TempLoopVariable = 2;
            break;
          }
          case 2:
          {
            
            // SmartLEDs.setPixelColor() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(0,SmartLEDs.Color(0,0,5));  // Blue
            Serial.printf("blu");
            Serial.println(F(" "));
            brdtst_TempLoopVariable = 3;
            break;
          }
          case 3:
          {
            // SmartLEDs.setPixelColor() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(0,SmartLEDs.Color(10,10,10));  // White
            Serial.printf("wht");
            Serial.println(F(" "));
            brdtst_TempLoopVariable = 4;
            break;
          }
          case 4:
          {
            // SmartLEDs.set PixelColor() takes RGB values, from 0,0,0 up to 255,255,255
            SmartLEDs.setPixelColor(0,SmartLEDs.Color(0,0,0));
            Serial.printf("off");
            Serial.println(F(" "));
            brdtst_TempLoopVariable = 0;
            break;
          }
        }
       
        SmartLEDs.show();   // Send the updated pixel colors to the hardware.
     } 
    break;
   }

   // ***********************************************************************************************************************************************************************************************************************
   //push button 1 test
   case 20:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    SmartLEDs.begin(); // INITIALIZE SMART LEDs object (REQUIRED)
    SmartLEDs.clear();    
    SmartLEDs.setPixelColor(0,SmartLEDs.Color(0,0,0));// Set pixel colors to 'off'
    SmartLEDs.show();   // Send the updated pixel colors to the hardware.
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[3]);
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
    Serial.printf("%s",BoardTesting_Instructions[4]);
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
   
   
   // ***********************************************************************************************************************************************************************************************************************
   //DIP Switch S1-1 test
   case 30:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[5]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_DIP_SW_S1_1, INPUT_PULLUP); // set D3 as input
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
    Serial.printf("%s",BoardTesting_Instructions[6]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_DIP_SW_S1_1);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("DIP Switch S1-5 Off (Input High), switch to test"));
    }
    else
    {
      Serial.println(F("DIP Switch S1-1 ON (Input Low), switch to test"));
    }
    break;
   }
   case 33:
   {
   
    if(digitalRead(BRDTST_DIP_SW_S1_1) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_DIP_SW_S1_1);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("DIP Switch S1-1 Off (Input High)"));
      }
      else
      {
        Serial.println(F("DIP Switch S1-1 ON (Input Low)"));
      }
    }
    break;
   }
   
// ***********************************************************************************************************************************************************************************************************************
   //DIP Switch S1-6 test
   case 40:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[7]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_DIP_SW_S1_2, INPUT_PULLUP); // set D16 as input
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 41:
   {
    // waiting for user input
    break;
   }
   case 42:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[8]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_DIP_SW_S1_2);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("DIP Switch S1-2 Off (Input High), switch to test"));
    }
    else
    {
      Serial.println(F("DIP Switch S1-2 On (Input Low), switch to test"));
    }
    break;
   }
   case 43:
   {
   
    if(digitalRead(BRDTST_DIP_SW_S1_2) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_DIP_SW_S1_2);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("DIP Switch S1-2 Off (Input High)"));
      }
      else
      {
        Serial.println(F("DIP Switch S1-2 On (Input Low)"));
      }
    }
    break;
   }
 // ***********************************************************************************************************************************************************************************************************************
   //Potentiometer R1 Test
   case 50:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[9]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_POT_R1, INPUT); // set A4 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 51:
   {
    // waiting for user input
    break;
   }
   case 52:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Pot R1 = "));
        Serial.println(analogRead(BRDTST_POT_R1));
     }
    break;
   }      
   case 53:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[10]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 54:
   {
    // waiting for user input
    break;
   }
  
 // ***********************************************************************************************************************************************************************************************************************
  //Analog Input AD1-3  Test
   case 60:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[11]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO4, INPUT); // set A0 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 61:
   {
    // waiting for user input
    break;
   }
   case 62:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-3  = "));
        Serial.println(analogRead(BRDTST_GPIO4));
     }
    break;
   }     
   case 63:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[12]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 64:
   {
    // waiting for user input
    break;
   }
   // ***********************************************************************************************************************************************************************************************************************
   //Analog Input AD1-4  Test
   case 70:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[13]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO5, INPUT); // set AD1-4 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 71:
   {
    // waiting for user input
    break;
   }
    case 72:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-4  = "));
        Serial.println(analogRead(BRDTST_GPIO5));
     }
    break;
   } 
   case 73:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[14]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
  
   case 74:
   {
    // waiting for user input
    break;
   }     
   // ***********************************************************************************************************************************************************************************************************************
   //Analog Input AD1-5 Test
   case 80:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[15]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO6, INPUT); // set A6 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 81:
   {
    // waiting for user input
    break;
   }
   case 82:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-5  = "));
        Serial.println(analogRead(BRDTST_GPIO6));
     }
    break;
   }  
   case 83:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[16]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 84:
   {
    // waiting for user input
    break;
   }
       
   // ***********************************************************************************************************************************************************************************************************************
   //Analog Input AD1-6  Test
   case 90:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[17]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO7, INPUT); // set A5 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 91:
   {
    // waiting for user input
    break;
   }
    case 92:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-6  = "));
        Serial.println(analogRead(BRDTST_GPIO7));
     }
    break;
   }  
   case 93:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[18]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 94:
   {
    // waiting for user input
    break;
   }
   // ***********************************************************************************************************************************************************************************************************************
   //Analog Input AD1-7  Test
   case 100:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[19]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO8, INPUT); // set A5 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 101:
   {
    // waiting for user input
    break;
   }
    case 102:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-7  = "));
        Serial.println(analogRead(BRDTST_GPIO8));
     }
    break;
   }  
   case 103:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[20]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 104:
   {
    // waiting for user input
    break;
   }
      // ***********************************************************************************************************************************************************************************************************************
   //Analog Input AD1-8  Test
   case 110:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[21]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO9, INPUT); // set A5 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 111:
   {
    // waiting for user input
    break;
   }
    case 112:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-8  = "));
        Serial.println(analogRead(BRDTST_GPIO9));
     }
    break;
   }  
   case 113:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[22]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 114:
   {
    // waiting for user input
    break;
   }
    // ***********************************************************************************************************************************************************************************************************************
   //Analog Input AD1-9  Test
   case 120:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[23]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO10, INPUT); // set A5 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 121:
   {
    // waiting for user input
    break;
   }
    case 122:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-9  = "));
        Serial.println(analogRead(BRDTST_GPIO10));
     }
    break;
   }  
   case 123:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[24]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 124:
   {
    // waiting for user input
    break;
   }
    // ***********************************************************************************************************************************************************************************************************************
   //Analog Input AD1-1  Test
   case 130:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[25]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO2, INPUT); // set A5 as input, not strickly needed but what the
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 131:
   {
    // waiting for user input
    break;
   }
    case 132:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Analog Input AD1-1  = "));
        Serial.println(analogRead(BRDTST_GPIO2));
     }
    break;
   }  
   case 133:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[26]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 134:
   {
    // waiting for user input
    break;
   }
 // ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO45 Test
   case 140:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[27]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO45, INPUT); // set D45 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 141:
   {
    // waiting for user input
    break;
   }
   case 142:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[28]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO45);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO45 at J45 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO45 at J45 - Low, Press PB1 to test"));
    }
    break;
   }
   case 143:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO45) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO45);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO45 at J45 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO45 at J45 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO43 Test
   case 150:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[29]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO43, INPUT); // set D43 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 151:
   {
    // waiting for user input
    break;
   }
   case 152:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[30]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO43);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO43 at J43 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO43 at J43 - Low, Press PB1 to test"));
    }
    break;
   }
   case 153:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO43) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO43);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO43 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO43 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO44 Test
   case 160:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[31]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO44, INPUT); // set D44 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 161:
   {
    // waiting for user input
    break;
   }
   case 162:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[32]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO44);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO44 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO44 - Low, Press PB1 to test"));
    }
    break;
   }
   case 163:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO44) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO44);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO44 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO44 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO11 Test
   case 170:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[33]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO11, INPUT); // set D11 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 171:
   {
    // waiting for user input
    break;
   }
   case 172:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[34]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO11);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO11 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO11 - Low, Press PB1 to test"));
    }
    break;
   }
   case 173:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO11) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO11);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO11 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO11 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO12 Test
   case 180:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[35]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO12, INPUT); // set D12 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 181:
   {
    // waiting for user input
    break;
   }
   case 182:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[36]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO12);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO12 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO12 - Low, Press PB1 to test"));
    }
    break;
   }
   case 183:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO12) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO12);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO12 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO12 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO13 Test
   case 190:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[37]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO13, INPUT); // set D13 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 191:
   {
    // waiting for user input
    break;
   }
   case 192:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[38]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO13);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO13 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO13 - Low, Press PB1 to test"));
    }
    break;
   }
   case 193:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO13) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO13);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO13 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO13 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO14 Test
   case 200:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[39]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO14, INPUT); // set D14 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 201:
   {
    // waiting for user input
    break;
   }
   case 202:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[40]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO14);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO14 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO14 - Low, Press PB1 to test"));
    }
    break;
   }
   case 203:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO14) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO14);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO14 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO14 - Low"));
      }
    }
    break;
   }  

     
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO15 Test
   case 210:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[41]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO15, INPUT); // set D15 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 211:
   {
    // waiting for user input
    break;
   }
   case 212:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[22]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO15);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO15 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO15 - Low, Press PB1 to test"));
    }
    break;
   }
   case 213:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO15) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO15);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO15 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO15 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO16 Test
   case 220:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[43]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO16, INPUT); // set D16 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 221:
   {
    // waiting for user input
    break;
   }
   case 222:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[44]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO16);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO16 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO16 - Low, Press PB1 to test"));
    }
    break;
   }
   case 223:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO16) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO16);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO16 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO16 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO17 Test
   case 230:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[45]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO17, INPUT); // set D17 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 231:
   {
    // waiting for user input
    break;
   }
   case 232:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[46]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO17);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO17 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO17 - Low, Press PB1 to test"));
    }
    break;
   }
   case 233:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO17) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO17);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO17 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO17 - Low"));
      }
    }
    break;
   }    
// ***********************************************************************************************************************************************************************************************************************
   //Digital Input GPIO18 Test
   case 240:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[47]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_GPIO18, INPUT); // set D18 as input
    pinMode(BRDTST_GPIO4, OUTPUT); // set D4 as output
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 241:
   {
    // waiting for user input
    break;
   }
   case 242:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[48]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    
    brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO18);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input GPIO18 - High, Press PB1 to test"));
    }
    else
    {
      Serial.println(F("Digital Input GPIO18 - Low, Press PB1 to test"));
    }
    break;
   }
   case 243:
   {
     
     digitalWrite(BRDTST_GPIO4,digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_GPIO18) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_GPIO18);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital GPIO18 - High"));
      }
      else
      {
        Serial.println(F("Digital GPIO18 - Low"));
      }
    }
    break;
   }    


 // ***********************************************************************************************************************************************************************************************************************
 //I2C 3V Port DA Pin Test 
   case 250:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[49]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_DA, INPUT); // set I2C_DA  as input
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 251:
   {
    // waiting for user input
    break;
   }
   case 252:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[50]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_DA);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("I2C 3V Port Pin DA - High,  Press PB1 to test"));
    }
    else
    {
      Serial.println(F("I2C 3V Port Pin DA - Low,  Press PB1 to test"));
    }
    break;
   }
   case 253:
   {
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_I2C_DA) != brdtst_TempLoopVariable)
    {
      
      brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_DA);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("I2C 3V Port Pin DA - High"));
      }
      else
      {
        Serial.println(F("I2C 3V Port Pin DA - Low"));
      }
    }
    break;
   }
  
// ***********************************************************************************************************************************************************************************************************************
 //I2C 3V Port CLK Pin Test        
   case 260:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[51]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_CLK, INPUT); // set I2C_CLK  as input
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 261:
   {
    // waiting for user input
    break;
   }
   case 262:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[52]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_CLK);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("I2C 3V Port Pin CLK - High,  Press PB1 to test"));
    }
    else
    {
      Serial.println(F("I2C 3V Port Pin CLK - Low,  Press PB1 to test"));
    }
    break;
   }
   case 263:
   {
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_I2C_CLK) != brdtst_TempLoopVariable)
    {
      
      brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_CLK);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("I2C 3V Port Pin CLK - High"));
      }
      else
      {
        Serial.println(F("I2C 3V Port Pin CLK - Low"));
      }
    }
    break;
   } 
 
// ***********************************************************************************************************************************************************************************************************************
   //I2C 5V Port DA Pin Test 
   case 270:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[53]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_DA, INPUT); // set I2C_DA  as input
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 271:
   {
    // waiting for user input
    break;
   }
   case 272:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[54]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_DA);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("I2C 5V Port Pin DA - High, pull ground end wire to test"));
    }
    else
    {
      Serial.println(F("I2C 5V Port Pin DA - Low, pull ground end wire to test"));
    }
    break;
   }
   case 273:
   {
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_I2C_DA) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_DA);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("I2C 5V Port Pin DA - High"));
      }
      else
      {
        Serial.println(F("I2C 5V Port Pin DA - Low"));
      }
    }
    break;
   }  
  
 // ***********************************************************************************************************************************************************************************************************************
   //I2C 5V Port CLK Pin Test     
   case 280:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[55]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_CLK, INPUT); // set I2C_CLK  as input
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 281:
   {
    // waiting for user input
    break;
   }
   case 282:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[56]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_CLK);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("I2C 5V Port Pin CLK - High, pull ground end wire to test"));
    }
    else
    {
      Serial.println(F("I2C 5V Port Pin CLK - Low, pull ground end wire to test"));
    }
    break;
   }
   case 283:
   {
    digitalWrite(BRDTST_GPIO4, digitalRead(BRDTST_PB1)); // push PB1 to gpio4
    if(digitalRead(BRDTST_I2C_CLK) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_CLK);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("I2C 5V Port Pin SCLK - High"));
      }
      else
      {
        Serial.println(F("I2C 5V Port Pin SCLK - Low"));
      }
    }
    break;
   } 
   
// ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO35    
   case 290:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[57]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_MOTOR_2_A, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
    
    ledcSetup(1, 50,14);// channel 1, 50 Hz, 14-bit width
    ledcAttachPin(BRDTST_MOTOR_2_A, 1); // assign Motors pins to channels
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 291:
   {
    // waiting for user input
    break;
   }
   case 292:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[58]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 293:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
    if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;
        Serial.println(F("Servo moves to zero degrees.t"));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
   
 // ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO36     
   case 300:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[59]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_MOTOR_2_B, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
     ledcDetachPin(BRDTST_MOTOR_2_A);
     //ledcSetup(1, 50,16);// channel 1, 50 Hz, 16-bit width
    ledcAttachPin(BRDTST_MOTOR_2_B, 1); // assign Motors pins to channels
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 301:
   {
    // waiting for user input
    break;
   }
   case 302:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[60]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 303:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Serial.println(F("Servo moves to zero degrees."));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;  //180 degree
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
   
   // ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO37    
   case 310:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[61]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_MOTOR_1_A, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
     ledcDetachPin(BRDTST_MOTOR_2_B);
     //ledcSetup(1, 50,16);// channel 1, 50 Hz, 16-bit width
    ledcAttachPin(BRDTST_MOTOR_1_A, 1); // assign Motors pins to channels
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 311:
   {
    // waiting for user input
    break;
   }
   case 312:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[62]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 313:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
    if(brdtst_uiTimeCount >= 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Serial.println(F("Servo moves to zero degrees."));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;  //180 degree
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
  
 // ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO38      
   case 320:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[63]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_MOTOR_1_B, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
     ledcDetachPin(BRDTST_MOTOR_1_A);
     //ledcSetup(1, 50,16);// channel 1, 50 Hz, 16-bit width
    ledcAttachPin(BRDTST_MOTOR_1_B, 1); // assign Motors pins to channels
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 321:
   {
    // waiting for user input
    break;
   }
   case 322:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[64]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 323:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Serial.println(F("Servo moves to zero degrees."));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;  //180 degree
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
   
 // ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO39     
   case 330:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[65]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_STEPPER_DIR, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
     ledcDetachPin(BRDTST_MOTOR_1_B);
     //ledcSetup(1, 50,16);// channel 1, 50 Hz, 16-bit width
    ledcAttachPin(BRDTST_STEPPER_DIR, 1); // assign Motors pins to channels
     brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 331:
   {
    // waiting for user input
    break;
   }
   case 332:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[66]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 333:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Serial.println(F("Servo moves to zero degrees."));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;  //180 degree
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
  
 // ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO40    
   case 340:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[67]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_STEPPER_CLK, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
     ledcDetachPin(BRDTST_STEPPER_DIR);
    //ledcSetup(1, 50,16);// channel 1, 50 Hz, 16-bit width 
    ledcAttachPin(BRDTST_STEPPER_CLK, 1); // assign Motors pins to channels
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 341:
   {
    // waiting for user input
    break;
   }
   case 342:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[68]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 343:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Serial.println(F("Servo moves to zero degrees."));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;  //180 degree
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
    
 // ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO41      
   case 350:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[69]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_SERVO_1, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
     ledcDetachPin(BRDTST_STEPPER_CLK);
    //ledcSetup(1, 50,16);// channel 1, 50 Hz, 16-bit width
    ledcAttachPin(BRDTST_SERVO_1,1); // assign Motors pins to channels
     brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 351:
   {
    // waiting for user input
    break;
   }
   case 352:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[70]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 353:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Serial.println(F("Servo moves to zero degrees."));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;  //180 degree
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
    
 // ***********************************************************************************************************************************************************************************************************************
   //Servo test GPIO42    
   case 360:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[71]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_SERVO_2, OUTPUT); // set I2C_CLK  as input
     //setup PWM for motors
     ledcDetachPin(BRDTST_SERVO_1);
    //ledcSetup(1, 50,16);// channel 1, 50 Hz, 16-bit width
    ledcAttachPin(BRDTST_SERVO_2, 1); // assign Motors pins to channels
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 361:
   {
    // waiting for user input
    break;
   }
   case 362:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[72]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_uiPCMTest = 425;  //zero degree
    ledcWrite(1,brdtst_uiPCMTest);
    brdtst_uiTimeCount = 0;
    Serial.println(F("Servo moves to zero degrees."));
    
    break;
   }
   case 363:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Serial.println(F("Servo moves to zero degrees."));
      }
      else
      {
         Serial.println(F("Servo moves to 180 degrees."));
         brdtst_uiPCMTest = 1638;  //180 degree
      }
      ledcWrite(1,brdtst_uiPCMTest);
    }
    break;
   } 
// ***********************************************************************************************************************************************************************************************************************
   // Encoder/Motor Controller A Test    
   case 370:
   {
     ledcDetachPin(BRDTST_SERVO_2);
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[73]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Bot.driveBegin("D1", BRDTST_MOTOR_1_A, BRDTST_MOTOR_1_B, BRDTST_MOTOR_2_A, BRDTST_MOTOR_2_B); // Set up motors as Drive 1
    Bot.Stop("D1");
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 371:
   {
    // waiting for user input
    break;
   }
   case 372:
   {
    brdtst_ucIncrementTestStep = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[74]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_uiTimeCount = 0;
    Bot.Forward("D1",0,240);
    brdtst_uiPCMTest = 425;  
    break;
   }
   case 373:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
    Serial.print(F("Encoder Count = "));
    Serial.println(GetPosition(0));
    if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //
        Bot.Forward("D1",0,240);
        Serial.println(F("Motor Forward."));
      }
      else
      {
         Serial.println(F("Motor Reverse."));
         brdtst_uiPCMTest = 1638;  //180 degree
         Bot.Reverse("D1",0,240);
      }
      
    }
   
    break;
   } 


// ***********************************************************************************************************************************************************************************************************************
   // Encoder/Motor Controller B Test   
   case 380:
   {
    
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[75]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Bot.driveBegin("D1", BRDTST_MOTOR_1_A, BRDTST_MOTOR_1_B, BRDTST_MOTOR_2_A, BRDTST_MOTOR_2_B); // Set up motors as Drive 1
    Bot.Stop("D1");
    brdtst_ucIncrementTestStep = 1;
    break;
   }
   case 381:
   {
    // waiting for user input
    break;
   }
   case 382:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[76]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    Bot.Forward("D1",0, 250); // Drive ID, Left speed, Right speed
    brdtst_uiTimeCount = 0;
    Serial.println(F("Right Motor forward."));
    
    break;
   }
   case 383:
   {
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
    Serial.print(F("Encoder Count = "));
    Serial.println(GetPosition(1));
    if(brdtst_uiTimeCount > 1500)
    {
      brdtst_uiTimeCount = 0;
      if(brdtst_uiPCMTest > 500)
      {
        brdtst_uiPCMTest = 425;  //zero degree
        Bot.Reverse("D1", 0,250); // Drive ID, Left speed, Right speed
        Serial.println(F("Right Motor Reverse."));
      }
      else
      {
         Bot.Forward("D1",0, 250); // Drive ID, Left speed, Right speed
         brdtst_uiPCMTest = 1638;  //180 degree
         Serial.println(F("Right Motor Forward."));
      }
     
    }
    break;
   } 

  
// ***********************************************************************************************************************************************************************************************************************
   //Done Testst 
   case 390:
   {
    brstst_ucMaxNumberofTestSteps = 4;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[77]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_BoardTestingActive = false;
    brdtst_ucIncrementTestStep = 0;
    brdtst_ucTestID = 0;
    break;
   }


   
 }


}









#endif
