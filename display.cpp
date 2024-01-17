#include "display.h"

int data [] = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4,};  // setup array with values from 0 to 9 converted to decimal from binary in XOR
int data2 [] = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4,}; // same for high score display

void initializeDisplay(void)
{

/*
#define DATA 7
#define LATCH 8
#define CLOCK 9
#define DATA2 10
#define LATCH2 11
#define CLOCK2 12
*/


int score;
int highscore;

  pinMode(LATCH, OUTPUT);  // 3 D-pins for a display. data, clock, and latch set to output
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(LATCH2, OUTPUT);
  pinMode(CLOCK2, OUTPUT);
  pinMode(DATA2, OUTPUT);
  
}

void displayNumber(int n) {   // score display function, display numbers 0-99 as integer when calling the function
  int temp = score;  // so that score variable can be used on both displays temporarily
  int ones = temp % 10;  // ones modulo
  temp = temp /10; // divided by 10
  int tens = temp % 10; // tens modulo
    digitalWrite(LATCH, LOW); //latch low when writing
    shiftOut(DATA, CLOCK, LSBFIRST, data [ones]);  // write data into two displays, save into two arrays
    shiftOut(DATA, CLOCK, LSBFIRST, data [tens]);
    digitalWrite(LATCH, HIGH); // latch high when write finished
}
  


void displayhighscore(int n) {  //same for highscore display
	/*int highscore = EEPROM.read(0);
	if (score > highscore) {
		highscore = score;
		EEPROM.write(0, highscore);
  }*/
  int temp2 = highscore;
  int ones2 = temp2 % 10;
  temp2 = temp2 /10;
  int tens2 = temp2 % 10;
    digitalWrite(LATCH2, LOW);
    shiftOut(DATA2, CLOCK2, LSBFIRST, data2 [ones2]);
    shiftOut(DATA2, CLOCK2, LSBFIRST, data2 [tens2]);
    digitalWrite(LATCH2, HIGH);
  }
  
  void ZeroDisplay(int n) {
	digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, LSBFIRST, data[0]);
    shiftOut(DATA, CLOCK, LSBFIRST, data[0]);
    digitalWrite(LATCH, HIGH);
}