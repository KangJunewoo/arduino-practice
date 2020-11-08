/**
 * 유튜브에 아두이노 프로젝트 검색해보자. 아이디어 지금부터 생각해야 함.
 * 수업에서 안배운 센서 하나정도는 써보자.
 * 
*/

const int POT = 0;
const int LED = 9;
int val = 0;


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(POT);
  int newVal = val * 255 / 1023;

  analogWrite(LED, newVal);
//  Serial.println(val);
  Serial.println(newVal);
  delay(500);
}
