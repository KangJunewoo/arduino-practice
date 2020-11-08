/**
 * 버튼을 눌러 rgb를 바꾸고
 * 밝기는 조도센서 따라가게.
*/
const int RLED = 9;
const int GLED = 10;
const int BLED = 11;

const int BUTTON = 2;
boolean lastButton = LOW;
boolean currentButton = LOW;

boolean lastBts[3] = {HIGH, HIGH, HIGH};
boolean currentBts[3] = {HIGH, HIGH, HIGH};


const int LIGHT = 0;
const int MIN_LIGHT = 20;
const int MAX_LIGHT = 170;
int val = 0;
int ledMode = 1;
void setup() {
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = analogRead(LIGHT); // 조도센서 값을 읽어
  Serial.println(val); // 시리얼에 뿌리고
  delay(500);

  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH){
    ledMode ++;
    if(ledMode == 4) ledMode = 1;
  }
  lastButton = currentButton;
  setMode(ledMode);
  
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);
  val = constrain(val, 0, 255);
//  analogWrite(RLED, 255-val);
//  analogWrite(GLED, 255-val);
//  analogWrite(BLED, 255-val);

  

}

void setMode(int mode){
  
  if(mode==1){
    analogWrite(RLED, val);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  } else if(mode==2){
    digitalWrite(RLED, HIGH);
    analogWrite(GLED, val);
    digitalWrite(BLED, HIGH);
  } else if(mode==3){
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    analogWrite(BLED, val);
  }
}

boolean debounce(boolean last){
  boolean current = digitalRead(BUTTON);
  if(last!=current){
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}