#include <SoftwareSerial.h>

//SoftwareSerial mySerial(14, 15); // RX, TX for WNPink
SoftwareSerial mySerial(16, 10); // RX, TX for ProMicro

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }
  mySerial.begin(9600);
}

void loop() {
  byte command[] = {
    0xFF,  // Byte 0
    0x01,  // Byte 1
    0x86,  // Byte 2
    0x00,  // Byte 4
    0x00,  // Byte 5
    0x00,  // Byte 6
    0x00,  // Byte 7
    0x00,  // Byte 8
    0x79   // Byte 9
  };
  mySerial.write(command, sizeof(command));

  delay(100);

  int c = 0;
  int message[9];

  while (mySerial.available()) {
    int b = mySerial.read();
    if ((c == 0 && b == 0xFF) || (c >= 1 && c <= 8)) {
      message[c] = b;
      c++;
    }
  }

  int high_byte = message[2];
  int low_byte = message[3];
  int value = high_byte * 256 + low_byte;
  Serial.print("co2=");
  Serial.println(value, DEC);

  delay(900);
}
