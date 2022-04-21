#include "vex.h"

using namespace vex;

bool enableDisplay = false;

int brainDisplay() {
  while(enableDisplay)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Brain.Screen.print("FrontLeftMotor: ");
    Brain.Screen.print(FrontLeftMotor.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print("FrontRightMotor: ");
    Brain.Screen.print(FrontRightMotor.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print("BackLeftMotor: ");
    Brain.Screen.print(BackLeftMotor.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print("BackRightMotor: ");
    Brain.Screen.print(BackRightMotor.position(degrees));
    Brain.Screen.newLine();
    vex::task::sleep(400);
  }

  return 1;
}