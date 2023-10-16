/*
  Calculator Toy

  Tool for kids wich displays math equations to solve

  circuit:
  - 3x4 button keypad matrix
  - ssd1306 OLED display
  - buzzer

  created 2023-09-20
  by Marco Graf

  https://github.com/grafmar/Calculator_Toy
*/

#include "KeypadReader.h"
#include "Game.h"

KeypadReader keypadReader;
Game game;

void setup() {
  game.begin();
}

void loop() {
  game.handle(keypadReader.getKey());
}

