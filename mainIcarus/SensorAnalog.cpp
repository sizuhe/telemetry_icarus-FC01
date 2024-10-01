//-----LIBRARIES-----
#include "SensorAnalog.h"
#include <Arduino.h>



//-----CLASSES AND METHODS-----
SensorAnalog::SensorAnalog(int pinvcc, unsigned long sampleinterval) {
  this->pinvcc = pinvcc;
  interval = sampleinterval;
  previousMillis = 0;
  voltage = 0;
  pinMode(pinvcc, INPUT);
}

void SensorAnalog::update() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Readvoltage();
  }
}

void SensorAnalog::Readvoltage() {
  int readvoltage = analogRead(pinvcc);
  voltage = readvoltage * (25.0 / 1023.0);
  //-----PRINT DATA ON SERIAL MONITOR-----
  //Serial.print("Current voltage is: "); Serial.print(voltage); Serial.print("V"); 
}

float SensorAnalog::volt(){
  return voltage;
}
