#include<SoftwareSerial.h>
#include<Servo.h>
#define BT_RX 8
#define BT_TX 7
SoftwareSerial bluetooth(BT_RX, BT_TX);
Servo myservo;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  myservo.attach(9);
}

void loop() {
  if(bluetooth.available()) {
    char data = bluetooth.read();
    if(data == '1') {
      myservo.write(30);
      delay(1000);
      myservo.write(0);
      delay(1000);
    }
  }
}
