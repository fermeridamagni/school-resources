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