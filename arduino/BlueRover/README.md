---
# BlueRover: Bluetooth-Controlled Car Using Arduino, L298N & HC-05
---

**BlueRover** is a Bluetooth-controlled robotic car that combines wireless communication, 
precise motor control, and real-time responsiveness. Built around Arduino Uno, L298N motor driver, 
and the HC-05 Bluetooth module, it demonstrates how embedded systems can bring motion automation 
to life with minimal hardware and clean logic.

---

## What It Does
- Receives wireless commands via **Bluetooth** from the **CandyCom** Android app  
- Moves **forward**, **backward**, **left**, **right**, or **stops** based on received inputs  
- Controls two DC motors through **L298N motor driver** using H-Bridge logic  
- Uses **PWM** for smooth motor speed control and direction changes  
- Operates wirelessly within Bluetooth range for real-time manual control  

---

## Components Used
- Arduino Uno / Nano  
- HC-05 Bluetooth Module  
- L298N Motor Driver  
- 2x BO Motors + Wheels  
- 2x 3.7V Li-ion Batteries  
- Acrylic / Custom Chassis  
- Jumper Wires + Breadboard (for 5V sharing)  
- **CandyCom Android App** (MIT App Inventor)  

---

## Pin Assignments
- IN1 → D4  
- IN2 → D5  
- IN3 → D6  
- IN4 → D7  
- ENA → D9  
- ENB → D10  
- HC-05 TX → Arduino RX (D0)  
- HC-05 RX → Arduino TX (D1)  
- Common GND → Shared between Arduino & L298N  

---

## How It Works
- **Bluetooth Connection:** The CandyCom app pairs with HC-05 at 9600 baud rate.  
- **Command Input:** Each button press on the app sends a character (`F`, `B`, `L`, `R`, `S`) via Bluetooth.  
- **Arduino Logic:** Serial input is read and interpreted through a switch-case structure.  
- **Motor Control:** L298N H-Bridge outputs set motor direction and PWM speed based on the command.  
- **Stop Command:** All motor pins go LOW, halting the car instantly.  

---

## Technical Relevance
- Demonstrates wireless serial communication with Arduino  
- Implements real-time motor control via Bluetooth  
- Uses PWM for motor speed modulation  
- Establishes stable power routing and grounding between modules  
- Serves as a foundation for robotics, mobility, and IoT-based automation  

---

## Learning Alignment
- Interfacing Bluetooth (HC-05) with Arduino for command transmission  
- Integrating L298N motor driver with H-Bridge logic  
- Handling serial data using `Serial.read()` and condition statements  
- Managing power and PWM speed control for DC motors  
- Building a basic mobile robot for future automation expansions  

---

## Personal Note
**BlueRover** is my first fully wireless motion project — a small step into the world of mobile robotics.  
Building the **CandyCom** Android app alongside it made this setup feel complete, bridging 
the gap between hardware and user interaction. From circuit design to app development, 
this project helped me understand how real-time communication brings embedded systems to life.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/JZhMdJl7Nqw)

---

## Next Iterations
- Add obstacle avoidance with ultrasonic sensors  
- Implement voice or gesture control through the CandyCom app  
- Introduce line-following or autonomous driving logic  
- Add Wi-Fi or GPS for location tracking  
- Upgrade chassis design for better stability and torque control  

---
