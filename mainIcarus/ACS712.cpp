#include "ACS712.h"



//-----CLASSES AND METHODS-----
ACS712::ACS712(uint8_t pin, float sensitivity) {
    _pin = pin;
    _sensitivity = sensitivity;
}


void ACS712::begin() {
    pinMode(_pin, INPUT);
}


String ACS712::readCurrent() {
    int rawValue = analogRead(_pin); 
    float voltage = (rawValue / (float)ADC_RES) * VREF; 
    float offsetVoltage = VREF / 2; 
    float current = (voltage - offsetVoltage) / (_sensitivity / 1000.0); 
    return String(current);
}