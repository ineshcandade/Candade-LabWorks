#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include "RTClib.h"
#include <TM1637Display.h>

RTC_DS3231 rtc;
WebServer server(80);

#define CLK 4
#define DIO 19
TM1637Display display(CLK, DIO);

#define BUZZER 23

const char* ssid = "ESP-Alarm";
const char* password = "12345678";

// Alarm variables
int alarmHour = -1;
int alarmMinute = -1;
bool alarmSet = false;
bool alarmTriggered = false;
bool buzzerOn = false;
unsigned long buzzerStart = 0;
unsigned long buzzerDuration = 60000; 
int lastTriggerMinute = -1;           

String htmlPage() {
  String html = R"rawliteral(
  <!DOCTYPE html><html><head>
  <meta name='viewport' content='width=device-width, initial-scale=1.0'>
  <title>ChronoLink</title>
  <style>
    body { background:#000; color:#FFF; font-family:Arial, sans-serif; text-align:center; margin:0; padding:20px; }
    .container { max-width:420px; margin:40px auto; padding:20px; }
    h2 { color:#a78bfa; margin-bottom:20px; font-size:28px; letter-spacing:0.5px; }
    label { font-size:14px; display:block; margin-top:6px; }
    input { padding:8px; margin:8px; font-size:16px; text-align:center; border-radius:6px; border:2px solid #a78bfa; background:#fff; color:#000; width:85px; }
    button { width:140px; height:50px; font-size:18px; margin:15px; border-radius:10px; cursor:pointer; font-weight:600; transition:0.25s; }
    .set-btn { background:#222; color:#fff; border:2px solid #a78bfa; }
    .set-btn:hover { background:#333; transform:scale(1.05); }
    .stop-btn { background:#a78bfa; color:#000; font-weight:bold; border:none; border-radius:50%; width:110px; height:110px; }
    .stop-btn:hover { transform:scale(1.1); }
  </style></head><body>
    <div class='container'>
      <h2>ChronoLink</h2>
      <form action='/set' method='GET'>
        <label>Hour (0-23):</label>
        <input type='number' name='h' min='0' max='23'><br>
        <label>Minute (0-59):</label>
        <input type='number' name='m' min='0' max='59'><br>
        <button type='submit' class='set-btn'>Set Alarm</button>
      </form>
      <form action='/stop' method='GET'>
        <button type='submit' class='stop-btn'>STOP</button>
      </form>
    </div>
  </body></html>
  )rawliteral";
  return html;
}

String styledPage(String title, String msg) {
  String html = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'>"
  "<title>" + title + "</title>"
  "<style>"
  "body{background:#000;color:#fff;font-family:Arial,sans-serif;text-align:center;margin:0;padding:20px;}"
  ".container{max-width:420px;margin:100px auto;padding:20px;}"
  "h2{color:#a78bfa;font-size:28px;margin-bottom:15px;}"
  "p{font-size:20px;}"
  "</style></head><body>"
  "<div class='container'><h2>" + title + "</h2><p>" + msg + "</p></div></body></html>";
  return html;
}

void handleRoot() { server.send(200, "text/html", htmlPage()); }

void handleSet() {
  if (server.hasArg("h") && server.hasArg("m")) {
    alarmHour = server.arg("h").toInt();
    alarmMinute = server.arg("m").toInt();
    alarmSet = true;
    alarmTriggered = false; 
    lastTriggerMinute = -1; // reset lock
    server.send(200, "text/html", styledPage("Alarm Set", 
      "Reminder at " + String(alarmHour) + ":" + (alarmMinute < 10 ? "0" : "") + String(alarmMinute)));
  }
}

void handleStop() {
  buzzerOn = false;
  alarmTriggered = true;       // block retrigger for this minute
  buzzerStart = 0;             
  digitalWrite(BUZZER, LOW);   
  server.send(200, "text/html", styledPage("Alarm Stopped", "Reminder dismissed."));
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL
  rtc.begin();

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  display.setBrightness(0x0f);

  WiFi.softAP(ssid, password);
  Serial.println("AP Started");

  server.on("/", handleRoot);
  server.on("/set", handleSet);
  server.on("/stop", handleStop);
  server.begin();
}

void loop() {
  server.handleClient();
  static int lastMinuteDisplay = -1;

  DateTime now = rtc.now();

  // Update display only when minute changes
  if (now.minute() != lastMinuteDisplay) {
    int displayTime = now.hour() * 100 + now.minute();
    display.showNumberDecEx(displayTime, 0b11100000, true); // HH:MM
    lastMinuteDisplay = now.minute();
    Serial.print("Updated: ");
    Serial.print(now.hour());
    Serial.print(":");
    Serial.println(now.minute());

    // Reset daily alarm lock each new minute
    alarmTriggered = false;  
  }

  // Alarm check
  if (alarmSet && !alarmTriggered) {
    if (now.hour() == alarmHour && now.minute() == alarmMinute) {
      alarmTriggered = true;          // only once this minute
      lastTriggerMinute = now.minute();
      buzzerOn = true;
      buzzerStart = millis();
    }
  }

  if (buzzerOn) {
  unsigned long currentMillis = millis();
  unsigned long elapsed = (currentMillis - buzzerStart) % 2000;
  if ((elapsed < 200) || 
    (elapsed >= 300 && elapsed < 500) || 
    (elapsed >= 600 && elapsed < 800)) {
  digitalWrite(BUZZER, HIGH); 
  } else {
  digitalWrite(BUZZER, LOW);  
  }

  if (currentMillis - buzzerStart > buzzerDuration) {
    buzzerOn = false;
    buzzerStart = 0;            
    digitalWrite(BUZZER, LOW);
  }
 }
}
