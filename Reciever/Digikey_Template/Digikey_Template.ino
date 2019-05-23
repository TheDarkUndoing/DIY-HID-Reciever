#include "DigiKeyboard.h"
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
DigiKeyboard.sendKeyStroke(1);

DigiKeyboard.println("TESTTT");
DigiKeyboard.delay(1000);
}
