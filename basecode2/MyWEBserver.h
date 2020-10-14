/*
//Western Engineering base code 
March 21,2020
  
\WEB server code


*/

#ifndef MYWEBSERVER_H
#define MYWEBSERVER_H 1



#include <ESPAsyncWebServer.h>

#include <WebSocketsServer.h>

void WSVR_ButtonResponse(void);

bool btWS_Fellover = true;

// Replace with your network credentials
const char *ssid = "BaseC2";
const char *password = "12345678";  //must be 8 characters long



IPAddress local_ip(192,168,128,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

AsyncWebServer server(80);
WebSocketsServer webSocket(81); 


 
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

 <head>
  <meta charset="utf-8">
  <title>Wifi Debug R1</title>
  <link rel="shortcut icon" href="#"/>
 </head>



<style>
:root {
  --main-bg-color: gray;
  
}
html {
  margin: 0;
  padding: 0;
  
}

body{ 
    width: 80%;
    margin: 0 auto;
    <!---font: 100% Arial, Helvetica, sans-serif;--->
    padding: 1em 1em;
    background: white;
    
    }
.form input {
    position: absolute;
    left: -9999px;
}


.Setup{
  position:absolute;
  
  top:1%;
  left:10%;
  height:80%;
  width:80%;
  background:white;
}


.DebugOn{
  position:absolute;
  
  top:1%;
  left:10%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#DebugOn:checked + .DebugOn{
 background: green;   
}

.DebugOn:after {
     margin: 0;
    position: absolute;
    top: 50%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Debug - On';
    color: white;
}

.DebugOff{
  position:absolute;
  
  top:1%;
  left:31%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#DebugOff:checked + .DebugOff{
 background: green;   
}



.DebugOff:after {
     margin: 0;
    position: absolute;
    top: 50%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Debug - Off';
    color: white;
}


.Halt{
  position:absolute;
  
  top:1%;
  left:54%;
  height:5%;
  width:20%;
  background:red;
}

#Halt:checked + .Halt{
 background: green;   
}

.Halt:after {
    margin: 0;
    position: absolute;
    top: 50%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Halt Mode';
    color: white;
      
}

.Continuous{
  position:absolute;
  
  top:1%;
  left:75%;
  height:5%;
  width:20%;
  background:red;
}

#Continuous:checked + .Continuous{
 background: green;   
}


.Continuous:after {
    margin: 0;
    position: absolute;
    top: 50%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Continuous Mode';
    color: white;
      
}


.Table1 {
  position:absolute;
  top:8%;
  left:10%;
  height:70%;
}


table, th, td {
  border: 1px solid black;
  border-collapse: collapse;
  width:95%;
  font: Arial, Helvetica, sans-serif;
  font-weight: bold;
  font-size: 1vmax;
  
  table-layout: fixed;
}
th, td {
  padding: 15px;
  text-align: left;
  
}
table#DP02 tr:nth-child(even) {
  background-color: #eee;
}

table#DP02 tr:nth-child(even) {
  background-color: #eee;
}
table#DP02 tr:nth-child(odd) {
 background-color: #fff;
}
table#DP02 th {
  background-color: grey;
  color: white;
}
table#DP01 th {
  background-color: grey;
  color: white;
}


.Datum{
  position:absolute;
  top:84%;
  left:10%;
  font: 100% Arial, Helvetica, sans-serif;
  font-weight: bold;
}




</style>

