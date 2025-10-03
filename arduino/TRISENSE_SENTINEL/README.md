---

# TriSense Sentinel: Multi-Zone Flame & Motion Hazard Detection  

---

**TriSense Sentinel** is a responsive hazard detection system that combines flame sensing and motion detection to deliver tiered visual and audio alerts in real time. Designed for multi-zone monitoring, it demonstrates how layered safety logic can be applied to home safety demos, lab security, and future IoT-enabled monitoring.  

---

## What It Does  
- Flame detection → Red LED ON + mid-speed buzzer  
- Motion detection → Yellow LED ON + slow buzzer  
- Dual threat (both detected) → High alert: both LEDs ON + fast buzzer  
- Idle state → All indicators OFF  
- Serial Monitor feedback for live status and debugging  
- Modular logic with adjustable alert speeds  

---

## Components Used  
- Arduino Uno  
- Flame Sensor Module  
- PIR Motion Sensor Module  
- Red LED (Fire Indicator)  
- Yellow LED (Motion Indicator)  
- Active Buzzer  
- Breadboard + Jumper Wires  

---

## Pin Assignments  
- Flame Sensor → A0  
- PIR Motion Sensor → D2  
- Red LED → D8  
- Yellow LED → D9  
- Buzzer → D10  

---

## How It Works  
- Flame sensor provides analog threshold detection for fire events  
- PIR motion sensor outputs LOW when motion is detected  
- Logic flow:  
  → Fire only → Red LED + mid-speed buzzer  
  → Motion only → Yellow LED + slow buzzer  
  → Both → High alert (both LEDs + fast buzzer)  
  → None → All OFF  
- Alert speeds adjustable through delays  
- Modular design ready for IoT/ML integration  

---

## Technical Relevance  
- Embedded systems for multi-sensor hazard detection  
- Tiered alert logic with LEDs and buzzers  
- Modular embedded design for scaling  
- Serial Monitor for debugging and feedback  

---

## Learning Alignment  
- Handling analog and digital sensor inputs together  
- Implementing tiered alert logic  
- Designing modular code for system expansion  
- Real-time feedback and monitoring  

---

## Personal Note  
TriSense Sentinel was built to mimic how layered hazard detection systems operate in real security environments. It balances simplicity and scalability — easy to prototype yet versatile enough to evolve into an IoT-connected, AI-driven safety solution.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/OrkDoXTRvH4)  

---

## Next Iterations  
- Wi-Fi/Bluetooth alert notifications  
- Dynamic flame intensity calibration  
- Expansion to three or more detection zones  
- Edge ML for fire pattern recognition  

---
