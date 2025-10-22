# Dependencies and Libraries

## Required Libraries

To compile this project, you need to install the following Arduino libraries:

### 1. Si5351 Library
- **Name**: Etherkit Si5351
- **Author**: Jason Milldrum (NT7S)
- **Version**: 2.1.4 or later
- **Installation**: 
  - Arduino IDE: Tools -> Manage Libraries -> Search "Si5351" -> Install "Etherkit Si5351"
  - PlatformIO: Add to platformio.ini: `lib_deps = etherkit/Etherkit Si5351@^2.1.4`
  - GitHub: https://github.com/etherkit/Si5351Arduino

### 2. Wire Library
- **Name**: Wire (I2C communication)
- **Included**: This is a standard Arduino library, included by default
- **No installation needed**

## Platform Support

### ESP8266 (ESP01)
- **Board Manager URL**: http://arduino.esp8266.com/stable/package_esp8266com_index.json
- **Board**: Generic ESP8266 Module or ESP-01
- **Installation**:
  1. File -> Preferences -> Additional Boards Manager URLs
  2. Add the URL above
  3. Tools -> Board -> Boards Manager -> Search "ESP8266" -> Install

### Arduino (Uno, Nano, etc.)
- Standard Arduino boards are supported
- Use hardware I2C pins (A4=SDA, A5=SCL on Uno/Nano)
- Modify the code to use standard Wire.begin() without pin parameters

## Installation Steps

### Using Arduino IDE:

1. Install Arduino IDE from https://www.arduino.cc/en/software

2. Add ESP8266 board support (for ESP01):
   - File -> Preferences
   - Add board manager URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json
   - Tools -> Board -> Boards Manager
   - Search for "ESP8266" and install

3. Install Si5351 library:
   - Tools -> Manage Libraries
   - Search for "Si5351"
   - Install "Etherkit Si5351" by Jason Milldrum

4. Select your board:
   - Tools -> Board -> ESP8266 Boards -> Generic ESP8266 Module (for ESP01)
   - Tools -> Board -> Arduino AVR Boards -> Arduino Uno (for Arduino)

5. Open Beacon-Opera4-CW.ino and upload

### Using PlatformIO:

Create a `platformio.ini` file with:

```ini
[env:esp01]
platform = espressif8266
board = esp01_1m
framework = arduino
lib_deps = 
    etherkit/Etherkit Si5351@^2.1.4

[env:uno]
platform = atmelavr
board = uno
framework = arduino
lib_deps = 
    etherkit/Etherkit Si5351@^2.1.4
```

## Compilation

### For ESP01:
- Board: Generic ESP8266 Module
- Flash Size: 1M (no SPIFFS)
- Upload Speed: 115200

### For Arduino Uno/Nano:
- Board: Arduino Uno or Arduino Nano
- Processor: ATmega328P (Uno) or ATmega328P (Old Bootloader) for some Nano clones

## Troubleshooting

### "Si5351 not found" error:
1. Check wiring connections
2. Verify 3.3V power supply
3. Add 4.7kΩ pull-up resistors on SDA and SCL lines
4. Check I2C address (default is 0x60 for Si5351)

### Compilation errors:
1. Ensure Si5351 library is installed
2. Check board selection matches your hardware
3. Update to latest library versions

### Upload errors on ESP01:
1. GPIO0 must be pulled LOW during upload (boot mode)
2. After upload, GPIO0 returns to normal operation (I2C SDA)
3. Use a USB-to-Serial adapter with 3.3V logic levels
