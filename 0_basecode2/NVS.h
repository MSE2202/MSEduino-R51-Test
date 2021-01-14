/*
Western Engineering base code
2020 05 13 E J Porter

  
\Non volitile storeage (EEPROM)




*/
#ifndef NVS_H
  #define NVS_H 1
  
#include <EEPROM.h>

//DEBUG print
#define DEBUGEEPROM 1
#define DEBUGEEPROM2 1
#define DEBUGEEPROM_COMMIT 1

#define NVS_HEADER 0xAA
#define NVS_FOOTER 0x26

#define NVS_EEPROM_SIZE 32
#define NVS_Header 0
#define NVS_CRC_1 1
#define NVS_CRC_2 2
#define NVS_Footer 3



unsigned char NVS_Reverse(unsigned char crc);

EEPROMClass  NVS_CRCArea("eeprom0",4); 
EEPROMClass  NVS_Area1("eeprom1",NVS_EEPROM_SIZE);
EEPROMClass  NVS_Area2("eeprom2",NVS_EEPROM_SIZE);

boolean NVS_btEEpromArea1_2 = 0; //0 = area 1 ; 1 = area 2


unsigned char NVS_ucTempRead;
unsigned int NVS_uiCRC_1; 
unsigned int NVS_uiCRC_2;
unsigned int NVS_uiCRC_Temp; 
unsigned int NVS_uiCRC_Temp2;
unsigned int NVS_uiHeader; 
unsigned int NVS_uiFooter;
unsigned int NVS_uiForCounter;
unsigned int NVS_ui_Error;

