---
# V-GATE: Vibration-Guided Automated Toll Entry with OLED Display and Servo Control
---

**V-GATE** is an automated toll gate simulation system that combines vibration-triggered access, ultrasonic vehicle detection, servo-controlled gate movement, and OLED feedback. Designed for simplicity and clarity, this project demonstrates real-world access automation logic in a compact Arduino setup.

---

## What It Does
- Activates automatically through **vibration input** (simulating vehicle presence or card tap)  
- Detects approaching vehicles using an **ultrasonic sensor**  
- Opens and closes a **servo gate** based on vehicle distance  
- Provides real-time visual feedback via **OLED display**  
- Alerts users using **buzzer and LED indicators**  
- Tracks and displays **vehicle count** with a reset button  

---

## Components Used
- Arduino Uno / Nano  
- Vibration Sensor Module  
- Ultrasonic Sensor (HC-SR04)  
- Servo Motor (SG90 or equivalent)  
- OLED Display (SSD1306, I2C)  
- Buzzer  
- Red & Green LEDs  
- Pushbutton (for reset)  
- Breadboard + Jumper Wires  
- Optional: 4xAA Battery Pack (for servo power isolation)  

---

## Pin Assignments
- Vibration Sensor → D2  
- Ultrasonic Sensor → Trig: D3, Echo: D4  
- Servo Motor → D5  
- Green LED → D6  
- Red LED → D7  
- Buzzer → D8  
- Pushbutton (Reset) → A0  
- OLED Display (I2C) → SDA: A4, SCL: A5  

---

## How It Works
- **Idle State:** System waits for vibration input; Red LED stays ON.  
- **Activation:** On detecting vibration, the system becomes active for 20 seconds.  
- **Vehicle Detection:** When an object is closer than 5 cm, the servo opens the gate, buzzer beeps, and OLED updates the status and vehicle count.  
- **Timeout:** If no vehicle is detected, the system resets after a set duration.  
- **Reset Button:** Clears the vehicle count manually for a new session.  

---

## Technical Relevance
- Demonstrates multi-sensor coordination using Arduino  
- Servo motor automation with real-time distance feedback  
- Non-blocking control flow using `millis()`  
- Real-time OLED text rendering for embedded UIs  
- Compact representation of toll and parking automation logic  

---

## Learning Alignment
- Interfacing ultrasonic and vibration sensors  
- Using PWM control for servo operation  
- Managing sensor logic and timing without `delay()`  
- Designing embedded interfaces with OLED displays  
- Implementing reset and counter systems in automation projects  

---

## Personal Note
**V-GATE** represents my first complete automation prototype — where sensing, timing, and motion all work together to mimic a real toll gate system. It helped me understand how sensors interact in real-time and how embedded control logic can recreate large-scale automation concepts on a small scale.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/761DZy9xmiU)

---

## Next Iterations
- Add EEPROM memory to store total vehicle count  
- Replace vibration trigger with RFID or IR sensor  
- Include sound module for gate audio feedback  
- Enable Wi-Fi or Bluetooth for remote counter display  
- Expand to dual-lane or multi-gate setup  

---
