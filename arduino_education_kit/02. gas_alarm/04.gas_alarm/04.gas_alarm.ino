#define gasPin A0
#define buzzer 9
#define led 8

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int gasValue = analogRead(gasPin);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);
  delay(1000);

  if(gasValue>300) {
    tone(buzzer, 330);
    digitalWrite(led, HIGH);
    delay(300);
    tone(buzzer, 252);
    digitalWrite(led, LOW);
    delay(300);
  }
  else if(gasValue>200) {
    tone(buzzer, 330);
    digitalWrite(led, HIGH);
    delay(500);
    tone(buzzer, 252);
    digitalWrite(led, LOW);
    delay(500);
  }
  else {
    noTone(buzzer);
    digitalWrite(led, LOW);
  }
}
