#include "arduino.h"

int reed_switch = 21;
int reed_status;

const int trigPin = 22;
const int echoPin = 23;

const int trigPin1 = 18;
const int echoPin1 = 19;
#define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
long duration1;
float distanceCm;
float distanceCm1;

void setup() {
    Serial.begin(9600);
    //reed
    pinMode(reed_switch, INPUT);
    //ultrasoon
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1,INPUT);
    //ir-sensor
    pinMode(16,INPUT);
    pinMode(17,INPUT);
  }
  void loop(){
    //reed
    reed_status = digitalRead(reed_switch);
    if (reed_status == 1){
    Serial.println("0");
    }else{
    Serial.println("1");
    delay(1000);}

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
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  
  // Calculate the distance
  distanceCm1 = duration1 * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance1 (cm): ");
  Serial.println(distanceCm1);
  

  //ir-sensor
  if (digitalRead(16)== LOW)
    {
      Serial.println("0 = 1");
    }
  else 
    {
      Serial.println("0 = 0");
    }

  if (digitalRead(17)== LOW)
    {
      Serial.println("1 = 1");
    }
  else 
    {
      Serial.println("1 = 0");
    }

    delay(1000);
}
