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

using namespace vex;

competition Competition;

void pre_auton() {
  vexcodeInit();
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
