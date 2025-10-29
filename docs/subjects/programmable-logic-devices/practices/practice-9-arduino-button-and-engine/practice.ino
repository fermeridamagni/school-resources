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
