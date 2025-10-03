---

# Basic Traffic Light System: My First Logic Control Project  

---

**Basic Traffic Light System** simulates the classic red-yellow-green traffic signal cycle using Arduino — a foundational exercise in sequential logic and output control. This project demonstrates progression from single LED control to managing multiple outputs in a timed sequence.  

---

## What It Does  
- Turns Red LED ON for 2 seconds (STOP)  
- Turns Yellow LED ON for 0.5 seconds (WAIT)  
- Turns Green LED ON for 2 seconds (GO)  
- Repeats this cycle endlessly  

---

## Components Used  
- Arduino Uno / Nano  
- 3x LEDs (Red, Yellow, Green)  
- 3x Resistors (220–330Ω)  
- Breadboard + Jumper Wires  

---

## Pin Assignments  
- Red LED → Pin 10  
- Yellow LED → Pin 11  
- Green LED → Pin 12  

---

## How It Works  
- Sets pins 10, 11, and 12 as outputs using `pinMode()`  
- Uses `digitalWrite()` to control LEDs in sequence  
- Implements timing with `delay()` for alternating outputs  

---

## Technical Relevance  
- Embedded systems basics: sequential logic and timed control  
- Demonstrates digital output handling for multiple devices  
- Simulates real-world traffic signaling behavior  

---

## Learning Alignment  
- Sequencing multiple outputs in Arduino sketches  
- Understanding timing and delays in embedded systems  
- Practical implementation of digital output logic  

---

## Personal Note  
This was my first step beyond single LED control — a simple but essential lesson in managing multiple outputs and timing cycles in embedded systems.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/FSDmnyxN6Ig)  

---

## Next Iterations  
- Add a button for pedestrian crossing input  
- Replace `delay()` with `millis()` for non-blocking control  
- Expand to control multiple lanes or junctions  

---
