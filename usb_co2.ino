#define PIN_LED_RED 0
#define PIN_LED_GREEN 1
#define LED_ON LOW
#define LED_OFF HIGH
#define PIN_SW1 3
#define PIN_SW2 2

void setup() {
  digitalWrite(PIN_LED_RED, LED_OFF);
  digitalWrite(PIN_LED_GREEN, LED_OFF);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_SW1, INPUT);
  pinMode(PIN_SW2, INPUT);

  usb_mhz14a_init();
  if( digitalRead( PIN_SW1 ) ){
    digitalWrite(PIN_LED_RED, LED_ON);
    usb_mhz14a_zero_calibration();
    digitalWrite(PIN_LED_RED, LED_OFF);
  }
  digitalWrite(PIN_LED_GREEN, LED_ON);

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

  delay(1000);
}
