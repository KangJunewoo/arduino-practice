/**
 * RGB 점멸 반복
 * with 1000, 800, 600, 400, 200ms delay
*/

const int RLED = 9;
const int GLED = 10;
const int BLED = 11;

void setup() {
  pinMode(RLED, OUTPUT); // 9, 10, 11번을 출력으로 사용하겠다.
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
}

void loop() {
  for(int i=1000 ; i >= 200 ; i -= 200){
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);

    delay(i);

    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);

    delay(i);

    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);

    delay(i);
  }

}
