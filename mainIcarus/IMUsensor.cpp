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
String IMUsensor::readAccel() {
  String packet = String(ax)+","+ String(ay)+"," + String(az)+",";
  return packet;
}

String IMUsensor::readGyro(){
  String packet = String(gx)+","+ String(gy)+"," + String(gz)+",";
  return packet;

}
