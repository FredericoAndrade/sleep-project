int motorPins[] = {1, 2, 3, 4, 5, 6, 7, 8};
int motor_1_Pins[] = {1, 3, 6, 8};
int motor_2_Pins[] = {2, 3, 5, 8};
int motor_3_Pins[] = {1, 4, 6, 7};
int motor_4_Pins[] = {2, 4, 5, 7};
int count = 0;
int internalCount = 0;
int delayTime = 500;
int val = 0;
int n = 500;

//Set all pins up as OUTPIUT
void setup() {
  Serial.begin(9600);
  for (count = 0; count < 8; count++) {
  pinMode(motorPins[count], OUTPUT);
  }
}

//Counter clock-wise motion
//You can declare the array when calling the function
void counterClockWise(int *array) {
//  If the internal count is 0 or 1
  if ((internalCount == 0) || ( internalCount == 1)) {
//  Then make it 16
  internalCount = 16;
  }
//  Bitshift the internal count one side to the right.
  internalCount>>=1;
//  For loop counting down from 3 to 0
  for (count = 3; count >= 0; count--) {
//  Pass values to pins.
  digitalWrite(array[count], internalCount>>count&0x01);
  }
  Serial.print(count);
  delay(delayTime);
}

void clockWise(int *array) {
  if ((internalCount == 0) || (internalCount == 1)) {
  internalCount = 16;
  }
  internalCount>>=1;
  for (count = 3; count >= 0; count--) {
  digitalWrite(array[3 - count], internalCount>>count&0x01);
  }
  delay(delayTime);
}

void loop() {
  for (int i=0; i < n; i++) {
  if(i==(n-1)){
//    Serial.print(i);
    Serial.print(" counter-clockwise.");
    counterClockWise(motor_1_Pins);
  } else {
//    Serial.print(i);
    Serial.print(", ");
    counterClockWise(motor_1_Pins);
  }
  }
//  for (int b=0; b < n; b++) {
//  if(b==(n-1)){
//    Serial.print(b);
//    Serial.print(" clockwise.");
//    clockWise(motor_1_Pins);
//  } else {
//    Serial.print(b);
//    Serial.print(", ");
//    clockWise(motor_1_Pins);
//  }
//  }
//  Serial.println("loop");
  delay(100*delayTime);
  }




