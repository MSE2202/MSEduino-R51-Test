/*
 Western Engineering base code
2020 05 13 E J Porter

 WatchDog implement
  
 */

 #ifndef WDT_H
  #define WDT_H 1

//---------------------------------------------------------------------------
//WatchDog

 
 unsigned char WDT_ucWatchDogCore0BeenSet;
 unsigned char WDT_ucWatchDogCore1BeenSet;
 
 volatile boolean  WDT_vbTiggeredCore0;
 volatile boolean  WDT_vbTiggeredCore1;
 
 volatile unsigned char WDT_ucCaseIndexCore0;
 volatile unsigned char WDT_ucCaseIndexCore1;
 
 
 volatile uint32_t WDT_vfFastWDTWarningCore0[10];
 volatile uint32_t WDT_vfFastWDTWarningCore1[10];
 

 volatile uint32_t WDT_vlPreviousTimeCore0;
 volatile uint32_t WDT_vlNowTimeCore0;
 volatile uint32_t WDT_vlPreviousTimeCore1;
 volatile uint32_t WDT_vlNowTimeCore1;
 

 hw_timer_t * WDT_htTimer0 = NULL;
portMUX_TYPE WDT_pmtTimerMux0 = portMUX_INITIALIZER_UNLOCKED;
 hw_timer_t * WDT_htTimer1 = NULL;
portMUX_TYPE WDT_pmtTimerMux1 = portMUX_INITIALIZER_UNLOCKED;
 
//---------------------------------------------------------------------------

void IRAM_ATTR WDT_TimeOutCore0() {
  portENTER_CRITICAL_ISR(&WDT_pmtTimerMux0);
  //add in timing warning
  WDT_vbTiggeredCore0 = true;
  portEXIT_CRITICAL_ISR(&WDT_pmtTimerMux0);
 
}

void IRAM_ATTR WDT_TimeOutCore1() {
  portENTER_CRITICAL_ISR(&WDT_pmtTimerMux1);
  //add in timing warning
  WDT_vbTiggeredCore1 = true;
  portEXIT_CRITICAL_ISR(&WDT_pmtTimerMux1);
 
}

static void WDT_ResetCore0()
{
   portENTER_CRITICAL(&WDT_pmtTimerMux0);
   //WDT_vlNowTimeCore0 = micros();
   asm volatile("esync; rsr %0,ccount":"=a" (WDT_vlNowTimeCore0)); // @ 240mHz clock each tick is ~4nS 
   if(WDT_vbTiggeredCore0)
   {
    WDT_vfFastWDTWarningCore0[WDT_ucCaseIndexCore0] = WDT_vlNowTimeCore0 - WDT_vlPreviousTimeCore0;
    WDT_vbTiggeredCore0 = false;
   }
   WDT_vlPreviousTimeCore0 = WDT_vlNowTimeCore0;
   timerWrite(WDT_htTimer0, 0); //reset timer (feed watchdog)
   portEXIT_CRITICAL(&WDT_pmtTimerMux0);
}

static void WDT_ResetCore1()
{
   portENTER_CRITICAL(&WDT_pmtTimerMux1);
  // WDT_vlNowTimeCore1 = micros();
   asm volatile("esync; rsr %0,ccount":"=a" (WDT_vlNowTimeCore1)); // @ 240mHz clock each tick is ~4nS 
   if(WDT_vbTiggeredCore1)
   {
    WDT_vfFastWDTWarningCore1[WDT_ucCaseIndexCore1] = WDT_vlNowTimeCore1 - WDT_vlPreviousTimeCore1;
    WDT_vbTiggeredCore1 = false;
   }
   WDT_vlPreviousTimeCore1 = WDT_vlNowTimeCore1;
   timerWrite(WDT_htTimer1, 0); //reset timer (feed watchdog)
  portEXIT_CRITICAL(&WDT_pmtTimerMux1);
}

void WDT_EnableFastWatchDogCore0()
{
  if(WDT_ucWatchDogCore0BeenSet)
  {
    //warning system restarted, chk to see if it was a watchdog time out
  }
  else
  {
    WDT_htTimer0 = timerBegin(0, 80, true);
    timerAttachInterrupt(WDT_htTimer0, &WDT_TimeOutCore0, true);
    timerAlarmWrite(WDT_htTimer0, 1010, true);
    timerAlarmEnable(WDT_htTimer0);

    Serial.println("WDT Core 0 on");
  }

  WDT_ResetCore0();
 
}


void WDT_EnableFastWatchDogCore1()
{
  if(WDT_ucWatchDogCore1BeenSet)
  {
    //warning system restarted, chk to see if it was a watchdog time out
  }
  else
  {
  
     WDT_htTimer1 = timerBegin(1, 80, true);
    timerAttachInterrupt(WDT_htTimer1, &WDT_TimeOutCore1, true);
    timerAlarmWrite(WDT_htTimer1, 1010, true);
    timerAlarmEnable(WDT_htTimer1);
    Serial.println("WDT Core 1 on");
  }

  WDT_ResetCore1();
 
}

#endif