<body>
 

 <div class="form">
  <div>
    <input type="radio" onclick="sendData(0)" id="DebugOn" value="1" name="DebugOnOff" checked />
    <label class="DebugOn" for="DebugOn"></label>
  
  </div>
  <div>
    <input type="radio" onclick="sendData(1)" id="DebugOff" value="0" name="DebugOnOff" checked />
    <label class="DebugOff" for="DebugOff"></label>
  </div>

  <div>
    <input type="radio" onclick="sendData(2)" id="Halt" value="2" name="HaltContinuous" checked/>
    <label class="Halt" for="Halt"></label>
  
  </div>
  <div>
    <input type="radio" onclick="sendData(3)" id="Continuous" value="3" name="HaltContinuous" unchecked />
    <label class="Continuous" for="Continuous"></label>
  </div>
 <div>
  
  

  <div>
  <label class = "Table1">
    <table id="DP01" onclick="sendData(4)" >
      <tr>
        <th name = WatchHeader colspan="2" style= "text-align: center;">   Debug Point 1</th>
        <th name = WatchHeader colspan="2" style= "text-align: center;">   Debug Point 2</th>
        <th name = WatchHeader colspan="2" style= "text-align: center;">   Debug Point 3</th>
        <th name = WatchHeader colspan="2" style= "text-align: center;">   Debug Point 4</th>
        <th name = WatchHeader colspan="2" style= "text-align: center;">   Debug Point 5</th>
      </tr>
     </table> 
     <br>
     
     <table id="DP02">
      <tr>
        <th>Var Name</th> 
        <th>Data</th> 
        <th>Var Name</th> 
        <th>Data</th> 
        <th>Var Name</th> 
        <th>Data</th> 
        <th>Var Name</th> 
        <th>Data</th> 
       
        
      </tr>
      <tr>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
       
        
        
      </tr>
      <tr>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
       
      </tr>
      <tr>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
       
      </tr>
      <tr>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
       
      </tr>
      <tr>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
        <td name = WatchName style= "word-wrap:break-word;"> Empty</td>
        <td name = WatchData style= "word-wrap:break-word;"></td>
       
      </tr>
    </table>  
     
    <br>
    <canvas id="myCanvas"  onclick="sendData(5)" style="border:1px solid #d3d3d3;">
        Your browser does not support the HTML5 canvas tag.
    </canvas>
  </label>    
  </div>
</div>

<script>
  
 var c = document.getElementById("myCanvas");
 var ctx = c.getContext("2d");
 var XAxis =  -2;
 var XAxisPrevious =  -2;
 var YAxis = [0,0,0,0,0,0];
 var YAxisPrevious = [0,0,0,0,0,0];
 var ChartLowerLimits = [0,0,0,0,0,0];
 var ChartUpperLimits = [0,0,0,0,0,0];
 var ChartWatchIndex = [9,9,9,9,9,9];
 var ChartVariableIndex;
 var UpperLowerLimit;
 var canWidth = 0;
 var canHeight = 0;
 var ChartForCount;
 var WVN = document.getElementsByName("WatchName")
 var WVH = document.getElementsByName("WatchHeader")
 var WVD = document.getElementsByName("WatchData");
 var WatchCommandIndex = 0;
 var WatchVariableIndex = 21;
 var WatchColumHaltedAt = 6;
 var WatchIndexer = 0;
 var DebugOnOff = false;
 var HaltContin = false; 
 var colors = ["red",   "green",   "blue",   "yellow",   "orange", "black"];
 
 var counttmr = 0;
 ctx.moveTo(0,0);
 ctx.canvas.width = window.innerWidth* 0.85;
 ctx.canvas.height = window.innerHeight* 0.3;
 canWidth = ctx.canvas.width;
 canHeight = ctx.canvas.height;


var connection = new WebSocket('ws://' + location.hostname + ':81/', ['arduino']);
connection.onopen = function () {
  connection.send('Connect ' + new Date());
  //alert("WebSocket is supported by your Browser!");
};
connection.onerror = function (error) { console.log('WebSocket Error ', error);};
connection.onmessage = function (e) { onMessage(e)};
connection.onclose = function () { console.log('WebSocket connection closed');};


// Called when a message is received from the server
function onMessage(e) 
{
  var vWorkingData;
    // Print out our received message
    console.log("Received: " + e.data);
    vWorkingData = (e.data).split(";");
   if(vWorkingData[0] == "N#^")
   {
    getNames();
   }
}

 
 //ctx.beginPath();
 // getNames();
 sendData(6);   //load graph/chart with names for debugging
 
