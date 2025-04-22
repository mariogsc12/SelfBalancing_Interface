#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SHT4x.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLE2902.h>

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

BLEServer *pServer = nullptr;
BLECharacteristic humidityCharacteristic(BLEUUID((uint16_t)0x2A6F), BLECharacteristic::PROPERTY_READ);
BLECharacteristic temperatureCharacteristic(BLEUUID((uint16_t)0x2A6E), BLECharacteristic::PROPERTY_READ);
BLECharacteristic timerCharacteristic(BLEUUID((uint16_t)0x183F), BLECharacteristic::PROPERTY_READ);

class BtServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    Serial.println("Bluetooth connected");
  };
  void onDisconnect(BLEServer* pServer) {
    delay(500);
    pServer->startAdvertising();
  }
};

void setup() {
  Serial.begin(115200);
  if (!sht4.begin()) {
    Serial.println("Error: SHT4x not found");
    while (1) delay(1);
  }
  Serial.println("SHT4x found");

  BLEDevice::init("SuperIoT");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new BtServerCallbacks());
  BLEService *devService = pServer->createService(BLEUUID((uint16_t)0x181A));
  devService->addCharacteristic(&humidityCharacteristic);
  devService->addCharacteristic(&temperatureCharacteristic);
  devService->addCharacteristic(&timerCharacteristic);
  humidityCharacteristic.addDescriptor(new BLE2902());
  temperatureCharacteristic.addDescriptor(new BLE2902());
  timerCharacteristic.addDescriptor(new BLE2902());
  devService->start();
  pServer->getAdvertising()->start();
  Serial.println("Awaiting Blueotooth connection...");
}

void loop() {
  unsigned long ms = millis();
  sensors_event_t h, t;
  sht4.getEvent(&h, &t);
  Serial.printf("ms: %lu; h: %.2f; t: %.2f\n", ms, h.relative_humidity, t.temperature);
  humidityCharacteristic.setValue(h.relative_humidity);
  temperatureCharacteristic.setValue(t.temperature);
  uint32_t time = (uint32_t)ms;
  timerCharacteristic.setValue(time);
  delay(500);
}