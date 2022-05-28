const int temp_trans_pin = A0;
const int heater_pin = 13;
const int fan_pin = 6;

//Set the range of the desired temperature

float minTemp = 20, maxTemp = 25; //Room Temp [20-25]

#include<LiquidCrystal.h> 

LiquidCrystal LCD (12, 11, 5, 4, 3 ,2);

void setup()
{
  LCD.begin(16, 2);
  pinMode(heater_pin, OUTPUT);
  pinMode(fan_pin, OUTPUT);
  
  LCD.print("Room Temperature(C): ");
  LCD.setCursor(2,1);
  LCD.print(minTemp);
  LCD.print("-");
  LCD.print(maxTemp);
  
  delay(2000);
}

void loop()
{
  float eqv_volt, sensorTemp;
  eqv_volt = analogRead(temp_trans_pin)*5.0/1023;
  sensorTemp = 100.0*eqv_volt-50.0;
  
  LCD.clear();
  LCD.print("Sensor Reading: ");
  LCD.setCursor(2,1);
  LCD.print(sensorTemp);
  LCD.print("C");
  
  delay(2000);
  
  if (sensorTemp > maxTemp)
  {
    LCD.clear();
    LCD.print("Room Temperature is HIGHER!");
    LCD.setCursor(0,1);
    LCD.print("Turn ON Fan!");
    for (int i = 0; i <= 255; i++)
    {
      analogWrite(fan_pin, i);
    }
    
    delay(2000);
    
    LCD.clear();
    LCD.print("Now Room Temperature is better!");
    LCD.setCursor(0,1);
    LCD.print("Turn OFF Fan!");
    for (int i = 255; i >= 0; i--)
    {
      analogWrite(fan_pin, 1);
    }
    
    delay(2000);
  }
  else if (sensorTemp < minTemp)
  {
    LCD.clear();
    LCD.print("Room Temperature is LOWER!");
    LCD.setCursor(0, 1);
    LCD.print("Turn ON Heater!");
    
    digitalWrite(heater_pin, HIGH);
    
    delay(3000);
    
    LCD.clear();
    LCD.print("Now Room Temperature is better!");
    LCD.setCursor(0,1);
    LCD.print("Turn OFF Heater!");
    
    delay(1000);
    
    digitalWrite(heater_pin, LOW);
    LCD.clear();
  }
  else if(sensorTemp > minTemp && sensorTemp < maxTemp)
  {
    LCD.clear();
    LCD.print("Room Temperature is normal!");
    LCD.setCursor(2,1);
    LCD.print("Turn OFF all!");
    delay(1000);
    LCD.clear();
  }
  else
  {
  	LCD.clear();
    LCD.print("Something went wrong!");
    LCD.setCursor(2,1);
    LCD.print("Recheck circuit connections!");
    delay(1000);
    LCD.clear();
  }
  delay(1000);
}