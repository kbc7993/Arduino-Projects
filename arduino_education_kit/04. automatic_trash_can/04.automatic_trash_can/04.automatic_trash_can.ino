#include <Servo.h>
Servo myservo;
#define trig 6
#define echo 5

float duration;
float distance;

void setup() {
  myservo.attach(7);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;

  if(distance > 10) {
    myservo.write(90);
    delay(3000);
    myservo.write(0);
  }
}
