#include <Servo.h>

Servo kickServo;
Servo snareServo;
Servo hihatServo;

const int kickPin = 9;
const int snarePin = 6;
const int hihatPin = 11;

int bpm = 140;

// One quarter note
int beatInterval = 60000 / bpm;

// If you want kick-hat-snare-hat as evenly spaced steps,
// each step should be an eighth note:
int stepInterval = beatInterval / 2;

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
  for (int pos = snareRest; pos <= snareHit; pos += 5) {
    snareServo.write(pos);
    delay(10);
  }

  delay(snareHold);

  for (int pos = snareHit; pos >= snareRest; pos -= 5) {
    snareServo.write(pos);
    delay(10);
  }

  delay(50);
  snareServo.write(snareRest);
}

void hitHiHat() {
  for (int pos = hihatRest; pos <= hihatHit; pos += 5) {
    hihatServo.write(pos);
    delay(10);
  }

  delay(hihatHold);

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
  delay(stepInterval);

  Serial.println("hihat");
  hitHiHat();
  delay(stepInterval);

  Serial.println("snare");
  hitSnare();
  delay(stepInterval);

  Serial.println("hihat");
  hitHiHat();
  delay(stepInterval);
}