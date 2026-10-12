---

# RoboArmV1 – ESP32-Based 6-Axis Pick-and-Place Robotic Arm

---

RoboArmV1 is an ESP32-based 6-axis robotic arm designed to perform a predefined pick-and-place movement sequence using six servo motors. It functions as a multi-axis electromechanical system that combines servo control, motion sequencing, push-button operation, and visual status indication.

The system uses a PCA9685 servo driver to control six servo motors through I²C communication with the ESP32. A 12V rechargeable Li-Po battery and high-current DC-DC buck converter provide the external power stage required for servo operation. When triggered using the push button, the arm executes its programmed movement sequence and automatically returns to its initial position.

---

## What It Does
- Controls six servo motors across six axes
- Performs a predefined pick-and-place movement sequence
- Starts a complete movement cycle using a push button
- Moves individual servos smoothly to programmed target angles
- Sequentially returns all servos to their initial positions
- Provides red and green LED status indication
- Uses a dedicated external power stage for servo operation

---

## Components Used
- ESP32 Dev Board (WROOM-32)
- PCA9685 16-Channel PWM Servo Driver
- 4 × High-Torque Servo Motors
- 2 × Micro Servo Motors
- 12V Rechargeable Li-Po Battery
- High-Current DC-DC Buck Converter
- Push Button
- Red LED
- Green LED
- Robotic Arm Mechanical Structure
- Jumper Wires / Connecting Wires

---

## Pin Connections
- PCA9685 Servo Driver (I²C):
  - SDA → 21
  - SCL → 22
- Push Button:
  - Signal → 4
- Green LED:
  - Signal → 18
- Red LED:
  - Signal → 19
- Servo Motors:
  - PCA9685 Channels → 0, 1, 2, 3, 4, 5

---

## How It Works
- ESP32 initializes the PCA9685 servo driver through I²C
- PCA9685 generates PWM signals for the six servo channels
- All servos are initially positioned at their programmed 0° reference
- Red LED remains ON while the system is idle
- Pressing the push button starts one complete movement sequence
- Red LED turns OFF and green LED turns ON during operation
- Each servo moves smoothly from its initial position to its predefined target angle
- Servo movement is performed incrementally for smoother motion
- After reaching the target configuration, the arm holds its position for five seconds
- Servos sequentially return to their initial positions in reverse order
- The sixth servo performs one additional forward-and-return movement
- Green LED turns OFF and red LED turns ON when the sequence is complete
- System then waits for the next push-button command

---

## Technical Relevance
- Multi-axis robotic control using ESP32
- PCA9685-based multi-servo PWM generation
- I²C communication between embedded devices
- Sequential robotic motion control
- Smooth incremental servo positioning
- Push-button triggered control logic
- External power management for multi-servo systems

---

## Learning Alignment
- Controlling multiple servo motors using ESP32
- Interfacing PCA9685 servo drivers using I²C
- Developing predefined robotic movement sequences
- Implementing smooth servo angle transitions
- Coordinating multiple actuators in an embedded system
- Using digital inputs and LED status indicators
- Understanding power requirements for multi-servo robotic systems

---

## Personal Note
RoboArmV1 was built to explore multi-axis robotic control and the coordination of multiple servo motors within a complete electromechanical system.

Working with the ESP32, PCA9685 servo driver, external power stage, push-button control, and six servo motors helped me better understand motion sequencing, servo calibration, power management, and the integration of electronics with mechanical systems.

This project provided hands-on experience in developing a functional 6-axis robotic arm capable of executing a predefined pick-and-place movement cycle and returning automatically to its initial position.

---

## Demo
Watch the working demo here:  
[Demo Video](https://youtu.be/qt7ssO2UNCo)

---

## Next Iterations
- Add joystick or wireless manual control
- Implement programmable pick-and-place positions
- Add inverse kinematics for coordinated movement
- Integrate sensors for object detection
- Add gripper feedback and object sensing
- Develop a web-based control interface
- Improve motion planning and synchronization
- Explore autonomous pick-and-place operation

---
