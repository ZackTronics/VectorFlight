# VectorFlight - Pegasus - Control System 
**Zackery Sobin** 

## Introduction: The Pegasus Philosophy 
The VectorFlight Pegasus Control System was developed with an ambitious engineering goal: to create a flight control architecture that operates identically whether it is flying a virtual drone in a 3D environment or a physical aircraft in the field. 
By using a "single source of truth" via the SuperVar framework, Pegasus allows for the seamless iteration of complex flight dynamics, autopilot logic, and sensor filtering on a desktop PC, which can then be deployed to a Raspberry Pi or microcontroller target without rewriting the core engine. 

Whether this suite is utilized as a high-fidelity simulator for pilot training or as the primary flight-brain for a custom multi-rotor, this manual provides the technical roadmap for configuration, networking, and flight operations. 

> Note on this Documentation: This manual was developed with the assistance of an AI collaborator (Gemini). 
> While the instructions and technical details are derived directly from the Pegasus source code, users should exercise standard engineering caution when applying these configurations to physical flight hardware. 
> Always verify safety-critical parameters—such as battery voltage cutoffs and RTH altitudes—in a controlled environment. 

## Contents 
* Introduction: The Pegasus Philosophy
* Chapter 0: Quick Start (Loopback Demo)
  * 0.1 Opening the Project
  * 0.2 Initial Build and Directory Setup
  * 0.3 Running the Simulation
* Chapter 1: System Overview
  * 1.1 Introduction to Pegasus Control
  * 1.2 The Hardware-in-the-Loop (HIL) Bridge
  * 1.3 The "SuperVar" Framework
  * 1.4 Communication Architecture
  * 1.5 System Roles
* Chapter 2: Installation & Prerequisites
  * 2.1 Software Requirements
    * 2.1.1 Qt Framework
    * 2.1.2 Development Environment
  * 2.2 Hardware Setup
    * 2.2.1 Pilot Interface (Xbox Controller)
    * 2.2.2 Flight Controller (Raspberry Pi / Microcontroller Target)
  * 2.3 Project Compilation
    * 2.3.1 Building for Desktop (Default)
    * 2.3.2 Building for Raspberry Pi / MCU
  * 2.4 Data Persistence and Directory Structur
* Chapter 3: Networking & Connectivity
  * 3.1 The UDP Architecture
  * 3.2 Role Configuration and Identity
    * 3.2.1 Serving Helicopter (The Flight Target)
    * 3.2.2 Client Computer (Ground Control Station)
  * 3.3 Network Performance & Latency
    * 3.3.1 Round Trip Time (RTT) and Baselines
    * 3.3.2 Packet Integrity and Error Tracking
  * 3.4 Data Transmission Control
  * 3.5 Connectivity Handshake
* Chapter 4: The Handshake & Variable Synchronization
  * 4.1 The Synchronization Philosophy
  * 4.2 The Handshake State Machine
    * 4.2.1 Phase 1: Identity & Version Verification
    * 4.2.2 Phase 2: Bulk Data Transfer
    * 4.2.3 Phase 3: Verification & Steady State
  * 4.3 SuperVar Architecture
    * 4.3.1 Variable Types and Storage
    * 4.3.2 Functional Flags
  * 4.4 Data Persistence (.stz and .csv)
    * 4.4.1 The .stz (Settings) File
    * 4.4.2 The .csv (Retain) File
  * 4.5 Manual Synchronization
* Chapter 5: Controller Configuration
  * 5.1 Input Device Architecture
  * 5.2 Mapping the Xbox Controller
  * 5.3 The Calibration Routine
    * 5.3.2 Saving Offsets
  * 5.4 Data Transmission (The Controller Word)
  * 5.5 Visual Verification
* Chapter 6: Flight Simulation & Graphics
  * 6.1 The 3D Rendering Engine
    * 6.1.1 OpenGL Architecture
  * 6.2 Aircraft Geometry Configuration
    * 6.2.1 Motor Mapping
    * 6.2.2 Preset Configurations
  * 6.3 The Physics Engine (SimuHeli)
    * 6.3.1 Forces and Moments
    * 6.3.2 The Animation Loop
  * 6.4 Visual Elements of the Drone
  * 6.5 Interacting with the Simulation
* Chapter 7: Autopilot & Safety Logic
  * 7.1 Autopilot Architecture
  * 7.2 Flight Envelopes and Operational Limits
  * 7.3 Communication Loss Failsafes (Comms Loss)
  * 7.4 Battery Management & Safety
  * 7.5 PID Control & Stabilization Logic
    * 7.5.1 Axis Stabilization
    * 7.5.2 Motor Summation
  * 7.6 Monitoring Autopilot State
* Chapter 8: Maintenance & Diagnostics
  * 8.1 The Variable List (SuperVar Explorer)
    * 8.1.1 Accessing and Searching
    * 8.1.2 Real-Time Editing
  * 8.2 Event & Communication Logging
    * 8.2.1 Log Types
    * 8.2.2 Log Management
  * 8.3 Troubleshooting Common Errors
    * 8.3.1 Socket Binding Failures
    * 8.3.2 Version & Checksum Mismatches
    * 8.3.3 Controller Connectivity
  * 8.4 Maintenance Checklist
