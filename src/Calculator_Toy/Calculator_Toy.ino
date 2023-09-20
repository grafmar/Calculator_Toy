/*
  Calculator Toy

  Displays math equations to solve

  circuit:
  - 3x4 button keypad matrix
  - ssd1306 OLED display
  - buzzer

  created 2023-09-20
  by Marco Graf

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneKeyboard
*/

#include "pitches.h"
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Keypad.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

static const uint8_t BUZZER = 11;

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

// Buzzer
#define NOTE_C4 262
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

char myString[20];
uint8_t pos=0;

void setup() {
  display.setRotation(2);
  if(!display.begin(SSD1306_NORMALDISPLAY, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(1000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("Hallo Du"));
  display.setTextSize(1);
  display.println(F("Da, ha ha"));
  display.display();
}

uint32_t resetMillis=0;
bool resetStarted=false;

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    if (pos>18) pos=0;
    myString[pos++]=key;
    myString[pos]='\0';
    
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);
    display.println(myString);
    display.display();
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
      sound();
    }
  } else {
    resetStarted = false;
  }
}

void sound(){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(BUZZER);
  }
}
