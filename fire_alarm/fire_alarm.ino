#include <SoftwareSerial.h>
SoftwareSerial btSerial(7, 6);

#define gasSensor = A0;
#define limitValue = 400;

void setup() {
  btSerial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(gasSensorPin);

  if (sensorValue > threshold) {
    btSerial.println("fire");
  }
  delay(1000);
}
