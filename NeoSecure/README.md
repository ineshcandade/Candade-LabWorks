---

# 🔐 NeoSecure: Password-Based Smart Entry System 🔢🔒📣

---

**NeoSecure** is a keypad-free password entry system built with **4 push buttons** and **EEPROM memory** for persistent storage. It provides clear LED and buzzer feedback for both correct and incorrect attempts — showing how even minimal hardware can deliver a functional and secure smart lock prototype.

---

🔢 WHAT IT DOES:  
----------------  

- 🔑 Accepts a **4-digit password** (`4-1-3-2`) using four dedicated buttons  
- ✅ Correct Password → Serial: *"Password Correct!"* + 1s long beep + LED OFF (access granted)  
- ❌ Incorrect Password → Serial: *"Password Incorrect!"* + 3 short beeps + LED ON temporarily → Auto reset after 2s  
- 🔄 System automatically resets after each attempt  
- 📟 Serial Monitor displays button presses and results in real-time  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno / Nano  
- 4x Push Buttons  
- Red LED  
- Active Buzzer  
- Resistors (10k for buttons, 220Ω for LED)  
- Breadboard & Jumper Wires  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- Push Buttons → D2, D4, D6, D8  
- Red LED → D11  
- Buzzer → D12  

---

🧠 HOW IT WORKS:  
-----------------  
- Uses **internal pull-up resistors** → buttons register as `LOW` when pressed  
- Stores the default password `4-1-3-2` in **EEPROM** during setup  
- Compares entered sequence with stored values after 4 button presses  
- Distinct feedback:  
  → Long beep + LED OFF = Correct password  
  → 3 short beeps + LED ON = Incorrect password  
- Password persists even after reset/power cycle  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- 🔒 Smart entry systems without keypads  
- 🏠 Drawer, locker, or portable lock prototypes  
- 💼 Beginner-friendly authentication systems  
- 📡 Foundation for IoT-enabled secure access  

---

📚 Learning Alignment:  
-----------------------  
- 🔐 EEPROM for **persistent password storage**  
- 🎮 Handling **multiple button inputs** without a keypad  
- 🔊 Designing **audible & visual feedback** for authentication  
- 🧩 Basics of building secure entry prototypes with microcontrollers  

---

💡 PERSONAL NOTE:  
------------------  
**NeoSecure** was designed to be compact, purposeful, and easy to upgrade — balancing simplicity with real-world usability. It’s a neat foundation for future smart lock projects.  

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/OLleJgI8jVk)

---

🚀 NEXT ITERATIONS:  
---------------------  
- OLED display for masked password entry (`* * * *`)  
- Long-press combo for password reset  
- Servo integration for real lock/unlock mechanism  
- ESP32 upgrade for app-based or IoT-enabled control  

---
