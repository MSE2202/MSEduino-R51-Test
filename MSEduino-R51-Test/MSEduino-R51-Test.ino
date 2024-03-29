//
//  MSE 2202 
//  MSEduino V5.1 Board Testing
//
//  Author: E J Porter
//  Date: Dec 2023
//
//  To program and use ESP32-S3
//   
//  File->Preferences:
//  Additional Boards Manager URLs: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
//
//
//  Tools->:
//  Board: "Adafruit Feather ESP32-S3 No PSRAM"
//  Upload Speed: "921600"
//  USB CDC On Boot: "Enabled"
//  USB Firmware MSC on Boot: "Disabled"
//  USB DFU On Bot: "Disabled"
//  Upload Mode:"UART0/Hardware CDC"
//  SPU Frequency: "240MHz (WiFi)"
//  Flash Mode: "QIO 80MHz"
//  Flash SIze: "4MB (32Mb)"
//  Partition Scheme: "Default 4MB with spiffs (1.2MB app/1.5MB SPIFFS)"
//  Core Debug Level: "Verbose"
//  PSRAM: 'Disabled"
//  Arduino Runs On: "Core 1"
//  Events Run On: "Core 1"
//
//  To program, press and hold the reset button then press and hold program button, release the reset button then release the program button 
//

#ifdef CORE_DEBUG_LEVEL
#undef CORE_DEBUG_LEVEL
#endif
#define CORE_DEBUG_LEVEL 3

#define BOARDTESTING 1

#include "0_Core_Zero.h"
#include <esp_task_wdt.h>
#include <Math.h>
#include "WDT.h"

#ifdef BOARDTESTING
#include "BoardTesting.h"
#endif

void ARDUINO_ISR_ATTR encoderISR(void* arg);

const int CR1_ciMainTimer =  1000;
unsigned long CR1_ulMainTimerPrevious;
unsigned long CR1_ulMainTimerNow;
unsigned char CR1_ucMainTimerCaseCore1;

const int CR1_ciCountsRev = 1096;                          // encoder pulses per motor revolution
const int CR1_ciMaxSpeedInCounts = 1600;                   // maximum encoder counts/sec

// Encoder structure
struct Encoder 
{
  const int chanA;                                    // GPIO pin for encoder channel A
  const int chanB;                                    // GPIO pin for encoder channel B
  long pos;                                           // current encoder position
};

Encoder encoder[] = {{11, 12, 0},                    // encoder 0 on GPIO 11 and 12, 0 position 
                     {15, 16, 0}};                    // encoder 1 on GPIO 15 and 16, 0 position 


// encoder interrupt service routine
// argument is pointer to an encoder structure, which is statically cast to a Encoder structure, allowing multiple
// instances of the encoderISR to be created (1 per encoder)
void ARDUINO_ISR_ATTR encoderISR(void* arg)
{
  Encoder* s = static_cast<Encoder*>(arg);            // cast pointer to static structure
  
  int b = digitalRead(s->chanB);                      // read state of channel B
  if (b > 0) {                                        // high, leading channel A
    s->pos++;                                         // increase position
  }
  else {                                              // low, lagging channel A
    s->pos--;                                         // decrease position
  }
}

long GetPosition(int Which_Encoder)
{
  return encoder[Which_Encoder].pos;
}

void setup() 
{
   Serial.begin(115200);
   
   Serial.println("MSEduino V5.1 Test Program");
   delay(1000);
    
   //set the resolution to 12 bits (0-4096)
   analogReadResolution(12);
   
   Core_ZEROInit();
   
   WDT_EnableFastWatchDogCore1();
   WDT_ResetCore1();
   WDT_vfFastWDTWarningCore1[0] = 0;
   WDT_vfFastWDTWarningCore1[1] = 0;
   WDT_vfFastWDTWarningCore1[2] = 0;
   WDT_vfFastWDTWarningCore1[3] = 0;
   WDT_ResetCore1();
   WDT_vfFastWDTWarningCore1[4] = 0;
   WDT_vfFastWDTWarningCore1[5] = 0;
   WDT_vfFastWDTWarningCore1[6] = 0;
   WDT_vfFastWDTWarningCore1[7] = 0;
   WDT_ResetCore1();
   WDT_vfFastWDTWarningCore1[8] = 0;
   WDT_vfFastWDTWarningCore1[9] = 0;
   WDT_ResetCore1(); 
   
   CR1_ucMainTimerCaseCore1 = 0;

    pinMode(encoder[0].chanA, INPUT);                 // configure GPIO for encoder 0 channel A input
    pinMode(encoder[0].chanB, INPUT);                 // configure GPIO for encoder 0 channel B input
    // configure encoder to trigger interrupt with each rising edge on channel A
    attachInterruptArg(encoder[0].chanA, encoderISR, &encoder[0], RISING);
    
    pinMode(encoder[1].chanA, INPUT);                 // configure GPIO for encoder 1 channel A input
    pinMode(encoder[1].chanB, INPUT);                 // configure GPIO for encoder 1 channel B input
    // configure encoder to trigger interrupt with each rising edge on channel A
    attachInterruptArg(encoder[1].chanA, encoderISR, &encoder[1], RISING);
}
 
void loop()
{
   CR1_ulMainTimerNow = micros();
   if(CR1_ulMainTimerNow - CR1_ulMainTimerPrevious >= CR1_ciMainTimer) // enter main switch case every 1 mS , with 10 cases it take 10 mS to run every case
   {
      CR1_ulMainTimerPrevious = CR1_ulMainTimerNow;
      WDT_ResetCore1();                                                //watchdog reset
      WDT_ucCaseIndexCore1 = CR1_ucMainTimerCaseCore1;                 // loads case index so watchdog can track if case is taking longer than 1 mS
      
      switch(CR1_ucMainTimerCaseCore1)                                 //full switch run through is 1 mS
      {
      //###############################################################################
         case 0: //Board Testing if enabled
         {
#ifdef BOARDTESTING
            if((brdtst_BoardTestingActive) && (WDT_vbCore0Running))
            {
               BRD_Testing();
            }
#endif
            break;
         }
         //###############################################################################
         case 1: 
         {
            
            CR1_ucMainTimerCaseCore1 = 2;
            break;
         }
         //###############################################################################
         case 2: 
         {
            
            CR1_ucMainTimerCaseCore1 = 3;
            break;
         }
         //###############################################################################
         case 3:
         {
           
            CR1_ucMainTimerCaseCore1 = 4;
            break;
         }
         //###############################################################################
         case 4:   
         {
    
            CR1_ucMainTimerCaseCore1 = 5;
            break;
         }
         //###############################################################################
         case 5: 
         {
   
            CR1_ucMainTimerCaseCore1 = 6;
            break;
         }
         //###############################################################################
         case 6: 
         {
  
            CR1_ucMainTimerCaseCore1 = 7;
            break;
         }
         //###############################################################################
         case 7: 
         {
   
            CR1_ucMainTimerCaseCore1 = 8;
            break;
         }
         //###############################################################################
         case 8: 
         {
    
            CR1_ucMainTimerCaseCore1 = 9;
            break;
         }
         //###############################################################################
         case 9: 
         {
  
            CR1_ucMainTimerCaseCore1 = 0;
            break;
         }
      }
   }
}
