#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
const int vibrationPin = 2;
const int redLED = 7;
const int greenLED = 6;
const int trigPin = 3;
const int echoPin = 4;
const int servoPin = 5;
const int buzzerPin = 8;
const int resetPin = A0;

Servo gateServo;

bool systemActive = false;
unsigned long activationTime = 0;
const unsigned long activationDuration = 20000;

int vehicleCount = 0;

void setup() {
  Serial.begin(9600);

  pinMode(vibrationPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(resetPin, INPUT_PULLUP);

  gateServo.attach(servoPin);
  gateServo.write(0);

  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (true);
  }

  centerScreenText("V-GATE", 3);
  delay(3000);
  updateDisplay(vehicleCount);
}

void loop() {
  // Reset Button Check
  if (digitalRead(resetPin) == LOW) {
    vehicleCount = 0;
    Serial.println("Vehicle count reset!");
    updateDisplay(vehicleCount);
    delay(500);
  }

  int vibrationVal = digitalRead(vibrationPin);

  if (vibrationVal == HIGH && !systemActive) {
    Serial.println("Vibration Detected");
    systemActive = true;
    activationTime = millis();
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

    display.clearDisplay();
    centerLineText("Proceed to", 2, 0);
    centerLineText("Gate", 2, 30);
    display.display();
    delay(2500);
    updateDisplay(vehicleCount);
  }

  if (systemActive) {
    if (millis() - activationTime <= activationDuration) {
      long distance = measureDistance();

      Serial.print("Distance: ");
      Serial.println(distance);

      if (distance > 2 && distance < 5) {
        Serial.println("Vehicle Detected!");
        openGate();
        beepBuzzer();
        delay(1200);
        closeGate();

        vehicleCount++;
        updateDisplay(vehicleCount);

        while (measureDistance() < 5) {
          delay(50);
        }
      }

    } else {
      Serial.println("Session Expired");
      systemActive = false;
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);

      display.clearDisplay();
      centerLineText("Gate", 2, 0);
      centerLineText("Closed", 2, 30);
      display.display();
      delay(2500);
      updateDisplay(vehicleCount);
    }
  }
}

// --- FUNCTIONS ---

long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 20000);
  long distance = duration * 0.034 / 2;
  return distance;
}

void openGate() {
  gateServo.write(70);
  Serial.println("Gate Opened");
}

void closeGate() {
  gateServo.write(0);
  Serial.println("Gate Closed");
}

void beepBuzzer() {
  digitalWrite(buzzerPin, HIGH);
  delay(300);
  digitalWrite(buzzerPin, LOW);
}

void updateDisplay(int count) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Vehicle Count:");

  String countStr = String(count);
  int16_t x1, y1;
  uint16_t w, h;
  display.setTextSize(3);
  display.getTextBounds(countStr, 0, 0, &x1, &y1, &w, &h);

  // Proper center alignment with padding
  int boxW = w + 14;
  int boxH = h + 14;
  int boxX = (SCREEN_WIDTH - boxW) / 2;
  int boxY = (SCREEN_HEIGHT - boxH) / 2 + 8;

  int textX = (SCREEN_WIDTH - w) / 2;
  int textY = (SCREEN_HEIGHT - h) / 2 + 8;

  display.drawRect(boxX, boxY, boxW, boxH, SSD1306_WHITE);
  display.setCursor(textX, textY);
  display.println(countStr);
  display.display();
}

// --- OLED Text Helpers ---

void centerScreenText(String text, int textSize) {
  display.clearDisplay();
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);

  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

  int x = (SCREEN_WIDTH - w) / 2;
  int y = (SCREEN_HEIGHT - h) / 2;

  display.setCursor(x, y);
  display.println(text);
  display.display();
}

void centerLineText(String text, int textSize, int y) {
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);

  int16_t x1, y1_tmp;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1_tmp, &w, &h);

  int x = (SCREEN_WIDTH - w) / 2;
  display.setCursor(x, y);
  display.println(text);
}


