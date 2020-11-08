const int LED = 9;
const int BUTTON = 2;

boolean prevState = LOW;
boolean currentState = LOW;
boolean ledOn = false;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean prevValue){
  boolean currentValue = digitalRead(BUTTON);
  if (prevValue != currentValue){ // 버튼에서 변화를 감지했을때
    delay(5); // 0.005초를 기다렸다가 또 읽어서
    currentValue = digitalRead(BUTTON);
  }
  return currentValue; // 그 때의 값을 반환
}

void loop(){
  currentState = debounce(prevState); //루프 안에 debounce가 있으니, 계에에에속 감지하는 상태.
  if(prevState == LOW && currentState == HIGH){ // 눌린 게 확실할 경우 ledOn 토글
    ledOn = !ledOn;
  }
  prevState = currentState; // 상태저장 후 반영
  digitalWrite(LED, ledOn);
}