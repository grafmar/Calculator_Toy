#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

class Display {
public:

  explicit Display();
  ~Display();

  void begin();

  void showConfig(uint8_t operations, String maxSmallNum, bool enteringNumber);
  void showGame(uint8_t life, uint8_t points, uint16_t score, uint8_t bat, const char* calc, const char* result);
  void showFinalScore(uint16_t score);

private:

  Adafruit_SSD1306 m_display;

};

#endif // DISPLAY_H