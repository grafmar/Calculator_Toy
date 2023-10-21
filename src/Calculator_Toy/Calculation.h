#ifndef CALCULATION_H
#define CALCULATION_H

#include <Arduino.h>

class Calculation {
public:

  explicit Calculation();
  ~Calculation();

  String getCalculationString();
  uint16_t getResult();
  void generateCalculation();
  
  void setMaxSmallNum(uint16_t num);
  uint16_t getMaxSmallNum();
  void setOperations(uint8_t operations);
  uint8_t getOperations();
  
  static const uint8_t EN_PLUS = 1U;
  static const uint8_t EN_MINUS = 2U;
  static const uint8_t EN_MULT = 4U;
  static const uint8_t EN_DIV = 8U;
  
private:
  uint16_t iMaxSmallNum;
  uint8_t enabledOps;

  uint8_t activeOp;
  uint16_t smallNumA;
  uint16_t smallNumB;
  uint16_t bigNum;
};

#endif // CALCULATION_H
