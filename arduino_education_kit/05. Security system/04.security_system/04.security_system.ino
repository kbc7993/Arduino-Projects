#define trig 6
#define echo 5
#define buzzer 7
float duration;
float distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
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

  if(distance < 100) {
    tone(buzzer, 330);
    delay(500);
    noTone(buzzer);
    tone(buzzer, 252);
    delay(500);
    noTone(buzzer);
  }
  else {
    noTone(buzzer);
  }
}
