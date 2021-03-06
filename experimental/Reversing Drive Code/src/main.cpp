/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*    Update:  DK  8-22-21. Reversing Drive                                                  */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LM                   motor_group   1, 2            
// RM                   motor_group   3, 4            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global Variables here
float pi=3.14;


// Custom Functions
void driveVolts(int lspeed, int rspeed, int wt)
{
  LM.spin(forward, lspeed*120, voltageUnits::mV);
  RM.spin(forward, rspeed*120, voltageUnits::mV);
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
  int dir=1; //1 = forward, -1 =backward
  int lstick=0;
  int rstick=0;
  while (true) {
    if(Controller1.ButtonUp.pressing())
    {
      dir=1;
      Brain.Screen.printAt(1, 40, "I am driving Forward  >>");
      }
       if(Controller1.ButtonDown.pressing())
    {
      dir=-1;
      Brain.Screen.printAt(1, 40, "I am driving Backward <<");
      }
    lstick=dir*Controller1.Axis3.position();
    rstick=dir*Controller1.Axis2.position();
    if(dir==1){
      driveVolts(lstick, rstick, 10);
    }
    else{
    driveVolts(rstick, lstick, 10);  
     }
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
