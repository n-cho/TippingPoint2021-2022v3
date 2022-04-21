/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       nathancho                                                 */
/*    Created:      Thu Apr 14 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "drive-pid.h"
#include "brain-display.h"

using namespace vex;

competition Competition;

void auton() {
  vex::task task0(drivePID);
  vex::task task1(brainDisplay);
  enablePID = true;
  enableDisplay = true;
  lateral.setPoint = 10 * 90/M_PI;
}

void usercontrol() {
  enablePID = false;
}

int main() {
  vexcodeInit();
  Competition.autonomous(auton);
  Competition.drivercontrol(usercontrol);
}
