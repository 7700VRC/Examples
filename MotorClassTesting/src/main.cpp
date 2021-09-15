/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*    Update:  DK  6-11-2021                                                  */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// Motor                motor         1
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global Variables here
float pi = 3.14;

// Custom Functions
void moveMotor(int sp, float turns = 0) {
  Brain.Screen.printAt(1, 40, "encoder = %f.2.  ", Motor.position(rev));
  Motor.setVelocity(sp, percent);
  if (turns == 0) {
    Motor.spin(forward);
  } else {
    Motor.spinFor(forward, turns, rev);
  }
  Brain.Screen.printAt(1, 80, "encoder = %f.2.  ", Motor.position(rev));
}

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
Brain.Screen.printAt(1, 20, "Pre- Auton encoder = %f.2.  ", Motor.position(rev));
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting initial positions, ...
}

void auton() {
  moveMotor(50);
  wait(1000, msec);
  moveMotor(0);
}

void driver() {
  // User control code here, inside the loop
  while (true) {

    wait(10, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(auton);
  Competition.drivercontrol(driver);

  // Run the pre-autonomous function.
  pre_auton();
auton();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
