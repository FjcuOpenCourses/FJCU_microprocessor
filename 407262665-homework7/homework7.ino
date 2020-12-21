
//Sample using LiquidCrystal library
#include <LiquidCrystal.h>

/*******************************************************

This program will test the LCD panel and the buttons
Mark Bramwell, July 2010

********************************************************/
int melody[] = { 
659, 659, 659, 0, 523, 659, 784, 392, 523, 0,
392, 0, 330, 0, 440, 0, 494, 0, 466, 440, 392,
659, 784, 880, 698, 784, 0, 659, 0, 523, 587,
494, 0, 523, 0, 392, 0, 330, 0, 440, 0, 494,
0, 466, 440, 392, 659, 784, 880, 698, 784, 0,
659, 0, 523, 587, 494, 0, 0, 784, 740, 698,
622, 659, 0, 415, 440, 523, 0, 440, 523, 587, 0,
784, 740, 698, 622, 659, 0, 698, 1047, 0, 698,
1047, 698, 1047, 0, 784, 740, 698, 622, 659, 0,
415, 440, 523, 0, 440, 523, 587, 0, 622, 0, 587,
0, 523, 0, 0, 784, 740, 698, 622, 659, 0, 415,
440, 523, 0, 440, 523, 587, 0, 784, 740, 698,
622, 659, 0, 698, 1047, 0, 698, 1047, 698,
1047, 0, 784, 740, 698, 622, 659, 0, 415, 440,
523, 0, 440, 523, 587, 0, 622, 0, 587, 0, 523,
0, 523, 523, 523, 0, 523, 587, 659, 523, 440,
392, 523, 523, 523, 0, 523, 587, 659, 0, 523,
523, 523, 0, 523, 587, 659, 523, 440, 392, 659,
659, 659, 0, 523, 659, 784, 392, 523, 0, 392, 0,
330, 0, 440, 0, 494, 0, 466, 440, 392, 659, 784,
880, 698, 784, 0, 659, 0, 523, 587, 494, 0, 523,
0, 392, 0, 330, 0, 440, 0, 494, 0, 466, 440, 392,
659, 784, 880, 698, 784, 0, 659, 0, 523, 587, 494,
0, 659, 523, 392, 0, 415, 440, 698, 698, 440, 494,
880, 880, 880, 784, 698, 659, 523, 440, 392, 659,
523, 392, 0, 415, 440, 698, 698, 440, 494, 698, 698,
698, 659, 587, 523, 392, 392, 262, 523, 523, 523, 0,
523, 587, 659, 523, 440, 392, 523, 523, 523, 0, 523,
587, 659, 0, 523, 523, 523, 0, 523, 587, 659, 523,
440, 392, 659, 659, 659, 0, 523, 659, 784, 392, 659,
523, 392, 0, 415, 440, 698, 698, 440, 494, 880, 880,
880, 784, 698, 659, 523, 440, 392, 659, 523, 392, 0,
415, 440, 698, 698, 440, 494, 698, 698, 698, 659, 587,
523, 392, 392, 262, 0 };
int noteDurations[] = { 
150, 300, 150, 150, 150, 300, 600, 600, 300, 150, 150, 300,
300, 150, 150, 150, 150, 150, 150, 300, 200, 200, 200, 300,
150, 150, 150, 150, 150, 150, 150, 150, 300, 300, 150, 150,
300, 300, 150, 150, 150, 150, 150, 150, 300, 200, 200, 200,
300, 150, 150, 150, 150, 150, 150, 150, 150, 300, 300, 150,
150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 150, 150,
300, 150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150,
600, 600, 300, 150, 150, 150, 300, 150, 150, 150, 150, 150,
150, 150, 150, 150, 300, 300, 150, 150, 300, 600, 600, 300,
150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 150,
150, 300, 150, 150, 150, 300, 150, 150, 150, 150, 150, 150,
150, 600, 600, 300, 150, 150, 150, 300, 150, 150, 150, 150,
150, 150, 150, 150, 150, 300, 300, 150, 150, 300, 600, 600,
150, 300, 150, 150, 150, 300, 150, 300, 150, 600, 150, 300,
150, 150, 150, 150, 150, 1200, 150, 300, 150, 150, 150, 300,
150, 300, 150, 600, 150, 300, 150, 150, 150, 300, 600, 600,
300, 150, 150, 300, 300, 150, 150, 150, 150, 150, 150, 300,
200, 200, 200, 300, 150, 150, 150, 150, 150, 150, 150, 150,
300, 300, 150, 150, 300, 300, 150, 150, 150, 150, 150, 150,
300, 200, 200, 200, 300, 150, 150, 150, 150, 150, 150, 150,
150, 300, 150, 300, 150, 300, 300, 150, 300, 150, 600, 200,
200, 200, 200, 200, 200, 150, 300, 150, 600, 150, 300, 150,
300, 300, 150, 300, 150, 600, 150, 300, 150, 200, 200, 200,
150, 300, 150, 600, 150, 300, 150, 150, 150, 300, 150, 300,
150, 600, 150, 300, 150, 150, 150, 150, 150, 1200, 150, 300,
150, 150, 150, 300, 150, 300, 150, 600, 150, 300, 150, 150,
150, 300, 600, 600, 150, 300, 150, 300, 300, 150, 300, 150,
600, 200, 200, 200, 200, 200, 200, 150, 300, 150, 600, 150,
300, 150, 300, 300, 150, 300, 150, 600, 150, 300, 150, 200,
200, 200, 150, 300, 150, 600, 0 };
int length = sizeof(melody);
int formatted [1420];


// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
byte Row=0, Col=0;
int speakerPin = D3;



void setup() {
    // put your setup code here, to run once:
  pinMode(10, INPUT); //R1: S1,S2,S3,S4 (1,2,3,A)                                   
  pinMode(11, INPUT_PULLUP); //R2: S5,S6,S7,S8 (4,5,6,B)
  pinMode(12, INPUT_PULLUP); //R3: S9, S10, S11,S12 (7,8,9,C)
  pinMode(13, INPUT_PULLUP); //R4: (*,0,#,D)
  //Pin left to right :R1 R2 R3 R4 C1 C2 C3 C4
  pinMode(speakerPin, OUTPUT);
  digitalWrite(A0,HIGH);
  digitalWrite(A1,HIGH);
  digitalWrite(A2,HIGH);
  digitalWrite(A3,HIGH);
  lcd.begin(16, 2);              // start the library
  lcd.setCursor(0,0);

  for(int i=0;i<length;i++){
    if(melody[i]>=523&&melody[i]<=988)
      formatted[i]=melody[i]/2;
    if(melody[i]>=51046&&melody[i]<=1976)
      formatted[i]=melody[i]/4;
    else
      formatted[i]=melody[i];
  }
}

void loop() {
  byte keyindex=0;
  if(keyscan()==true) 
  {
  play(Row);
  }
}
void play(int row){
   pinMode(speakerPin, OUTPUT);
  for (int thisNote = 0; thisNote < length; thisNote++)
  {    
    tone(speakerPin, formatted[thisNote]*row, noteDurations[thisNote] * .7);    
    delay(noteDurations[thisNote]);    
    noTone(speakerPin);
  }
}


bool keyscan( ){
  Row=0;Col=0;
  bool keypressed = false;
  //scan col1
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);
  //Read keys in row.1
  if(digitalRead(10)==LOW){
      digitalWrite(A0, HIGH);
      Col=1;Row=1;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.2
  if(digitalRead(11)==LOW)
  {
      digitalWrite(A0, HIGH);
      Col=1;Row=2;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.3
  if(digitalRead(12)==LOW)
  {
      digitalWrite(A0, HIGH);
      Col=1;Row=3;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.4
  if(digitalRead(13)==LOW)
  {
       digitalWrite(A0, HIGH);
      Col=1;Row=4;
      keypressed = true;
      return(keypressed);
  }
  //scan col 2  
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);
  //Read keys in row.1
  if(digitalRead(10)==LOW)
  {
      digitalWrite(A1, HIGH);
      Col=2;Row=1;
      keypressed = true;
      return(keypressed);
  }
    //Read keys in row.2
  if(digitalRead(11)==LOW)
  {
      digitalWrite(A1, HIGH);
      Col=2;Row=2;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.3
  if(digitalRead(12)==LOW)
  {
      digitalWrite(A1, HIGH);
      Col=2;Row=3;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.4
  if(digitalRead(13)==LOW)
  {
      digitalWrite(A1, HIGH);
      Col=2;Row=4;
      keypressed = true;
      return(keypressed);
  }

  //scan col 3  
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delayMicroseconds(100);
  //Read keys in row.1
  if(digitalRead(10)==LOW)
  {
      digitalWrite(A2, HIGH);
      Col=3;Row=1;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.2
  if(digitalRead(11)==LOW)
  {
      digitalWrite(A2, HIGH);
      Col=3;Row=2;
      keypressed = true;
      return(keypressed);
  }  
  //Read keys in row.3
  if(digitalRead(12)==LOW)
  {
      digitalWrite(A2, HIGH);
      Col=3;Row=3;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.4
  if(digitalRead(13)==LOW)
  {
      digitalWrite(A2, HIGH);
      Col=3;Row=4;
      keypressed = true;
      return(keypressed);
  }
  
  //scan col 4  
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  delayMicroseconds(100);
  //Read keys in row.1
  if(digitalRead(10)==LOW)
  {
      digitalWrite(A3, HIGH);
      Col=4;Row=1;
      keypressed = true;
      return(keypressed);
  }
    //Read keys in row.2
  if(digitalRead(11)==LOW)
  {
      digitalWrite(A3, HIGH);
      Col=4;Row=2;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.3
  if(digitalRead(12)==LOW)
  {
      digitalWrite(A3, HIGH);
      Col=4;Row=3;
      keypressed = true;
      return(keypressed);
  }
  //Read keys in row.4
  if(digitalRead(13)==LOW)
  {
      digitalWrite(A3, HIGH);
      Col=4;Row=4;
      keypressed = true;
      return(keypressed);
  }
  return(false);
}
