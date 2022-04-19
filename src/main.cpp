/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       nathancho                                                 */
/*    Created:      Thu Apr 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

competition Competition;

void pre_auton() {
  vexcodeInit();
}

struct {
  double kP = 0.0;
  double kI = 0.0;
  double kD = 0.0;
  int error = 0;
  int prevError = 0;
  int integral = 0;
  int derivative = 0;
  int setPoint = 200;
} lateral;

struct {
  double kP = 0.0;
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
    int currentPosition = (LeftMotorGroup.position(degrees) + RightMotorGroup.position(degrees)) / 2;

    lateral.error = currentPosition - lateral.setPoint;   // Update the current lateral error. The goal is to have error equal 0
    lateral.derivative = lateral.error - lateral.prevError;   // Update the lateral derivative. Compares current error to the error in previous iteration. Makes small adjustments based on that value.
    lateral.integral += lateral.error;                     // Update the total lateral error. If the proportional component is consistantly lacking or overshooting, integral will grow very large.
    
    // Proportional + Derivative + Integral
    double lateralMotorPower = (lateral.error * lateral.kP + lateral.derivative * lateral.kD + lateral.integral * lateral.kI);

    // Turning Motion
    // Comparing left and right motor groups then comparing to desired difference of the two motor groups.
    int turnDifference = LeftMotorGroup.position(degrees) - RightMotorGroup.position(degrees);

    turning.error = turnDifference  - turning.setPoint;   // Explanation given above.
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

void auton() {
  vex::task task0(drivePID);
  enablePID = true;
}

void usercontrol() {
  enablePID = false;
}

int main() {

}
