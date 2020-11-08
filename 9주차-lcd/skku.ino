#include <LiquidCrystal.h>

int time = 0;

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  lcd.begin(16, 2);

}

void loop() {
  for(int i=3;i<6;i++){
    lcd.setCursor(i,1);
    lcd.print("skku");
    delay(1000);
    lcd.clear();
  }
//  lcd.setCursor(0,1);
//  lcd.print(time);

//  delay(1000);
//  time++;

}
