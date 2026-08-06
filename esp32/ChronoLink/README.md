---

# ChronoLink – An ESP32 + RTC Alarm Clock with Web Control

---

ChronoLink is an ESP32-based smart alarm clock that combines accurate real-time clock functionality with wireless web control. It functions as a compact, self-contained embedded system that combines accurate timekeeping, wireless control, and real-time alarm management without requiring an internet connection.

The system hosts its own Wi-Fi Access Point, eliminates the need for cloud connectivity, and uses a DS3231 RTC module for precise timekeeping. Users can wirelessly configure alarms through a web dashboard while the TM1637 display continuously shows the current time. When the scheduled alarm time is reached, a patterned buzzer alert is triggered until dismissed or automatically stopped.

---

## What It Does
- Displays accurate real-time clock (HH:MM)
- Creates its own Wi-Fi hotspot for wireless control
- Hosts a responsive web dashboard for alarm configuration
- Allows alarms to be set and dismissed remotely
- Triggers patterned buzzer alerts at scheduled times
- Uses non-blocking logic for smooth operation

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- DS3231 RTC Module
- TM1637 4-Digit 7-Segment Display
- Active Buzzer
- Breadboard + Jumper Wires

---

## Pin Connections
- DS3231 RTC (I2C):
  - SDA → 21
  - SCL → 22
- TM1637 Display:
  - CLK → 4
  - DIO → 19
- Buzzer:
  - Signal → 23

---

## How It Works
- ESP32 starts its own Wi-Fi Access Point on boot
- DS3231 RTC continuously provides accurate current time
- TM1637 display shows the live time in HH:MM format
- Connecting to the ESP32 hotspot opens the web dashboard
- User sets an alarm using the web interface
- ESP32 continuously compares RTC time with the scheduled alarm
- When both match, the buzzer generates a three-beep alert pattern
- Alarm can be dismissed using the STOP button or automatically stops after 60 seconds
- System uses millis() for smooth, non-blocking execution

---

## Technical Relevance
- Real-time clock integration using DS3231
- ESP32 Access Point (AP) networking
- Embedded web server development
- Web-based device control
- TM1637 7-segment display interfacing
- Non-blocking task scheduling using millis()

---

## Learning Alignment
- Interfacing RTC modules with ESP32
- Creating embedded web servers
- Building responsive HTML/CSS dashboards
- Controlling TM1637 7-segment displays
- Implementing event-driven alarm systems
- Designing non-blocking embedded applications

---

## Personal Note
ChronoLink was built to explore how embedded systems can combine accurate timekeeping with intuitive wireless control.

Working with the ESP32 web server, DS3231 RTC, TM1637 display, and buzzer helped me better understand embedded networking, event-driven programming, and real-time automation.

This project demonstrated how a simple alarm clock can evolve into a practical IoT-enabled embedded system without relying on cloud services or internet connectivity.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/XMnAXPwq87A)

---

## Next Iterations
- Support multiple configurable alarms
- Store alarm settings in EEPROM/Flash memory
- Add NTP synchronization for internet time
- Integrate an OLED display for date and temperature
- Add snooze functionality
- Send notifications through Telegram or Blynk
- Support recurring daily and weekly alarms

---
