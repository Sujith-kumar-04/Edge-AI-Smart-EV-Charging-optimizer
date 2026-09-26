# Edge AI Based Smart EV Charging Station Optimizer

## Overview

This project presents an Edge AI based Smart EV Charging Station Optimizer designed to improve the management and optimization of electric vehicle charging.

The system uses an ESP32-based platform to monitor charging-station parameters, process data locally, and make intelligent charging decisions at the edge.

## Key Features

- Edge AI based decision making
- Smart EV charging optimization
- Real-time telemetry and monitoring
- Charging state management
- Network communication
- ESP32-based implementation
- Modular software architecture

## Project Structure

- `src/` – Main source code
- `include/` – Header files
- `lib/` – Project libraries
- `test/` – Test files
- `platformio.ini` – PlatformIO configuration

## Main Components

The `src` directory contains modules for:

- Edge AI processing
- Charging optimization
- State management
- Network communication
- Telemetry
- Peripherals
- Configuration

## Hardware and Software

**Hardware:** ESP32-based development platform

**Development Environment:** PlatformIO

**Programming Language:** C/C++

## Project Status

This project is being developed as an internship project focused on Edge AI and intelligent EV charging station optimization.

## Future Improvements

- Improved charging optimization algorithms
- Additional real-time monitoring
- More advanced Edge AI models
- Performance evaluation with real charging data
- Integration with multiple charging stations

- ## Testing and Validation

The project was tested using the Wokwi ESP32 simulator and ThingsBoard Cloud.

### Test 1 – Normal Charging

- ESP32 simulation executed successfully
- Normal charging operation verified
- Telemetry sent to ThingsBoard Cloud
- Cloud data verified successfully

### Test 2 – Overcurrent Protection

- Overcurrent condition simulated
- System detected the overcurrent condition
- Charging throttle was set to 50%
- Overload protection verified successfully

### Optimization Features

The charging optimizer includes:

- Normal charging control
- Overcurrent protection
- Station power-cap management
- Peak-hour decision logic
- Predicted EV arrival consideration
- Relay and charging throttle control
- ThingsBoard Cloud telemetry

### Simulation

The ESP32-based system was tested using the Wokwi simulator.

### Cloud Monitoring

Charging and telemetry data are sent to ThingsBoard Cloud for monitoring and verification.

### Project Status

The current implementation demonstrates an Edge AI-based smart EV charging optimization system using ESP32, Wokwi simulation, and ThingsBoard Cloud.