unsigned char NVS_Init()
{
  
  NVS_btEEpromArea1_2 = 0;
  NVS_ui_Error = 0;
  //check to see if eeprom area exist
  if (!NVS_CRCArea.begin(NVS_CRCArea.length()))
  {
   NVS_ui_Error = 0x01;
  }
  if (!NVS_Area1.begin(NVS_Area1.length()))
  {
   NVS_ui_Error |= 0x02;
  }
  if (!NVS_Area2.begin(NVS_Area2.length())) 
  {
     NVS_ui_Error |= 0x04;
  }
  if(NVS_ui_Error == 0)
  {
  //check heater and footer ( footer is reversesand 2s ompoliment of header
  //Header = 0xAA
  //Footer = 0x26
   NVS_uiHeader = NVS_CRCArea.readByte(NVS_Header);
   NVS_uiFooter = NVS_CRCArea.readByte(NVS_Footer);
   if((NVS_uiHeader != NVS_HEADER) || (NVS_uiFooter != NVS_FOOTER))
   {
    NVS_ui_Error |= 0x08;
   }
  // check CRC for eeprom area 1 is = eeprom area 2
  // checks CRC againts both Data sets
  // if good then set RTC memory
  // not set up then start fresh
  //if corrupt then error message
  
  
    // check CRC for eeprom area 1 is = eeprom area 2
    NVS_uiCRC_1 = NVS_CRCArea.readByte(NVS_CRC_1);
    NVS_uiCRC_2 = NVS_CRCArea.readByte(NVS_CRC_2);
    //crc_2 in stored in revered bit and 2 complimented, need to undo
    NVS_uiCRC_Temp = NVS_uiCRC_2;
    NVS_uiCRC_Temp = ~NVS_uiCRC_Temp + 1;
    NVS_uiCRC_Temp2 = NVS_Reverse(NVS_uiCRC_Temp);
    #ifdef DEBUGEEPROM2
     Serial.println("");
     Serial.print("CRC 1 = ");
     Serial.println(NVS_uiCRC_1, HEX);
     Serial.print("CRC 2 raw = ");
     Serial.println(NVS_uiCRC_2, HEX);
     Serial.print("CRC 2 2comp = ");
     Serial.println(NVS_uiCRC_Temp, HEX);
     Serial.print("CRC 2 reversed = ");
     Serial.println(NVS_uiCRC_Temp2, HEX);
     
    #endif
    NVS_uiCRC_2 = NVS_uiCRC_Temp2;
    
    NVS_uiCRC_Temp = 0;
    for (NVS_uiForCounter = 0; NVS_uiForCounter < NVS_EEPROM_SIZE; NVS_uiForCounter++)
    {
      NVS_uiCRC_Temp ^= NVS_Area1.readByte(NVS_uiForCounter);
    }
     #ifdef DEBUGEEPROM2
     Serial.println("");
     Serial.print("CRC 1 chk ");
     Serial.print("CRC 1 = ");
     Serial.println(NVS_uiCRC_1, HEX);
     Serial.print("CRC 1 calc = ");
     Serial.println(NVS_uiCRC_Temp, HEX);
     
    #endif
    if(NVS_uiCRC_Temp != NVS_uiCRC_1) 
    {
      NVS_ui_Error |= 0x20;
    }
    NVS_uiCRC_Temp2 = 0;
    for (NVS_uiForCounter = 0; NVS_uiForCounter < NVS_EEPROM_SIZE; NVS_uiForCounter++)
    {
      NVS_uiCRC_Temp2 ^= NVS_Area2.readByte(NVS_uiForCounter);
    }
     #ifdef DEBUGEEPROM2
     Serial.println("");
     Serial.print("CRC 2 chk ");
     Serial.print("CRC 2 = ");
     Serial.println(NVS_uiCRC_2, HEX);
     Serial.print("CRC 2 calc = ");
     Serial.println(NVS_uiCRC_Temp2, HEX);
     
    #endif
    
    if(NVS_uiCRC_Temp2 != NVS_uiCRC_2)
    {
      NVS_ui_Error |= 0x40;
    }
    
    if((NVS_ui_Error & 0x02) && (NVS_uiCRC_Temp != NVS_uiCRC_Temp2))
    {
      NVS_ui_Error |= 0x200;
    }
    if((NVS_ui_Error & 0x04) && (NVS_uiCRC_Temp2 != NVS_uiCRC_Temp))
    {
      NVS_ui_Error |= 0x400;
    }
    if(NVS_uiCRC_1 != NVS_uiCRC_2)
    {
      NVS_ui_Error |= 0x10;
    }
    if((NVS_uiFooter == 0xFF) && (NVS_uiHeader == 0xFF) && (NVS_uiCRC_1 == 0xFF) && (NVS_uiCRC_2 == 0xFF))
    {
      NVS_ui_Error |= 0x80;
    } 
   }
  #ifdef DEBUGEEPROM
   if(NVS_ui_Error)
   {
    Serial.println("");
    Serial.print(" eeprom error = ");
    Serial.println(NVS_ui_Error,BIN);
    if(NVS_ui_Error & 0x07)
    {
      Serial.print("eeprom area not set: ");
      if(NVS_ui_Error & 0x01)
      {
        Serial.print(" CRC area, ");
      }
      if(NVS_ui_Error & 0x02)
      {
        Serial.print(" eeprom area 1, ");
      }
      if(NVS_ui_Error & 0x04)
      {
        Serial.print(" eeprom area 2, ");
      }
      Serial.println("");
      
    }
    if(NVS_ui_Error & 0x08)
    {
      Serial.println("");
      Serial.print(" Header/Footer is corrupt ");
      Serial.print(NVS_uiHeader,HEX);
      Serial.print("/");
      Serial.print(NVS_uiFooter,HEX);
      Serial.print(" not 0xAA/0x26 ");
    }
    if(NVS_ui_Error & 0xF0)
    {
      if(NVS_ui_Error & 0x10)
      {
        Serial.print(" CRCs don't match");
      }
      if(NVS_ui_Error & 0x20)
      {
        Serial.print(" area 1 data corrupt, CRC_1 !=. ");
      }
       if(NVS_ui_Error & 0x200)
      {
        Serial.print(" area 1 data corrupt, CRC_2 !=. ");
      }
      if(NVS_ui_Error & 0x40)
      {
        Serial.print(" area 2 data corrupt, CRC_2 !=. ");
      }
      if(NVS_ui_Error & 0x400)
      {
        Serial.print(" area 2 data corrupt, CRC_1 !=. ");
      }
      Serial.println("");
     if(NVS_ui_Error & 0x80)
      {
        Serial.println(" Most likely new micro not data saved yet");
      } 
    }
    if((NVS_ui_Error & 0x220) && (!(NVS_ui_Error & 0x040) && (!(NVS_ui_Error & 0x0400))))
    {
      NVS_btEEpromArea1_2 = 1; //use area 2
    }
   }
   else
   {
     Serial.println("");
     Serial.println(" eeprom error = ");
     Serial.println(NVS_ui_Error);
   }
  #endif
  return(NVS_ui_Error);
}

