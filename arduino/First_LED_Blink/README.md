---

# First LED Blink: Where It All Started  

---

**First LED Blink** is the classic beginner’s ritual in the Arduino world — the moment the board responds and your journey officially begins. This project toggles a single LED on and off at regular intervals, marking the entry point into embedded systems and physical computing.  

---

## What It Does  
- Turns an LED ON for 1 second  
- Turns it OFF for 1 second  
- Repeats this loop endlessly  

---

## Components Used  
- Arduino Uno / Nano  
- 1x LED  
- 1x Resistor (220–330Ω recommended)  
- Breadboard + Jumper Wires  

---

## Pin Connections  
- LED → Pin 12  

---

## How It Works  
- Configures Pin 12 as an output using `pinMode()`  
- Uses `digitalWrite()` to toggle the LED HIGH/LOW  
- Implements timing with `delay()` for the ON/OFF cycle  

---

## Technical Relevance  
- Basic digital output control with microcontrollers  
- Timing-based LED control  
- Foundation for more advanced sequencing or non-blocking code  

---

## Learning Alignment  
- Syntax and structure of an Arduino sketch  
- Digital pin configuration and usage  
- Timing control using delays  

---

## Personal Note  
This was my very first Arduino project — simple, but deeply significant. It marked the exact moment I transitioned from passive learning to active experimentation. That one blinking LED was more than just light — it was proof that code can control the physical world.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/x2l2bgBd3HY)  

---

## Next Iterations  
- Modify blink rates to experiment with timing  
- Add multiple LEDs for sequencing  
- Replace `delay()` with `millis()` for non-blocking control  

---
