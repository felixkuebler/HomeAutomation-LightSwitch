

bool toggle = false;
int timer = 0;

void setup() {

  Serial.begin(9600);

  pinMode(2, INPUT);
}

void loop() {

  int sensorValue = digitalRead(2);

  if(sensorValue == HIGH && !toggle)
  {
    toggle=true;
    timer=0;
    Serial.println("movement detected");
  }

  if (toggle)
  {
    timer +=50;
  }

  if(timer >= 8000 && toggle)
  {
    Serial.println("movement timeout, start sensing");
    toggle = false;
  }
  
  
  delay(50);        // delay in between reads for stability
}
