#include <Stepper.h>
// pilotage de 4 moteurs sur Nano avec une telecommande IR

#include "IRremote.hpp"

#define IR_RECEIVE_PIN 19

int stepsPerRevolution = 2048;


Stepper myStepper1(stepsPerRevolution, 2, 4, 3, 5);
Stepper myStepper2(stepsPerRevolution, 6, 8, 7, 9);
Stepper myStepper3(stepsPerRevolution, 10, 12, 11, 14);
Stepper myStepper4(stepsPerRevolution, 15, 17, 16, 18);

void setup() {
  myStepper1.setSpeed(5);
  myStepper2.setSpeed(5);
  myStepper3.setSpeed(5);
  myStepper4.setSpeed(5);
  
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  // initialize the serial port pour tests :
  Serial.begin(9600);
}

void loop() {
  if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
    Serial.println(command);    // pour tests
    if (command == 69) {        // 1
      myStepper1.step(5);
    } else if (command == 71) { // 3
      myStepper1.step(-5);
    } else if (command == 68) { // 4
      myStepper2.step(5);
    } else if (command == 67) { // 6
      myStepper2.step(-5);    
    } else if (command == 7) {  // 7
      myStepper3.step(5);    
    } else if (command == 9) {  // 9
      myStepper3.step(-5);    
    } else if (command == 22) { // *
      myStepper4.step(5);    
    } else if (command == 13) { // #
      myStepper4.step(-5);    
    }
    
    IrReceiver.resume();
  }
}
