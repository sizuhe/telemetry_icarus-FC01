#ifndef MPU6050_CUSTOM_H
#define MPU6050_CUSTOM_H

#include <Arduino.h>
#include "MPU6050.h"



class MPU6050_Custom {
  public:
    MPU6050_Custom();

    void init();
    String processData();

    bool isInit;

      
  private:
    int16_t axRead, ayRead, azRead;
    float ax, ay, az;
    MPU6050 mpu;
};

#endif