* Chapter 9: Dual-Headed Simulation Setup
  * 9.1 Concept: Distributed Processing
  * 9.3 Step 2: Configuring Computer A (The Controller)
  * 9.4 Step 3: Configuring Computer B (The Simulator)
  * 9.5 Step 4: Variable Synchronization (The Handshake)
  * 9.6 Performance Monitoring 25 

## Chapter 0: Quick Start (Loopback Demo) 
For the most straightforward introduction to the system, you can run a "Loopback" simulation where the Ground Control interface and the 3D OpenGL renderer run on the same machine. 

### 0.1 Opening the Project 
1. Launch Qt Creator. 
2. Open the SendingUnit.pro project file. 
3. Select a valid kit (e.g., Desktop Qt 5.5.1 MSVC2010 32-bit). 

### 0.2 Initial Build and Directory Setup 
1. Click Run (or press Ctrl+R). 
2. The program will initialize but may complain about missing OpenGL models or settings. 
3. Deploy Assets: You must manually copy your asset folders into the build directory created by Qt Creator (e.g., build-SendingUnit-Desktop_Qt_5_5_1_MSVC2010_32bit-Debug/). 
4. Copy the "models" folder into the build directory. 
5. Copy the "ProgramData" folder (or the retainData.stz settings file) into the build directory. 
6. Restart: Run the program again. It should now load the 3D environment and the default parameter set without errors. 

### 0.3 Running the Simulation 
1. Plug in an Xbox Controller: Ensure it is recognized by the OS before proceeding. 
2. Configure Role: Go to Parameters > Communication Settings and ensure the system is set to Serving Helicopter. 
3. Enter Simulation: Go to Main Display > Helicopter Simulation. 
4. Begin: Move the sticks on your controller to see the 3D drone respond in real-time via the loopback network. 

## Chapter 1: System Overview 

### 1.1 Introduction to Pegasus Control 
Pegasus Control is a unified, cross-platform flight control and simulation suite designed for the development, testing, and deployment of multi-rotor aircraft logic. 
At its core, the system is built to bridge the gap between virtual simulation and physical hardware. 
It allows an engineer to run a high-fidelity 3D simulation on a desktop environment or deploy the exact same physics and control logic to a micro-processing target, such as a Raspberry Pi or a dedicated microcontroller (MCU). 

### 1.2 The Hardware-in-the-Loop (HIL) Bridge 
The system architecture is designed for "Hardware-in-the-Loop" testing. In this ecosystem, the software can function in two distinct capacities: 
* The Desktop Simulator: Provides a full OpenGL-based 3D viewport for visual testing of flight dynamics, allowing for the safe iteration of PID loops and failsafe logic without risking physical hardware. 
* The Flight Controller (Target Hardware): When compiled for target hardware (like a Raspberry Pi or MCU), the core physics and control loops run in real-time, interfacing with physical sensors via the I2C bus. 

In both scenarios, the desktop version of the software acts as the Ground Control Station (GCS), providing a graphical interface to monitor telemetry and modify system behavior on the fly. 

### 1.3 The "SuperVar" Framework 
The primary innovation of Pegasus Control is the SuperVar framework. 
SuperVars are network-aware parameters that represent the "shared mental context" between the Ground Control Station and the flight target (whether that target is a virtual sim or a physical MCU). 
Every critical parameter—from battery thresholds and motor geometry to real-time sensor data—is a SuperVar. 
When a user modifies a setting in the GCS (e.g., increasing a roll-rate constant), the system uses a robust 14-step handshake protocol to update that variable on the target hardware. 
This ensures that the Ground Station and the Flight Controller are always synchronized, preventing the state-mismatches that often plague remote-controlled systems. 

### 1.4 Communication Architecture 
The system utilizes a custom UDP-based protocol over Port 12346 to facilitate low-latency communication. 
Because flight stability depends on timing, the protocol is optimized for speed while maintaining reliability for critical configuration data: 
* Real-Time Data (Non-Critical): High-speed telemetry and joystick inputs are transmitted via "best-effort" UDP packets. This minimizes lag, ensuring that the latest stick position is always prioritized. 
* Configuration Data (Critical): Changes to SuperVars and system handshakes require explicit acknowledgments (ACKs). If the MCU or Simulation target does not confirm receipt of a critical parameter, the GCS will automatically retransmit the data based on the calculated Round Trip Time (RTT). 

### 1.5 System Roles 
To facilitate this networked environment, the software utilizes a role-based configuration: 
* Client Computer (GCS): The primary pilot interface. It captures Xbox controller input, manages the master list of SuperVars, and displays telemetry logs. 
* Serving Helicopter (Sim or MCU): The "Flight Intelligence." It receives control words, executes the physics/PID loops, and drives the output—either to an OpenGL renderer or to physical ESCs (Electronic Speed Controllers) on an aircraft. 

