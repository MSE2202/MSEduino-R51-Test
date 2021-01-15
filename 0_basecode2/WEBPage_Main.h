/*
//Western Engineering base code 
Oct 15,2020
  
\Main WEB Page code to other pages or where you can make you own controls


*/

#ifndef MAINWEBPAGE_H
#define MAINWEBPAGE_H 1

#define BROADTESTING 1
 
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

#ifdef BROADTESTING
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
    content: 'Board Testing';
    color: white;
      
}

#endif


.Forward{
  position:absolute;
  
  top:50%;
  left:50%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Forward:checked + .Forward{
 background: green;   
}



.Forward:after {
     margin: 0;
    position: absolute;
    top: 50%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Forward';
    color: white;

.Left{
  position:absolute;
  
  top:60%;
  left:30%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Left:checked + .Left{
 background: green;   
}



.Left:after {
     margin: 0;
    position: absolute;
    top: 60%;
    left: 30%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: bold;
    content: 'Left';
    color: white;   

.Right{
  position:absolute;
  
  top:60%;
  left:70%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Right:checked + .Right{
 background: green;   
}



.Right:after {
     margin: 0;
    position: absolute;
    top: 60%;
    left: 70%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: Right;
    content: 'Left';
    color: white;

 
.Backwards{
  position:absolute;
  
  top:70%;
  left:50%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Backwards:checked + .Backwards{
 background: green;   
}



.Backwards:after {
     margin: 0;
    position: absolute;
    top: 70%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: Right;
    content: 'Backwards';
    color: white;    
}

.Stop{
  position:absolute;
  
  top:80%;
  left:10%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Stop:checked + .Stop{
 background: green;   
}



.Stop:after {
     margin: 0;
    position: absolute;
    top: 80%;
    left: 10%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: Right;
    content: 'Stop';
    color: white;    
}

.Percent25{
  position:absolute;
  
  top:80%;
  left:30%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Percent25:checked + .Percent25{
 background: green;   
}



.Percent25:after {
     margin: 0;
    position: absolute;
    top: 80%;
    left: 30%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: Right;
    content: '25%';
    color: white;    
}

.Percent50{
  position:absolute;
  
  top:80%;
  left:50%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Percent50:checked + .Percent50{
 background: green;   
}



.Percent50:after {
     margin: 0;
    position: absolute;
    top: 80%;
    left: 50%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: Right;
    content: '50%';
    color: white;    
}

.Percent75{
  position:absolute;
  
  top:80%;
  left:70%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Percent75:checked + .Percent75{
 background: green;   
}



.Percent75:after {
     margin: 0;
    position: absolute;
    top: 80%;
    left: 70%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: Right;
    content: '75%';
    color: white;    
}

.Percent100{
  position:absolute;
  
  top:80%;
  left:90%;
  height:5%;
  width:20%;
  background:red;
  text-align: center;
}

#Percent100:checked + .Percent100{
 background: green;   
}



.Percent100:after {
     margin: 0;
    position: absolute;
    top: 80%;
    left: 90%;
    -ms-transform: translate(-50%, -50%);
    transform: translate(-50%, -50%);
    font: Arial, Helvetica, sans-serif;
  font-size: 1vmax;
    font-weight: Right;
    content: '100%';
    color: white;    
}



</style>

<body>
 

 <div class="form">
  <div>
    <input type="radio" onclick="" id="MainPB" value="1" name="Main" checked />
    <label class="MainPB" for="MainPB"></label>
  
  </div>
  <div>
    <input type="radio" onclick="myFunctionBP()" id="Breakpoints" value="0" name="BreakPoints" checked />
    <label class="Breakpoints" for="Breakpoints"></label>
  </div>


  <div>
    <input type="radio" onclick="myFunctionBT()" id="BoardTesting" value="2" name="BoardTest" checked/>
    <label class="BoardTesting" for="BoardTesting"></label>
  
  </div>
  %#################################################################################################
   <div>
    <input type="radio" onclick="sendData(10)" id="Forward" value="10" name="Forward" checked/>
    <label class="Forward" for="Forward"></label>
  
  </div>

   <div>
    <input type="radio" onclick="sendData(11)" id="Left" value="11" name="Left" checked/>
    <label class="Left" for="Left"></label>
  
  </div>

   <div>
    <input type="radio" onclick="sendData(12)" id="Right" value="12" name="Right" checked/>
    <label class="Right" for="Right"></label>
  
  </div>

   <div>
    <input type="radio" onclick="sendData(13)" id="Barkwards" value="13" name="Barkwards" checked/>
    <label class="Barkwards" for="Barkwards"></label>
  
  </div>

   <div>
    <input type="radio" onclick="sendData(14)" id="Stop" value="14" name="Stop" checked/>
    <label class="Stop" for="Stop"></label>
  
  </div>

    </div>

   <div>
    <input type="radio" onclick="sendData(15)" id="Percent25" value="15" name="25%" checked/>
    <label class="Percent25" for="Percent25"></label>
  
  </div>

  <div>
    <input type="radio" onclick="sendData(16)" id="Percent50" value="16" name="50%" checked/>
    <label class="Percent50" for="Percent50"></label>
  
  </div>

  <div>
    <input type="radio" onclick="sendData(17)" id="Percent75" value="17" name="75%" checked/>
    <label class="Percent75" for="Percent75"></label>
  
  </div>

  <div>
    <input type="radio" onclick="sendData(18)" id="Percent100" value="18" name="100%" checked/>
    <label class="Percent100" for="Percent100"></label>
  
  </div>
 
</div>
<script>




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


   
function sendData(ButtonPressed)
{

  //To send data to server

  switch(ButtonPressed)
  {
    case 10:   //Forward
    {
     
        connection.send("PF"); 
       
      break;
    }
    case 11:  //left button pressed
    {
     
        connection.send("PL");
       
   
      break;
    }
    case 12:   //right button pressed
    {
        connection.send("PR");
       
      break;
    }
    case 13:  //Bardwards button pressed
    {
      
        connection.send("PB");
     
      break;
    }
    case 14:  //Stop button pressed
    {
      
        connection.send("PS");
     
      break;
    }
    case 15:  //25% button pressed
    {
      
        connection.send("PT");
     
      break;
    }
    case 16:  //50% button pressed
    {
      
        connection.send("PQ");
     
      break;
    }
    case 17:  //75% button pressed
    {
      
        connection.send("PV");
     
      break;
    }
    case 18:  //100 button pressed
    {
      
        connection.send("PH");
     
      break;
    }
   
  }
 
}



function myFunctionBP()
{
  location.replace("/BP")
}

function myFunctionBT()
{
  location.replace("/BT")
}
</script>

</body>
</html>




)=====";

















#endif
