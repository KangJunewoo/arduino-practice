/**
 * 4주차 배운 거 다써먹기
 * pot -> rgb 조절
 * tmp -> 밝기조
*/

int temp_val = 0;
int pot_val = 0;
int brightness = 0;
const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int TEMP = 0;
const int POT = 1;

const int LOWER_BOUND = 350;
const int UPPER_BOUND = 700;
const int ON_OFF_BOUND = 151;
// 재본 결과 low~high : 148~158

void setup() {
  Serial.begin(9600);
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(RLED, OUTPUT);
}

void loop() {
  temp_val = analogRead(TEMP);
  pot_val = analogRead(POT);
  
  Serial.println(temp_val);
  Serial.println(pot_val);
//  Serial.println(pot_val);
  delay(1000);

  if(pot_val<LOWER_BOUND && temp_val > ON_OFF_BOUND){
    Serial.println("a");
    delay(1000);
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  } else if(pot_val > UPPER_BOUND && temp_val > ON_OFF_BOUND){
    Serial.println("b");
    delay(1000);
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  } else if(temp_val > ON_OFF_BOUND){
    Serial.println("c");
    delay(1000);
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  } else{
    Serial.println("d");
    delay(1000);
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
}
