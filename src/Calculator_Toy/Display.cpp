#include "Adafruit_SSD1306.h"
#include "Display.h"
#include "Calculation.h"
#include <String.h>

// Heart icon
static const unsigned char PROGMEM heart_8x7[] =
{ 0b01101100,
  0b11111110,
  0b11111110,
  0b11111110,
  0b01111100,
  0b00111000,
  0b00010000};

Display::Display() :
  m_display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire)
{
}

Display::~Display() {
}

void Display::begin() {
  m_display.setRotation(2);
  if(!m_display.begin(SSD1306_NORMALDISPLAY, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  //m_display.display();
  //delay(1000); // Pause for 2 seconds
}

void Display::showConfig(uint8_t operations, String maxSmallNum, bool enteringNumber) {
  String ops = "";
  ops += String((operations&Calculation::EN_PLUS) != 0 ? "+" : "");
  ops += String((operations&Calculation::EN_MINUS) != 0 ? "-" : "");
  ops += String((operations&Calculation::EN_MULT) != 0 ? "*" : "");
  ops += String((operations&Calculation::EN_DIV) != 0 ? ":" : "");
                    
  m_display.clearDisplay();
  m_display.setTextColor(SSD1306_WHITE);
  m_display.setTextSize(1);

  // hint1
  m_display.setCursor(0,63-4*8);
  m_display.println(F("1 +   2 -   3 *   4 :"));
  m_display.println(F("5 Max. kleine Zahl"));
  m_display.println(F("< Loeschen/Ende"));
  m_display.println(F("> Start/Eingabe"));

  // operations
  m_display.setCursor(0,4);
  m_display.println(F("Operation"));
  m_display.setCursor(0,18);
  m_display.println(F("Max Zahl"));

  m_display.setTextSize(2);
  m_display.setCursor(70,0);
  m_display.println(ops);
  m_display.setCursor(70,14);
  if (enteringNumber) {
    m_display.fillRect(70,14,48,14, SSD1306_WHITE);
    m_display.setTextColor(SSD1306_BLACK);
  }
  m_display.println(maxSmallNum);

  m_display.display();
}

void Display::showGame(uint8_t life, uint8_t points, uint16_t score, const char* calc, const char* result) {
  m_display.clearDisplay();
  m_display.setTextColor(SSD1306_WHITE);

  // Lifes
  if (life>3) life = 3;
  uint8_t xoffset=0;
  for (uint8_t i=0; i<life; i++) {
    m_display.drawBitmap(xoffset, 0, heart_8x7, 8, 7, 1);
    xoffset += 10;
  }

  // score
  char scoreBuf[5];
  sprintf(scoreBuf, "%04d", score);
  m_display.setTextSize(1);
  m_display.setCursor(128-7*4,0);
  m_display.print(scoreBuf);

  // points
  m_display.setTextSize(1);
  m_display.drawLine(93, 1, 96, 3, SSD1306_WHITE);
  m_display.drawLine(93, 5, 96, 3, SSD1306_WHITE);
  for (uint8_t i=0; i<points; i++) {
    m_display.fillCircle(90-5*i, 3, 1, SSD1306_WHITE);
  }

  // calculation
  m_display.setTextSize(2);
  m_display.setCursor(0,15);
  m_display.println(calc);

  // result
  m_display.setCursor(7,40);
  m_display.println(result);

  m_display.display();
}

void Display::showFinalScore(uint16_t score) {
  m_display.clearDisplay();
  m_display.setTextColor(SSD1306_WHITE);

  // score
  char scoreBuf[5];
  sprintf(scoreBuf, "%04d", score);
  m_display.setCursor(35,24);
  m_display.setTextSize(2);
  m_display.println(scoreBuf);
  m_display.setTextSize(1);
  m_display.setCursor(37,7);
  m_display.print(F("Du hast"));
  m_display.setCursor(17,49);
  m_display.print(F("Punkte gemacht"));

  m_display.display();
}

