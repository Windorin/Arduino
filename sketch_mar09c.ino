#include <ESP8266WiFi.h> 
const char* ssid ="MegaFonMR150-2-A576AB";

const char* password = "CDDnPD8nAt";  //Your Wifi Password
int ledPin = 16; 
WiFiServer server(80);
void setup() {
  Serial.begin(115200);

  delay(10); 
  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(ledPin, LOW); 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected"); 
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/"); 
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  } 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush(); 
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("teeeest"); 
  client.println(analogRead(A0));
  client.println("");
  client.print("Led is : "); 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }  client.println("");  
client.println(" On ");
   client.println(" Off ");  
   client.println(" <p> ");  
  client.println(" <a href=\"/LED=OFF\"><button>ON</button></a> ");
  client.println(" <a href=\"/LED=ON\"><button>,OFF</button></a> ");
   client.println(" <p> ");  
   client.println(" sensor value:  ");  
    client.println(analogRead(A0));
        Serial.println(analogRead(A0));
     delay(1);
   Serial.println("Client disonnected");
  Serial.println("");   }
