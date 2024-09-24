#ifndef IMUSENSOR_H
#define IMUSENSOR_H

#include <Wire.h>
#include <MPU6050.h>

class IMUsensor {
public:
    IMUsensor();
    void start();
    void readData();
    float readAx();
    float readAy();
    float readAz();
    float readGx();
    float readGy();
    float readGz();
    
private:
    MPU6050 mpu;
    int16_t ax, ay, az; //-----ACCELERATION-----
    int16_t gx, gy, gz; //-----GYROSCOPE------
};

#endif // IMUSENSOR_H