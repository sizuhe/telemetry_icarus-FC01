#ifndef GPSSENSOR_H
#define GPSSENSOR_H

#include <TinyGPS++.h>
#include <Arduino.h>



class GPSsensor {
  private:
    TinyGPSPlus gps;
    float lat;
    float lng; 

  public:
    GPSsensor();  
    void update();  
    void printLocation();
    float readLat();
    float readLng();
};

#endif