#include <Servo.h>
Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(9);
}

void loop() {
  myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
  myservo.write(180);
  delay(500);

  for (pos = 0; pos <=180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }

  for (pos = 180; pos >=0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
