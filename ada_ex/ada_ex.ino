
#include <Wire.h>
#include <Adafruit_MCP23X17.h>
Adafruit_MCP23X17 mcp;
int dly=300;

void setup() {
  Serial.begin(9600);
  Serial.println("MCP23017 Blink Test!");
  mcp.begin_I2C();
  for (int i=0; i<=15; i++){
    mcp.pinMode(i,OUTPUT);
  }

}

void loop() {
  for (int i=0; i<=15;i++){
   mcp.digitalWrite(i, HIGH);
   delay(dly);
   mcp.digitalWrite(i, LOW);
   delay(dly);
  }
}