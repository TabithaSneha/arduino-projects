// Ultrasonic Sensor
const int trigPin = 12;
const int echoPin = 10;

// Left Motor(A)
int enableA = 8;
const int motorPin1 = 3;
const int motorPin2 = 5;

// Right Motor(B)
int enableB = 9;
const int motorPin3 = 4;
const int motorPin4 = 2;

long duration;
long distance;

void setup()
{
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delay (2);
  
  digitalWrite(trigPin, HIGH);
  delay (10);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
   
  if (distance <= 20) // if obstacle is within 20 cm
  {
    // Robot will stop for a while
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 0);
    delay (200);
    
    // Robot will move backwards
    digitalWrite(motorPin1, 1);
    digitalWrite(motorPin2, 0);
    digitalWrite(motorPin3, 1);
    digitalWrite(motorPin4, 0);
    delay (200);
    
    // Robot will move towards the right
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 1);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 0);
    delay (200);
  }
  
  else
  {
    // Robot will move forwards
    digitalWrite(motorPin1, 0);
    digitalWrite(motorPin2, 1);
    digitalWrite(motorPin3, 0);
    digitalWrite(motorPin4, 1);
  }
}