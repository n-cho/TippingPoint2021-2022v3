#include "vex.h"

using namespace vex;

// Global instance of Brain
brain Brain;                   

// Device constructors
/**
 * vex::controller::controller( controllerType id ) The type of controller that is being created. This can be set to primary or partner.
 *
 * vex::inertial::inertial(	int32_t 	index	)       The port index for this sensor.
 *
 * vex::motor::motor(int32_t  index,                The port index for this motor.
 *                   gearSetting  gears,            Sets the gear's setting for the new motor object.
 *                   bool  reverse                  Sets the reverse flag for the new motor object.
 *                   )
 *
 * vex::motor_group::motor_group(motor  m1,         Sets the first motor in the new motor group object.
 *                               motor  m2          Sets the second motor in the new motor group object.
 *                               )
 */
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

inertial Inertial = inertial(PORT5);

motor FrontLeftMotor = motor (PORT1, ratio18_1, false);
motor FrontRightMotor = motor (PORT2, ratio18_1, true);
motor BackLeftMotor = motor (PORT3, ratio18_1, false);
motor BackRightMotor = motor (PORT4, ratio18_1, true);

motor_group LeftMotorGroup = motor_group (FrontLeftMotor, BackLeftMotor);
motor_group RightMotorGroup = motor_group (FrontRightMotor, BackRightMotor); 

// Used to initialize code / tasks / devices.
void vexcodeInit( void ) {

}