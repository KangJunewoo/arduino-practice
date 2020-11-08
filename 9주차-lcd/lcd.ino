#include <LiquidCrystal.h>

int time = 0;

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  lcd.begin(16, 2); // 16 바이 2 로 갈거다.
  lcd.setCursor(0,0); // x좌표는 진짜 수학좌표st, y좌표는 행렬st
  lcd.print("merong");

}

void loop() {
  lcd.setCursor(0,0); // 찐 x, y좌표
  lcd.print(time);

  delay(1000);
  time++;

}
