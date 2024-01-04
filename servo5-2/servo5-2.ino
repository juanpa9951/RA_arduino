#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

Servo servo3;  // Define servo1 object
Servo servo4;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1   Black
int servo2Pin = 11; // PWM pin for servo2    Blue

int servo3Pin = 5;  // PWM pin for servo3    Black
int servo4Pin = 6; // PWM pin for servo4     Blue

int t1 = 20;  //20
int t2 = 100;  //100

int total_pos;

int Laser=13;

String ch;
String qty_vertex;

String x1;
String x2;
String x3;
String x4;
String x5;
String x6;
String x7;
String x8;
String x9;
String x10;
String x11;
String x12;
String y1;
String y2;
String y3;
String y4;
String y5;
String y6;
String y7;
String y8;
String y9;
String y10;
String y11;
String y12;

String Xp4[]={x1,x2,x3,x4};
String Yp4[]={y1,y2,y3,y4};
String Xp4_2[]={x5,x6,x7,x8};
String Yp4_2[]={y5,y6,y7,y8};

String Xp5[]={x1,x2,x3,x4,x5};
String Yp5[]={y1,y2,y3,y4,y5};
String Xp5_2[]={x6,x7,x8,x9,x10};
String Yp5_2[]={y6,y7,y8,y9,y10};

String Xp6[]={x1,x2,x3,x4,x5,x6};
String Yp6[]={y1,y2,y3,y4,y5,y6};
String Xp6_2[]={x7,x8,x9,x10,x11,x12};
String Yp6_2[]={y7,y8,y9,y10,y11,y12};

void setup() {
  Serial.begin(115200);   // critical for python communication
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  servo3.attach(servo3Pin); // Attach servo1 to its pin
  servo4.attach(servo4Pin); // Attach servo2 to its pin
  pinMode(Laser,OUTPUT);
}

void loop() {
  while(Serial.available()==0){
  } // this while loop wait until there is a new command arriving in the serial port and then executes the code
  // this should work for receiving a string like this "1:2:3:4:5:6:7:8:9:10:11:12:13:14\r" from python serial
  qty_vertex=Serial.readStringUntil(':');
  total_pos=qty_vertex.toInt();

  if (total_pos==4){

      for (int position = 0; position < total_pos*4; position++) { // here we read the command from python and decompose it
        if (position < total_pos){  // check here.................   X-positions servo 1
          Xp4[position]=Serial.readStringUntil(':'); // 
        }else if (position< total_pos*2){
          Yp4[position - total_pos]=Serial.readStringUntil(':'); // check here.....   Y-positions servo 1
        }else if (position< total_pos*3){
          Xp4_2[position - total_pos*2]=Serial.readStringUntil(':'); // check here.....   X-positions servo 2
        }else if (position < total_pos*4-1){ // check here.......................   Y-positions servo 2
          Yp4_2[position - total_pos*3]=Serial.readStringUntil(':');
        }else{
          Yp4_2[position - total_pos*3]=Serial.readStringUntil('\r'); // last part of the command from python, so the last Y-position servo 2
        }
      }
      // here we start the projection of the layer looping through the X and Y positions
      for (int position = 0; position < total_pos; position++) {
        digitalWrite(Laser,HIGH);
        servo1.write(Xp4[position].toInt());
        servo3.write(Xp4_2[position].toInt());
        delay(t1);
        servo2.write(Yp4[position].toInt()); 
        servo4.write(Yp4_2[position].toInt());  
        delay(t2);
      }
      ch=Serial.readStringUntil('\r');
      if (ch=="OFF"){
        servo1.write(90);
        servo2.write(90);
        servo3.write(90);
        servo4.write(90);        
        digitalWrite(Laser,LOW);
        delay(100);
      }
      Serial.flush();

  }else if (total_pos==5){
      
      for (int position = 0; position < total_pos*4; position++) { // here we read the command from python and decompose it
        if (position < total_pos){  // check here.................   X-positions servo 1
          Xp5[position]=Serial.readStringUntil(':'); // 
        }else if (position< total_pos*2){
          Yp5[position - total_pos]=Serial.readStringUntil(':'); // check here.....   Y-positions servo 1
        }else if (position< total_pos*3){
          Xp5_2[position - total_pos*2]=Serial.readStringUntil(':'); // check here.....   X-positions servo 2
        }else if (position < total_pos*4-1){ // check here.......................   Y-positions servo 2
          Yp5_2[position - total_pos*3]=Serial.readStringUntil(':');
        }else{
          Yp5_2[position - total_pos*3]=Serial.readStringUntil('\r'); // last part of the command from python, so the last Y-position servo 2
        }
      }
      // here we start the projection of the layer looping through the X and Y positions
      for (int position = 0; position < total_pos; position++) {
        digitalWrite(Laser,HIGH);
        servo1.write(Xp5[position].toInt());
        servo3.write(Xp5_2[position].toInt());
        delay(t1);
        servo2.write(Yp5[position].toInt()); 
        servo4.write(Yp5_2[position].toInt());  
        delay(t2);
      }
      ch=Serial.readStringUntil('\r');
      if (ch=="OFF"){
        servo1.write(90);
        servo2.write(90);
        servo3.write(90);
        servo4.write(90);           
        digitalWrite(Laser,LOW);
        delay(100);
      }
      Serial.flush();

  }else if (total_pos==6){

      for (int position = 0; position < total_pos*4; position++) { // here we read the command from python and decompose it
        if (position < total_pos){  // check here.................   X-positions servo 1
          Xp6[position]=Serial.readStringUntil(':'); // 
        }else if (position< total_pos*2){
          Yp6[position - total_pos]=Serial.readStringUntil(':'); // check here.....   Y-positions servo 1
        }else if (position< total_pos*3){
          Xp6_2[position - total_pos*2]=Serial.readStringUntil(':'); // check here.....   X-positions servo 2
        }else if (position < total_pos*4-1){ // check here.......................   Y-positions servo 2
          Yp6_2[position - total_pos*3]=Serial.readStringUntil(':');
        }else{
          Yp6_2[position - total_pos*3]=Serial.readStringUntil('\r'); // last part of the command from python, so the last Y-position servo 2
        }
      }
      // here we start the projection of the layer looping through the X and Y positions
      for (int position = 0; position < total_pos; position++) {
        digitalWrite(Laser,HIGH);
        servo1.write(Xp6[position].toInt());
        servo3.write(Xp6_2[position].toInt());
        delay(t1);
        servo2.write(Yp6[position].toInt()); 
        servo4.write(Yp6_2[position].toInt());  
        delay(t2);
      }
      ch=Serial.readStringUntil('\r');
      if (ch=="OFF"){
        servo1.write(90);
        servo2.write(90);
        servo3.write(90);
        servo4.write(90);           
        digitalWrite(Laser,LOW);
        delay(100);
      }
      Serial.flush();

  }else if (total_pos==0){   // condition for turning off
        servo1.write(90);
        servo2.write(90);
        servo3.write(90);
        servo4.write(90);           
        digitalWrite(Laser,LOW);
        delay(500);
      
        Serial.flush();

  }
  Serial.flush();  // LAST ADDED
}
