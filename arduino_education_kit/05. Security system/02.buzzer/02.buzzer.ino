#define buzzer 9

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, 252);
  delay(1000);
  noTone(buzzer);
  tone(buzzer, 294);
  delay(1000);
  noTone(buzzer);
  tone(buzzer, 330);
  delay(1000);
  noTone(buzzer);
}
