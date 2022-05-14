#include "vex.h"

using namespace vex;

bool enableDisplay = false;

int brainDisplay() {
  while(enableDisplay)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Brain.Screen.print("FrontLeftMotor: ");
    Brain.Screen.print(FrontLeftMotor.rotation(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print("FrontRightMotor: ");
    Brain.Screen.print(FrontRightMotor.rotation(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print("BackLeftMotor: ");
    Brain.Screen.print(BackLeftMotor.rotation(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print("BackRightMotor: ");
    Brain.Screen.print(BackRightMotor.rotation(degrees));
    Brain.Screen.newLine();
    vex::task::sleep(400);
  }

  return 1;
}