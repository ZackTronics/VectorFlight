# VectorFlight
### Flight Control Stack & Physics Simulation

**VectorFlight** is a comprehensive aerospace engineering project developed over the course of 5 years. It features a sophisticated, low-latency telemetry protocol, a real-time physics simulation, and a drone control suite. 

The architecture is built for **parity**: the same C++ codebase can run as a graphical Ground Control Station (GCS) or as a headless, embedded flight controller Linux - Interfaced to a bare metal microcontroller with sensors.

---

## 📖 Documentation
Available here:<br>
[**VectorFlight - Pegasus - Manual.md** (or .docx)](https://github.com/ZackTronics/VectorFlight/blob/main/VectorFlight%20-%20Pegasus%20-%20Manual.docx) <br>
See "Chapter 0" for quick start loopback demo.

See Also:<br>
[https://zacktronics.com/](https://zacktronics.com/)

---


---

## 📂 Key Files to Explore

* **Simulation Engine:** [`z01_SimFlightControl.h`](./GroundControlStation/OpenGL/z01_SimFlightControl.h)
* **Flight Control Algorithm:** [`GL_4_Animate.h`](./GroundControlStation/OpenGL/GL_4_Animate.h)
* **Communication Protocols:** [Communications Directory](./GroundControlStation/Communications)
* **Memory Framework:** [`globalStructs.h`](./Globals/globalStructs.h)


## ⚖️ License
Original control logic, physics engine, and protocol definitions are licensed under the **MIT License**.
Copyright (c) 2026 Zacktronics.

This project utilizes the **Qt Framework**, used under the **GNU LGPL v3**.

---

## 👨‍💻 About the Author
**Zackery Sobin** is a Senior Design Engineer in Firmware with a background in nuclear electronics and industrial SCADA systems. VectorFlight represents a multi-year effort to unify desktop simulation with embedded flight hardware.