---

# S.P.A.R.K – Smart Playable Analog RGB Knob

---

S.P.A.R.K (Smart Playable Analog RGB Knob) is an ESP32-based interactive RGB system that uses a joystick and OLED display to control colors.  
The project allows you to switch between manual color selection and automatic color cycling, with the OLED showing the active color clearly in the center.

---

## What It Does  
- Lets you select colors using joystick direction  
- Shows the selected color name on the OLED display  
- Switches between manual and auto mode via joystick button  
- Cycles through 8 preset colors in auto mode  
- Drives a common-anode RGB LED using inverted PWM signals  

---

## Components Used  
- ESP32 Dev Board (ESP32-WROOM-32)  
- Joystick Module (X, Y, SW)  
- Common Anode RGB LED  
- SSD1306 OLED (128×64, I2C)  
- Resistors  
- Breadboard + Jumper Wires  
- USB Cable (for power and programming)  

---

## Pin Connections  
- Joystick X → GPIO 34  
- Joystick Y → GPIO 35  
- Joystick SW → GPIO 32  
- RGB LED → R=GPIO 25, G=GPIO 26, B=GPIO 27  
- OLED (I2C) → SDA=GPIO 13, SCL=GPIO 14  

---

## How It Works  
- Reads joystick input using analog pins  
- Maps directional movement to predefined RGB values  
- Uses `digitalRead()` to toggle between modes  
- Updates the OLED text using Adafruit SSD1306 libraries  
- Controls LED color with `analogWrite()` using inverted PWM for common-anode LEDs  

---

## Technical Relevance  
- Analog input handling on ESP32  
- PWM-controlled LED color mixing  
- I2C-based OLED communication  
- State switching logic using button input  
- Text formatting and UI design on small displays  

---

## Learning Alignment  
- Reading analog sensors on ESP32  
- RGB LED control using PWM  
- Working with SSD1306 OLEDs  
- Debouncing and mode switching logic  
- Building interactive embedded interfaces  

---

## Personal Note  
S.P.A.R.K is a small but expressive hardware build that blends input, output, and display into one responsive system.  
It highlights how simple components can create an engaging user-controlled interface — a great step forward in my embedded systems journey.

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/QcuMWxfI4OQ)

---

## Next Iterations  
- Add fade transitions between colors  
- Add brightness control using joystick press cycles  
- Use sensors to drive color changes  
- Add Wi-Fi for remote RGB control  
- Animate text on the OLED display  

---
