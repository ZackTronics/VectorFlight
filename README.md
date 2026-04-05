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
For the most simple demonstration, the ground control program can be run in **loopback mode** to control a simulation rendered with OpenGL on a single machine.

1.  **Open the Project:** Open `SendingUnit.pro` with Qt Creator.
2.  **Initial Build:** Build and run the project. Note that the program may initially complain about missing models or settings.
3.  **Deploy Assets:** You must manually copy the following folders into your compiled build directory (e.g., `build-SendingUnit-Desktop.../`):
    * Copy the **`models`** folder.
    * Copy the **`ProgramData`** folder (contains `retainData.stz`).
4.  **Hardware:** Plug in an Xbox controller.
5.  **Run:** Restart the program, navigate to **Main Display > Helicopter Simulation**, and begin.

---

## 📂 Key Files to Explore
* **Simulation Engine:** `GroundControlStation/OpenGL/z01_SimFlightControl.h`
* **Flight Control Algorithm:** `GroundControlStation/OpenGL/GL_4_Animate.h`
* **Communication Protocols:** `GroundControlStation/Communications`
* **`Globals/globalStructs.h`**: The structural definition of the `SimuHeli` physics model and the `SuperVar` memory framework.
---

## 📦 Installation & Build

### Prerequisites
* **Qt Creator** (v4.14+ recommended)
* **Qt 5.15 or 6.x**
* **OpenGL Support**

### Build Instructions
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/Zacktronics/VectorFlight.git](https://github.com/Zacktronics/VectorFlight.git)
    ```
2.  **Configure Target:**
    * **For Desktop Simulator:** Ensure `CONFIG += pi_target` is commented in the `.pro` file.
    * **For Embedded Target:** Uncomment `CONFIG += pi_target` to enable I2C drivers and GPIO mappings.
3.  **Build and Run.**

---

## ⚖️ License
Original control logic, physics engine, and protocol definitions are licensed under the **MIT License**.
Copyright (c) 2026 Zacktronics.

This project utilizes the **Qt Framework**, used under the **GNU LGPL v3**.

---

## 👨‍💻 About the Author
**Zackery Sobin** is a Senior Design Engineer in Firmware with a background in nuclear electronics and industrial SCADA systems. VectorFlight represents a multi-year effort to unify desktop simulation with embedded flight hardware.