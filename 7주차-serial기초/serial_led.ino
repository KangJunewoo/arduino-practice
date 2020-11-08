const int LED = 9;
char data;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    data = Serial.read();
    if(data == '1'){
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    } else if (data == '0'){ // 이걸 else로 바꾸면 아주 잠깐 켜졌다가 결국 '\n'을 만나 꺼짐.
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
}