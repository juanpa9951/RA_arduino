#include <IRremote.h>
int IRpin=11;
IRrecv IR(IRpin);
decode_results cmd;
String mycom;
int rack=0;
int dir;
int rack_old=0;
int desf=1;
int t_mov=5000;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 IR.enableIRIn();
 pinMode(1,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (IR.decode(&cmd)==0){
  }
  Serial.println(cmd.value,HEX);
  delay(500);  // delay to prevent double press
  
// each rack has 3 digital outputs (starting in 1), 1-->LED, 2---> MOTOR UP, 3----> MOTOR DOWN

  if (cmd.value== 0xFFA25D){
    mycom="pwr";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFFA857){
    mycom="min";
    Serial.println(mycom);
    if (rack!=0){
      digitalWrite(rack*3+desf,HIGH); // ACTIVATE MOTOR RELAY
      delay(t_mov);
      digitalWrite(rack*3+desf,LOW); // DEACTIVATE MOTOR RELAY
      digitalWrite(rack*3-2+desf,LOW); // TURN OFF RACK LED
      rack=0;  // SET RACK VARIABLE TO ZERO
    }    
  }
  else  if (cmd.value== 0xFF906F){
    mycom="plus";
    Serial.println(mycom);
    if (rack!=0){
      digitalWrite(rack*3-1+desf,HIGH); // ACTIVATE MOTOR RELAY
      delay(t_mov);
      digitalWrite(rack*3-1+desf,LOW); // DEACTIVATE MOTOR RELAY
      digitalWrite(rack*3-2+desf,LOW); // TURN OFF RACK LED
      rack=0;  // SET RACK VARIABLE TO ZERO
    }
  }
  else  if (cmd.value== 0xFF6897){
    mycom="0";
    Serial.println(mycom);
    rack=0;
  }
  else  if (cmd.value== 0xFF30CF){
    mycom="1";
    Serial.println(mycom);
    rack=mycom.toInt();   // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }
  else  if (cmd.value== 0xFF18E7){
    mycom="2";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON    
  }
  else  if (cmd.value== 0xFF7A85){
    mycom="3";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }  
  else  if (cmd.value== 0xFF10EF){
    mycom="4";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }
  else  if (cmd.value== 0xFF38C7){
    mycom="5";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }
  else  if (cmd.value== 0xFF5AA5){
    mycom="6";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }
  else  if (cmd.value== 0xFF42BD){
    mycom="7";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }
  else  if (cmd.value== 0xFF4AB5){
    mycom="8";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }
  else  if (cmd.value== 0xFF52AD){
    mycom="9";
    Serial.println(mycom);
    rack=mycom.toInt();  // ASIGN THE RACK
    digitalWrite(rack*3-2+desf,HIGH);  // TURN THE RACK LED ON
  }
  else {
    mycom="not recognized";
    Serial.println(mycom);
  }

  if (rack!=rack_old){
    digitalWrite(rack_old*3-2+desf,LOW);
  }
  rack_old=rack;

  IR.resume();
}
