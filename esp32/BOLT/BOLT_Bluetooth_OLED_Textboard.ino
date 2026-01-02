#include <BluetoothSerial.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

BluetoothSerial SerialBT;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool btConnected = false;
String paragraph = "";   // entire text buffer

void centerText(const char* text, int textSize, int y) {
  display.clearDisplay();
  display.setTextSize(textSize);
  display.setTextColor(SSD1306_WHITE);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;
  display.setCursor(x, y);
  display.print(text);
  display.display();
}

void refreshDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  int lineHeight = 8;
  int maxLines = SCREEN_HEIGHT / lineHeight;

  // Break paragraph into 21-char lines
  int start = 0;
  int totalLines = 0;
  String lines[200]; // buffer for many lines

  while (start < paragraph.length()) {
    lines[totalLines++] = paragraph.substring(start, start + 21);
    start += 21;
  }

  // Auto-scroll: show only the last `maxLines`
  int firstLine = max(0, totalLines - maxLines);
  int lineNum = 0;
  for (int i = firstLine; i < totalLines; i++) {
    display.setCursor(0, lineNum * lineHeight);
    display.print(lines[i]);
    lineNum++;
  }

  display.display();
}

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }

  centerText("BOLT", 2, (SCREEN_HEIGHT / 2) - 8);
  delay(2500);

  centerText("Connecting...", 1, (SCREEN_HEIGHT / 2) - 4);

  if (!SerialBT.begin("ESP32-OLED")) {
    Serial.println("Bluetooth init failed!");
    while (1);
  }
  Serial.println("Bluetooth ready. Connect via Serial BT Terminal.");
}

void loop() {
  // Connection status
  if (SerialBT.hasClient() && !btConnected) {
    btConnected = true;
    centerText("Ready to Receive", 1, (SCREEN_HEIGHT / 2) - 4);
    delay(1500);
    paragraph = "";
    refreshDisplay();
  } else if (!SerialBT.hasClient() && btConnected) {
    btConnected = false;
    centerText("Connecting...", 1, (SCREEN_HEIGHT / 2) - 4);
  }

  if (SerialBT.available()) {
    String input = SerialBT.readStringUntil('\n'); 
    input.trim();

    if (input.equalsIgnoreCase("CLEAR")) {
      paragraph = "";
      refreshDisplay();
      centerText("Cleared", 1, (SCREEN_HEIGHT / 2) - 4);
      delay(1000);
      refreshDisplay();
    } else {
      paragraph += input;  
      refreshDisplay();   
    }
  }
}
