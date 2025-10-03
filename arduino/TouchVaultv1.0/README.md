---

# TouchVault v1.0: Touch-Activated Secure Safe with LCD & RGB Feedback  

---

**TouchVault v1.0** is an interactive smart safe that unlocks using a triple-tap touch input. It integrates a servo motor for locking, a 16x2 LCD display for real-time prompts, an RGB LED for state indication, and a buzzer for audio feedback. This project simulates a real-world access control system with simple hardware and intuitive interaction.  

---

## What It Does  
- Detects a 3-tap sequence from the capacitive touch sensor (with timing logic)  
- Correct password → Servo unlocks, LCD shows success, LED turns green, buzzer beeps once  
- Incorrect password / timeout → LCD shows error, LED flashes red, buzzer error beeps  
- System resets to idle (blue LED + “Enter Password” prompt) after each attempt  
- Serial Monitor logs tap detection and unlock events  

---

## Components Used  
- Arduino Uno / Nano  
- Capacitive Touch Sensor  
- Servo Motor (SG90 or similar)  
- RGB LED (Common Cathode preferred)  
- Buzzer  
- 16x2 LCD Display  
- Resistors (220–330Ω for RGB)  
- Breadboard + Jumper Wires  

---

## Pin Assignments  
- Touch Sensor → D2  
- RGB LED → D3 (Red), D5 (Green), D6 (Blue)  
- Servo Motor → D9  
- Buzzer → A0  
- LCD → RS(4), EN(7), D4(8), D5(10), D6(11), D7(12)  

---

## How It Works  
- System starts in idle mode (Blue LED + “Enter Password”)  
- Touch taps are counted with debounce and timing logic (`millis()`)  
- If 3 taps occur within the allowed window → unlock sequence  
- If taps are incorrect or delayed → error sequence  
- LCD shows live status messages at each stage  
- RGB LED and buzzer provide visual and audio feedback  

---

## Technical Relevance  
- Entry-level simulation of access control systems  
- Smart lockers / IoT-based secure storage  
- Tap-based input systems and gesture authentication  
- Foundation for dual-mode authentication prototypes  

---

## Learning Alignment  
- Capacitive touch input and debounce handling  
- Password/tap sequence validation with timing windows  
- LCD interfacing for real-time user feedback  
- RGB LED control using PWM states  
- Servo and buzzer integration with logical conditions  

---

## Personal Note  
TouchVault v1.0 was a solid step into embedded interaction design. Keeping the hardware simple but adding LCD, LED, and buzzer feedback made it satisfying to build. Seeing the green light and servo unlock after three taps felt like the system really came alive.  

---

## Demo  
Watch the working demo here:  
[Demo Video](https://youtu.be/CscJnCIo-dE)  

---

## Next Iterations  
- Add EEPROM to store unlock count  
- Replace single tap sensor with capacitive keypad  
- Add Bluetooth app for dual-mode authentication  
- Show tap count live on LCD  

---
