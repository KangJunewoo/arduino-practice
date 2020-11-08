const int RLED = 9;
const int LIGHT = 0;
const int MIN_LIGHT = 200;
const int MAX_LIGHT = 900;

int val = 0;

void setup(){
  pinMode(RLED, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  val = analogRead(LIGHT);
  Serial.print("변환 전 : ");
  Serial.println(val);
  // 최소~최대 범위의 값들을 255 ~ 0에 대응시켜줌 (주변이 어두울수록 밝아지는 구조)
  // 하지만 이 경우 최소최대 바깥 범위는 0과 255 사이를 벗어난다는 단점이 있음.
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  // 그 바깥 범위를 constrain 함수가 처리해줌. 예외값은 모두 255 혹은 0에 대응되도록.
  val = constrain(val, 0, 255);
  Serial.print("변환 후 : ");
  Serial.println(val);
  analogWrite(RLED, val);
  delay(1000);
}