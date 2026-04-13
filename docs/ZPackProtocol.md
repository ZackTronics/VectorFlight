# Protocol Analysis: ZPack & SuperVar Handshaking

For intercontinental drone control, the primary enemies are **latency** (typically 200ms to 500ms round-trip) and **packet loss**. While MAVLink is the industry standard, the ZPack/SuperVar architecture provides a "State-Synchronization" model that is technically superior for unstable, high-latency links.

## 1. The ZPack Protocol: Packet Windowing

Unlike standard UDP-based telemetry which "fires and forgets," ZPack implements a **Sliding Window Protocol**. This is critical for intercontinental flight because it solves the *Long Fat Network* problem.

* **Asynchronous Flow:** The sender can transmit a "window" of multiple packets (e.g., packets 1 through 10) without waiting for an Acknowledgement (ACK) for packet 1.
* **Latency Masking:** If the Round Trip Time (RTT) is 400ms, a "Stop-and-Wait" protocol would only send one update every 0.4 seconds. ZPack keeps the pipe full, ensuring the drone receives a steady stream of commands despite the delay.
* **Selective Repeat:** If packet #3 is lost over the Atlantic, the receiver notifies the sender. The sender retransmits *only* #3 while the drone continues to process #4, #5, and #6. This prevents "Head-of-Line Blocking."

## 2. The SuperVar Handshake (`plsHandshk`)

The `plsHandshk` flag is the core of the system's reliability. It transforms a simple data transfer into a **Guaranteed State Sync**.

```c
// Logic from PleaseXmitChanges()
if (getFlags(x) & plsHandshk) {
    if (*Vars.Ptr_uint8[i] != Vars.Cached3_uint8[i]) {
        pushSuperVarWrite(x);
    }
}
```


This snippet demonstrates the system's Delta-Encoding and local caching mechanism. Instead of blindly broadcasting the entire configuration array across a saturated, high-latency connection, the architecture monitors the local memory pointers (Ptr_uint8). It only pushes a network write if the live value diverges from the cached value.<br>

Because it is bound by the plsHandshk flag, this guarantees that critical flight parameters—such as PID gains, motor geometry, and battery failsafe thresholds—are treated with highest priority and explicitly acknowledged by the target hardware.<br><br>
To prevent a drone from taking off with a mismatched configuration (e.g., the Ground Control Station thinks the altitude limit is 400ft, but the drone thinks it is 40ft), the ZPack protocol enforces a rigid 14-step handshake before motors can be armed.


## 3. 