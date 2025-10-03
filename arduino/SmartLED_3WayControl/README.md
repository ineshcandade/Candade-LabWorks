---

# SmartLED_3WayControl: Multi-Input LED Control Using Serial, Potentiometer & Button  

---

**SmartLED_3WayControl** is an interactive LED control project that combines serial input, analog adjustment, and digital triggering to control three LEDs in real time. This project demonstrates how multiple types of hardware inputs can be processed simultaneously using non-blocking logic — a critical step forward in mastering embedded systems.  

---

## What It Does  
- One LED blinks at a user-defined interval set via the Serial Monitor  
- Another LED smoothly adjusts brightness based on a potentiometer  
- A third LED turns ON only when a push-button is pressed  

---

## Components Used  
- Arduino Uno / Nano  
- 3x LEDs (any color)  
- 1x Potentiometer  
- 1x Push-button  
- 3x Resistors (220–330Ω for LEDs, 10K for button if needed)  
- Breadboard + Jumper Wires  

---

## Pin Assignments  
- LED 1 (Blink) → Pin 9  
- LED 2 (PWM Brightness) → Pin 10  
- LED 3 (Button Trigger) → Pin 11  
- Potentiometer → A0  
- Button → D2  

---

## How It Works  
- The blinking LED uses `millis()` for non-blocking timing and takes custom delay values from the Serial Monitor  
- The brightness LED reads analog input from the potentiometer and maps it to PWM using `analogWrite()`  
- The button LED reads digital input and activates only when the push-button is pressed  

---

## Technical Relevance  
- Embedded Systems → Real-time control using multiple input types  
- IoT Foundations → Serial input as a stand-in for remote commands  
- Hardware + Software Integration → Combining analog, digital, and software-driven triggers  

---

## Learning Alignment  
- Real-time logic using `millis()` (non-blocking delays)  
- Analog-to-PWM brightness scaling  
- Serial communication as a basic user interface  
- Handling multiple simultaneous input methods  
- Integrating analog, digital, and software-based control in one sketch  

---

## Personal Note  
This project helped me bridge the gap between individual LED control and full-blown smart logic. Getting serial input, analog scaling, and button logic to work together felt like my first true multi-input embedded system coming alive.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/H3wnKUX6BvY)  

---

## Next Iterations  
- Display blink speed and brightness level on an OLED/LCD screen  
- Upgrade to RGB LED for color control via analog input  
- Port to ESP32 and control LED states via Bluetooth Serial commands  

---
