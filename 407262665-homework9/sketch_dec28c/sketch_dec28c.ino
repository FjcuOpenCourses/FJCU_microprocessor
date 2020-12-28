
#define LATCH_DIO D15     
#define CLK_DIO D14
#define DATA_DIO 2
#define BUTTON1 BT1
#define BUTTON2 BT2
#define BUTTON3 BT3
#define BUTTON4 BT4
#define BUTTON_A1 A1
#define BUTTON_A2 A2
#define BUTTON_A3 A3/* Segment byte maps for numbers 0 to 9 , A, b , C*/
const byte SEGMENT_MAP[] = {0x3F,0x06,0x3C,0x4F,0x66,0x6D,0x7D,0x07,0X7F,0X6F,0X77,0X7C,0X39};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xFE,0xFD,0xFB,0xF7};
int curr=16;
void setup (){/* Set DIO pins to outputs */
pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO,OUTPUT);
pinMode(DATA_DIO,OUTPUT);

}/* Main program */
void loop(){
  
  while(!digitalRead(BUTTON1)){
    curr=3;
    WriteNumberToSegment(3 , 3);}   
  while(!digitalRead(BUTTON2)){
     curr=2;
    WriteNumberToSegment(2 ,3);} 
  while(!digitalRead(BUTTON3)){
     curr=1;
    WriteNumberToSegment(1 , 5);}   
  while(!digitalRead(BUTTON4)){
     curr=0;
    WriteNumberToSegment(0 , 6);} 
  while(!digitalRead(BUTTON_A1)){
     curr=0;
    WriteNumberToSegment(0 , 10);} 
  while(!digitalRead(BUTTON_A2)){
     curr=1;
    WriteNumberToSegment(1 , 11);}
  while(!digitalRead(BUTTON_A3)){WriteNumberToSegment(2 , 12);}

delay(500);
 WriteNumberToSegment((curr)%4, 8);
 if(curr==0)
    curr=16;
 else
   curr--;
  delay(500);
  }
  /* Write a decimal number between 0 and 9 to one of the 4 digits of the display */
  void WriteNumberToSegment(byte Segment, byte Value){
    digitalWrite(LATCH_DIO,LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
    digitalWrite(LATCH_DIO,HIGH);
}
