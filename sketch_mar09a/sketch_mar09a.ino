#include <Wire.h>
#include <Strela.h>
#include <FastIO.h>
#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_SR3W.h>

LiquidCrystal_I2C lcd(LC_ADDR,LCEN,LCRW,LCRS,LC4,LC5,LC6,LC7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(8,2);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.home();
lcd.print("waiting");
if(Serial.available()>0)
{
  Serial.readBytes(text,8);
Serial.println(text);
lcd.clear();
lcd.home();
lcd.print(text);
delay(3000);
lcd.clear();
  memset(text,0,9);
  
  }
  
}
