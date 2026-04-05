# VectorFlight
### Flight Control Stack & Physics Simulation

The VectorFlight Pegasus Control System was developed with an ambitious engineering goal: to create a flight control architecture that operates identically whether it is flying a virtual drone in a 3D environment or a physical aircraft in the field. 
By using a "single source of truth" via the SuperVar framework, Pegasus allows for the seamless iteration of complex flight dynamics, autopilot logic, and sensor filtering on a desktop PC, which can then be deployed to a Raspberry Pi or microcontroller target without rewriting the core engine. 

Whether this suite is utilized as a high-fidelity simulator for pilot training or as the primary flight-brain for a custom multi-rotor, this manual provides the technical roadmap for configuration, networking, and flight operations. 



 It features a sophisticated, low-latency telemetry protocol, a real-time physics simulation, and a drone control suite. 

The architecture is built for **parity**: the same C++ codebase can run as a graphical Ground Control Station (GCS) or as a headless, embedded flight controller Linux - Interfaced to a bare metal microcontroller with sensors.

---

## 📖 Documentation
Full Documentation.
[**VectorFlight - Pegasus - Manual.md** ](https://github.com/ZackTronics/VectorFlight/blob/main/VectorFlight_Pegasus_Manual.md) <br>
                                                    

(See Also):<br>
[https://zacktronics.com/](https://zacktronics.com/)


---

## 📂 Key Files to Explore

* **Simulation Engine:** [`z01_SimFlightControl.h`](https://github.com/ZackTronics/VectorFlight/blob/main/VectorFlight_Pegasus_Core/OpenGL/z01_SimFlightControl.h)
* **Flight Control Algorithm:** [`GL_4_Animate.h`](https://github.com/ZackTronics/VectorFlight/blob/main/VectorFlight_Pegasus_Core/OpenGL/GL_4_Animate.h)
* **Memory Framework:** [`superVar_Declarations.h`](https://github.com/ZackTronics/VectorFlight/blob/main/VectorFlight_Pegasus_Core/Globals/superVar_Declarations.h)
* **Communication Protocols:** [Communications Directory](https://github.com/ZackTronics/VectorFlight/tree/main/VectorFlight_Pegasus_Core/Communications)

## ⚖️ License
Original control logic, physics engine, and protocol definitions are licensed under the **MIT License**.
Copyright (c) 2026 Zacktronics.

This project utilizes the **Qt Framework**, used under the **GNU LGPL v3**.

---

## 👨‍💻 About the Author
**Zackery Sobin** is a Senior Design Engineer in Firmware with a background in nuclear electronics and industrial SCADA systems. VectorFlight represents a multi-year effort to unify desktop simulation with embedded flight hardware.