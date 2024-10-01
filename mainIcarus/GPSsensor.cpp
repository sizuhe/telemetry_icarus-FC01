//-----LIBRARIES-----
#include "GPSsensor.h"



//-----CLASSES AND METHODS-----
GPSsensor::GPSsensor() {}

void GPSsensor::update() {
  while (Serial.available() > 0) {  
    gps.encode(Serial.read());      
    if (gps.location.isUpdated()) {  
      printLocation();               
    }
  }
}

void GPSsensor::printLocation() {
  lat = gps.location.lat();
  lng = gps.location.lng();

  //Serial.print("Latitude= ");
  //Serial.print(gps.location.lat(), 6);
  //Serial.print(" Longitude= ");
  //Serial.println(gps.location.lng(), 6);
}

float GPSsensor::readLat(){
  return lat;
}
float GPSsensor::readLng(){
  return lng;
}