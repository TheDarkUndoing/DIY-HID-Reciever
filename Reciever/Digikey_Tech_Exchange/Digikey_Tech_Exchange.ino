
#include "DigiKeyboard.h"
void setup() {

DigiKeyboard.sendKeyStroke('r',MOD_GUI_LEFT);
DigiKeyboard.println("powershell");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
delay(5000);
DigiKeyboard.println("echo \"I now have full access to the command prompt\"");


}

void loop() {
//DigiKeyboard.sendKeyStroke(1);

}
