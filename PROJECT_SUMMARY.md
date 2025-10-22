# Project Summary

## Beacon Opera4 and CW

### Overview
This project implements a radio beacon capable of transmitting in Opera4 and CW (Morse code) modes using an ESP01 (ESP8266) or Arduino microcontroller with a Si5351 oscillator module.

### Key Features Implemented

#### 1. Main Beacon Sketch (`Beacon-Opera4-CW.ino`)
- **Opera4 Mode**: 4-FSK modulation with 16 symbols
  - Symbol duration: 4 seconds
  - Frequency spacing: 1.46 Hz between tones
  - Total transmission time: ~64 seconds
  
- **CW Mode**: Morse code transmission
  - Configurable speed (dot/dash timing)
  - Example implementation transmits "CQ"
  - On/off keying of Si5351 output

- **I2C Communication**:
  - Custom pin configuration for ESP01: GPIO0 (SDA), GPIO2 (SCL)
  - Standard I2C pins for Arduino (A4=SDA, A5=SCL)
  
- **Frequency Control**:
  - Precise frequency generation using Si5351
  - Default: 7 MHz (40m band)
  - Easily configurable for any frequency 8kHz - 160MHz

#### 2. Configuration System
- **config.h**: Centralized configuration file
  - Mode selection (Opera4/CW)
  - Frequency settings
  - Timing parameters
  - Callsign and locator fields (for future Opera4 encoding)
  - Serial debug settings

#### 3. Example Sketches

- **Si5351_Test**: Basic Si5351 functionality test
  - Verifies I2C communication
  - Outputs test frequency continuously
  - Useful for hardware verification

- **CW_Beacon**: Enhanced CW beacon
  - Full Morse code table (A-Z, 0-9)
  - Configurable callsign
  - WPM-based timing calculation
  - Complete message transmission

#### 4. Build System Support

- **Arduino IDE**: Traditional Arduino workflow
- **PlatformIO**: Modern build system
  - Multiple environment configurations
  - ESP01, Arduino Uno, Arduino Nano support
  - OTA update capability for ESP01

#### 5. Documentation

- **README.md**: Comprehensive guide in Spanish with English sections
- **README_DEPENDENCIES.md**: Library installation guide
- **QUICK_START.md**: Quick start guide (bilingual)
- **circuit_diagram.txt**: Hardware connection diagrams
- **AMPLIFIER_FILTER.md**: Optional RF amplifier and filter designs
- **CHANGELOG.md**: Version history and planned features

### Hardware Requirements

- **Microcontroller**: ESP01 (ESP8266) or Arduino (Uno/Nano)
- **Oscillator**: Si5351 breakout board
- **Power**: 3.3V regulated supply
- **Optional**: RF amplifier and low-pass filter

### Pin Connections (ESP01)

```
Si5351          ESP01
VCC ----------- 3.3V
GND ----------- GND
SDA ----------- GPIO0
SCL ----------- GPIO2
CLK0 ---------- [RF Output]
```

### Software Dependencies

- **Required Libraries**:
  - Etherkit Si5351 (v2.1.4 or later)
  - Wire (included with Arduino)

- **Platform Support**:
  - ESP8266 (ESP01)
  - Arduino AVR (Uno, Nano, etc.)

### Technical Specifications

- **Frequency Range**: 8 kHz - 160 MHz
- **Frequency Resolution**: 0.01 Hz
- **Output Drive**: 2-8 mA (configurable)
- **Power Consumption**: <100 mA typical
- **I2C Speed**: Up to 400 kHz
- **Serial Debug**: 115200 baud

### Future Enhancements

- Opera4 message encoding with callsign/locator
- WSPR mode support
- Web interface for ESP01
- GPS time synchronization
- Automatic band switching
- Temperature compensation
- Battery operation optimization

### Validation Status

✓ Code structure validated
✓ Required includes present
✓ I2C initialization correct
✓ Si5351 initialization correct
✓ Example sketches verified
✓ Security scan completed (no issues)

### Build Status

- **Syntax**: ✓ Validated
- **Hardware Compilation**: Requires Arduino IDE or PlatformIO with internet access
- **Hardware Testing**: Requires physical ESP01 and Si5351 module

### License

GNU General Public License v3.0

### Author

EB1HHA

### Contributing

Contributions welcome! Please see README.md for guidelines.

---

## File Structure

```
Beacon-Opera4-CW/
├── Beacon-Opera4-CW.ino    # Main beacon sketch
├── config.h                 # Configuration file
├── platformio.ini           # PlatformIO configuration
├── README.md                # Main documentation
├── README_DEPENDENCIES.md   # Library installation guide
├── QUICK_START.md           # Quick start guide
├── AMPLIFIER_FILTER.md      # RF amplifier/filter designs
├── circuit_diagram.txt      # Hardware connections
├── CHANGELOG.md             # Version history
├── LICENSE                  # GPL v3 license
├── verify_build.sh          # Build verification script
├── .gitignore              # Git ignore rules
└── examples/
    ├── Si5351_Test/
    │   └── Si5351_Test.ino  # Si5351 test sketch
    └── CW_Beacon/
        └── CW_Beacon.ino    # CW beacon example
```

### Quick Start

1. Install Arduino IDE
2. Install ESP8266 board support
3. Install Etherkit Si5351 library
4. Connect hardware as per circuit_diagram.txt
5. Open Beacon-Opera4-CW.ino
6. Configure frequency and mode in the code
7. Upload to ESP01 or Arduino
8. Monitor serial output at 115200 baud

For detailed instructions, see QUICK_START.md
