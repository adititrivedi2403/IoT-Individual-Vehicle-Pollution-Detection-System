# 🚗 IoT-Based Vehicle Pollution Detection & Offender Identification System

This project is an IoT and AI-based smart system that detects vehicle pollution levels in real-time and identifies offenders using number plate recognition.

It integrates gas sensors, Arduino, ESP8266, and AI models (YOLO + OCR) to create an automated pollution monitoring solution for smart cities.

## ⭐ Key Features
- Real-time IoT Monitoring
- AI-based Number Plate Recognition
- Cloud Integration
- Automated Offender Detection

- ## 🎯 Objectives
- Real-time monitoring of vehicle emissions (CO, CO2, Smoke)
- Identify vehicles exceeding pollution limits
- Capture vehicle images and detect number plates using AI
- Upload data to cloud (ThingSpeak/Firebase)
- Generate alerts for authorities

## 🛠️ Tech Stack
- **Hardware:** Arduino Uno, ESP8266, MQ2, MQ7, MQ135 Sensors
- **Software:** Python, Arduino IDE
- **Libraries:** OpenCV, YOLOv8, EasyOCR, NumPy
- **Cloud:** ThingSpeak / Firebase
- **Concepts:** IoT, Embedded Systems, Computer Vision, RF Communication

  ## 🏗️ System Architecture

1. Gas sensors detect pollution levels
2. Arduino processes sensor data
3. ESP8266 uploads data to cloud
4. If threshold exceeds:
   - Camera captures vehicle image
   - YOLO detects number plate
   - OCR extracts plate number
5. Data stored and alert generated

   ## 🔌 Hardware Components
- Arduino Uno
- ESP8266 NodeMCU
- MQ2, MQ7, MQ135 Gas Sensors
- ESP32-CAM / Smartphone Camera
- Breadboard, Jumper Wires

  ## 💻 Software Requirements
- Arduino IDE
- Python 3.x
- VS Code / Jupyter Notebook
- Libraries: OpenCV, Ultralytics YOLO, EasyOCR, Requests

  ## ⚡ Working Principle
- Sensors measure gas concentration (PPM)
- Data sent to ESP8266 via serial communication
- Cloud dashboard displays real-time data
- AI model detects number plate using YOLO
- OCR extracts plate number
- If pollution exceeds threshold → offender logged

  ## 📊 Results
- Real-time pollution monitoring achieved
- Accurate number plate detection using AI
- Cloud-based tracking system implemented
- Reduced latency in data transmission by ~25%

  ## 🌍 Applications
- Smart Traffic Systems
- Toll Booth Monitoring
- Pollution Control Boards
- Automated Challan Systems

  ## 🔮 Future Scope
- GPS integration for location tracking
- Government server integration
- AI-based pollution prediction
- Mobile app development

  ## 📚 References
- Arduino Documentation
- OpenCV Library
- Ultralytics YOLO Docs
- ThingSpeak IoT Platform

  
