#include "Display.h"

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
  m_display.display();
  delay(1000); // Pause for 2 seconds

  showConfig();
}

void Display::showConfig() {
  m_display.clearDisplay();
  m_display.setTextColor(SSD1306_WHITE);
  m_display.setTextSize(1);

  // hint
  m_display.setTextSize(1);
  m_display.setCursor(0,63-2*7);
  m_display.println("< Loeschen/Ende");
  m_display.println("> Start");
  //m_display.println("> Start/Eingabe");

  m_display.display();
}

void Display::showGame(uint8_t life, uint16_t score, const char* calc, const char* result) {
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

  // calculation
  m_display.setTextSize(2);
  m_display.setCursor(0,15);
  m_display.println(calc);

  // result
  m_display.setCursor(7,40);
  m_display.println(result);

  m_display.display();
}
