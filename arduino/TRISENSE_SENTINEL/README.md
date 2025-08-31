---

# 🚨 TRISENSE SENTINEL: Multi-Zone Flame & Motion Hazard Detection 🔥🚶🔊

---

**TRISENSE SENTINEL** is a responsive hazard detection system that combines **flame sensing** and **motion detection** to deliver tiered visual and audio alerts in real-time. Designed for **multi-zone monitoring**, it demonstrates how layered safety logic can be applied to home safety demos, lab security, and future IoT-enabled monitoring.

---

🔥 WHAT IT DOES:  
----------------  

- 🔥 Flame Detection (per zone) → Triggers **Red LED** + mid-speed buzzer  
- 🚶 Motion Detection (per zone) → Triggers **Yellow LED** + slow buzzer  
- 🚨 Dual Threat (both detected) → Activates **HIGH ALERT**: both LEDs ON + fast buzzer  
- ✅ Idle State → All indicators OFF  
- 📟 Serial Monitor feedback for real-time status & debugging  
- ⚙️ Simple modular logic with adjustable alert speeds  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno  
- Flame Sensor Module  
- PIR Motion Sensor Module  
- Red LED (Fire Indicator)  
- Yellow LED (Motion Indicator)  
- Active Buzzer  
- Breadboard & Jumper Wires  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- Flame Sensor → A0  
- PIR Motion Sensor → D2  
- Red LED → D8  
- Yellow LED → D9  
- Buzzer → D10  

---

🧠 HOW IT WORKS:  
-----------------  
- **Flame Sensor** provides analog threshold detection for fire events  
- **Motion Sensor** outputs LOW when motion is detected  
- **Logic Flow:**  
  → Fire only → Red LED ON + mid-speed buzzer  
  → Motion only → Yellow LED ON + slow buzzer  
  → Both → HIGH ALERT (both LEDs + fast buzzer)  
  → None → All OFF  
- Adjustable delays for alert patterns  
- Modular code ready for IoT/ML integration  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- 🏠 Home Safety Demonstrations  
- 🧪 Lab & Equipment Security  
- 🛠️ Scalable Multi-Zone Hazard Detection  
- 📡 Future IoT Integration with Cloud Alerts  

---

📚 Learning Alignment:  
-----------------------  
- 🔀 Handling analog & digital sensor inputs together  
- ⏱️ Tiered alert speed control with LEDs and buzzers  
- 🧩 Modular embedded design for expansion  
- 🖥️ Serial Monitor for live feedback and debugging  

---

💡 PERSONAL NOTE:  
------------------  
**TRISENSE SENTINEL** was built to mimic how layered hazard detection systems work in real security environments. It’s a neat balance between simplicity and scalability — easy to prototype but powerful enough to evolve into an IoT-connected, AI-driven safety solution.

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/OrkDoXTRvH4)

---

🚀 NEXT ITERATIONS:  
---------------------  
- Wi-Fi/Bluetooth alert notifications  
- Dynamic flame intensity calibration  
- Expansion to 3+ detection zones  
- Edge ML for fire pattern recognition  

---
