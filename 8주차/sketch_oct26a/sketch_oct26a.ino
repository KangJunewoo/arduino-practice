const int RLED = 9;
const int GLED = 10;
const int BLED = 11;
char data;

void setup() {
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    data = Serial.read();
    switch(data){
      Serial.print(data);
      case '1':
        digitalWrite(RLED, HIGH);
        digitalWrite(GLED, LOW);
        digitalWrite(BLED, LOW);
        break;
      case '2':
        digitalWrite(RLED, LOW);
        digitalWrite(GLED, HIGH);
        digitalWrite(BLED, LOW);
        break;
      case '3':
        digitalWrite(RLED, LOW);
        digitalWrite(GLED, LOW);
        digitalWrite(BLED, HIGH);
        break;
      case '4':
        digitalWrite(RLED, HIGH);
        digitalWrite(GLED, HIGH);
        digitalWrite(BLED, HIGH);
        break;
    }
  }
}

void toggle(