function getNames(e) 
{
 //// var xhttp = new XMLHttpRequest();
  var vWorkingName;
 
 // xhttp.onreadystatechange = function() 
//  {
//    if (this.readyState == 4 && this.status == 200)
//    {
     vWorkingName = (e.data).split(";");
     if(vWorkingName.length > 1)
     {
       for (WatchIndexer=0;WatchIndexer<vWorkingName.length;WatchIndexer++)  
       {
         if(WatchCommandIndex == 5)
         {
          ChartLowerLimits[ChartVariableIndex] = parseFloat(vWorkingName[WatchIndexer]);
          WatchCommandIndex = 0;
         }

         if(WatchCommandIndex == 6)
         {
          ChartUpperLimits[ChartVariableIndex] = parseFloat(vWorkingName[WatchIndexer]);
          WatchCommandIndex = 0;
         }

         if(WatchCommandIndex >10)  // load varaible names
         {

           
           WVN[WatchVariableIndex].innerHTML = vWorkingName[WatchIndexer];
           WatchCommandIndex = 0;
          
         }
        if(vWorkingName[WatchIndexer] == "DBON")
         {
           WatchCommandIndex = 0;
           WatchVariableIndex = 0;
           document.getElementById("DebugOn").checked = true;
           DebugOnOff = true;
         }
         if(vWorkingName[WatchIndexer] == "DBOF")
         {
           WatchCommandIndex = 0;
           WatchVariableIndex = 0;
       document.getElementById("DebugOn").checked = false;
           DebugOnOff = false;
         }
         if(vWorkingName[WatchIndexer] == "HALT")
         {
           WatchCommandIndex = 0;
           WatchVariableIndex = 0;
           document.getElementById("Halt").checked = false;
           HaltContin = false;
         }
         if(vWorkingName[WatchIndexer] == "CONT")
         {
           WatchCommandIndex = 0;
           WatchVariableIndex = 0;
           document.getElementById("Continuous").checked = true;
           HaltContin = true;
         }
         if(vWorkingName[WatchIndexer] == "BPN")
         {
          WatchCommandIndex = 0;
          WatchVariableIndex = 0;
         }
         if(vWorkingName[WatchIndexer] == "NN")
         {
           WatchCommandIndex = 0;
           WatchVariableIndex = 0;
           
         }
         if(vWorkingName[WatchIndexer] == "LL1")
         {
           WatchCommandIndex = 5;
           ChartWatchIndex[0] = WatchVariableIndex;
           WVN[WatchVariableIndex].style.backgroundColor = "red";
           WVN[WatchVariableIndex].style.color = "white";
           ChartVariableIndex = 0;
           UpperLowerLimit = 0;
         }
         if(vWorkingName[WatchIndexer] == "LL2")
         {
           WatchCommandIndex = 5;
           ChartWatchIndex[1] = WatchVariableIndex;
           WVN[WatchVariableIndex].style.backgroundColor = "green";
           WVN[WatchVariableIndex].style.color = "white";
           ChartVariableIndex = 1;
           UpperLowerLimit = 0;
         }
         if(vWorkingName[WatchIndexer] == "LL3")
         {
           WatchCommandIndex = 5;
           ChartWatchIndex[2] = WatchVariableIndex;
           WVN[WatchVariableIndex].style.backgroundColor = "blue";
           ChartVariableIndex = 2;
           UpperLowerLimit = 0;
         }
         if(vWorkingName[WatchIndexer] == "LL4")
         {
           WatchCommandIndex = 5;
           ChartWatchIndex[3] = WatchVariableIndex;
           WVN[WatchVariableIndex].style.backgroundColor = "yellow";
           ChartVariableIndex = 3;
           UpperLowerLimit = 0;
         }
         if(vWorkingName[WatchIndexer] == "LL5")
         {
           WatchCommandIndex = 5;
           ChartWatchIndex[4] = WatchVariableIndex;
           WVN[WatchVariableIndex].style.backgroundColor = "orange";
           ChartVariableIndex = 4;
           UpperLowerLimit = 0;
         }
         if(vWorkingName[WatchIndexer] == "LL6")
         {
           WatchCommandIndex = 5;
           ChartWatchIndex[5] = WatchVariableIndex;
           WVN[WatchVariableIndex].style.backgroundColor = "black";
           WVN[WatchVariableIndex].style.color = "white";
           
           ChartVariableIndex = 5;
           UpperLowerLimit = 0;
         }
         
         
         if(vWorkingName[WatchIndexer] == "UL1")
         {
           WatchCommandIndex = 6;
           
           ChartVariableIndex = 0;
           UpperLowerLimit = 1;
         }
         if(vWorkingName[WatchIndexer] == "UL2")
         {
           WatchCommandIndex = 6;
           
           ChartVariableIndex = 1;
           UpperLowerLimit = 1;
         }
         if(vWorkingName[WatchIndexer] == "UL3")
         {
           WatchCommandIndex = 6;
          
           ChartVariableIndex = 2;
           UpperLowerLimit = 1;
         }
         if(vWorkingName[WatchIndexer] == "UL4")
         {
           WatchCommandIndex = 6;
           
           ChartVariableIndex = 3;
           UpperLowerLimit = 1;
         }
         if(vWorkingName[WatchIndexer] == "UL5")
         {
           WatchCommandIndex = 6;
           
           ChartVariableIndex = 4;
           UpperLowerLimit = 1;
         }
         if(vWorkingName[WatchIndexer] == "UL6")
         {
           WatchCommandIndex = 6;
           
           ChartVariableIndex = 5;
           UpperLowerLimit = 1;
         }

         if(vWorkingName[WatchIndexer] == "WV01")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 0;
         }
         if(vWorkingName[WatchIndexer] == "WV02")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 1;
         }
         if(vWorkingName[WatchIndexer] == "WV03")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 2;
         }
         if(vWorkingName[WatchIndexer] == "WV04")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 3;
         }
         if(vWorkingName[WatchIndexer] == "WV05")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 4;
         }
         if(vWorkingName[WatchIndexer] == "WV06")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 5;
         }
         if(vWorkingName[WatchIndexer] == "WV07")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 6;
         }
         if(vWorkingName[WatchIndexer] == "WV08")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 7;
         }
         if(vWorkingName[WatchIndexer] == "WV09")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 8;
         }
         if(vWorkingName[WatchIndexer] == "WV10")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 9;
         }
         if(vWorkingName[WatchIndexer] == "WV11")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 10;
         }
         if(vWorkingName[WatchIndexer] == "WV12")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 11;
         }
         if(vWorkingName[WatchIndexer] == "WV13")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 12;
         }
         if(vWorkingName[WatchIndexer] == "WV14")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 13;
         }
         if(vWorkingName[WatchIndexer] == "WV15")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 14;
         }
         if(vWorkingName[WatchIndexer] == "WV16")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 15;
         }
         if(vWorkingName[WatchIndexer] == "WV17")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 16;
         }
         if(vWorkingName[WatchIndexer] == "WV18")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 17;
         }
         if(vWorkingName[WatchIndexer] == "WV19")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 18;
         }
         if(vWorkingName[WatchIndexer] == "WV20")
         {
           WatchCommandIndex = 11;
           WatchVariableIndex = 19;
         }

        

       }
     }
  
   // }
  //};


  xhttp.open("GET", "LN", true);
  xhttp.send();
 }
   
