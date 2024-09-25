#ifndef BMP180SENSOR_H
#define BMP180SENSOR_H

//-----LIBRARY-----
#include <Adafruit_BMP085.h>



class BMP180Sensor {
    public:
        BMP180Sensor();  
        void start();    
        void readData();
        float readTemp();
        float readPres(); 
        
    private:
        Adafruit_BMP085 bmp;
        float temperature;
        float pressure;
};

#endif // BMP180SENSOR_H