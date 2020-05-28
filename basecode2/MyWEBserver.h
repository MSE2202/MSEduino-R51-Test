


//#include <WiFi.h>
#include <ESPAsyncWebServer.h>


bool btWS_Fellover = true;

// Replace with your network credentials
const char *ssid = "BaseC2";
const char *password = "12345678";  //must be 8 characters long


IPAddress local_ip(192,168,128,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

AsyncWebServer server(80);

 
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

 <head>
  <meta charset="utf-8">
  <title>RaB1 Wifi server R9a</title>
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
    font: 100% Arial, Helvetica, sans-serif;
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

.Forward{
  position:absolute;
  
  top:1%;
  left:10%;
  height:20%;
  width:80%;
  background: var(--main-bg-color,black);
}

#Forward:checked + .Forward{
 background: green;   
}

.Forward:after {
    font: 380% Arial, Helvetica, sans-serif;
  font-weight: bold;
    content: 'Forward';
  color: white;
  position: relative;
    top: 25%;
    left: 35%;
}

.Left{
  position:absolute;
  
  top:22%;
  left:10%;
  height:20%;
  width:39%;
  background:var(--main-bg-color,black);
}

#Left:checked + .Left{
 background: green;   
}

.Left:after {
    font: 380% Arial, Helvetica, sans-serif;
  font-weight: bold;
    content: 'Left';
  color: white;
  position: relative;
    top: 25%;
    left: 35%;
}

.Right{
  position:absolute;
  
  top:22%;
  right:10%;
  height:20%;
  width:39%;
  background:var(--main-bg-color,black);
}

#Right:checked + .Right{
 background: green;   
}

.Right:after {
    font: 380% Arial, Helvetica, sans-serif;
  font-weight: bold;
    content: 'Right';
  color: white;
  position: relative;
    top: 25%;
    left: 30%;
}

.Reverse{
  position:absolute;
  
  top:43%;
  left:10%;
  height:20%;
  width:80%;
  background:var(--main-bg-color,black);
}

#Reverse:checked + .Reverse{
 background: green;   
}

.Reverse:after {
    font: 380% Arial, Helvetica, sans-serif;
  font-weight: bold;
    content: 'Reverse';
  color: white;
  position: relative;
    top: 25%;
    left: 35%;
}

.Stop{
  position:absolute;
  
  top:64%;
  left:10%;
  height:20%;
  width:80%;
  background:red;
}

#Stop:checked + .Stop{
 background: orange;   
}

.Stop:after {
    font: 380% Arial, Helvetica, sans-serif;
  font-weight: bold;
    content: 'Stop';
  color: white;
  position: relative;
    top: 25%;
    left: 40%;
}
.Datum{
  position:absolute;
  top:84%;
  left:10%;
  font: 100% Arial, Helvetica, sans-serif;
  font-weight: bold;
}

.Graph{
  position:absolute;
  top:90%;
  left:10%;
  font: 200% Arial, Helvetica, sans-serif;
  font-weight: bold;
  
}


</style>

<body>
 

<div class="form">
  <div>
    <input type="radio" onclick="sendData(1)"  id="Forward" value="1" name="radio" />
    <label class="Forward" for="Forward"></label>
  </div>
  <div>
    <input type="radio" onclick="sendData(2)" id="Left" value="2" name="radio" />
    <label class="Left" for="Left"></label>
  </div>
  <div>
    <input type="radio" onclick="sendData(3)" id="Right" value="3" name="radio" />
    <label class="Right" for="Right"></label>
  </div>
    <div>
    <input type="radio" onclick="sendData(4)" id="Reverse" value="3" name="radio" />
    <label class="Reverse" for="Reverse"></label>
  </div>
  <div>
    <input type="radio" onclick="sendData(0)" id="Stop" value="4" name="radio" checked="checked"/>
    <label class="Stop" for="Stop"></label>
  </div>


  <div>
    <label class = "Datum">
     <!--  Gravity Distance <br> <span id="SensorData">--         --          --        --</span> -->
      
      SensorData - Gravity: <span id="GravityMeas">0</span>
      Distance - : <span id="DistanceMeas">0</span>
       
    </label>  
  </div>

  <div>
  <label class = "Graph">
  <canvas id="myCanvas" width= "10" height="50" onclick="sendData(5)" style="border:1px solid #d3d3d3;">
    Your browser does not support the HTML5 canvas tag.</canvas>
   </label>
   </div>
   
</div>

<script>
  
 var c = document.getElementById("myCanvas");
 var ctx = c.getContext("2d");
 var XAxis =  0;
 var XClear = 0;
 var YAxis = 0;
 var YAxisPrevious = 0;
 var canWidth = 0;
 var canHeight = 0;
 var lineColour = "red";
 var lineColourChanged = 0;
 var Flipped;
 
 var counttmr = 0;
 ctx.moveTo(0,0);
 ctx.canvas.width  = window.innerWidth*0.8;
 ctx.canvas.height = window.innerHeight*0.08;
 canWidth = ctx.canvas.width;
 canHeight = ctx.canvas.height;
 ctx.beginPath();
  
  
