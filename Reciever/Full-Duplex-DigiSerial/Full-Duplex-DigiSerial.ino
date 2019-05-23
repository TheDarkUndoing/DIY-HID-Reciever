#include <SoftSerial_INT0.h>
#include <DigiKeyboard.h>


#define RX    2   
#define TX    1
#define ACK   6

SoftSerial Serial_0(RX, TX);
SoftSerial Serial_1(RX, TX);

void setup() {
   
   Serial_0.begin(115200); // Main
   Serial_1.begin(115200); // ACK
///FIX msg Overflow
}
unsigned char b;
bool rcv;
char msg[64];
unsigned short count = 0;
void loop() {
  DigiKeyboard.update();
  

  
  while (Serial_1.available()) {
    b = Serial_1.read();
    if(b != 6){
    count = count + 1;
    Serial_1.write(b);
    msg[count] = b;
    
    
    }
    else{
       rcv = true;
       count = 0;
      }
    
    
  }
  
  
      
     
    
  if (rcv){
    //Serial_1.write(ACK);
    for(int i=0;i <= sizeof(msg);i++){
    DigiKeyboard.print(msg[i]);
    rcv = false;
    }
    }

}