function sendData(ButtonPressed)
{

  //To send data to server

  switch(ButtonPressed)
  {
    case 0:
    {
      if (DebugOnOff == false)
      {
        connection.send("Po"); 
        DebugOnOff = true;
      }
      break;
    }
    case 1:
    {
      if (DebugOnOff == true)
      {
        connection.send("Pf");
        DebugOnOff = false;
      }
      break;
    }
    case 2:
    {
      if (HaltContin == true)
      {
        connection.send("Ph");
        HaltContin = false;
      }
      break;
    }
    case 3:
    {
      if (HaltContin == false)
      {
        connection.send("Pc");
        HaltContin = true;
      }
      break;
    }
    case 4:
    {
      if (WatchColumHaltedAt < 6)
      {
        connection.send("Pt");
        if(WatchColumHaltedAt < 5)
        {
          WVH[WatchColumHaltedAt].style.backgroundColor = "grey";
        }
        WatchColumHaltedAt = 6;
      }
      break;
    }
    case 6:
    {
      connection.send("L");
       
      break;
    }
  }
 
}

function Chartting()
{
  canWidth = Math.round(window.innerWidth* 0.85);
  canHeight = Math.round(window.innerHeight* 0.3);
  if((canHeight != ctx.canvas.height) || (canWidth != ctx.canvas.width))
  {
  ctx.canvas.width = canWidth;
  ctx.canvas.height = canHeight;
  XAxis = 0;
   
  
    
  }
  
  ctx.beginPath();
  ctx.lineWidth = "5";
  ctx.strokeStyle = "white";
  ctx.moveTo((XAxis+4),0);
  ctx.lineTo((XAxis+4),(canHeight + 1));
  ctx.stroke();
  
  
 
  
  XAxisPrevious = XAxis;
  XAxis = XAxis + 1;
  
  if(XAxis > canWidth)
  {
    XAxis = -2;
    XAxisPrevious = -2;
  
   ctx.moveTo(0,YAxisPrevious[0]);
   ctx.moveTo(1,YAxisPrevious[1]);
   ctx.moveTo(2,YAxisPrevious[2]);
   ctx.moveTo(3,YAxisPrevious[3]);
   ctx.moveTo(4,YAxisPrevious[4]);
   ctx.moveTo(5,YAxisPrevious[5]);
  }
  
  
  for (ChartForCount=0;ChartForCount<6;ChartForCount++)
  {
    ctx.beginPath();
    ctx.moveTo(XAxisPrevious,YAxisPrevious[ChartForCount]);
    ctx.strokeStyle = colors[ChartForCount%colors.length];
    ctx.lineWidth = 2;  
    ctx.lineTo(XAxis,YAxis[ChartForCount]);
    YAxisPrevious[ChartForCount] = YAxis[ChartForCount];
    ctx.stroke();
  }

}
 

