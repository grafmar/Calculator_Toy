#include "Display.h"

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

  // Clear the buffer
  m_display.clearDisplay();
  m_display.setTextSize(2);
  m_display.setTextColor(SSD1306_WHITE);
  m_display.setCursor(0,0);
  m_display.println(F("Hallo Du"));
  m_display.setTextSize(1);
  m_display.println(F("Da, ha ha"));
  m_display.display();
}

void Display::showConfig() {

}

void Display::showGame(String calc) {
  m_display.clearDisplay();
  m_display.setTextSize(2);
  m_display.setTextColor(SSD1306_WHITE);
  m_display.setCursor(0,0);
  m_display.println(calc);
  m_display.display();
}
