#ifndef GAME_H
#define GAME_H

#include <Arduino.h>

class Game {
public:

  explicit Game();
  ~Game();

  void begin();
  void handle(char key);

private:
  void handleConfig(char key);
  void handleGame(char key);
  void handleScore(char key);

  void enterConfig();
  void enterGame();
  void enterScore();

  void newGameStep();

  void toggleOperation(uint8_t op);

  void showConfigNumber();

  void handleEnterNumber(char key, uint8_t maxDigits);
  
  enum GameState {CONFIG, GAME, SCORE};
  GameState m_state;
  bool m_isEnterNumber;
  uint16_t m_score;
  uint8_t m_lifes;
  uint8_t m_points;
  uint32_t m_pointsTime;
  uint8_t m_resultPos;
  char m_result[7];
};

#endif // GAME_H
