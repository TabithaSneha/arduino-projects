void setup()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available())
  {
    String val=Serial.readString();
    if (val == "FORWARD" or val == "forward")
    {
      digitalWrite(4,0);
      digitalWrite(5,1);
      digitalWrite(7,0);
      digitalWrite(6,1);
    }
    else if (val == "BACKWARD" or val == "backward")
    {
      digitalWrite(4,1);
      digitalWrite(5,0);
      digitalWrite(7,1);
      digitalWrite(6,0);
    }
    else if (val == "LEFT" or val == "left")
    {
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(7,0);
      digitalWrite(6,1);
    }
    else if (val == "RIGHT" or val == "right")
    {
      digitalWrite(4,0);
      digitalWrite(5,1);
      digitalWrite(7,0);
      digitalWrite(6,0);
    }
    else if (val == "STOP" or val == "stop")
    {
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(7,0);
      digitalWrite(6,0);
    }
  }
}