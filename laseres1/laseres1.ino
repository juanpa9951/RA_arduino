/// constants won't change

const int L1    = 2; // the number of the LED pin
const int L2    = 3; // the number of the LED pin
const int L3    = 4; // the number of the LED pin
const int L4    = 5; // the number of the LED pin
const int L5    = 6; // the number of the LED pin
const int L6    = 7; // the number of the LED pin
const int L7    = 8; // the number of the LED pin
const int L8    = 9; // the number of the LED pin

// variables will change:
int ledState = LOW;   // the current state of LED

void setup() {
  Serial.begin(9600);         // initialize serial
  pinMode(L1, OUTPUT);   // set arduino pin to output mode
  pinMode(L2, OUTPUT);   // set arduino pin to output mode
  pinMode(L3, OUTPUT);   // set arduino pin to output mode
  pinMode(L4, OUTPUT);   // set arduino pin to output mode
}

void loop() {
  // control LED arccoding to the toggleed sate
  digitalWrite(L1, HIGH);
  Serial.println("1");
  delay(1000);
  digitalWrite(L1, LOW); 
  digitalWrite(L2, HIGH); 
  Serial.println("2");
  delay(1000);   
  digitalWrite(L2, LOW);
  digitalWrite(L3, HIGH);
  Serial.println("3"); 
  delay(1000); 
  digitalWrite(L3, LOW);
  digitalWrite(L4, HIGH); 
  Serial.println("4");
  delay(1000);
  digitalWrite(L4, LOW);
  digitalWrite(L5, HIGH);
  Serial.println("5");
  delay(1000); 
  digitalWrite(L5, LOW);
  digitalWrite(L6, HIGH); 
  Serial.println("6");
  delay(1000);   
  digitalWrite(L6, LOW);
  digitalWrite(L7, HIGH);
  Serial.println("7"); 
  delay(1000); 
  digitalWrite(L7, LOW);
  digitalWrite(L8, HIGH);
  Serial.println("8"); 
  delay(1000); 
  digitalWrite(L8, LOW);           
}
