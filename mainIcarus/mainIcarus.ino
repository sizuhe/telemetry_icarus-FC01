#include "SensorAnalog.h"
#include "IMUsensor.h"
#include "BMP180Sensor.h"
#include "GPSsensor.h"
#include "ACS712.h"
#include "LoRaTransmitter.h"

SensorAnalog SensorVoltage(A0, 1000); 
IMUsensor IMUsensor;
BMP180Sensor BMPsensor;
GPSsensor gpssensor;
ACS712 sensorCurrent(A1,100);
LoRaTransmitter LoRaTransmit;
//const int ledVerde = 7;
//const int ledRojo = 8;



void setup() {
  Serial.begin(9600);

  BMPsensor.start();
  IMUsensor.start();
  sensorCurrent.begin();

  LoRaTransmit.setup();

  //pinMode(ledVerde, OUTPUT);
  //pinMode(ledRojo, OUTPUT);
}

void loop() {
  IMUsensor.readData();
  SensorVoltage.update();
  BMPsensor.readData();
 
  gpssensor.update();
  gpssensor.readData();

  sensorCurrent.readCurrent();

  // Serial.println("Lat "+String(gpssensor.readLat()) + ", Lng " + String(gpssensor.readLng()));
  // Serial.println(" Voltage " + String(SensorVoltage.volt()) );
  // Serial.println("Current " + String(sensorCurrent.getCurrent()) + "A");
  
  String dataAccel = IMUsensor.readAccel()+ IMUsensor.readGyro();
  String dataBMP = BMPsensor.readValues();
  String dataVoltage = SensorVoltage.readVoltage();
  String dataCurrent = sensorCurrent.readCurrent();
  String dataGPS = gpssensor.readLat()+ gpssensor.readLng();
  String dataPacket = dataAccel + dataBMP + dataVoltage + dataCurrent;
  // LoRaTransmit.sendData(dataPacket);

  //digitalWrite(ledVerde, HIGH); 
  //digitalWrite(ledRojo, LOW);   
  //delay(1000);
  //digitalWrite(ledVerde, LOW);  
  //digitalWrite(ledRojo, HIGH);  
  //delay(1000);
}