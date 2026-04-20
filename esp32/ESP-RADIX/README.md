---

# ESP-RADIX – ESP32 Radar System with LED Matrix, Servo Sweep & OLED

---

ESP-RADIX is an ESP32-based real-time radar system that scans its surroundings using an ultrasonic sensor and visualizes distance data through a dynamic LED matrix display. It functions as a compact, self-contained embedded system that combines sensing, actuation, and visualization without any external computation.

The system continuously sweeps across 180°, detects objects, and converts distance readings into trapezium-style peaks on a 32×8 LED matrix while displaying live data on an OLED screen.

---

## What It Does
- Scans environment using servo-mounted ultrasonic sensor
- Detects object distance in real time
- Visualizes distance as “mountain peaks” on LED matrix
- Displays live distance and angle on OLED
- Triggers buzzer alerts based on proximity
- Uses non-blocking logic for smooth operation

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- HC-SR04 Ultrasonic Sensor
- SG90/MG90 Servo Motor
- 4 × MAX7219 8×8 LED Matrix Modules
- SSD1306 128×64 OLED Display
- Active Buzzer
- Breadboard + Jumper Wires

---

## Pin Connections
- Ultrasonic Sensor:
  - TRIG → 26
  - ECHO → 25
- Servo Motor → 27
- Buzzer → 14
- LED Matrix:
  - DIN → 23
  - CLK → 19
  - CS → 5
- OLED (I2C):
  - SDA → 21
  - SCL → 22

---

## How It Works
- Servo continuously sweeps from 0° to 180° and back
- At each step, ultrasonic sensor measures distance
- Distance values are filtered for stability
- Distance is mapped to height levels (0–6)
- LED matrix renders trapezium-style peaks with fading trails
- OLED displays real-time distance (cm) and angle (°)
- Buzzer logic:
  - ≤ 5 cm → Continuous alert
  - ≤ 10 cm → Pulsed alert
  - > 10 cm → No alert
- System uses millis() for smooth, non-blocking execution

---

## Technical Relevance
- Real-time embedded sensing and visualization
- Servo-based scanning systems
- Ultrasonic distance measurement
- LED matrix control using MAX7219
- OLED interfacing with SSD1306
- Non-blocking task scheduling using millis()

---

## Learning Alignment
- Interfacing ultrasonic sensors with ESP32
- Controlling servo motors for scanning systems
- Driving LED matrix displays with animations
- Using OLED for real-time data output
- Implementing non-blocking embedded logic
- Mapping sensor data to visual representations

---

## Personal Note
ESP-RADIX was built to explore how raw sensor data can be transformed into meaningful visual feedback.

Working with multiple components simultaneously — servo, ultrasonic sensor, LED matrix, OLED, and buzzer — helped me understand system synchronization and real-time processing at a deeper level.

This project pushed me to think beyond detection and focus on how data can be interpreted and presented effectively.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/m3u15pfH4cw)

---

## Next Iterations
- Add Wi-Fi dashboard for live radar monitoring
- Implement radar-style circular sweep interface
- Store scan data using SPIFFS/SD card
- Integrate multiple sensors for wider coverage
- Add object tracking and classification logic

---
