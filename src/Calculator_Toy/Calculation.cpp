#include "Calculation.h"

Calculation::Calculation() :
  iMaxSmallNum(10),
  enabledOps(3),
  activeOp(1),
  smallNumA(1),
  smallNumB(1),
  bigNum(2)
{
}

Calculation::~Calculation() {
}

String Calculation::getCalculationString() {
  String calcString;
  if (activeOp & EN_PLUS) {
    calcString = String("") + smallNumA + F("+") + smallNumB + F("=");
  } else if (activeOp & EN_MINUS) {
    calcString = String("") + bigNum + F("-") + smallNumA + F("=");
  } else if (activeOp & EN_MULT) {
    calcString = String("") + smallNumA + F("*") + smallNumB + F("=");
  } else {
    calcString = String("") + bigNum + F(":") + smallNumA + F("=");
  }
  return calcString;
}

uint16_t Calculation::getResult() {
  if ((activeOp & EN_PLUS) || (activeOp & EN_MULT)) {
    return bigNum;
  } else {
    return smallNumB;
  }
}

void Calculation::generateCalculation() {
  do {
    activeOp = ((1<<random(0,3+1)) & enabledOps);
  } while (activeOp == 0);
  smallNumA = random(1,iMaxSmallNum+1);
  smallNumB = random(1,iMaxSmallNum+1);
  
  if ((activeOp & EN_PLUS) || (activeOp & EN_MINUS)) {
    bigNum = smallNumA + smallNumB;
  } else {
    bigNum = smallNumA * smallNumB;
  }
}

void Calculation::setMaxSmallNum(uint16_t num) {
  iMaxSmallNum = num;
}

uint16_t Calculation::getMaxSmallNum() {
  return iMaxSmallNum;
}

void Calculation::setOperations(uint8_t operations) {
  if (operations != 0) {
    enabledOps = operations;
  }
}

uint8_t Calculation::getOperations() {
  return enabledOps;
}
