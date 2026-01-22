#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

const char* AP_SSID = "BaroCastNet";      
const char* AP_PASS = "BaroCast1234";     

#define BMP_I2C_ADDRESS 0x76

Adafruit_BMP280 bmp;      
WebServer server(80);

String buildPage(float temperature, float pressure) {
  String html = "<!DOCTYPE html><html><head>";
  html += "<meta charset='utf-8'/>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'/>";
  html += "<meta http-equiv='refresh' content='2'/>"; // auto-refresh every 2s
  html += "<title>BaroCast</title>";
  html += "<style>"
          "body{background:#000;color:#FFF;font-family:Arial,Helvetica,sans-serif;"
          "margin:0;padding:24px;text-align:center;}"
          "h1{color:#a78bfa;margin-bottom:28px;font-size:28px;letter-spacing:0.5px;}"
          ".lbl{color:#cfcfcf;font-size:14px;margin-top:16px}"
          ".val{color:#FFF;font-size:22px;margin:6px 0;font-weight:600;}"
          ".accent{color:#a78bfa;font-weight:700;}"
          ".meta{color:#777;font-size:12px;margin-top:18px}"
          "</style></head><body>";
  html += "<h1>BaroCast</h1>";                    
  html += "<div class='lbl'>Temperature</div>";
  html += "<div class='val'><span class='accent'>" + String(temperature, 2) + " °C</span></div>";
  html += "<div class='lbl'>Pressure</div>";
  html += "<div class='val'><span class='accent'>" + String(pressure, 2) + " hPa</span></div>";
  html += "<div class='meta'>Live updates every 2 seconds</div>";
  html += "</body></html>";
  return html;
}

void handleRoot() {
  float temperature = NAN;
  float pressure = NAN;

  temperature = bmp.readTemperature();
  pressure    = bmp.readPressure() / 100.0; // Pa to hPa

  server.send(200, "text/html", buildPage(temperature, pressure));
}

void setup() {
  Serial.begin(115200);
  delay(100);

  Serial.println();
  Serial.println("BaroCast starting...");

  Wire.begin(21, 22);  
  if (!bmp.begin(BMP_I2C_ADDRESS)) {
    Serial.println("BMP280 not found at 0x76. Trying 0x77...");
    if (!bmp.begin(0x77)) {
      Serial.println("Could not find BMP280 at 0x76 or 0x77. Check wiring.");
      while (1) {
        Serial.println("BMP280 not detected. Fix wiring or address.");
        delay(2000);
      }
    } else {
      Serial.println("BMP280 found at 0x77");
    }
  } else {
    Serial.println("BMP280 found at 0x76");
  }

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,
                  Adafruit_BMP280::SAMPLING_X16,
                  Adafruit_BMP280::FILTER_X16,
                  Adafruit_BMP280::STANDBY_MS_500);

  WiFi.softAP(AP_SSID, AP_PASS);
  IPAddress myIP = WiFi.softAPIP();

  Serial.print("Access Point started: ");
  Serial.println(AP_SSID);
  Serial.print("IP address: http://");
  Serial.println(myIP);

  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server running...");
}

void loop() {
  server.handleClient();
}
