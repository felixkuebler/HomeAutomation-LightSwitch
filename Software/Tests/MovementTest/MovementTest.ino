


#define PIN_MOTOR_A_1 4
#define PIN_MOTOR_A_2 5

#define PIN_MOTOR_ENDSTOP_A_1 9
#define PIN_MOTOR_ENDSTOP_A_2 10

#define PIN_MOTOR_B_1 14
#define PIN_MOTOR_B_2 16

#define PIN_MOTOR_ENDSTOP_B_1 12
#define PIN_MOTOR_ENDSTOP_B_2 13


int direction = 1;
bool stop_a = true;
bool stop_b = true;

/*
int motor_a_1_speed;
int motor_a_2_speed;
int motor_a_1_time;
int motor_a_2_time;

int motor_b_1_speed;
int motor_b_2_speed;
int motor_b_1_time;
int motor_b_2_time;

int thresh = 100;
*/

void setup() 
{

  pinMode(PIN_MOTOR_A_1, OUTPUT);
  pinMode(PIN_MOTOR_A_2, OUTPUT);

  pinMode(PIN_MOTOR_B_1, OUTPUT);
  pinMode(PIN_MOTOR_B_2, OUTPUT);

  pinMode(PIN_MOTOR_ENDSTOP_A_1, INPUT);
  pinMode(PIN_MOTOR_ENDSTOP_A_2, INPUT);

  pinMode(PIN_MOTOR_ENDSTOP_B_1, INPUT);
  pinMode(PIN_MOTOR_ENDSTOP_B_2, INPUT);

  pinMode(A0, INPUT);
  
  Serial.begin(9600);

}

void loop() 
{

  if(Serial.available()>0)
  {
    while(Serial.available()>0)
    {
      Serial.read();
    }
    
    if(direction==1) direction = 2;
    else direction = 1;

    stop_a=false;
    stop_b=false;
  }
/*
  int val = analogRead(A0);
  Serial.print("IR Sensor: ");
  Serial.println(val);
*/
  if(direction == 1)
  {
    if(!stop_a)
    {
      //Serial.println("a to 1");
      analogWrite(PIN_MOTOR_A_2, 0);
      analogWrite(PIN_MOTOR_A_1, 1024);

      //motor_a_1_time += 50;
    }

     if(!stop_b)
     {
      //Serial.println("b to 1");
      analogWrite(PIN_MOTOR_B_2, 0);
      analogWrite(PIN_MOTOR_B_1, 500);

      //motor_b_1_time += 50;
     }
  }
  else
  {
    if(!stop_a)
    {
      //Serial.println("a to 2");
      analogWrite(PIN_MOTOR_A_1, 0);
      analogWrite(PIN_MOTOR_A_2, 1024);

      //motor_a_2_time += 50;
    }

    if(!stop_b)
    {
      //Serial.println("b to 2");
      analogWrite(PIN_MOTOR_B_1, 0);
      analogWrite(PIN_MOTOR_B_2, 800);

      //motor_b_2_time += 50;
    }
  }
    
  if(digitalRead(PIN_MOTOR_ENDSTOP_A_1)==HIGH && direction == 1)
  {
    //Serial.println("ENDSTOPT_A_1");
    analogWrite(PIN_MOTOR_A_1, 0);
    analogWrite(PIN_MOTOR_A_2, 0);
    stop_a = true;
  }
  
  if(digitalRead(PIN_MOTOR_ENDSTOP_A_2)==HIGH && direction == 2) 
  {                                                                                                                   
    //Serial.println("ENDSTOPT_A_2");
    analogWrite(PIN_MOTOR_A_1, 0);
    analogWrite(PIN_MOTOR_A_2, 0);
    stop_a = true;
  }

  if(digitalRead(PIN_MOTOR_ENDSTOP_B_1)==HIGH && direction == 1) 
  {
    //Serial.println("ENDSTOPT_B_1");
    analogWrite(PIN_MOTOR_B_1, 0);
    analogWrite(PIN_MOTOR_B_2, 0);
    stop_b = true;
  }
  
  if(digitalRead(PIN_MOTOR_ENDSTOP_B_2)==HIGH && direction == 2)
  {
    //Serial.println("ENDSTOPT_B_2");
    analogWrite(PIN_MOTOR_B_1, 0);
    analogWrite(PIN_MOTOR_B_2, 0);
    stop_b = true;
  }

/*
  if(stop_a && stop_b)
  {
    if(direction == 1)
    {
      int time_diff = motor_a_1_time - motor_b_1_time;
      if(time_diff > thresh)
      {
        //a kleiner oder b höher
        if(motor_a_1_speed < motor_b_1_speed)
        {
          if(motor_a_1_speed)
        }
      }
      else if(time_diff < -1*thresh)
      {
        a höher oder b kleiner
      }
    }
    else
    {
      
    }
  }
  */
  
  delay(50);            
}
