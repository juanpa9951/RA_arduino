#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

Servo servo3;  // Define servo1 object
Servo servo4;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1   Black
int servo2Pin = 11; // PWM pin for servo2    Blue

int servo3Pin = 5;  // PWM pin for servo3    Black
int servo4Pin = 6; // PWM pin for servo4     Blue


void setup() {
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  servo3.attach(servo3Pin); // Attach servo1 to its pin
  servo4.attach(servo4Pin); // Attach servo2 to its pin
  pinMode(13,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  // scale it for use with the servo (value between 0 and 180)
  digitalWrite(13,HIGH);
  digitalWrite(4,HIGH);
  
  servo1.write(90);
  servo3.write(90);
  servo2.write(90);
  servo4.write(90);
  delay(200);

  servo1.write(120);
  servo3.write(120);
  delay(200);
  servo1.write(60);
  servo3.write(60);
  delay(200);
  servo1.write(120);
  servo3.write(120);
  delay(200);
  servo1.write(60);
  servo3.write(60);
  delay(200);
  servo1.write(120);
  servo3.write(120);
  delay(200);
  servo1.write(60);
  servo3.write(60);

  servo1.write(90);
  servo3.write(90);
  servo2.write(90);
  servo4.write(90);
  delay(200);

  servo2.write(120);
  servo4.write(120);
  delay(200); 
  servo2.write(60);
  servo4.write(60);
  delay(200);  
  servo2.write(120);
  servo4.write(120);
  delay(200); 
  servo2.write(60);
  servo4.write(60);
  delay(200);
  servo2.write(120);
  servo4.write(120);
  delay(200); 
  servo2.write(60);
  servo4.write(60);     

  digitalWrite(13,LOW);
  digitalWrite(4,LOW);
}
