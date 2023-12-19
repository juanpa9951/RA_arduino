#include "Wire.h"

int L1=9;    // here we need to declare all the LEDS with their corresponding pin
int L2=8;
int L3=6;
int L4=7; 
int L5=4;
int L6=3;
int L7=5; 
int L8=2;
int LEDS[]={L1,L2,L3,L4,L5,L6,L7,L8}; // create a list with all the LEDS
int ledCount=8; // specify how many leds there are
String cmd1; // first part of command string
String cmd2; // 2nd part of command string
String cmd3; // 3rd part of command string
String cmd4; // x part of command string
String cmd5; // x part of command string
String cmd6; // x part of command string
String cmd7; // x part of command string
String cmd8; // last part command string
String CMD[]={cmd1,cmd2,cmd3,cmd4,cmd5,cmd6,cmd7,cmd8}; // create a list with all the command parts

// in Arduino the indexes start with 0, like in python, keep that in mind for all the "for" looping ahead

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);   // start the serial monitor for comunication with python
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {     // define all the leds as outputs
    pinMode(LEDS[thisLed], OUTPUT);
  }
Wire.begin(); // wake up I2C bus
// set I/O pins to outputs
Wire.beginTransmission(0x20);
Wire.write(0x00); // IO-DIR-A register
Wire.write(0x00); // set all of port A to outputs
Wire.endTransmission();
Wire.beginTransmission(0x20);
Wire.write(0x01); // IO-DIR-B register
Wire.write(0x00); // set all of port B to outputs
Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0){
} // this while loop wait until there is a new command arriving in the serial port and then executes the code


  for (int thisLed = 0; thisLed < ledCount; thisLed++) { // here we read the command from python and decompose it
    if (thisLed<ledCount-1){
      CMD[thisLed]=Serial.readStringUntil(':'); // 
    }else{
      CMD[thisLed]=Serial.readStringUntil('\r'); // last part of the command from python 
    }
  }
  
  for (int thisCmd = 0; thisCmd < ledCount; thisCmd++) {   // loop through the command parts from python
    for (int thisLed2 = 1; thisLed2 < ledCount+1; thisLed2++){  // loop through all possible LEDS
      if (CMD[thisCmd]==String(thisLed2)){
        digitalWrite(LEDS[thisLed2-1],HIGH);
      }

    if (CMD[thisCmd]=="9"){
      Wire.beginTransmission(0x20);
      Wire.write(0x12); // GPIO-A
      Wire.write(00000001);  // command in binary for the 8 positions (1-on, 0-off)
      Wire.endTransmission();
  
      Wire.beginTransmission(0x20);
      Wire.write(0x13); // GPIO-B
      Wire.write(10000000);  // command in binary for the 8 positions (1-on, 0-off)
      Wire.endTransmission();
    
    }

    }

  }

  if (CMD[ledCount-1]=="OFF"){   // the turn off command for all the leds comes always in the last position
    for (int thisLed = 0; thisLed < ledCount; thisLed++){   // loop through all possible LEDS
      digitalWrite(LEDS[thisLed],LOW);

    }
    Wire.beginTransmission(0x20);
    Wire.write(0x12); // GPIO-A
    Wire.write(00000000); //  command in binary for the 8 positions (1-on, 0-off)
    Wire.endTransmission();
    Wire.beginTransmission(0x20);
    Wire.write(0x13); // GPIO-B
    Wire.write(00000000); //  command in binary for the 8 positions (1-on, 0-off)
    Wire.endTransmission();
  }
}