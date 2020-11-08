/**
 * pwm을 활용해
 * 아날로그처럼 빛의 밝기를 조절할 수 있다.
*/

const int RLED = 9;
const int GLED = 10;
const int BLED = 11;

void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
}

void loop() {
  int i;
  for(i=0; i<256; i++){
    analogWrite(RLED, i);
    delay(10);
  }
  for(i=0; i<256; i++){
    analogWrite(GLED, i);
    delay(10);
  }
  for(i=0; i<256; i++){
    analogWrite(BLED, i);
    delay(10);
  }

  for(i=255; i>=0 ; i--){
    analogWrite(RLED, i);
    delay(10);
  }
  for(i=255; i>=0 ; i--){
    analogWrite(GLED, i);
    delay(10);
  }
  for(i=255; i>=0 ; i--){
    analogWrite(BLED, i);
    delay(10);
  }
}