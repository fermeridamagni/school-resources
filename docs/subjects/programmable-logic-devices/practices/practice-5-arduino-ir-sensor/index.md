# Practice 8 - Analog Sensor Reader with LED Indicator

## Overview

This practice demonstrates analog sensor reading and threshold-based LED control. The system reads an analog sensor value and activates an LED when the reading falls below a specified threshold.

## Objectives

- Learn analog input reading with Arduino
- Implement threshold-based logic
- Display sensor data via Serial Monitor
- Practice conditional output control

## Hardware Components

- Arduino board
- Analog sensor on pin A0 (e.g., photoresistor, potentiometer, etc.)
- LED on pin 7
- Current-limiting resistor for LED
- Breadboard and jumper wires

## Functionality

The system operates as follows:

1. Reads analog value from sensor on pin A0 (0-1023 range)
2. Compares reading to threshold (100)
3. If reading < 100:
   - Turns LED ON
4. If reading ≥ 100:
   - Turns LED OFF
5. Displays reading to Serial Monitor
6. Repeats with 200ms delay

## Key Features

- **Analog Reading**: Uses Arduino's ADC (0-1023 range)
- **Threshold Detection**: Simple binary decision based on sensor value
- **Serial Output**: Real-time sensor value monitoring
- **Fast Response**: 200ms update rate
- **Flexible Input**: Works with various analog sensors

## Usage

1. Connect your analog sensor to pin A0
2. Upload the sketch to your Arduino board
3. Open Serial Monitor at 9600 baud
4. Adjust sensor input (e.g., cover photoresistor, turn potentiometer)
5. Observe LED turning on when reading drops below 100
6. Monitor sensor readings in Serial Monitor

## Circuit Connections

| Component      | Arduino Pin |
|---------------|-------------|
| Analog Sensor | A0          |
| LED           | 7           |

## Configuration

To adjust the threshold, modify the comparison value in the code:

```cpp
if (reading < 100) {  // Change 100 to your desired threshold
  digitalWrite(ledPin, HIGH);
}
```

## Suggested Sensors

This code works with various analog sensors:

- **Photoresistor**: Light-dependent resistor
- **Potentiometer**: Manual variable resistor
- **Temperature sensor**: Analog temperature readings
- **Moisture sensor**: Soil or humidity sensing

## Teaching Concepts

- Analog-to-Digital Conversion (ADC)
- Threshold-based control
- Serial communication
- Sensor interfacing
- Conditional logic

## Code

```cpp
/**
 * @file practice-8.ino
 * @author fermeridamagni
 * @date 2025-10-22
 * @description Analog sensor reader that activates an LED when the sensor reading falls below a threshold of 100.
 */

const int sensorPin = A0;
const int ledPin = 7;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}


void loop() {
  int reading = analogRead(sensorPin);

  if (reading < 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
   
  Serial.print("Reading: ");
  Serial.print(reading);
  Serial.println();

  delay(200);
}
```
