---

# BaroCast – ESP32 + BMP280 IoT Weather Dashboard

---

BaroCast is an ESP32-based wireless weather monitoring system that hosts its own Wi-Fi hotspot and streams live temperature and pressure data to a sleek web dashboard. It functions as a compact self-contained IoT weather station with no internet dependency.

The project allows real-time environmental monitoring from any phone or laptop by simply connecting to the ESP32’s access point and opening a browser.

---

## What It Does
- Creates its own Wi-Fi hotspot (Access Point mode)
- Hosts a local web server with a live dashboard
- Displays temperature (°C) and pressure (hPa) in real time
- Auto-refreshes the web page every 2 seconds
- Works without any router or internet connection

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- BMP280 Barometric Sensor (I2C)
- Breadboard + Jumper Wires
- Smartphone or Laptop with Wi-Fi

---

## Pin Connections
- BMP280 (I2C) → SDA=GPIO 21, SCL=GPIO 22

---

## How It Works
- ESP32 boots in Access Point (AP) mode and creates a Wi-Fi hotspot
- The BMP280 sensor initializes and starts measuring temperature and pressure
- ESP32 hosts a web server on 192.168.4.1
- Any connected phone or laptop opens the IP in a browser
- The dashboard displays live sensor values
- The page auto-refreshes every 2 seconds for continuous updates

---

## Technical Relevance
- ESP32 Wi-Fi Access Point networking
- Hosting embedded web servers
- I2C sensor interfacing (BMP280)
- Real-time sensor-to-web data streaming
- Building lightweight IoT dashboards with HTML & CSS

---

## Learning Alignment
- Working with ESP32 Wi-Fi (AP mode)
- Building web servers on microcontrollers
- Interfacing barometric sensors using I2C
- Auto-refreshing web dashboards
- Designing clean UI for embedded IoT systems

---

## Personal Note
BaroCast is my first complete ESP32 + sensor-based IoT dashboard project.  
It gave me hands-on experience with access point networking, sensor interfacing, and hosting real-time data on an embedded web server.

Seeing live pressure and temperature update instantly on a phone browser made this one of my most satisfying early IoT builds and a strong foundation for future connected systems.

---

## Demo 
Watch the working demo here:  
[Demo Video](https://youtu.be/kvrLbA8ZlEY)

---

## Next Iterations
- Add humidity sensor for a full weather station
- Store historical data in SPIFFS / SD card
- Add live graphs using Chart.js
- Switch to Station mode for cloud logging
- Integrate MQTT for IoT platforms

---

