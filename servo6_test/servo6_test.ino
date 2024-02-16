#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// The PCA9685 address
#define PCA9685_ADDRESS 0x40

// Create the PWM servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(PCA9685_ADDRESS);

// Define constants for the servo
#define SERVO_MIN_PULSE_WIDTH 100   // Minimum pulse width in microseconds 100    50
#define SERVO_MAX_PULSE_WIDTH 500   // Maximum pulse width in microseconds 500   500
#define SERVO_MIN_ANGLE 0            // Minimum angle in degrees
#define SERVO_MAX_ANGLE 180          // Maximum angle in degrees

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos typically run at 50Hz - 60Hz updates

  delay(10);
}

void loop() {
  // Move the servo to different positions
  
    setServoAngle(4, 90);
    setServoAngle(5, 90);
    setServoAngle(6, 90);
    setServoAngle(7, 90);
    delay(5000); // Delay to allow servo to reach the desired position

    setServoAngle(4, 100);
    setServoAngle(5, 100);
    setServoAngle(6, 80);
    setServoAngle(7, 80);
    delay(5000); // Delay to allow servo to reach the desired position

    setServoAngle(4, 110);
    setServoAngle(5, 110);
    setServoAngle(6, 70);
    setServoAngle(7, 70);
    delay(5000); // Delay to allow servo to reach the desired position

    setServoAngle(4, 100);
    setServoAngle(5, 100);
    setServoAngle(6, 80);
    setServoAngle(7, 80);
    delay(5000); // Delay to allow servo to reach the desired position  

    setServoAngle(4, 90);
    setServoAngle(5, 90);
    setServoAngle(6, 90);
    setServoAngle(7, 90);
    delay(5000); // Delay to allow servo to reach the desired position
  
}

// Function to set the angle of the servo
void setServoAngle(uint8_t servoNum, int angle) {
  // Convert angle to pulse width
  uint16_t pulse_width = map(angle, 0, 180, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  // Set pulse width
  pwm.setPWM(servoNum, 0, pulse_width);
}

