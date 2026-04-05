# VectorFlight
### Flight Control Stack & Physics Simulation

[https://zacktronics.com/](https://zacktronics.com/)

**VectorFlight** is a comprehensive aerospace engineering project developed over the course of 5 years. It features a sophisticated, low-latency telemetry protocol, a real-time physics simulation, and a drone control suite. 

The architecture is built for **parity**: the same C++ codebase can run as a graphical Ground Control Station (GCS) or as a headless, embedded flight controller on a Raspberry Pi or microcontroller.

---

## 📖 Documentation
For a deep dive into the system architecture, PID tuning, and dual-computer network setup, please refer to the:
* **VectorFlight - Pegasus - Manual.md** (or .docx)

The manual provides a technical roadmap covering everything from the 14-step variable handshake to Hardware-in-the-Loop (HIL) testing.

---

## 🚀 Quick Start: Loopback Demo
See Chapter 0 of the documentation referenced above.  

---

## 📂 Key Files to Explore
* **Simulation Engine:** `GroundControlStation/OpenGL/z01_SimFlightControl.h`
* **Flight Control Algorithm:** `GroundControlStation/OpenGL/GL_4_Animate.h`
* **Communication Protocols:** `GroundControlStation/Communications`
* **`Globals/globalStructs.h`**: The structural definition of the `SimuHeli` physics model and the `SuperVar` memory framework.
---

## 📦 Installation & Build



## ⚖️ License
Original control logic, physics engine, and protocol definitions are licensed under the **MIT License**.
Copyright (c) 2026 Zacktronics.

This project utilizes the **Qt Framework**, used under the **GNU LGPL v3**.

---

## 👨‍💻 About the Author
**Zackery Sobin** is a Senior Design Engineer in Firmware with a background in nuclear electronics and industrial SCADA systems. VectorFlight represents a multi-year effort to unify desktop simulation with embedded flight hardware.