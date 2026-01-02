---

# BOLT – Bluetooth OLED Textboard

---

BOLT is an ESP32-based wireless text display system that receives messages over Bluetooth and displays them live on an SSD1306 OLED screen. It functions as a compact Bluetooth-enabled mini textboard with automatic scrolling support.

The project allows real-time text transmission from a phone or laptop using a Bluetooth Serial connection, making it useful as a wireless notice board or embedded console display.

---

## What It Does
- Receives text wirelessly via Bluetooth (SPP)
- Displays incoming messages in real time on an OLED
- Automatically scrolls when text exceeds screen space
- Clears the display instantly using a CLEAR command
- Shows startup and connection status screens

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- SSD1306 OLED Display (128×64, I2C)
- Breadboard + Jumper Wires
- Smartphone or Laptop with Bluetooth

---

## Pin Connections
- SSD1306 OLED (I2C) → SDA=GPIO 21, SCL=GPIO 22

---

## How It Works
- ESP32 initializes a Bluetooth Serial (SPP) service
- A phone or laptop connects using a Serial Bluetooth Terminal app
- Typed text is sent wirelessly to the ESP32
- Incoming messages are rendered on the OLED display
- Text automatically scrolls when it exceeds visible lines
- Sending the CLEAR command wipes the display instantly

---

## Technical Relevance
- Bluetooth Classic (SPP) communication on ESP32
- OLED display interfacing using I2C
- Text buffering and auto-scroll logic
- Command-based serial communication
- Real-time wireless embedded displays

---

## Learning Alignment
- Working with BluetoothSerial on ESP32
- Interfacing SSD1306 OLED displays
- Handling dynamic text buffers
- Designing simple embedded command protocols
- Building clean UI behavior on constrained displays

---

## Personal Note
BOLT is my first hands-on project exploring Bluetooth communication on the ESP32.
It helped me understand how Bluetooth Serial (SPP) works in practice and how wireless data can be integrated with real-time display systems.

Building BOLT strengthened my understanding of ESP32 Bluetooth capabilities, OLED rendering, and buffer management, and served as a foundation for more advanced wireless and IoT-based projects.

---

## Demo 
Watch the working demo here:  
[Demo Video](https://youtu.be/DDLr5MQMI2M) 

---

## Next Iterations
- Store received messages in EEPROM or Flash
- Support multiple Bluetooth clients
- Add custom fonts and icons to OLED
- Upgrade to Wi-Fi-based text dashboard
- Expand to larger displays or LED matrices

---

