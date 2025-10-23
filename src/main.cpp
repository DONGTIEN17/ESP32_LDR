#include <Arduino.h>

const int ledPin = 27;
const int ldrPin = 34;

const int threshold = 1500;

void setup() {

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  pinMode(ldrPin, INPUT);

  digitalWrite(ledPin, LOW);
}

void loop() {

  int ldrValue = analogRead(ldrPin);

  int ledState = 0; 

  if (ldrValue < threshold) {

    digitalWrite(ledPin, HIGH); 
    ledState = 1; 
  } else {

    digitalWrite(ledPin, LOW); 
    ledState = 0; 
  }

  Serial.print(">ldr:");
  Serial.println(ldrValue);

  Serial.print(">led:");
  Serial.println(ledState);

  delay(100);
}