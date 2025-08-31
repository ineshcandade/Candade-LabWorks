#include <EEPROM.h>

const int buttonPins[4] = {2, 4, 6, 8};  
const int ledPin = 11;  
const int buzzerPin = 12;  

int enteredPassword[4];  
int index = 0;  

unsigned long lastDebounceTime[4] = {0, 0, 0, 0};  
const unsigned long debounceDelay = 50;  
bool lastButtonState[4] = {HIGH, HIGH, HIGH, HIGH};  
bool buttonState[4] = {HIGH, HIGH, HIGH, HIGH};  

void setup() {
  Serial.begin(9600);  

  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    EEPROM.update(i, (i == 0) ? 4 : (i == 1) ? 1 : (i == 2) ? 3 : 2);  // Set password as 4, 1, 3, 2
  }

  pinMode(ledPin, OUTPUT);  
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {
  for (int i = 0; i < 4; i++) {
    bool reading = digitalRead(buttonPins[i]);  

    if (reading != lastButtonState[i]) {
      lastDebounceTime[i] = millis();  
    }

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      if (reading != buttonState[i]) {
        buttonState[i] = reading;

        if (buttonState[i] == LOW) {
          enteredPassword[index] = i + 1;  
          index++;  
          Serial.print("Button ");
          Serial.print(i + 1);  
          Serial.println(" Pressed");
          delay(300);  // Small delay to avoid multiple entries
        }
      }
    }

    lastButtonState[i] = reading;  
  }

  if (index == 4) {
    bool isCorrect = true;

    for (int i = 0; i < 4; i++) {
      if (EEPROM.read(i) != enteredPassword[i]) {
        isCorrect = false;
        break;
      }
    }

    if (isCorrect) {
      Serial.println("Password Correct!");
      tone(buzzerPin, 1000, 1000);  
      digitalWrite(ledPin, LOW);  
    } else {
      Serial.println("Password Incorrect!");
      digitalWrite(ledPin, HIGH); 
      for (int i = 0; i < 3; i++) {
        tone(buzzerPin, 2000, 100);  
        delay(150);
      }
      digitalWrite(ledPin, LOW);  
    }

    delay(2000);  
    index = 0;  
  }
}
