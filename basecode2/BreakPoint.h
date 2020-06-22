/*
//Western Engineering base code 
March 21,2020
  
\Break point variable code setup

usage
#define WATCH_VARIABLE_1_NAME "put Varianle name here ( in quotes), if charting is wanted then inside quotes put  ;LL1;###;UL1;####"  the ## is the upper and lower variable limits nagative values ok 
                                                                                                        //only 6 charting varable allowed, ie LL1, UL1 to LL6, UL6
#define WATCH_VARIABLE_1_TYPE " put variabel type ie unsigned int, boolean, float etc
#define WATCH_VARIABLE_1 Variable name , not in quotes, if the variable is not a golbal ie local a temperary global variable wil have to be used and the local variable will have to be passed in code to this 
                                                                                        Temp variable before call to breap point funtion. see under //temporary variable for local vaiable wtaching
 

*/

#ifndef BREAKPOINT_H
#define BREAKPOINT_H 1

//-----------------------------------------------------------
//Column 1
 
#define WATCH_VARIABLE_1_NAME "uiTestCounter;LL1;0;UL1;65535" //only 6 charting varable allowed, first number is minimun value ; 2nd is maximum value
#define WATCH_VARIABLE_1_TYPE unsigned int
#define WATCH_VARIABLE_1 uiTestCounter
// 
#define WATCH_VARIABLE_2_NAME "bTestCounter"
#define WATCH_VARIABLE_2_TYPE boolean
#define WATCH_VARIABLE_2 bTestCounter
//
#define WATCH_VARIABLE_3_NAME "fTestCounter;LL2;-500;UL2;500"
#define WATCH_VARIABLE_3_TYPE float
#define WATCH_VARIABLE_3 fTestCounter

//#define WATCH_VARIABLE_4_NAME ""
//#define WATCH_VARIABLE_4_TYPE unsigned int
//#define WATCH_VARIABLE_4 
//
//#define WATCH_VARIABLE_5_NAME ""
//#define WATCH_VARIABLE_5_TYPE unsigned int
//#define WATCH_VARIABLE_5 
//
////-----------------------------------------------------------
////Column 2

//#define WATCH_VARIABLE_6_NAME ""
//#define WATCH_VARIABLE_6_TYPE unsigned int
//#define WATCH_VARIABLE_6 
// 
//#define WATCH_VARIABLE_7_NAME ""
//#define WATCH_VARIABLE_7_TYPE unsigned int
//#define WATCH_VARIABLE_7 
//
//#define WATCH_VARIABLE_8_NAME ""
//#define WATCH_VARIABLE_8_TYPE unsigned int
//#define WATCH_VARIABLE_8 
//
//#define WATCH_VARIABLE_9_NAME ""
//#define WATCH_VARIABLE_9_TYPE unsigned int
//#define WATCH_VARIABLE_9 
//
//#define WATCH_VARIABLE_10_NAME ""
//#define WATCH_VARIABLE_10_TYPE unsigned int
//#define WATCH_VARIABLE_10 
//
////-----------------------------------------------------------
////Column 3
//#define WATCH_VARIABLE_11_NAME ""
//#define WATCH_VARIABLE_11_TYPE unsigned int
//#define WATCH_VARIABLE_11
// 
//#define WATCH_VARIABLE_12_NAME ""
//#define WATCH_VARIABLE_12_TYPE unsigned int
//#define WATCH_VARIABLE_12 
//
//#define WATCH_VARIABLE_13_NAME ""
//#define WATCH_VARIABLE_13_TYPE unsigned int
//#define WATCH_VARIABLE_13 
//
//#define WATCH_VARIABLE_14_NAME ""
//#define WATCH_VARIABLE_14_TYPE unsigned int
//#define WATCH_VARIABLE_14 
//
//#define WATCH_VARIABLE_15_NAME ""
//#define WATCH_VARIABLE_15_TYPE unsigned int
//#define WATCH_VARIABLE_15 
//
////-----------------------------------------------------------
////Column 4
//#define WATCH_VARIABLE_16_NAME ""
//#define WATCH_VARIABLE_16_TYPE unsigned int
//#define WATCH_VARIABLE_16
// 
//#define WATCH_VARIABLE_17_NAME ""
//#define WATCH_VARIABLE_17_TYPE unsigned int
//#define WATCH_VARIABLE_17 
//
//#define WATCH_VARIABLE_18_NAME ""
//#define WATCH_VARIABLE_18_TYPE unsigned int
//#define WATCH_VARIABLE_18 
//
//#define WATCH_VARIABLE_19_NAME ""
//#define WATCH_VARIABLE_19_TYPE unsigned int
//#define WATCH_VARIABLE_19 
//
//#define WATCH_VARIABLE_20_NAME ""
//#define WATCH_VARIABLE_20_TYPE unsigned int
//#define WATCH_VARIABLE_20 


