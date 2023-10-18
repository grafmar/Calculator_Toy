#include "KeypadReader.h"
#include <Keypad.h>

// Keypad
static const byte ROWS = 4; //four rows
static const byte COLS = 3; //three columns
static const char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'<','0','>'}
};
static const byte rowPins[ROWS] = {10, 9, 2, 4}; //connect to the row pinouts of the keypad
static const byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

KeypadReader::KeypadReader() :
  m_resetMillis(0),
  m_resetStarted(false)
{
}

KeypadReader::~KeypadReader() {
}

char KeypadReader::getKey(void) {
  char key = keypad.getKey();

  // check if '<' pressed for 2s
  KeyState myKeyState = keypad.key[keypad.findInList('<')].kstate;
  if ((myKeyState == PRESSED) || (myKeyState == HOLD)) {
    if (!m_resetStarted){
      m_resetStarted=true;
      m_resetMillis=millis();
    }
    if ((millis()-m_resetMillis) > 2000) {
      m_resetStarted = false;
      key = ESC_KEY;  // was pressed for 2s
    }
  } else {
    m_resetStarted = false;
  }

  return key;
}