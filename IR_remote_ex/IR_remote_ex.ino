#include <IRremote.h>
int IRpin=11;
IRrecv IR(IRpin);
decode_results cmd;
String mycom;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 IR.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (IR.decode(&cmd)==0){
  }
  Serial.println(cmd.value,HEX);
  delay(500);
  
  if (cmd.value== 0xFFA25D){
    mycom="pwr";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFFA857){
    mycom="min";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF906F){
    mycom="plus";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF6897){
    mycom="0";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF30CF){
    mycom="1";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF18E7){
    mycom="2";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF7A85){
    mycom="3";
    Serial.println(mycom);
  }  
  else  if (cmd.value== 0xFF10EF){
    mycom="4";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF38C7){
    mycom="5";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF5AA5){
    mycom="6";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF42BD){
    mycom="7";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF4AB5){
    mycom="8";
    Serial.println(mycom);
  }
  else  if (cmd.value== 0xFF52AD){
    mycom="9";
    Serial.println(mycom);
  }
  else {
    mycom="not recognized";
    Serial.println(mycom);
  }

  IR.resume();
}
