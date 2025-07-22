# Latching-power-circuit
A low-power latching circuit using Arduino, a push button and a sensor to turn on and off automatically 

# Arduino Latching Circuit Project

This project demonstrates a self-latching power control system using an Arduino, a P-Channel MOSFET, an NPN transistor, and a relay. It allows the Arduino to fully power ON through a button or motion, and automatically shut OFF to save power.

## Features

- **Button & Tilt Switch on Same Pin**: A single input pin is used for both a push button and a tilt switch.
  - **Short press / movement**: Powers ON the Arduino.
  - **Long press (3 seconds)**: Turns OFF the Arduino.
- **Latching Power**: The circuit uses a MOSFET and/or NPN transistor to latch power to the Arduino.
- **Auto Shutoff**: A relay disconnects power after a timeout or long button press.
- **RGB Module**: An RGB LED module is used for visual testing and status indication.

## Components Used

- Arduino Uno
- P-Channel MOSFET
- NPN Transistor (e.g., 2N2222)
- Relay Module (SRD-03VDC-SL-C)
- Push Button
- Tilt Switch (Ball Type)
- RGB LED Module (for testing)
- Resistors (as needed)

## How It Works

1. **Power ON**:
   - Pressing the button or detecting a tilt triggers the NPN transistor and powers the Arduino via the MOSFET.

2. **Operation**:
   - The Arduino monitors the shared pin (button + tilt switch).
   - If the input is HIGH for 3 seconds, the Arduino cuts its own power using the relay.
   - Otherwise, it stays ON for 10 seconds (if triggered by movement).

3. **Power OFF**:
   - After the timeout or long button press, the Arduino activates the relay to cut its own power.

## Pin Connections

| Component                    | Arduino Pin |
|-----------------------------|-------------|
| Button + Tilt Switch (shared)| D4          |
| Relay Module                | D3          |
| NPN Transistor (base)       | D2          |
| RGB Module (P1)             | D6, D7, D8  |

*Power control through the MOSFET and relay is wired externally.*

## Usage

- Great for low-power projects, like motion-triggered systems or smart battery-operated devices.
- Simplified wiring using a shared input pin for both user and motion activation.
- RGB LED module is used for testing and feedback.

## License

This project is open-source and free to use for personal and educational purposes.
