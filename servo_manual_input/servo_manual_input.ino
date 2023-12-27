#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

Servo servo3;  // Define servo1 object
Servo servo4;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1   Black
int servo2Pin = 11; // PWM pin for servo2    Blue

int servo3Pin = 5;  // PWM pin for servo3    Black
int servo4Pin = 6; // PWM pin for servo4     Blue

int t1 = 80;
int t2 = 100;

String x;
String y;

String x2;
String y2;


void setup() {
  Serial.begin(9600);   // CRITICAL FOR USING THE SERIAL MONITOR AS INPUT
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  servo3.attach(servo3Pin); // Attach servo1 to its pin
  servo4.attach(servo4Pin); // Attach servo2 to its pin
  pinMode(13,OUTPUT);
}

void loop() {   // This works with the serial monitor giving inputs like 90,90,90,90
    while(Serial.available()==0){
  }  // wait until there is something to read  input come separated by COMMA  ex 90,90
  x=Serial.readStringUntil(',');
  y=Serial.readStringUntil(',');
  x2=Serial.readStringUntil(',');
  y2=Serial.readStringUntil('\r');

  digitalWrite(13,HIGH);
  servo1.write(x.toInt());  
  servo2.write(y.toInt());
  servo3.write(x2.toInt());  
  servo4.write(y2.toInt());

  Serial.print(" X value = ");
  Serial.println(x);
  Serial.print(" Y value = ");
  Serial.println(y);
  Serial.print(" X2 value = ");
  Serial.println(x2);
  Serial.print(" Y2 value = ");
  Serial.println(y2); 

  if (y2.toInt()==0){   // turn off laser when you send 0,0,0,0
    digitalWrite(13,LOW);
  }              
    
  
}

