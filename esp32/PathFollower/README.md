---

# PathFollower – ESP32 Line Following Robot with IR Sensors & L298N

---

PathFollower is an ESP32-based autonomous robot that detects and follows a line using IR sensors and real-time motor control. It functions as a compact self-contained robotics system that demonstrates embedded decision-making without any external computation.

The robot continuously reads surface contrast (black/white) and dynamically adjusts its movement to stay aligned with the path.

---

## What It Does
- Detects line position using dual IR sensors
- Moves forward when aligned with the path
- Adjusts direction using left/right corrections
- Stops when the line is lost
- Uses PWM for smooth motor speed control

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- L298N Motor Driver
- 2 × IR Line Sensors
- 2 × DC Motors + Wheels + Chassis
- Li-ion / LiPo Battery Pack
- Breadboard + Jumper Wires

---

## Pin Connections
- IR Sensors → GPIO 34 (Left), GPIO 35 (Right)
- Motor Driver:
  - IN1 → 26
  - IN2 → 27
  - IN3 → 32
  - IN4 → 33
  - ENA → 25
  - ENB → 13

---

## How It Works
- IR sensors detect surface color (LOW = black, HIGH = white)
- ESP32 continuously reads both sensor inputs
- Based on sensor states:
  - Both HIGH → Move forward
  - Left HIGH, Right LOW → Turn left
  - Left LOW, Right HIGH → Turn right
  - Both LOW → Stop (line lost)
- PWM signals control motor speed with slight bias for stability
- Robot self-corrects in real time to stay on the path

---

## Technical Relevance
- Real-time embedded control systems
- PWM motor speed control using ESP32
- Motor driver interfacing (L298N)
- Sensor-based decision making
- Low-cost autonomous robotics design

---

## Learning Alignment
- Working with IR line sensors
- Using PWM on ESP32 (ledcWrite)
- Controlling DC motors via motor driver
- Implementing basic control logic
- Understanding real-world robotics behavior

---

## Personal Note
PathFollower was built to explore the fundamentals of robotics and embedded control systems.

Tuning motor speeds and observing how small sensor variations affect movement gave me a practical understanding of real-world imperfections — something that simulations never fully capture.

This project strengthened my foundation in building responsive and adaptive embedded systems.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/1FDQ9LFt_Uw)

---

## Next Iterations
- Add a center IR sensor for improved accuracy
- Implement PID control for smoother motion
- Add Bluetooth/Wi-Fi telemetry
- Integrate obstacle detection
- Extend to maze-solving capabilities

---
