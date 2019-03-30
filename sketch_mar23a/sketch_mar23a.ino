void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(D8,OUTPUT);
pinMode(D6,INPUT);
digitalWrite(D8,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
int s1gnal = digitalRead(D8);
Serial.println(s1gnal);
if(s1gnal==HIGH)
digitalWrite(D5,HIGH);

if(4==HIGH)
{
digitalWrite(D7,HIGH);
}
if(s1gnal==LOW)
{
digitalWrite(D6,HIGH);
}
}
