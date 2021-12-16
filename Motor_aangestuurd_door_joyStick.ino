  //4 motoren in 2 groepen, groep 1 is links, groep 2 is rechts
  const int motorpinLeft1 =2;
  const int motorpinLeft2 =3;
  const int motorpinRight1 =4;
  const int motorpinRight2 =5;
  const int forward = 6;
  const int backward = 7;
  const int left = 8;
  const int right = 9;
  int buttonStateForward;
  int buttonStateBackward;
  int buttonStateLeft;
  int buttonStateRight;

void setup() {
  pinMode(motorpinLeft1,OUTPUT);
  pinMode(motorpinLeft2,OUTPUT);
  pinMode(motorpinRight1,OUTPUT);
  pinMode(motorpinRight2,OUTPUT);
  pinMode(forward,INPUT);
  pinMode(backward,INPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
}

void loop() {
  buttonStateForward = digitalRead(forward);
  buttonStateBackward = digitalRead(backward);
  buttonStateLeft = digitalRead(left);
  buttonStateRight = digitalRead(right);
  //vooruit
  if (buttonStateForward == HIGH){
    digitalWrite(motorpinLeft1,HIGH);
    digitalWrite(motorpinLeft2,LOW);
    digitalWrite(motorpinRight1,LOW);
    digitalWrite(motorpinRight2,HIGH);
    }

  //achteruit
  if (buttonStateBackward == HIGH){
    digitalWrite(motorpinLeft1,LOW);
    digitalWrite(motorpinLeft2,HIGH);
    digitalWrite(motorpinRight1,HIGH);
    digitalWrite(motorpinRight2,LOW);
    }

  //rechts
  if (buttonStateRight == HIGH){
    digitalWrite(motorpinLeft1,HIGH);
    digitalWrite(motorpinLeft2,LOW);
    digitalWrite(motorpinRight1,HIGH);
    digitalWrite(motorpinRight2,LOW);
    }

  //Links
  if (buttonStateLeft == HIGH){
    digitalWrite(motorpinLeft1,LOW);
    digitalWrite(motorpinLeft2,HIGH);
    digitalWrite(motorpinRight1,LOW);
    digitalWrite(motorpinRight2,HIGH);
    }
}