function getData() 
{
  var xhttp = new XMLHttpRequest();
  var vWorkingData;
  var ConvertFromString;
  var Denominator = -50;
  

  xhttp.onreadystatechange = function() 
  {
    if (this.readyState == 4 && this.status == 200)
    {
     WatchCommandIndex = 0;
     vWorkingData = (this.responseText).split(";");
     if(vWorkingData.length > 1)
     {
      
       for (WatchIndexer=0;WatchIndexer<vWorkingData.length;WatchIndexer++)  
       {
         if(vWorkingData[WatchIndexer] == "BPD")
         {
          WatchCommandIndex = 1;
          WatchVariableIndex = 0;
         }
        
         if(vWorkingData[WatchIndexer] == "H1")
         {
           WatchCommandIndex = 2;
           WatchVariableIndex = 0;
           WVH[0].style.backgroundColor = "red";
           WatchColumHaltedAt = 0;
         }
         if(vWorkingData[WatchIndexer] == "H2")
         {
           WatchCommandIndex = 2;
           WatchVariableIndex = 0;
           WVH[1].style.backgroundColor = "red";
           WatchColumHaltedAt = 1;
         }
         if(vWorkingData[WatchIndexer] == "H3")
         {
           WatchCommandIndex = 2;
           WatchVariableIndex = 0;
           WVH[2].style.backgroundColor = "red";
           WatchColumHaltedAt = 2;
         }
         if(vWorkingData[WatchIndexer] == "H4")
         {
           WatchCommandIndex = 2;
           WatchVariableIndex = 0;
           WVH[3].style.backgroundColor = "red";
           WatchColumHaltedAt = 3;
         }
         if(vWorkingData[WatchIndexer] == "H5")
         {
           WatchCommandIndex = 2;
           WatchVariableIndex = 0;
           WVH[4].style.backgroundColor = "red";
           WatchColumHaltedAt = 4;
         }
         if(vWorkingData[WatchIndexer] == "END")
         {
           WatchCommandIndex = 0;
         }
         
         if(vWorkingData[WatchIndexer] == "CC")
         {
           WatchCommandIndex = 2;
           
         }
         if(WatchCommandIndex == 3)
         {
           WVD[WatchVariableIndex].innerHTML = vWorkingData[WatchIndexer];

           for (ChartVariableIndex=0;ChartVariableIndex<6;ChartVariableIndex++)  
           {
            if(WatchIndexer == 4)
            {
              WatchIndexer = 4;
             
            }
             if(ChartWatchIndex[ChartVariableIndex] == WatchVariableIndex)
             {
              ConvertFromString = parseFloat(vWorkingData[WatchIndexer]);
              Denominator = (ChartUpperLimits[ChartVariableIndex] - ChartLowerLimits[ChartVariableIndex]);
              if(ChartLowerLimits[ChartVariableIndex] < 0)
              {
                
                YAxis[ChartVariableIndex] = canHeight -  (((ChartLowerLimits[ChartVariableIndex] * -1) + ConvertFromString) * canHeight)/Denominator;
              }
              else
              {
                YAxis[ChartVariableIndex] = canHeight -  (ConvertFromString * canHeight)/Denominator;
              }
              
             }
           }
           
           WatchVariableIndex = WatchVariableIndex + 1;
         }
         if(WatchCommandIndex == 2)
         {
          WatchCommandIndex = 3;
         }
        
       }
     }
  
    }
  };

  xhttp.open("GET", "RD", true);
  xhttp.send();

}

