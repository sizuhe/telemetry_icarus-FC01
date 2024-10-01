#ifndef SENSORANALOG_H
#define SENSORANALOG_H

#include <Arduino.h>



class SensorAnalog {
  private:
    int pinvcc;
    unsigned long interval;
    unsigned long previousMillis;
    float voltage;

  public:
    SensorAnalog(int pinvcc, unsigned long sampleinterval);
    void update();
    void Readvoltage();
    float volt();
   
};

#endif