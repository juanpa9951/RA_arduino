/*
 Example 41.1 - Microchip MCP23017 with Arduino
*/
// pins 15~17 to GND, I2C bus address is 0x20
#include "Wire.h"

void setup()
{
 Wire.begin(); // wake up I2C bus
// set I/O pins to outputs
 Wire.beginTransmission(0x20); //address of 1st MCP23017
 Wire.write(0x00); // IO-DIR-A register
 Wire.write(0x00); // set all of port A to outputs
 Wire.endTransmission();
 Wire.beginTransmission(0x20);
 Wire.write(0x01); // IO-DIR-B register
 Wire.write(0x00); // set all of port B to outputs
 Wire.endTransmission();


 Wire.beginTransmission(0x27);  //address of 2nd MCP23017
 Wire.write(0x00); // IO-DIR-A register
 Wire.write(0x00); // set all of port A to outputs
 Wire.endTransmission();
 Wire.beginTransmission(0x27);
 Wire.write(0x01); // IO-DIR-B register
 Wire.write(0x00); // set all of port B to outputs
 Wire.endTransmission();
}

void loop()
{
 Wire.beginTransmission(0x20); //address of 1st MCP23017
 Wire.write(0x12); // GPIO-A
 Wire.write(1);  // command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 delay(1000);
 Wire.beginTransmission(0x20); //address of 1st MCP23017
 Wire.write(0x12); // GPIO-A
 Wire.write(0); //  command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 delay(1000);

 Wire.beginTransmission(0x27); //address of 2nd MCP23017
 Wire.write(0x12); // GPIO-A
 Wire.write(128);  // command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 delay(1000);
 Wire.beginTransmission(0x27);
 Wire.write(0x12); // GPIO-A
 Wire.write(0); //  command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 delay(1000);


 Wire.beginTransmission(0x27); //address of 2nd MCP23017
 Wire.write(0x12); // GPIO-A
 Wire.write(8);  // command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 delay(1000);
 Wire.beginTransmission(0x27);
 Wire.write(0x12); // GPIO-A
 Wire.write(0); //  command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 delay(1000);

}