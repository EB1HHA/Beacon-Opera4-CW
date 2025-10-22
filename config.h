/*
 * Configuration File for Beacon Opera4 and CW
 * 
 * Copy this file and customize according to your needs
 */

#ifndef CONFIG_H
#define CONFIG_H

// ============================================
// BEACON MODE SELECTION
// ============================================
// Select one: BEACON_MODE_OPERA4 or BEACON_MODE_CW
#define DEFAULT_MODE        BEACON_MODE_OPERA4

// ============================================
// FREQUENCY CONFIGURATION
// ============================================
// Default frequency in Hz
// Examples:
// 7000000ULL  = 7 MHz (40m band)
// 10140000ULL = 10.14 MHz (30m band)
// 14000000ULL = 14 MHz (20m band)
#define BEACON_FREQUENCY    7000000ULL

// ============================================
// OPERA4 CONFIGURATION
// ============================================
// Symbol duration in milliseconds (standard is 4000ms)
#define OPERA4_SYMBOL_DURATION  4000

// Number of symbols in Opera4 message (standard is 16)
#define OPERA4_NUM_SYMBOLS      16

// Frequency spacing between tones in centi-Hz (146 = 1.46 Hz)
#define OPERA4_TONE_SPACING     146

// ============================================
// CW CONFIGURATION
// ============================================
// CW speed settings (in milliseconds)
// Slower: increase values, Faster: decrease values
#define CW_DOT_LENGTH           100   // Duration of a dot
#define CW_DASH_LENGTH          300   // Duration of a dash (3x dot)
#define CW_ELEMENT_GAP          100   // Gap between dots/dashes
#define CW_LETTER_GAP           300   // Gap between letters
#define CW_WORD_GAP             700   // Gap between words

// CW message to transmit
// Edit this string to change the CW message
#define CW_MESSAGE              "CQ DE EB1HHA"

// ============================================
// TIMING CONFIGURATION
// ============================================
// Time between transmissions in milliseconds
#define TX_INTERVAL             60000  // 60 seconds (1 minute)

// ============================================
// I2C CONFIGURATION
// ============================================
#ifdef ESP8266
  // ESP01 I2C pins
  #define I2C_SDA_PIN           0      // GPIO0
  #define I2C_SCL_PIN           2      // GPIO2
#else
  // Arduino uses default I2C pins (A4=SDA, A5=SCL on Uno/Nano)
  // No need to define pins for Arduino
#endif

// ============================================
// Si5351 CONFIGURATION
// ============================================
// Crystal load capacitance
// Options: SI5351_CRYSTAL_LOAD_6PF, SI5351_CRYSTAL_LOAD_8PF, 
//          SI5351_CRYSTAL_LOAD_10PF
#define SI5351_CRYSTAL_LOAD     SI5351_CRYSTAL_LOAD_8PF

// Output clock to use (CLK0, CLK1, or CLK2)
#define SI5351_OUTPUT_CLK       SI5351_CLK0

// Drive strength: 2mA, 4mA, 6mA, or 8mA
// Options: SI5351_DRIVE_2MA, SI5351_DRIVE_4MA, 
//          SI5351_DRIVE_6MA, SI5351_DRIVE_8MA
#define SI5351_DRIVE_STRENGTH   SI5351_DRIVE_8MA

// ============================================
// SERIAL DEBUG CONFIGURATION
// ============================================
// Enable/disable serial debugging
#define DEBUG_ENABLED           true

// Serial baud rate
#define SERIAL_BAUD_RATE        115200

// ============================================
// CALLSIGN AND LOCATOR
// ============================================
// Your callsign (for future Opera4 encoding)
#define CALLSIGN                "EB1HHA"

// Maidenhead locator (for future Opera4 encoding)
#define LOCATOR                 "IN52"

#endif // CONFIG_H
