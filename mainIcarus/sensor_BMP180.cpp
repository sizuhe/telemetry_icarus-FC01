#include "sensor_BMP180.h"



BMP180::BMP180() : temperature(0.0), pressure(0.0) {}


void BMP180::init() {
  if (!bmp.begin()) {
    isInit = 0;
  } else {
    isInit = 1;
  }

  delay(20);
}


// Get read data from library functions
void BMP180::processData() {
  temperature = bmp.readTemperature();
  pressure = bmp.readAltitude();
}


String BMP180::readData() {
  String data = String(temperature) + "," + String(pressure) + ",";

  return data;
}