/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       georgekirkman                                             */
/*    Created:      7/30/2024, 6:04:37 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
brain Brain;
controller Controller1=controller(primary);
motor RDR4B=motor(PORT5,ratio36_1,false);
motor LDR4B=motor(PORT2,ratio36_1,true);

motor Rpunch=motor(PORT19,ratio18_1,false);
motor Lpunch=motor(PORT4,ratio18_1,true);

motor29 LM=motor29(Brain.ThreeWirePort.F,false);
motor29 RM=motor29(Brain.ThreeWirePort.E,false);


void dr4b(int speed, int wt=0){
  speed=speed*120;
  RDR4B.spin(fwd,speed,voltageUnits::mV);
  LDR4B.spin(fwd,speed,voltageUnits::mV);
  wait(wt,msec);
}

void dr4bBrake(){
  RDR4B.stop(brake);
  LDR4B.stop(brake);
}
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
  // User control code here, inside the loop
  while (1) {
    if (Controller1.ButtonUp.pressing()){
      dr4b(100,10);
    }
    else if(Controller1.ButtonDown.pressing()){
      dr4b(-100,10);
    }
    else{
      dr4bBrake();
    }
       if (Controller1.ButtonR1.pressing()){
      Rpunch.spin(forward,100,pct);
    }
    else if(Controller1.ButtonR2.pressing()){
       Rpunch.spin(forward,-100,pct);
    }
    else{
      Rpunch.stop();
    }
    
    if (Controller1.ButtonL1.pressing()){
      Lpunch.spin(forward,100,pct);
    }
    else if(Controller1.ButtonL2.pressing()){
       Lpunch.spin(forward,-100,pct);
    }
    else{
      Lpunch.stop();
    }

LM.spin(forward,Controller1.Axis3.position(),pct);
RM.spin(forward,Controller1.Axis2.position(),pct);

    wait(10, msec); // Sleep the task for a short amount of time to
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

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
