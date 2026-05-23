#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ESP32Servo.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

const char* BOT_TOKEN = "YOUR_BOT_TOKEN";
const int64_t CHAT_ID = YOUR_CHAT_ID;

WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);

#define RAIN_DIGITAL 4
#define RAIN_ANALOG 15
#define SERVO_PIN 19

Servo myServo;

bool autoMode = true;
bool clothesInside = false;

unsigned long lastTimeBotRan;
const unsigned long BOT_INTERVAL = 500; 

unsigned long lastAlertTime = 0;

void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    Serial.println("Received command: " + text);

    if (text == "/open") {
      myServo.write(90);  
      clothesInside = false;
      bot.sendMessage(chat_id, "✅ Clothes moved OUT (Open)", "");
    }
    else if (text == "/close") {
      myServo.write(0);   
      clothesInside = true;
      bot.sendMessage(chat_id, "✅ Clothes pulled IN (Closed)", "");
    }
    else if (text == "/status") {
      int rainDigital = !digitalRead(RAIN_DIGITAL);
      int rainAnalog = analogRead(RAIN_ANALOG);
      String state = clothesInside ? "Closed (inside)" : "Open (outside)";
      String rain = rainDigital ? "🌧 Rain Detected" : "🌞 Dry";
      String msg = "📊 Status:\nServo: " + state +
                   "\nRain: " + rain +
                   "\nAnalog: " + String(rainAnalog) +
                   "\nMode: " + (autoMode ? "AUTO" : "MANUAL");
      bot.sendMessage(chat_id, msg, "");
    }
    else if (text == "/help") {
      String msg = "Available commands:\n"
                   "/open   → Move clothes outside\n"
                   "/close  → Pull clothes inside\n"
                   "/status → Show current state\n"
                   "/help   → Show this help";
      bot.sendMessage(chat_id, msg, "");
    }
    else {
      bot.sendMessage(chat_id, "Unknown command. Type /help", "");
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(RAIN_DIGITAL, INPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0);      
  clothesInside = true;  

  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected!");
  Serial.println(WiFi.localIP());

  client.setInsecure();

  bot.sendMessage(String(CHAT_ID), "🤖 RainGuard Bot online. Type /help for commands.", "");
  lastTimeBotRan = millis();
}

void loop() {
  unsigned long now = millis();

  static int lastRainState = -1;
  int rainDigital = !digitalRead(RAIN_DIGITAL);

  if (autoMode && rainDigital != lastRainState) {
    if (millis() - lastAlertTime > 3000) { 
      if (rainDigital == 1) { 
        myServo.write(0);
        clothesInside = true;
        bot.sendMessage(String(CHAT_ID), "🌧 Rain detected! Clothes pulled inside.", "");
      }
      else { 
        myServo.write(90);
        clothesInside = false;
        bot.sendMessage(String(CHAT_ID), "🌞 No rain detected! Clothes moved outside.", "");
      }
      lastRainState = rainDigital;
      lastAlertTime = millis();
    }
  }

  if (now - lastTimeBotRan > BOT_INTERVAL) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    if (numNewMessages > 0) {
      handleNewMessages(numNewMessages);
    }
    lastTimeBotRan = now;
  }
}
