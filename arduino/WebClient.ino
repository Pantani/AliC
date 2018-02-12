/*
  Web client

 This sketch connects to a website (http://www.google.com)
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe, based on work by Adrian McEwen

 */

#include <SPI.h>
// extern "C" {
//   #include "alic.h"
// }


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  
}

void loop() {
  
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // personalSendDataContract("0x1b93082ff44d4de400d31196d99f14b7fd37d128", 
  // "0x3D99982E7686b0BA4D2E06C25163317aBF71caE8", 
  // "0x6463f4370000000000000000000000000000000000000000000000000000000000000001", "123");

  Serial.println("disconnecting.");
}

