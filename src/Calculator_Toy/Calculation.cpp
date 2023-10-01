#include "Calculation.h"

Calculation::Calculation() :
  iMaxSmallNum(1),
  enabledOps(3),
  activeOp(1),
  smallNumA(1),
  smallNumB(1),
  bigNum(2),
  calcString()
{
}

Calculation::~Calculation() {
}

String Calculation::getCalculationString() {
  if (activeOp & EN_PLUS) {
    calcString = String("") + smallNumA + " + " + smallNumB + " = ";
  } else if (activeOp & EN_MINUS) {
    calcString = String("") + bigNum + " - " + smallNumA + " = ";
  } else if (activeOp & EN_MULT) {
    calcString = String("") + smallNumA + " * " + smallNumB + " = ";
  } else {
    calcString = String("") + bigNum + " : " + smallNumA + " = ";
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
    activeOp = ((1<<random(0,3)) & enabledOps);
  } while (activeOp == 0);
  smallNumA = random(1,iMaxSmallNum);
  smallNumB = random(1,iMaxSmallNum);
  
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
