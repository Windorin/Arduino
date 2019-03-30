#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#define SSID "iPhone"
#define PASS "inginirium"

WiFiUDP myesp;
IPAddress server(192, 168, 4, 1);
char incomingPacket[255];
void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin(SSID, PASS);
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
  int packetSize = myesp.parsePacket();
  if (packetSize)
  {
    int len = myesp.read(incomingPacket, 255);
    if (len > 0)
    { incomingPacket[len] = 0;
    }
    String answer = incomingPacket;
    Serial.printf("incoming packet: %s\n", incomingPacket);
  }
}
