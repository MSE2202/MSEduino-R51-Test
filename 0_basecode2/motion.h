

unsigned char ucMotion_Direction;
unsigned char ucMotion_Speed;


unsigned char ucMotorState = 0;
unsigned char ucMotorStateIndex = 0;

double dManualSpeed;
double dForwardSpeed;
double dReverseSpeed;
double dLeftSpeed;
double dRightSpeed;




void setupMotion (void)
{
	
  dManualSpeed = 0;
  dForwardSpeed = 250;
  dReverseSpeed = 250;
  dLeftSpeed = 200;
  dRightSpeed = 200
  ;
  
  //setup PWM for motors
  ledcAttachPin(MOTORLEFTa, 1); // assign Motors pins to channels
  ledcAttachPin(MOTORLEFTb, 2);
  ledcAttachPin(MOTORRIGHTa, 3);
  ledcAttachPin(MOTORRIGHTb, 4);

    // Initialize channels 
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  ledcSetup(1, 20000, 8); // 20mS PWM, 8-bit resolution
  ledcSetup(2, 20000, 8);
  ledcSetup(3, 20000, 8);
  ledcSetup(4, 20000, 8);
  //uiMotorSpeedLeft = uiStop;
  //uiMotorSpeedRight = uiStop;
  //uiMotorCommandLeft = uiStop;
  //uiMotorCommandRight = uiStop;

  
	
   ucMotion_Direction = 0;
   ucMotion_Speed = 0;

	
}


void move(double dspeed)
{
    int  iPrintOnce;
      
   
     switch(ucMotorState)
      {
        case 0:
        {
          ledcWrite(2,0);
          ledcWrite(1,0);
          ledcWrite(4,0);
          ledcWrite(3,0);
        //ucWorkingButtonState = 9;
          if(iPrintOnce != 0)
           {
            iPrintOnce = 0;
            Serial.print(F("stop "));
            Serial.println(dspeed);
          }
          break;
        }
      
      
        case 1:
        {
          dspeed = dForwardSpeed;
          ledcWrite(2,0);
          ledcWrite(1,dspeed);
          ledcWrite(4,0);
          ledcWrite(3,dspeed);
          //ucWorkingButtonState = 9;
          if(iPrintOnce != 1)
           {
            iPrintOnce = 1;
            Serial.print(F("Forward "));
            Serial.println(dspeed);
           }
          break;
        }
        case 2:
        {
          dspeed = dLeftSpeed;
          ledcWrite(2,0);
          ledcWrite(1,dspeed);
          ledcWrite(3,0);
          ledcWrite(4,dspeed);
         //ucWorkingButtonState = 9;
          if(iPrintOnce != 3)
           {
            iPrintOnce = 3;
            Serial.print(F("Left "));
            Serial.println(dspeed);
           }
        
          break;
        }
        case 3:
        {
          dspeed = dRightSpeed;
          ledcWrite(1,0);
          ledcWrite(2,dspeed);
          ledcWrite(4,0);
          ledcWrite(3,dspeed);
          // ucWorkingButtonState = 9;
          if(iPrintOnce != 4)
           {
            iPrintOnce = 4;
            Serial.print(F("Right "));
            Serial.println(dspeed);
           }
          break;
        }
        case 4:
        {
           dspeed = dReverseSpeed;
          ledcWrite(1,0);
          ledcWrite(2,dspeed);
          ledcWrite(3,0);
          ledcWrite(4,dspeed);
         // ucWorkingButtonState = 9;
          if(iPrintOnce != 2)
           {
            iPrintOnce = 2;
            Serial.print(F("Reverse "));
            Serial.println(dspeed);
           }
          break;
        }
        
      }
       
       
        
   
 
}
