#include "vex.h"

using namespace vex;

bool enableDisplay = false;

int brainDisplay() {
  while(enableDisplay)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);

    Brain.Screen.print("FrontLeftMotor: ");
    Brain.Screen.print(FrontLeftMotor.velocity(percent));
    Brain.Screen.newLine();
    Brain.Screen.print("FrontRightMotor: ");
    Brain.Screen.print(FrontRightMotor.velocity(percent));
    Brain.Screen.newLine();
    Brain.Screen.print("BackLeftMotor: ");
    Brain.Screen.print(BackLeftMotor.velocity(percent));
    Brain.Screen.newLine();
    Brain.Screen.print("BackRightMotor: ");
    Brain.Screen.print(BackRightMotor.velocity(percent));
    Brain.Screen.newLine();

    Brain.Screen.print("Inertial: ");
    Brain.Screen.print(Inertial.rotation());
    Brain.Screen.newLine();
    vex::task::sleep(400);
  }

  return 1;
}