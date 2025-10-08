#include <ESP8266WiFi.h>
#include <DHT.h>

const char* ssid = "***********";
const char* password = "*****";
WiFiServer server(80);
WiFiClient client;

int relay = D1;
int PIN_DHT = D2;
int buzzer = D8;
DHT DHTsensor(PIN_DHT, DHT11);

void setup() {
  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("Server started");
  
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

  DHTsensor.begin();
}

void loop() {
  client = server.available();
  if(!client) return;

  Serial.println("새로운 클라이언트");
  while (!client.available()) {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println("request: ");
  Serial.println(request);
  client.flush();

  float humidity = DHTsensor.readHumidity();
  float temp = DHTsensor.readTemperature();


  if(request.indexOf("/ON") != -1) {
    digitalWrite(relay, LOW);
  }
  
  if(request.indexOf("/OFF") != -1) {
    digitalWrite(relay, HIGH);
  }
  
  if(-5>=temp && 40<=temp) {
    digitalWrite(relay, HIGH);
    tone(buzzer, 987);
    delay(1000);
    tone(buzzer, 523);
    delay(1000);
  }

  if(humidity >= 85) {
    digitalWrite(relay, HIGH);
    tone(buzzer, 987);
    delay(1000);
    tone(buzzer, 523);
    delay(1000);
  }

  else {
    noTone(buzzer);
  }


  client.print("HTTP/1.1 200 OK");
  client.print("Content-Type: text/html\r\n\r\n");
  client.print("<!DOCTYPE HTML>");
  client.print("<html>");
  client.print("<head>");
  client.print("<meat charset=\"UTF-8\"http-equiv=\"refresh\"content=\"1\">");
  client.print("<title>multitap controller</title>");
  client.print("</head>");
  client.print("<body>");
  client.print("<h2>multitap controller</h2>");
  client.print("<br>");
  client.print("<a href=\"/ON\"\"><button>ON</button></a>");
  client.print("<a href=\"/OFF\"\"><button>OFF</button></a>");
  client.print("<br>");
  client.print("<Temperature: >");
  client.print(temp);
  client.print("&#8451");
  client.print("<br>");
  client.print("<Humidity: >");
  client.print(humidity);
  client.print("%");
  client.print("</body>");
  client.print("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
