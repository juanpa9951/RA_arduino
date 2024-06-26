#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// The PCA9685 address
#define PCA9685_ADDRESS 0x40

// Create the PWM servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(PCA9685_ADDRESS);

// Define constants for the servo
#define SERVO_MIN_PULSE_WIDTH 100   // Minimum pulse width in microseconds 100    50
#define SERVO_MAX_PULSE_WIDTH 500   // Maximum pulse width in microseconds 500   500
#define SERVO_MIN_ANGLE 50            // Minimum angle in degrees
#define SERVO_MAX_ANGLE 65          // Maximum angle in degrees

void setup() {
  Serial.begin(115200);
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos typically run at 50Hz - 60Hz updates

  delay(10);
}

void loop() {
  // Move the servo to different positions
  for (int angle = SERVO_MIN_ANGLE; angle <= SERVO_MAX_ANGLE; angle += 3) {
    setServoAngle(2, angle);
    //setServoAngle(1, angle);
    //setServoAngle(2, angle);
    //setServoAngle(3, angle);
    delay(7000); // Delay to allow servo to reach the desired position
  }
  for (int angle = SERVO_MAX_ANGLE; angle <= SERVO_MIN_ANGLE; angle -= 3) {
    setServoAngle(2, angle);
    //setServoAngle(1, angle);
    //setServoAngle(2, angle);
    //setServoAngle(3, angle);
    delay(7000); // Delay to allow servo to reach the desired position
  }


}

// Function to set the angle of the servo
void setServoAngle(uint8_t servoNum, int angle) {
  // Convert angle to pulse width
  uint16_t pulse_width = map(angle, 0, 180, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  // Set pulse width
  pwm.setPWM(servoNum, 0, pulse_width);
}

