#include <Servo.h>
#include <LiquidCrystal.h>

#define TOUCH_PIN 2
#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6
#define BUZZER_PIN A0  

Servo myServo;
LiquidCrystal lcd(4, 7, 8, 10, 11, 12); // RS, EN, D4-D7

unsigned long lastTapTime = 0;
int tapCount = 0;
unsigned long tapDisplayTime = 0;
bool showTap = false;

void setup() {
  pinMode(TOUCH_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  noTone(BUZZER_PIN);

  myServo.attach(9);
  myServo.write(0); // Locked

  Serial.begin(9600);
  lcd.begin(16, 2);

  welcomeScreen();
  lcd.print("Enter Password");
  setColor(0, 0, 255); // Blue = idle
}

void loop() {
  static bool lastTouch = LOW;
  bool currentTouch = digitalRead(TOUCH_PIN);

  if (currentTouch == HIGH && lastTouch == LOW) {
    unsigned long now = millis();
    Serial.println("Tap!");
    lcd.clear();
    lcd.print("Tap Detected");
    showTap = true;
    tapDisplayTime = now;

    if (tapCount == 0 || (now - lastTapTime <= 2000)) {
      tapCount++;
      lastTapTime = now;
    } else {
      tapCount = 1;
      lastTapTime = now;
    }

    delay(40); // debounce
  }

  lastTouch = currentTouch;

  if (showTap && millis() - tapDisplayTime > 500) {
    lcd.clear();
    lcd.print("Enter Password");
    showTap = false;
  }

  if (tapCount == 3 && millis() - lastTapTime > 300) {
    unlockBox();
    tapCount = 0;
  }

  if (tapCount > 0 && millis() - lastTapTime > 2500) {
    errorState();
    tapCount = 0;
  }
}

void unlockBox() {
  Serial.println("Access Granted");
  lcd.clear();
  lcd.print("Unlocked");

  setColor(0, 255, 0); // Green
  tone(BUZZER_PIN, 1000, 200); 
  delay(300);

  lcd.clear();
  lcd.print("Access Granted");
  myServo.write(90);
  delay(4000);

  myServo.write(0);
  lcd.clear();
  lcd.print("Locked");
  setColor(0, 0, 255);
  delay(1500);
  lcd.clear();
  lcd.print("Enter Password");
}

void errorState() {
  Serial.println("Wrong Password");
  lcd.clear();
  lcd.print("Wrong Password");

  for (int i = 0; i < 3; i++) {
    setColor(255, 0, 0);  // Red ON
    tone(BUZZER_PIN, 1000, 150);
    delay(150);
    setColor(0, 0, 0);    // OFF
    delay(100);
  }

  delay(1250); // Wrong password stays 1.5s
  setColor(0, 0, 255);
  lcd.clear();
  lcd.print("Enter Password");
}

void welcomeScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TouchVault v1.0");
  setColor(128, 0, 128); // Purple
  delay(3000);
  lcd.clear();
}

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, 255 - r);
  analogWrite(GREEN_PIN, 255 - g);
  analogWrite(BLUE_PIN, 255 - b);
}
