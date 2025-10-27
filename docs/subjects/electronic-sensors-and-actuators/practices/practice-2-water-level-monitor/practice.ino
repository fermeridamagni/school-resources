/**
 * @file practice-2.ino
 * @author fermeridamagni
 * @date 2025-10-22
 * @description Water level monitoring system using ultrasonic sensor. Displays tank levels with LEDs and activates buzzer when tank is near full.
 */

#include <MinimalUltrasonic.h>

MinimalUltrasonic ultrasonic(10, 11);

const int buzzerPin = 8;
const int led1Pin = 5;
const int led2Pin = 6;
const int led3Pin = 7;

int distance = 0;
int waterLevel = 0;
int tankHeight = 13; // height (cm)
int remainingLevel = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  distance = ultrasonic.read();

  waterLevel = tankHeight - distance;
  remainingLevel = tankHeight - waterLevel;

  if (waterLevel >= 1)
  {
    digitalWrite(led1Pin, HIGH);
  }
  else
  {
    digitalWrite(led1Pin, LOW);
  }

  if (waterLevel >= (tankHeight / 2))
  {
    digitalWrite(led2Pin, HIGH);
  }
  else
  {
    digitalWrite(led2Pin, LOW);
  }

  if (waterLevel >= 10)
  {
    digitalWrite(led3Pin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    digitalWrite(led3Pin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  // Serial.println("--------------");
  // Serial.print("Distance (cm): ");
  // Serial.print(distance);
  // Serial.println();

  Serial.println("--------------");
  Serial.print("Tank Height (cm): ");
  Serial.print(tankHeight);
  Serial.println();

  Serial.print("Remaining Height (cm): ");
  Serial.print(remainingLevel);
  Serial.println();

  Serial.print("Water Level (cm): ");
  Serial.print(waterLevel);
  Serial.println();

  delay(100); // A small delay to prevent rapid, unstable readings
}
