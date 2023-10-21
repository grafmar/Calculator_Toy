#ifndef BATTERYMONITOR_H
#define BATTERYMONITOR_H

#include <Arduino.h>

class BatteryMonitor {
public:
  static void begin();

  static uint8_t getBat();

private:
};

#endif // BATTERYMONITOR_H