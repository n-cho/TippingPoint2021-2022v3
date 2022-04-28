#include "vex.h"
#include "drive-pid.h"
using namespace vex;

struct auton_drivetrain {
  // void drive(directionType direction, int degrees) {
  //   if(direction == directionType::fwd) {
  //     lateral.setPoint += degrees;
  //   } else {
  //     lateral.setPoint -= degrees;
  //   }
  // }
  void drive(int degrees) {
    lateral.setPoint += degrees;
  }
  void turn(int degrees) {
    turning.setPoint += degrees;
  }
};