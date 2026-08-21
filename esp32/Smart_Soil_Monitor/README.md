---

# Smart Soil Monitor – ESP32 + Blynk Soil Monitoring & Alerts

---

Smart Soil Monitor is an ESP32-based IoT system that monitors soil moisture levels in real time and provides both physical and remote status indication. It functions as a compact, connected embedded system that combines analog sensing, threshold-based classification, LED indicators, and Blynk-based monitoring.

The system continuously reads soil moisture data, determines whether the soil is DRY or WET, and sends the sensor value and status to a Blynk IoT dashboard. Red and green LEDs provide local indication, while dry-soil conditions trigger Blynk event alerts with notification frequency restricted to one message per minute through the configured Blynk notification setting.

---

## What It Does
- Monitors soil moisture levels in real time
- Reads analog moisture data using ESP32 ADC
- Classifies soil condition as DRY or WET
- Displays live sensor readings on Blynk
- Provides red and green LED status indication
- Triggers Blynk event alerts when soil is dry
- Uses Blynk-side notification limits to restrict alert frequency

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- Soil Moisture Sensor
- Red LED
- Green LED
- Breadboard + Jumper Wires

---

## Pin Connections
- Soil Moisture Sensor:
  - Analog Output → 34
- Red LED:
  - Signal → 18
- Green LED:
  - Signal → 19

---

## How It Works
- ESP32 connects to the configured Wi-Fi network and Blynk IoT platform
- Soil moisture sensor provides an analog reading to GPIO34
- Sensor value is sampled every second
- Moisture reading is sent to Blynk through Virtual Pin V1
- Reading is compared against a predefined threshold of 2000
- If the value is above the threshold, soil is classified as DRY
- If the value is at or below the threshold, soil is classified as WET
- DRY status activates the red LED while WET status activates the green LED
- Soil condition is sent to Blynk through Virtual Pin V2 with corresponding status color
- Dry-soil conditions trigger a Blynk event alert
- Blynk notification settings restrict alert messages to one per minute

---

## Technical Relevance
- Analog sensor interfacing using ESP32 ADC
- Real-time environmental monitoring
- Blynk IoT platform integration
- Virtual Pin-based data communication
- Threshold-based sensor classification
- Event-based remote alerting

---

## Learning Alignment
- Interfacing soil moisture sensors with ESP32
- Reading and processing analog sensor data
- Connecting ESP32 projects to Blynk IoT
- Using Blynk Virtual Pins for live monitoring
- Implementing threshold-based decision logic
- Creating local and remote status indicators

---

## Personal Note
Smart Soil Monitor was built to explore how basic environmental sensing can be extended into a connected IoT monitoring system.

Working with analog soil moisture readings, threshold-based classification, physical LED indicators, and the Blynk dashboard helped me better understand the complete flow from sensor acquisition to remote visualization and alerting.

This project demonstrated how a simple sensor can be integrated with IoT tools to create a practical real-time monitoring system for smart agriculture applications.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/eVoIWf-wq3A)

---

## Next Iterations
- Add automatic irrigation using a water pump
- Implement dual-threshold control for stable switching
- Add adjustable moisture threshold through Blynk
- Store moisture readings for historical analysis
- Integrate temperature and humidity monitoring
- Support multiple soil moisture sensors
- Add battery-powered operation for remote monitoring

---
