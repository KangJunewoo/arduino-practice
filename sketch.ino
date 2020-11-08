int val = 0;
const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int TEMP = 0;

const int LOWER_BOUND = 154;
const int UPPER_BOUND = 157;
// 재본 결과 low~high : 148~158

void setup() {
  Serial.begin(9600);
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
}

void loop() {
  val = analogRead(TEMP);
  Serial.println(val);
  delay(1000);
  

  if(val<LOWER_BOUND){
    digitalWrite(RLED, !LOW);
    digitalWrite(GLED, !LOW);
    digitalWrite(BLED, !HIGH);
  } else if(val > UPPER_BOUND){
    digitalWrite(RLED, !HIGH);
    digitalWrite(GLED, !LOW);
    digitalWrite(BLED, !LOW);
  } else{
    digitalWrite(RLED, !LOW);
    digitalWrite(GLED, !HIGH);
    digitalWrite(BLED, !LOW);
  }
}
