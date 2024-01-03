#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

Servo servo3;  // Define servo3 object
Servo servo4;  // Define servo4 object

int servo1Pin = 10;  // PWM pin for servo1   Black
int servo2Pin = 11; // PWM pin for servo2    Blue

int servo3Pin = 5;  // PWM pin for servo3    Black
int servo4Pin = 6; // PWM pin for servo4     Blue


int X=A0;   //ANALOG INPUT A0
int Y=A1;   //ANALOG INPUT A1
int PosX;
int PosY;
int Xs;
int Ys;
int Xp=90; // DEFINE WITH INITIAL STATE
int Yp=90; // DEFINE WITH INITIAL STATE

int Selector = 2;  // 1--> servo1     2---> servo2


void setup() {      // this code works with the JOYSTICK and the serial prompt
  Serial.begin(9600); 
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  servo3.attach(servo3Pin); // Attach servo1 to its pin
  servo4.attach(servo4Pin); // Attach servo2 to its pin
  pinMode(13,OUTPUT);
  pinMode(X,INPUT);
  pinMode(Y,INPUT);
  digitalWrite(13,LOW);  // FORCE INITIAL STATE TO TURN OFF THE LED
}

void loop() {
  PosX=analogRead(X)*180./1023.;
  PosY=analogRead(Y)*180./1023.;
  
  if (Selector==1){    // servo 1 tuning
     Xs=PosX;   // this to check if direction of movement complies, other wise to 180-Posx
     Ys=180-PosY; // this to check if direction of movement complies, other wise to 180-Posy
  

    //digitalWrite(13,HIGH);
    
    if (Xs>100){
      digitalWrite(13,HIGH);
      Xp=Xp+1;
      servo2.write(Xp);
      Serial.print(" X value = ");
      Serial.println(Yp);
      Serial.print(" Y value = ");
      Serial.println(Xp);    
    }

    if (Ys>100){
      digitalWrite(13,HIGH);
      Yp=Yp+1;
      servo1.write(Yp);
      Serial.print(" X value = ");
      Serial.println(Yp);    
      Serial.print(" Y value = ");
      Serial.println(Xp);
    }

    if (Xs<80){
      digitalWrite(13,HIGH);
      Xp=Xp-1;
      servo2.write(Xp);
      Serial.print(" X value = ");
      Serial.println(Yp);
      Serial.print(" Y value = ");
      Serial.println(Xp);    
    }

    if (Ys<80){
      digitalWrite(13,HIGH);
      Yp=Yp-1;
      servo1.write(Yp);
      Serial.print(" X value = ");
      Serial.println(Yp);    
      Serial.print(" Y value = ");
      Serial.println(Xp);
    }  
    delay(100);
  }


  else{   // servo 2 tuning
     Xs=180-PosX;   // this to check if direction of movement complies, other wise to 180-Posx
     Ys=PosY; // this to check if direction of movement complies, other wise to 180-Posy
  

    // digitalWrite(13,HIGH);
    
    if (Xs>100){
      digitalWrite(13,HIGH);
      Xp=Xp+1;
      servo4.write(Xp);
      Serial.print(" X value = ");
      Serial.println(Yp);
      Serial.print(" Y value = ");
      Serial.println(Xp);    
    }

    if (Ys>100){
      digitalWrite(13,HIGH);
      Yp=Yp+1;
      servo3.write(Yp);
      Serial.print(" X value = ");
      Serial.println(Yp);    
      Serial.print(" Y value = ");
      Serial.println(Xp);
    }

    if (Xs<80){
      digitalWrite(13,HIGH);
      Xp=Xp-1;
      servo4.write(Xp);
      Serial.print(" X value = ");
      Serial.println(Yp);
      Serial.print(" Y value = ");
      Serial.println(Xp);    
    }

    if (Ys<80){
      digitalWrite(13,HIGH);
      Yp=Yp-1;
      servo3.write(Yp);
      Serial.print(" X value = ");
      Serial.println(Yp);    
      Serial.print(" Y value = ");
      Serial.println(Xp);
    }  
    delay(100);

  }
}


