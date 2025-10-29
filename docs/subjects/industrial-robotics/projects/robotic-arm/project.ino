#include <Arduino.h>
#include <Servo.h>

Servo servoBase;
Servo servoArm;
Servo servoElbow;
Servo servoWrist;
Servo servoClawBase;
Servo servoClaw;

void setup() {
  Serial.begin(9600);

  servoBase.attach(3);
  servoArm.attach(4);
  servoElbow.attach(5);
  servoWrist.attach(6);
  servoClawBase.attach(7);
  servoClaw.attach(8);

  // Initial Positions
  servoBase.write(90);  // 90° (neutral position)
  servoArm.write(90);
  servoElbow.write(90);
  servoWrist.write(90);
  servoClawBase.write(90);
  servoClaw.write(0);  // Claws closed
}

void loop() {
  int servoBaseReading = servoBase.read();
  int servoArmReading = servoArm.read();
  int servoElbowReading = servoElbow.read();
  int servoWristReading = servoWrist.read();
  int servoClawBaseReading = servoClawBase.read();
  int servoClawReading = servoClaw.read();

  Serial.println("---------");
  Serial.print("Base Servo Position: ");
  Serial.println(servoBaseReading);
  Serial.print("Arm Servo Position: ");
  Serial.println(servoArmReading);
  Serial.print("Elbow Servo Position: ");
  Serial.println(servoElbowReading);
  Serial.print("Wrist Servo Position: ");
  Serial.println(servoWristReading);
  Serial.print("Claw Base Servo Position: ");
  Serial.println(servoClawBaseReading);
  Serial.print("Claw Servo Position: ");
  Serial.println(servoClawReading);
  Serial.println("---------");

  delay(2000);  // wait for 2 seconds before next movement

  // Base movement
  servoBase.write(45);  // rotate the base to left
  delay(1000);
  servoBase.write(135);  // rotate the base to right
  delay(1000);

  // Arm movement
  servoArm.write(60);  // the arm extends
  delay(1000);
  servoArm.write(120);  // the arm contracts
  delay(1000);

  // Elbow movement
  servoElbow.write(45);  // elbow extends
  delay(1000);
  servoElbow.write(135);  // elbow contracts
  delay(1000);

  // Wrist Movement
  servoWrist.write(45);  // wrist contracts
  delay(1000);
  servoWrist.write(135);  // wrist extends
  delay(1000);

  // Claw Base movement
  servoClawBase.write(45);  // rotate the claw
  delay(1000);

  // Claw Movement
  servoClaw.write(180);  // open the claw
  delay(1000);
  servoClaw.write(0);  // close the claw
  delay(1000);
}