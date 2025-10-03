---

# NeoSecure: Password-Based Smart Entry System  

---

**NeoSecure** is a keypad-free password entry system built with four push buttons and EEPROM memory for persistent storage. It provides clear LED and buzzer feedback for both correct and incorrect attempts — demonstrating how even minimal hardware can deliver a functional and secure smart lock prototype.  

---

## What It Does  
- Accepts a 4-digit password (`4-1-3-2`) using four dedicated buttons  
- Correct Password → Serial: *"Password Correct!"* + 1s long beep + LED OFF (access granted)  
- Incorrect Password → Serial: *"Password Incorrect!"* + 3 short beeps + LED ON temporarily → auto reset after 2s  
- System automatically resets after each attempt  
- Serial Monitor displays button presses and results in real-time  

---

## Components Used  
- Arduino Uno / Nano  
- 4x Push Buttons  
- Red LED  
- Active Buzzer  
- Resistors (10kΩ for buttons, 220Ω for LED)  
- Breadboard & Jumper Wires  

---

## Pin Assignments  
- Push Buttons → D2, D4, D6, D8  
- Red LED → D11  
- Buzzer → D12  

---

## How It Works  
- Uses internal pull-up resistors → buttons register as `LOW` when pressed  
- Stores the default password `4-1-3-2` in EEPROM during setup  
- Compares entered sequence with stored values after four button presses  
- Provides distinct feedback:  
  → Long beep + LED OFF = Correct password  
  → 3 short beeps + LED ON = Incorrect password  
- Password persists even after reset or power cycle  

---

## Technical Relevance  
- Smart entry systems without keypads  
- Drawer, locker, or portable lock prototypes  
- Beginner-friendly authentication system design  
- Foundation for IoT-enabled secure access  

---

## Learning Alignment  
- EEPROM for persistent password storage  
- Handling multiple button inputs without a keypad  
- Designing audio and visual feedback for authentication  
- Basics of secure entry prototypes with microcontrollers  

---

## Personal Note  
NeoSecure was designed to be compact, purposeful, and easy to upgrade — balancing simplicity with real-world usability. It serves as a foundation for future smart lock projects.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/OLleJgI8jVk)  

---

## Next Iterations  
- Add OLED display for masked password entry (`* * * *`)  
- Implement long-press combo for password reset  
- Integrate servo for real locking/unlocking mechanism  
- Upgrade to ESP32 for app-based or IoT-enabled control  

---
