
int speakerPin = D3;

#define NUM 25 // 首先定義LED的數目
int leds[NUM] = {
  0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, D14, D15, A0, A1, A2, A3, LED1, LED2, LED3,LED4
};

#define SIZE 16

int myLeds[SIZE] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, D14, D15
};


// 將每個腳位模式設為OUTPUT
void setup() {               
  for(int i = 0; i < SIZE; i++){
    if (myLeds[i] != D3) pinMode(myLeds[i], OUTPUT);
  }    
}
int tones[] = { 261, 294, 330, 349, 392, 440, 494, 523 };
// 雖然A3、A2、A1、A0是類比腳位，
// 但也可以把它當做數位腳位使用。

// 然後是兩個迴圈，
// 第一個迴圈從這邊跑到那邊，
// 第二個迴圈跑回來。
void loop() {
/*
  for(int i = 0; i < NUM; i++){
    digitalWrite(leds[i], LOW);
    delay(200);
    digitalWrite(leds[i], HIGH);
  }
  for(int i = NUM-1; i >= 0; i--){
    digitalWrite(leds[i], LOW);
    delay(200);
    digitalWrite(leds[i], HIGH);
  }
*/
/*
  for (int i = 0; i < 8; ++i) {
    tone(speakerPin,tones[i], 100);
    delay(100);
    noTone(speakerPin);
  }
*/
  //tone(speakerPin, tones[0], 100);
  noTone(speakerPin);
/*
  for (int i = 0; i < 3; ++i) {
    digitalWrite(D3, LOW);
    delay(300);
    digitalWrite(D3, HIGH);
    delay(300);
  }
*/
  
  for (int i = 0; i < 3; ++i) {
    LedsMapping(0x0);
    delay(300);
    LedsMapping(0xFFFF);
    delay(300);
  }

  for (int i = 0; i < 5; ++i) {
    LedsMapping(0x5555);
    delay(300);
    LedsMapping(0xAAAA);
    delay(300);
  }
  for (int i = 0; i < 2; ++i) {
    LowToHigh(200);
    delay(300);
    HighToLow(200);
    delay(300);
  }
}

void LedsMapping(unsigned value)
{
  unsigned tmp = value & 0xFFFF;

  for (int i = 0; i < SIZE; ++i) {
    if (tmp & 0x1) 
      digitalWrite(myLeds[i], HIGH);
    else
      digitalWrite(myLeds[i], LOW);
    //delay(300);
    tmp >>= 1;
  }
}

void LowToHigh(unsigned due)
{
  unsigned val = 0xFFFE;

  for (int i = 0; i < SIZE; ++i) {
    LedsMapping(val);
    delay(due);
    val <<= 1;
    val |= 0x01;
  }
}


void HighToLow(unsigned due)
{
  unsigned val = 0x7FFF;

  for (int i = 0; i < SIZE; ++i) {
    LedsMapping(val);
    delay(due);
    val >>= 1;
    val |= 0x8000;
  }
}

