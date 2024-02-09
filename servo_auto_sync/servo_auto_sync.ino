#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

Servo servo3;  // Define servo1 object
Servo servo4;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1   Black
int servo2Pin = 11; // PWM pin for servo2    Blue

int servo3Pin = 5;  // PWM pin for servo3    Black
int servo4Pin = 6; // PWM pin for servo4     Blue

int t1 = 180;    //80
int t2 = 180;   //100

void setup() {
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  servo3.attach(servo3Pin); // Attach servo1 to its pin
  servo4.attach(servo4Pin); // Attach servo2 to its pin
  pinMode(13,OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // scale it for use with the servo (value between 0 and 180)

  digitalWrite(13,HIGH);
  servo1.write(49);
  servo3.write(99);
  delay(t1);
  servo2.write(57);
  servo4.write(130);  
  delay(t2);
  servo1.write(47);
  servo3.write(101);
  delay(t1);
  servo2.write(128);
  servo4.write(60);    
  delay(t2);
  servo1.write(95);
  servo3.write(59);
  delay(t1);
  servo2.write(128);
  servo4.write(58);    
  delay(t2);
  servo1.write(95);
  servo3.write(55);
  delay(t1);
  servo2.write(57);
  servo4.write(123);    
  delay(t2);
  digitalWrite(13,LOW);
}
