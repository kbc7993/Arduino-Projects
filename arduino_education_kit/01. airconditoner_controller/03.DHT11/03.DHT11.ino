#include<DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 테스트 시작!");
  dht.begin();
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
}
