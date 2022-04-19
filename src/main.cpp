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

double kP = 0, kI = 0, kD = 0;
int error, prevError = 0, totalError = 0, derivative;

double turnKP = 0, turnKI = 0, turnKD = 0;
int turnError, turnPrevError = 0, turnTotalError = 0, turnDerivative;

int desiredValue = 200;
int desiredTurnValue = 0;

bool enablePID = false;

int drivePID() {
  while(enablePID) {
    
    int leftMotorPosition = FrontLeftMotor.position(degrees);
    int rightMotorPosition = FrontRightMotor.position(degrees);

    int averagePosition = (leftMotorPosition + rightMotorPosition) / 2;

    error = averagePosition - desiredValue; 
    derivative = error - prevError;
    totalError += error; 

    double lateralMotorPower = (error * kP + derivative * kD + totalError * kI);

    // Trungingejfbsdkjf

    int turnDifference = leftMotorPosition - rightMotorPosition;

    turnError = turnDifference  - desiredTurnValue; 
    turnDerivative = turnError - turnPrevError;
    turnTotalError += turnError; 

    double turnMotorPower = (turnError * turnKP + turnDerivative * turnKD + turnTotalError * turnKI);

    FrontRightMotor.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);
    FrontLeftMotor.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    BackLeftMotor.spin(forward, lateralMotorPower + turnMotorPower, voltageUnits::volt);
    BackRightMotor.spin(forward, lateralMotorPower - turnMotorPower, voltageUnits::volt);

    prevError = error;
    turnPrevError = turnError;
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
