# 🏋️‍♂️ IoT Scale with OLED Display

This is an ESP32-based project that reads weight values from 4 load cells using HX711 modules and displays the results on a 128x32 OLED screen.

## 📷 Features

- ✅ Reads real-time data from **4 load cells** (via `HX711`)
- ✅ Displays weight values on an **SSD1306 OLED (128x32)**
- ✅ Initializes via I2C using **custom SDA/SCL pins**
- ✅ Easily expandable to include WiFi connectivity (code included but commented)

## 🔧 Hardware

- Arduino board (e.g., ESP32, ESP8266, Uno with software I2C)
- 4 × Load cells
- 4 × HX711 amplifiers
- 128x32 OLED screen (I2C, address `0x3C`)
- Wires and breadboard

## 📦 Dependencies

Make sure the following libraries are installed in your Arduino IDE:

- [`Adafruit_GFX`](https://github.com/adafruit/Adafruit-GFX-Library)
- [`Adafruit_SSD1306`](https://github.com/adafruit/Adafruit_SSD1306)
- `Wire` and `SPI` (included with Arduino)
- `WiFi.h` (for ESP32/ESP8266 boards)
- Custom `weight.h` for HX711 initialization and reading

## 🧠 Pin Configuration

| Component | Arduino Pin |
|----------|-------------|
| OLED SDA | Pin 8       |
| OLED SCL | Pin 9       |
| HX711 pins | Defined in `weight.h` |

> ⚠️ Adjust `OLED_SDA_PIN` and `OLED_SCK_PIN` based on your board.

## 🚀 How It Works (simulated on Wokwi)
https://wokwi.com/projects/413735976441723905
