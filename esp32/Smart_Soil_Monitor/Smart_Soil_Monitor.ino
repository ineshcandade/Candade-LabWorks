#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define SOIL_PIN 34
#define RED_LED 18
#define GREEN_LED 19

int threshold = 2000;  // adjust after testing

BlynkTimer timer;

void sendSoilData() {

  int soilValue = analogRead(SOIL_PIN);

  Serial.print("Soil: ");
  Serial.println(soilValue);

  // Send value to Blynk
  Blynk.virtualWrite(V1, soilValue);

  if (soilValue > threshold) {
    // DRY

    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

    Blynk.virtualWrite(V2, "DRY");
    Blynk.setProperty(V2, "color", "#FF0000"); // RED

    // Notification
    Blynk.logEvent("soil_alert", "Soil is dry! Water needed");

  } else {
    // WET

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);

    Blynk.virtualWrite(V2, "WET");
    Blynk.setProperty(V2, "color", "#00FF00"); // GREEN
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(1000L, sendSoilData);
}

void loop() {
  Blynk.run();
  timer.run();
}