uint8_t NVS_ReadUChar(unsigned int uiAddress) //one byte
{
  if(NVS_btEEpromArea1_2)
  {
   return(NVS_Area2.readUChar(uiAddress));
  }
  else
  {
   return(NVS_Area2.readUChar(uiAddress));
  }
}

uint16_t NVS_ReadUInt(unsigned  int uiAddress)//2 byte
{
  if(NVS_btEEpromArea1_2)
  {
   return(NVS_Area2.readUShort(uiAddress));
  }
  else
  {
   return(NVS_Area1.readUShort(uiAddress));
  }
}

uint32_t NVS_ReadULong(unsigned  int uiAddress)//4 bytes
{
  if(NVS_btEEpromArea1_2)
  {
   return(NVS_Area2.readULong(uiAddress));
  }
  else
  {
   return(NVS_Area1.readULong(uiAddress));
  }
}

int32_t NVS_ReadLong(unsigned  int uiAddress)//4 bytes
{
  if(NVS_btEEpromArea1_2)
  {
   return(NVS_Area2.readLong(uiAddress));
  }
  else
  {
   return(NVS_Area1.readLong(uiAddress));
  }
}

double_t NVS_ReadDouble(unsigned  int uiAddress)//8 bytes
{
  if(NVS_btEEpromArea1_2)
  {
   return(NVS_Area2.readDouble(uiAddress));
  }
  else
  {
   return(NVS_Area1.readDouble(uiAddress));
  }
}

void NVS_StoreUChar(unsigned  int uiAddress,uint8_t ucData)
{
   Serial.println();
   Serial.print(" d = ");
   Serial.print(ucData);
   Serial.print("  @ ");
   Serial.println(uiAddress);
   
   NVS_Area1.writeUChar(uiAddress, ucData);
}

void NVS_StoreUInt(unsigned  int uiAddress,uint16_t uiData)
{

   NVS_Area1.writeUShort(uiAddress, uiData);
}

void NVS_StoreULong(unsigned  int uiAddress,uint32_t ulData)
{

   NVS_Area1.writeULong(uiAddress, ulData);
}

void NVS_StoreLong(unsigned  int uiAddress,int32_t lData)
{

   NVS_Area1.writeLong(uiAddress, lData);
}

void NVS_StoreDouble(unsigned  int uiAddress,double_t dData)
{
  
  NVS_Area1.writeDouble(uiAddress, dData);
  
}



//Commit Area 1 when the unit is when put to sleep/Shutdown
//does a RAID commit 
void NVS_Commit()
{
 
  NVS_uiCRC_Temp = 0;
  NVS_Area1.commit();
  for (NVS_uiForCounter = 0; NVS_uiForCounter < NVS_EEPROM_SIZE; NVS_uiForCounter++)
    {
      NVS_ucTempRead = NVS_Area1.readByte(NVS_uiForCounter);
      NVS_Area2.writeByte(NVS_uiForCounter, NVS_ucTempRead);
      NVS_uiCRC_Temp ^= NVS_ucTempRead;
    }
  NVS_Area2.commit();
  NVS_CRCArea.writeByte(NVS_Header,NVS_HEADER);
  NVS_CRCArea.writeByte(NVS_CRC_1,NVS_uiCRC_Temp);
  NVS_uiCRC_Temp =  NVS_Reverse(NVS_uiCRC_Temp);
  NVS_uiCRC_Temp = ~NVS_uiCRC_Temp + 1;
  NVS_CRCArea.writeByte(NVS_CRC_2,NVS_uiCRC_Temp);
  NVS_CRCArea.writeByte(NVS_Footer,NVS_FOOTER);
  NVS_CRCArea.commit();
  
}

unsigned char NVS_Reverse(unsigned char crc)
{
   crc = (crc & 0xF0) >> 4 | (crc & 0x0F) << 4;
   crc = (crc & 0xCC) >> 2 | (crc & 0x33) << 2;
   crc = (crc & 0xAA) >> 1 | (crc & 0x55) << 1;
   return crc;
}


#endif