By maintaining the same code footprint across desktop and embedded targets, Pegasus Control allows for a seamless transition from a virtual quadcopter on a screen to a physical aircraft in the field. 

## Chapter 2: Installation & Prerequisites 

### 2.1 Software Requirements 

#### 2.1.1 Qt Framework 
The system is built using the Qt Framework. To compile the project, the following modules must be installed via the Qt Maintenance Tool: 
* Core, GUI, and Widgets: Required for the primary interface, window management, and core logic. 
* Network: Essential for the UDP-based communication between the Ground Control Station and the flight target. 
* OpenGL & Multimedia (Desktop only): Required for the 3D rendering engine and visual simulation. 

#### 2.1.2 Development Environment 
* Windows: Compiling for Windows requires a C++ compiler such as MSVC (Microsoft Visual C++). The integration with Xbox controllers relies on the XInput library. If you encounter errors regarding XINPUT9_1_0.dll, install the DirectX End-User Runtimes. 
* Linux / Raspberry Pi: Compiling for Linux or the Raspberry Pi target requires standard GCC build tools. 

### 2.2 Hardware Setup 

#### 2.2.1 Pilot Interface (Xbox Controller) 
The system is optimized for an Xbox 360 or compatible controller to serve as the pilot's input device. 
* Connection: Connect the controller to the computer designated as the Ground Control Station (GCS). 
* Detection: The software automatically attempts to acquire the controller on startup. If the controller is disconnected or not recognized, a "Controller NOT Connected" warning will appear in the primary viewport. 
* Calibration: Proper operation requires an initial calibration to define stick centers and deadzones, which are stored in the local settings file. 

#### 2.2.2 Flight Controller (Raspberry Pi / Microcontroller Target) 
When the software is deployed to a Raspberry Pi or similar target to act as a physical flight controller, additional hardware configuration is required: 
* I2C Configuration: The target must have I2C communication enabled to interface with flight sensors (accelerometers, gyros, etc.). This typically involves installing i2c-tools and loading the necessary kernel modules (i2c-dev). 
* Permissions: The user account running the software must have permissions to access I2C devices, often managed through udev rules (e.g., setting MODE="0666" for I2C devices). 

### 2.3 Project Compilation 
The compilation process is controlled by the SendingUnit.pro project file. 
This file contains a configuration switch that determines whether the resulting binary is a visual simulator for a desktop or a lightweight flight controller for an embedded target. 

#### 2.3.1 Building for Desktop (Default) 
To build the Ground Control Station or the 3D Simulator: 
1. Open the project in Qt Creator. 
2. Ensure the CONFIG += pi_target line in the .pro file is commented out. 
3. Build the project. This configuration includes all OpenGL rendering libraries and desktop-specific joystick polling logic. 

#### 2.3.2 Building for Raspberry Pi / MCU 
To build the executable for an embedded flight controller: 
1. Uncomment the line # CONFIG += pi_target in the .pro file. 
2. This defines the TARGET_HARDWARE_PI macro. This flag strips away the 3D rendering code and UI dependencies to minimize the footprint. 
3. It activates the I2C sensor communication modules and Linux-specific hardware polling. 

### 2.4 Data Persistence and Directory Structure 
The application requires a specific directory structure to manage settings and logs. 
Ensure the following folder exists in the same directory as the executable: 
* ./ProgramData/: This folder is used to store telemetry logs (commsLog.txt, eventLog.txt) and persistent settings. 
* retainData.stz: This file contains the synchronized SuperVar states. It is loaded automatically on startup. If it is missing, the system will prompt you to select a parameter set to initialize the simulation variables. 

## Chapter 3: Networking & Connectivity 

### 3.1 The UDP Architecture 
Pegasus Control utilizes the User Datagram Protocol (UDP) for all real-time data exchange between the Ground Control Station (GCS) and the flight target. 
UDP is prioritized for its minimal overhead, which is essential for maintaining the high-frequency control loops required for flight stability. 
* The system binds to Port 12346 by default. 
* Upon initialization, the software attempts to secure this port to listen for incoming "ZackPackets" (identified by the 0x25 start byte). 
* If the port is unavailable—often due to another instance of the software already running—the application will issue an "Unable to Bind" warning, as it will be unable to process incoming telemetry or handshake requests. 

### 3.2 Role Configuration and Identity 
The networking behavior of an instance is determined by its assigned role, which dictates how it identifies itself in the packet headers. 

#### 3.2.1 Serving Helicopter (The Flight Target) 
In this role, the application acts as the "Server," whether it is a 3D simulation on a desktop or an MCU/Raspberry Pi acting as a physical flight controller. 
* Function: Listens for ZPack_XBoxControllerWord packets and processes them through the physics and PID engines. 
* Identity: Typically assigned a Component ID of Flightboard (0x03) or Beagleboard (0x02). 
* Responsibility: Transmits real-time telemetry back to the GCS and acknowledges critical configuration changes. 

