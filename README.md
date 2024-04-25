# Embedded Real-Time LED System

This Arduino project is a real-time embedded systems that utilizes the Arduino FreeRTOS to create a robust LED control and management system. Designed for multitasking, this system allows for concurrent control of multiple LEDs and input handling, demonstrating an efficient use of FreeRTOS capabilities such as tasks, queues, and semaphores.

## Project Overview

The project is divided into multiple task files, each representing specific functionalities using FreeRTOS. Tasks manage LED blinking patterns, respond to serial input to adjust LED brightness, and handle system resets via an interrupt-triggered button press. The system is designed to showcase real-time multitasking in embedded systems.

### Features

- **LED Control:** Toggle LED states between on and off with specific delays.
- **Brightness Adjustment:** Adjust LED brightness based on serial input parsing.
- **System Reset:** Reset functionality through a hardware button to clear queues and reset task states.

### Hardware Requirements

- **Arduino Board** (Uno, Mega, etc.)
- **LEDs**
- **Push Button**
- **Resistors** for LEDs
- **Wires and Breadboard**

### Software Requirements

- Arduino IDE
- Arduino_FreeRTOS library
- Additional libraries: `queue.h`, `semphr.h`

## Getting Started

### Setup

1. Assemble your hardware.
2. Install the Arduino IDE and the necessary libraries.
3. Upload the code to your Arduino board.

### Usage

- **Operation:** The system operates automatically once powered, with tasks running concurrently as per their design.
- **Serial Commands:** Send commands through the Arduino's Serial Monitor to adjust parameters like LED brightness.
- **Button Interaction:** Press the designated button to trigger system-wide resets.

## Structure

The project is structured into several task files, each encapsulating specific functionalities:

- **Task Files for LED Operations:** Handle on/off states and brightness control.
- **Interrupt Service Routines:** Manage asynchronous events like button presses.
- **Utility Tasks:** Perform background operations such as monitoring or adjusting settings.

## Image of the arduino used in the project
<img width="670" alt="image" src="https://github.com/mohamadd10/LED-Control-and-Management-System/assets/119814738/eda0c95d-abf0-47fd-a33b-67173d37ca1b">

