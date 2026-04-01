#include <Servo.h>

Servo myservo;
#include <Servo.h>

Servo kickServo;
Servo snareServo;
Servo hihatServo;

const int kickPin = 9;
const int snarePin = 10;
const int hihatPin = 11;

// BPM
int bpm = 80;
int beatInterval = 60000 / bpm;

int kickRest = 20;
int kickHit = 140;

int snareRest = 30;
int snareHit = 110;

int hihatRest = 40;
int hihatHit = 90;

int kickHold = 40;
int snareHold = 35;
int hihatHold = 20;

void hitKick() {
  kickServo.write(kickHit);
  delay(kickHold);
  kickServo.write(kickRest);
}

void hitSnare() {
  snareServo.write(snareHit);
  delay(snareHold);
  snareServo.write(snareRest);
}

void hitHiHat() {
  hihatServo.write(hihatHit);
  delay(hihatHold);
  hihatServo.write(hihatRest);
}

void setup() {
  kickServo.attach(kickPin);
  snareServo.attach(snarePin);
  hihatServo.attach(hihatPin);

  kickServo.write(kickRest);
  snareServo.write(snareRest);
  hihatServo.write(hihatRest);
  delay (500);
  
}

void loop() {
  hitKick();
  delay(beatInterval);
  }