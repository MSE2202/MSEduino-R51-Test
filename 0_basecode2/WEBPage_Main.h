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

  
 
</div>
<script>
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
