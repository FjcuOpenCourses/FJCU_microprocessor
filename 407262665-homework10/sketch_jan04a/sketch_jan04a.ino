
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
void setup() {
pinMode(BT1, INPUT);
pinMode(BT2, INPUT);
pinMode(BT3, INPUT);
pinMode(BT4, INPUT);

lcd.begin(16, 2);
lcd.print("Hello World!");
}
int buttonState1,buttonState2,buttonState3,buttonState4 = 0;
int delay_number = 100;
void loop() {
buttonState1 = digitalRead(BT1);
buttonState2 = digitalRead(BT2);
buttonState3 = digitalRead(BT3);
buttonState4 = digitalRead(BT4);
if (buttonState1 == LOW) {
lcd.clear();
lcd.print("BT1");
delay(delay_number);
} else if (buttonState2 == LOW) {
lcd.clear();
lcd.print("BT2");
delay(delay_number);
} else if (buttonState3 == LOW) {
lcd.clear();
lcd.print("BT3");
delay(delay_number);
} else if (buttonState4 == LOW) {
lcd.clear();
lcd.print("BT4");
delay(delay_number);
}
}
