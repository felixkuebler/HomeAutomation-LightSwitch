
#define switch1 16
#define switch2 14
#define relay1 12
#define relay2 13

void setup(void)
{
  
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

}

void loop(void)
{
  delay(10);
}



