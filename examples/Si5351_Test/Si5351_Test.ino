/*
 * Simple Si5351 Test Sketch
 * 
 * This sketch tests basic Si5351 functionality
 * Outputs a fixed frequency on CLK0
 * 
 * Use this to verify your Si5351 module is working correctly
 */

#include <Wire.h>
#include <si5351.h>

Si5351 si5351;

// Test frequency: 7.000 MHz (7000000 Hz)
#define TEST_FREQUENCY 7000000ULL

// ESP01 I2C pins
#define SDA_PIN 0  // GPIO0
#define SCL_PIN 2  // GPIO2

void setup() {
  Serial.begin(115200);
  Serial.println("\nSi5351 Test Sketch");
  
  // Initialize I2C
  #ifdef ESP8266
    Wire.begin(SDA_PIN, SCL_PIN);
    Serial.println("ESP8266 mode - Using GPIO0 (SDA) and GPIO2 (SCL)");
  #else
    Wire.begin();
    Serial.println("Arduino mode - Using default I2C pins");
  #endif
  
  // Initialize Si5351
  Serial.println("Initializing Si5351...");
  bool i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);
  
  if (!i2c_found) {
    Serial.println("ERROR: Si5351 not found!");
    Serial.println("Check your wiring:");
    Serial.println("  VCC -> 3.3V");
    Serial.println("  GND -> GND");
    Serial.println("  SDA -> GPIO0 (ESP01) or A4 (Arduino)");
    Serial.println("  SCL -> GPIO2 (ESP01) or A5 (Arduino)");
    while (1);
  }
  
  Serial.println("Si5351 found!");
  
  // Set frequency
  Serial.print("Setting frequency to ");
  Serial.print(TEST_FREQUENCY);
  Serial.println(" Hz");
  
  si5351.set_freq(TEST_FREQUENCY * 100ULL, SI5351_CLK0);
  
  // Enable output
  si5351.output_enable(SI5351_CLK0, 1);
  
  Serial.println("Output enabled on CLK0");
  Serial.println("Use an oscilloscope or frequency counter to verify output");
  Serial.println("Test complete - output running continuously");
}

void loop() {
  // Nothing to do - just output the frequency
  delay(1000);
}
