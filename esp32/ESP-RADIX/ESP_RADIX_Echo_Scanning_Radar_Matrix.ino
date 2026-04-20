#include "LedControl.h"
#include "ESP32Servo.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define LED_DIN_PIN 23
#define LED_CLK_PIN 19
#define LED_CS_PIN  5
#define NUM_DEVICES 4   // 4 x 8x8 = 32 columns

#define TRIG_PIN 26
#define ECHO_PIN 25
#define SERVO_PIN 27
#define BUZZER_PIN 14

LedControl lc = LedControl(LED_DIN_PIN, LED_CLK_PIN, LED_CS_PIN, NUM_DEVICES);
Servo myServo;

long duration;
int distance;
int lastValidDistance = 0;   // for filtering

const int BASELINE_ROW = 7;

int trailBuffer[32][8];  // intensity buffer (0–3)
int lastHeight = 0;

// Orientation: adjust if needed (0 = normal, 1 = flipped)
int orientation[NUM_DEVICES] = {1, 1, 1, 1};

// Servo sweep tracking
int angle = 0;
int stepDir = 1; // 1 = forward, -1 = backward
unsigned long lastServoMove = 0;
const int SERVO_INTERVAL = 10; // ms per step

unsigned long lastBuzzerToggle = 0;
bool buzzerOn = false;

void fadeBuffer() {
  for (int x = 0; x < 32; x++) {
    for (int y = 0; y < 8; y++) {
      if (trailBuffer[x][y] > 0) {
        trailBuffer[x][y]--; // decay intensity
      }
    }
  }
  for (int x = 0; x < 32; x++) {
    trailBuffer[x][BASELINE_ROW] = 3;
  }
}

void drawMountain(int peakCol, int peakHeight) {
  if (peakHeight < 0) return;

  int spread = 8;   
  int flatTop = 2;  

  for (int offset = -spread; offset <= spread; offset++) {
    int col = peakCol + offset;
    if (col < 0 || col > 31) continue;

    int h = peakHeight - max(0, abs(offset) - flatTop);
    if (h < 0) continue;

    for (int r = 0; r <= h; r++) {
      trailBuffer[col][6 - r] = 3; // reset to max intensity
    }
  }
}

void pushToLEDs() {
  for (int dev = 0; dev < NUM_DEVICES; dev++) {
    int baseCol = dev * 8;
    for (int col = 0; col < 8; col++) {
      int mappedCol = (orientation[dev] == 0) ? col : (7 - col);
      for (int row = 0; row < 8; row++) {
        bool state = (trailBuffer[baseCol + col][row] > 0);
        lc.setLed(dev, row, mappedCol, state);
      }
    }
  }
}

int getHeightFromDistance(int dist) {
  if (dist < 0) return -1;

  if (dist <= 5) return 6;
  if (dist <= 10) return 5;
  if (dist <= 15) return 4;
  if (dist <= 20) return 3;
  if (dist <= 25) return 2;
  if (dist <= 30) return 1;
  return 0;
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH, 20000);
  return duration * 0.034 / 2;
}

int getFilteredDistance() {
  int d = getDistance();
  if (d == 0 || d > 200) {
    return lastValidDistance;  
  } else {
    lastValidDistance = d;
    return d;
  }
}

void updateOLED(int distance, int angle) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Dist:");
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(distance);
  display.println(" cm");

  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Angle:");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(angle);
  display.println(" deg");

  display.display();
}

void handleBuzzer(int distance) {
  unsigned long now = millis();

  if (distance > 0 && distance <= 5) {
    tone(BUZZER_PIN, 1000); 
    buzzerOn = true;
  } else if (distance <= 10) {
    if (now - lastBuzzerToggle >= 200) { 
      lastBuzzerToggle = now;
      if (buzzerOn) {
        noTone(BUZZER_PIN);
        buzzerOn = false;
      } else {
        tone(BUZZER_PIN, 600);
        buzzerOn = true;
      }
    }
  } else {
    noTone(BUZZER_PIN);
    buzzerOn = false;
  }
}

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("ESP-RADIX");  
  display.display();
  delay(3000);

  for (int i = 0; i < NUM_DEVICES; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 8);
    lc.clearDisplay(i);
  }

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN);
  pinMode(BUZZER_PIN, OUTPUT);

  for (int x = 0; x < 32; x++) {
    for (int y = 0; y < 8; y++) {
      trailBuffer[x][y] = 0;
    }
    trailBuffer[x][BASELINE_ROW] = 3;
  }
}

void loop() {
  unsigned long now = millis();

  if (now - lastServoMove >= SERVO_INTERVAL) {
    lastServoMove = now;
    angle += stepDir;

    if (angle >= 180) {
      stepDir = -1;
    } else if (angle <= 0) {
      stepDir = 1;
    }

    myServo.write(angle);

    distance = getFilteredDistance();
    int targetHeight = getHeightFromDistance(distance);

    if (targetHeight > lastHeight) {
      lastHeight++;
    } else if (targetHeight < lastHeight) {
      lastHeight--;
    }

    int peakCol = map(angle, 0, 180, 0, 31);

    fadeBuffer();
    drawMountain(peakCol, lastHeight);
    pushToLEDs();

    updateOLED(distance, angle);
    handleBuzzer(distance);
  }
}
