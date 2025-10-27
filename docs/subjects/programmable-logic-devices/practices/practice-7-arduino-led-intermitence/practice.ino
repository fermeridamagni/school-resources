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