#### 3.2.2 Client Computer (Ground Control Station) 
This role serves as the pilot's primary interface. 
* Function: Captures controller inputs and manages the master "SuperVar" list. 
* Identity: Assigned a Component ID of ControlLaptop (0x01). 
* Peer Addressing: Requires the IPv4 or IPv6 address of the target. For internal testing on a single machine, the loopback address (127.0.0.1) is supported. 

### 3.3 Network Performance & Latency 
To maintain flight safety, the system provides a dedicated Communication Statistics interface to monitor the health of the data link in real-time. 

#### 3.3.1 Round Trip Time (RTT) and Baselines 
For "Crucial" packets (such as variable updates or handshakes), the system expects an explicit acknowledgment (ACK). 
The time elapsed between sending the packet and receiving the ACK is recorded as the RTT. 
* Average RTT: A smoothed value used to distinguish between temporary jitter and sustained network congestion. 
* Ping Baseline: Users can "Reset" the baseline once a stable connection is established. The Autopilot logic uses this baseline to detect communication degradation; if latency spikes significantly above this value, the system may automatically initiate a "Comms Loss" failsafe (e.g., Position Hold or Return to Home). 

#### 3.3.2 Packet Integrity and Error Tracking 
The system monitors for three specific types of network errors to prevent corrupted data from affecting flight: 
* CRC Errors: Triggered when the 16-bit Cyclic Redundancy Check in the packet footer does not match the calculated value. This is often a sign of electrical interference on a wireless link or a software version mismatch. 
* Bad Length: Occurs if the physical size of the received packet does not match the packletSize declared in its header. 
* Stub Packets: Small fragments or incomplete headers that are discarded by the listener. 

### 3.4 Data Transmission Control 
Within the Communication Settings, users can fine-tune the network load: 
* Packet Intervals: The frequency at which the GCS polls for the Xbox controller can be adjusted (defaulting to 20ms or 50ms). Decreasing this interval provides a more responsive feel but increases network traffic. 
* Transmission Pause: A "Pause All Data Xmit" feature allows users to halt all outbound packets immediately. This is a critical safety feature when troubleshooting configuration issues without affecting the live state of the flight controller. 
* Heartbeats: If the "Serving Helicopter" remains silent for a period exceeding the HeartbeatInterval, it will automatically transmit a heartbeat packet to maintain the connection state and prevent the GCS from timing out. 

### 3.5 Connectivity Handshake 
A successful network connection is defined by more than just the exchange of packets; 
it requires the Handshake Sequence. The software will not allow flight commands to be processed until the 14-step variable synchronization is complete. 
This ensures that the GCS and the MCU/Simulator have identical values for critical parameters like motor angles, mass, and safety limits before the motors are armed. 

## Chapter 4: The Handshake & Variable Synchronization 

### 4.1 The Synchronization Philosophy 
In the Pegasus Control system, flight cannot safely begin until the Ground Control Station (GCS) and the Flight Target (Simulation or MCU) are in perfect agreement regarding the aircraft's configuration. 
Because parameters like PID gains, motor angles, and safety limits are stored locally on both devices, the Handshake Sequence is used to resolve any discrepancies before the system enters a "Ready" state. 

### 4.2 The Handshake State Machine 
The handshake is a multi-step automated process that ensures data integrity across the network. 
It is governed by a state machine that progresses only when specific conditions or network acknowledgments are met. 

#### 4.2.1 Phase 1: Identity & Version Verification 
* Step 1-2 (Initialization): The GCS sends a request for the paramSetVersion and paramSetChecksum from the flight target. 
* Step 3 (Comparison): The GCS compares the returned values against its own local settings. If the versions match, the system may skip to a steady state. If they differ, the system prepares for a bulk synchronization. 

#### 4.2.2 Phase 2: Bulk Data Transfer 
* Step 4 (Directional Sync): Based on the user's choice or system defaults, the GCS decides to either Read from Chopper (update the GCS with the aircraft's current settings) or Write to Chopper (push the GCS settings to the aircraft). 
* Filtering by Flag: The system does not sync every variable in the system. It specifically iterates through the largestVarID and only transmits variables marked with the plsHandshk flag. 

#### 4.2.3 Phase 3: Verification & Steady State 
* Step 5 (Acknowledgment Wait): The GCS waits for the unackedPacketCount to reach zero. It monitors the Round Trip Time (RTT) to ensure all configuration packets were successfully received by the target. 
* Step 10 (Steady State): Once all plsHandshk variables are confirmed, the system enters Step 10. The 3D simulation or physical motors are now "Armed" and ready to respond to Xbox controller inputs. 

### 4.3 SuperVar Architecture 
"SuperVars" are the fundamental data units of the system. Each SuperVar is more than just a value; 
it is a structure that contains metadata used by the network engine. 

#### 4.3.1 Variable Types and Storage 
The system supports a wide range of data types to balance precision and network bandwidth: 
* Integers (uint8, uint16, uint32, uint64): Used for flags, counters, and IDs. 
* Floats (float32, float64): Used for high-precision physics, such as Sensor_Accelerometer_X or Position_X. 
* Strings (QString): Used for descriptive data or error messages (e.g., FlighboardErrorString). 

