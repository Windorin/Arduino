
#include <ESP8266WiFi.h>



void setup() {
  Serial.begin(115200);
  WiFi.begin("network-name", "pass-to-network");
  Serial.print("Connection");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }

  Serial.println();
  Serial.print("Connected, IP address: ");
  while (true) {
    Serial.println(WiFi.localIP());
    delay(1000);
  }
}

void loop() {}
