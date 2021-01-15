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
#define BRDTST_SLIDE_SW_1A 13     //when JP7 has jumper installed Digital pin D13 is connected to Slide Switch 1a
#define BRDTST_SLIDE_SW_1B 16     //when JP8 has jumper installed Digital pin D16 is connected to Slide Switch 1b
#define BRDTST_SLIDE_SW_2A 14     //when JP6 has jumper installed Digital pin D14 is connected to Slide Switch 2a
#define BRDTST_SLIDE_SW_2B 17     //when JP9 has jumper installed Digital pin D17 is connected to Slide Switch 2b


#define BRDTST_POT_R1      A4     //when JP2 has jumper installed Analog pin AD4 is connected to Poteniometer R1
#define BRDTST_POT_R2      A7     //when JP3 has jumper installed Analog pin AD7 is connected to Poteniometer R2

#define BRDTST_AD0         A0     //Analog input AD0
#define BRDTST_AD3         A3     //Analog input AD3
#define BRDTST_AD6         A6     //Analog input AD6
#define BRDTST_IMON        A5     //when JP1 has jumper installed Analog pin AD5 is connected to Current Monitor IC U3

#define BRDTST_D2          2      //Digital i/o D2 at Jumper J9 and J29
#define BRDTST_D4          4      //Digital i/o D4 at Jumper J10 and J28
#define BRDTST_D15         15     //Digital i/o D15 at Jumper J8 and J30
#define BRDTST_D12         12     //Digital i/o D12 at Jumper J17 and J24
#define BRDTST_D5          5      //Digital i/o D5 at Jumper J13 and J27
#define BRDTST_D18         18     //Digital i/o D18 at Jumper J14 and J26
#define BRDTST_D19         19     //Digital i/o D19 at Jumper J15 and J25
#define BRDTST_D23         23     //Digital i/o D23 at Jumper J21 and J23

#define BRDTST_TX0_OUT     1      //TX0 UART at jumper J15 (3V) and JP16 (5V)
#define BRDTST_RX0_IN      3      //RX0 UART at jumper J15 (3V) and JP16 (5V)

#define BRDTST_I2C_CLK     22      //I2C CLK at jumper J11 (3V) and JP12 (5V)
#define BRDTST_I2C_DA      21      //I2C Data at jumper J11 (3V) and JP12 (5V)


#define BRDTST_PB1         27     //when JP13 has jumper installed pin D27 is connected to push Buttton 1
#define BRDTST_PB2         26     //when JP14 has jumper installed pin D26 is connected to push Buttton 2
#define BRDTST_LED_PIN     25     //when JP5 has jumper installed pin D25 is connected to SMART LEDs

#define BRDTST_HALLPH1     15     //encoder input B
#define BRDTST_HALLPH2     2      //encoder input A



#define BRSTST_LED_COUNT    2       //number of SMART LEDs in use



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
unsigned char brstst_ucMaxNumberofTests = 28;
unsigned char brdtst_ucIncrementTestStep = 0;
unsigned char brdtst_ucTestID = 0;

unsigned char brdtst_TempLoopVariable = 0;
unsigned char brdtst_TempLoopVariable2 = 0;

unsigned int brdtst_uiTimeCount;
unsigned int brdtst_uiTestIndex;


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
        Serial.println(F("Quiting - Board Testing ( to restart reset esp32"));
        
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
 //blink LEDs
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
  //***********************************************************************************************************************************************************************************************************************
  //Smart LEDs
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
   //***********************************************************************************************************************************************************************************************************************
   //push button 1 test
   case 20:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    SmartLEDs.begin(); // INITIALIZE SMART LEDs object (REQUIRED)
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
   //***********************************************************************************************************************************************************************************************************************
   //push button 2 test
   case 30:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    SmartLEDs.begin(); // INITIALIZE SMART LEDs object (REQUIRED)
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
   //***********************************************************************************************************************************************************************************************************************
   //Slide Switch 1a test
   case 40:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[8]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_SLIDE_SW_1A, INPUT); // set D13 as input
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
    Serial.printf("%s",BoardTesting_Instructions[9]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_1A);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Slide Switch 1a High, switch to test"));
    }
    else
    {
      Serial.println(F("Slide Switch 1a Low, switch to test"));
    }
    break;
   }
   case 43:
   {
   
    if(digitalRead(BRDTST_SLIDE_SW_1A) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_1A);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Slide Switch 1a High"));
      }
      else
      {
        Serial.println(F("Slide Switch 1a Low"));
      }
    }
    break;
   }
