---

# CAP-VIEW: Live Capacitor Monitoring with LCD & RGB Feedback  

---

**CAP-VIEW** is a real-time capacitor monitoring system that visualizes charging, discharging, and stable states using an LCD display and RGB LED feedback. With interactive visual cues and transistor-based discharge control, this project makes RC circuit theory come alive.  

---

## What It Does  
- Continuously monitors capacitor voltage in real-time  
- Shows voltage level on a 16x2 LCD (two-decimal precision)  
- Indicates states with RGB LED:  
  - Green → Charging (voltage below 1.0V)  
  - Red → Discharging (voltage above 4.7V)  
  - Blue → Stable (between thresholds)  
- Uses a BC548 transistor for automatic capacitor discharge  

---

## Components Used  
- Arduino Uno / Nano  
- Capacitor (e.g., 1000µF)  
- BC548 Transistor  
- RGB LED (Common Anode)  
- 16x2 LCD Display  
- Resistors (1kΩ base, 47kΩ charging, optional for LED)  
- Breadboard + Jumper Wires  

---

## Pin Assignments  
- Capacitor Voltage → A0  
- BC548 (Discharge Control) → D2  
- RGB LED → D5 (Red), D6 (Blue), D9 (Green)  
- LCD → RS(4), EN(7), D4–D7: 8, 10, 11, 12  

---

## How It Works  
- Capacitor charges through a resistor → voltage rises exponentially  
- Arduino reads the voltage via analog pin A0  
- System compares voltage against thresholds:  
  - Charging (<1.0V) → Green LED + LCD “Charging”  
  - Discharging (>4.7V) → Red LED + LCD “Discharging”  
  - Stable (between values) → Blue LED + LCD “Stable”  
- Transistor automatically helps in capacitor discharge  

---

## Technical Relevance  
- Demonstrates capacitor charging and discharging behavior  
- Real-time analog voltage sensing with Arduino  
- Visual + textual feedback using RGB LED and LCD  
- Practical demonstration of RC circuit theory  

---

## Learning Alignment  
- Understanding capacitor charge/discharge curves  
- Using analog inputs for live monitoring  
- Interfacing LCD for real-time feedback  
- RGB LED state indication with PWM  
- Embedded system design for circuit visualization  

---

## Personal Note  
**CAP-VIEW** helped me translate abstract capacitor theory into something interactive and visible. Watching the transitions between charging, discharging, and stable states made this one of my most rewarding projects in basic circuit visualization.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/ckysQAzhyvs)  

---

## Next Iterations  
- Add SD card logging for capacitor voltage history  
- Adjustable thresholds for flexible experiments  
- Monitor multiple capacitors simultaneously  
- Add buzzer alerts for overvoltage/undervoltage  

---
