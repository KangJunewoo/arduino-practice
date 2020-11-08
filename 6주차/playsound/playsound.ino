// 사분음표 : 250ms
#include "pitches.h"

const int SPEAKER = 9;

int notes[] = {
  NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,
  NOTE_C5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_F4,NOTE_E4,NOTE_D4,NOTE_C4,
};

int times[] = {
  250,250,250,250,
  250,250,250,1000,
  250,250,250,250,
  250,250,250,250
};
void setup() {
  int notes_n = sizeof(notes)/sizeof(int);
  for(int i=0;i<notes_n;i++){
    tone(SPEAKER, notes[i], times[i]);
    delay(times[i]); // 실행시간을 벌어주는 역
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
