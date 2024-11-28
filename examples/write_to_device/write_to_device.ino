#include "dummy_device.h"

static em::DummyDevice g_dummy_device;

void setup() {
  Serial.begin(115200);
  Serial.println("setup");
  Serial.println(String("dummy device lib version: ") + em::DummyDevice::Version());

  Wire.begin();

  const auto ret = g_dummy_device.Init();

  if (em::DummyDevice::kOK == ret) {
    Serial.println("dummy device initialization successful");
  } else {
    Serial.print("dummy device initialization failed: ");
    Serial.println(ret);
    while (true);
  }

  Serial.println("setup successful");
}

void loop() {
  const uint8_t data[10] = {0};
  g_dummy_device.Write(data, sizeof(data));
  delay(1000);
}
