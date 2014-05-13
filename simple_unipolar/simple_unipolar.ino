#include <Stepper.h>

  
Stepper myStepper(360 , 8, 9, 10, 11);

void setup() {

  myStepper.setSpeed(36);
}

void loop() {
myStepper.step(1);

//  delay(500);
}
