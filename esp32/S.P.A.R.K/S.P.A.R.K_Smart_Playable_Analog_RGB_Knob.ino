#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long startupTime; 
bool showName = true;  

// Joystick pins
#define JOY_X 34
#define JOY_Y 35
#define JOY_SW 32

// RGB LED pins (common anode type)
#define LED_R 25
#define LED_G 26
#define LED_B 27

// Auto mode variables
bool autoMode = false;
unsigned long lastChange = 0;
int autoColor = 0;
bool buttonPressed = false; // Add a state variable to debounce the button

// 8 colors table (R,G,B)
int colors[8][3] = {
  {0, 255, 0},     // GREEN
  {255, 40, 0},    // ORANGE
  {0, 0, 255},     // BLUE
  {255, 0, 0},     // RED
  {0, 255, 255},   // CYAN
  {255, 0, 255},   // MAGENTA
  {255, 255, 0},   // YELLOW
  {255, 255, 255}  // WHITE
};

const char* colorNames[8] = {
  "GREEN", "ORANGE", "BLUE", "RED", "CYAN", "MAGENTA", "YELLOW", "WHITE"
};

// --- common anode LED ---
void setColor(int r, int g, int b) {
  analogWrite(LED_R, 255 - r);
  analogWrite(LED_G, 255 - g);
  analogWrite(LED_B, 255 - b);
}

// --- OLED update ---
void showText(const char* txt) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  int16_t x1, y1;
  uint16_t w, h;

  display.getTextBounds(txt, 0, 0, &x1, &y1, &w, &h);

  int x = (SCREEN_WIDTH - w) / 2;
  int y = 20;  

  display.setCursor(x, y);
  display.println(txt);
  display.display();
}

void setup() {
  Serial.begin(115200);
  pinMode(JOY_SW, INPUT_PULLUP);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  // OLED init with custom SDA/SCL pins
  Wire.begin(13, 14);   // SDA = GPIO13, SCL = GPIO14
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  showText("S.P.A.R.K");   
  startupTime = millis();
}

void loop() {
  int x = analogRead(JOY_X);
  int y = analogRead(JOY_Y);
  int sw = digitalRead(JOY_SW);

  if (showName && millis() - startupTime < 2500) {
    return; 
  } else if (showName) {
    showName = false;
  }

  // Simple button press detection to toggle modes
  if (sw == LOW && !buttonPressed) {
    autoMode = !autoMode; // Toggle autoMode
    buttonPressed = true;
    delay(50); 
  }
  if (sw == HIGH) {
    buttonPressed = false;
  }

  if (autoMode) {
    // Cycle colors every 1000ms
    if (millis() - lastChange > 1000) {
      lastChange = millis();
      autoColor = (autoColor + 1) % 8;
      setColor(colors[autoColor][0], colors[autoColor][1], colors[autoColor][2]);
      showText(colorNames[autoColor]); // Update OLED
    }
  } else {
    int centerX = 2048;
    int centerY = 2048;
    int deadzone = 800;
    
    const char* current = "OFF";

    // --- Manual joystick mode ---
    if (y > centerY + deadzone) {
      if (x > centerX + deadzone) { setColor(255, 0, 255); current = "MAGENTA"; }
      else if (x < centerX - deadzone) { setColor(255, 40, 0); current = "ORANGE"; }
      else { setColor(0, 255, 255); current = "CYAN"; }
    }
    else if (y < centerY - deadzone) {
      if (x > centerX + deadzone) { setColor(255, 255, 0); current = "YELLOW"; }
      else if (x < centerX - deadzone) { setColor(255, 0, 0); current = "RED"; }
      else { setColor(0, 0, 255); current = "BLUE"; }
    }
    else if (x > centerX + deadzone) { setColor(255, 255, 255); current = "WHITE"; }
    else if (x < centerX - deadzone) { setColor(0, 255, 0); current = "GREEN"; }
    else { setColor(0, 0, 0); current = "OFF"; }

    showText(current); 
  }
}
