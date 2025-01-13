#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
// AI Classification Competition Element IDs
enum gameElements {
  mobileGoal,
  redRing,
  blueRing,
};

// AI Vision Color Descriptions
// AI Vision Code Descriptions
vex::aivision AIVision1(PORT1, aivision::ALL_AIOBJS);



// generating and setting random seed
void initializeRandomSeed(){
  int systemTime = Brain.Timer.systemHighResolution();
  double batteryCurrent = Brain.Battery.current();
  double batteryVoltage = Brain.Battery.voltage(voltageUnits::mV);

  // Combine these values into a single integer
  int seed = int(batteryVoltage + batteryCurrent * 100) + systemTime;

  // Set the seed
  srand(seed);
}



void vexcodeInit() {

  //Initializing random seed.
  initializeRandomSeed(); 
}




#pragma endregion VEXcode Generated Robot Configuration

// ----------------------------------------------------------------------------
//                                                                            
//    Project:                                               
//    Author:
//    Created:
//    Configuration:        
//                                                                            
// ----------------------------------------------------------------------------

// Include the V5 Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace vex;

// Begin project code

float getRingX(){
  float x;
  AIVision1.takeSnapshot(aivision::ALL_AIOBJS);
  
      // Determine which AI Classification is detected.
      if (AIVision1.objects[0].id == redRing) {
        // Conditional based on finding a redRing.
        Brain.Screen.printAt(1,20,"redRing found     ");
           x=AIVision1.objects[0].centerX;
  Brain.Screen.printAt(1,40,"red Ring x =  %.2f   ",x);
      }

    else{
Brain.Screen.printAt(1,20,"no red ring found");
 Brain.Screen.printAt(1,40,"                       ");
    }
    if (AIVision1.objects[0].id == blueRing) {
        // Conditional based on finding a blueRing.
        Brain.Screen.printAt(1,80,"blue Ring found   ");
           x=AIVision1.objects[0].centerX;
  Brain.Screen.printAt(1,100,"blue Ring x =  %.2f   ",x);
      }

    else{
Brain.Screen.printAt(1,80,"no blue ring found");
 Brain.Screen.printAt(1,100,"                       ");
    }
  wait(33,msec);

  return x;
}

float objectDetect(){
   float x;
 
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    // Take a snapshot of all AI Classifications.
    AIVision1.takeSnapshot(aivision::ALL_AIOBJS);
    // Check to see if an AI Classification exists in this snapshot.
    if (AIVision1.objectCount > 0) {
      // Determine which AI Classification is detected.
      if (AIVision1.objects[0].id == redRing) {
        // Conditional based on finding a redRing.
        Brain.Screen.print("redRing found");
           x=AIVision1.objects[0].centerX;
  Brain.Screen.printAt(1,40,"red Ring x =  %.2f   ",x);
      } else if (AIVision1.objects[0].id == blueRing) {
        // Conditional based on finding a blueRing.
        Brain.Screen.print("blueRing found");
                   x=AIVision1.objects[0].centerX;
  Brain.Screen.printAt(1,60,"blue Ring x =  %.2f   ",x);
      } else {
        // Else condition will print that an AI Classification is detected but it does not match the above cases.
        Brain.Screen.print("Other Object Found");
      }
    }
    else {
      // If no AI Classifications are found in this snapshot, display a message.
      Brain.Screen.print("No Object Found");
    }
  return x;
  
}

void preAutonomous(void) {
  // actions to do when the program starts
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(1,20,"pre auton code");
 
    float x;
  while (true) {
   //objectDetect();
   getRingX();
    
    wait(0.35, seconds);
  
  }
}

void autonomous(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.printAt(1,20,"autonomous code");
  
  // place automonous code here

}

void userControl(void) {
  Brain.Screen.clearScreen();
  // place driver control in this while loop
  while (true) {
    wait(20, msec);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // create competition instance
  competition Competition;

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(userControl);

  // Run the pre-autonomous function.
  preAutonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}