#### 4.3.2 Functional Flags 
Each SuperVar is assigned flags that dictate its behavior: 
* UserEditable: The variable can be modified via the "All Parameters" list in the UI. 
* defIsRetain: The variable is "persistent" and will be saved to the hard drive when the program closes. 
* plsHandshk: The variable must be synchronized during the initial connection. 
* isStoredOnLaptop / isStoredOnChopper: Defines the "Master" source of truth for the variable. 

### 4.4 Data Persistence (.stz and .csv) 
Pegasus Control uses two primary methods for storing these variables on disk so that calibrations and configurations are not lost between sessions. 

#### 4.4.1 The .stz (Settings) File 
The .stz file (typically retainData.stz) is an XML-structured file that acts as the primary database for the system. 
On startup, the readRetainDataFromFile() function parses this file to populate the live memory addresses of every SuperVar. 

#### 4.4.2 The .csv (Retain) File 
In some configurations, a retainData.csv file is used as a human-readable backup or for quick bulk editing outside of the Qt environment. 
The system monitors these files for changes; if the monitorRetainDataForChangesToSave() function detects a mismatch between the "cached" value and the "live" value, it triggers an automatic write-to-disk operation. 

### 4.5 Manual Synchronization 
While the handshake is typically automatic, users can force a re-synchronization at any time: 
1. Navigate to Parameters > Re-Handshake With Aircraft. 
2. The Event Log will display the transition from HandshakeStep 0 through the sequence. 
3. If the handshake fails (e.g., due to a "Handshake Watchdog" timeout), the system will revert to Step 0 and alert the user to check the network connection or the SystemID. 

## Chapter 5: Controller Configuration 

### 5.1 Input Device Architecture 
The Pegasus Control system is designed primarily for the Xbox 360 Controller (or compatible XInput devices). 
The software utilizes a hardware-abstraction layer that allows the same flight logic to operate whether it is receiving signals from a Windows-based XInput driver, a Linux joystick device (/dev/input/jsX), or a "Dummy" software-generated source for headless testing. 
The system polls the controller at a high frequency (defaulting to 10ms via timer1) to ensure that pilot inputs are captured with minimal jitter before being processed by the local display or transmitted to the flight target. 

### 5.2 Mapping the Xbox Controller 
The software maps the physical hardware to a standardized Struct_XBox360Controller. 
While these mappings can be adjusted in the flight logic, the default configuration for the 3D simulation follows standard "Mode 2" UAV conventions: 
* Left Joystick (LJ): Typically mapped to Vertical Thrust (Y-axis) and Yaw/Rotation (X-axis). 
* Right Joystick (RJ): Mapped to Pitch (Y-axis) and Roll (X-axis) for lateral movement. 
* Triggers (LT/RT): Captured as high-resolution analog values (0–255), often used for auxiliary throttle control or camera gimbal tilt. 
* Buttons (A, B, X, Y): Used for discrete system commands such as Arming Motors, Toggling Autopilot, or Resetting the Simulation View. 

### 5.3 The Calibration Routine 
Because every physical controller has slight mechanical variances, the software includes a dedicated Calibration Mode (num_calibrateMode). 
This routine is essential for ensuring that "center" on your physical stick actually corresponds to "zero force" in the simulation. 

#### 5.3.1 Step-by-Step Calibration 
1. Enter Mode: Navigate to Main Display > Controller Calibration. 
2. Neutral Sampling: Leave the sticks at their rest positions. The system samples the raw analog values (LJ_X_Raw, RJ_X_Raw, etc.) to calculate the average electrical offset. 
3. Range Definition: Move both sticks to their maximum extents in a circular motion. This allows the software to calculate the Magnitude (LJ_Mag) and Angle (LJ_Ang) scaling factors. 
4. Deadzone Calculation: The system automatically establishes a "deadzone" around the center to prevent "drift"—where the drone moves slowly even when you aren't touching the sticks. 

#### 5.3.2 Saving Offsets 
Once calibration is complete, the offsets (e.g., Ctrl.LJ_X_Offset) are stored in the SuperVar system. 
Because these are marked with the defIsRetain flag, they are automatically written to retainData.stz and will be loaded every time the program starts, removing the need for daily recalibration. 

### 5.4 Data Transmission (The Controller Word) 
To save network bandwidth, the entire state of the controller is packed into a specialized ZPack_XBoxControllerWord (0x36) before being sent to the simulation machine or MCU. 
* Bit-Packing: The 11 buttons and the D-pad are compressed into the first 3 bytes of the packet. 
* Analog Compression: Sticks and triggers are converted from their raw values into the shared coordinate system before being appended as byte arrays. 

### 5.5 Visual Verification 
Before attempting flight, the pilot should use the Controller Input screen (Main Display > Controller Input). 
* Visual Feedback: This screen provides a real-time graphical representation of the controller. As you move the physical sticks, the virtual bars on the screen will move to show exactly what the simulation "sees". 
* Connectivity Alerts: If the software loses contact with the USB device, a large red warning "Controller NOT Connected" will be overlaid on the display, and all transmission to the flightboard will be safely halted. 

