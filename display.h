#ifndef DISPLAY_H
#define DISPLAY_H
#include <arduino.h>

extern int highscore;
extern int score;

#define DATA 7  // define digital pins 7-12
#define LATCH 8
#define CLOCK 9
#define DATA2 10
#define LATCH2 11
#define CLOCK2 12

/*
int data [] = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4,};
int data2 [] = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4,};  // in display.cpp
int score;
int highscore;

  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH2, OUTPUT);
  pinMode(CLOCK2, OUTPUT);
  pinMode(DATA2, OUTPUT);
  pinMode(button, INPUT_PULLUP);

*/
void initializeDisplay(void);  // function prototype

/*

void displayNumber(int n) {
  int left, right = 0;
  if (n < 10) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, data [n]); // in display.cpp
    shiftOut(DATA, CLOCK, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  }
  else if (n >= 10) {
    right = n % 10;   // remainder of dividing the number to display by 10  // old
    left = n / 10;  // quotient of dividing the number to display by 10
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, data [right]);
    shiftOut(DATA, CLOCK, LSBFIRST, data [left]);
    digitalWrite(LATCH, HIGH);
  }*/
void displayNumber(int n);  // function prototype

/*
void displayNumber2(int n) {
  int left2, right2 = 0;
  if (n < 10) {
    digitalWrite(LATCH2, LOW);  //vanha versio
    shiftOut(DATA2, CLOCK2, LSBFIRST, data2 [n]);
    shiftOut(DATA2, CLOCK2, LSBFIRST, 0);
    digitalWrite(LATCH, HIGH);
  }
  else if (n >= 10) {
    right2 = n % 10;   // remainder of dividing the number to display by 10
    left2 = n / 10;  // quotient of dividing the number to display by 10
    digitalWrite(LATCH2, LOW);
    shiftOut(DATA2, CLOCK2, LSBFIRST, data2 [right2]);
    shiftOut(DATA2, CLOCK2, LSBFIRST, data2 [left2]);
    digitalWrite(LATCH2, HIGH);
  }
  */

  void displayhighscore(int highscore);  // function prototype
  void ZeroDisplay(int); // function prototype
#endif
