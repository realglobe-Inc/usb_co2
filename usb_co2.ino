void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }
}

void loop() {
  int value = 0;

  value = usb_mhz14a_get_co2();

  Serial.print("co2=");
  Serial.println(value, DEC);

  delay(900);
}
