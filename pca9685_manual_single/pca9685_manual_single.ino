#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// The PCA9685 address
#define PCA9685_ADDRESS 0x40

// Create the PWM servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(PCA9685_ADDRESS);

// Define constants for the servos
#define Servo_B 8     // Servo connected to channel 0 of PCA9685
#define Servo_Th 9     // Servo connected to channel 1 of PCA9685
#define SERVO_MIN_PULSE_WIDTH 100   // Minimum pulse width in microseconds 100    50
#define SERVO_MAX_PULSE_WIDTH 500   // Maximum pulse width in microseconds 500   500
#define SERVO_MIN_ANGLE 0            // Minimum angle in degrees
#define SERVO_MAX_ANGLE 180          // Maximum angle in degrees

// DEFINE THE LASERS PINS
int Laser=2;

//...............................................

int total_pos=2; // how many inputs we receive 

// DECLARE THE INPUTS TO RECEIVE FROM PYTHON
String B;
String Th;
String Inputs[]={B,Th};

void setup() {
  Serial.begin(9600);   // critical for python communication  //115200 for python   //9600 for IDE user serial monitor
  pinMode(Laser,OUTPUT);
  // pca9685 settings
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos typically run at 50Hz - 60Hz updates
  delay(10);
}

void loop() {
  Serial.println(" Hello boy");
  while(Serial.available()==0){
  } // this while loop wait until there is a new command arriving in the serial port and then executes the code
  // this should work for receiving a string like this "1,2" from user IDE serial monitor
  for (int position = 0; position < total_pos; position++) { // here we read the command from python and decompose it
    if (position < total_pos-1){ 
      Inputs[position]=Serial.readStringUntil(',');
    }else{
      Inputs[position]=Serial.readStringUntil('\r'); // last part of the command from python
    }
  }
  // here we separate the received inputs
  B=Inputs[0];
  Th=Inputs[1];
  // here we print the inputs to verify.....................
  Serial.print(" B = ");
  Serial.println(B);
  Serial.print(" Th = ");
  Serial.println(Th);
  //..................................................
  setServoAngle(Servo_B, B.toInt());
  setServoAngle(Servo_Th, Th.toInt());
  
  //  here we assign the values
  Serial.flush();
}
// Function to set the angle of the servo
void setServoAngle(uint8_t servoNum, int angle) {
  // Convert angle to pulse width
  uint16_t pulse_width = map(angle, 0, 180, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  // Set pulse width
  pwm.setPWM(servoNum, 0, pulse_width);
}