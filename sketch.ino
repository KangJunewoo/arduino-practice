// 사분음표 : 250ms
#include "headers/pitches.h"

const int SPEAKER = 9;
const int DO = 2;
const int RE = 3;
const int MI = 4;
const int FA = 5;
const int SOL = 6;
const int LA = 7;

int notes[] = {
  NOTE_C4,NOTE_E4,NOTE_G4,NOTE_C4,NOTE_E4,NOTE_G4,NOTE_A4,NOTE_A4,NOTE_A4,NOTE_G4,
  NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,NOTE_D4,NOTE_D4,NOTE_D4,NOTE_C4,
};

int times[] = {
  250,250,250,250,250,250,250,250,250,750,
  250,250,250,250,250,250,250,250,250,1000,
};

void setup() {
  pinMode(DO, OUTPUT);
  pinMode(RE, OUTPUT);
  pinMode(MI, OUTPUT);
  pinMode(FA, OUTPUT);
  pinMode(SOL, OUTPUT);
  pinMode(LA, OUTPUT);
  
  
  
}

void loop() {
  digitalWrite(DO, LOW);
  digitalWrite(RE, LOW);
  digitalWrite(MI, LOW);
  digitalWrite(FA, LOW);
  digitalWrite(SOL, LOW);
  digitalWrite(LA, LOW);
  int notes_n = sizeof(notes)/sizeof(int);
  for(int i=0;i<notes_n;i++){
    switch(notes[i]){
      case NOTE_C4:
        digitalWrite(DO, HIGH);
        break;
      case NOTE_D4:
        digitalWrite(RE, HIGH);
        break;
      case NOTE_E4:
        digitalWrite(MI, HIGH);
        break;

      case NOTE_F4:
        digitalWrite(FA, HIGH);
        break;
      case NOTE_G4:
        digitalWrite(SOL, HIGH);
        break;
      case NOTE_A4:
        digitalWrite(LA, HIGH);
        break;
    }
    tone(SPEAKER, notes[i], times[i]);
    delay(times[i]); // 실행시간을 벌어주는 역
    switch(notes[i]){
      case NOTE_C4:
        digitalWrite(DO, LOW);
        break;
      case NOTE_D4:
        digitalWrite(RE, LOW);
        break;
      case NOTE_E4:
        digitalWrite(MI, LOW);
        break;

      case NOTE_F4:
        digitalWrite(FA, LOW);
        break;
      case NOTE_G4:
        digitalWrite(SOL, LOW);
        break;
      case NOTE_A4:
        digitalWrite(LA, LOW);
        break;
    }
  }
}
