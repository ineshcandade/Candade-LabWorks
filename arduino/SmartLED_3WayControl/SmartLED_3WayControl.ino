#define LED_1_PIN 12
#define LED_2_PIN 11 // PWM pin
#define LED_3_PIN 10

#define BUTTON_PIN 2
#define POTENTIOMETER_PIN A2

unsigned long previousTimeLED1Blink = millis();
unsigned long blinkDelayLED1 = 500;

int LED1State = LOW;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // Serial input for LED 1 blink rate
  if (Serial.available() > 0) {
    int data = Serial.parseInt();
    if (data >= 100 && data <= 4000) {
      blinkDelayLED1 = data;
    }
  }

  // Blink LED 1 with adjustable delay
  unsigned long timeNow = millis();
  if (timeNow - previousTimeLED1Blink > blinkDelayLED1) {
    LED1State = !LED1State;
    digitalWrite(LED_1_PIN, LED1State);
    previousTimeLED1Blink += blinkDelayLED1;
  }

  // LED 2 brightness via potentiometer
  int potValue = analogRead(POTENTIOMETER_PIN);
  int brightness = map(potValue, 0, 1023, 0, 255);
  analogWrite(LED_2_PIN, brightness);

  // LED 3 responds to button press
  digitalWrite(LED_3_PIN, digitalRead(BUTTON_PIN));

  // 👇 Clean and professional serial debug output
  Serial.print("[Pot Value: ");
  Serial.print(potValue);
  Serial.print("] [PWM: ");
  Serial.print(brightness);
  Serial.print("] [LED1 Blink Delay: ");
  Serial.print(blinkDelayLED1);
  Serial.println(" ms]");
  
  delay(100); // Optional smoothing
}




