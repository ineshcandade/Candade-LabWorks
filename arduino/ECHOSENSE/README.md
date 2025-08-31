---

# 📦 ECHOSENSE: Smart Object Counter using Ultrasonic Sensor + LED & Buzzer 🔊🔴🟦

---

**ECHOSENSE** is a real-time object detection and counting system powered by an **ultrasonic sensor**, giving immediate feedback through **LED indicators** and a **buzzer**. With a built-in **pushbutton reset**, it's a perfect beginner-friendly smart system for entrances, counters, and basic IoT setups.

---

🔥 WHAT IT DOES:  
----------------  

- 📡 Continuously monitors object distance using an **HC-SR04 ultrasonic sensor**  
- 📦 Detects objects within ~10 cm range  
- 🔴 On object detection:  
  - Red LED turns ON  
  - Buzzer beeps once  
  - Blue LED turns OFF  
  - Count increases  
- 🟦 When no object is nearby:  
  - Blue LED remains ON (idle state)  
  - Red LED and buzzer stay OFF  
- 🔁 Pushbutton allows **manual reset** of the object count  
- 📟 Serial Monitor logs all detections and reset events in real time  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno / Nano  
- HC-SR04 Ultrasonic Sensor  
- Red LED (Detection Alert)  
- Blue LED (Idle Indicator)  
- Buzzer (Active)  
- Pushbutton (Reset Button)  
- Resistors (220–330Ω for LEDs)  
- Breadboard + Jumper Wires  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- Trig (Ultrasonic) → D9  
- Echo (Ultrasonic) → D10  
- Red LED → D7  
- Blue LED → D6  
- Buzzer → D5  
- Pushbutton → D8  

---

🧠 HOW IT WORKS:  
-----------------  
- Uses `pulseIn()` to calculate distance from the ultrasonic sensor  
- If object is detected within ~10 cm:  
  → Increments count  
  → Activates red LED and buzzer  
  → Deactivates blue LED  
- When object is out of range:  
  → Resets red LED and buzzer  
  → Blue LED turns back ON  
- Pushbutton is debounced to ensure clean count reset  
- Serial monitor shows live object count and reset messages  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- ⚙️ Embedded Systems → Real-time object sensing & feedback  
- 📊 Smart Counting → Entry logs, object tracking, access monitors  
- 🛠️ Edge Logic → Buzzer + LED response based on proximity input  

---

📚 Learning Alignment:  
-----------------------  
- 📦 Ultrasonic sensor integration and range-based detection  
- 🧠 State-based control using flags and digital logic  
- 🔁 Debounce handling and manual input in microcontroller systems  
- 🔔 Visual + audio feedback for embedded interaction  

---

💡 PERSONAL NOTE:  
------------------  
**ECHOSENSE** was the **first project that worked flawlessly on the first attempt** — which was honestly a shocker. Seeing the LEDs and buzzer respond on point with each object pass made this a personal milestone. Definitely a keeper for documentation and future IoT upgrades.

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/20vfKFFDusI)

---

🚀 NEXT ITERATIONS:  
---------------------  
- Add OLED to display live object count  
- Store count in EEPROM across resets  
- Add dual sensors for directional counting  
- Upgrade to ESP32 for cloud-connected tracking

---
