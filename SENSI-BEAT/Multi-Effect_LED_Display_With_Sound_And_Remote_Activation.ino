#include <IRremote.h>

#define IR_RECEIVE_PIN 2
#define SOUND_SENSOR A0
#define POT_PIN A1

#define LED_FADE     3   // Blue
#define LED_BLINK    5   // Red
#define LED_SOUND    6   // Yellow
#define LED_FLICKER  9   // White
#define LED_GREEN    10  // Green - Party Mode Indicator

#define POWER_BTN 0x12
#define PLAY_BTN  0x01

bool isPoweredOn = false;
bool isPartyMode = false;

unsigned long lastFlickerTime = 0;
unsigned long lastBurstTime = 0;
int burstCount = 0;
bool burstState = false;

int pulseValue = 0;
int pulseDirection = 5;
unsigned long lastPulseTime = 0;
const int pulseDelay = 20;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  pinMode(LED_FADE, OUTPUT);
  pinMode(LED_BLINK, OUTPUT);
  pinMode(LED_SOUND, OUTPUT);
  pinMode(LED_FLICKER, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  randomSeed(analogRead(A2));
}

void loop() {
  if (IrReceiver.decode()) {
    if (!(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) {
      uint32_t command = IrReceiver.decodedIRData.command;
      Serial.print("IR Command: ");
      Serial.println(command, HEX);

      if (command == POWER_BTN) {
        isPoweredOn = !isPoweredOn;
        if (!isPoweredOn) turnOffAllLEDs();
      } else if (command == PLAY_BTN && isPoweredOn) {
        isPartyMode = !isPartyMode;
        if (!isPartyMode) {
          digitalWrite(LED_GREEN, LOW);  // Turn off Green LED when Party Mode is off
        }
      }
    }
    IrReceiver.resume();
  }

  if (isPoweredOn) {
    if (isPartyMode) {
      partyMode();
    } else {
      staticMode();
    }
  }
}

// Static Mode: All LEDs ON (no effects) 
void staticMode() {
  analogWrite(LED_FADE, 255);
  analogWrite(LED_BLINK, 255);
  analogWrite(LED_SOUND, 255);
  analogWrite(LED_FLICKER, 255);
  digitalWrite(LED_GREEN, LOW);  // Green OFF in static mode
}

// === Party Mode ===
void partyMode() {
  errorBurstBlue();     // Blue - Burst flashes
  soundRedLED();        // Red - Sound reactive
  fadeYellowLED();      // Yellow - Smooth fade
  flickerWhiteLED();    // White - Flicker
  digitalWrite(LED_GREEN, HIGH);  // Green always ON in party mode
}

// Blue LED: Error Burst Effect
void errorBurstBlue() {
  unsigned long currentMillis = millis();
  if (burstCount < 3) {
    if (currentMillis - lastBurstTime >= 80) {
      lastBurstTime = currentMillis;
      burstState = !burstState;
      digitalWrite(LED_FADE, burstState);
      if (!burstState) burstCount++;
    }
  } else {
    if (currentMillis - lastBurstTime >= 1500) {
      burstCount = 0;
    }
    digitalWrite(LED_FADE, LOW);
  }
}

// Red LED: Sound Reactive 
void soundRedLED() {
  int soundVal = analogRead(SOUND_SENSOR);
  int threshold = analogRead(POT_PIN) / 4;
  digitalWrite(LED_BLINK, soundVal > threshold ? HIGH : LOW);
}

// Yellow LED: Fading 
void fadeYellowLED() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastPulseTime >= pulseDelay) {
    lastPulseTime = currentMillis;

    pulseValue += pulseDirection;
    if (pulseValue <= 0 || pulseValue >= 255) {
      pulseDirection = -pulseDirection;
      pulseValue = constrain(pulseValue, 0, 255);
    }

    analogWrite(LED_SOUND, pulseValue);
  }
}

// White LED: Flickering 
void flickerWhiteLED() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastFlickerTime >= random(10, 50)) {
    lastFlickerTime = currentMillis;
    int flickerBrightness = random(150, 255);
    analogWrite(LED_FLICKER, flickerBrightness);
  }
}

// Turn off all LEDs
void turnOffAllLEDs() {
  digitalWrite(LED_FADE, LOW);
  digitalWrite(LED_BLINK, LOW);
  digitalWrite(LED_SOUND, LOW);
  digitalWrite(LED_FLICKER, LOW);
  digitalWrite(LED_GREEN, LOW); // Green LED off when powered off
}
