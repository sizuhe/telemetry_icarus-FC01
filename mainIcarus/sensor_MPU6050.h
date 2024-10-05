#ifndef MPU6050_CUSTOM_H
#define MPU6050_CUSTOM_H

#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>



class MPU6050_Custom {
  public:
    MPU6050_Custom();

    void init();
    void processData();
    String readDataAccel();
    String readDataGyro();

    bool isInit;

      
  private:
    float ax, ay, az;
    float gx, gy, gz;

    Adafruit_MPU6050 mpu;
};

#endif