# Practice 1 - Object Counter with Ultrasonic Sensor

## Overview

This practice implements an object counter using an ultrasonic distance sensor. The system detects objects passing within a certain distance threshold and maintains a count, providing visual and audio feedback through LEDs and a buzzer.

## Objectives

- Learn to interface with ultrasonic sensors
- Implement object detection logic
- Use digital outputs to control LEDs and buzzers
- Practice state management in Arduino

## Hardware Components

- Arduino board
- Ultrasonic sensor (HC-SR04) connected to pins 10 (trigger) and 11 (echo)
- Buzzer on pin 8
- LED 1 on pin 6
- LED 2 on pin 7
- Breadboard and jumper wires

## Functionality

The system operates as follows:

1. Continuously reads distance from the ultrasonic sensor
2. When an object is detected within 12cm:
   - Increments the object counter (only once per object)
   - Turns on LED 2 (alert LED)
   - Activates the buzzer
3. When no object is detected:
   - Turns on LED 1 (ready LED)
   - Deactivates LED 2 and buzzer
   - Resets detection flag for next object
4. Displays distance and object count via Serial Monitor

## Key Features

- **Edge Detection**: Only counts each object once as it enters the detection zone
- **Visual Feedback**: Different LEDs indicate ready vs. detection state
- **Audio Alert**: Buzzer sounds when object is detected
- **Serial Output**: Real-time distance and count information

## Usage

1. Upload the sketch to your Arduino board
2. Open Serial Monitor at 9600 baud
3. Place objects within 12cm of the sensor
4. Observe the count increment and LED/buzzer activation
5. Monitor distance readings in the Serial Monitor

## Circuit Connections

| Component        | Arduino Pin |
|-----------------|-------------|
| Ultrasonic Trig | 10          |
| Ultrasonic Echo | 11          |
| Buzzer          | 8           |
| LED 1 (Ready)   | 6           |
| LED 2 (Alert)   | 7           |

## Code

```cpp
/**
 * @file practice-1.ino
 * @author fermeridamagni
 * @date 2025-10-22
 * @description Ultrasonic sensor-based object counter with visual and audio feedback. Counts objects when they pass within 12cm of the sensor and provides LED/buzzer alerts.
 */

#include <Arduino.h>
#include <MinimalUltrasonic.h>

MinimalUltrasonic ultrasonic(10, 11);

const int buzzerPin = 8;
const int led1 = 6;
const int led2 = 7;

int objectCount = 0;
float distance = 0;
bool objectPreviouslyDetected = false;

void setup()
{
  Serial.begin(9600);

  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
  distance = ultrasonic.read(MinimalUltrasonic::METERS);

  if (distance <= 12)
  {
    if (objectPreviouslyDetected == false)
    {
      objectCount++; // increment the counter ONLY ONCE
      objectPreviouslyDetected = true;

      digitalWrite(led1, LOW);       // turn off alert led
      digitalWrite(led2, HIGH);      // turn on alert led (showing an object has detected)
      digitalWrite(buzzerPin, HIGH); // turn on buzzer
    }

    // If objectPreviouslyDetected is already true, we do nothing.
    // The object is just sitting there, and we've already counted it.
  }
  else
  {
    // Reset the flag so we are ready to detect the NEXT object.
    objectPreviouslyDetected = false;

    digitalWrite(led2, LOW);      // turn of alert led
    digitalWrite(led1, HIGH);     // turn on alert led
    digitalWrite(buzzerPin, LOW); // turn off buzzer
  }

  Serial.println("--------------");
  Serial.print("Distance (cm): ");
  Serial.print(distance);
  Serial.println();

  Serial.print("Object count: ");
  Serial.print(objectCount);
  Serial.println();

  delay(100); // A small delay to prevent rapid, unstable readings
}
```

[View Full Code](https://github.com/fermeridamagni/school-resources/blob/main/docs/subjects/electronic-sensors-and-actuators/practices/practice-1-object-counter/practice.ino)
