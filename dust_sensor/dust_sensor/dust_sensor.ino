#define led 4
#define measure A0
#define led_r 7
#define led_g 6
#define led_b 5

const int samplingTime = 280;
const int sleepTime = 40;
const int delayTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
  
  Serial.println("미세먼지 농도에 따른 RGB LED 제어 시작");
}

void loop() {
  digitalWrite(led, LOW);
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measure);
  delayMicroseconds(sleepTime);
  digitalWrite(led, HIGH);
  delayMicroseconds(delayTime);

  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = (0.17 * calcVoltage - 0.1) * 1000;
  if (dustDensity < 0) {
    dustDensity = 0;
  }

  Serial.print("Dust Density: ");
  Serial.print(dustDensity);
  Serial.println(" ug/m3");

  if (dustDensity <= 30) {
    Serial.println("Status: Good (Blue)");
    setColor(0, 0, 255);
  } else if (dustDensity <= 80) {
    Serial.println("Status: Moderate (Yellow)");
    setColor(255, 255, 0);
  } else {
    Serial.println("Status: Unhealthy (Red)");
    setColor(255, 0, 0);
  }
  
  Serial.println("---------------------------------------");
  delay(1000);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(led_r, redValue);
  analogWrite(led_g, greenValue);
  analogWrite(led_b, blueValue);
}
