# 🚀 Smart Alert System (STM32 + Wokwi)

## 📌 Project Overview
This project is a smart alert system using STM32 simulation in Wokwi.

It detects:
- Distance using Ultrasonic Sensor
- Temperature condition (simulated)

Based on conditions:
- 🔴 Red LED + Buzzer → Alert (Danger / Chill)
- 🟢 Green LED → Safe

## ⚙️ Components Used
- STM32 (Wokwi)
- Ultrasonic Sensor (HC-SR04)
- Buzzer
- Red & Green LEDs
- OLED Display (SSD1306)

## 🧠 Features
- Real-time distance monitoring
- Temperature-based alert logic
- OLED display output
- Efficient memory-optimized code
- Smooth display (no flickering)

## 🌐 Live Simulation

👉 Click below to run the project:

🔗https://wokwi.com/projects/461262326223419393

## 🛠 How It Works

- Distance < 20 cm → 🚨 DANGER
- Temperature < 25°C → ❄️ CHILL
- Otherwise → ✅ SAFE

## 📸 Output

- OLED displays values and status
- LEDs indicate system condition
- Buzzer alerts on danger

## 📌 Note

Due to STM32 memory limitations, lightweight libraries are used.

---

