/*
Western Engineering base code
2020 06 17
  
\Core 0 code


*/

#ifndef CORE_ZERO_H
#define CORE_ZERO_H 1


#include "MyWEBserver.h"
#include "BreakPoint.h"

TaskHandle_t Core_Zero;



unsigned long ulPreviousMicrosCore0;
unsigned long ulCurrentMicrosCore0;

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
   WSVR_BreakPointInit("DBON","HALT"); //Start contidions "HALT", "CONT", DBON", DBOF" 

   WSVR_setupWEbServer();
  
  //loop function for core 0
  //-------------------------------------------------------------------------------------------
  for(;;)
  {

       
       //esp_err_t esp_task_wdt_reset();
       
      //main timing loop enters if every ~1ms
      ulCurrentMicrosCore0 = micros();
      if ((ulCurrentMicrosCore0 - ulPreviousMicrosCore0) >= 500)
      {
        vTaskDelay(1);
        ulPreviousMicrosCore0 = ulCurrentMicrosCore0;
        WSVR_ButtonResponce();
        
      } 
  }
}

#endif
