---

# 🔁 SENSI-BEAT: Multi-Effect LED Display with Sound & Remote Activation 💡🔊🎛️

---

**SENSI-BEAT** is a real-time light control system that reacts to both **IR remote input** and **sound sensor** data to activate dynamic LED patterns. Featuring a **potentiometer for sound sensitivity**, this system blends ambient lighting with interactive modes — ideal for mood setups, party visuals, and embedded control experiments.

---

🔥 WHAT IT DOES:  
----------------  

- 📲 IR Remote allows user to switch between modes  
- 🎚️ Potentiometer dynamically adjusts sound threshold  
- 🔇 Default Mode:  
  - All LEDs ON (steady ambient lighting)  
- 🎉 Party Mode (triggered via IR remote):  
  - 🔵 Blue LED: Rapid strobe effect  
  - 🔴 Red LED: Sound-reactive pulsing  
  - 🟡 Yellow LED: Breathing fade animation  
  - ⚪ White LED: Random flicker  
  - 🟢 Green LED: Status/heartbeat indicator  
- 🕒 All LED actions use `millis()` (non-blocking logic)  
- 💻 Serial Monitor logs current mode and threshold values  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno  
- IR Receiver Module + Remote  
- Analog Sound Sensor  
- Potentiometer (10kΩ)  
- 5 LEDs: Red, Blue, Yellow, White, Green  
- Resistors (220–330Ω)  
- Breadboard + Jumper Wires  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- IR Receiver → D2  
- Sound Sensor → A0  
- Potentiometer → A1  
- Blue LED → D3  
- Red LED → D5  
- Yellow LED → D6  
- White LED → D9  
- Green LED → D10  

---

🧠 HOW IT WORKS:  
-----------------  
- IR Remote sends hex codes to toggle modes (via `IRremote.h`)  
- Potentiometer sets live threshold for sound intensity  
- In Party Mode:  
  → Sound peaks trigger pulsing LED  
  → Other LEDs animate independently using millis timers  
- In Default Mode:  
  → All LEDs stay ON  
- Clean state switching and no blocking delays for multitasking behavior  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- 📟 Embedded Interaction → IR + Audio-based event control  
- 🌈 Visual Feedback → LEDs animate based on real-world triggers  
- 🎧 Sound Reactive Systems → Micro-level pulse logic using analog input  

---

📚 Learning Alignment:  
-----------------------  
- 🧠 Multi-sensor input handling with clean threshold logic  
- 🔁 State-machine logic using flags and IR triggers  
- 🕒 Non-blocking LED animations using millis()  
- 📲 IR decoding and remote interfacing using standard Arduino libraries  

---

💡 PERSONAL NOTE:  
------------------  
**SENSI-BEAT** was a leap forward into **multi-sensor embedded logic**. Getting the IR, potentiometer, and sound sensor to work together without lag was challenging but rewarding. Plus, syncing visual patterns to music gave this one a real "wow" factor — definitely one of my most satisfying builds.

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/dA1ATFRMc3s)

---

🚀 NEXT ITERATIONS:  
---------------------  
- Sync LED patterns with external Bluetooth music signals  
- Add OLED screen to show current mode and sound levels  
- Use ESP32 to stream live sound levels or control via mobile  
- Introduce beat-detection algorithm for rhythmic light response  

---
