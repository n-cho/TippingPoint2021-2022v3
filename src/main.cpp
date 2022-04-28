/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       nathancho                                                 */
/*    Created:      Thu Apr 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "autonomous.h"
#include "brain-display.h"

using namespace vex;

competition Competition;
auton_drivetrain motion;

void auton() {
  vex::task task0(drivePID);
  vex::task task1(brainDisplay);
  enablePID = true;
  enableDisplay = true;
}

void control() {
  enablePID = false;
}

int main() {
  vexcodeInit();
  Competition.autonomous(auton);
  Competition.drivercontrol(control);
}
