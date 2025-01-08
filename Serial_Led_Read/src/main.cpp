#include <Arduino.h>

#define LED_PIN 20
char serial_data = '0';

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configura el pin del LED como salida
  Serial.begin(115200);      // Inicia la comunicación serial
}

void loop() {
  if (Serial.available()) {
    serial_data = Serial.read();  // Lee el carácter enviado por Serial

    if (serial_data == '1') {
      digitalWrite(LED_PIN, HIGH);     // Enciende el LED
    } else {
      digitalWrite(LED_PIN, LOW);      // Apaga el LED
    }
  }
  Serial.print(">Serial_data: ");Serial.println(serial_data);
}
