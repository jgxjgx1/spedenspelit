#ifndef BUZZER_H
#define BUZZER_H
#include <arduino.h>

#define BUZZER 13 // digital pin 13

extern int nuottimaara; // number of notes in the melody
extern int NUOTIT[]; // frequency of notes

extern int nuottimaara2; // number of notes in the melody
extern int NUOTIT2[];  // frequency of notes

extern int nuotitLed;
extern int NUOTITLED[];

// function prototypes:
void PlaySound(void);
void PlaySound2(void);

#endif