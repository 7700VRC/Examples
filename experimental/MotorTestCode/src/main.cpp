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
// LM                   motor         1
// RM                   motor         2
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global Variables here
const float pi = 3.14;

// Custom Functions

void setUpGraph()
{
  Brain.Screen.drawLine(1, 25, 420, 25);
  Brain.Screen.drawLine(1, 125, 420, 125);
   Brain.Screen.drawLine(1, 225, 420, 225);
}
void graphMotorCurrent(int x) {
  int ml = LM.current(percent);
  int mr = RM.current(percent);
  int y=120;
  if (x>420) //make a second line 
  {y=220;
  x=x-420;
  }
  Brain.Screen.printAt(1, 20, "Current LM = %d    RM =  %d ", ml, mr);
  Brain.Screen.setPenColor(black);
  Brain.Screen.setFillColor(red);
  Brain.Screen.drawCircle(x, y-ml, 2);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawCircle(x, y-mr, 2);
  Brain.Screen.setFillColor(black);
}

void drive(int lspeed, int rspeed, int wt = 0) {
  LM.spin(forward, lspeed, percent);
  RM.spin(forward, rspeed, percent);
  wait(wt, msec);
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
}

void driver() {
  setUpGraph();
  int x = 0;
  while (true) {
    graphMotorCurrent(x);
    int lstick = Controller1.Axis3.position();
    int rstick = Controller1.Axis2.position();
    drive(lstick, rstick);
    wait(20, msec);
    x++;
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
