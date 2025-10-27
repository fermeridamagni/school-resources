# Practice 10 - Button-Controlled LED Intermittence

## Overview

This practice implements a button-controlled LED system with different blinking patterns. Two buttons control two LEDs, each with distinct intermittence patterns (fast and slow), demonstrating user input handling and state management.

## Objectives

- Learn to read button inputs with pull-up resistors
- Implement different LED blinking patterns
- Manage state variables for intermittence control
- Practice function-based code organization
- Handle button state transitions

## Hardware Components

- Arduino board
- Button 1 on pin 5 (with INPUT_PULLUP)
- Button 2 on pin 6 (with INPUT_PULLUP)
- LED 1 on pin 8 (short intermittence)
- LED 2 on pin 7 (long intermittence)
- Current-limiting resistors for LEDs
- Breadboard and jumper wires

## Functionality

### Button Controls

- **Button 1**: Activates short LED intermittence (100ms on)
- **Button 2**: Activates long LED intermittence (1000ms on)
- Buttons are mutually exclusive (pressing one deactivates the other)

### LED Patterns

- **LED 1 (Short)**: Blinks with 100ms ON period
- **LED 2 (Long)**: Blinks with 1000ms ON period

### Operation Flow

1. System reads both button states continuously
2. When Button 1 is pressed:
   - Activates short intermittence on LED 1
   - Deactivates long intermittence on LED 2
3. When Button 2 is pressed:
   - Activates long intermittence on LED 2
   - Deactivates short intermittence on LED 1
4. Serial Monitor displays button readings for debugging

## Key Features

- **INPUT_PULLUP**: Uses internal pull-up resistors (button pressed = LOW)
- **Mutual Exclusion**: Only one pattern active at a time
- **Function-Based Design**: Separate functions for each intermittence pattern
- **State Management**: Uses boolean flags to track active pattern
- **Debug Output**: Serial Monitor shows button states

## Usage

1. Upload the sketch to your Arduino board
2. Open Serial Monitor at 9600 baud
3. Press Button 1 to see short LED blinking (fast)
4. Press Button 2 to see long LED blinking (slow)
5. Monitor button readings in Serial Monitor

## Circuit Connections

| Component  | Arduino Pin | Notes                    |
|-----------|-------------|--------------------------|
| Button 1  | 5           | Uses INPUT_PULLUP        |
| Button 2  | 6           | Uses INPUT_PULLUP        |
| LED 1     | 8           | Fast blink pattern       |
| LED 2     | 7           | Slow blink pattern       |

**Button Wiring**: With INPUT_PULLUP, connect one button terminal to the pin and the other to GND. No external resistor needed.

## Teaching Concepts

- **Input Pull-up Resistors**: Understanding internal pull-ups
- **Button Debouncing**: Basic input reading (can be enhanced)
- **State Variables**: Using flags to control behavior
- **Function Abstraction**: Breaking code into reusable functions
- **Mutual Exclusion**: Ensuring only one state is active
- **Serial Debugging**: Using Serial Monitor for troubleshooting

## Possible Enhancements

- Add button debouncing for more reliable operation
- Implement toggle instead of momentary activation
- Add more LEDs and patterns
- Create a selection menu with multiple modes

## Code

```cpp
/**
 * @file practice-10.ino
 * @author fermeridamagni
 * @date 2025-10-22
 * @description Button-controlled LED intermittence system. Two buttons control different LED blinking patterns (short 100ms and long 1000ms intervals).
 */

const int button1Pin = 5;
const int button2Pin = 6;

const int led1Pin = 8;
const int led2Pin = 7;

int isShortLedIntermittenceActive = 0;
int isSLongLedIntermittenceActive = 0;

void shortLedIntermittence(int active) {
  if (active == 1) {
    digitalWrite(led1Pin, HIGH);
    delay(100);
    digitalWrite(led1Pin, LOW);
  } else {
    digitalWrite(led1Pin, LOW);
  }
}

void longLedIntermittence(int active) {
  if (active == 1) {
    digitalWrite(led2Pin, HIGH);
    delay(1000);
    digitalWrite(led2Pin, LOW);
  } else {
    digitalWrite(led2Pin, LOW);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  int button1Reading = digitalRead(button1Pin);
  int button2Reading = digitalRead(button2Pin);

  Serial.println("-----------------");
  Serial.print("Button 1 Reading: ");
  Serial.print(button1Reading);
  Serial.println();

  Serial.print("Button 2 Reading: ");
  Serial.print(button2Reading);
  Serial.println();

  if (!button1Reading) {
    isShortLedIntermittenceActive = 1;
    isSLongLedIntermittenceActive = 0;
  }

  if (!button2Reading) {
    isSLongLedIntermittenceActive = 1;
    isShortLedIntermittenceActive = 0;
  }

  if (isShortLedIntermittenceActive) {
    shortLedIntermittence(1);
    longLedIntermittence(0);
  } else {
    shortLedIntermittence(0);
  }

  if (isSLongLedIntermittenceActive) {
    longLedIntermittence(1);
    shortLedIntermittence(0);
  } else {
    longLedIntermittence(0);
  }

  delay(100);  // short delay
}
```
