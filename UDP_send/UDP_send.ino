#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#define SSID1 "LOX_Point"
#define PASS1 "TryToKnowIt"

WiFiUDP myesp;
IPAddress server(192, 168, 4, 1);

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin(SSID1, PASS1);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP());
  myesp.begin(80);
}

void loop() {
  Serial.println(" Sending the pack..");
  myesp.beginPacket(server, 80);
  myesp.print("Hello, we first send this string \r");
  myesp.endPacket();
  delay(10000);
}
