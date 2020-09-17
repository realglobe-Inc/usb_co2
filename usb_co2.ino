#define LED_ON LOW
#define LED_OFF HIGH
#define PIN_SW1 3
#define PIN_SW2 2
#define STATUS_OK 0

void setup() {
  digitalWrite(LED_BUILTIN, LED_OFF);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_SW1, INPUT);
  pinMode(PIN_SW2, INPUT);

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }

  usb_mhz14a_init();
/*
  if( digitalRead( PIN_SW1 ) ){
    digitalWrite(LED_BUILTIN, LED_ON);
    usb_mhz14a_zero_calibration();
    digitalWrite(LED_BUILTIN, LED_OFF);
  }
*/
  digitalWrite(LED_BUILTIN, LED_ON);
}

void loop() {
  int value = 0;

  value = usb_mhz14a_get_co2();

  Serial.print("co2=");
  Serial.print(value, DEC);
  Serial.print(";status=");
  Serial.println(STATUS_OK);

  delay(1000);
}
