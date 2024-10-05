#ifndef NEO6M_H
#define NEO6M_H

#include <Arduino.h>
#include <SoftwareSerial.h>



// Instance receives the mcu rx pin, mcu tx pin and gps baudrate.
class NEO6M {
  public:
    NEO6M(int pinrx, int pintx, int baudrate);

    void init();
    void processData();

    bool isNew;
    String data;


  private:
    void decodeGPSdata(char* packet);

    const int _BAUDRATE_GPS, _PIN_RX_ARDUINO, _PIN_TX_ARDUINO;

    struct GPSData {
      char time[10];
      char latitude[11];
      char latitudeDir;
      char longitude[12];
      char longitudeDir;
      char altitude[7];
      char altitudeMSL[7];
      char speedGround[7];
    };

    GPSData dataGPS;
    SoftwareSerial GPS_Serial;
};

#endif