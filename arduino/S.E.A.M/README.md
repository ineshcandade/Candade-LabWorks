---

# SEAM: Skyborne Environmental Alert Mechanism  

---

**SEAM (Skyborne Environmental Alert Mechanism)** is a compact multi-sensor safety system that fuses tilt, distance, temperature, and humidity data into a real-time OLED dashboard with multi-level LED and buzzer alerts.  
Inspired by spacecraft hazard monitoring, this project demonstrates how multiple sensor inputs can be prioritized and visualized for safety and environmental monitoring.  

---

## What It Does  
- Tilt detected → Red LED ON + buzzer constant ON  
- Distance < 10 cm → Blue LED ON + buzzer beep (200 ms cycle)  
- Temperature > 40°C OR abnormal humidity → Danger flagged on OLED  
- Safe state → Green LED ON + OLED shows live readings  
- OLED updates every 1.5s with sensor data and status  
- Serial Monitor provides debugging output  

---

## Components Used  
- Arduino Uno  
- DHT22 Temperature & Humidity Sensor  
- HC-SR04 Ultrasonic Distance Sensor  
- Tilt Switch Sensor  
- 128x64 OLED Display (SSD1306 driver)  
- 3 LEDs (Red, Green, Blue)  
- Active Buzzer  
- Breadboard & Jumper Wires  

---

## Pin Assignments  
- DHT22 → D2  
- Ultrasonic Sensor → Trigger D3, Echo D4  
- Tilt Switch → D7  
- Green LED → D9  
- Blue LED → D10  
- Red LED → D11  
- Buzzer → D12  
- OLED → I2C (SDA, SCL)  

---

## How It Works  
- Tilt input has highest priority (emergency override)  
- Distance alert triggers if obstacle < 10 cm  
- Environmental hazards checked last (temperature/humidity thresholds)  
- OLED dynamically displays live sensor readings and hazard status  
- Alerts use progressive priority handling for clarity  

---

## Technical Relevance  
- Spacecraft-inspired hazard detection demos  
- Smart home safety monitoring  
- Environmental monitoring in labs or equipment rooms  
- Scalable IoT-ready safety systems  

---

## Learning Alignment  
- Fusing multiple sensor inputs in one embedded system  
- Designing priority-based alert logic  
- Real-time data visualization on OLED  
- Prototyping scalable environmental safety systems  

---

## Personal Note  
SEAM was designed to showcase how environmental monitoring and hazard detection can be compact, modular, and future-ready. It is simple enough to prototype yet versatile enough to scale into IoT-enabled or AI-driven safety systems.  

---

## Demo  
Watch the demo video here:  
[Demo Video](https://youtu.be/Y6APGDZD57A)  

---

## Project Showcase  
Presented at **Open Day 2025 (Electronics Dept, JSSSTU)**.  
Check out the LinkedIn post here:  
[Open Day 2025 Showcase](https://www.linkedin.com/posts/inesh-candade_openday2025-iot-embeddedsystems-activity-7334592204872597504-Q_RL)  

---

## Next Iterations  
- Add EEPROM logging for alert history  
- Develop smarter OLED dashboards (graphs, logs, trends)  
- Wireless alerts via Wi-Fi or Bluetooth  
- Customizable thresholds for user-specific needs  
- AI/ML integration for anomaly detection  

---
