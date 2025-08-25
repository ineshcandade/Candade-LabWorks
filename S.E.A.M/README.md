---

# ✨ S.E.A.M: Skyborne Environmental Alert Mechanism 🌍⚠️📡

---

**S.E.A.M (Skyborne Environmental Alert Mechanism)** is a compact multi-sensor safety system that fuses **tilt, distance, temperature, and humidity** data into a real-time OLED dashboard with multi-level LED and buzzer alerts.  
Inspired by **spacecraft hazard monitoring**, this project demonstrates how multiple sensor inputs can be prioritized and visualized for safety and environmental monitoring.

---

⚡ WHAT IT DOES:  
----------------  

- ⚠️ Tilt Detected → **Red LED ON** + **Buzzer constant ON**  
- 📏 Distance < 10 cm → **Blue LED ON** + **Buzzer beep (200 ms cycle)**  
- 🌡️ Temperature > 40°C OR abnormal humidity → **Danger flagged on OLED**  
- ✅ Safe State → **Green LED ON** + OLED shows live readings  
- 📟 OLED updates every **1.5s** with sensor data & status  
- 🖥️ Serial Monitor feedback for debugging  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno  
- DHT22 Temperature & Humidity Sensor  
- HC-SR04 Ultrasonic Distance Sensor  
- Tilt Switch Sensor  
- 128x64 OLED Display (SSD1306 driver)  
- 3 LEDs (Red, Green, Blue)  
- Active Buzzer  
- Breadboard & Jumper Wires  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- DHT22 → D2  
- Ultrasonic Sensor → Trigger D3, Echo D4  
- Tilt Switch → D7  
- Green LED → D9  
- Blue LED → D10  
- Red LED → D11  
- Buzzer → D12  
- OLED → I2C (SDA, SCL)  

---

🧠 HOW IT WORKS:  
-----------------  
- **Tilt takes highest priority** (emergency override)  
- **Distance alert** comes next if obstacle < 10 cm  
- **Environmental hazards** checked last (temperature/humidity thresholds)  
- OLED dynamically displays sensor readings + hazard status  
- Alerts designed with **progressive priority handling** for clarity  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- 🛰️ Spacecraft-inspired hazard detection demos  
- 🏠 Smart Home Safety Monitoring  
- 🧪 Environmental Monitoring in labs/equipment rooms  
- 📡 Scalable IoT-ready Safety Systems  

---

📚 LEARNING ALIGNMENT:  
-----------------------  
- 🔗 Fusing multiple sensor inputs in one embedded system  
- ⏱️ Designing priority-based alert logic  
- 🖥️ Real-time data visualization on OLED  
- 🛠️ Prototyping scalable environmental safety systems  

---

💡 PERSONAL NOTE:  
------------------  
**SEAM** was designed to showcase how **environmental monitoring and hazard detection** can be compact, modular, and future-ready. It’s simple enough to prototype yet versatile enough to scale into **IoT-enabled or AI-driven safety systems**.

---

🎬 Watch the demo video here:  
👉 [Demo Video](https://youtu.be/Y6APGDZD57A)  

📢 Project Showcase:  
👉 [Open Day 2025 LinkedIn Post](https://www.linkedin.com/posts/inesh-candade_openday2025-iot-embeddedsystems-activity-7334592204872597504-Q_RL)  

---

🚀 NEXT ITERATIONS:  
---------------------  
- EEPROM logging for alert history  
- Smarter OLED dashboards (graphs, logs, trends)  
- Wireless alerts (Wi-Fi / Bluetooth)  
- Customizable thresholds for user-specific needs  
- AI/ML integration for anomaly detection  

---

