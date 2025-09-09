---

# ✨ GestureGlow: A Smart Ambient Controller Activated in Darkness 👋🌙🎨

---

**GestureGlow** is an interactive lighting + motion controller that activates only in darkness. It uses an **IR sensor** to detect up to 3 gestures, an **LDR** to sense ambient light, and combines **RGB LED glow patterns** with a **servo motor response** for each gesture. A compact, intuitive build that emulates smart-home style automation with minimal components.

---

🌙 WHAT IT DOES:  
----------------  

- 🌑 Works only in **low-light conditions** (based on LDR threshold)  
- 🖐️ 1 Gesture → Blue LED blink + Servo at 0°  
- 🖐️🖐️ 2 Gestures → Red/Blue alternation + Servo at 90°  
- 🖐️🖐️🖐️ 3 Gestures → RGB cycle pattern + Servo at 180°  
- ☀️ If bright → System stays idle/reset  
- 📟 Serial Monitor provides real-time gesture + light status  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno / Nano  
- IR Sensor (digital output)  
- LDR + Resistor (voltage divider)  
- 3x LEDs: Red, Yellow, Blue  
- Servo Motor (SG90 or similar)  
- Breadboard & Jumper Wires  
- *(Optional)* Paper cutout/indicator for gesture visualization  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- IR Sensor → D2  
- LDR → A0  
- LEDs → D9 (Red), D10 (Yellow), D11 (Blue)  
- Servo Motor → D6  

---

🧠 HOW IT WORKS:  
-----------------  
- **LDR** checks if ambient light is below threshold (night mode)  
- If dark → **IR sensor** detects hand gesture pulses  
- Gesture count drives LED patterns + servo angles:  
  → 1 = Blue blink + Servo 0°  
  → 2 = Red/Blue alternation + Servo 90°  
  → 3 = RGB party cycle + Servo 180°  
- If bright → System resets and ignores input  
- Feedback shown on **Serial Monitor** for debugging/verification  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- 🏠 Smart room/night lighting systems  
- 🎮 Gesture-controlled interactive installations  
- 🎨 Ambient decor prototypes with motion response  
- 📡 Foundation for smart-home style gesture automation  

---

📚 Learning Alignment:  
-----------------------  
- 🌙 Context-aware activation using **sensor fusion (IR + LDR)**  
- 🖐️ Gesture recognition with **pulse detection + timing**  
- 🎛️ Driving **servo motors + LEDs** interactively  
- 🧩 Real-world intro to **gesture-based automation systems**  

---

💡 PERSONAL NOTE:  
------------------  
**GestureGlow** is a blend of responsiveness, interactivity, and ambient awareness. It pushed my understanding of state tracking and sensor interaction while keeping the hardware simple. A perfect demo piece for smart-home inspired concepts.  

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/2Cia_pWLoeY)

---

🚀 NEXT ITERATIONS:  
---------------------  
- Pushbutton for manual mode switching  
- EEPROM to save last-used gesture pattern  
- IR remote support for extended controls  
- Diffused LED mounts for smoother ambient effects  

---
