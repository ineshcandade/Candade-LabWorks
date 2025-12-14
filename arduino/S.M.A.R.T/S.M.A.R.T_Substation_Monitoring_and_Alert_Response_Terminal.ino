#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define VOLTAGE_PIN A0
#define RELAY_PIN 6
#define BUTTON_PIN 7
#define FLAME_PIN 3

#define RED_LED 9
#define YELLOW_LED 10
#define GREEN_LED 11
#define BUZZER 12

bool dangerLatched = false;
bool buttonPreviouslyPressed = false;
bool bootScreenShown = false;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
bool lastButtonState = HIGH;
bool currentButtonState;

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); 

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(FLAME_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds("S.M.A.R.T", 0, 0, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;
  int y = (SCREEN_HEIGHT - h) / 2 - y1;
  display.setCursor(x, y);
  display.println("S.M.A.R.T");
  display.display();
  delay(2000);
}

void loop() {
  int voltageRaw = analogRead(VOLTAGE_PIN);
  float temperature = dht.readTemperature();
  bool flameDetected = digitalRead(FLAME_PIN) == LOW;

  bool isVoltageHigh = voltageRaw > 180;
  bool isTempHigh = temperature > 40;
  bool isDangerNow = isVoltageHigh || isTempHigh || flameDetected;

  if (isDangerNow) {
    dangerLatched = true;
  }

  bool reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && !buttonPreviouslyPressed && !isDangerNow) {
      Serial.println("Manual reset pressed. Relay ON.");
      dangerLatched = false;
    }
    buttonPreviouslyPressed = (reading == LOW);
  }

  lastButtonState = reading;

  digitalWrite(RELAY_PIN, dangerLatched ? HIGH : LOW);

  if (dangerLatched) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);

    if (flameDetected) {
      blinkFast(RED_LED);
      flameBuzzer();
    } else if (isVoltageHigh) {
      fadeRedLED();
      alertBuzzer();
    } else if (isTempHigh) {
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, HIGH);
      normalBeep();
    }
  } else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZZER);
  }

  // --- OLED Display Logic ---
  display.clearDisplay();

  if (dangerLatched) {
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds("DANGER", 0, 0, &x1, &y1, &w, &h);
    int x = (SCREEN_WIDTH - w) / 2;
    display.setCursor(x, 5);
    display.println("DANGER");

    display.setTextSize(1);
    const char* subMsg = "";
    if (flameDetected) {
      subMsg = "FIRE DETECTED!";
    } else if (isVoltageHigh) {
      subMsg = "High Voltage";
    } else if (isTempHigh) {
      subMsg = "High Temp";
    }

    display.getTextBounds(subMsg, 0, 0, &x1, &y1, &w, &h);
    int subX = (SCREEN_WIDTH - w) / 2;
    display.setCursor(subX, 40);
    display.println(subMsg);
  } else {
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds("Substation Monitor", 0, 0, &x1, &y1, &w, &h);
    int headerX = (SCREEN_WIDTH - w) / 2;
    display.setCursor(headerX, 0);
    display.println("Substation Monitor");
    display.setCursor(0, 10);
    display.println("---------------------");

    // Sensor readings
    display.setCursor(0, 22);
    display.print("Voltage: ");
    display.println(voltageRaw);

    display.print("Temp: ");
    display.print(temperature);
    display.println(" C");

    display.print("Flame: ");
    display.println(flameDetected ? "YES" : "Safe");

    display.setTextSize(2);
    display.getTextBounds("NORMAL", 0, 0, &x1, &y1, &w, &h);
    int normalX = (SCREEN_WIDTH - w) / 2;
    display.setCursor(normalX, 48);
    display.println("NORMAL");
  }

  display.display();
  delay(200);
}

// --- Helper Functions ---

void fadeRedLED() {
  for (int i = 0; i < 255; i += 15) {
    analogWrite(RED_LED, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i -= 15) {
    analogWrite(RED_LED, i);
    delay(10);
  }
}

void blinkFast(int pin) {
  digitalWrite(pin, HIGH);
  delay(50);
  digitalWrite(pin, LOW);
  delay(50);
}

void flameBuzzer() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER, 1000);
    delay(100);
    noTone(BUZZER);
    delay(100);
  }
}

void alertBuzzer() {
  tone(BUZZER, 2000);
  delay(500);
  noTone(BUZZER);
  delay(200);
}

void normalBeep() {
  tone(BUZZER, 1000);
  delay(200);
  noTone(BUZZER);
}
