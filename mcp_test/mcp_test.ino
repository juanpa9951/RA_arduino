// Blinks an LED attached to a MCP23XXX pin.

// ok to include only the one needed
// both included here to make things simple for example
#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>

#define LED_PIN 2     // MCP23XXX pin LED is attached to

// only used for SPI
#define CS_PIN 6

// uncomment appropriate line
//Adafruit_MCP23X08 mcp;
Adafruit_MCP23X17 mcp;

void setup() {
  Serial.begin(9600);
  //while (!Serial);
  Serial.println("MCP23017 Blink Test!");
  
  mcp.begin_I2C();
  // uncomment appropriate mcp.begin  
  if (!mcp.begin_I2C()) {
  //if (!mcp.begin_SPI(CS_PIN)) {
    Serial.println("Error mcp");
    while (1);
  }

  // configure pin for output
  mcp.pinMode(LED_PIN, OUTPUT);

  Serial.println("Looping...");
}

void loop() {
  mcp.digitalWrite(LED_PIN, HIGH);
  delay(500);
  mcp.digitalWrite(LED_PIN, LOW);
  delay(500);
}