//***********************************************************************************************************************************************************************************************************************
   //Slide Switch 1b test
   case 50:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[10]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_SLIDE_SW_1B, INPUT); // set D16 as input
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
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[11]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_1B);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Slide Switch 1b High, switch to test"));
    }
    else
    {
      Serial.println(F("Slide Switch 1b Low, switch to test"));
    }
    break;
   }
   case 53:
   {
   
    if(digitalRead(BRDTST_SLIDE_SW_1B) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_1B);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Slide Switch 1b High"));
      }
      else
      {
        Serial.println(F("Slide Switch 1b Low"));
      }
    }
    break;
   }
 //***********************************************************************************************************************************************************************************************************************
   //Slide Switch 2a test
   case 60:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[12]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_SLIDE_SW_2A, INPUT); // set D14 as input
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
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[13]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_2A);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Slide Switch 2a High, switch to test"));
    }
    else
    {
      Serial.println(F("Slide Switch 2a Low, switch to test"));
    }
    break;
   }
   case 63:
   {
   
    if(digitalRead(BRDTST_SLIDE_SW_2A) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_2A);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Slide Switch 2a High"));
      }
      else
      {
        Serial.println(F("Slide Switch 2a Low"));
      }
    }
    break;
   }  
 //***********************************************************************************************************************************************************************************************************************
   //Slide Switch 2b test
   case 70:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[14]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_SLIDE_SW_2B, INPUT); // set D17 as input
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
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[15]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_2B);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Slide Switch 2b High, switch to test"));
    }
    else
    {
      Serial.println(F("Slide Switch 2b Low, switch to test"));
    }
    break;
   }
   case 73:
   {
   
    if(digitalRead(BRDTST_SLIDE_SW_2B) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_SLIDE_SW_2B);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Slide Switch 2b High"));
      }
      else
      {
        Serial.println(F("Slide Switch 2b Low"));
      }
    }
    break;
   }    
 //***********************************************************************************************************************************************************************************************************************
   //Potentiometer R1 Test
   case 80:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[16]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_POT_R1, INPUT); // set A4 as input, not strickly needed but what the
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
        Serial.print(F("Pot R1 = "));
        Serial.println(analogRead(BRDTST_POT_R1));
     }
    break;
   }      
   case 83:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[17]);
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
  
 //***********************************************************************************************************************************************************************************************************************
   //Potentiometer R2 Test
   case 90:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[18]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_POT_R2, INPUT); // set A7 as input, not strickly needed but what the
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
        Serial.print(F("Pot R2 = "));
        Serial.println(analogRead(BRDTST_POT_R2));
     }
    break;
   } 
   case 93:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[19]);
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
 //***********************************************************************************************************************************************************************************************************************
   //Analog Input AD0  Test
   case 100:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[20]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_AD0, INPUT); // set A0 as input, not strickly needed but what the
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
        Serial.print(F("Analog Input AD0  = "));
        Serial.println(analogRead(BRDTST_AD0));
     }
    break;
   }     
   case 103:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[21]);
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
   //***********************************************************************************************************************************************************************************************************************
   //Analog Input AD3  Test
   case 110:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[22]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_AD3, INPUT); // set A3 as input, not strickly needed but what the
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
        Serial.print(F("Analog Input AD3  = "));
        Serial.println(analogRead(BRDTST_AD3));
     }
    break;
   } 
   case 113:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[23]);
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
   //***********************************************************************************************************************************************************************************************************************
   //Analog Input AD6  Test
   case 120:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[24]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_AD6, INPUT); // set A6 as input, not strickly needed but what the
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
        Serial.print(F("Analog Input AD6  = "));
        Serial.println(analogRead(BRDTST_AD6));
     }
    break;
   }  
   case 123:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[25]);
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
       
   //***********************************************************************************************************************************************************************************************************************
   //Analog Input AD5  Test
   case 130:
   {
    brstst_ucMaxNumberofTestSteps = 3;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[26]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_IMON, INPUT); // set A5 as input, not strickly needed but what the
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
        Serial.print(F("Analog Input AD5  = "));
        Serial.println(analogRead(BRDTST_IMON));
     }
    break;
   }  
   case 133:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[27]);
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
      
  //***********************************************************************************************************************************************************************************************************************
   //Digital Input D2 Test
   case 140:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[28]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D2, INPUT); // set D2 as input
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
    Serial.printf("%s",BoardTesting_Instructions[29]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D2);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D2 at J9 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D2 at J9 - Low, switch to test"));
    }
    break;
   }
   case 143:
   {
   
    if(digitalRead(BRDTST_D2) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D2);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D2 at J9 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D2 at J9 - Low"));
      }
    }
    break;
   }    
   case 144:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[30]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 145:
   {
    // waiting for user input
    break;
   }
   case 146:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[31]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D2);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D2 at J29 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D2 at J29 - Low, switch to test"));
    }
    break;
   }
   case 147:
   {
   
    if(digitalRead(BRDTST_D2) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D2);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D2 at J29 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D2 at J29 - Low"));
      }
    }
    break;
   }    
