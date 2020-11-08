const int RLED  = 11;
const int GLED  = 10;
const int BLED  = 9;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup(){
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce(boolean prevValue){
  boolean currentValue = digitalRead(BUTTON);
  if(prevValue != currentValue){
    delay(5);
    currentValue = digitalRead(BUTTON);
  }
  return currentValue;
}

void lightLED(boolean rv, boolean gv, boolean bv){
  digitalWrite(RLED, !rv);
  digitalWrite(GLED, !gv);
  digitalWrite(BLED, !bv);
}

void setMode(int mode){
  switch(mode){
  case 1:
    lightLED(HIGH, LOW, LOW);
    break;

  case 2:
    lightLED(LOW, HIGH, LOW);
    break;

  case 3:
    lightLED(LOW, LOW, HIGH);
    break;

  case 4:
    lightLED(HIGH, LOW, HIGH);
    break;

  case 5:
    lightLED(LOW, HIGH, HIGH);
    break;

  case 6:
    lightLED(HIGH, HIGH, LOW);
    break;

  case 7:
    lightLED(HIGH, HIGH, HIGH);
    break;
  
  default:
    lightLED(LOW, LOW, LOW);
    break;
  }
}

void loop(){
  currentButton = debounce(lastButton);
  if(lastButton == LOW && currentButton == HIGH){
    ledMode++;
  }
  lastButton = currentButton;

  if(ledMode == 8) ledMode = 0;
  
  setMode(ledMode);
}