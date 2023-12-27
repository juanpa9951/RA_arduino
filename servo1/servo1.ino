#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1
int servo2Pin = 11; // PWM pin for servo2
int t1 = 80;
int t2 = 100;

void setup() {
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  pinMode(3,OUTPUT);
}

void loop() {
  // scale it for use with the servo (value between 0 and 180)
  digitalWrite(3,HIGH);
  servo1.write(60);
  delay(t1);
  servo2.write(60);  
  delay(t2);
  servo1.write(110);
  delay(t1);
  servo2.write(60);    
  delay(t2);
  servo1.write(110);
  delay(t1);
  servo2.write(110);    
  delay(t2);
  servo1.write(60);
  delay(t1);
  servo2.write(110);    
  delay(t2);
  digitalWrite(3,LOW);  
      
}
