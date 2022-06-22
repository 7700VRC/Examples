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
// F1                   motor         4               
// F2                   motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global Variables here
float Pi = 3.14;
float D = 4.0;
float W = 14.5;
double OldError = 0.0;
double TBHval = 0.0;
double FWDrive = 0.0;

// Custom Functions
void spinFlywheel(double speed) {
  speed = speed * 120; // speed is in percentage so convert to mV 100% = 12000
                       // mV
  F1.spin(forward, speed, voltageUnits::mV);
  F2.spin(forward, speed, voltageUnits::mV);
}

void controlFlywheelSpeed(double target) {
  double kI = .025;
  double speed = F1.velocity(percent);
  double error = target - speed;
  double fwDrive = FWDrive + kI * error;
// :D
   Brain.Screen.printAt(1, 40, " speed = %.2f ", speed);
  // Keep drive between 0 to 100%
  if (fwDrive > 100)
    fwDrive = 100;
  if (fwDrive < 0)
    fwDrive = 0;
  // Check for zero crossing
  if (error * OldError < 0) {
    fwDrive = 0.5 * (fwDrive + TBHval);
    TBHval = fwDrive;
  }
  

  Brain.Screen.printAt(180, 40, "fwdrive %.1f  ", fwDrive);
  spinFlywheel(fwDrive);

  FWDrive = fwDrive;
  OldError = error;
}

void flywheelMonitor() {
  double current1 = F1.current();
  double current2 = F2.current();
  double t1 = F1.temperature(celsius);
  double t2 = F2.temperature(celsius);

  Brain.Screen.printAt(1, 60, "F1 current = %.1f   Temp = %.1f   ", current1, t1);
  Brain.Screen.printAt(1, 80, "F2 current = %.1f   Temp = %.1f   ", current2, t2);
}
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
  double targetSpeed = 0.0;
  bool alg = true;
  bool flag = true;
  while (true) {

    if (Controller1.ButtonA.pressing())
      targetSpeed = 0;

    if (Controller1.ButtonB.pressing())
      targetSpeed = 17;

    if (Controller1.ButtonY.pressing())
      targetSpeed = 34;
    if (Controller1.ButtonX.pressing())
      targetSpeed = 68;
    if (Controller1.ButtonUp.pressing())
      targetSpeed = 85;
    Brain.Screen.printAt(1, 20, "target speed = %.2f ", targetSpeed);
    if(Controller1.ButtonDown.pressing() && flag){
      flag = false;
      alg = !alg;
    }
    if (!Controller1.ButtonDown.pressing()){
      flag = true;
    }
    if (alg){
      controlFlywheelSpeed(targetSpeed);
      Brain.Screen.printAt(1, 120, "controlled speed    ");
    }
    else {
      spinFlywheel(targetSpeed);
        double speed = F1.velocity(percent);

      Brain.Screen.printAt(1, 120, "not controlled     ");
      Brain.Screen.printAt(1, 40, " speed = %.2f ", speed);
    }

    
      
  //targetSpeed = targetSpeed / 6.0;
  // ew
  // help 
  // currently suffering from secondhand smoking
  // i am now a potted potato
  // "secondhand potato" - aidan 
 // h
 // the mitochondria is the powerhouse of the cell losers
 //  
   //spinFlywheel(targetSpeed);
   // pogchamp
   // ur mom
   // deez nuts
   // lmao
   // hkgtckutxkrtyghv
    flywheelMonitor();
    
    wait(20, msec); // Sleep the task for a short amount of time to
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
