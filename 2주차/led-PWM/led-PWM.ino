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
  for(int i=45;i>=5;i-=10){
    int val = (i / 100.0 * 255 + 0.5);

    for(int j=300;j>=100;j-=100){
      analogWrite(RLED, val);
      analogWrite(GLED, 0);
      analogWrite(BLED, 0);

      delay(j);

      analogWrite(RLED, 0);
      analogWrite(GLED, val);
      analogWrite(BLED, 0);

      delay(j);

      analogWrite(RLED, 0);
      analogWrite(GLED, 0);
      analogWrite(BLED, val);

      delay(j);
    }
  }
}
