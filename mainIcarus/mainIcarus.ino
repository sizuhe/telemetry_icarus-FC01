#include "SensorAnalog.h"
#include "IMUsensor.h"
#include "BMP180Sensor.h"
#include "GPSsensor.h"

SensorAnalog SensorVoltage(A0, 1000); 
IMUsensor IMUsensor;
BMP180Sensor BMPsensor;
GPSsensor gpssensor;

void setup() {
  Serial.begin(9600);

  BMPsensor.start();
  IMUsensor.start();
}

void loop() {
  IMUsensor.readData();
  SensorVoltage.update();
  BMPsensor.readData();
 
  gpssensor.update();
  gpssensor.printLocation();

  Serial.println(" X accel " + String(IMUsensor.readAx()) + ", Y accel " + String(IMUsensor.readAy()) + ", Z accel " + String(IMUsensor.readAz()) );
  Serial.println(" X gyro " + String(IMUsensor.readGx()) + ", Y gyro " + String(IMUsensor.readGy()) + ", Z gyro " + String(IMUsensor.readGz()));
  Serial.println(" Temperature " + String(BMPsensor.readTemp())+" °C " + ", Pressure " + String(BMPsensor.readPres()) + " Pa" );


  delay(1000);  // Esperar 1000ms antes de la siguiente lectura
}