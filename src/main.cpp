#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

int valor = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  if(!SerialBT.begin("ESP32_vibracall")) {
    Serial.println("An error occurred initializing Bluetooth");
  } else {
    Serial.println("Bluetooth initialized");
  }
}


void loop() {}