#include "MyWEBserver.h"

//temporary variable for local vaiable wtaching
 unsigned int BP_uiTempVariable1; 

 //extern variable you what to watch except locals 
#ifdef  WATCH_VARIABLE_1
extern WATCH_VARIABLE_1_TYPE WATCH_VARIABLE_1;
#endif
#ifdef  WATCH_VARIABLE_2
extern WATCH_VARIABLE_2_TYPE WATCH_VARIABLE_2;
#endif
#ifdef  WATCH_VARIABLE_3
extern WATCH_VARIABLE_3_TYPE WATCH_VARIABLE_3;
#endif
#ifdef  WATCH_VARIABLE_4
extern WATCH_VARIABLE_4_TYPE WATCH_VARIABLE_4;
#endif
#ifdef  WATCH_VARIABLE_5
extern WATCH_VARIABLE_5_TYPE WATCH_VARIABLE_5;
#endif
#ifdef  WATCH_VARIABLE_6
extern WATCH_VARIABLE_6_TYPE WATCH_VARIABLE_6;
#endif
#ifdef  WATCH_VARIABLE_7
extern WATCH_VARIABLE_7_TYPE WATCH_VARIABLE_7;
#endif
#ifdef  WATCH_VARIABLE_8
extern WATCH_VARIABLE_8_TYPE WATCH_VARIABLE_8;
#endif
#ifdef  WATCH_VARIABLE_9
extern WATCH_VARIABLE_9_TYPE WATCH_VARIABLE_9;
#endif
#ifdef  WATCH_VARIABLE_10
extern WATCH_VARIABLE_10_TYPE WATCH_VARIABLE_10;
#endif
#ifdef  WATCH_VARIABLE_11
extern WATCH_VARIABLE_11_TYPE WATCH_VARIABLE_11;
#endif
#ifdef  WATCH_VARIABLE_12
extern WATCH_VARIABLE_12_TYPE WATCH_VARIABLE_12;
#endif
#ifdef  WATCH_VARIABLE_13
extern WATCH_VARIABLE_13_TYPE WATCH_VARIABLE_13;
#endif
#ifdef  WATCH_VARIABLE_14
extern WATCH_VARIABLE_14_TYPE WATCH_VARIABLE_14;
#endif
#ifdef  WATCH_VARIABLE_15
extern WATCH_VARIABLE_15_TYPE WATCH_VARIABLE_15;
#endif
#ifdef  WATCH_VARIABLE_16
extern WATCH_VARIABLE_16_TYPE WATCH_VARIABLE_16;
#endif
#ifdef  WATCH_VARIABLE_17
extern WATCH_VARIABLE_17_TYPE WATCH_VARIABLE_17;
#endif
#ifdef  WATCH_VARIABLE_18
extern WATCH_VARIABLE_18_TYPE WATCH_VARIABLE_18;
#endif
#ifdef  WATCH_VARIABLE_19
extern WATCH_VARIABLE_19_TYPE WATCH_VARIABLE_19;
#endif
#ifdef  WATCH_VARIABLE_20
extern WATCH_VARIABLE_20_TYPE WATCH_VARIABLE_20;
#endif
  

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
  
 strWSVR_VariableNames = String(strDebug_OnOff) + ";" + String(strHaltContinous) + ";" + String("BPN") + ";" + String("CC") + ";"

#ifdef WATCH_VARIABLE_1_NAME
                       + String("WV01") + ";" + String(WATCH_VARIABLE_1_NAME) + ";" 
