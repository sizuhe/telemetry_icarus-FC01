#include "SensorAnalog.h"
#include "IMUsensor.h"
#include "BMP180Sensor.h"
#include "GPSsensor.h"
#include "ACS712.h"

SensorAnalog SensorVoltage(A0, 1000); 
IMUsensor IMUsensor;
BMP180Sensor BMPsensor;
GPSsensor gpssensor;
ACS712 sensorCurrent(A1,100);
//const int ledVerde = 7;
//const int ledRojo = 8;



void setup() {
  Serial.begin(9600);

  BMPsensor.start();
  IMUsensor.start();
  sensorCurrent.begin();

  //pinMode(ledVerde, OUTPUT);
  //pinMode(ledRojo, OUTPUT);
}

void loop() {
  IMUsensor.readData();
  SensorVoltage.update();
  BMPsensor.readData();
 
  gpssensor.update();
  gpssensor.printLocation();

  sensorCurrent.getCurrent();

  Serial.println(" X accel " + String(IMUsensor.readAx()) + ", Y accel " + String(IMUsensor.readAy()) + ", Z accel " + String(IMUsensor.readAz()) );
  Serial.println(" X gyro " + String(IMUsensor.readGx()) + ", Y gyro " + String(IMUsensor.readGy()) + ", Z gyro " + String(IMUsensor.readGz()));
  Serial.println(" Temperature " + String(BMPsensor.readTemp())+" °C " + ", Pressure " + String(BMPsensor.readPres()) + " Pa" );
  Serial.println("Lat "+String(gpssensor.readLat()) + ", Lng " + String(gpssensor.readLng()));
  Serial.println(" Voltage " + String(SensorVoltage.volt()) );
  Serial.println("Current " + String(sensorCurrent.getCurrent()) + "A");

  //digitalWrite(ledVerde, HIGH); 
  //digitalWrite(ledRojo, LOW);   
  //delay(1000);
  //digitalWrite(ledVerde, LOW);  
  //digitalWrite(ledRojo, HIGH);  
  //delay(1000);

  delay(1000);
}