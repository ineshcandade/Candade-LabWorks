#include <LiquidCrystal.h>

LiquidCrystal lcd(4, 7, 8, 10, 11, 12);  // RS, EN, D4–D7

const int capPin = A0;    
const int dischargePin = 2; 

const int redPin   = 5;
const int bluePin  = 6;
const int greenPin = 9;  

void setup() {
  lcd.begin(16, 2);
  
  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW); // transistor OFF initially
  
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  lcd.print("SYS: Booting...");
  delay(1000);
}

void loop() {
  int raw = analogRead(capPin);
  float voltage = (raw / 1023.0) * 5.0;

  lcd.setCursor(0, 0);

  if (voltage > 4.7) {
    // trigger discharge
    digitalWrite(dischargePin, HIGH);
    lcd.print("SYS: DISCHARGING ");
    setRGB(255, 0, 0);  // Red 
  }
  else if (voltage < 1.0) {
    // stop discharge and let it charge via resistor
    digitalWrite(dischargePin, LOW);
    lcd.print("SYS: CHARGING... ");
    setRGB(0, 255, 0);  // Green
  }
  else {
    lcd.print("SYS: STABLE      ");
    setRGB(0, 0, 255);  // Blue
  }

  lcd.setCursor(0, 1);
  lcd.print("V: ");
  lcd.print(voltage, 2);
  lcd.print("V   ");

  delay(200);
}

// Inverted logic for common-anode RGB
void setRGB(int r, int g, int b) {
  analogWrite(redPin,   255 - r);
  analogWrite(greenPin, 255 - g);
  analogWrite(bluePin,  255 - b);
}
