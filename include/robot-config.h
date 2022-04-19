using namespace vex;

// Brain and Devices
extern brain Brain;

extern controller Controller1;
extern controller Controller2;

extern inertial Inertial;

extern motor FrontLeftMotor;
extern motor FrontRightMotor;
extern motor BackLeftMotor;
extern motor BackRightMotor;

extern motor_group LeftMotorGroup;
extern motor_group RightMotorGroup;

// Initialize code / tasks / devices.
void  vexcodeInit( void );