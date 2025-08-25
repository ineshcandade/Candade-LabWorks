#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin Definitions
#define TRIG_PIN 3
#define ECHO_PIN 4
#define DHT_PIN 2
#define DHT_TYPE DHT22
#define TILT_PIN 7

#define LED_GREEN 9
#define LED_RED 11
#define LED_BLUE 10

#define BUZZER_PIN 12  

// Sensor initialization
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    while (true);
  }

  // --- Splash Screen Start ---
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds("S.E.A.M", 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT / 2) - h);
  display.println("S.E.A.M");

  display.setTextSize(1);
  int16_t x_offset = 10;  

 display.setTextSize(1);

 String creditText = "-INESH & THEJAS";
 display.getTextBounds(creditText, 0, 0, &x1, &y1, &w, &h);
 display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT / 2) + 5);
 display.println(creditText);



  display.display();
  delay(3000);
  // --- Splash Screen End ---

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TILT_PIN, INPUT);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); 

  dht.begin();
}

void loop() {
  // ----- Ultrasonic Sensor -----
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
  int distance = (duration == 0) ? -1 : duration * 0.034 / 2;

  // ----- DHT22 Sensor -----
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) {
    temperature = 0;
    humidity = 0;
  }

  // ----- Tilt Sensor -----
  bool tiltState = digitalRead(TILT_PIN); // HIGH = stable, LOW = tilted
  String tiltLabel = tiltState ? "No" : "Yes";

  // ----- Status Check -----
  bool danger = false;
  String statusLabel = "SAFE";

  if (!tiltState || distance < 5 || distance == -1 || temperature > 40 || humidity < 20 || humidity > 100) {
    danger = true;
    statusLabel = "DANGER";
  }

  // ----- LEDs -----
  digitalWrite(LED_RED, !tiltState ? HIGH : LOW);
  digitalWrite(LED_BLUE, (distance < 5 || distance == -1) ? HIGH : LOW);
  digitalWrite(LED_GREEN, (statusLabel == "SAFE") ? HIGH : LOW);

  // ----- Buzzer Logic -----
  if (!tiltState) {
    digitalWrite(BUZZER_PIN, HIGH);  
  } else if (distance < 5 || distance == -1) {
    tone(BUZZER_PIN, 1000);  
    delay(200);
    noTone(BUZZER_PIN);
  } else {
    noTone(BUZZER_PIN);
  }

  // ----- Serial Debug -----
  Serial.print("Distance: "); Serial.print(distance); Serial.print(" cm, ");
  Serial.print("Temp: "); Serial.print(temperature); Serial.print(" C, ");
  Serial.print("Hum: "); Serial.print(humidity); Serial.print(" %, ");
  Serial.print("Tilted: "); Serial.println(tiltLabel);

  // ----- OLED Display -----
  display.clearDisplay();
  display.setCursor(0, 0);

  display.print("Dist: ");
  display.print((distance == -1) ? 0 : distance);
  display.println(" cm");

  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.print("Hum: ");
  display.print(humidity);
  display.println(" %");

  display.print("Tilt: ");
  display.println(tiltLabel);

  display.setTextSize(2);
  display.setCursor(0, 35);  
  display.println(statusLabel);
  display.setTextSize(1);

  display.display();
  delay(1500);
}

