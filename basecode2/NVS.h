/*
Western Engineering base code
2020 05 13 E J Porter

  
\Non volitile storeage (EEPROM)



•  User inputs
• BPM – 5 to 30 (in 1 BPM steps) 
• I:E – 1:1, 1;2, 1:3, 1:4 shown on display as 0.5, 0.33, 0.25, 0.2 

• maximum/maximum minute ventilation (Ve) 
       o prototype setting - 1.5 to 21.9L  
• TV – 100 to 900 (in steps 10) 
      o  tidal volume 
      o Adult - 6-8 ml/kg body weight, 200-750 mL typical
      o Only for adults > 40 kg
• Limit maximum pressure (MP) (0- 60.0) 
• Positive end-expiratory pressure (PEEP) (0-60.0) 
• startup run from 10 to 60 seconds (RT)


*/
#ifndef NVS_H
  #define NVS_H 1
  
#include "EEPROM.h"



#define NVS_EEPROM_SIZE 32
#define NVS_CRC 0
#define NVS_ADR_BPM 0
#define NVS_ADR_IE 2
#define NVS_ADR_VE 4
#define NVS_ADR_TV 6
#define NVS_ADR_MP 8
#define NVS_ADR_PEEP 10
#define NVS_ADR_RT 12

EEPROMClass  NCS_CRC("eeprom0",2); 
EEPROMClass  NVS1("eeprom1",32);
EEPROMClass  NVS2("eeprom2",32);

unsigned char NVS_uc_Error;
unsigned char NVS_ucTempRead;
unsigned int NVS_uiCRC; 
unsigned int NVS_uiCRC_Temp; 


void NVS_Init()
{
  unsigned int uiForCounter;
  NVS_uc_Error = 0;
  if (!NCS_CRC.begin(NCS_CRC.length()))
  {
   NVS_uc_Error = 0x01;
  }
  if (!NVS1.begin(NVS1.length()))
  {
   NVS_uc_Error |= 0x02;
  }
  if (!NVS2.begin(NVS2.length())) 
  {
     NVS_uc_Error |= 0x04;
  }
  //checks CRC to  both Data sets
  // if both same unit starts in timed run mode unless Run Timre (RT)= 0 the start in set mode;
  // if one = crc data and one not start in set mode but run in run time 
  //if both not = to CRC then strat in setup mode
  if(NVS_uc_Error == 0)
  {
    NVS_uiCRC = NCS_CRC.readByte(NVS_CRC);
    NVS_uiCRC_Temp = 0;
    for (uiForCounter = 0; uiForCounter < NVS_EEPROM_SIZE; uiForCounter++)
    {
      NVS_uiCRC_Temp ^= NVS1.readByte(uiForCounter);
    }
    if(NVS_uiCRC_Temp != NVS_uiCRC)
    {
      NVS_uc_Error = 0x10;
    }
    NVS_uiCRC_Temp = 0;
    for (uiForCounter = 0; uiForCounter < NVS_EEPROM_SIZE; uiForCounter++)
    {
      NVS_uiCRC_Temp ^= NVS2.readByte(uiForCounter);
    }
    if(NVS_uiCRC_Temp != NVS_uiCRC)
    {
      NVS_uc_Error |= 0x20;
    }
  }
}

//Stores data when data is entered

void NVS_Store(unsigned char ucAddress,unsigned int uiData)
{

   NVS1.writeUShort(ucAddress, uiData);
}

//Commit NVS when the unit is locked or when put to sleep
//does a RAID commit over a few cycles
void NVS_Commit()
{
  unsigned int uiForCounter;

  NVS_uiCRC_Temp = 0;
  NVS1.commit();
  for (uiForCounter = 0; uiForCounter < NVS_EEPROM_SIZE; uiForCounter++)
    {
      NVS_ucTempRead = NVS1.readByte(uiForCounter);
      NVS2.writeByte(uiForCounter, NVS_ucTempRead);
      NVS_uiCRC_Temp ^= NVS_ucTempRead;
    }
  NVS2.commit();
  NCS_CRC.writeByte(NVS_CRC,NVS_uiCRC_Temp);
  
}




#endif
