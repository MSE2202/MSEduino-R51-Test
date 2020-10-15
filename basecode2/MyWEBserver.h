/*
//Western Engineering base code 
March 21,2020
  
\WEB server code


*/

#ifndef MYWEBSERVER_H
#define MYWEBSERVER_H 1


#include "BreakPointWEBPage.h"
#include <ESPAsyncWebServer.h>

#include <WebSocketsServer.h>

void WSVR_ButtonResponse(void);


// Replace with your network credentials
const char *ssid = "BaseC2";
const char *password = "12345678";  //must be 8 characters long

uint8_t u8WSVR_WEBSocketID;

IPAddress local_ip(192,168,128,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

AsyncWebServer server(80);
WebSocketsServer webSocket(81); 



  boolean bWSVR_DebugOfOff = false;
  boolean bWSVR_HaltContinuous = false;
  boolean bWSVR_Halted = false;
  
   unsigned char ucWSVR_ButtonState = 9;

  unsigned char ucWSVR_WEBSocketConnected = 0;
 
  String strWSVR_ButtonState = "0";

  String strWSVR_VariableNames;
  String strWSVR_VariableData;

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) 
{ // When a WebSocket message is received

  u8WSVR_WEBSocketID = num;
  switch (type) 
  {
    case WStype_DISCONNECTED:             // if the websocket is disconnected
    {
      Serial.printf("[%u] Disconnected!\n", num);
      ucWSVR_WEBSocketConnected = 0;
      break;
    }
    case WStype_CONNECTED:
    {              // if a new websocket connection is established
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
        ucWSVR_WEBSocketConnected = 1;
        break;        
    }
      
    case WStype_TEXT:                     // if new text data is received
    {
     
      
      switch(payload[0])
      {
        case 'P':
        {
          
          strWSVR_ButtonState = payload[1];
          Serial.print("P");
          Serial.printf("%c",payload[1]);
          Serial.println("");
          WSVR_ButtonResponse();
          break;
        }
        case 'L':
        {
          
          webSocket.sendTXT(u8WSVR_WEBSocketID, strWSVR_VariableNames);
          break;
        }
         
      }
     break;
    }
    case WStype_BIN:
    {
      Serial.print("b");
      break;
    }
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
    {
      Serial.print("O");
      break;
    }
  }
}


void WSVR_setupWEbServer(void)
{
  
  Serial.print(F("Configuring access point..."));

  
  Serial.print(F("Connecting to "));
  Serial.println(ssid);
  
  WiFi.persistent(false);
  WiFi.softAP(ssid, password);
   delay(2000);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(1000);
  
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print(F("AP IP address: "));
  Serial.println(myIP);
  
  
 server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(200, "text/html", BreakPoint_page);

  });
    
 
    
  webSocket.begin();                          // start the websocket server
  webSocket.onEvent(webSocketEvent);  
  Serial.println("WebSocket server started.");
  
  
  server.begin();
  Serial.println(F("HTTP server started"));
  //turn off wifi for now it adds time to execution
//  WiFi.mode(WIFI_OFF);
//  btStop();

  Serial.println(F(""));
}


void WSVR_SendMsg(String strText)
{
  if(ucWSVR_WEBSocketConnected)
  {
     webSocket.sendTXT(u8WSVR_WEBSocketID, strText);
  }
 
}

void WSVR_ButtonResponse(void)
{
   ucWSVR_ButtonState = strWSVR_ButtonState.toInt();
   
    switch(ucWSVR_ButtonState)
    {
      case 'o':
       {
       Serial.println("DebugOn");
       strWSVR_ButtonState = "";
       bWSVR_DebugOfOff = true;
       break;
      }
      case 'f':
      {
       Serial.println("DebugOff");
       bWSVR_DebugOfOff = false;
       strWSVR_ButtonState = "";
       break;
      }
      case 'h':
      {
        
       Serial.println("Halt");
        strWSVR_ButtonState = "";
        bWSVR_HaltContinuous = false;
        break;
      }
      case 'c':
      {
      
       Serial.println("Continuous");
       strWSVR_ButtonState = "";
       bWSVR_HaltContinuous = true;
        break;
      }

      case 't':  //continue from BP halt
      {
        Serial.println("UnHalt");
        bWSVR_Halted = false;
        strWSVR_ButtonState = "";
        strWSVR_VariableData.replace("HH", "GG");
       
        break;
      }
      case 'g': 
      {
        
        strWSVR_ButtonState = "";
       
       
        break;
      }
      case 's':
      {
        
        strWSVR_ButtonState = "";
        break;
      }
     
        
       
    }

}

#endif
