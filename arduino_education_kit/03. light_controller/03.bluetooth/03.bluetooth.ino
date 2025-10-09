#include<SoftwareSerial.h>
#define BT_RX 8
#define BT_TX 7
SoftwareSerial bluetooth(BT_RX, BT_TX);
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    char data = bluetooth.read();
    Serial.print(data);
  }
  if (Serial.available()) {
    char data = Serial.read();
    bluetooth.print(data);
  }
}
