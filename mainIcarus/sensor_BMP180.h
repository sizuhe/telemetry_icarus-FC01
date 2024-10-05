#ifndef BMP180_H
#define BMP180_H

#include <Arduino.h>
#include <Adafruit_BMP085.h>



class BMP180 {
  public:
    BMP180();

    void init();
    void processData();
    String readData();

    bool isInit;
      

  private:
    float temperature, pressure;

    Adafruit_BMP085 bmp;
};

#endif