setInterval(function() {
 
 // getData();
  Chartting();
}, 100); //100mSeconds update rate
 


</script>
</body>
</html>




)=====";


  boolean bWSVR_DebugOfOff = false;
  boolean bWSVR_HaltContinuous = false;
  boolean bWSVR_Halted = false;
  
  unsigned char ucWSVR_GETRequest = 0;
  unsigned char ucWSVR_ButtonState = 9;

  unsigned char ucWSVR_WEBSocketConnected = 0;
 
  String strWSVR_ButtonState = "0";

  

  AsyncWebServerRequest *GetRequest;

//________________________________________________________________________
  //unsigned char ucWSVR_NumberOfBreakPointsVariables[5][5]
  //unsigned char ucWSVR_NumberOfChartVariables = 0;
  //unsigned char ucWSVR_NumberOfBreakPoints = 0;
 // unsigned char ucWSVR_NumberOfBreakPoints = 0;
  String strWSVR_VariableNames;
  String strWSVR_VariableData;

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) 
{ // When a WebSocket message is received
  
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
          
          webSocket.sendTXT(0, strWSVR_VariableNames);
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
    //request->send(200, "text/html", MAIN_page);
//    ucWSVR_GETRequest = 1;
//    GetRequest = request;
  });
    
 

//   server.on("/RD", HTTP_GET, [](AsyncWebServerRequest *request)  //readData
//    {
//        // request->send(200, "text/plain", strWSVR_VariableData); //Send ADC value only to client ajax request
//      ucWSVR_GETRequest = 3;
//      GetRequest = request;
//     
//   
//    });
//
//   server.on("/LN", HTTP_GET, [](AsyncWebServerRequest *request) //loadDataNames
//    {
//       ucWSVR_GETRequest = 4;
//      GetRequest = request;
//      //request->send(200, "text/plain", strWSVR_VariableNames); //Send ADC value only to client ajax request
//   
//    }); 
    
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


void WSVR_SendToWeb(void)
{
     webSocket.sendTXT(0, "#######");
}


//void WSVR_AnswerGetRequest(void)
//{
//  
// 
//  switch(ucWSVR_GETRequest)
//  {
//    case 1:
//    {
//      GetRequest->send(200, "text/html", MAIN_page);
//       
//      ucWSVR_GETRequest = 0;
//     
//      break;
//    }
////    case 2:
////    {
////      
////       
////      GetRequest->send(200, "text/plain", strWSVR_ButtonState); //Send web page
////   
////      ucWSVR_GETRequest = 0;
////      break;
////    }
//    case 3:
//    {
//     
//      GetRequest->send(200, "text/plain", strWSVR_VariableData); //Send ADC value only to client ajax request
//    
//      ucWSVR_GETRequest = 0;
//      break;
//    }
//    case 4:
//    {
//       
//      GetRequest->send(200, "text/plain", strWSVR_VariableNames); //Send ADC value only to client ajax request
//         
//      ucWSVR_GETRequest = 0;
//      break;
//    }
//  }
//}


void WSVR_SendMsg(void)
{
  if(ucWSVR_WEBSocketConnected)
  {
   
   //webSocket.sendTXT(0, "message here");
  }
  else
  {
    Serial.println("Not Connected ");
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
