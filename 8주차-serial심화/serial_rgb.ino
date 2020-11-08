const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

int rv = 0;
int gv = 0;
int bv = 0;

void setup(){
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop(){
  while(Serial.available() > 0){
    rv = Serial.parseInt();
    gv = Serial.parseInt();
    bv = Serial.parseInt();

    if(Serial.read() == '\n'){
      analogWrite(RED, 255-rv);
      analogWrite(GREEN, 255-gv);
      analogWrite(BLUE, 255-bv);
    }
  }

}