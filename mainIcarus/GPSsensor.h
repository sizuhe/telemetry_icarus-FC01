#ifndef GPSSENSOR_H
#define GPSSENSOR_H

#include <TinyGPS++.h>
#include <Arduino.h>



class GPSsensor {
  private:
    TinyGPSPlus gps; 

  public:
    GPSsensor();  
    void update();  
    void printLocation();  
};

#endif