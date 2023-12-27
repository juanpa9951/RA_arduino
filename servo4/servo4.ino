#include <Servo.h>

Servo servo1;  // Define servo1 object
Servo servo2;  // Define servo2 object

int servo1Pin = 10;  // PWM pin for servo1
int servo2Pin = 11; // PWM pin for servo2
int t1 = 20;  //20
int t2 = 100;  //100

int onp;
int total_pos=7;
String ch;
String x1;
String x2;
String x3;
String x4;
String x5;
String x6;
String x7;
String y1;
String y2;
String y3;
String y4;
String y5;
String y6;
String y7;

String Xp[]={x1,x2,x3,x4,x5,x6,x7};
String Yp[]={y1,y2,y3,y4,y5,y6,y7};

void setup() {
  Serial.begin(115200); 
  servo1.attach(servo1Pin); // Attach servo1 to its pin
  servo2.attach(servo2Pin); // Attach servo2 to its pin
  pinMode(3,OUTPUT);
}

void loop() {
  while(Serial.available()==0){
  } // this while loop wait until there is a new command arriving in the serial port and then executes the code
  // this should work for receiving a string like this "1:2:3:4:5:6:7:8:9:10:11:12:13:14\r" from python serial
  for (int position = 0; position < total_pos*2; position++) { // here we read the command from python and decompose it
    if (position < total_pos){  // check here.................  7 X-positions
      Xp[position]=Serial.readStringUntil(':'); // 
    }else if (position < total_pos*2-1){ // check here.......................  7 Y-positions
      Yp[position - total_pos]=Serial.readStringUntil(':');
    }else{
      Yp[position - total_pos]=Serial.readStringUntil('\r'); // last part of the command from python, so the 7th Y-position 
    }
  }

  // here just to verify if the X and Y arrrays are OK
  /*
  Serial.println("X---> ");
  for (int i = 0; i < sizeof(Xp) / sizeof(Xp[0]); i++) {
    Serial.print(Xp[i]);
    Serial.print(" ");
  }
  Serial.println("Y---> ");
  for (int i = 0; i < sizeof(Yp) / sizeof(Yp[0]); i++) {
    Serial.print(Yp[i]);
    Serial.print(" ");
  }
  */

  // here we start the projection of the layer looping through the X and Y positions
  for (int position = 0; position < total_pos; position++) {
    digitalWrite(3,HIGH);
    servo1.write(Xp[position].toInt());
    delay(t1);
    servo2.write(Yp[position].toInt());  
    delay(t2);
  }
  ch=Serial.readStringUntil('\r');
  if (ch=="OFF"){
    onp=0;
    servo1.write(90);
    servo2.write(90);
    digitalWrite(3,LOW);
    delay(100);
  }

}