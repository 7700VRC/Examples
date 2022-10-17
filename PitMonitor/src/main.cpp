/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftFront            motor         2
// LeftBack             motor         4
// RightFront           motor         1
// RightBack            motor         3
// Flywheel1            motor         5
// Flywheel2            motor         7
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

//----------Custom Functions----------
void pitMonitor() {
  double LeftFrontTemp = LeftFront.temperature(celsius);
  double RightFrontTemp = RightFront.temperature(celsius);
  double LeftBackTemp = LeftBack.temperature(celsius);
  double RightBackTemp = RightBack.temperature(celsius);
  double F1Temp = Flywheel1.temperature(celsius);
  double F2Temp = Flywheel2.temperature(celsius);

  Brain.Screen.setCursor(5, 1);
  Brain.Screen.print("%.1f", LeftFrontTemp);

  Brain.Screen.setCursor(5, 6);
  Brain.Screen.print("%.1f", RightFrontTemp);

  Brain.Screen.setCursor(9, 1);
  Brain.Screen.print("%.1f", LeftBackTemp);

  Brain.Screen.setCursor(9, 6);
  Brain.Screen.print("%.1f", RightBackTemp);

  Brain.Screen.setCursor(4, 15);
  Brain.Screen.print("%.1f", F1Temp);

  Brain.Screen.setCursor(5, 15);
  Brain.Screen.print("%.1f", F2Temp);

  if (LeftFrontTemp < 45) {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(1, 50, 20, 30);
  } else if (LeftFrontTemp <= 50 && LeftFrontTemp >= 45) {
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.drawRectangle(1, 50, 20, 30);
  } else {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(1, 50, 20, 30);
  }

  if (RightFrontTemp < 45) {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(50, 50, 20, 30);
  } else if (RightFrontTemp  <= 50 && RightFrontTemp >= 45) {
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.drawRectangle(50, 50, 20, 30);
  } else {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(50, 50, 20, 30);
  }

  if (LeftBackTemp < 45) {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(1, 125, 20, 30);
  } else if (LeftBackTemp  <= 50 && LeftBackTemp >= 45) {
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.drawRectangle(1, 125, 20, 30);
  } else {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(1, 125, 20, 30);
  }

  if (RightBackTemp < 45) {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(50, 125, 20, 30);
  } else if (RightBackTemp  <= 50 && RightBackTemp >= 45) {
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.drawRectangle(50, 125, 20, 30);
  } else {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(50, 125, 20, 30);
  }

  if (F1Temp < 45) {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(125, 60, 10, 15);
  } else if (F1Temp  <= 50 && F1Temp >= 45) {
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.drawRectangle(125, 60, 10, 15);
  } else {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(125, 60, 10, 15);
  }

  if (F2Temp < 45) {
    Brain.Screen.setFillColor(green);
    Brain.Screen.drawRectangle(125, 85, 10, 15);
  } else if (F2Temp  <= 50 && F2Temp >= 45) {
    Brain.Screen.setFillColor(yellow);
    Brain.Screen.drawRectangle(125, 85, 10, 15);
  } else {
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(125, 85, 10, 15);
  }
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
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void drivercontrol(void) {
  while(true){
    pitMonitor();
    wait(1000, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.drivercontrol(drivercontrol);
  while (true) {
    wait(100, msec);
  }
}
