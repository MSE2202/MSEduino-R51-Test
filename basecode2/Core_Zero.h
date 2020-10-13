/*
Western Engineering base code
2020 06 17
  
\Core 0 code


*/

#ifndef CORE_ZERO_H
#define CORE_ZERO_H 1


#include "MyWEBserver.h"
#include "BreakPoint.h"
#include "WDT.h";

TaskHandle_t Core_Zero;

const int CR0_ciMainTimer =  1000;

unsigned char CR0_ucMainTimerCaseCore0;

unsigned int uiTestCounter;

uint32_t CR0_u32Now;
uint32_t CR0_u32Last;
uint32_t CR0_u32Temp;
uint32_t CR0_u32Avg;

unsigned long CR0_ulPreviousMicrosCore0;
unsigned long CR0_ulCurrentMicrosCore0;

void Core_ZeroCode( void * pvParameters );


void Core_ZEROInit()
{
   xTaskCreatePinnedToCore(
                    Core_ZeroCode,   /* Task function. */
                    "Core_Zero",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Core_Zero,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 
};


void Core_ZeroCode( void * pvParameters )
{
  Serial.print("Core - ");
  Serial.print(xPortGetCoreID());
  Serial.println("   running ");


  //Core 0 Setup
  //-------------------------------------------------------------------------------------------
   WSVR_BreakPointInit("DBON","CONT"); //Start contidions "HALT", "CONT", DBON", DBOF" 

   WSVR_setupWEbServer();
  
   delay(1000);
   
   WSVR_AnswerGetRequest();
   
   WDT_EnableFastWatchDogCore0();
   
   WDT_ResetCore0();
   WDT_vfFastWDTWarningCore0[0] = 0;
   WDT_vfFastWDTWarningCore0[1] = 0;
   WDT_vfFastWDTWarningCore0[2] = 0;
   WDT_vfFastWDTWarningCore0[3] = 0;
   WDT_ResetCore0();
   WDT_vfFastWDTWarningCore0[4] = 0;
   WDT_vfFastWDTWarningCore0[5] = 0;
   WDT_vfFastWDTWarningCore0[6] = 0;
   WDT_vfFastWDTWarningCore0[7] = 0;
   WDT_ResetCore0();
   WDT_vfFastWDTWarningCore0[8] = 0;
   WDT_vfFastWDTWarningCore0[9] = 0;
   WDT_ResetCore0(); 
   
   
  //loop function for core 0
  //-------------------------------------------------------------------------------------------
  for(;;)
  {

       
       CR0_ulCurrentMicrosCore0 = micros();
      if ((CR0_ulCurrentMicrosCore0 - CR0_ulPreviousMicrosCore0) >= CR0_ciMainTimer)
      {
        
        WDT_ResetCore0();
        WDT_ucCaseIndexCore0 = CR0_ucMainTimerCaseCore0;
        vTaskDelay(1);

    
        CR0_ulPreviousMicrosCore0 = CR0_ulCurrentMicrosCore0;
        
        
        WSVR_ButtonResponce();
        asm volatile("esync; rsr %0,ccount":"=a" (CR0_u32Last)); // @ 240mHz clock each tick is ~4nS  
        webSocket.loop();
         asm volatile("esync; rsr %0,ccount":"=a" (CR0_u32Now));    
        
        switch(CR0_ucMainTimerCaseCore0)  //full switch run through is 1mS
        {
          //###############################################################################
          case 0: //LCD Display
          {
            WSVR_AnswerGetRequest();
            CR0_ucMainTimerCaseCore0 = 1;
            
            break;
          }
          //###############################################################################
          case 1: //Screen control
          {
         
            uiTestCounter = uiTestCounter + 1;
            //Serial.println(uiTestCounter);
            WSVR_BreakPoint(1);
            CR0_ucMainTimerCaseCore0 = 2;
          
            break;
          }
          //###############################################################################
          case 2: //push button control
          {
            
            
            CR0_ucMainTimerCaseCore0 = 3;
            break;
          }
          //###############################################################################
          case 3: //LCD Display
          {
            
            
            CR0_ucMainTimerCaseCore0 = 4;
            break;
          }
          //###############################################################################
          case 4:   ///warning nad emergency control
          {
          
            CR0_ucMainTimerCaseCore0 = 5;
            break;
          }
          //###############################################################################
          case 5: 
          {
          //  asm volatile("esync; rsr %0,ccount":"=a" (CR0_u32Last)); //@ 240mHz 1 tick = ~4nS
          //  asm volatile("esync; rsr %0,ccount":"=a" (CR0_u32Now));              
//
//                  if(CR0_u32Temp < (CR0_u32Now - CR0_u32Last)) //display max time for execution
//                  {
//                    CR0_u32Temp  = (CR0_u32Now - CR0_u32Last);
//                  }
//                  CR0_u32Avg = (CR0_u32Avg + (CR0_u32Now - CR0_u32Last))/2;
//                  Serial.print("  max ");
//                  Serial.print(CR0_u32Temp);
//                  Serial.print(" avg  ");
//                  Serial.println(CR0_u32Avg);

//                  for(GV_uiLoopCounter_A = 0; GV_uiLoopCounter_A < 10; GV_uiLoopCounter_A++)
//                  {
//                  
//                  Serial.print(GV_uiLoopCounter_A); 
//                  Serial.print(" , ");
//                  Serial.print(WDT_vfFastWDTWarningCore0[GV_uiLoopCounter_A]);
//                  Serial.print(" , ");
//                  Serial.println(WDT_vfFastWDTWarningCore1[GV_uiLoopCounter_A]);
//                  }
//                  
//         
                  
                  
                  
            CR0_ucMainTimerCaseCore0 = 6;
            break;
          }
          //###############################################################################
          case 6:
          {
        
          
            CR0_ucMainTimerCaseCore0 = 7;
            break;
          }
          //###############################################################################
          case 7: 
          {
            WSVR_SendMsg();
            CR0_ucMainTimerCaseCore0 = 8;
            break;
          }
          //###############################################################################
          case 8: 
          {
           
            CR0_ucMainTimerCaseCore0 = 9;
            break;
          }
          //###############################################################################
          case 9: 
          {
                       
       
            CR0_ucMainTimerCaseCore0 = 0;
           
            break;
          }
      
        }
        
      }
  }
}

#endif
