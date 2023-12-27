#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1
int servo2Pin = 11; // PWM pin for servo2
int t1 = 80;
int t2 = 100;

String x;
String y;


void setup() {
  Serial.begin(9600); 
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  pinMode(3,OUTPUT);
}

void loop() {   // This works with the serial monitor giving inputs like 
    while(Serial.available()==0){
  }  // wait until there is something to read  input come separated by COMMA  ex 90,90
  x=Serial.readStringUntil(',');
  y=Serial.readStringUntil('\r');

  digitalWrite(3,HIGH);
  servo1.write(x.toInt());  
  servo2.write(y.toInt());

  Serial.print(" X value = ");
  Serial.println(x);
  Serial.print(" Y value = ");
  Serial.println(y);

  if (y.toInt()==0){   // turn off laser when you send 0,0
    digitalWrite(3,LOW);
  }              
    
  
}

