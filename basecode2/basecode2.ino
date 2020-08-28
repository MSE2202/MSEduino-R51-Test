

//Western Engineering base code
//2020 05 13 E J Porter





/*
  esp32
  pins         description                        used
  1             3v3                               PWR 3V3
  2             gnd                               GND
  3             GPIO15/AD2_3/T3/SD_CMD/
  4             GPIO2/AD2_2/T2/SD_D0              INDICATORLED
  5             GPIO4/AD2_0/T0/SD_D1
  6             GPIO16/RX2
  7             GPIO17/TX2
  8             GPIO5                             
  9             GPIO18                            
  10            GPIO19/CTS0
  11            GPIO21                             CLK
  12            GPIO3/RX0
  13            GPIO1//TX0
  14            GPIO22/RTS1                        SDA
  15            GPIO23
  16            EN
  17            GPI36/VP/AD1_0                    
  18            GPI39/VN/AD1_3/
  19            GPI34/AD1_6/
  20            GPI35/AD1_7
  21            GPIO32/AD1_4/T9
  22            GPIO33/AD1_5/T8
  23            GPIO25/AD2_8/DAC1
  24            GPIO26/A2_9/DAC2
  25            GPIO27/AD2_7/T7                   
  26            GPOP14/AD2_6/T6/SD_CLK            
  27            GPIO12/AD2_5/T5/SD_D2/            
  28            GPIO13/AD2_4/T4/SD_D3/            
  29            GND                               GND
  30            VIN                               PWR >= 5v

*/



#include "Core_Zero.h"

//pins
#define INDICATORLED 2

#define SDA 22
#define SCL 21


#include <esp_task_wdt.h>

#include <Math.h>
#include "MyWEBserver.h"
#include "BreakPoint.h"
#include "WDT.h";

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


void setup() {
  Serial.begin(115200);
  pinMode(INDICATORLED, OUTPUT);
  
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
}
void loop()
{

  //WSVR_BreakPoint(1);
 
 
 
 CR1_ulMainTimerNow = micros();
 if(CR1_ulMainTimerNow - CR1_ulMainTimerPrevious >= CR1_ciMainTimer)
 {
   WDT_ResetCore1(); 
   WDT_ucCaseIndexCore0 = CR0_ucMainTimerCaseCore0;
   
   CR1_ulMainTimerPrevious = CR1_ulMainTimerNow;
 
  switch(CR1_ucMainTimerCaseCore1)  //full switch run through is 1mS
  {
    //###############################################################################
    case 0: //LCD Display
    {
      
     
      CR1_ucMainTimerCaseCore1 = 1;
      
      break;
    }
    //###############################################################################
    case 1: //Screen control
    {
   
    
      CR1_ucMainTimerCaseCore1 = 2;
    
      break;
    }
    //###############################################################################
    case 2: //push button control
    {
      
   
      CR1_ucMainTimerCaseCore1 = 3;
      break;
    }
    //###############################################################################
    case 3: //LCD Display
    {
      
      
      CR1_ucMainTimerCaseCore1 = 4;
      break;
    }
    //###############################################################################
    case 4:   ///warning nad emergency control
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
    case 6: //LCD Display
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
