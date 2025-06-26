---

# 📏 SENSI-RANGE: Adaptive Ultrasonic Proximity Alert System with Potentiometer Dial + Buzzer Feedback 🛑🎛️

---

**SENSI-RANGE** is an intelligent proximity alert system that uses an **ultrasonic sensor** for distance measurement and a **potentiometer dial** to dynamically set the sensitivity threshold. Based on the object's distance, it provides **real-time visual and audio feedback** — simulating how smart systems adapt to environmental input.

---

🔥 WHAT IT DOES:  
----------------  
📡 Continuously measures distance using an **HC-SR04 ultrasonic sensor**  
🎚️ User sets detection threshold (5–50 cm) using a **potentiometer**  
🔴 If object is too close:  
- Red LED turns ON  
- Buzzer sounds an alert  
⚪ If object is at a safe distance:  
- White LED stays ON  
- Buzzer remains silent  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno / Nano  
- HC-SR04 Ultrasonic Sensor  
- Potentiometer (10k)  
- Red LED (Too Close Indicator)  
- White LED (Safe Zone Indicator)  
- Buzzer (Active)  
- Resistors (220–330Ω for LEDs)  
- Breadboard + Jumper Wires  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- Trig (Ultrasonic) → D9  
- Echo (Ultrasonic) → D10  
- Potentiometer → A0  
- Red LED → D6  
- White LED → D5  
- Buzzer → D7  

---

🧠 HOW IT WORKS:  
-----------------  
- Uses `pulseIn()` to read echo time from the ultrasonic sensor  
- Maps potentiometer input to threshold range (5–50 cm)  
- Compares distance to threshold:  
  → If distance < threshold → Red LED + Buzzer ON  
  → Else → White LED ON, Buzzer OFF  
- Provides real-time adjustable feedback without reprogramming  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- ⚙️ Embedded Systems → Real-time sensor-actuator interaction  
- 📡 Smart Alerts → Obstacle detection, parking sensor logic  
- 🎛️ User Configurable Thresholds → Responsive and customizable behavior  

---

📚 Learning Alignment:  
-----------------------  
- 📏 Sensor data handling and feedback logic  
- 🎚️ Analog input mapping with potentiometer  
- 🔔 Digital output control based on thresholding  
- 💡 Hands-on experience in interactive system design  

---

💡 PERSONAL NOTE:  
------------------  
This project marked my first step into building **adaptive embedded systems**. Watching the system respond to real-time dial adjustments showed me the importance of combining analog inputs and digital feedback in smart electronics.

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/E4R74_U9dMg)

---

🚀 NEXT ITERATIONS:  
---------------------  
- Add OLED to show live distance & threshold  
- Upgrade to ESP32 for IoT dashboard logging  
- Replace buzzer with silent vibration motor

---