## Chapter 6: Flight Simulation & Graphics 

### 6.1 The 3D Rendering Engine 
The visual component of Pegasus Control is powered by a custom OpenGL-based engine encapsulated in the Heli_GLWidget. 
This engine is responsible for transforming raw physics data—coordinates, Euler angles, and motor RPMs—into a real-time 3D visualization. 

#### 6.1.1 OpenGL Architecture 
The simulation utilizes a standard 3D pipeline: 
* Geometry Management: 3D objects are constructed using the Patch and Geometry classes, supporting both smooth and faceted shading. 
* Coordinate System: The simulation uses a standard Cartesian system ($X, Y, Z$). In the 3D view, $Y$ represents altitude (vertical), while $X$ and $Z$ represent the lateral ground plane. 
* Lighting and Textures: The environment supports real-time lighting and can load external .obj files with associated texture maps via the ObjMan class. 

### 6.2 Aircraft Geometry Configuration 
The system is aircraft-agnostic, meaning it can simulate various multi-rotor configurations by modifying the physical placement and rotation of the motors. 

#### 6.2.1 Motor Mapping 
Through the Aircraft Geometry window, users can define: 
* Motor Count: Support for up to 6 motors (Hexacopter). 
* Angular Position: Each motor is assigned an angle (0–360°) relative to the aircraft's nose. 
* Rotation Direction: Motors are toggled between Clockwise (CW) and Counter-Clockwise (CCW) rotation to balance the torque of the airframe. 

#### 6.2.2 Preset Configurations 
For rapid setup, the system includes hardcoded presets: 
* Quadcopter: 4 motors placed at 45°, 135°, 225°, and 315°. 
* Hexacopter: 6 motors placed at 60° increments (30°, 90°, 150°, 210°, 270°, 330°). 

### 6.3 The Physics Engine (SimuHeli) 
While the graphics provide visual feedback, the SimuHeli physics engine handles the "truth" of the aircraft's state. 

#### 6.3.1 Forces and Moments 
The physics loop calculates flight movement based on several vectors: 
* Thrust: Calculated per motor based on the Throttle_Motor percentage and MotorMaxThrust constant. 
* Torque: Yaw is controlled by the difference in torque between CW and CCW motors, while Pitch and Roll are controlled by thrust differentials across the airframe. 
* Drag: The system applies linear and rotational drag ($k_{linear}, k_{roll}, k_{yaw}$) to simulate air resistance and prevent infinite acceleration. 

#### 6.3.2 The Animation Loop 
The animateSimulation() function updates the state of the world at a fixed interval (driven by timer3). 
* Integrate Velocity: Current velocities are multiplied by secondsElapsed to update the $X, Y, Z$ positions. 
* Normalize Angles: Heading and tilt angles are wrapped to 0–360° to prevent overflow. 
* Ground Collision: The engine monitors pos_Y. If the altitude reaches zero, vertical velocity is halted to simulate a landing or impact. 

### 6.4 Visual Elements of the Drone 
The drone is rendered procedurally using several primitive components: 
* Helicopter Body: The central chassis of the drone. 
* Motor Housings: Cylindrical objects placed at the geometry coordinates defined in Section 6.2. 
* Rotor Disks: Semi-transparent RectTorus objects that represent the spinning propellers. The visual "thickness" or opacity of these disks can be tied to the motor's throttle value to simulate speed. 

### 6.5 Interacting with the Simulation 
When in Helicopter Simulation Mode, the pilot can use both the Xbox controller and keyboard shortcuts to manage the environment: 
* Reset View: Return the camera to the default follow-position. 
* Freeze Simulation: A debug toggle that forces the drone to a fixed point in space ($0, 5, 40$) to test controller mapping without crashing. 
* Manual Override: Keyboard keys ($W, A, S, D, Q, E$) can be used to manually nudge the camera or environment position for better observation of flight maneuvers. 

## Chapter 7: Autopilot & Safety Logic 

### 7.1 Autopilot Architecture 
The Autopilot system in Pegasus Control acts as a supervisory layer over the core flight dynamics. 
It is responsible for translating high-level mission objectives—such as "Return to Home"—into specific target coordinates and orientations. 
The system is designed to handle both user-initiated commands and automatic safety interventions based on the aircraft's internal state. 

### 7.2 Flight Envelopes and Operational Limits 
To ensure the safety of the simulation and prevent the loss of the virtual or physical aircraft, the system allows for the definition of strict operational boundaries. 
* Altitude Ceiling: Users can define a maximum ceiling in feet, either relative to Sea Level (Setpoint_Ceiling_SeaLevel) or Above Takeoff (Setpoint_Ceiling_DistanceAboveTakeoff). If the aircraft hits this limit, the autopilot will override the pilot's vertical throttle to prevent further ascent. 
* Distance Tolerance: Parameters like AutoPilot_ReturnHomeAltitudeObjectiveToleranceReqd define the "precision window" for the autopilot. The system must bring the aircraft within this distance of the target before the mission segment is considered complete. 

