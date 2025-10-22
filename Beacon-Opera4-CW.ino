/*
 * Beacon Opera4 and CW
 * 
 * Beacon for Opera4 and CW modes using ESP01 or Arduino with Si5351 oscillator
 * 
 * Hardware connections:
 * Si5351          ESP01
 * VCC ----------- 3.3V
 * GND ----------- GND
 * SDA ----------- GPIO0
 * SCL ----------- GPIO2
 * 
 * Author: EB1HHA
 * License: GPL v3
 */

#include <Wire.h>
#include <si5351.h>

// Si5351 instance
Si5351 si5351;

// Configuration
#define BEACON_MODE_OPERA4  0
#define BEACON_MODE_CW      1

// Default frequency in Hz (7 MHz for 40m band)
#define DEFAULT_FREQUENCY   7000000ULL

// Current mode
uint8_t beaconMode = BEACON_MODE_OPERA4;
unsigned long long frequency = DEFAULT_FREQUENCY;

// Opera4 timing (in milliseconds)
#define OPERA4_SYMBOL_TIME  4000  // 4 seconds per symbol
#define OPERA4_MESSAGE_LENGTH 16   // 16 symbols per message

// CW timing (in milliseconds)
#define CW_DOT_TIME         100    // Duration of a dot
#define CW_DASH_TIME        300    // Duration of a dash
#define CW_ELEMENT_SPACE    100    // Space between dots and dashes
#define CW_LETTER_SPACE     300    // Space between letters
#define CW_WORD_SPACE       700    // Space between words

// ESP01 I2C pins
#define SDA_PIN 0  // GPIO0
#define SCL_PIN 2  // GPIO2

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  Serial.println("\nBeacon Opera4 and CW");
  Serial.println("Initializing...");
  
  // Initialize I2C on custom pins for ESP01
  #ifdef ESP8266
    Wire.begin(SDA_PIN, SCL_PIN);
  #else
    Wire.begin();
  #endif
  
  // Initialize Si5351
  bool i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  
  if (!i2c_found) {
    Serial.println("Si5351 not found! Check wiring.");
    while (1);  // Halt
  }
  
  Serial.println("Si5351 initialized successfully");
  
  // Set initial frequency
  setFrequency(frequency);
  
  // Enable output
  si5351.output_enable(SI5351_CLK0, 1);
  
  Serial.print("Mode: ");
  Serial.println(beaconMode == BEACON_MODE_OPERA4 ? "Opera4" : "CW");
  Serial.print("Frequency: ");
  Serial.print(frequency);
  Serial.println(" Hz");
  Serial.println("Beacon ready!");
}

void loop() {
  if (beaconMode == BEACON_MODE_OPERA4) {
    transmitOpera4();
  } else {
    transmitCW();
  }
  
  // Wait between transmissions
  delay(60000);  // 1 minute
}

void setFrequency(unsigned long long freq) {
  // Set frequency on CLK0 output
  si5351.set_freq(freq * 100ULL, SI5351_CLK0);
  frequency = freq;
}

void transmitOpera4() {
  Serial.println("Transmitting Opera4...");
  
  // Opera4 message - 16 symbols
  // This is a simple pattern; in a real implementation,
  // you would encode callsign and locator
  uint8_t opera4_symbols[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
  
  for (int i = 0; i < OPERA4_MESSAGE_LENGTH; i++) {
    // Opera4 uses 4-FSK modulation with 4 tones
    // Each symbol shifts frequency by ~1.46 Hz
    unsigned long long symbolFreq = frequency + (opera4_symbols[i] * 146ULL / 100ULL);
    
    setFrequency(symbolFreq);
    Serial.print("Symbol ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(opera4_symbols[i]);
    
    delay(OPERA4_SYMBOL_TIME);
  }
  
  // Return to base frequency
  setFrequency(frequency);
  Serial.println("Opera4 transmission complete");
}

void transmitCW() {
  Serial.println("Transmitting CW...");
  
  // Example: Send "CQ" in Morse code
  // C: -.-. 
  // Q: --.-
  
  // C
  sendDash();
  sendDot();
  sendDash();
  sendDot();
  letterSpace();
  
  // Q
  sendDash();
  sendDash();
  sendDot();
  sendDash();
  
  Serial.println("CW transmission complete");
}

void sendDot() {
  si5351.output_enable(SI5351_CLK0, 1);
  delay(CW_DOT_TIME);
  si5351.output_enable(SI5351_CLK0, 0);
  delay(CW_ELEMENT_SPACE);
}

void sendDash() {
  si5351.output_enable(SI5351_CLK0, 1);
  delay(CW_DASH_TIME);
  si5351.output_enable(SI5351_CLK0, 0);
  delay(CW_ELEMENT_SPACE);
}

void letterSpace() {
  delay(CW_LETTER_SPACE);
}

void wordSpace() {
  delay(CW_WORD_SPACE);
}
