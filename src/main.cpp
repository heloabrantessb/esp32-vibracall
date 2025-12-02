#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

int valor = 0;

int motorPin = 5;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  if (!SerialBT.begin("ESP32_vibracall"))
  {
    Serial.println("An error occurred initializing Bluetooth");
  }
  else
  {
    Serial.println("Bluetooth initialized");
  }

  pinMode(motorPin, OUTPUT);
}

void loop()
{
  if (SerialBT.available())
  {
    String s = SerialBT.readStringUntil('\n');
    s.trim();

    if (s.length() > 0)
    {
      int valor = s.toInt();
      valor = constrain(valor, 0, 255);

      analogWrite(motorPin, valor);

      Serial.print("Recebido via BT: ");
      Serial.println(valor);
    }
  }
}
