const int RLED = 9;
const int LIGHT = 0;
const int MIN_LIGHT = 20;
const int MAX_LIGHT = 170;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
}

void loop() {
  val = analogRead(LIGHT); // 조도센서 값을 읽어
  Serial.println(val); // 시리얼에 뿌리고
  delay(500);

  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  val = constrain(val, 0, 255);
  analogWrite(RLED, val);
}
