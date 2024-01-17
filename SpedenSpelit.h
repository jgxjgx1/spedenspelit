#ifndef SPEDENSPELIT_H
#define SPEDENSPELIT_H
#include <arduino.h>

enum GameMode {
  MENU,
  GAME,
  STARTED,
  GAMEOVER
};

// function prototypes, functions inside .ino
void startTheGame();
void gameOver();
void gameMenu();

void initializeGame();

//void initializeTimer();
//void checkGame(int);

void readHighscore();
void writeHighscore();
void resetHighScore();

#endif