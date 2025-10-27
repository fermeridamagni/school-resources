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