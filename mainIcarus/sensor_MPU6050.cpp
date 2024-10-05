#include "sensor_MPU6050.h"



MPU6050_Custom::MPU6050_Custom() : mpu() {}


void MPU6050_Custom::init() {
  if (!mpu.begin()) {
    isInit = 0;
  } else {
    isInit = 1;
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(20);
}


// Get read data from library functions
void MPU6050_Custom::processData() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  ax = a.acceleration.x;
  ay = a.acceleration.y;
  az = a.acceleration.z;

  gx = g.gyro.x;
  gy = g.gyro.y;
  gz = g.gyro.z;
}


String MPU6050_Custom::readDataAccel() {
  String data = String(ax) + "," + String(ay) + "," + String(az) + ",";

  return data;
}


String MPU6050_Custom::readDataGyro(){
  String data = String(gx) + "," + String(gy) + "," + String(gz) + ",";

  return data;
}