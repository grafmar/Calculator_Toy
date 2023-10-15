#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <String.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

class Display {
public:

  explicit Display();
  ~Display();

  void begin();

  void showConfig();
  void showGame(uint8_t life, uint16_t score, const char* calc, const char* result);

private:

  Adafruit_SSD1306 m_display;

};

#endif // DISPLAY_H