# Practice 5 - Intelligent Security System (ESP32)

## Overview

This practice implements an intelligent security system using an ESP32 microcontroller. The system monitors a door sensor (reed switch) and a sound sensor to detect potential security breaches, triggering a pre-alarm sequence followed by a full alarm if not deactivated.

## Objectives

- Learn to interface with reed switches and sound sensors
- Implement state machine logic for alarm systems
- Use timing functions for pre-alarm and alarm states
- Control multiple outputs (LEDs, buzzer, relay)
- Practice ESP32 programming

## Hardware Components

- ESP32 development board
- Reed switch (magnetic door sensor) on pin 34
- Sound sensor on pin 35 (ADC1_CH6)
- Buzzer (active or PWM capable) on pin 23
- Relay on pin 27
- LED 1 on pin 19
- LED 2 on pin 5
- LED 3 on pin 17
- Breadboard and jumper wires

## Functionality

The system operates in two states:

### Normal State

- Monitors door sensor and sound sensor
- When triggered by door opening or loud sound:
  - Enters pre-alarm state
  - Starts 20-second countdown

### Pre-alarm State (20 seconds)

- Displays LED sequence animation
- Checks if door is closed (reed switch deactivated)
- If door closes: cancels alarm, returns to normal state
- If 20 seconds elapse without deactivation:
  - Activates full alarm
  - Turns on buzzer
  - Activates relay (can control external devices)

## Key Features

- **Dual Trigger Detection**: Reed switch and sound sensor
- **Pre-alarm Grace Period**: 20 seconds to deactivate before full alarm
- **Visual Feedback**: Sequential LED animation during pre-alarm
- **Audio Alert**: Buzzer activation in full alarm state
- **Relay Control**: Can trigger external security devices
- **Adjustable Threshold**: Sound sensitivity can be tuned

## Usage

1. Upload the sketch to your ESP32 board
2. Open Serial Monitor at 115200 baud
3. Test by opening the door (activating reed switch)
4. Observe LED sequence during pre-alarm
5. Close door within 20 seconds to cancel, or wait for full alarm
6. Test sound trigger by making loud noise near sensor

## Circuit Connections

| Component     | ESP32 Pin |
|--------------|-----------|
| Reed Switch  | 34        |
| Sound Sensor | 35        |
| Buzzer       | 23        |
| Relay        | 27        |
| LED 1        | 19        |
| LED 2        | 5         |
| LED 3        | 17        |

## Configuration

Adjust the sound detection threshold by modifying the value in the code:

```cpp
return (soundLevel > 2000); // Adjust threshold as needed
```

## Teaching Concepts

- State machine implementation
- Timing and delays in embedded systems
- Digital and analog sensor reading
- Pull-up resistor configuration
- Relay control for external devices

## Code

```cpp
/**
 * @file main.ino
 * @author fermeridamagni
 * @date 2025-10-22
 * @description Intelligent security system using ESP32. Monitors door sensor (reed switch) and sound sensor to trigger pre-alarm and full alarm states with LED sequences and buzzer/relay activation.
 */

/**
 * Sistema de Seguridad Inteligente - ESP32
 * Cuando el sensor de puerta (reed switch) se activa o el sensor de sonido detecta un ruido fuerte,
 * el sistema entra en un estado de prealarma durante 20 segundos, indicado por una secuencia de LEDs.
 * Si no se desactiva la prealarma (por ejemplo, cerrando la puerta) dentro de este tiempo,
 * se activa la alarma completa, encendiendo un buzzer y un relé.
 */

const int reedPin = 34;  // Reed switch
const int soundPin = 35; // Sensor de sonido (ADC1_CH6)
const int buzzerPin = 23; // Buzzer (activo) o PWM si es pasivo (ledc)
const int relayPin = 27;

const int led1 = 19;
const int led2 = 5;
const int led3 = 17;

bool alarmActive = false;
unsigned long alarmStartTime = 0;

void setup() {
  Serial.begin(115200);

  pinMode(reedPin, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(relayPin, LOW);
}

bool hasReedActivated() {
  int reading = digitalRead(reedPin);

  // El reed switch está activo cuando la lectura es LOW (circuito cerrado)
  return (reading == LOW);
}

bool hasSoundDetected() {
  int soundLevel = analogRead(soundPin);
  return (soundLevel > 2000); // Umbral ajustable
}

void ledsSequence() {
  int timer = 100;
  int pinCount = 3;
  int leds[] = { led1, led2, led3 };

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    digitalWrite(leds[thisPin], HIGH);
    delay(100);
    digitalWrite(leds[thisPin], LOW);
  }
}

void stopAllAlarmOutputs() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  
  if (!alarmActive) {
    // Si el reed switch se activa o se detecta un sonido fuerte, iniciar prealarma
    bool reed = hasReedActivated();
    bool sound = hasSoundDetected();

    if (reed || sound) {
      alarmActive = true;
      alarmStartTime = millis();
      Serial.println("Prealarma activada");
    }
  } else {
    // Durante la prealarma, mostrar secuencia de LEDs
    ledsSequence();

    // Si el reed switch se desactiva, cancelar la alarma
    if (!reed) {
      alarmActive = false;
      stopAllAlarmOutputs();
      Serial.println("Alarma cancelada");
    } else {
      // Si han pasado más de 20 segundos, activar la alarma completa
      if (millis() - alarmStartTime > 20000) {
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(relayPin, HIGH);
        Serial.println("Alarma completa activada");
      }
    }
  }

  // pequeño retardo cooperativo (no bloquear)
  delay(10);
}
```
