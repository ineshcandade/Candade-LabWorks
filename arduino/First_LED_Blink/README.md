---

# 💡 First LED Blink: Where It All Started ✨🔁

---

**First LED Blink** is the classic beginner’s ritual in the Arduino world — the moment the board responds and your journey officially begins. This project toggles a single LED on and off at regular intervals, marking your entry into embedded systems and physical computing.

---

🔥 WHAT IT DOES:  
----------------
- Turns an LED ON for 1 second  
- Turns it OFF for 1 second  
- Repeats this loop endlessly  

---

🧰 COMPONENTS USED:  
--------------------
- Arduino Uno / Nano  
- 1x LED  
- 1x Resistor (220–330Ω recommended)  
- Breadboard + Jumper Wires  

---

🎮 PIN CONNECTIONS:  
--------------------
- LED → Pin 12  

---

🧠 HOW IT WORKS:  
-----------------
- Configures **Pin 12** as an output using `pinMode()`  
- Uses `digitalWrite()` to toggle the LED HIGH/LOW  
- Implements timing with `delay()` for the ON/OFF cycle  

---

🌐 TECH & APPLICATIONS:  
------------------------
- 🧩 Basic digital output control with microcontrollers  
- ⚡ Timing-based LED control  
- 🚀 Foundation for more advanced sequencing or non-blocking code  

---

📚 LEARNING ALIGNMENT:  
-----------------------
- 📘 Syntax and structure of an Arduino sketch  
- 🔌 Digital pin configuration and usage  
- ⏱️ Timing control using delays  

---

💡 PERSONAL NOTE:  
------------------
This was **my very first Arduino project** — simple, but deeply significant. It marks the exact moment I transitioned from passive learning to active experimentation. That one blinking LED was more than just light — it was proof that code can control the physical world.  

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/x2l2bgBd3HY)  

---

🚀 NEXT ITERATIONS:  
---------------------
- Modify blink rates to experiment with timing  
- Add multiple LEDs for sequencing  
- Replace `delay()` with `millis()` for smarter, non-blocking control  

---

