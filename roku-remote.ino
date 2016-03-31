/*
* roku-remote.ino: A quick and dirty infrared Roku remote
*
* Sends directional and selection commands by IR LED to an
* infrared-controlled Roku.
*
* An IR LED must be connected to Arduino PWM pin 3.
* Uses the IRremote library:
*   https://github.com/z3t0/Arduino-IRremote
*/

#include <IRremote.h>

IRsend irsend;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    switch (Serial.read()) {
      case ' ':
        Serial.println("Select");
        irsend.sendNEC(0x7DF7C03F, 32);
        break;
      case 'w':
        Serial.println("Up");
        irsend.sendNEC(0x7DF7807F, 32);
        break;
      case 'a':
        Serial.println("Back");
        irsend.sendNEC(0x7DF740BF, 32);
        break;
      case 's':
        Serial.println("Down");
        irsend.sendNEC(0x7DF7A05F, 32);
        break;
      case 'd':
        Serial.println("Forward");
        irsend.sendNEC(0x7DF720DF, 32);
        break;
      default:
        Serial.println("?");
    }
  }
}
