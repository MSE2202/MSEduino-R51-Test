
//MSE 2202 
//Western Engineering base code
//2022 12 05 E J Porter



/* To program and use esp32-s3
   
  File->Preferences:
Additional Boards Manager URLs: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

Tools->:
Board:"ESP32S3 Dev Module"
Upload Speed: "921600"
USB CDC On Boot: "Enabled"
USB Firmware MSC on Boot: "Disabled"
USB DFU On Bot: "Disabled"
Upload Mode:"UART0/Hardware CDC"
SPU Frequency: "240MHz ( WiFi)"
Flash Mode: "QIO 80MHz"
Flash SIze: "4MB (32Mb)"
Partition Scheme: "Default 4MB with spiffs (1.2MB app/1.5MB SPIFFS)"
Core Debug Level: "Verbose"
PSRAM: 'Disabled"
Arduino Runs On: "Core 1"
Events Run On: "Core 1"


*/


#ifdef CORE_DEBUG_LEVEL
#undef CORE_DEBUG_LEVEL
#endif

#define CORE_DEBUG_LEVEL 3


//#include "WEBserver.h"
#include "0_Core_Zero.h"

#define BROADTESTING 1


//pins
#define MOTORLEFTa 14
#define MOTORLEFTb 4
#define MOTORRIGHTa 5
#define MOTORRIGHTb 18


#include <esp_task_wdt.h>

#include <Math.h>
//#include "MyWEBserver.h"
#include "WDT.h"

#ifdef BROADTESTING
#include "BoardTesting.h"
#endif


void loopWEBServerButtonresponce(void);

//unsigned int uiCountUp;
//unsigned int uiTestCounter;
//boolean bTestCounter;
//float fTestCounter;
//
//char bToggleBit;
const int CR1_ciMainTimer =  1000;

unsigned char CR1_ucMainTimerCaseCore1;


uint32_t CR1_u32Now;
uint32_t CR1_u32Last;
uint32_t CR1_u32Temp;
uint32_t CR1_u32Avg;


unsigned long CR1_ulMainTimerPrevious;
unsigned long CR1_ulMainTimerNow;

unsigned long CR1_ulMotorTimerPrevious;
unsigned long CR1_ulMotorTimerNow;

void setup() 
{
  Serial.begin(115200);

  Serial.println(F("MSE-diuno V4.2 Test Program"));
  delay(1000);
  
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
   
 }


 
void loop()
{

  //WSVR_BreakPoint(1);

 CR1_ulMainTimerNow = micros();
 if(CR1_ulMainTimerNow - CR1_ulMainTimerPrevious >= CR1_ciMainTimer)   //enter main switch case every 1mS , with 10 cases it take 10mS to run every case
 {
   CR1_ulMainTimerPrevious = CR1_ulMainTimerNow;
   WDT_ResetCore1();   //watchdog reset
   WDT_ucCaseIndexCore1 = CR1_ucMainTimerCaseCore1;  //loads case index so wath dog can track if case is taking longer than 1mS
      
  switch(CR1_ucMainTimerCaseCore1)  //full switch run through is 1mS
  {
    //###############################################################################
    case 0: //Board Testing if enabled
    {
#ifdef BROADTESTING
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
