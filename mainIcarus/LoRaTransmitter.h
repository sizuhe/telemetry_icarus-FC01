#ifndef LORA_TRANSMITTER_H
#define LORA_TRANSMITTER_H

#include <SPI.h>
#include <LoRa.h>

#define DEBUG 1
#if DEBUG == 1
  #define debug(x) {Serial.print(x); delay(10);}
  #define debugln(x) {Serial.println(x); delay(10);}
#else
  #define debug(x)
  #define debugln(x)
#endif

#define BAUDRATE 9600
#define LORA_FREQ 433E6
#define LORA_SYNC 0xAF


class LoRaTransmitter {
public:
    void setup();
    void loop();

private:
    void initLoRa();
};

#endif // LORA_TRANSMITTER_H
