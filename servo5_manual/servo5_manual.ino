#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1  10
int servo2Pin = 11; // PWM pin for servo2   11

int t1 = 20;  //20
int t2 = 100;  //100

int total_pos;

String ch;
String qty_vertex;

String x1;
String x2;
String x3;
String x4;
String x5;
String x6;
String y1;
String y2;
String y3;
String y4;
String y5;
String y6;

String Xp4[]={x1,x2,x3,x4};
String Yp4[]={y1,y2,y3,y4};

String Xp5[]={x1,x2,x3,x4,x5};
String Yp5[]={y1,y2,y3,y4,y5};

String Xp6[]={x1,x2,x3,x4,x5,x6};
String Yp6[]={y1,y2,y3,y4,y5,y6};

void setup() {
  Serial.begin(9600);   // critical for serial monitor communication
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  pinMode(13,OUTPUT);
}

void loop() {
  while(Serial.available()==0){
  } // this while loop wait until there is a new command arriving in the serial port and then executes the code
  // this should work for receiving a string like this "1:2:3:4:5:6:7:8:9:10:11:12:13:14\r" from python serial
  qty_vertex=Serial.readStringUntil(':');
  total_pos=qty_vertex.toInt();

  if (total_pos==4){
      Serial.println("4 Edges"); 
      for (int position = 0; position < total_pos*2; position++) { // here we read the command from python and decompose it
        if (position < total_pos){  // check here.................  7 X-positions
          Xp4[position]=Serial.readStringUntil(':'); // 
        }else if (position < total_pos*2-1){ // check here.......................  7 Y-positions
          Yp4[position - total_pos]=Serial.readStringUntil(':');
        }else{
          Yp4[position - total_pos]=Serial.readStringUntil('\r'); // last part of the command from python, so the 7th Y-position 
        }
      }
      Serial.print(" X value = ");
      Serial.print(Xp4[0]);
      Serial.print("-"); 
      Serial.print(Xp4[1]);
      Serial.print("-"); 
      Serial.print(Xp4[2]);
      Serial.print("-");
      Serial.print(Xp4[3]);
      Serial.print("-");    
      Serial.print(" Y value = ");
      Serial.print(Yp4[0]);
      Serial.print("-");
      Serial.print(Yp4[1]);
      Serial.print("-"); 
      Serial.print(Yp4[2]);
      Serial.print("-");
      Serial.print(Yp4[3]);        
      // here we start the projection of the layer looping through the X and Y positions
      for (int position = 0; position < total_pos; position++) {
        digitalWrite(13,HIGH);
        servo1.write(Xp4[position].toInt());
        delay(t1);
        servo2.write(Yp4[position].toInt());  
        delay(t2);
      }
      ch=Serial.readStringUntil('\r');
      if (ch=="OFF"){
        servo1.write(90);
        servo2.write(90);
        digitalWrite(13,LOW);
        delay(100);
      }

  }else if (total_pos==5){
      Serial.println("5 Edges"); 
      for (int position = 0; position < total_pos*2; position++) { // here we read the command from python and decompose it
        if (position < total_pos){  // check here.................  7 X-positions
          Xp5[position]=Serial.readStringUntil(':'); // 
        }else if (position < total_pos*2-1){ // check here.......................  7 Y-positions
          Yp5[position - total_pos]=Serial.readStringUntil(':');
        }else{
          Yp5[position - total_pos]=Serial.readStringUntil('\r'); // last part of the command from python, so the 7th Y-position 
        }
      }
      Serial.print(" X value = ");
      Serial.print(Xp5[0]);
      Serial.print("-"); 
      Serial.print(Xp5[1]);
      Serial.print("-"); 
      Serial.print(Xp5[2]);
      Serial.print("-");
      Serial.print(Xp5[3]);
      Serial.print("-");
      Serial.print(Xp5[4]);
      Serial.print("-");    
      Serial.print(" Y value = ");
      Serial.print(Yp5[0]);
      Serial.print("-");
      Serial.print(Yp5[1]);
      Serial.print("-"); 
      Serial.print(Yp5[2]);
      Serial.print("-");
      Serial.print(Yp5[3]);
      Serial.print("-");
      Serial.print(Yp5[4]); 
      // here we start the projection of the layer looping through the X and Y positions
      for (int position = 0; position < total_pos; position++) {
        digitalWrite(13,HIGH);
        servo1.write(Xp5[position].toInt());
        delay(t1);
        servo2.write(Yp5[position].toInt());  
        delay(t2);
      }
      ch=Serial.readStringUntil('\r');
      if (ch=="OFF"){
        servo1.write(90);
        servo2.write(90);
        digitalWrite(13,LOW);
        delay(100);
      }  

  }else if (total_pos==6){
      Serial.println("6 Edges"); 
      for (int position = 0; position < total_pos*2; position++) { // here we read the command from python and decompose it
        if (position < total_pos){  // check here.................  7 X-positions
          Xp6[position]=Serial.readStringUntil(':'); // 
        }else if (position < total_pos*2-1){ // check here.......................  7 Y-positions
          Yp6[position - total_pos]=Serial.readStringUntil(':');
        }else{
          Yp6[position - total_pos]=Serial.readStringUntil('\r'); // last part of the command from python, so the 7th Y-position 
        }
      }
      Serial.print(" X value = ");
      Serial.print(Xp6[0]);
      Serial.print("-"); 
      Serial.print(Xp6[1]);
      Serial.print("-"); 
      Serial.print(Xp6[2]);
      Serial.print("-");
      Serial.print(Xp6[3]);
      Serial.print("-");
      Serial.print(Xp6[4]);
      Serial.print("-"); 
      Serial.print(Xp6[5]);
      Serial.print("-");    
      Serial.print(" Y value = ");
      Serial.print(Yp6[0]);
      Serial.print("-");
      Serial.print(Yp6[1]);
      Serial.print("-"); 
      Serial.print(Yp6[2]);
      Serial.print("-");
      Serial.print(Yp6[3]);
      Serial.print("-");
      Serial.print(Yp6[4]);
      Serial.print("-");
      Serial.print(Xp6[5]);
  
      // here we start the projection of the layer looping through the X and Y positions
      for (int position = 0; position < total_pos; position++) {
        digitalWrite(13,HIGH);
        servo1.write(Xp6[position].toInt());
        delay(t1);
        servo2.write(Yp6[position].toInt());  
        delay(t2);
      }
      ch=Serial.readStringUntil('\r');
      if (ch=="OFF"){
        servo1.write(90);
        servo2.write(90);
        digitalWrite(13,LOW);
        delay(100);
      }  

  }
}