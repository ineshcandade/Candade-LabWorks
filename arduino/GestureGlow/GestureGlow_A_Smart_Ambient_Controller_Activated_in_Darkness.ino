#include <Servo.h>

// --- Pin Definitions ---
const int irPin = 2;
const int redPin = 9;
const int yellowPin = 10; 
const int bluePin = 11;
const int servoPin = 6;
const int ldrPin = A0; 

// --- State Variables ---
bool lastIrState = HIGH;
bool gestureWindowActive = false;
int gestureCount = 0;
unsigned long gestureStartTime = 0;
int ldrThreshold = 520; // Adjust this based on your environment

Servo myServo;

// --- Setup ---
void setup() {
  pinMode(irPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(90); // Neutral start

  clearLEDs();

  Serial.begin(9600);
}

// --- Utility Functions ---
void clearLEDs() {
  analogWrite(redPin, 0);
  analogWrite(yellowPin, 0);
  analogWrite(bluePin, 0);
}

void setLEDs(int r, int y, int b) {
  analogWrite(redPin, r);
  analogWrite(yellowPin, y);
  analogWrite(bluePin, b);
}

// --- Gesture Handler ---
void handleGestureActions() {
  Serial.print("Gesture Count: ");
  Serial.println(gestureCount);

  unsigned long startTime = millis();

  if (gestureCount == 1) {
    myServo.write(0);
    delay(500);
    while (millis() - startTime < 3000) {
      setLEDs(0, 0, 255); delay(250);  // Blue
      clearLEDs(); delay(250);
    }

  } else if (gestureCount == 2) {
    myServo.write(90);
    delay(500);
    while (millis() - startTime < 3000) {
      setLEDs(255, 0, 0); delay(300);  // Red
      setLEDs(0, 0, 255); delay(300);  // Blue
    }

  } else if (gestureCount == 3) {
    myServo.write(180);
    delay(500);
    while (millis() - startTime < 3000) {
      setLEDs(255, 0, 0); delay(300);   // Red
      setLEDs(255, 255, 0); delay(300); // Yellow
      setLEDs(0, 0, 255); delay(300);   // Blue
    }
  }

  clearLEDs();
  gestureCount = 0;
  gestureWindowActive = false;
}

// --- IR Input Monitor ---
void checkGesture() {
  bool irState = digitalRead(irPin);
  Serial.print("IR State: ");
  Serial.println(irState);

  if (lastIrState == HIGH && irState == LOW) {
    if (!gestureWindowActive) {
      gestureWindowActive = true;
      gestureStartTime = millis();
      gestureCount = 1;
    } else {
      gestureCount++;
    }
  }

  lastIrState = irState;

  if (gestureWindowActive && millis() - gestureStartTime > 2000) {
    handleGestureActions();
  }
}

// --- Main Loop ---
void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < ldrThreshold) {
    // Only check gestures in the dark
    checkGesture();
  } else {
    // If it's bright, reset everything
    gestureWindowActive = false;
    gestureCount = 0;
    clearLEDs();
    myServo.write(90); // Reset to center
  }

  delay(50); 
}
