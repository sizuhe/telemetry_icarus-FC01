//-----LIBRARIES-----
#include <Adafruit_BMP085.h>
#include "IMUsensor.h"
#include <Wire.h>
#include <Arduino.h>



//-----CLASSES AND METHODS-----
IMUsensor::IMUsensor() : mpu() {}

void IMUsensor::start() {
    Wire.begin();
    mpu.initialize();
    if (mpu.testConnection()) {
        Serial.println("MPU6050 successfully connected");
    } else {
        Serial.println("Error connecting to MPU6050");
    }
}

void IMUsensor::readData() {
  mpu.getAcceleration(&ax, &ay, &az); 
  mpu.getRotation(&gx, &gy, &gz); 
}

//-----READ ACCELERATION AND GYRO-----
float IMUsensor::readAx() {
  return ax;
}
float IMUsensor::readAy() {
  return ay;
}
float IMUsensor::readAz() {
  return az;
}

float IMUsensor::readGx(){
  return gx;
}
float IMUsensor::readGy(){
  return gy;
}
float IMUsensor::readGz(){
  return gz;
}