# Changelog

All notable changes to this project will be documented in this file.

## [1.0.0] - 2024-10-22

### Added
- Initial release of Beacon Opera4 and CW
- Main beacon sketch with Opera4 and CW mode support
- Si5351 oscillator integration via I2C
- ESP01 and Arduino compatibility
- Configuration file (config.h) for easy customization
- PlatformIO support with platformio.ini
- Examples:
  - Si5351_Test: Basic Si5351 functionality test
  - CW_Beacon: Simple CW beacon with Morse code
- Documentation:
  - Comprehensive README in Spanish with English sections
  - README_DEPENDENCIES.md: Library installation guide
  - QUICK_START.md: Quick start guide in Spanish and English
  - AMPLIFIER_FILTER.md: Optional amplifier and filter designs
  - circuit_diagram.txt: Hardware connection diagrams
- GPL v3 License

### Features
- Opera4 mode with 4-FSK modulation (16 symbols)
- CW mode with configurable Morse code transmission
- I2C communication with Si5351 (SDA=GPIO0, SCL=GPIO2 for ESP01)
- Frequency range: 8 kHz - 160 MHz
- Serial debugging at 115200 baud
- Configurable transmission intervals
- Support for multiple ham radio bands (40m, 30m, 20m)

### Hardware Support
- ESP01 (ESP8266)
- Arduino Uno
- Arduino Nano
- Any Arduino-compatible board with I2C

### Dependencies
- Etherkit Si5351 library v2.1.4 or later
- Wire library (included with Arduino)

## [Future Enhancements]

### Planned Features
- Opera4 message encoding with callsign and locator
- WSPR mode support
- Web interface for configuration (ESP01)
- EEPROM storage for settings
- Multiple frequency scheduling
- Temperature compensation
- GPS time synchronization
- Power management for battery operation
- Automatic band switching
- Telemetry transmission
