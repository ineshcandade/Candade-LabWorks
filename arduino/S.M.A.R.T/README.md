---
# S.M.A.R.T: Substation Monitoring & Alert Response Terminal
---

**S.M.A.R.T (Substation Monitoring and Alert Response Terminal)** is an embedded safety
monitoring system designed to simulate real-world substation protection logic.
It continuously monitors voltage, temperature, and fire conditions, and responds
with relay isolation, visual indicators, audible alerts, and a professional OLED
interface when unsafe conditions are detected.

---

## What It Does
- Monitors **voltage levels**, **temperature**, and **flame presence** in real time  
- Detects unsafe conditions such as overvoltage, overheating, or fire  
- Triggers a **latched danger state** that persists until manual reset  
- Isolates the circuit using a **relay module** during fault conditions  
- Provides clear feedback using **LEDs**, **buzzer patterns**, and **OLED display**  

---

## Components Used
- Arduino Uno / Nano  
- DHT11 Temperature Sensor  
- Flame Sensor (Digital)  
- SSD1306 OLED Display (128x64, I2C)  
- Relay Module  
- Red, Yellow & Green LEDs  
- Passive Buzzer  
- Push Button (Manual Reset)  
- Potentiometer (Voltage Simulation)  
- Breadboard & Jumper Wires  

---

## Pin Assignments
- Voltage Input → A0  
- DHT11 → D2  
- Flame Sensor → D3  
- Relay Module → D6  
- Reset Button → D7  
- Red LED → D9  
- Yellow LED → D10  
- Green LED → D11  
- Buzzer → D12  
- OLED (I2C) → SDA, SCL  

---

## How It Works
- **Sensor Monitoring:**  
  Voltage (analog), temperature (DHT11), and flame (digital) inputs are read continuously.
- **Fault Detection:**  
  If any parameter crosses its threshold, the system enters a danger state.
- **Latched Protection Logic:**  
  Once triggered, the danger state remains active until manually reset using the button.
- **Alert System:**  
  - Flame → Fast red LED blink + short buzzer bursts  
  - High Voltage → Red LED fade + alert tone  
  - High Temperature → Yellow LED + soft beep  
- **Circuit Isolation:**  
  The relay disconnects the load during unsafe conditions to simulate substation tripping.

---

## Technical Relevance
- Demonstrates safety-critical embedded system design  
- Implements latched fault logic similar to industrial protection relays  
- Combines multiple sensors for real-time condition monitoring  
- Uses relay control for circuit isolation  
- Integrates OLED-based visual feedback with audio alerts  

---

## Learning Alignment
- Designing fault-detection logic for embedded systems  
- Implementing relay-based protection mechanisms  
- Multi-sensor data fusion and prioritization  
- Button debouncing and manual reset handling  
- Creating professional monitoring interfaces using OLED displays  

---

## Personal Note
**S.M.A.R.T** was built to explore how embedded systems behave in safety-critical
environments inspired by electrical substations. The focus was not just detection,
but **decision-making** — ensuring that once a fault occurs, the system reacts
decisively and does not return to normal until explicitly reset. This project
strengthened my understanding of protection logic, alert systems, and real-world
embedded design principles.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/eRuRNy5kXVY)

---

## Next Iterations
- Store last detected fault using EEPROM  
- Upgrade to ESP32 for Wi-Fi based monitoring  
- Send remote alerts via cloud or SMS  
- Add current sensing for full power profiling  
- Display live graphs on OLED or web dashboard  

---