//***********************************************************************************************************************************************************************************************************************
   //Digital Input D4 Test
   case 150:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[32]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D4, INPUT); // set D4 as input
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
    Serial.printf("%s",BoardTesting_Instructions[33]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D4);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D4 at J10 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D4 at J10 - Low, switch to test"));
    }
    break;
   }
   case 153:
   {
   
    if(digitalRead(BRDTST_D4) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D4);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D4 at J10 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D4 at J10 - Low"));
      }
    }
    break;
   }    
   case 154:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[34]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 155:
   {
    // waiting for user input
    break;
   }
   case 156:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[35]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D4);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D4 at J28 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D4 at J28 - Low, switch to test"));
    }
    break;
   }
   case 157:
   {
   
    if(digitalRead(BRDTST_D4) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D4);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D4 at J28 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D4 at J28 - Low"));
      }
    }
    break;
   } 
//***********************************************************************************************************************************************************************************************************************
   //Digital Input 15 Test
   case 160:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[36]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D15, INPUT); // set D15 as input
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
    Serial.printf("%s",BoardTesting_Instructions[37]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D15);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D15 at J8 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D15 at J8 - Low, switch to test"));
    }
    break;
   }
   case 163:
   {
   
    if(digitalRead(BRDTST_D15) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D15);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D15 at J8 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D15 at J8 - Low"));
      }
    }
    break;
   }    
   case 164:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[38]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 165:
   {
    // waiting for user input
    break;
   }
   case 166:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[39]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D15);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D15 at J30 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D15 at J30 - Low, switch to test"));
    }
    break;
   }
   case 167:
   {
   
    if(digitalRead(BRDTST_D15) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D15);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D15 at J30 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D15 at J30 - Low"));
      }
    }
    break;
   } 
//***********************************************************************************************************************************************************************************************************************
   //Digital Input 12 Test
   case 170:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[40]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D12, INPUT); // set D12 as input
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
    Serial.printf("%s",BoardTesting_Instructions[41]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D12);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D12 at J17 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D12 at J17 - Low, switch to test"));
    }
    break;
   }
   case 173:
   {
   
    if(digitalRead(BRDTST_D12) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D12);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D12 at J17 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D12 at J17 - Low"));
      }
    }
    break;
   }    
   case 174:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[42]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 175:
   {
    // waiting for user input
    break;
   }
   case 176:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[43]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D12);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D12 at J24 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D12 at J24 - Low, switch to test"));
    }
    break;
   }
   case 177:
   {
   
    if(digitalRead(BRDTST_D12) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D12);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D12 at J24 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D12 at J24 - Low"));
      }
    }
    break;
   } 