### 7.3 Communication Loss Failsafes (Comms Loss) 
Because the simulation relies on a networked link, the system includes a tiered response strategy for when the connection to the Ground Control Station (GCS) is degraded or lost. 
* Position Hold: The first stage of a comms-loss event. The aircraft utilizes the AutoPilot_CommLoss_Delay_PositionHold timer to maintain its current $X, Y, Z$ coordinates while waiting for a signal recovery. 
* Return Home (RTH): If the connection remains lost beyond the defined threshold, the aircraft transitions to RTH mode, navigating back to the takeoff coordinates. 
* Automatic Land: The final fail-safe. If the aircraft is unable to re-establish a link or reach home, it will initiate a controlled descent based on the AutoPilot_descentRate. 

### 7.4 Battery Management & Safety 
The software continuously monitors the Battery_ActualVoltage and Battery_PercentRemainingFiltered SuperVars. 
* Low Battery Return Home: When the battery reaches a specific percentage (e.g., 25%), the system can automatically trigger a Return Home maneuver. This can be set to Recalculate Continuously, which dynamically adjusts the "Go Home" threshold based on the aircraft's current distance from the origin. 
* Critical Landing: If the battery level becomes critical, the autopilot initiates an immediate landing (AutoPilot_LowBatt_Percent_LandNow) to prevent a mid-air power failure. 
* System Kill: For extreme safety scenarios, the AutoPilot_LowBatt_Percent_KillSystem flag can be set to completely disarm the motors once the aircraft has safely reached the ground. 

### 7.5 PID Control & Stabilization Logic 
The autopilot achieves stability using a series of Proportional-Integral-Derivative (PID) loops found in the z01_SimFlightControl.h module. 

#### 7.5.1 Axis Stabilization 
The system calculates individual error values for Yaw, Pitch, and Roll by comparing the current sensor telemetry against the "Desired" state from the autopilot or the Xbox controller. 
* Proportional (P): Corrects current error (the "nudge"). 
* Integral (I): Corrects accumulated error over time (the "wind-up" correction). 
* Derivative (D): Corrects the rate of change to prevent overshooting the target. 

#### 7.5.2 Motor Summation 
Once the PID values are calculated for each axis, the Thrust_MotorThrottleSummation logic combines them into a single command for each individual motor. 
The system takes the base throttle (Altitude control) and adds or subtracts the Pitch, Roll, and Yaw corrections based on the motor's position in the airframe geometry. 
* Climb Effect Protection: The system monitors the total throttle to ensure that high-intensity Yaw maneuvers do not inadvertently cause the aircraft to climb or lose altitude. 

### 7.6 Monitoring Autopilot State 
The pilot can monitor the active autopilot mode via the Main Window or the Autopilot Settings window. 
The system will display the current status, such as "Manual Pilot," "Autopilot - Fly Home," or "Autopilot - Land," ensuring the operator always knows who is in control of the aircraft. 

## Chapter 8: Maintenance & Diagnostics 

### 8.1 The Variable List (SuperVar Explorer) 
The Variable List is the central diagnostic hub of Pegasus Control. 
It provides a real-time window into the memory of the system, allowing operators to monitor and modify any "SuperVar" currently active in the simulation or on the flight controller. 

#### 8.1.1 Accessing and Searching 
* Access: Navigate to Parameters > All Parameters to open the explorer. 
* Live Search: Use the search bar at the top of the window to filter the hundreds of available variables. The search logic supports partial matches and ignores case sensitivity, making it easy to find specific parameters like "PID," "Battery," or "Motor". 
* Organization: Variables are grouped by their functional class (e.g., Motion Vars, Craft Status). The vertical scroll bar allows for quick navigation through the indexed list. 

#### 8.1.2 Real-Time Editing 
Unlike static configuration files, the Variable List allows for "Hot-Swapping" values during a live session. 
* Editing Logic: When a user clicks into a value field, the system sets the NoEdits_InProgress flag to prevent the display from refreshing while the user is typing. 
* Commiting Changes: Once an edit is finished (by pressing Enter or clicking away), the system immediately updates the local variable and, if the network is active, transmits the new value to the peer machine. 

### 8.2 Event & Communication Logging 
For deep-dive diagnostics, the system maintains two distinct logging streams that can be viewed in real-time or saved for post-flight analysis. 

#### 8.2.1 Log Types 
* Communication Log (Comms): A low-level trace of every UDP packet sent and received. It captures packet IDs, byte sizes, and CRC status. This is the primary tool for identifying network jitter or dropped packets. 
* Event Log: A high-level narrative of system milestones. It records critical events such as "Initiated Handshake," "Controller Disconnected," or "Return to Home Triggered". 

#### 8.2.2 Log Management 
* Scroll Lock: Users can toggle between Scrolling and Scroll Locked modes to pause the log and inspect a specific event without the display jumping to the newest entry. 
* Disk Persistence: Both logs can be automatically written to the ./ProgramData/ directory as commsLog.txt and eventLog.txt. These files include timestamps for every entry, facilitating synchronized debugging between the GCS and the aircraft. 

