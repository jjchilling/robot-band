#include <Servo.h>

Servo kickServo;
Servo snareServo;
Servo hihatServo;

const int kickPin = 9;
const int snarePin = 10;
const int hihatPin = 11;

int bpm = 140;
int beatInterval = 60000 / bpm;

// Kick
int kickRest = 20;
int kickHit = 140;

// Snare
int snareRest = 80;
int snareHit = 110;

// Hi-hat
int hihatRest = 80;
int hihatHit = 140;

int kickHold = 40;
int snareHold = 35;
int hihatHold = 30;

void hitKick() {
  for (int pos = kickRest; pos <= kickHit; pos += 8) {
    kickServo.write(pos);
    delay(4);
  }

  delay(kickHold);

  for (int pos = kickHit; pos >= kickRest; pos -= 8) {
    kickServo.write(pos);
    delay(4);
  }

  delay(20);
  kickServo.write(kickRest);
}

void hitSnare() {
  snareServo.write(snareHit);
  delay(snareHold);
  snareServo.write(snareRest);
}

void hitHiHat() {
  // move up
  for (int pos = hihatRest; pos <= hihatHit; pos += 5) {
    hihatServo.write(pos);
    delay(10);
  }

  delay(hihatHold);

  // move back down
  for (int pos = hihatHit; pos >= hihatRest; pos -= 5) {
    hihatServo.write(pos);
    delay(10);
  }

  delay(50);
  hihatServo.write(hihatRest);
}

void setup() {
  Serial.begin(9600);

  kickServo.attach(kickPin);
  snareServo.attach(snarePin);
  hihatServo.attach(hihatPin);

  kickServo.write(kickRest);
  snareServo.write(snareRest);
  hihatServo.write(hihatRest);

  delay(1000);
}

void loop() {
  Serial.println("kick");
  hitKick();
  delay(beatInterval);

  Serial.println("hihat");
  hitHiHat();
  delay(beatInterval);
}