/*
 * The LCD circuit:
 *
 *  LCD RS pin to digital pin 12
 *  LCD Enable pin to digital pin 11
 *  LCD D4 pin to digital pin 5
 *  LCD D5 pin to digital pin 4
 *  LCD D6 pin to digital pin 3
 *  LCD D7 pin to digital pin 2
 *  LCD R/W pin to ground
 *  LCD VSS pin to ground
 *  LCD VCC pin to 5V
 *  10K resistor, ends to +5V and ground & wiper to LCD VO pin (pin 3)
 *
 * --------------
 *
 * The Bluetooth:
 *
 *  RX to Arduino TX
 *  TX to Arduino RX
 *  VCC to 5V
 *  GND to GND
 *
 * --------------
 *
 * LDR Circuit :
 *
 *  Pin to ground + pull down resistor
 *  Pin to Analog Pin A0
 *
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int sensorPin = A0;
int sensorValue = 0;

const String ID = "ID123345";

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {

  sensorValue = analogRead(A0);

  if (sensorValue < 500) { //This value is subject to change according to the pool lighting to provide the best response

    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("MATE 2017");

    Serial.print("MATE 2017");
    Serial.write(0); //Terminating character sent over UART (0 == 0x00 == NULL == '\0')

    lcd.setCursor(0, 1);
    lcd.print("No Light ");

  } else {

    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print(ID);

    Serial.print(ID);
    Serial.write(0); //Terminating character sent over UART (0 == 0x00 == NULL == '\0')

    lcd.setCursor(0, 1);
    lcd.print("Light Detected");

  }

  delay(2000);
}
