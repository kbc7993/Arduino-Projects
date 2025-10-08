#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#define LED_PIN 6 
#define LED_COUNT 9

SoftwareSerial bluetooth(2, 3); // RX, TX

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
String receivedString = ""; 

void setup() {
  strip.begin();
  strip.show();
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()) {
    char c = bluetooth.read();
    
    if (c == '\n') {
      Serial.print("수신된 데이터: ");
      Serial.println(receivedString);
      
      int FirstCommaIndex = receivedString.indexOf(',');
      int SecondCommaIndex = receivedString.indexOf(',', FirstCommaIndex +1);
      if (FirstCommaIndex > 0 && SecondCommaIndex > 0) {
        String r_str = receivedString.substring(0, FirstCommaIndex);
        String g_str = receivedString.substring(FirstCommaIndex + 1, SecondCommaIndex);
        String B_str = receivedString.substring(SecondCommaIndex +1);
        
        int r = r_str.toInt();
        int g = g_str.toInt();
        int b = b_str.toInt();
        
        Serial.print("R: ");
        Serial.print(r);
        Serial.print(" G: ");
        Serial.print(g);
        Serial.print(" B: ");
        Serial.print(b);
        
        setColor(r, g, b);
      }
      receivedString = "";
    }
    else {
      receivedString += c;
    }
  }
}

void setColor(int r, int g, int b) {
  for (int i = 0; i < LED_COUNT; i++) {
  strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}