//***********************************************************************************************************************************************************************************************************************
   //Digital Input 5 Test
   case 180:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[44]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D5, INPUT); // set D5 as input
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
    Serial.printf("%s",BoardTesting_Instructions[45]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D5);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D5 at J13 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D5 at J13 - Low, switch to test"));
    }
    break;
   }
   case 183:
   {
   
    if(digitalRead(BRDTST_D5) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D5);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D5 at J13 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D5 at J13 - Low"));
      }
    }
    break;
   }    
   case 184:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[46]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 185:
   {
    // waiting for user input
    break;
   }
   case 186:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[47]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D5);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D5 at J27 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D5 at J27 - Low, switch to test"));
    }
    break;
   }
   case 187:
   {
   
    if(digitalRead(BRDTST_D5) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D5);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D5 at J27 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D5 at J27 - Low"));
      }
    }
    break;
   } 
 //***********************************************************************************************************************************************************************************************************************
   //Digital Input 18 Test
   case 190:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[48]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D18, INPUT); // set D18 as input
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
    Serial.printf("%s",BoardTesting_Instructions[49]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D18);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D18 at J14 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D18 at J14 - Low, switch to test"));
    }
    break;
   }
   case 193:
   {
   
    if(digitalRead(BRDTST_D18) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D18);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D18 at J14 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D18 at J14 - Low"));
      }
    }
    break;
   }    
   case 194:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[50]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 195:
   {
    // waiting for user input
    break;
   }
   case 196:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[51]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D18);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D18 at J26 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D18 at J26 - Low, switch to test"));
    }
    break;
   }
   case 197:
   {
   
    if(digitalRead(BRDTST_D18) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D18);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D18 at J26 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D18 at J26 - Low"));
      }
    }
    break;
   } 
  //***********************************************************************************************************************************************************************************************************************
   //Digital Input 19 Test
   case 200:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[52]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D19, INPUT); // set D19 as input
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
    Serial.printf("%s",BoardTesting_Instructions[53]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D19);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D19 at J15 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D19 at J15 - Low, switch to test"));
    }
    break;
   }
   case 203:
   {
   
    if(digitalRead(BRDTST_D19) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D19);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D19 at J15 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D19 at J15 - Low"));
      }
    }
    break;
   }    
   case 204:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[54]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 205:
   {
    // waiting for user input
    break;
   }
   case 206:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[55]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D19);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D19 at J25 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D19 at J25 - Low, switch to test"));
    }
    break;
   }
   case 207:
   {
   
    if(digitalRead(BRDTST_D19) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D19);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D19 at J25 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D19 at J25 - Low"));
      }
    }
    break;
   } 
