/*
---

# 🔐 TouchVault v1.0: Touch-Activated Secure Safe with LCD & RGB Feedback 📟🔧

---

**TouchVault v1.0** is an interactive smart safe that unlocks using a **triple-tap touch input**. It integrates a **servo motor** for locking, a **16x2 LCD display** for real-time prompts, an **RGB LED** for state indication, and a **buzzer** for audio feedback. This project simulates a **real-world access control system** with simple hardware and intuitive interaction.  

---

🔑 WHAT IT DOES:  
----------------  

- 👆 Detects **3 tap sequence** from capacitive touch sensor (with timing logic)  
- 🔓 Correct password → Servo unlocks, LCD shows success, LED turns green, buzzer happy beep  
- ❌ Wrong / timeout → LCD shows error, LED flashes red, buzzer error beeps  
- 🔄 System resets to idle (blue LED + “Enter Password” prompt) after each attempt  
- 📟 Serial Monitor logs tap detection + unlock events  

---

🧰 COMPONENTS USED:  
--------------------  
- Arduino Uno / Nano  
- Capacitive Touch Sensor  
- Servo Motor (SG90 or similar)  
- RGB LED (Common Cathode preferred)  
- Buzzer  
- 16x2 LCD Display  
- Resistors (220–330Ω for RGB)  
- Breadboard & Jumper Wires  

---

🎮 PIN ASSIGNMENTS:  
--------------------  
- Touch Sensor → D2  
- RGB LED → D3 (Red), D5 (Green), D6 (Blue)  
- Servo Motor → D9  
- Buzzer → A0  
- LCD → RS(4), EN(7), D4(8), D5(10), D6(11), D7(12)  

---

🧠 HOW IT WORKS:  
-----------------  
- System starts in **idle** mode (Blue LED + “Enter Password”)  
- Touch taps are counted with debounce + timing logic (`millis()`)  
- If 3 taps occur within allowed window → **unlock sequence**  
- If taps incorrect / delayed → **error sequence**  
- LCD displays live status messages for all stages  
- RGB LED + buzzer provide instant visual + audio feedback  

---

🌐 TECH & APPLICATIONS:  
------------------------  
- 🔒 Entry-level simulation of **access control systems**  
- 🏠 Smart lockers / IoT-based secure storage  
- 🎮 Interactive tap-based input systems  
- 📡 Foundation for **dual-mode authentication prototypes**  

---

📚 Learning Alignment:  
-----------------------  
- Capacitive touch input & debounce handling  
- Password/tap sequence validation with **timing windows**  
- LCD interfacing for **real-time user feedback**  
- RGB LED control using **PWM states**  
- Servo + buzzer integration with logical conditions  

---

💡 PERSONAL NOTE:  
------------------  
**TouchVault v1.0** was a good step into **embedded interaction design**. Keeping the hardware simple but adding LCD, LED, and buzzer feedback made it satisfying to build. Seeing the green light and servo unlock after 3 taps felt like the system really came alive. 

---

🎬 Watch the working demo here:  
[Demo Video](https://youtu.be/CscJnCIo-dE)

---

🚀 NEXT ITERATIONS:  
---------------------  
- Add EEPROM to store unlock count  
- Replace single tap sensor with **capacitive keypad**  
- Add Bluetooth app for dual-mode authentication  
- Show tap count live on LCD  

---
*/
