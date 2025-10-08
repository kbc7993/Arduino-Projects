#define touch = 7;
#defien buzzer = 8;
#define led_r 9
#define led_g 10;
#define led_b 11;

int ledState = 0;
int lastTouchState = 0;
int currentTouchState;

void setup() {
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(touch, INPUT);
}

void loop() {
  currentTouchState = digitalRead(touchPin);
  
  if (lastTouchState == 0 && currentTouchState == 1) {
    tone(buzzerPin, 500, 100);
    ledState = 1 - ledState;

    if (ledState == 1) {
      analogWrite(redPin, 150);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 255);
    } else {
      analogWrite(redPin, 0);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
    }
  }
  lastTouchState = currentTouchState;
  delay(10); 
}
