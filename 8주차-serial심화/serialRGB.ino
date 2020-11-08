const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

int index = 0;
int value = 0;

void setup() {
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  if(Serial.available() >0){
    int howmany = Serial.parseInt();
    for(int i=0;i<howmany;i++){
      index = Serial.parseInt();
      value = Serial.parseInt();
      Serial.print(index);
      Serial.print(", ");
      Serial.print(value);
      Serial.print('\n');
      
      switch(index){
        case 2:
          Serial.print("파랑파랑\n");
          analogWrite(BLUE, value);
          break;
        case 1:
          Serial.print("초록초\n");
          analogWrite(GREEN, value);
          break;
        case 0:
          Serial.print("빨강빨강\n");
          analogWrite(RED, value);
          break;
      }
    }
  }
}
