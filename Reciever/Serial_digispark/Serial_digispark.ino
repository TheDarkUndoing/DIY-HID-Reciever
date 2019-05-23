

#include "DigiKeyboard.h"
#include <SoftSerial_INT0.h>
// ***
// *** Define the RX and TX pins. Choose any two
// *** pins that are unused. Try to avoid D0 (pin 5)
// *** and D2 (pin 7) if you plan to use I2C.
// ***
#define RX    2   
#define TX    1   // *** D4, Pin 3

// ***
// *** Define the software based serial port. Using the
// *** name Serial so that code can be used on other
// *** platforms that support hardware based serial. On
// *** chips that support the hardware serial, just
// *** comment this line.
// ***
SoftSerial mySerial(RX, TX);
void endT();

void setup() {
   // ***
  // *** Initialize the Serial port
  // ***
  mySerial.begin(115200);
  DigiKeyboard.delay(5000);
  
  
  
}

void loop() {
  DigiKeyboard.update();
  char b;
  
  while (mySerial.available() > 0) {
    DigiKeyboard.print(mySerial.available());
    b = mySerial.read();
    
    DigiKeyboard.print(b);
  }
  
  
 

  
  }
  
  
    
  
