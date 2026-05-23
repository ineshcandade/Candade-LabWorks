---

# DRAPE-T – Smart Rain-Aware Clothesline with Telegram Control

---

DRAPE-T is an ESP32-based smart clothesline automation system that detects rain in real time and automatically protects clothes using a servo-driven mechanism with Telegram-based remote monitoring and control.

The system continuously monitors weather conditions using a rain sensor and dynamically moves clothes inside or outside depending on rain detection. Alongside automation, it provides real-time Telegram alerts and manual control commands through a cloud-connected bot interface.

It functions as a compact IoT embedded system that combines sensing, actuation, wireless communication, and automation without requiring any external processing system.

---

## What It Does
- Detects rain using digital and analog rain sensing
- Automatically pulls clothes inside during rain
- Pushes clothes back outside when dry
- Sends instant Telegram notifications
- Allows remote control using Telegram commands
- Displays real-time system status
- Uses non-blocking embedded logic for smooth execution

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- Rain Sensor Module
- SG90/MG90 Servo Motor
- Jumper Wires
- Breadboard / Mounting Base
- Wi-Fi Network
- Telegram Bot API

---

## Pin Connections
- Rain Sensor:
  - Digital OUT → 4
  - Analog OUT → 15

- Servo Motor → 19

---

## How It Works
- ESP32 connects to Wi-Fi and initializes Telegram bot
- Rain sensor continuously monitors environmental conditions
- Digital rain output determines rain/dry state
- Analog output provides raw rain intensity data
- When rain is detected:
  - Servo rotates to pull clothes inside
  - Telegram alert is sent instantly
- When dry conditions are detected:
  - Servo rotates to move clothes outside
  - Telegram alert is sent
- Telegram commands allow manual control:
  - /open → Move clothes outside
  - /close → Pull clothes inside
  - /status → Show live system data
  - /help → Display available commands
- System uses debounce timing to avoid false rain triggers
- Telegram polling runs continuously using millis() for smooth non-blocking execution

---

## Technical Relevance
- Real-time embedded automation systems
- Rain sensing using digital & analog signals
- Servo motor-based actuation systems
- ESP32 Wi-Fi communication
- Telegram Bot cloud integration
- Event-driven embedded programming
- Non-blocking task scheduling using millis()

---

## Learning Alignment
- Interfacing rain sensors with ESP32
- Controlling servo motors for automation
- Building Telegram bots for IoT systems
- Implementing Wi-Fi communication on ESP32
- Writing non-blocking embedded code
- Designing real-time automation logic
- Integrating cloud communication with embedded systems

---

## Personal Note
DRAPE-T was built to explore how embedded systems can solve small but practical real-world problems through automation.

Working with rain sensing, servo control, and Telegram communication simultaneously helped me better understand real-time IoT interaction and cloud-connected embedded systems.

This project pushed me beyond basic automation and introduced me to remote monitoring, event-driven control, and smart home style system behavior.

---

## Demo
Watch the working demo here:  
[Demo Video](https://www.youtube.com/watch?v=5ysBq-uavSI)

---

## Next Iterations
- Add OLED display for local monitoring
- Add AUTO/MANUAL mode switching
- Integrate humidity & temperature sensors
- Add MQTT & Home Assistant support
- Build mobile dashboard monitoring
- Store settings using EEPROM/Flash memory
- Expand into a complete smart balcony automation system

---
