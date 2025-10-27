# Practice 9 - Traffic Light Controller

## Overview

This practice simulates a traffic light control system using two sets of traffic lights. The system coordinates the lights to alternate between two directions, implementing realistic traffic light sequences including yellow (caution) transitions.

## Objectives

- Implement state machine logic for traffic control
- Learn to use enums for state management
- Control multiple synchronized outputs
- Practice timing and sequencing in embedded systems

## Hardware Components

- Arduino board
- First traffic light set:
  - Red LED on pin 2
  - Yellow LED on pin 3
  - Green LED on pin 4
- Second traffic light set:
  - Red LED on pin 5
  - Yellow LED on pin 6
  - Green LED on pin 7
- Current-limiting resistors for all LEDs
- Breadboard and jumper wires

## Functionality

The system cycles through four states:

### State 1: FIRST (1 second)

- First light: GREEN
- Second light: RED

### State 2: CHANGING_FIRST (1 second)

- First light: YELLOW (transition)
- Second light: RED

### State 3: SECOND (1 second)

- First light: RED
- Second light: GREEN

### State 4: CHANGING_SECOND (1 second)

- First light: RED
- Second light: YELLOW (transition)

Then the cycle repeats from State 1.

## Key Features

- **State Machine Implementation**: Uses enum for clear state definitions
- **Synchronized Control**: Two traffic lights operate in coordination
- **Realistic Transitions**: Includes yellow caution lights between changes
- **Array-Based LED Management**: Efficient handling of multiple LEDs
- **Continuous Operation**: Runs indefinitely with proper timing

## Usage

1. Upload the sketch to your Arduino board
2. Open Serial Monitor at 9600 baud (optional)
3. Observe the traffic light sequence
4. Note the coordinated operation ensuring only one direction has green at a time

## Circuit Connections

| Component               | Arduino Pin |
|------------------------|-------------|
| First Light - Red      | 2           |
| First Light - Yellow   | 3           |
| First Light - Green    | 4           |
| Second Light - Red     | 5           |
| Second Light - Yellow  | 6           |
| Second Light - Green   | 7           |

**Note**: Use appropriate current-limiting resistors (typically 220Ω-330Ω) for each LED.

## Teaching Concepts

- **State Machine Design**: Using enums and switch statements
- **Synchronization**: Coordinating multiple outputs
- **Array Usage**: Organizing related pins in arrays
- **Safety Logic**: Ensuring safe traffic light operation
- **Timing Control**: Managing state transitions with delays

## Real-World Application

This project simulates real traffic light controllers, which are essential for:

- Urban traffic management
- Intersection safety
- Pedestrian crossing control
- Emergency vehicle priority systems

## Code

```cpp
/**
 * @file practice-9.ino
 * @author fermeridamagni
 * @date 2025-10-22
 * @description Traffic light controller simulation. Controls two sets of traffic lights (red, yellow, green) with synchronized state transitions.
 */

#include <Arduino.h>

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

const int led4 = 5;
const int led5 = 6;
const int led6 = 7;

int firstTrafficLight[] = {led1, led2, led3};  // red, yellow, green
int secondTrafficLight[] = {led4, led5, led6}; // red, yellow, green

enum TrafficLightState
{
  FIRST,
  CHANGING_FIRST,
  SECOND,
  CHANGING_SECOND
};

TrafficLightState currentState = FIRST;

void setup()
{
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop()
{
  switch (currentState)
  {
  case FIRST:
    digitalWrite(firstTrafficLight[0], LOW);  // turn off red light
    digitalWrite(firstTrafficLight[1], LOW);  // turn off yellow light
    digitalWrite(firstTrafficLight[2], HIGH); // turn on green light

    digitalWrite(secondTrafficLight[0], HIGH); // turn on red light
    digitalWrite(secondTrafficLight[1], LOW);  // turn off yellow light
    digitalWrite(secondTrafficLight[2], LOW);  // turn off green light

    delay(1000); // wait one second
    currentState = CHANGING_FIRST;
    break;

  case CHANGING_FIRST:
    digitalWrite(firstTrafficLight[0], LOW);  // turn off red light
    digitalWrite(firstTrafficLight[1], HIGH); // turn on yellow light
    digitalWrite(firstTrafficLight[2], LOW);  // turn off green light

    digitalWrite(secondTrafficLight[0], HIGH); // turn on red light
    digitalWrite(secondTrafficLight[1], LOW);  // turn off yellow light
    digitalWrite(secondTrafficLight[2], LOW);  // turn off green light

    delay(1000); // wait one second
    currentState = SECOND;
    break;

  case SECOND:
    digitalWrite(secondTrafficLight[0], LOW);  // turn off red light
    digitalWrite(secondTrafficLight[1], LOW);  // turn off yellow light
    digitalWrite(secondTrafficLight[2], HIGH); // turn on green light

    digitalWrite(firstTrafficLight[0], HIGH); // turn on red light
    digitalWrite(firstTrafficLight[1], LOW);  // turn off yellow light
    digitalWrite(firstTrafficLight[2], LOW);  // turn off green light

    delay(1000); // wait one second
    currentState = CHANGING_SECOND;
    break;

  case CHANGING_SECOND:
    digitalWrite(secondTrafficLight[0], LOW);  // turn off red light
    digitalWrite(secondTrafficLight[1], HIGH); // turn on yellow light
    digitalWrite(secondTrafficLight[2], LOW);  // turn off green light

    digitalWrite(firstTrafficLight[0], HIGH); // turn on red light
    digitalWrite(firstTrafficLight[1], LOW);  // turn off yellow light
    digitalWrite(firstTrafficLight[2], LOW);  // turn off green light

    delay(1000); // wait one second
    currentState = FIRST;
    break;
  }

  delay(100); // short delay
}
```
