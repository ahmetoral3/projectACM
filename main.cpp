#include "arduino.h"

int reed_switch = 21;
int reed_status;
void setup() {
    pinMode(reed_switch, INPUT);
    Serial.begin(9600);
  }
  void loop(){
    reed_status = digitalRead(reed_switch);
    if (reed_status == 1){
    Serial.println("0");
    }else{
    Serial.println("1");
    delay(1000);}
    }

/*const int trigPin = 27;
const int echoPin = 26;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(9600); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  
  delay(1000);
}*/

/*void setup()
{
  pinMode(16,INPUT);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(16)== LOW)
  {
    Serial.println("1");
    
    delay(100);
  }
  else 
  {
    
    Serial.println("0");
    
  }
  
}*/