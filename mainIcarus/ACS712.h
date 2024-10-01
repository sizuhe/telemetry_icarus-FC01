#ifndef ACS712_H
#define ACS712_H

//-----LIBRARY-----
#include <Arduino.h>



class ACS712 {
public:
    
    ACS712(uint8_t pin, float sensitivity);
    void begin();
    String readCurrent();

private:
    uint8_t _pin;           
    float _sensitivity;     
    const float VREF = 5.0;
    const int ADC_RES = 1024; 
    const int ADC_MID = ADC_RES / 2; 
};

#endif