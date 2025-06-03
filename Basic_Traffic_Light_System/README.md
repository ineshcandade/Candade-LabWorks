---

# 🚦 BASIC TRAFFIC LIGHT SYSTEM: My First Logic Control Project 🔴🟡🟢

---

**Basic Traffic Light System** simulates the classic red-yellow-green traffic signal cycle using Arduino — a foundational exercise in sequential logic and output control. This project marks your progression from simple blinking LEDs to managing multiple outputs in a timed sequence.

🔥 WHAT IT DOES:  
----------------  
- Turns **Red LED ON** for 2 seconds (STOP)  
- Turns **Yellow LED ON** for 0.5 seconds (WAIT)  
- Turns **Green LED ON** for 2 seconds (GO)  
- Repeats this cycle endlessly  

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno / Nano  
- 3x LEDs (Red, Yellow, Green)  
- 3x Resistors (220–330 ohm recommended)  
- Breadboard + Jumper Wires  

🎮 PIN ASSIGNMENTS:  
--------------------  
- Red LED → Pin 10  
- Yellow LED → Pin 11  
- Green LED → Pin 12  

🧠 HOW IT WORKS:  
-----------------  
- Sets pins 10, 11, and 12 as outputs using `pinMode()`  
- Uses `digitalWrite()` to turn LEDs HIGH or LOW in sequence  
- Implements timing using `delay()` to alternate LED states  

🌐 TECH & COURSE RELEVANCE:  
----------------------------  
- 🧠 **Embedded Systems 101**: Pin output control and sequencing logic  
- 💡 **IoT Basics**: Simulating real-world signaling behavior  
- 🛠️ **Udemy Arduino Crash Course**: Reinforces fundamental digital output and control sequencing  

📚 Learning Alignment:  
-----------------------  
- 📘 Sequencing outputs in Arduino sketches  
- ⚡ Digital output handling  
- ⏱️ Use of `delay()` for timing  

💡 PERSONAL NOTE:  
------------------  
This **Basic Traffic Light System** was my first step beyond single LED control — a simple yet essential lesson in managing multiple outputs and timing cycles in embedded systems.

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/FSDmnyxN6Ig)

🚀 NEXT ITERATIONS:  
---------------------  
- Add a button for pedestrian crossing input  
- Replace `delay()` with `millis()` for smarter control  
- Expand to control multiple lanes or junctions  


