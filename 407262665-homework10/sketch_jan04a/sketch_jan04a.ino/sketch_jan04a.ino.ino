
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {


lcd.begin(16, 2);
lcd.print("Andes Hello");
}
int buttonState1,buttonState2,buttonState3,buttonState4 = 0;
int delay_number = 100;
void loop() {
  //lcd.print("Andes Hello");
}
