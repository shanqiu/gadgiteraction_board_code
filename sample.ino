#include "pitches.h"

//Alert
//G: NOTE_G3 L: NOTE_D4
int melodyAlert[] = {
  NOTE_D4, NOTE_D4, NOTE_G3, NOTE_D4, NOTE_D4};
int noteDurationsAlert[] = {
  4, 8, 8, 4, 4};

//Sadness
//A: NOTE_C3 S: NOTE_D3 D: NOTE_E3 F: NOTE_F3 G: NOTE_G3 H: NOTE_A3 J: NOTE_B3
int melodySad[] = {
  NOTE_B3, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_F3, NOTE_G3, 0,
  NOTE_G3, NOTE_F3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_C3};
int noteDurationsSad[] = {
  4, 4, 4, 4, 2, 2, 1, 4, 4, 4, 4, 4, 2, 2, 1};

//Happiness
//A: NOTE_C4 D: NOTE_E4 G: NOTE_G4 J: NOTE_B4 K: NOTE_C5
int melodyHappy[] = {
  NOTE_C4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4, 0, NOTE_B4, NOTE_C5};
int noteDurationsHappy[] = {
  4, 8, 8, 4, 4, 4, 4, 4};

//Angry
//A: NOTE_C4 S: NOTE_D4 D: NOTE_E4 F: NOTE_F4 G: NOTE_G4 J: NOTE_A4 K: NOTE_B4
//L: NOTE_C5
int melodyAngry[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int noteDurationsAngry[] = {
  16, 16, 16, 16, 16, 16, 16, 16};

//Love
//G: NOTE_G2 T: NOTE_FS2 S: NOTE_D2 Y: NOTE_GS2 J: NOTE_B2 L: NOTE_D3
int melodyLove[] = {
  NOTE_G4, NOTE_FS4, NOTE_D4, NOTE_G4, NOTE_FS4,
  NOTE_D4, NOTE_B4, NOTE_D5, NOTE_GS4, NOTE_G4};
int noteDurationsLove[] = {
  4, 4, 4, 4, 4, 4, 2, 1, 4, 2};

int buzzerPin = 10;
int sensorPin = 0;
int sensorValue;
int flag = 0;

void setup(){
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop(){
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  //Alert  
  if(sensorValue >= 10 && sensorValue < 205){
    alert();
  }

  //Sadness
  else if(sensorValue >= 205 && sensorValue < 410){
    sadness();
  }

  //Happiness
  else if(sensorValue >= 410 && sensorValue < 615){
    happiness();
  }

  //Love
  else if(sensorValue >= 615 && sensorValue < 820){
    love();
  }

  //Angry
  else if(sensorValue >= 820 && sensorValue < 1020){
    angry();
  }
  else
    noTone(buzzerPin);
}

void alert(){
  for (int thisNote = 0; thisNote < 5; thisNote++) {
    int noteDuration = 1000/noteDurationsAlert[thisNote];
    tone(buzzerPin, melodyAlert[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}

void sadness(){
  for (int thisNote = 0; thisNote < 15; thisNote++) {
    int noteDuration = 1000/noteDurationsSad[thisNote];
    tone(buzzerPin, melodySad[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  delay(2000);
}

void happiness(){
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000/noteDurationsHappy[thisNote];
    tone(buzzerPin, melodyHappy[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  delay(500);
}

void love(){
  for (int thisNote = 0; thisNote < 10; thisNote++) {
    int noteDuration = 1000/noteDurationsLove[thisNote];
    tone(buzzerPin, melodyLove[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
  delay(2000);
}

void angry(){
  int randomNote = random(8);
  int noteDuration = 1000/noteDurationsAngry[randomNote];
  tone(buzzerPin, melodyAngry[randomNote],noteDuration);
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
}




