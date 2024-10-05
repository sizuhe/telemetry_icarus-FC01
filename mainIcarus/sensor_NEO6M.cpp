#include "sensor_NEO6M.h"

static int serial_putc(const char c, FILE *stream) { return Serial.write(c); }
static FILE *serial_stream = fdevopen(serial_putc, NULL);



NEO6M::NEO6M(int pinrx, int pintx, int baudrate) : _PIN_RX_ARDUINO(pinrx), _PIN_TX_ARDUINO(pintx), _BAUDRATE_GPS(baudrate), GPS_Serial(_PIN_RX_ARDUINO, _PIN_TX_ARDUINO) {}


void NEO6M::init() {
  GPS_Serial.begin(_BAUDRATE_GPS);

  Serial.println(F("NEO6M correct initialization"));
  delay(20);
}


void NEO6M::decodeGPSdata(char* packet) {
  sscanf(packet, 
    "$GPGGA,%9[^,],%10[^,],%c,%11[^,],%c,%*[^,],%*[^,],%*[^,],%6[^,],%*[^,],%6[^,]",
    dataGPS.time, dataGPS.latitude, &dataGPS.latitudeDir,
    dataGPS.longitude, &dataGPS.longitudeDir, dataGPS.altitude, dataGPS.altitudeMSL);

  sscanf(packet, 
    "$GPRMC,%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%6[^,]",
    dataGPS.speedGround);
}


void NEO6M::processData() {
  static uint8_t index = 0;
  char dataPacket[82];
  isNew = false;

  while (GPS_Serial.available() > 0) {
    char GPS_packet = GPS_Serial.read();

    if (GPS_packet != '\n') {
      dataPacket[index++] = GPS_packet;
    } else {
      dataPacket[index] = '\0';   // Termination character
      index = 0;

      decodeGPSdata(dataPacket);

      if (strncmp(dataPacket, "$GPGGA", 6) == 0) {
        isNew = true;
        data = String(dataGPS.time) + "," + String(dataGPS.latitude) + "," + String(dataGPS.latitudeDir) + "," + 
          String(dataGPS.longitude) + "," + String(dataGPS.longitudeDir) + "," + String(dataGPS.altitude) + "," + 
          String(dataGPS.altitudeMSL) + "," + String(dataGPS.speedGround);

        // break;
      }
    }
  }
}