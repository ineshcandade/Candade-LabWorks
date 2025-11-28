#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <EEPROM.h>

// ===== OLED Setup =====
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ===== DHT Setup =====
#define DHTPIN 15        
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);

// ===== EEPROM Setup =====
#define MAX_READINGS 5
#define TEMP_START 0
#define HUM_START 20
int storeIndex = 0;

void setup() {
  Serial.begin(115200);
  dht.begin();

  // ESP32 EEPROM init (emulated in flash)
  EEPROM.begin(512); 

  // Set custom I2C pins for ESP32 (e.g., SDA=21, SCL=22)
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    while (1);
  }

  // --- Splash screen ---
  display.clearDisplay();
  display.setTextSize(2);               
  display.setTextColor(SSD1306_WHITE);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds("TempEEP", 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT - h) / 2); 
  display.println("TempEEP");
  display.display();
  delay(2500); 

  Serial.println("Send 'r' in Serial Monitor to see last 5 readings");
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0,0);
    display.println("Tracker");

    // Temperature & Humidity values
    display.setTextSize(1);
    display.setCursor(0, 25);
    display.print("Temp: "); display.print(temp); display.println(" C");
    display.setCursor(0, 40);
    display.print("Hum: "); display.print(hum); display.println(" %");

    display.display();

    // Store in EEPROM
    EEPROM.put(TEMP_START + storeIndex * 4, temp);
    EEPROM.put(HUM_START + storeIndex * 4, hum);
    EEPROM.commit();

    storeIndex = (storeIndex + 1) % MAX_READINGS;
  } else {
    Serial.println("DHT11 read failed, skipping storage");
  }

  // Check Serial input
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'r' || c == 'R') {
      printLastReadings();
    }
  }

  delay(2000); 
}

// Print last 5 readings to Serial Monitor
void printLastReadings() {
  Serial.println("----- Last 5 Readings -----");
  for (int i = 0; i < MAX_READINGS; i++) {
    float t, h;
    EEPROM.get(TEMP_START + i * 4, t);
    EEPROM.get(HUM_START + i * 4, h);
    Serial.print(i + 1); Serial.print(": ");
    Serial.print(t); Serial.print(" C, ");
    Serial.print(h); Serial.println(" %");
  }
  Serial.println("---------------------------");
}
