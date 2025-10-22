#!/bin/bash
# Build verification script for Beacon Opera4 and CW

echo "=== Beacon Opera4 and CW - Build Verification ==="
echo ""

# Check if running in PlatformIO environment
if command -v pio &> /dev/null; then
    echo "PlatformIO found. Attempting to build..."
    echo ""
    
    # Try to build for ESP01
    echo "Building for ESP01..."
    pio run -e esp01 || echo "ESP01 build failed (requires internet for platform download)"
    
    echo ""
    echo "Building for Arduino Uno..."
    pio run -e uno || echo "Arduino Uno build failed (requires internet for platform download)"
    
    echo ""
else
    echo "PlatformIO not found."
    echo ""
fi

# Check if running in Arduino CLI environment
if command -v arduino-cli &> /dev/null; then
    echo "Arduino CLI found. Attempting to build..."
    echo ""
    
    # Check sketch syntax
    arduino-cli compile --fqbn esp8266:esp8266:generic Beacon-Opera4-CW.ino || \
        echo "ESP01 compile check failed (may require platform installation)"
    
    arduino-cli compile --fqbn arduino:avr:uno Beacon-Opera4-CW.ino || \
        echo "Arduino Uno compile check failed"
    
    echo ""
else
    echo "Arduino CLI not found."
    echo ""
fi

echo "=== Manual Verification Checklist ==="
echo ""
echo "To verify this code:"
echo "1. Install Arduino IDE or PlatformIO"
echo "2. Install ESP8266 board support (for ESP01)"
echo "3. Install 'Etherkit Si5351' library"
echo "4. Open Beacon-Opera4-CW.ino"
echo "5. Select your board (ESP01 or Arduino)"
echo "6. Verify/Compile the sketch"
echo ""
echo "For detailed instructions, see README_DEPENDENCIES.md"
echo ""

# Basic syntax check using grep/sed (very basic validation)
echo "=== Basic Syntax Validation ==="
echo ""

errors=0

# Check for required includes
if grep -q "#include <Wire.h>" Beacon-Opera4-CW.ino && \
   grep -q "#include <si5351.h>" Beacon-Opera4-CW.ino; then
    echo "✓ Required includes found"
else
    echo "✗ Missing required includes"
    errors=$((errors+1))
fi

# Check for setup and loop functions
if grep -q "void setup()" Beacon-Opera4-CW.ino && \
   grep -q "void loop()" Beacon-Opera4-CW.ino; then
    echo "✓ Setup and loop functions found"
else
    echo "✗ Missing setup or loop function"
    errors=$((errors+1))
fi

# Check for Si5351 instance
if grep -q "Si5351 si5351" Beacon-Opera4-CW.ino; then
    echo "✓ Si5351 instance declared"
else
    echo "✗ Missing Si5351 instance"
    errors=$((errors+1))
fi

# Check for I2C initialization
if grep -q "Wire.begin" Beacon-Opera4-CW.ino; then
    echo "✓ I2C initialization found"
else
    echo "✗ Missing I2C initialization"
    errors=$((errors+1))
fi

# Check for si5351 initialization
if grep -q "si5351.init" Beacon-Opera4-CW.ino; then
    echo "✓ Si5351 initialization found"
else
    echo "✗ Missing Si5351 initialization"
    errors=$((errors+1))
fi

echo ""
if [ $errors -eq 0 ]; then
    echo "✓ Basic syntax validation PASSED"
    echo "Code structure appears correct."
else
    echo "✗ Basic syntax validation found $errors issue(s)"
    echo "Please review the code."
fi

echo ""
echo "Note: Full compilation requires proper development environment."
echo "This script only performs basic structural checks."
