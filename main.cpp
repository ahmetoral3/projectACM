#include "arduino.h"

int reed_switch = 21;
int reed_status;

const int trigPin = 22;
const int echoPin = 23;

const int trigPin1 = 16;
const int echoPin1 = 17;

const int motorpinLeft1 =2;
const int motorpinLeft2 =3;
const int motorpinRight1 =4;
const int motorpinRight2 =5;
const int forward = 6;
const int backward = 7;
const int left = 8;
const int right = 9;

#define sound speed in cm/uS
#define SOUND_SPEED 0.034

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
    pinMode(15,INPUT);
    pinMode(2,INPUT);
  }

  void vooruit(){
    digitalWrite(motorpinLeft1,HIGH);
    digitalWrite(motorpinLeft2,LOW);
    digitalWrite(motorpinRight1,LOW);
    digitalWrite(motorpinRight2,HIGH);
  }
  void achteruit(){
    digitalWrite(motorpinLeft1,LOW);
    digitalWrite(motorpinLeft2,HIGH);
    digitalWrite(motorpinRight1,HIGH);
    digitalWrite(motorpinRight2,LOW);
  }

  void links(){
    digitalWrite(motorpinLeft1,LOW);
    digitalWrite(motorpinLeft2,HIGH);
    digitalWrite(motorpinRight1,LOW);
    digitalWrite(motorpinRight2,HIGH);
  }

  void rechts(){
    digitalWrite(motorpinLeft1,HIGH);
    digitalWrite(motorpinLeft2,LOW);
    digitalWrite(motorpinRight1,HIGH);
    digitalWrite(motorpinRight2,LOW);
  }

  void loop(){
    //reed
    reed_status = digitalRead(reed_switch);
    if (reed_status == 1){
    Serial.println("0");
    }else{
    Serial.println("1");
    delay(1000);
    }

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
  

  
  
  


  if (digitalRead(15)== LOW){
      rechts();
  }
  else if (digitalRead(2)== LOW){
      links();
  }
  else if (distanceCm < 10){
    achteruit();
  }
  else if (distanceCm1 > 20){
    achteruit();
  }
  else{
      vooruit();
    }
}