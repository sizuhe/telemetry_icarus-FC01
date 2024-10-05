// #include "transmitter_LoRa.h"

// void LoRaTransmitter::setup() {
//     initLoRa();
// }

// void LoRaTransmitter::initLoRa() {

//     if (!LoRa.begin(LORA_FREQ)) {
//         debugln("LoRa init failed");
//     }
//     LoRa.setSyncWord(LORA_SYNC);
//     LoRa.setSpreadingFactor(7);
//     LoRa.setSignalBandwidth(500E3);
// }

// void LoRaTransmitter::sendData(String Data) {
//     LoRa.beginPacket();
//     LoRa.print(Data);
//     LoRa.endPacket();
// }
