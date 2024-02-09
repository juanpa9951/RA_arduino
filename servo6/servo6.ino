#include <Servo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// The PCA9685 address
#define PCA9685_ADDRESS 0x40

// Create the PWM servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(PCA9685_ADDRESS);

// Define constants for the servos
#define Servo_Th_x_bot 0     // Servo connected to channel 0 of PCA9685
#define Servo_Th_x_top 1     // Servo connected to channel 1 of PCA9685
#define Servo_Th_y_bot 2     // Servo connected to channel 2 of PCA9685
#define Servo_Th_y_top 3     // Servo connected to channel 3 of PCA9685
#define Servo_B_x_bot 4     // Servo connected to channel 4 of PCA9685
#define Servo_B_x_top 5     // Servo connected to channel 5 of PCA9685
#define Servo_B_y_bot 6     // Servo connected to channel 6 of PCA9685
#define Servo_B_y_top 7     // Servo connected to channel 7 of PCA9685
#define SERVO_MIN_PULSE_WIDTH 100   // Minimum pulse width in microseconds 100    50
#define SERVO_MAX_PULSE_WIDTH 500   // Maximum pulse width in microseconds 500   500
#define SERVO_MIN_ANGLE 0            // Minimum angle in degrees
#define SERVO_MAX_ANGLE 180          // Maximum angle in degrees


// DEFINE THE LASERS PINS
int Laser_X_bot=2;
int Laser_X_top=3;
int Laser_Y_bot=4;
int Laser_Y_top=5;

// DELAYS FOR MOVING THE SERVOS
int t1 = 20;  //20
int t2 = 100;  //100
//...............................................

int total_pos=8; // how many inputs we receive from python

// DECLARE THE INPUTS TO RECEIVE FROM PYTHON
String Th_x_bot;
String Th_x_top;
String Th_y_bot;
String Th_y_top;
String B_x_bot;
String B_x_top;
String B_y_bot;
String B_y_top;

String Inputs[]={Th_x_bot,Th_x_top,Th_y_bot,Th_y_top,B_x_bot,B_x_top,B_y_bot,B_y_top};

void setup() {
  Serial.begin(115200);   // critical for python communication  //115200 for python
  pinMode(Laser_X_bot,OUTPUT);
  pinMode(Laser_X_top,OUTPUT);
  pinMode(Laser_Y_bot,OUTPUT);
  pinMode(Laser_Y_top,OUTPUT);
  // pca9685 settings
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos typically run at 50Hz - 60Hz updates
  delay(10);
}

void loop() {
  while(Serial.available()==0){
  } // this while loop wait until there is a new command arriving in the serial port and then executes the code
  // this should work for receiving a string like this "1:2:3:4:5:6:7:8\r" from python serial
  for (int position = 0; position < total_pos; position++) { // here we read the command from python and decompose it
    if (position < total_pos-1){ 
      Inputs[position]=Serial.readStringUntil(':');
    }else{
      Inputs[position]=Serial.readStringUntil('\r'); // last part of the command from python
    }
  }
  // here we separate the received inputs
  Th_x_bot=Inputs[0];
  Th_x_top=Inputs[1];
  Th_y_bot=Inputs[2];
  Th_y_top=Inputs[3];
  B_x_bot=Inputs[4];
  B_x_top=Inputs[5];
  B_y_bot=Inputs[6];
  B_y_top=Inputs[7];
  // here we print the inputs to verify.....................
  Serial.print(" 1 Value = ");
  Serial.println(Th_x_bot);
  Serial.print(" 2 Value = ");
  Serial.println(Th_x_top);
  Serial.print(" 3 Value = ");
  Serial.println(Th_y_bot);
  Serial.print(" 4 Value = ");
  Serial.println(Th_y_top);
  Serial.print(" 5 Value = ");
  Serial.println(B_x_bot);
  Serial.print(" 6 Value = ");
  Serial.println(B_x_top);
  Serial.print(" 7 Value = ");
  Serial.println(B_y_bot);
  Serial.print(" 8 Value = ");
  Serial.println(B_y_top);
  //..................................................
  setServoAngle(Servo_Th_x_bot, Th_x_bot.toInt());
  setServoAngle(Servo_Th_x_top, Th_x_top.toInt());
  setServoAngle(Servo_Th_y_bot, Th_y_bot.toInt());
  setServoAngle(Servo_Th_y_top, Th_y_top.toInt());
  setServoAngle(Servo_B_x_bot, B_x_bot.toInt());
  setServoAngle(Servo_B_x_top, B_x_top.toInt());
  setServoAngle(Servo_B_y_bot, B_y_bot.toInt());
  setServoAngle(Servo_B_y_top, B_y_top.toInt());  
  
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