#include "BatteryMonitor.h"

#define BATTERY_ADC_IN  A0
#define BATTERY_MAX     6000UL  // mV (4 x 1.5V) 5200@4x1.3
#define BATTERY_MIN     3600UL  // mV (4 x 0.9V)
#define RES_DIV_HIGH    47UL    // 47k Resistor-Voltage-Divider high resistore
#define RES_DIV_LOW     10UL    // 10k Resistor-Voltage-Divider low resistore
#define MAX_IN_VOLT     (1100UL * (RES_DIV_HIGH + RES_DIV_LOW) / RES_DIV_LOW) // 1100mV * (10k + 47k) / (10k), internal reference = 1.1V


void BatteryMonitor::begin() {
  pinMode(BATTERY_ADC_IN, INPUT);
  analogReference(INTERNAL);
}

uint8_t BatteryMonitor::getBat() {
  uint16_t adc = 0;
  delay(20);
  for (uint8_t i = 0; i<4; i++) { // average through 4 samples
    adc += analogRead(BATTERY_ADC_IN);
    delay(5);
  }
  uint16_t voltage = map(adc/4, 0 , 1023, 0, MAX_IN_VOLT); 
  voltage = constrain(voltage, BATTERY_MIN, BATTERY_MAX);
  return map(voltage, BATTERY_MIN, BATTERY_MAX, 0, 100);
}
