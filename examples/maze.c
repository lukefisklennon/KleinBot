#include "motors.h";

double speedMult = 0.75;
double leftMotorMult = 0.85;

// Automatic function: setup
void setup() {
  Serial.begin(9600);
  pinMode(D6, INPUT);
  Serial.println("Starting robot...");
  motorSetup(); // Set up motors
}

// Custom function: start moving forwards
void moveForwards() {
  leftMotor(1024 * speedMult * leftMotorMult);  // Left motor:  full power forwards
  rightMotor(-1024 * speedMult); // Right motor: full power forwards
}

// Custom function: start moving backwards
void moveBackwards() {
  leftMotor(-1024 * speedMult * leftMotorMult);  // Left motor:  full power backwards
  rightMotor(1024 * speedMult); // Right motor: full power backwards
}

// Custom function: stop
void stop() {
  leftMotor(0);  // Left motor: stop
  rightMotor(0); // Right motor: stop
}

// Custom function: start turning left
void turnLeft() {
  leftMotor(1024 * speedMult * leftMotorMult);   // Left motor: full power forwards
  rightMotor(1024 * speedMult); // Right motor: full power backwards
}

// Custom function: start turning right
void turnRight() {
  leftMotor(-1024 * speedMult * leftMotorMult); // Left motor: full power backwards
  rightMotor(-1024 * speedMult); // Right motor: full power forwards
}

// Custom function: turn left 90° and then stop
void turnLeft90() {
  turnLeft();  // Use above function to start turning left
  delay(450 / speedMult); // Wait 1 second
  stop();      // Use above function to stop
}

void turn180() {
  turnRight();
  delay(900 / speedMult);
  stop();
}

int sensor() {
  return !digitalRead(D6);
}

void loop() {
  Serial.println("Full steam ahead");
  moveForwards();
  Serial.println("Waiting for a wall");
  while (!sensor()) {
    delay(15);
  }
  Serial.println("Coming to a halt");
  stop();
  Serial.println("Trying to turn left 90");
  turnLeft90();
  if (sensor()) {
    Serial.println("Nope... going the other way around");
    turn180();
  }
}