### 8.3 Troubleshooting Common Errors 
Most system issues stem from network configuration or hardware initialization. 

#### 8.3.1 Socket Binding Failures 
If the application displays an "Unable to Bind Incoming Traffic" warning on startup: 
* Cause: Another instance of the program is already running and has locked Port 12346. 
* Solution: Close all instances of the application and restart. On some systems, a "ghost" process may remain; use your OS Task Manager to ensure no SendingUnit processes are active. 

#### 8.3.2 Version & Checksum Mismatches 
If the connection reaches Handshake Step 3 and then reverts to Step 0: 
* Cause: The paramSetVersion or paramSetChecksum on the Controller does not match the Aircraft. 
* Solution: Ensure both machines are running the exact same version of the compiled code. A single change in globalDefines.h or superVar_Declarations.h will change the checksum and prevent the handshake from completing. 

#### 8.3.3 Controller Connectivity 
If the screen displays " Controller NOT Connected ": 
* Check USB: Ensure the Xbox 360 controller is firmly plugged into the GCS computer. 
* Re-Acquire: Use the actionRe_Acquire_Controller command (often mapped to a keyboard shortcut) to force the CXBOXController class to poll the USB bus for new devices. 

### 8.4 Maintenance Checklist 
To ensure the highest reliability, perform the following maintenance before each simulation session: 
* Clear Logs: Periodically delete the contents of the ProgramData folder to prevent log files from becoming excessively large. 
* Verify Retain Data: Check that retainData.stz is present in the executable directory to ensure your previous calibrations are loaded correctly. 
* Network Baseline: After establishing a stable connection, use the Communication Stats window to "Reset Ping Baseline," which calibrates the autopilot's sensitivity to network lag for that specific environment. 

## Chapter 9: Dual-Headed Simulation Setup 

### 9.1 Concept: Distributed Processing 
The "Dual-Headed" configuration is the most powerful way to easily demonstrate Pegasus Control with minimal hardware.
Only two computers are required to do this.  
In this setup: 
* Computer A (Controller PC): Acts as the GCS and Pilot Interface. 
* Computer B (Simulation PC): Acts as the virtual aircraft (Serving Helicopter). 

### 9.2 Step 1: Networking & IP Discovery 
Before configuring the software, both computers must be visible to each other on the local network. 
1. On Computer B (Simulation PC): Open the Communication Statistics window (Parameters > Statistics). 
2. Locate IP: Look at the Local IP Addresses box at the bottom. Identify the IPv4 address (e.g., 192.168.1.15). 
3. Connectivity Test: From Computer A, attempt to ping the IP of Computer B to ensure the firewall is not blocking ICMP/UDP traffic. 

### 9.3 Step 2: Configuring Computer A (The Controller) 
This machine is responsible for capturing the physical Xbox stick movements and transmitting the ZPack_XBoxControllerWord to the simulation. 
1. Set Identity: Open Parameters > Communication Settings. 
2. Role Selection: Set the What is this system? dropdown to Client Computer. 
3. Target Addressing: In the Address of Peer field, enter the IP address of Computer B. 
4. Packet Interval: Set the Joystick Xmit Max Speed (e.g., 20ms or 50ms). This determines how often the timer2 loop transmits control words. 
5. Enable Xmit: Ensure Pause All Data Xmit is unchecked. 

### 9.4 Step 3: Configuring Computer B (The Simulator) 
This machine receives the control words and processes the SimuHeli physics model. 
1. Set Identity: Open Parameters > Communication Settings. 
2. Role Selection: Set the What is this system? dropdown to Serving Helicopter. 
3. Point Back (Optional): Enter Computer A's IP in the Address of Peer field to ensure telemetry packets are routed back correctly. 
4. Initialize Graphics: Go to Main Display > Helicopter Simulation (Shortcut: Ctrl+S). The screen will transition to the 3D viewport and begin the animateSimulation() loop. 

### 9.5 Step 4: Variable Synchronization (The Handshake) 
The simulation on Computer B will remain "parked" until it receives a valid configuration state from Computer A. 
1. Initiate Sync: On Computer A, click Parameters > Re-Handshake With Aircraft. 
2. Monitor the State: The Event Log will show the transition through the 14-step handshake. The GCS will transmit all variables marked plsHandshk (like motor counts and PID gains) to the Simulator. 
3. Arming: Once the handshake reaches Step 10 (Steady State), Computer B will begin responding to the Xbox sticks. 

### 9.6 Performance Monitoring 
When running a dual-headed simulation, it is critical to monitor the health of the UDP link to prevent "fly-away" scenarios or visual stuttering. 
* Round Trip Time (RTT): Open the Statistics window on the Controller PC. Monitor the Average RTT. If it spikes above the Ping Baseline, the link is congested. 
* Packet Errors: Watch the CRC and Bad Length counters. If these climb, it usually indicates a software version mismatch between the two machines or electrical interference if using a wireless network. 
* Heartbeats: Computer B will automatically send a ZPack_HeartBeat if the link remains silent. On the Controller PC, ensure the heartbeat is being received to maintain the "Connected" status.