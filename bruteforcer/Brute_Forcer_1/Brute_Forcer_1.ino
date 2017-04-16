#include <Servo.h> //Header file for servo

/*
 * Arduino code for the Noke bruteforcer.
 * 
 * Demonstrates opening a Noke Quick Click Combination of 4
 * short presses followed by 4 long presses.
 * 
 */

//Time in ms for a long press
#define DASH 455
//Time in ms for a short press
#define DOT 150
//Servo setting for raising the arm
#define UP 95
//Servo setting for lowering the arm
#define DOWN 70
//Short delay to wait between presses
#define GAP 75
//Servo setting for when entry is finished
#define OPEN 180
#define UNLOCKED

int analogPin = 0;
int val = 0;

Servo servo; 

void setup() {
  // put your setup code here, to run once:
servo.attach(9);
Serial.begin(9600);
delay(500);
}

void loop() {
  dot();//Align servo arm
  //Compute 4 dots followed by 4 dashes
  for(int i = 0; i < 4; i++){
    dot();
    }
  for(int i = 0; i < 4; i++){
    dash();
    }
  //Once test combination is finished, raise servo arm.
  servo.write(OPEN);
  //Delay before reattempting
  delay(15000);
}

/*
 * Dot inputs a short press
 * writes to the servo for a short press
 * Short delay once finished
 * 
  */void dot(){
  servo.write(DOWN);
  delay(DOT);
  servo.write(UP);
  delay(GAP);
  }

/*
 * Dash inputs a long press
 * writes to the servo for a long press
 * Short delay once finished
 */
void dash(){
  servo.write(DOWN);
  delay(DASH);
  servo.write(UP);
  delay(GAP);
  }
