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
