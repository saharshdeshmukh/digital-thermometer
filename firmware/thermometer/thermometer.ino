#include <LiquidCrystal.h>

// LCD pin connections: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int LM35_PIN = A0; // LM35 analog pin
void setup() {
  // put your setup code here, to run once:void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // initialize LCD
  lcd.print("Digital Thermometer");
  delay(2000);
  lcd.clear();
}




void loop() {
  // put your main code here, to run repeatedly:void loop() {
  int analogValue = analogRead(LM35_PIN);

  float voltage = analogValue * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print((char)223); // degree symbol
  lcd.print("C");

  delay(1000);
}


}
