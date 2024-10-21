#include "sensor_MPU6050.h"

const float RANGE_G = 2.0;
const float FACTOR_CONVERSION = RANGE_G / (pow(2, 16) / 2.0);



MPU6050_Custom::MPU6050_Custom() : mpu() {}


void MPU6050_Custom::init() {
  mpu.initialize();
  if (!mpu.testConnection()){
    isInit = 0;
  } else {
    isInit = 1;
  }

  /* ----- CALIBRATION VARIABLES ----- */
  mpu.setXAccelOffset(1317);
  mpu.setYAccelOffset(-81);
  mpu.setZAccelOffset(1147);

  delay(20);
}


// Get read data from library functions
String MPU6050_Custom::processData() {
  mpu.getAcceleration(&axRead, &ayRead, &azRead);

  ax = axRead * FACTOR_CONVERSION;
  ay = ayRead * FACTOR_CONVERSION;
  az = azRead * FACTOR_CONVERSION;

  String data = String(ax) + "," + String(ay) + "," + String(az) + ",";
  return data;
}