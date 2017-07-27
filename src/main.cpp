#include <Arduino.h>

#define LED 33

bool detectBluetooth() {
  int baudrate[] = {1200,2400,4800,9600,19200,38400,57600,115200};
  for (int i = 0; i < 8; i++) {
    Serial3.begin(baudrate[i]);
    Serial3.write("AT");
    delay(500);
    if (Serial3.read() == 'O' && Serial3.read() == 'K') {
      goto found;
    }
  }
  return false;

  found:
  Serial3.write("AT+NAMELimiTTer");
  delay(500);
  Serial3.write("AT+RESET");
  delay(500);
  return true;
}

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, detectBluetooth() ? 1 : 0);
}

void loop() {

}
