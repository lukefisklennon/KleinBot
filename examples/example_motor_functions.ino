#include "motors.h";

// Automatic function: setup
void setup() {
  motorSetup(); // Set up motors
}

// Custom function: start moving forwards
void moveForwards() {
  leftMotor(1024);  // Left motor:  full power forwards
  rightMotor(1024); // Right motor: full power forwards
}

// Custom function: start moving backwards
void moveBackwards() {
  leftMotor(-1024);  // Left motor:  full power backwards
  rightMotor(-1024); // Right motor: full power backwards
}

// Custom function: stop
void stop() {
  leftMotor(0);  // Left motor: stop
  rightMotor(0); // Right motor: stop
}

// Custom function: start turning left
void turnLeft() {
  leftMotor(1024);   // Left motor: full power forwards
  rightMotor(-1024); // Right motor: full power backwards
}

// Custom function: start turning right
void turnRight() {
  leftMotor(-1024); // Left motor: full power backwards
  rightMotor(1024); // Right motor: full power forwards
}

// Custom function: turn left 90° and then stop
void turnLeft90() {
  turnLeft()  // Use above function to start turning left
  delay(1000); // Wait 1 second
  stop();      // Use above function to stop
}

void loop() {
  // Code to be run continuously
}
