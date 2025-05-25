---

# 💡 FIRST LED BLINK: Where It All Started ✨🔁

---

**First LED Blink** is the classic beginner’s ritual in the Arduino world — the moment the board responds and your journey officially begins. This project toggles a single LED on and off at regular intervals, marking your entry into embedded systems and physical computing.

🔥 WHAT IT DOES:
----------------
- Turns an LED ON for 1 second  
- Turns it OFF for 1 second  
- Repeats this loop endlessly  

🧰 COMPONENTS USED:
--------------------
- Arduino Uno / Nano  
- 1x LED  
- 1x Resistor (220–330 ohm recommended)  
- Breadboard + Jumper Wires  

🎮 PIN ASSIGNMENTS:
--------------------
- LED → Pin 12

🧠 HOW IT WORKS:
-----------------
- Sets pin 12 as an output using `pinMode()`  
- Uses `digitalWrite()` to turn the LED HIGH or LOW  
- Implements timing using `delay()` to alternate the LED state

🌐 TECH & COURSE RELEVANCE:
----------------------------
- 🧠 **Embedded Systems 101**: Pin output control  
- 🛠️ **Udemy Arduino Crash Course**: Directly inspired by the very first module, introducing digital output and basic coding structure

📚 Learning Alignment:
-----------------------
- 📘 Basic syntax and structure of an Arduino sketch  
- ⚡ Digital output handling  
- ⏱️ Use of `delay()` for timing  

💡 PERSONAL NOTE:
------------------
This is **my very first Arduino project/program** — simple, but deeply significant. It marks the exact moment I transitioned from passive learning to active experimentation. This one blinking LED was more than just light — it was proof that code can control the physical world.

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/x2l2bgBd3HY)

🚀 NEXT ITERATIONS:
---------------------
- Modify blink rates to understand timing  
- Add multiple LEDs for sequencing  
- Replace `delay()` with `millis()` for smarter control

