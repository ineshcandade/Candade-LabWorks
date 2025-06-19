---

# 💡 SmartLED_3WayControl: Multi-Input LED Control Using Serial, Potentiometer & Button 🚦🧠

---

**SmartLED_3WayControl** is an interactive LED control project that combines **serial input**, **analog adjustment**, and **digital triggering** to control three LEDs in real time. This project demonstrates how multiple types of hardware inputs can be processed simultaneously using non-blocking logic — a critical step forward in mastering embedded systems.

🔥 WHAT IT DOES:  
----------------  
1️⃣ **LED 1** blinks at a user-defined interval set via the **Serial Monitor**  
2️⃣ **LED 2** smoothly adjusts brightness based on a **potentiometer**  
3️⃣ **LED 3** turns ON only when a **push-button** is pressed  

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno / Nano  
- 3x LEDs (any color)  
- 1x Potentiometer  
- 1x Push-button  
- 3x Resistors (220–330Ω for LEDs, 10K for button if needed)  
- Breadboard + Jumper Wires  

🎮 PIN ASSIGNMENTS:  
--------------------  
- LED 1 (Blink) → Pin 9  
- LED 2 (PWM Brightness) → Pin 10  
- LED 3 (Button Trigger) → Pin 11  
- Potentiometer → A0  
- Button → D2  

🧠 HOW IT WORKS:  
-----------------  
- **Blinking LED** uses `millis()` for non-blocking timing and takes custom delay values from the Serial Monitor  
- **Brightness LED** reads analog input from the potentiometer and maps it to PWM using `analogWrite()`  
- **Button LED** reads digital input and activates only when the push-button is pressed  

🌐 TECH & COURSE RELEVANCE:  
----------------------------  
- ⚙️ **Embedded Systems** → Real-time control using multiple input types  
- 📡 **IoT Foundations** → Serial input mimics remote device control  
- 🎓 **Udemy Arduino Crash Course** → Reinforces key concepts like `millis()`, PWM, and sensor integration  

📚 Learning Alignment:  
-----------------------  
- 🔄 Real-time logic using `millis()` (non-blocking delays)  
- 🎛️ Analog-to-PWM brightness scaling  
- ⌨️ Serial communication as a basic user interface  
- 📥 Handling multiple simultaneous input methods  
- 🔌 Understanding analog, digital, and software-based triggering  

💡 PERSONAL NOTE:  
------------------  
This project helped bridge the gap between individual LED control and full-blown smart logic. The use of `millis()` finally made sense to me after following the **Udemy Arduino Crash Course**, and seeing all three input types work together felt like my first real embedded system coming to life.

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/H3wnKUX6BvY)

🚀 NEXT ITERATIONS:  
---------------------  
- Display blink speed and brightness level on an OLED/LCD screen  
- Upgrade to RGB LED for color control via analog input  
- Port to ESP32 and control LED states via Bluetooth Serial commands

---


