#define SIZE 16
int LED[SIZE]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
void setup() {
  for(int i=15;i>=0&&i!=3;i--)
      pinMode(i, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {


  
  for(int i=15;i>=0;i--){
        display(0xAAAA);
        delay(300);
        display(0x5555);
        delay(300);
  }
    delay(2000);
    
  for(int i=15;i>=0;i--){
    display(0xffff);
    delay(300);
    display(0x0000);
    delay(300);
    }
}
void display(int number){
  unsigned tmp = number & 0xffff;
  for(int i=0;i<SIZE;i++){
    if(tmp & 0x1){
      digitalWrite(LED[i],HIGH);
   //    delay(10);
    } 
    else{
      digitalWrite(LED[i],LOW);
 //     delay(10);
    } 
    tmp>>=1;
  }
}

