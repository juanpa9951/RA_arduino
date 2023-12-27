#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1
int servo2Pin = 11; // PWM pin for servo2
int X=A0;
int Y=A1;
int PosX;
int PosY;
int Xs;
int Ys;
int Xp=90;
int Yp=90;

void setup() {      // this code works with the JOYSTICK and the serial prompt
  Serial.begin(9600); 
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  pinMode(3,OUTPUT);
  pinMode(X,INPUT);
  pinMode(Y,INPUT);
}

void loop() {
  PosX=analogRead(X)*180./1023.;
  PosY=analogRead(Y)*180./1023.;

  Xs=PosX;   // this to check if direction of movement complies, other wise to 180-Posx
  Ys=180-PosY; // this to check if direction of movement complies, other wise to 180-Posy
  digitalWrite(3,HIGH);
  
  if (Xs>100){
    Xp=Xp+1;
    servo2.write(Xp);
    Serial.print(" X value = ");
    Serial.println(Yp);
    Serial.print(" Y value = ");
    Serial.println(Xp);    
  }

  if (Ys>100){
    Yp=Yp+1;
    servo1.write(Yp);
    Serial.print(" X value = ");
    Serial.println(Yp);    
    Serial.print(" Y value = ");
    Serial.println(Xp);
  }

  if (Xs<80){
    Xp=Xp-1;
    servo2.write(Xp);
    Serial.print(" X value = ");
    Serial.println(Yp);
    Serial.print(" Y value = ");
    Serial.println(Xp);    
  }

  if (Ys<80){
    Yp=Yp-1;
    servo1.write(Yp);
    Serial.print(" X value = ");
    Serial.println(Yp);    
    Serial.print(" Y value = ");
    Serial.println(Xp);
  }  
  delay(100);
}


