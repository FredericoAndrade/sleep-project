int motorPins[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42};
int motor_1_Pins[] = {1, 5, 11, 15};
int motor_2_Pins[] = {1, 6, 11, 16};
int motor_3_Pins[] = {1, 7, 11, 17};
int motor_4_Pins[] = {1, 8, 11, 18};
int motor_5_Pins[] = {1, 9, 11, 19};
int motor_6_Pins[] = {1, 10, 11, 20};
int motor_7_Pins[] = {2, 5, 12, 15};
int motor_8_Pins[] = {2, 6, 12, 16};
int motor_9_Pins[] = {2, 7, 12, 17};
int motor_10_Pins[] = {2, 8, 12, 18};
int motor_11_Pins[] = {2, 9, 12, 19};
int motor_12_Pins[] = {2, 10, 12, 20};
int motor_13_Pins[] = {3, 5, 13, 15};
int motor_14_Pins[] = {3, 6, 13, 16};
int motor_15_Pins[] = {3, 7, 13, 17};
int motor_16_Pins[] = {3, 8, 13, 18};
int motor_17_Pins[] = {3, 9, 13, 19};
int motor_18_Pins[] = {3, 10, 13, 20};
int motor_19_Pins[] = {4, 5, 14, 15};
int motor_20_Pins[] = {4, 6, 14, 16};
int motor_21_Pins[] = {4, 7, 14, 17};
int motor_22_Pins[] = {4, 8, 14, 18};
int count = 0;
int internalCount = 0;
int delayTime = 500;
int val = 0;
int n = 500;

//Set all pins up as OUTPIUT
void setup() {
  Serial.begin(9600);
  for (count = 22; count < 42; count++) {
  pinMode(motorPins[count], OUTPUT);
  }
}

//counter-clock-wise motion
//The motor number is a parameter
void counterClockWise(int *array) {
  //  internalCount starts at 0
  if ((internalCount == 0) || ( internalCount == 1)) {
  //  If the internal count is 0 or 1, make it 16
  internalCount = 16;
  }
//  Bitshift the internal count one side to the right.
// if 16,
  internalCount>>=1;
//  For loop counting down from 3 to 0
  for (count = 3; count >= 0; count--) {
//  Turn pins on or off.
//  Take the last bit of the count value (hexadecimal masking)
//  Bit shift the internalCount value by the masked count (0 or 1)
  digitalWrite(array[count], internalCount>>count&0x01);
  }
  Serial.print(count);
  delay(delayTime);
}

// same as counter-clock-wise motion, with the exception of the digital write
void clockWise(int *array) {
  if ((internalCount == 0) || (internalCount == 1)) {
  internalCount = 16;
  }
  internalCount>>=1;
  for (count = 3; count >= 0; count--) {
    // assign values backwards
  digitalWrite(array[3 - count], internalCount>>count&0x01);
  }
  delay(delayTime);
}

void loop() {
  for (int i=0; i < n; i++) {
    // if statement serves to place commas between i valuesprint counter-clockwise at the end of the loop
    if(i==(n-1)){
      Serial.print(i + " counter-clockwise.");
    // execute ccw function
      counterClockWise(motor_1_Pins);
    } else {
      Serial.print(i + ", ");
    // execute ccw function
      counterClockWise(motor_1_Pins);
    }
  }

  for (int b=0; b < n; b++) {
    if(b==(n-1)){
      Serial.print(b);
      Serial.print(" clockwise.");
      clockWise(motor_1_Pins);
    } else {
      Serial.print(b);
      Serial.print(", ");
      clockWise(motor_1_Pins);
    }
  }

  Serial.println("loop");
  // wait before looping
  delay(100*delayTime);
}

