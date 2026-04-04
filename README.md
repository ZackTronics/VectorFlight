# VectorFlight
### High-Fidelity Flight Control Stack & 6-DOF Physics Simulator

**VectorFlight** is a comprehensive aerospace engineering project designed to bridge the gap between digital logic and mechanical reality. Developed over five years of iterative engineering, this repository contains a complete flight control ecosystem—from low-level MEMS sensor fusion to a high-level 3D Ground Control Station (GCS).

The project was born from a deep fascination with physics and a professional commitment to "mission-critical" reliability, drawing on my background as a Naval-trained nuclear reactor operator to deliver a robust, failsafe-oriented architecture.

---

## 🛠 Technical Architecture

The system is architected into two primary environments: a **Real-Time Flight Controller** and a **Desktop Command & Simulation Suite**.

### 1. Ground Control Station (GCS) & Simulator
Located in `/GroundControlStation`, this module is built with **C++** and **Qt 5/6**.
* **6-DOF Physics Engine:** A custom simulator implementing vector mathematics for real-time flight modeling, including gravity, ground-effect, and torque summation.
* **PID Control Suite:** Modular Proportional-Integral-Derivative loops for Roll, Pitch, and Yaw stability, featuring integral windup guards and real-time coefficient tuning.
* **3.D Visualization:** A custom OpenGL-based rendering engine providing real-time visual telemetry of flight orientation.
* **ZPack Protocol:** A proprietary, high-velocity IP-based telemetry protocol featuring **CRC-X25** validation and a 10-stage state-machine handshake for reliable data synchronization.

### 2. Firmware & Embedded Systems
Located in `/Firmware_Embedded`, this module focuses on hardware-level execution.
* **Sensor Fusion:** I2C/SPI drivers for MEMS IMUs (Accelerometers, Gyroscopes, and Magnetometers).
* **Target Portability:** Architecture-aware code with specific optimizations for **ARM-based targets** (Raspberry Pi/BeagleBone) and x86 simulators via preprocessor directives.
* **Real-Time Reliability:** Implementation of heartbeat monitoring, hardware watchdog timers, and failsafe recovery routines to handle network congestion or signal loss.

---

## 🚀 Key Features

* **Asynchronous Telemetry:** Efficient data streaming with periodicity management to prevent network saturation.
* **Diagnostic Logging:** Advanced color-coded event logging for real-time protocol debugging and RTT (Round Trip Time) latency analysis.
* **Hardware Abstraction Layer (HAL):** Seamless switching between simulated environments and live flight hardware.
* **Precision Manual Control:** Integrated support for multi-axis joystick polling with customizable exponential curves and deadbands.

---

## 📦 Installation & Build

### Prerequisites
* **Qt Creator** (v4.14+ recommended)
* **Qt 5.15 or 6.x**
* **OpenGL Support**

### Build Instructions
1.  Clone the repository:
    ```bash
    git clone [https://github.com/Zacktronics/VectorFlight.git](https://github.com/Zacktronics/VectorFlight.git)
    ```
2.  Open `SendingUnit.pro` in Qt Creator.
3.  **For Desktop Simulator:** Ensure `CONFIG += pi_target` remains commented in the `.pro` file.
4.  **For Raspberry Pi:** Uncomment `CONFIG += pi_target` to enable hardware-specific I2C drivers and GPIO mappings.
5.  Build and Run.

---

## ⚖️ License

Original control logic, physics engine, and protocol definitions are licensed under the **MIT License**.
Copyright (c) 2026 Zacktronics.

This project utilizes the **Qt Framework**, used under the **GNU LGPL v3**.

---

## 👨‍💻 About the Author
**Zackery Sobin (Zacktronics)**
*Senior Design Engineer | Firmware & Embedded Systems*
*Navy Nuclear Power Veteran | BS Electrical Engineering*

Driven by technical curiosity and the pursuit of rigorous precision.