function sendData(ButtonPressed) {
  var xhttp = new XMLHttpRequest();
  
  if(ButtonPressed == 5)
  {
  if(lineColour == "red")
  {
    lineColour = "green";
    lineColourChanged = 1;
  }
  else
  {
    lineColour = "red";
    lineColourChanged = 1;
  }
  }
 
  
  xhttp.open("GET", "setPressedButton?StateButton="+ButtonPressed, true);
  xhttp.send();
}

 
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 250); //250mSeconds update rate
 
function getData() {
  var xhttp = new XMLHttpRequest();
  var WorkingSensorData;
 
 
 counttmr = counttmr + 1;
  if(counttmr >= 100)
  { 
     counttmr = 0;  
     //document.documentElement.style.setProperty('--main-bg-color', 'blue');
   }

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
     WorkingSensorData = (this.responseText).split(";     ");
    
      YAxis  = parseInt(WorkingSensorData[0],10);
      
      document.getElementById("GravityMeas").innerHTML = WorkingSensorData[0];
      document.getElementById("DistanceMeas").innerHTML = WorkingSensorData[1];
        
    }
  };


  xhttp.open("GET", "readSensorData", true);
  xhttp.send();

  
 
  ctx.beginPath();
  ctx.lineWidth = "5";
  ctx.strokeStyle = "white";
  ctx.moveTo((XAxis+4),0);
  ctx.lineTo((XAxis+4),200);
  ctx.stroke();
  if(lineColourChanged == 1)
  {
    ctx.fillStyle = lineColour;
  lineColourChanged = 0;
  ctx.fillRect((XAxis-9),(YAxis-5),10,10); 
  }
  ctx.beginPath();
 
  ctx.moveTo(XAxis,YAxisPrevious);
  XAxis = XAxis + 1;
  
  if(XAxis > canWidth)
  {
    XAxis = 0;
    
    ctx.moveTo(0,YAxis);
 
  }
  
  
  ctx.lineWidth = "2";
  ctx.strokeStyle = lineColour;
  ctx.lineTo(XAxis,YAxis);
  YAxisPrevious = YAxis;
  ctx.stroke(); 
 
  }

</script>
</body>
</html>
</script>
</body>
</html>

)=====";



  unsigned char ucButtonState;
  unsigned char ucWorkingButtonState;
  
  unsigned int uiDistance;
  double dWS_PIDInput;
  String buttonState = "0";
  
 
  String DistanceMeas = "0";
  
  String SensorData;


void setupWEbServer(void)
{

  
  
  Serial.print(F("Configuring access point..."));

	
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print(F("AP IP address: "));
  Serial.println(myIP);
  
  
 server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send(200, "text/html", MAIN_page);
  });
    
 
  server.on("/setPressedButton", HTTP_GET, [](AsyncWebServerRequest *request)
  {
      
      AsyncWebParameter* p;
     
     if(request->hasParam("StateButton"))
       p = request->getParam("StateButton");
       // Serial.printf("GET[%s]: %s\n", p->name().c_str(), p->value().c_str());

     String t_state = p->value().c_str();//server->arg("StateButton"); //Refer  xhttp.open("GET", "setButton?StateButton="+buttonPressed, true);
     buttonState = p->value().c_str();
     
     ucButtonState = buttonState.toInt();
    
     
    request->send(200, "text/plain", buttonState); //Send web page
   
  });

    server.on("/readSensorData", HTTP_GET, [](AsyncWebServerRequest *request)
    {
     
      SensorData = String(dWS_PIDInput) + ";     " + String(uiDistance);
     
   
    request->send(200, "text/plain", SensorData); //Send ADC value only to client ajax request
   
    });
    
 
  server.begin();
  Serial.println(F("HTTP server started"));


  Serial.println(F(""));
}

void loopWEBServerButtonresponce(void)
{

   

    switch(ucButtonState)
    {
      case 0:
      default:
      {
     
       //Serial.println("Stop");
       ucWorkingButtonState = 0;
       ucButtonState = 9;
      
       
        break;
      }
      case 1:
      {
      
      // Serial.println("Forward");
        ucButtonState = 9;
        ucWorkingButtonState = 1;
        
        break;
      }
      case 2:
      {
        
       //Serial.println("Left");
        ucButtonState = 9;
        ucWorkingButtonState = 2;
        break;
      }
      case 3:
      {
      
       //Serial.println("Right");
       ucButtonState = 9;
       ucWorkingButtonState = 3;
        break;
      }
      case 4:
      {
       
    
       // Serial.println("Reverse");
        ucButtonState = 9;
        ucWorkingButtonState = 4;
        break;
      }
      case 5:  //toggle servo
      {
        
        ucButtonState = 9;
       
       
        break;
      }
      case 9:
      {
        
        ucButtonState = 9;
        break;
      }
    }

}
