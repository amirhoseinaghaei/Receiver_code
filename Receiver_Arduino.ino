#include <SPI.h>

#include <LoRa.h>



void setup() {

  Serial.begin(9600);



  while (!Serial);

  Serial.println("LoRa Receiver");

  if (!LoRa.begin(434E6)) {

    Serial.println("Starting LoRa failed!");

    while (1);

  }

}

void loop() {

  // try to parse packet
  
  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    Serial.print("Received packet '");

    // read packet

    while (LoRa.available()) {

      char incoming = (char)LoRa.read();
      Serial.print(incoming);
      


    }

  }
}
