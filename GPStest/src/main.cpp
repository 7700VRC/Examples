/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       georgekirkman                                             */
/*    Created:      2/12/2025, 4:05:44 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
brain Brain;
gps GPS1=gps(PORT3,0.0,0.0,inches,0.0);

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  float heading =0.0;
  float xgps=0.0;
  float ygps=0.0;
  float qgps=100.0;
  // User control code here, inside the loop
  while (1) {
    heading = GPS1.heading(degrees);
    xgps=GPS1.xPosition(distanceUnits::in);
    ygps=GPS1.yPosition(distanceUnits::in);
    qgps=GPS1.quality();
    Brain.Screen.printAt(1,20, "GPS Values");
Brain.Screen.printAt(1,40, "heading = %.2f   ", heading);
Brain.Screen.printAt(1,60, "xPosition = %.2f   ", xgps);
Brain.Screen.printAt(1,80, "yPosition = %.2f   ", ygps);
Brain.Screen.printAt(1,100, "quality = %.2f   ", qgps);
    wait(50, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  
  usercontrol();
  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
