
#include "DigiKeyboard.h"
void setup() {
//delay(5000);
DigiKeyboard.sendKeyStroke('r',MOD_GUI_LEFT);
DigiKeyboard.print("powershell");
delay(1000);
DigiKeyboard.sendKeyStroke(KEY_ENTER);
delay(1000);
DigiKeyboard.println("echo \"I now have full access to the command prompt\"");


}

void loop() {
//DigiKeyboard.sendKeyStroke(1);

}
