#include "DigiKeyboard.h" 
#include "TinyWireS.h"



void setup() {
  TinyWireS.begin(8); 
  TinyWireS.onReceive(receiveEvent);
  DigiKeyboard.delay(5000);
           
  
}

void loop() {
    DigiKeyboard.sendKeyStroke(0); 
}


void receiveEvent(uint8_t msgSize) {
  DigiKeyboard.sendKeyStroke(0);
  
  char c;
  
  while (0< TinyWireS.available()) { 
    c = TinyWireS.receive();
    
    DigiKeyboard.print(c); 
          
  }
  //DigiKeyboard.print('\n');
  DigiKeyboard.print(msgSize);
 // DigiKeyboard.print('\n');
}
