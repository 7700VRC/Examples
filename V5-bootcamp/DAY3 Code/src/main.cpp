/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*    Update:  DK  6-19-2022   for v5 bootcamp */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftMotor            motor         1
// RightMotor           motor         10
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global Variables here
float Pi = 3.14;
float D = 4.0;
float W = 14.5;

// Custom Functions

void driveBrake() {
  LeftMotor.stop(brake);
  RightMotor.stop(brake);
}
void driveCoast() {
  LeftMotor.stop(coast);
  RightMotor.stop(coast);
}

void drive(int lspeed, int rspeed, int wt) {
  LeftMotor.spin(forward, lspeed, percent);
  RightMotor.spin(forward, rspeed, percent);
  wait(wt, msec);
}

void inchDrive(float target) {
  float x = 0.0;
  LeftMotor.setPosition(0.0, rev);
  while (x < target) {
    drive(50, 50, 10);
    x = Pi * D * LeftMotor.position(rev);
  }
  drive(0, 0, 0);
}

void inchTurn(float target) {
  float x = 0.0;
  target = W * Pi * target / 360.0;
  LeftMotor.setPosition(0.0, rev);
  while (x < target) {
    drive(50, -50, 10);
    x = Pi * D * LeftMotor.position(rev);
  }
  drive(0, 0, 0);
}

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting initial positions, ...
}

void auton() {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  Brain.Screen.printAt(1, 20, "Auton is running");
  inchDrive(24);
  inchTurn(90);
  inchDrive(12);
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

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
