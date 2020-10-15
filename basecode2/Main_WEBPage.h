/*
//Western Engineering base code 
Oct 15,2020
  
\Main WEB Page code to other pages or where you can make you own controls


*/

#ifndef MAINWEBPAGE_H
#define MAINWEBPAGE_H 1


 
const char Main_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

 <head>
  <meta charset="utf-8">
  <title>Wifi ESP32 R1</title>
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


.MainPB{
  position:absolute;
  
  top:1%;
  left:20%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#MainPB:checked + .MainPB{
 background: green;   
}

.MainPB:after {
     margin: 0;
    position: absolute;
    top: 50%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Main';
    color: white;
}

.Breakpoints{
  position:absolute;
  
  top:1%;
  left:41%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Breakopints:checked + .Brekpoints{
 background: green;   
}



.Breakpoints:after {
     margin: 0;
    position: absolute;
    top: 50%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Breakpoints';
    color: white;
}


.BoardTesting{
  position:absolute;
  
  top:1%;
  left:62%;
  height:5%;
  width:20%;
  background:red;
}

#BoardTesting:checked + .BoardTeating{
 background: green;   
}

.BoardTesting:after {
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






</style>

<body>
 

 <div class="form">
  <div>
    <input type="radio" onclick="sendData(0)" id="MainPB" value="1" name="Main" checked />
    <label class="MainPB" for="MainPB"></label>
  
  </div>
  <div>
    <input type="radio" onclick="sendData(1)" id="Breakpoints" value="0" name="BreakPoints" checked />
    <label class="Breakpoints" for="Breakpoints"></label>
  </div>

  <div>
    <input type="radio" onclick="sendData(2)" id="BoardTesting" value="2" name="BoardTest" checked/>
    <label class="BoardTesting" for="BoardTesting"></label>
  
  </div>
  
 
</div>

<script>
  
 
 var DebugOnOff = false;
 var HaltContin = false; 
 var colors = ["red",   "green",   "blue",   "yellow",   "orange", "black"];


var connection = new WebSocket('ws://' + location.hostname + ':81/', ['arduino']);
connection.onopen = function () {
  connection.send('Connect ' + new Date());
  sendData(6);   //load graph/chart with names for debugging
  
};
connection.onerror = function (error) { console.log('WebSocket Error ', error);};
connection.onmessage = function (e) { onMessage(e)};
connection.onclose = function () { console.log('WebSocket connection closed');};


// Called when a message is received from the server
function onMessage(e) 
{
 
    // Print out our received message
    console.log("Received: " + e.data);
    vWorkingData = (e.data).split(";");
   if(vWorkingData[0] == "N#^")  //variable names so load charts/tables
   {
    getNames();
   }
   if(vWorkingData[0] == "V#^")  //Variable data , put in chart/table
   {
    WatchCommandIndex = 0;
    WatchVariableIndex = 0;
    getData();
   }
}

  
function getNames() 
{
 
  var vWorkingName;
 
 
     vWorkingName = vWorkingData;
     if(vWorkingName.length > 1)
     {
       for (WatchIndexer=0;WatchIndexer<vWorkingName.length;WatchIndexer++)  
       {
         if(WatchCommandIndex == 5)  //Setup charts lower float limit
         {
          ChartLowerLimits[ChartVariableIndex] = parseFloat(vWorkingName[WatchIndexer]);
          WatchCommandIndex = 0;
         }

         if(WatchCommandIndex == 6)  //setup charts upper limit
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
 }
   
function sendData(ButtonPressed)
{

  //To send data to server

  switch(ButtonPressed)
  {
    case 0:   //debug on button pressed
    {
      if (DebugOnOff == false)
      {
        connection.send("Po"); 
        DebugOnOff = true;
      }
      break;
    }
    case 1:  //debug off button pressed
    {
      if (DebugOnOff == true)
      {
        connection.send("Pf");
        DebugOnOff = false;
      }
      break;
    }
    case 2:   //halt button pressed
    {
      if (HaltContin == true)
      {
        connection.send("Ph");
        HaltContin = false;
      }
      break;
    }
    case 3:  //continue button pressed
    {
      if (HaltContin == false)
      {
        connection.send("Pc");
        HaltContin = true;
      }
      break;
    }
    case 4:   //debug point pressed
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
    case 6:  //requesting variable name data to load charts
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
 
  
  var ConvertFromString;
  var Denominator = -50;
  

   WatchCommandIndex = 0;
   if(vWorkingData.length > 1)
   {
    
     for (WatchIndexer=0;WatchIndexer<vWorkingData.length;WatchIndexer++)  
     {
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

setInterval(function() {
 
  Chartting();
}, 100); //100mSeconds update rate
 


</script>
</body>
</html>




)=====";

















#endif
