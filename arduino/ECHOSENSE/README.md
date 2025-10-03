---

# ECHOSENSE: Smart Object Counter using Ultrasonic Sensor  

---

**ECHOSENSE** is a real-time object detection and counting system powered by an ultrasonic sensor, providing immediate feedback through LED indicators and a buzzer. With a built-in pushbutton reset, it demonstrates practical applications for entrances, counters, and basic IoT setups.  

---

## What It Does  
- Continuously monitors object distance using an HC-SR04 ultrasonic sensor  
- Detects objects within ~10 cm range  
- On object detection:  
  - Red LED turns ON  
  - Buzzer beeps once  
  - Blue LED turns OFF  
  - Count increases  
- When no object is nearby:  
  - Blue LED remains ON (idle state)  
  - Red LED and buzzer stay OFF  
- Pushbutton allows manual reset of the object count  
- Serial Monitor logs detections and reset events in real time  

---

## Components Used  
- Arduino Uno / Nano  
- HC-SR04 Ultrasonic Sensor  
- Red LED (Detection Alert)  
- Blue LED (Idle Indicator)  
- Buzzer (Active)  
- Pushbutton (Reset Button)  
- Resistors (220–330Ω for LEDs)  
- Breadboard + Jumper Wires  

---

## Pin Assignments  
- Trig (Ultrasonic) → D9  
- Echo (Ultrasonic) → D10  
- Red LED → D7  
- Blue LED → D6  
- Buzzer → D5  
- Pushbutton → D8  

---

## How It Works  
- Uses `pulseIn()` to calculate distance from the ultrasonic sensor  
- If an object is detected within ~10 cm:  
  → Increments count  
  → Activates red LED and buzzer  
  → Deactivates blue LED  
- When the object is out of range:  
  → Resets red LED and buzzer  
  → Blue LED turns ON  
- Pushbutton is debounced to ensure accurate count reset  
- Serial Monitor displays live object count and reset messages  

---

## Technical Relevance  
- Embedded systems: real-time object sensing and feedback  
- Smart counting: entry logs, object tracking, and monitoring  
- Edge logic: buzzer + LED response driven by proximity input  

---

## Learning Alignment  
- Ultrasonic sensor integration and range-based detection  
- State-based control using flags and digital logic  
- Debounce handling and manual input in microcontroller systems  
- Combining visual and audio feedback in embedded systems  

---

## Personal Note  
ECHOSENSE was a milestone project where everything worked smoothly on the first attempt. It provided a strong foundation in proximity sensing and real-time feedback — a reliable base for future IoT upgrades.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/20vfKFFDusI)  

---

## Next Iterations  
- Add OLED to display live object count  
- Store count in EEPROM across resets  
- Add dual sensors for directional counting  
- Upgrade to ESP32 for cloud-connected tracking  

---
