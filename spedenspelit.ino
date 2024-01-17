#include <EEPROM.h>

#include "buttons.h" // includes others, e.g. SpedenSpelit.h
#include "display.h"
#include "leds.h"

#define INTERVAL_DEF 1000
#define SPEED 5 // default = 10

// game vars:
int score = 0;
int highscore = 0;
int state = MENU;
byte ledNumber = 0;

int ledCount=0;
int ledArray[100];
int buttonArray[100];
int btn_x = 0;
int led_x = 0;

// time vars:
int sound_duration = 650; // sound duration at start, speeds up with interval
int interval; // starts with 1 sec = 1 Hz

unsigned long mainTime = 0;
unsigned long previousMillis = 0;
unsigned long current_Time = 0;
unsigned long elapsed_Time = mainTime - current_Time;
// -----------

void setup() {
  //Serial.begin(9600);
  initButtonsAndButtonInterrupts();
  initializeDisplay();
}

void loop() {
  readHighscore();
  displayhighscore(highscore);
  
  // checks the value of the state
  if(state == MENU)
    gameMenu();
  else if(state == GAME){
    initializeGame();
    state = STARTED;
    game_Started_LED(); // turn on specific LEDs
  }
  else if(state == STARTED)
    runGame();
  else {
    gameOver();
    game_Ended_LED(); // turn on specific LEDs
    state = MENU;
  }
}


// *** FUNCTIONS ***

void initializeGame(){
  score = 0;
  displayNumber(score);
  sound_duration = 650;

  randomSeed(analogRead(0)); // for true random behaviour, analog pin 0 is left floating
  for(int led_x = 0; led_x <= 99 ; led_x++){
    ledNumber = random(16,20); // create an array with the random numbers
    ledArray[led_x] = ledNumber;
  }

  interval = INTERVAL_DEF;
  btn_x = 0;
  led_x = 0;
}

void runGame()
{

  mainTime = millis();
  if (mainTime - previousMillis >= interval)
  {
    previousMillis = mainTime;

    setLed(ledArray[led_x]); // set LED at intervals
    
    nuotitLed = ledArray[led_x]-16;
    tone(BUZZER, NUOTITLED[nuotitLed], sound_duration);
    
    //Serial.print("debug LED: "); Serial.println(ledArray[led_x]);
    led_x++;
    
    if (ledCount >= SPEED && ledCount % SPEED == 0)
		{
		  interval *= 0.9;
      sound_duration *= 0.9;
		}
  }

}

void gameMenu() // default state: display specific LEDs
{
  clearAllLeds();
  menuLEDS();
}

void gameOver() // game ended
{
  if(score > highscore) { // if new high score has been recorded, write it in EEPROM and play related audiovisual effects
    highscore = score;
    writeHighscore();
    
    PlaySound2();
    newHighScore_LED();
  }
  else PlaySound();

  state = MENU; // return to MENU state
  ledNumber = 0; // prevents accidental presses from increasing points outside the game

  /* debug:
  Serial.println("GAME OVER");
  Serial.print("Score: "); Serial.println(score);
  delay(1000);
  */
}

void readHighscore() { // read high score from EEPROM
  highscore = (EEPROM.read(0) << 8) + EEPROM.read(1);
  if(highscore == 0xffff)
    highscore = 0;
}

void writeHighscore() { // write high score in EEPROM
  EEPROM.write(0, highscore >> 8);
  EEPROM.write(1, highscore & 0xff);
}

void resetHighScore(){ // reset high score to 0
  highscore = 0;
  writeHighscore();
}