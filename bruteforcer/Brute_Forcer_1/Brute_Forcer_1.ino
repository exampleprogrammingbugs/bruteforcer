#include <Servo.h>

#define DASH 455        //Time in ms for a long press
#define DOT 150         //Time in ms for a short press
#define UP 95           //Servo setting for raising the arm
#define DOWN 70         //Servo setting for lowering the arm
#define GAP 75          //Short delay to wait between presses
#define OPEN 180        //Servo setting for when entry is finished
Servo servo; 

void setup() {
  servo.attach(9);
  Serial.begin(9600);
  delay(500);
}

void loop() {
  dot();                //Align servo arm
  //An example: execute 4 dots followed by 4 dashes
  for(int i = 0; i < 4; i++){
    dot();
  }
  for(int i = 0; i < 4; i++){
    dash();
  }
  servo.write(OPEN);    //Once test combination is finished, raise servo arm
  delay(15000);         //Delay before reattempting
}

// dot(): perform a short press write to the servo, followed by a gap
void dot(){
  servo.write(DOWN);
  delay(DOT);
  servo.write(UP);
  delay(GAP);
}

// dash(): perform a long press write to the servo, followed by a gap
void dash(){
  servo.write(DOWN);
  delay(DASH);
  servo.write(UP);
  delay(GAP);
}
