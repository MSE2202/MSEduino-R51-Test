/*
//Western Engineering base code 
March 21,2020
  
\WEB server code


*/

#ifndef BREAKPOINT_H
#define BREAKPOINT_H 1


#include "MyWEBserver.h"


void WSVR_BreakPointInit(String strDebug_OnOff, String strHaltContinous)
{
 // break point initialze variabel names
 // "BPN#;NN;variable name1;...variable name 5;  # is 1 to 5, string these togather to populate all 25 variable names. 
 //BNP numbers don't need to be in order but the names between the BNPs will fill the teh column right below this BNP number
 //initialize chart names and data scope size
 //BPCN;NN;LL1;variable 1 lower limit,UU1; variable 1 upper limit;LL2;variable 2 lower limit,UU2; variable 2 upper limit;+
 //LL3;variable 3 lower limit,UU3; variable 3 upper limit;LL4;variable 4 lower limit,UU4; variable 4 upper limit;LL5;variable 5 lower limit,UU5; variable 5 upper limit;+
 //variable name1;...variable name 6;


  if(strDebug_OnOff.equals("DBON"))
  {
     bWSVR_DebugOfOff = true;
  }
  else
  {
     bWSVR_DebugOfOff = false;
  }
  if(strHaltContinous.equals("HALT"))
  {
     bWSVR_HaltContinuous = false;
  }
  else
  {
     bWSVR_HaltContinuous = true;
  } 
  
 
  //strWSVR_VariableNames = //String("BPN1") + ";" + String("NN") + ";" + String("") + ";" + String("") + ";" + String("") + ";"
   strWSVR_VariableNames  = String(strDebug_OnOff) + ";" + String(strHaltContinous) + ";"
                        + String("BPCN") + ";" + String("QQ") + ";" 
                        + String("LL1") + ";" + String(0) + ";" + String("UU1") + ";" + String(100) + ";"
                        + String("LL2") + ";" + String(0) + ";" + String("UU2") + ";" + String(100) + ";"
                        + String("LL3") + ";" + String(0) + ";" + String("UU3") + ";" + String(0) + ";"
                        + String("LL4") + ";" + String(0) + ";" + String("UU4") + ";" + String(0) + ";"
                        + String("LL5") + ";" + String(0) + ";" + String("UU5") + ";" + String(0) + ";"
                        + String("LL6") + ";" + String(0) + ";" + String("UU6") + ";" + String(0) + ";"
                        + String("NN") + ";" + String("countb") + ";" + String("ucCapacity")+ ";" + String("");
}

void WSVR_BreakPoint(unsigned char ucBPindex)
{
 
  extern unsigned int uiTestCounter;
  
  
  if(bWSVR_DebugOfOff)
  {
    
    if(bWSVR_HaltContinuous == false)
    {
     bWSVR_Halted = true;
     while(bWSVR_Halted)
     {
      // strWSVR_VariableData = String("BP1") + ";" + "HH" + ";" +String(0) + ";" + String(0)+ ";" + String()+ ";"
      //                      + String("BPC") + ";" + "CC" + ";" +String(countb) + ";" + String()+ ";" + String();
        strWSVR_VariableData = String("BPC") + ";" + "CC" + ";" + String(uiTestCounter);                     
       WSVR_ButtonResponce();
       if((bWSVR_DebugOfOff == false) || (bWSVR_HaltContinuous))
       {
        break;
       }
     }
    }
    else
    {
      //strWSVR_VariableData = String("BP1") + ";" + "XX" + ";" +String( ) + ";" + String(0)+ ";" + String(0) + ";" 
      //                     + String("BPC") + ";" + "CC" + ";" +String(countb) + ";" + String(ulCurrentMicros)+ ";" + String(uiTestCounter);
      strWSVR_VariableData = String("BPC") + ";" + "CC" + ";" + String(uiTestCounter);
    }
   }
  
}











#endif
