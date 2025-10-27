/**
 * @file main.ino
 * @author fermeridamagni
 * @date 2025-10-22
 * @description Simple LED sequence controller with buzzer. Cycles through blue, green, and yellow LEDs with 1-second delays, and generates a 1KHz tone on the buzzer.
 */

const int blueLed = 8;
const int greenLed = 7;
const int yellowLed = 4;

const int buzzer = 12;

void setup() {
  Serial.begin(115200);

  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(blueLed, HIGH);
  delay(1000);
  digitalWrite(blueLed, LOW);
  delay(1000);

  digitalWrite(greenLed, HIGH);
  delay(1000);
  digitalWrite(greenLed, LOW);
  delay(1000);

  digitalWrite(yellowLed, HIGH);
  delay(1000);
  digitalWrite(yellowLed, LOW);
  delay(1000);

  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1 sec
}
