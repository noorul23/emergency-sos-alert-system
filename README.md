# Women Safety Alert Device

A portable emergency alert system developed using ESP32, GPS, and GSM communication modules to transmit location-based distress notifications during emergency situations.

## Overview

The Women Safety Alert Device is an IoT-based safety system designed to provide a simple mechanism for initiating an emergency alert and communicating the user's location to predefined contacts.

The project was implemented through two approaches during development:

1. GSM and GPS based emergency alert implementation
2. Blynk-based IoT alert implementation for demonstration

The primary concept of the project is location-based emergency notification through an embedded hardware device.

---

## Objective

The objective was to develop a portable emergency alert device capable of transmitting a distress notification with location information when the emergency trigger is activated.

The concept can be applied to emergency assistance and personal safety scenarios.

---

## System Concept

The basic emergency workflow consists of:

1. Emergency button activation
2. Controller detection of the emergency input
3. Location acquisition through GPS
4. Preparation of the location-based alert
5. Transmission of the emergency notification through the communication system

---

## Implementation 1 — GPS + GSM

The first implementation used dedicated GPS and GSM communication modules.

### Main Components

- ESP32 / Arduino
- GPS module
- GSM / SIM module
- Push button

### Working Principle

When the emergency button is pressed, the controller initiates the emergency sequence.

The GPS module is used to obtain the location coordinates, which are then transmitted through the GSM module as an emergency notification.

### Prototype Status

The GPS and GSM implementation was developed as a hardware prototype.

During the demonstration, connectivity issues were encountered with the GPS and GSM modules. Therefore, the implementation was not demonstrated as a reliable end-to-end system during that presentation.

---

## Implementation 2 — Blynk IoT

A second implementation was developed using the Blynk IoT platform to demonstrate the emergency alert workflow independently of the GPS and GSM connectivity issues encountered in the first implementation.

### Main Components

- ESP32 / Arduino
- Push button
- Blynk IoT
- Blynk mobile application

### Working Principle

1. The emergency button is pressed.
2. The ESP32 detects the emergency input.
3. The alert event is transmitted through Blynk IoT.
4. The mobile application receives the emergency alert.

This implementation was used as an alternative demonstration of the emergency alert concept.

---

## Hardware Prototype

The project was implemented using a physical embedded hardware prototype.

Project images and implementation materials are included in the repository.

---

## Technologies Used

### Hardware

- ESP32
- GPS module
- GSM / SIM module
- Push button

### Software

- Embedded firmware
- Arduino IDE
- Blynk IoT
- Blynk mobile application

---

## Project Materials

The repository contains materials from the different implementation stages of the project, including:

- Firmware source code
- Hardware prototype images
- Implementation images
- Project documentation
- Presentation materials
- Project report

---

## Project Contribution

**Noorul Hassan**

- Embedded system development
- Hardware prototyping
- ESP32-based implementation
- GPS and GSM integration
- Emergency alert workflow development

**Muhammad Thahir**

- Collaborative project development
- Blynk-based implementation

---

## Limitations

- GPS and GSM connectivity can affect the reliability of the hardware implementation.
- The project was developed as an academic prototype.
- The system was not evaluated as a production-ready safety device.

---

## Future Improvements

Potential improvements include:

- Improved GPS and GSM connectivity
- Compact hardware enclosure
- Battery-powered portable implementation
- Improved emergency communication reliability
- Additional emergency contacts
- Mobile application integration
- Real-time location tracking

---

## License

This project is licensed under the MIT License.

---

## Contributors

- [Noorul Hassan](https://github.com/noorul23)
- [Muhammad Thahir](https://github.com/Thahir25)
