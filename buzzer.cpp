#include "buzzer.h"

int nuottimaara = 14; //  number of notes in the melody
int NUOTIT[] = {330, 392, 370, 294, 330, 247, 330, 392, 370, 247, 330, 392, 494, 659}; // frequency of notes
//int NUOTIT2[] = {349, 392, 392, 440, 392, 349, 392, 523, 494, 440, 349, 294, 247, 262};
int nuottimaara2 = 22; // number of notes in the melody
int NUOTIT2[] = {370, 277, 370, 370, 415, 440, 370, 370, 440, 415, 330, 330, 415, 440,370, 370, 370, 277, 370, 370, 415, 440};  // frequency of notes

int nuotitLed;
int NUOTITLED[] = {440, 554, 659, 831};  // frequency of notes


void PlaySound(void)
{
  for (int i = 0; i < nuottimaara; i++)  // plays the frequencies saved in the array for 200 ms, stops when array ends
  {
    tone(BUZZER, NUOTIT[i]);
    delay(200);
  }
  noTone(BUZZER);
}

void PlaySound2()
{
  for (int i = 0; i < nuottimaara2; i++)  // plays the frequencies saved in the array for 200 ms, stops when array ends
  {
    tone(BUZZER, NUOTIT2[i]);
    delay(200);
  }
  noTone(BUZZER);
}