//***********************************************************************************************************************************************************************************************************************
   //Digital Input 23 Test
   case 210:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[56]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_D23, INPUT); // set D23 as input
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
    Serial.printf("%s",BoardTesting_Instructions[57]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D23);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D23 at J21 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D23 at J21 - Low, switch to test"));
    }
    break;
   }
   case 213:
   {
   
    if(digitalRead(BRDTST_D23) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D23);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D23 at J21 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D23 at J21 - Low"));
      }
    }
    break;
   }    
   case 214:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[58]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 215:
   {
    // waiting for user input
    break;
   }
   case 216:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[59]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_D23);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Digital Input D23 at J23 - High, switch to test"));
    }
    else
    {
      Serial.println(F("Digital Input D23 at J23 - Low, switch to test"));
    }
    break;
   }
   case 217:
   {
   
    if(digitalRead(BRDTST_D23) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_D23);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Digital Input D23 at J23 - High"));
      }
      else
      {
        Serial.println(F("Digital Input D23 at J23 - Low"));
      }
    }
    break;
   } 
 //***********************************************************************************************************************************************************************************************************************
   //I2C 3V Port Pin Test 
   case 220:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[60]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_DA, INPUT); // set I2C_DA  as input
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
    Serial.printf("%s",BoardTesting_Instructions[61]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_DA);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("I2C 3V Port Pin DA - High, pull ground end wire to test"));
    }
    else
    {
      Serial.println(F("I2C 3V Port Pin DA - Low, pull ground end wire to test"));
    }
    break;
   }
   case 223:
   {
   
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
   case 224:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[62]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_CLK, INPUT); // set I2C_CLK  as input
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 225:
   {
    // waiting for user input
    break;
   }
   case 226:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[63]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_CLK);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("I2C 3V Port Pin SCLK - High, pull ground end wire to test"));
    }
    else
    {
      Serial.println(F("I2C 3V Port Pin SCLK - Low, pull ground end wire to test"));
    }
    break;
   }
   case 227:
   {
   
    if(digitalRead(BRDTST_I2C_CLK) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_CLK);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("I2C 3V Port Pin SCLK - High"));
      }
      else
      {
        Serial.println(F("I2C 3V Port Pin SCLK - Low"));
      }
    }
    break;
   } 
 
//***********************************************************************************************************************************************************************************************************************
   //I2C 5V Port Pin Test 
   case 230:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[64]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_DA, INPUT); // set I2C_DA  as input
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
    Serial.printf("%s",BoardTesting_Instructions[65]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
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
   case 233:
   {
   
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
   case 234:
   {
    
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[66]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_I2C_CLK, INPUT); // set I2C_CLK  as input
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 235:
   {
    // waiting for user input
    break;
   }
   case 236:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[67]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    brdtst_TempLoopVariable = digitalRead(BRDTST_I2C_CLK);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("I2C 5V Port Pin SCLK - High, pull ground end wire to test"));
    }
    else
    {
      Serial.println(F("I2C 5V Port Pin SCLK - Low, pull ground end wire to test"));
    }
    break;
   }
   case 237:
   {
   
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
//***********************************************************************************************************************************************************************************************************************
   // UART0 3V Port Pins Test
   case 240:
   {
    brstst_ucMaxNumberofTestSteps = 4;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[68]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 1;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 241:
   {
    // waiting for user input
    break;
   }
   case 242:
   {
    
    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 1000)
     {
        brdtst_TempLoopVariable = brdtst_TempLoopVariable + 1;
        brdtst_uiTimeCount = 0;
       
        if(brdtst_TempLoopVariable <= 10)
         {
           Serial.print(F("3V UART verify - "));
           Serial.println(brdtst_TempLoopVariable);
            
         }
         else
         {
           if(brdtst_TempLoopVariable > 11)
           {
            Serial.println(F("3V UART ERROR"));
            brdtst_ucIncrementTestStep = 3;
            
           }
           else
           {
            Serial.println(F("X"));
           }
         }
    
     }
    
    break;
   }
   case 243:
   {
    pinMode(BRDTST_RX0_IN, OUTPUT);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[69]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
    pinMode(BRDTST_RX0_IN, INPUT);
    
    break;
   }
   case 244:
   {
     
    // waiting for user input
    break;
   }    
//***********************************************************************************************************************************************************************************************************************
   // UART0 5V Port Pins Test
   case 250:
   {
    
    brstst_ucMaxNumberofTestSteps = 4;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[70]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    
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
      brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 1000)
     {
        brdtst_TempLoopVariable = brdtst_TempLoopVariable + 1;
        brdtst_uiTimeCount = 0;
       
        if(brdtst_TempLoopVariable <= 10)
         {
           Serial.print(F("5V UART verify - "));
           Serial.println(brdtst_TempLoopVariable);
            
         }
         else
         {
           if(brdtst_TempLoopVariable > 11)
           {
            Serial.println(F("5V UART ERROR"));
            brdtst_ucIncrementTestStep = 3;
            
           }
           else
           {
            Serial.println(F("X"));
           }
         }
         
        
     }
    break;
   }
   case 253:
   {
     pinMode(BRDTST_RX0_IN, OUTPUT);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[71]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 4;
    brdtst_TempLoopVariable = 0;
     pinMode(BRDTST_RX0_IN, INPUT);
    break;
   }
   case 254:
   {
    // waiting for user input
    break;
   } 
