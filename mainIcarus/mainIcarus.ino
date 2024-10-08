#include "sensor_ACS712.h"
#include "sensor_BMP180.h"
#include "sensor_FZ0430.h"
#include "sensor_MPU6050.h"
#include "sensor_NEO6M.h"
#include "transmitter_LoRa.h"

#define PIN_LED_GREEN 8
#define PIN_LED_RED 7

String dataGPS = "0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0";

ACS712 sensorCurrent(A1, 100, 5.0);
BMP180 sensorBMP;
FZ0430 sensorVoltage(A0, 25.0); 
MPU6050_Custom sensorIMU;
NEO6M sensorGPS(4, 3, 9600);
// LoRaTransmitter LoRaTransmit;



void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);

  sensorCurrent.init();
  // sensorBMP.init();
  sensorVoltage.init();
  sensorIMU.init();
  sensorGPS.init();

  // if (!sensorBMP.isInit) {
  //   ledLoop();
  //   while(1);
  // }
  if (!sensorIMU.isInit) {
    ledLoop();
    ledLoop();
    while(1);
  }

  digitalWrite(PIN_LED_GREEN, HIGH);
  delay(1000);
  digitalWrite(PIN_LED_GREEN, LOW);
}

void ledLoop() {
  digitalWrite(PIN_LED_RED, HIGH);
  delay(500);
  digitalWrite(PIN_LED_RED, LOW);
  delay(500);
}

/* -------------------------------------------------- */

void loop() {
  // BMP IS SLOW AS FUCK
  // Enviar de datos en menos de 1 seg (se envian cada seg)
  
  // String dataBMP = sensorBMP.readData();

  // ----- UNSTABLE WAY -----
  sensorCurrent.processData();
  // sensorBMP.processData();
  sensorVoltage.processData();
  sensorIMU.processData();
  
  sensorGPS.processData();
  if (sensorGPS.isNew) {
    dataGPS = sensorGPS.data;

    // ----- BELOW IS THE MOST STABLE WAY -----
    // If sensors are read here it doesnt hang up
    // String dataCurrent = sensorCurrent.readData();
    // String dataAccel = sensorIMU.readDataAccel() + sensorIMU.readDataGyro();
    // String dataVoltage = sensorVoltage.readData();

    // String dataPacket = dataCurrent + dataAccel + dataVoltage + sensorGPS.data;

    // Serial.println(dataPacket);
  }

  String dataCurrent = sensorCurrent.readData();
  String dataAccel = sensorIMU.readDataAccel();
  String dataVoltage = sensorVoltage.readData();

  String dataPacket = dataCurrent + dataVoltage + dataGPS;

  Serial.println(dataPacket);
}