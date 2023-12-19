#include "Wire.h"

// EACH MCP23017 WILL REQUIRE 2 COMMAND STRINGS, 1 for side GPIO-A and 1 for GPIO-B
String cmd1; // first part of command string
String cmd2; // 2nd part of command string
String cmd3; // 3rd part of command string
String cmd4; // 4th part of command string

void setup() {
  // put your setup code here, to run once:
 Wire.begin(); // wake up I2C bus
// set I/O pins to outputs
// this code block would have to exist for each MCP23017
 Wire.beginTransmission(0x20); // ADDRESS OF MCP23017
 Wire.write(0x00); // GPIO-A register
 Wire.write(0x00); // set all of port A to outputs
 Wire.endTransmission();
 Wire.beginTransmission(0x20); // ADDRESS OF MCP23017
 Wire.write(0x01); // GPIO-B register
 Wire.write(0x00); // set all of port B to outputs
 Wire.endTransmission();

 Wire.beginTransmission(0x27); // ADDRESS OF MCP23017
 Wire.write(0x00); // GPIO-A register
 Wire.write(0x00); // set all of port A to outputs
 Wire.endTransmission();
 Wire.beginTransmission(0x27); // ADDRESS OF MCP23017
 Wire.write(0x01); // GPIO-B register
 Wire.write(0x00); // set all of port B to outputs
 Wire.endTransmission();

 Serial.begin(115200); 

}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0){
} // this while loop wait until there is a new command arriving in the serial port and then executes the code
// for each MCP23017 there will be twice as much commands strings (1 for side A, 1 for side B)
cmd1=Serial.readStringUntil(':');  // BINARY COMMAND FOR THE GPIO-A of 1st MCP
cmd2=Serial.readStringUntil(':');  // BINARY COMMAND FOR THE GPIO-B of 1st MCP, they come separated by :
cmd3=Serial.readStringUntil(':');  // BINARY COMMAND FOR THE GPIO-A of 2nd MCP, they come separated by :
cmd4=Serial.readStringUntil('\r'); // BINARY COMMAND FOR THE GPIO-B of 2nd MCP, the last always comes before \r

// this code block will have to exist  for each MCP23017 with their respective address 
 Wire.beginTransmission(0x20); // ADDRESS OF MCP23017
 Wire.write(0x12); // GPIO-A  (SIDE A)
 Wire.write(cmd1.toInt());  //  command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 Wire.beginTransmission(0x20); // ADDRESS OF MCP23017
 Wire.write(0x13); // GPIO-B  (SIDE B)
 Wire.write(cmd2.toInt()); //  command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();

 Wire.beginTransmission(0x27); // ADDRESS OF MCP23017
 Wire.write(0x12); // GPIO-A  (SIDE A)
 Wire.write(cmd3.toInt());  //  command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission();
 Wire.beginTransmission(0x27); // ADDRESS OF MCP23017
 Wire.write(0x13); // GPIO-B  (SIDE B)
 Wire.write(cmd4.toInt()); //  command in INTEGER converted from a binary number of 8 bytes (1-on, 0-off)
 Wire.endTransmission(); 
 
}
