---

# TempEEP – Compact Temperature & Humidity Monitor

---

TempEEP is an ESP32-based environmental tracker that uses a DHT11 sensor to read temperature and humidity, displays them live on an OLED screen, and stores the last five readings inside EEPROM.  
The project also lets you retrieve stored readings anytime using a simple serial command.

---

## What It Does  
- Reads temperature and humidity every few seconds  
- Displays live sensor data on the OLED display  
- Stores the last 5 readings in EEPROM using a circular buffer  
- Lets you view stored data by sending 'r' in Serial Monitor  
- Shows a clean “TempEEP” splash screen at startup  

---

## Components Used  
- ESP32 Dev Board  
- DHT11 Temperature & Humidity Sensor  
- SSD1306 OLED (128×64, I2C)  
- EEPROM (internal ESP32 emulation)  
- Breadboard + Jumper Wires  
- USB Cable (for power and programming)  

---

## Pin Connections  
- DHT11 → Data: GPIO 15  
- OLED (I2C) → SDA=GPIO 21, SCL=GPIO 22  

---

## How It Works  
- Reads temperature and humidity via the DHT11 sensor  
- Prints values to the OLED using the Adafruit SSD1306 library  
- Stores readings in EEPROM sequentially, overwriting oldest entries  
- Responds to Serial input ‘r’ to print all saved readings  
- Uses a splash screen at boot to label the project  

---

## Technical Relevance  
- Sensor data acquisition on ESP32  
- Using OLED displays with I2C  
- EEPROM-based data logging  
- Serial communication for command handling  
- Minimal UI design on small displays  

---

## Learning Alignment  
- Interfacing DHT sensors on ESP32  
- OLED rendering using SSD1306 drivers  
- Implementing simple data loggers  
- Using circular buffers for memory management  
- Building clean and informative embedded interfaces  

---

## Personal Note  
TempEEP is a small but meaningful project that brings sensing, display updates, and memory storage into one compact system.  
It’s a solid stepping stone into real-world environmental monitoring and embedded data logging workflows.

---

## Demo 
Watch the working demo here:  
[Demo Video](https://youtu.be/KJ9BmVGGpqg) 

---

## Next Iterations  
- Increase EEPROM storage for more logged samples  
- Add SD card support for long-term logging  
- Display bar graphs or mini charts on the OLED  
- Build Wi-Fi dashboards for remote viewing  
- Add threshold alerts using LEDs or buzzer  

---
