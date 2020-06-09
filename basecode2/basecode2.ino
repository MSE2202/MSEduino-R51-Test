

//Western Engineering S1116 base code
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


TaskHandle_t Core0;

//pins
#define INDICATORLED 2

#define SDA 22
#define SCL 21


#include <esp_task_wdt.h>

#include <Math.h>
#include "MyWEBserver.h"


void loopWEBServerButtonresponce(void);

unsigned int uiCountUp;
unsigned int uiTestCounter;

char bToggleBit;
const int ciMainTimer =  1000;//200;

unsigned int uiCommunticationTimer;

unsigned long ulPreviousMicrosCore0;
unsigned long ulCurrentMicrosCore0;

unsigned long ulPreviousMicros;
unsigned long ulCurrentMicros;


void Core0code( void * pvParameters ){
  Serial.print("Core - ");
  Serial.print(xPortGetCoreID());
  Serial.println("   running ");

 
  
  //loop function for core 0
  for(;;)
  {

       
       esp_err_t esp_task_wdt_reset();
      //main timing loop enters if every ~1ms
      ulCurrentMicrosCore0 = micros();
      //if ((ulCurrentMicrosCore0 - ulPreviousMicrosCore0) >= 500)
     // {
        Serial.println("C");
        ulPreviousMicrosCore0 = ulCurrentMicrosCore0;
         WSVR_ButtonResponce();
        
      //} 
  }
}











void setup() {
  Serial.begin(115200);
  pinMode(INDICATORLED, OUTPUT);
  Serial.println(xPortGetCoreID());

   //setup
   WSVR_BreakPointInit();

   WSVR_setupWEbServer();
   
   xTaskCreatePinnedToCore(
                    Core0code,   /* Task function. */
                    "Core0",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Core0,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  
  delay(500); 

 
}
void loop()
{

  //main timing loop enters if every ~200us (ciMainTimer). thsi loop time controls all other timers
  ulCurrentMicros = micros();
  if ((ulCurrentMicros - ulPreviousMicros) >= ciMainTimer)
  {
    ulPreviousMicros = ulCurrentMicros;

    //increment program timers
  
    uiCommunticationTimer = uiCommunticationTimer + 1;
    bToggleBit = bToggleBit + 1;
   /* if (bToggleBit & 1)
    {
      digitalWrite(INDICATORLED, HIGH);

    }
    else
    {
      digitalWrite(INDICATORLED, LOW);

    }
*/
    
   
   

    uiCountUp = uiCountUp + 1;
    uiTestCounter = uiTestCounter + 1;
    if(uiTestCounter > 65530)
    {
      uiTestCounter = 0;
    }
    
    if(uiCountUp > 1500)
    {
      uiCountUp  =0;
      if (bToggleBit & 1)
      {
        digitalWrite(INDICATORLED, HIGH);
        Serial.println(xPortGetCoreID());
      }
      else
      {
        digitalWrite(INDICATORLED, LOW);
        WSVR_BreakPoint(1);
  
      }
    }


  }


}
