---

# First LED Blink with ESP32: My Next Step in Embedded Systems

---

**First LED Blink (ESP32)** continues the classic beginner’s ritual — the LED blink — but now using an **external LED** connected to the ESP32 board.  
This project toggles the LED at 500 ms intervals, marking the first hands-on step into embedded control and microcontroller-based IoT development.  

---

## What It Does  
- Turns an external LED ON for 0.5 seconds  
- Turns it OFF for 0.5 seconds  
- Repeats this loop endlessly  

---

## Components Used  
- ESP32 Dev Board (ESP32-WROOM-32)  
- 1x LED  
- 1x Resistor (220–330 Ω recommended)  
- Breadboard + Jumper Wires  
- USB Cable (for power and programming)  

---

## Pin Connections  
- LED → GPIO 2 (change if using a different pin)  

---

## How It Works  
- Configures GPIO 2 as an output using `pinMode()`  
- Uses `digitalWrite()` to toggle the LED HIGH/LOW  
- Implements timing with `delay()` for the ON/OFF cycle  

---

## Technical Relevance  
- Digital output control on ESP32 GPIOs  
- Timing-based LED toggling  
- Foundation for understanding pin modes and control logic  

---

## Learning Alignment  
- ESP32 programming through Arduino IDE  
- External component interfacing using GPIO  
- Practicing delay-based timing and output manipulation  

---

## Personal Note  
This project marks my **first hands-on experiment using the ESP32’s GPIO** with an external LED — a small yet crucial milestone in my embedded systems journey.  
It’s a reminder that even the simplest flicker of light can signify a powerful beginning in hardware development.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/arSZXFnM-aE)  

---

## Next Iterations  
- Try different GPIO pins for LED control  
- Modify blink intervals to observe timing behavior  
- Replace `delay()` with `millis()` for non-blocking code  
- Extend functionality toward Wi-Fi-based LED control  

---
