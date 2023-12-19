int L1=9; 
int L2=8;
int L3=6;
int L4=7; 
int L5=4;
int L6=3;
int L7=5; 
int L8=2;
String cmd1; // first part of command string
String cmd2; // 2nd part of command string
String cmd3; // 3rd part of command string
String cmd4; // first part of command string
String cmd5; // 2nd part of command string
String cmd6; // 3rd part of command string
String cmd7; // first part of command string
String cmd8; // 2nd part of command string

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(L1,OUTPUT);
pinMode(L2,OUTPUT);
pinMode(L3,OUTPUT);
pinMode(L4,OUTPUT);
pinMode(L5,OUTPUT);
pinMode(L6,OUTPUT);
pinMode(L7,OUTPUT);
pinMode(L8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
while(Serial.available()==0){
} // this loop wait until there is a new command arriving in the serial port and then executes the code

cmd1=Serial.readStringUntil(':'); // first part of command string
cmd2=Serial.readStringUntil(':'); // 2nd part of command string
cmd3=Serial.readStringUntil(':'); // 3rd part of command string
cmd4=Serial.readStringUntil(':'); // x part of command string
cmd5=Serial.readStringUntil(':'); // x part of command string
cmd6=Serial.readStringUntil(':'); // x part of command string
cmd7=Serial.readStringUntil(':'); // x part of command string
cmd8=Serial.readStringUntil('\r'); // last part of command string

// conditions for first part of coomand string
if (cmd1=="1"){
digitalWrite(L1,HIGH);
}
if (cmd1=="2"){
digitalWrite(L2,HIGH);
}
if (cmd1=="3"){
digitalWrite(L3,HIGH);
}
if (cmd1=="4"){
digitalWrite(L4,HIGH);
}
if (cmd1=="5"){
digitalWrite(L5,HIGH);
}
if (cmd1=="6"){
digitalWrite(L6,HIGH);
}
if (cmd1=="7"){
digitalWrite(L7,HIGH);
}
if (cmd1=="8"){
digitalWrite(L8,HIGH);
}

// conditions for 2nd part of coomand string
if (cmd2=="1"){
digitalWrite(L1,HIGH);
}
if (cmd2=="2"){
digitalWrite(L2,HIGH);
}
if (cmd2=="3"){
digitalWrite(L3,HIGH);
}
if (cmd2=="4"){
digitalWrite(L4,HIGH);
}
if (cmd2=="5"){
digitalWrite(L5,HIGH);
}
if (cmd2=="6"){
digitalWrite(L6,HIGH);
}
if (cmd2=="7"){
digitalWrite(L7,HIGH);
}
if (cmd2=="8"){
digitalWrite(L8,HIGH);
}

// conditions for 3rd part of coomand string
if (cmd3=="1"){
digitalWrite(L1,HIGH);
}
if (cmd3=="2"){
digitalWrite(L2,HIGH);
}
if (cmd3=="3"){
digitalWrite(L3,HIGH);
}
if (cmd3=="4"){
digitalWrite(L4,HIGH);
}
if (cmd3=="5"){
digitalWrite(L5,HIGH);
}
if (cmd3=="6"){
digitalWrite(L6,HIGH);
}
if (cmd3=="7"){
digitalWrite(L7,HIGH);
}
if (cmd3=="8"){
digitalWrite(L8,HIGH);
}

// conditions for x part of coomand string
if (cmd4=="1"){
digitalWrite(L1,HIGH);
}
if (cmd4=="2"){
digitalWrite(L2,HIGH);
}
if (cmd4=="3"){
digitalWrite(L3,HIGH);
}
if (cmd4=="4"){
digitalWrite(L4,HIGH);
}
if (cmd4=="5"){
digitalWrite(L5,HIGH);
}
if (cmd4=="6"){
digitalWrite(L6,HIGH);
}
if (cmd4=="7"){
digitalWrite(L7,HIGH);
}
if (cmd4=="8"){
digitalWrite(L8,HIGH);
}
// conditions for x part of coomand string
if (cmd5=="1"){
digitalWrite(L1,HIGH);
}
if (cmd5=="2"){
digitalWrite(L2,HIGH);
}
if (cmd5=="3"){
digitalWrite(L3,HIGH);
}
if (cmd5=="4"){
digitalWrite(L4,HIGH);
}
if (cmd5=="5"){
digitalWrite(L5,HIGH);
}
if (cmd5=="6"){
digitalWrite(L6,HIGH);
}
if (cmd5=="7"){
digitalWrite(L7,HIGH);
}
if (cmd5=="8"){
digitalWrite(L8,HIGH);
}
// conditions for x part of coomand string
if (cmd6=="1"){
digitalWrite(L1,HIGH);
}
if (cmd6=="2"){
digitalWrite(L2,HIGH);
}
if (cmd6=="3"){
digitalWrite(L3,HIGH);
}
if (cmd6=="4"){
digitalWrite(L4,HIGH);
}
if (cmd6=="5"){
digitalWrite(L5,HIGH);
}
if (cmd6=="6"){
digitalWrite(L6,HIGH);
}
if (cmd6=="7"){
digitalWrite(L7,HIGH);
}
if (cmd6=="8"){
digitalWrite(L8,HIGH);
}
// conditions for x part of coomand string
if (cmd7=="1"){
digitalWrite(L1,HIGH);
}
if (cmd7=="2"){
digitalWrite(L2,HIGH);
}
if (cmd7=="3"){
digitalWrite(L3,HIGH);
}
if (cmd7=="4"){
digitalWrite(L4,HIGH);
}
if (cmd7=="5"){
digitalWrite(L5,HIGH);
}
if (cmd7=="6"){
digitalWrite(L6,HIGH);
}
if (cmd7=="7"){
digitalWrite(L7,HIGH);
}
if (cmd7=="8"){
digitalWrite(L8,HIGH);
}
// conditions for x part of coomand string
if (cmd8=="1"){
digitalWrite(L1,HIGH);
}
if (cmd8=="2"){
digitalWrite(L2,HIGH);
}
if (cmd8=="3"){
digitalWrite(L3,HIGH);
}
if (cmd8=="4"){
digitalWrite(L4,HIGH);
}
if (cmd8=="5"){
digitalWrite(L5,HIGH);
}
if (cmd8=="6"){
digitalWrite(L6,HIGH);
}
if (cmd8=="7"){
digitalWrite(L7,HIGH);
}
if (cmd8=="8"){
digitalWrite(L8,HIGH);
}
// conditions for turning off
if (cmd8=="OFF"){
digitalWrite(L1,LOW);
digitalWrite(L2,LOW);
digitalWrite(L3,LOW);
digitalWrite(L4,LOW);
digitalWrite(L5,LOW);
digitalWrite(L6,LOW);
digitalWrite(L7,LOW);
digitalWrite(L8,LOW);
}

}
