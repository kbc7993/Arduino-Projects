#include<DHT.h>
#include<Servo.h>
#define DHTPIN 2
#define DHTTYPE DHT11
#define led 7

Servo myservo;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 테스트 시작!");
  dht.begin();

  myservo.attach(6);
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT 센서 읽기 실패!");
    return;
  }
  Serial.print("습도: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("온도: ");
  Serial.print(t);
  Serial.print(" °C, ");
  Serial.print(f);
  Serial.println("F");

  if(t >30) {
    myservo.write(30);
    delay(1000);
    myservo.write(0);
    delay(10,800,000);
  }
}
