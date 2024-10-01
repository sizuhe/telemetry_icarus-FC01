#include "LoRaTransmitter.h"

void LoRaTransmitter::setup() {
    Serial.begin(BAUDRATE);
    initLoRa();
}

void LoRaTransmitter::initLoRa() {

    if (!LoRa.begin(LORA_FREQ)) {
        debugln("LoRa init failed");
    }
    LoRa.setSyncWord(LORA_SYNC);
    LoRa.setSpreadingFactor(10);
    LoRa.setSignalBandwidth(250E3);
}

void LoRaTransmitter::loop() {
    String dataPacket = "25.09, 60.56, 30.42, 40.10, 80.08, 50, 60, Buenas tardes";

    LoRa.beginPacket();
    LoRa.print(dataPacket);
    LoRa.endPacket();

    debugln(sizeof(dataPacket));
}
