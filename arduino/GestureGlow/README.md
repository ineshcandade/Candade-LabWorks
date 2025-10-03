---

# GestureGlow: A Smart Ambient Controller Activated in Darkness  

---

**GestureGlow** is an interactive lighting and motion controller that activates only in darkness. It uses an IR sensor to detect up to three gestures, an LDR to sense ambient light, and combines RGB LED glow patterns with a servo motor response for each gesture. This compact system emulates smart-home style automation with minimal components.  

---

## What It Does  
- Works only in low-light conditions (based on LDR threshold)  
- 1 Gesture → Blue LED blink + Servo at 0°  
- 2 Gestures → Red/Blue alternation + Servo at 90°  
- 3 Gestures → RGB cycle pattern + Servo at 180°  
- In bright conditions → System stays idle/reset  
- Serial Monitor provides real-time gesture and light status  

---

## Components Used  
- Arduino Uno / Nano  
- IR Sensor (digital output)  
- LDR + Resistor (voltage divider)  
- 3x LEDs: Red, Yellow, Blue  
- Servo Motor (SG90 or similar)  
- Breadboard & Jumper Wires  
- *(Optional)* Paper cutout/indicator for gesture visualization  

---

## Pin Assignments  
- IR Sensor → D2  
- LDR → A0  
- LEDs → D9 (Red), D10 (Yellow), D11 (Blue)  
- Servo Motor → D6  

---

## How It Works  
- LDR checks if ambient light is below threshold (night mode)  
- If dark → IR sensor detects hand gesture pulses  
- Gesture count drives LED patterns and servo angles:  
  → 1 = Blue blink + Servo 0°  
  → 2 = Red/Blue alternation + Servo 90°  
  → 3 = RGB cycle + Servo 180°  
- If bright → System resets and ignores input  
- Serial Monitor logs gesture detection and system state  

---

## Technical Relevance  
- Smart room/night lighting systems  
- Gesture-controlled interactive installations  
- Ambient decor prototypes with motion response  
- Foundation for gesture-based smart-home automation  

---

## Learning Alignment  
- Context-aware activation using sensor fusion (IR + LDR)  
- Gesture recognition with pulse detection and timing  
- Driving servo motors and LEDs interactively  
- Real-world introduction to gesture-based automation systems  

---

## Personal Note  
GestureGlow blends responsiveness, interactivity, and ambient awareness. It pushed my understanding of state tracking and sensor fusion while keeping the hardware simple. A strong demo for smart-home inspired concepts.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/2Cia_pWLoeY)  

---

## Next Iterations  
- Add pushbutton for manual mode switching  
- Use EEPROM to save last-used gesture pattern  
- Add IR remote support for extended controls  
- Diffused LED mounts for smoother ambient effects  

---
