#include<Servo.h>
Servo servo1;
#define trig 7
#define echo 6
#define LED 5
int angle = 0;

void setup(){
  servo1.attach(4);
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
 
  unsigned long duration = pulseIn(echo, HIGH);`

  float distance = duration / 29.0 / 2;
   
   if(distance < 10) {
    angle = 90;
    digitalWrite(LED, HIGH);
    delay(1000);
   }
   else{
    angle = 0;
    digitalWrite(LED, LOW);
    delay(1000);
   }
   servo1.write(angle);
}