#endif 
#ifdef WATCH_VARIABLE_2_NAME
                       + String("WV02") + ";" + String(WATCH_VARIABLE_2_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_3_NAME
                       + String("WV03") + ";" + String(WATCH_VARIABLE_3_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_4_NAME
                       + String("WV04") + ";" + String(WATCH_VARIABLE_4_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_5_NAME
                       + String("WV05") + ";" + String(WATCH_VARIABLE_5_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_6_NAME
                       + String("WV06") + ";" + String(WATCH_VARIABLE_6_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_7_NAME
                       + String("WV07") + ";" + String(WATCH_VARIABLE_7_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_8_NAME
                       + String("WV08") + ";" + String(WATCH_VARIABLE_8_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_9_NAME
                       + String("WV09") + ";" + String(WATCH_VARIABLE_9_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_10_NAME
                       + String("WV10") + ";" + String(WATCH_VARIABLE_10_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_11_NAME
                       + String("WV11") + ";" + String(WATCH_VARIABLE_11_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_12_NAME
                       + String("WV12") + ";" + String(WATCH_VARIABLE_12_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_13_NAME
                       + String("WV13") + ";" + String(WATCH_VARIABLE_13_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_14_NAME
                       + String("WV14") + ";" + String(WATCH_VARIABLE_14_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_15_NAME
                       + String("WV15") + ";" + String(WATCH_VARIABLE_15_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_16_NAME
                       + String("WV16") + ";" + String(WATCH_VARIABLE_16_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_17_NAME
                       + String("WV17") + ";" + String(WATCH_VARIABLE_17_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_18_NAME
                       + String("WV18") + ";" + String(WATCH_VARIABLE_18_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_19_NAME
                       + String("WV19") + ";" + String(WATCH_VARIABLE_19_NAME) + ";" 
#endif
#ifdef WATCH_VARIABLE_20_NAME
                       + String("WV20") + ";" + String(WATCH_VARIABLE_20_NAME) + ";" 
#endif                      
                       + String("END"); 

}        

void WSVR_BreakPoint(unsigned char ucBPindex)
{
 
  if(bWSVR_DebugOfOff)
  {
 strWSVR_VariableData = String("BPD") + ";" + String("CC") + ";"

#ifdef WATCH_VARIABLE_1_NAME
                       + String(WATCH_VARIABLE_1) + ";" 
#endif 
#ifdef WATCH_VARIABLE_2_NAME
                       + String(WATCH_VARIABLE_2) + ";" 
#endif
#ifdef WATCH_VARIABLE_3_NAME
                       + String(WATCH_VARIABLE_3) + ";" 
#endif
#ifdef WATCH_VARIABLE_4_NAME
                       + String(WATCH_VARIABLE_4) + ";" 
#endif
#ifdef WATCH_VARIABLE_5_NAME
                       + String(WATCH_VARIABLE_5) + ";" 
#endif
#ifdef WATCH_VARIABLE_6_NAME
                       + String(WATCH_VARIABLE_6) + ";" 
#endif
#ifdef WATCH_VARIABLE_7_NAME
                       + String(WATCH_VARIABLE_7) + ";" 
#endif
#ifdef WATCH_VARIABLE_8_NAME
                       + String(WATCH_VARIABLE_8) + ";" 
#endif
#ifdef WATCH_VARIABLE_9_NAME
                       + String(WATCH_VARIABLE_9) + ";" 
#endif
#ifdef WATCH_VARIABLE_10_NAME
                       + String(WATCH_VARIABLE_10) + ";" 
#endif
#ifdef WATCH_VARIABLE_11_NAME
                       + String(WATCH_VARIABLE_11) + ";" 
#endif
#ifdef WATCH_VARIABLE_12_NAME
                       + String(WATCH_VARIABLE_12) + ";" 
#endif
#ifdef WATCH_VARIABLE_13_NAME
                       + String(WATCH_VARIABLE_13) + ";" 
#endif
#ifdef WATCH_VARIABLE_14_NAME
                       + String(WATCH_VARIABLE_14) + ";" 
#endif
#ifdef WATCH_VARIABLE_15_NAME
                       + String(WATCH_VARIABLE_15) + ";" 
#endif
#ifdef WATCH_VARIABLE_16_NAME
                       + String(WATCH_VARIABLE_16) + ";" 
#endif
#ifdef WATCH_VARIABLE_17_NAME
                       + String(WATCH_VARIABLE_17) + ";" 
#endif
#ifdef WATCH_VARIABLE_18_NAME
                       + String(WATCH_VARIABLE_18) + ";" 
#endif
#ifdef WATCH_VARIABLE_19_NAME
                       + String(WATCH_VARIABLE_19) + ";" 
#endif
#ifdef WATCH_VARIABLE_20_NAME
                       + String(WATCH_VARIABLE_20) + ";" 
#endif                      
                       + String("END"); 
    
    if(bWSVR_HaltContinuous == false)
    {
     bWSVR_Halted = true;
       
     if((ucBPindex != 0)  && (ucBPindex < 5))
     { 
       strWSVR_VariableData.setCharAt(4,'H'); 
       strWSVR_VariableData.setCharAt(5,(0x30 + ucBPindex));
       while(bWSVR_Halted)
       {
                 
         WSVR_ButtonResponce();
         if((bWSVR_DebugOfOff == false) || (bWSVR_HaltContinuous))
         {
          break;
         }
       }
     }
            
     
     strWSVR_VariableData.setCharAt(4,'C');       
     strWSVR_VariableData.setCharAt(5,'C'); 
    }
    
   
   }
  
}











#endif
