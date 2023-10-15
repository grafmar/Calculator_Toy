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

#include "Calculation.h"
#include "MelodyPlayer.h"
#include "MelodyCollection.h"
#include <Keypad.h>
#include "Display.h"

Display myDisplay;

static const uint8_t BUZZER = 11;
MelodyPlayer melodyPlayer(BUZZER);

// Keypad
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {10, 9, 2, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

Calculation myCalculation();

char myString[20];
uint8_t pos=0;

void setup() {
  myDisplay.begin();
}

uint32_t resetMillis=0;
bool resetStarted=false;

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    if (pos>18) pos=0;
    myString[pos++]=key;
    myString[pos]='\0';
    
    myDisplay.showGame(myString);

    if (key == '0') melodyPlayer.play(melodyGood);
    if (key == '1') melodyPlayer.play(melodyBad);
    if (key == '2') melodyPlayer.play(melodyScoreUp);
    if (key == '3') melodyPlayer.play(melodyVictory);
    if (key == '4') melodyPlayer.play(melodyFinishDrum);
  }

  // check if '*' pressed for 2s
  KeyState myKeyState = keypad.key[keypad.findInList('*')].kstate;
  if ((myKeyState == PRESSED) || (myKeyState == HOLD)) {
    if (!resetStarted){
      resetStarted=true;
      resetMillis=millis();
    }
    if ((millis()-resetMillis) > 2000) {
      resetStarted = false;
      // melodyPlayer.play(melodyCollection[11]);
      //melodyPlayer.play(melodyCollection[0]);
    }
  } else {
    resetStarted = false;
  }
}

