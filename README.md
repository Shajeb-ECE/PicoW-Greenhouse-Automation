# Greenhouse Monitoring System

An advanced greenhouse monitoring project designed for real-time environmental data acquisition and automated system control.

## Project Overview
This project leverages the **Raspberry Pi Pico W** to monitor critical agricultural parameters. By integrating multiple sensors, the system provides real-time telemetry and triggers an irrigation relay based on soil moisture thresholds.

## Technical Stack
- **Hardware:** Raspberry Pi Pico W, DHT22 (Temp/Humidity), Photoresistor, Potentiometers (Soil/Water level), Relay Module.
- **Simulation:** [Wokwi Simulator](https://wokwi.com/)
- **Firmware:** C++ (Arduino Framework)

## Circuit Diagram
The circuit configuration is defined in `diagram.json`, optimized for the Raspberry Pi Pico W analog and digital I/O pins.

## Simulation & Deployment
1. Import this repository into VS Code with the Wokwi extension.
2. Ensure the `pico.uf2` binary is loaded.
3. Execute the simulation to view real-time data in the terminal.


## Component Breakdown & Sensor Usage

| Component | Function | Use Case in this Project |
| :--- | :--- | :--- |
| **DHT22** | Temperature & Humidity Sensor | Monitors the greenhouse atmosphere to ensure optimal plant growth conditions. |
| **Photoresistor (LDR)** | Light Intensity Sensor | Detects ambient light levels to determine if artificial lighting (LEDs) is required. |
| **Soil Moisture Potentiometer** | Variable Resistance Sensor | Simulates a soil moisture probe to trigger the irrigation relay when levels drop below a critical threshold. |
| **Water Level Potentiometer** | Variable Resistance Sensor | Simulates tank volume monitoring, providing real-time data to prevent pump dry-running. |
| **Relay Module** | Electromagnetic Switch | Acts as the actuator that controls the irrigation system (or other high-voltage devices) based on sensor logic. |
| **NeoPixel (WS2812B)** | Addressable RGB LED | Provides visual status indicators for system activity and light automation. |
