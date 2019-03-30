byte val = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    val = Serial.read()-48;
    Serial.print("You send:");
    Serial.print(val);
    Serial.println();
  }
}
