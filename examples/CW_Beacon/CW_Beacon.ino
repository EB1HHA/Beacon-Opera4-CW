/*
 * CW Beacon Example
 * 
 * Simple CW (Morse Code) beacon that transmits a callsign
 * 
 * Modify CALLSIGN and FREQUENCY to your needs
 */

#include <Wire.h>
#include <si5351.h>

Si5351 si5351;

// Configuration
#define CALLSIGN "EB1HHA"
#define FREQUENCY 7030000ULL  // 7.030 MHz
#define CW_SPEED 20           // WPM (words per minute)

// Calculate timings from WPM
#define DOT_TIME (1200 / CW_SPEED)
#define DASH_TIME (DOT_TIME * 3)
#define ELEMENT_SPACE DOT_TIME
#define LETTER_SPACE (DOT_TIME * 3)
#define WORD_SPACE (DOT_TIME * 7)

// ESP01 pins
#define SDA_PIN 0
#define SCL_PIN 2

// Morse code table (A-Z, 0-9)
const char* morse[] = {
  ".-", "-...", "-.-.", "-..", ".",           // A-E
  "..-.", "--.", "....", "..", ".---",        // F-J
  "-.-", ".-..", "--", "-.", "---",           // K-O
  ".--.", "--.-", ".-.", "...", "-",          // P-T
  "..-", "...-", ".--", "-..-", "-.--", "--..", // U-Z
  "-----", ".----", "..---", "...--", "....-",   // 0-4
  ".....", "-....", "--...", "---..", "----."    // 5-9
};

void setup() {
  Serial.begin(115200);
  Serial.println("\nCW Beacon");
  Serial.print("Callsign: ");
  Serial.println(CALLSIGN);
  Serial.print("Frequency: ");
  Serial.print(FREQUENCY);
  Serial.println(" Hz");
  Serial.print("Speed: ");
  Serial.print(CW_SPEED);
  Serial.println(" WPM");
  
  #ifdef ESP8266
    Wire.begin(SDA_PIN, SCL_PIN);
  #else
    Wire.begin();
  #endif
  
  if (!si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0)) {
    Serial.println("Si5351 not found!");
    while (1);
  }
  
  si5351.set_freq(FREQUENCY * 100ULL, SI5351_CLK0);
  Serial.println("Ready!");
}

void loop() {
  Serial.print("Transmitting: ");
  Serial.println(CALLSIGN);
  sendMessage(CALLSIGN);
  
  Serial.println("Waiting 60 seconds...");
  delay(60000);  // Wait 1 minute between transmissions
}

void sendMessage(const char* msg) {
  for (int i = 0; msg[i] != '\0'; i++) {
    char c = msg[i];
    
    if (c == ' ') {
      delay(WORD_SPACE);
    } else {
      sendChar(c);
      delay(LETTER_SPACE);
    }
  }
}

void sendChar(char c) {
  // Convert to uppercase
  if (c >= 'a' && c <= 'z') {
    c = c - 'a' + 'A';
  }
  
  // Get morse code
  const char* code;
  if (c >= 'A' && c <= 'Z') {
    code = morse[c - 'A'];
  } else if (c >= '0' && c <= '9') {
    code = morse[26 + (c - '0')];
  } else {
    return;  // Unknown character
  }
  
  // Send morse code
  Serial.print(c);
  Serial.print(" (");
  Serial.print(code);
  Serial.print(") ");
  
  for (int i = 0; code[i] != '\0'; i++) {
    if (code[i] == '.') {
      sendDot();
    } else if (code[i] == '-') {
      sendDash();
    }
    delay(ELEMENT_SPACE);
  }
  Serial.println();
}

void sendDot() {
  si5351.output_enable(SI5351_CLK0, 1);
  delay(DOT_TIME);
  si5351.output_enable(SI5351_CLK0, 0);
}

void sendDash() {
  si5351.output_enable(SI5351_CLK0, 1);
  delay(DASH_TIME);
  si5351.output_enable(SI5351_CLK0, 0);
}