//***********************************************************************************************************************************************************************************************************************
   //Current Monitor Input Test 
   case 260:
   {
    brstst_ucMaxNumberofTestSteps = 7;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[72]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_IMON, INPUT); // set IMON(A5) as input, not strickly needed but what the
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
    Serial.printf("%s",BoardTesting_Instructions[73]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 263:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Current Monitor  = "));
        Serial.println(analogRead(BRDTST_IMON));
     }
    break;
   }    
  case 264:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[74]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    break;
   }
   case 265:
   {
    // waiting for user input
    break;
   }
   case 266:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[75]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 7;
    brdtst_TempLoopVariable = 0;
    break;
   }
   case 267:
   {

    brdtst_uiTimeCount = brdtst_uiTimeCount + 1;
     if(brdtst_uiTimeCount >= 100)
     {
        brdtst_uiTimeCount = 0;
        Serial.print(F("Current Monitor  = "));
        Serial.println(analogRead(BRDTST_IMON));
     }
    break;
   }     
//***********************************************************************************************************************************************************************************************************************
  
   //encoder test

 case 270:
   {
    brstst_ucMaxNumberofTestSteps = 5;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[76]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    pinMode(BRDTST_HALLPH1, INPUT);
    pinMode(BRDTST_HALLPH2, INPUT);
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
    brdtst_ucIncrementTestStep = 3;
    brdtst_TempLoopVariable = digitalRead(BRDTST_HALLPH1);
    if(brdtst_TempLoopVariable)
    {
      Serial.println(F("Ph1 High"));
    }
    else
    {
      Serial.println(F("PH1 Low"));
    }
    brdtst_TempLoopVariable2 = digitalRead(BRDTST_HALLPH2);
    if(brdtst_TempLoopVariable2)
    {
      Serial.println(F("PH2 High"));
    }
    else
    {
      Serial.println(F("PH2 Low"));
    }
    // waiting for user input
    break;
   }
   case 273:
   {
    if(digitalRead(BRDTST_HALLPH1) != brdtst_TempLoopVariable)
    {
      brdtst_TempLoopVariable = digitalRead(BRDTST_HALLPH1);
      if(brdtst_TempLoopVariable)
      {
        Serial.println(F("Ph1 High"));
      }
      else
      {
        Serial.println(F("PH1 Low"));
      }
    }
     if(digitalRead(BRDTST_HALLPH2) != brdtst_TempLoopVariable2)
    {
      brdtst_TempLoopVariable2 = digitalRead(BRDTST_HALLPH2);
      if(brdtst_TempLoopVariable2)
      {
        Serial.println(F("PH2 High"));
      }
      else
      {
        Serial.println(F("PH2 Low"));
      }
    }
    break;
   }
   case 274:
   {
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    Serial.printf("%s",BoardTesting_Instructions[77]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_ucIncrementTestStep = 5;
    brdtst_TempLoopVariable = 0;
    break;
   }

   
//***********************************************************************************************************************************************************************************************************************
   //Done Testst 
   case 280:
   {
    brstst_ucMaxNumberofTestSteps = 4;
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));Serial.println(F(""));
    Serial.printf("%s",BoardTesting_Instructions[78]);
    Serial.println(F("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"));
    brdtst_BoardTestingActive = false;
    brdtst_ucIncrementTestStep = 0;
    brdtst_ucTestID = 0;
    break;
   }


   
 }


}









#endif
