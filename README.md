# 🚨 Emergency SOS Alert System

Emergency SOS Alert System is a simple IoT-based safety device designed to send an emergency alert when a button is pressed.

The project demonstrates two different implementations of the same concept:

• GSM + GPS based emergency alert system  
• Blynk IoT mobile alert system

---

# 🎯 Objective

The goal of this project is to design a simple emergency alert device that allows a user to quickly notify trusted contacts during dangerous situations.

Potential use cases include:

• Personal safety
• Women safety systems
• Emergency assistance devices
• Elderly monitoring

---

# ⚙️ Version 1 — GSM + GPS Alert System

This version uses hardware communication modules to send alerts.

### Components

• ESP32 / Arduino  
• SIM module  
• GPS module  
• Push button  

### Working

1. User presses emergency button
2. GPS retrieves location
3. SIM module sends SMS with location coordinates
4. Emergency contact receives alert message

⚠️ During demonstration, the SIM and GPS modules faced connectivity issues, so this version remained as a prototype implementation.

---

# 📱 Version 2 — Blynk IoT Alert System

To ensure reliable demonstration, the system was reimplemented using Blynk IoT.

### Components

• ESP32 / Arduino  
• Push button  
• Blynk mobile application  

### Working

1. User presses emergency button
2. ESP32 sends signal to Blynk cloud
3. Mobile application receives alert notification

This version provided a stable and functional demonstration of the emergency alert concept.

---

# 📂 Repository Structure

```
version1_gsm_gps
   firmware
   images

version2_blynk
   firmware
   images
   docs
```

---

# 🔧 Hardware Prototype

Images of the hardware prototype are available in the repository.

---

# 👥 Contributors

This project was developed collaboratively.

- **[Noorul Hassan](https://github.com/noorul23)**  
- **[Muhammad Thahir](https://github.com/Thahir25)**  



---

## License
This project is licensed under->[MIT License](https://github.com/noorul23/emergency-sos-alert-system/blob/main/LICENSE), please check it out before using this resource.

---

If you find this project useful, feel free to ⭐ the repository!
