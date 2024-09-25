//-----LIBRARIES-----
#include "BMP180Sensor.h"
#include <Adafruit_BMP085.h>
#include <Arduino.h>



//-----CLASSES AND METHODS-----
BMP180Sensor::BMP180Sensor() {}

void BMP180Sensor::start() {
    if (!bmp.begin()) {
        Serial.println("Error connecting to BMP180");
    } else {
        Serial.println("BMP180 successfully connected");
    }
}

void BMP180Sensor::readData() {
    if (bmp.begin()) {
         temperature = bmp.readTemperature();
         pressure = bmp.readPressure();
    } else {
        Serial.println("BMP180 reading failure");
    }
}

//-----READ TEMPERATURE AND PRESSURE -----
float BMP180Sensor::readTemp(){
  return temperature;
}

float BMP180Sensor::readPres(){
  return pressure;
}