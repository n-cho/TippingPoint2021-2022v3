#include "vex.h"

using namespace vex;

struct {
  double kP = 0.03;
  double kI = 0.0;
  double kD = 0.0;
  int error = 0;
  int prevError = 0;
  int integral = 0;
  int derivative = 0;
  int setPoint = 0;
} lateral;

struct {
  double kP = 0.02;
  double kI = 0.0;
  double kD = 0.0;
  int error = 0;
  int prevError = 0;
  int integral = 0;
  int derivative = 0;
  int setPoint = 0;
} turning;

bool enablePID = false;

int drivePID() {
  while(enablePID) {
    
    // Lateral Motion
    // For determining distance from desired value.
    int currentPosition = (FrontLeftMotor.rotation(degrees) + FrontRightMotor.rotation(degrees)) / 2;

    lateral.error = lateral.setPoint - currentPosition;       // Update the current lateral error. The goal is to have error equal 0
    lateral.derivative = lateral.error - lateral.prevError;   // Update the lateral derivative. Compares current error to the error in previous iteration. Makes small adjustments based on that value.
    lateral.integral += lateral.error;                        // Update the total lateral error. If the proportional component is consistantly lacking or overshooting, integral will grow very large.
    
    // Proportional + Derivative + Integral
    double lateralMotorPower = (lateral.error * lateral.kP + lateral.derivative * lateral.kD + lateral.integral * lateral.kI);

    // Turning Motion
    int rotation = Inertial.rotation();

    turning.error = rotation  - turning.setPoint;
    turning.derivative = turning.error - turning.prevError;
    turning.integral += turning.error; 

    // Proportional + Derivative + Integral
    double turnMotorPower = (turning.error * turning.kP + turning.derivative * turning.kD + turning.integral * turning.kI);

    // Use determined values to spin motors.
    FrontRightMotor.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    FrontLeftMotor.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    BackLeftMotor.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    BackRightMotor.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);

    // Record this iteration's error for next interation's dervative value.
    lateral.prevError = lateral.error;
    turning.prevError = turning.error;

    // Don't hog computing power.
    vex::task::sleep(20);
  }

  return 1;
}