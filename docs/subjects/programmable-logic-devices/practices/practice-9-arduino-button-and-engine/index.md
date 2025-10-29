---
title: Practice 9 - Arduino Button and Engine
---

# Practice 9: Arduino Button and Engine Control

This practice demonstrates a simple state machine to control a DC motor (engine) using two push-buttons: a start button and an end button.

## Overview

The sketch uses two buttons with pull-up resistors to control a boolean flag, `isTransporterActive`.

- When the **start button** is pressed, the system should activate the motor.
- When the **end button** is pressed, the system should deactivate the motor.

However, the current logic has a flaw where pressing the start button while the motor is running does nothing, and pressing the start button when it's off incorrectly sets `isTransporterActive` to `false` instead of `true`.

## Hardware Requirements

- Arduino board
- DC Motor
- 2 Push-buttons
- Transistor or motor driver (to safely control the motor)
- Resistors (for pull-ups if not using `INPUT_PULLUP`)

## Pinout

- **Engine (Motor) Pin**: 6
- **Start Button Pin**: 4
- **End Button Pin**: 3

## Code

```cpp
const int enginePin = 6;
const int startButtonPin = 4;
const int endButtonPin = 3;

bool isTransporterActive = false;

void setup() {
  Serial.begin(9600);

  pinMode(enginePin, OUTPUT);
  pinMode(startButtonPin, INPUT_PULLUP);
  pinMode(endButtonPin, INPUT_PULLUP);
}

void loop() {
  int startButtonReading = digitalRead(startButtonPin);
  int endButtonReading = digitalRead(endButtonPin);

  if (isTransporterActive) {
    digitalWrite(enginePin, HIGH);

    if (endButtonReading == 0) {
      delay(100);
      isTransporterActive = false;
    }
  } else {
    digitalWrite(enginePin, LOW);

    if (startButtonReading == 0) {
      delay(100);
      isTransporterActive = false;
    }
  }

  delay(100);
}
```
