// define number of motors
const int motorQuantity = 22;
// define the first pin
const int firstPin = 22;
// define the number of pins
const int totalPins = 20;
// pin array
int motorPin[totalPins];
// // individual motor definitions
// int motor_1[] = {motorPin[1], motorPin[5], motorPin[11], motorPin[15]};
int motor_2[] = {motorPin[1], motorPin[6], motorPin[11], motorPin[16]};
// int motor_3[] = {motorPin[1], motorPin[7], motorPin[11], motorPin[17]};
// int motor_4[] = {motorPin[1], motorPin[8], motorPin[11], motorPin[18]};
// int motor_5[] = {motorPin[1], motorPin[9], motorPin[11], motorPin[19]};
// int motor_6[] = {motorPin[1], motorPin[10], motorPin[11], motorPin[20]};
// int motor_7[] = {motorPin[2], motorPin[5], motorPin[12], motorPin[15]};
// int motor_8[] = {motorPin[2], motorPin[6], motorPin[12], motorPin[16]};
// int motor_9[] = {motorPin[2], motorPin[7], motorPin[12], motorPin[17]};
// int motor_10[] = {motorPin[2], motorPin[8], motorPin[12], motorPin[18]};
// int motor_11[] = {motorPin[2], motorPin[9], motorPin[12], motorPin[19]};
// int motor_12[] = {motorPin[2], motorPin[10], motorPin[12], motorPin[20]};
// int motor_13[] = {motorPin[3], motorPin[5], motorPin[13], motorPin[15]};
// int motor_14[] = {motorPin[3], motorPin[6], motorPin[13], motorPin[16]};
// int motor_15[] = {motorPin[3], motorPin[7], motorPin[13], motorPin[17]};
// int motor_16[] = {motorPin[3], motorPin[8], motorPin[13], motorPin[18]};
// int motor_17[] = {motorPin[3], motorPin[9], motorPin[13], motorPin[19]};
// int motor_18[] = {motorPin[3], motorPin[10], motorPin[13], motorPin[20]};
// int motor_19[] = {motorPin[4], motorPin[5], motorPin[14], motorPin[15]};
// int motor_20[] = {motorPin[4], motorPin[6], motorPin[14], motorPin[16]};
// int motor_21[] = {motorPin[4], motorPin[7], motorPin[14], motorPin[17]};
// int motor_22[] = {motorPin[4], motorPin[8], motorPin[14], motorPin[18]};
// motor array
// int motors[22][4] = {
//   {motorPin[1], motorPin[5], motorPin[11], motorPin[15]},
//   {motorPin[1], motorPin[6], motorPin[11], motorPin[16]},
//   {motorPin[1], motorPin[7], motorPin[11], motorPin[17]},
//   {motorPin[1], motorPin[8], motorPin[11], motorPin[18]},
//   {motorPin[1], motorPin[9], motorPin[11], motorPin[19]},
//   {motorPin[1], motorPin[10], motorPin[11], motorPin[20]},
//   {motorPin[2], motorPin[5], motorPin[12], motorPin[15]},
//   {motorPin[2], motorPin[6], motorPin[12], motorPin[16]},
//   {motorPin[2], motorPin[7], motorPin[12], motorPin[17]},
//   {motorPin[2], motorPin[8], motorPin[12], motorPin[18]},
//   {motorPin[2], motorPin[9], motorPin[12], motorPin[19]},
//   {motorPin[2], motorPin[10], motorPin[12], motorPin[20]},
//   {motorPin[3], motorPin[5], motorPin[13], motorPin[15]},
//   {motorPin[3], motorPin[6], motorPin[13], motorPin[16]},
//   {motorPin[3], motorPin[7], motorPin[13], motorPin[17]},
//   {motorPin[3], motorPin[8], motorPin[13], motorPin[18]},
//   {motorPin[3], motorPin[9], motorPin[13], motorPin[19]},
//   {motorPin[3], motorPin[10], motorPin[13], motorPin[20]},
//   {motorPin[4], motorPin[5], motorPin[14], motorPin[15]},
//   {motorPin[4], motorPin[6], motorPin[14], motorPin[16]},
//   {motorPin[4], motorPin[7], motorPin[14], motorPin[17]},
//   {motorPin[4], motorPin[8], motorPin[14], motorPin[18]}
// };
int motors[motorQuantity][4] = {1,5,11,15,1,6,11,16,1,7,11,17,1,8,11,18,1,9,11,19,2,5,12,15,2,6,12,16,2,7,12,17,2,8,12,18,2,9,12,19,3,5,13,15,3,6,13,16,3,7,13,17,3,8,13,18,3,9,13,19,4,5,14,15,4,6,14,16,4,7,14,17,4,8,14,18,4,9,14,19};
// counters
int count = 0;
int internalCount = 0;
int cycle = 0;
// delay between motor steps
int delayTime = 500;
// loop length
int n = 500;

//Set all pins up as OUTPIUT
void setup() {
  Serial.begin(9600);
  pinInit();
  for (count = firstPin; count < firstPin + totalPins; count++)
  {
    pinMode(motorPin[count], OUTPUT);
  }
}

// Define pins used
void pinInit(){
  for (int p = firstPin; p < firstPin + totalPins; p++)
  {
    motorPin[p] = firstPin + p;
    Serial.print(p);
    Serial.print(motorPin[p]);
  }
}

//The motor number is a parameter
void counterClockWise(int *array) {
  //  internalCount starts at 0
  if ((internalCount == 0) || ( internalCount == 1))
  //  If the internal count is 0 or 1, make it 16
  {
    internalCount = 16;
  }
  //  Bitshift the internal count one digit to the right.
  internalCount>>=1;
  //  For loop counting down from 3 to 0
  for (count = 3; count >= 0; count--)
  //  Turn pins on or off.
  //  Take the last bit of the count value (hexadecimal masking)
  //  Bit shift the internalCount value by the masked count (0 or 1)
  {
    digitalWrite(array[count], internalCount>>count&0x01);
  }

  Serial.print(count);
  delay(delayTime);
}

// same as counter-clock-wise motion, with the exception of the digital write
void clockWise(int *array) {
  if ((internalCount == 0) || (internalCount == 1))
  {
    internalCount = 16;
  }

  internalCount>>=1;

  for (count = 3; count >= 0; count--)
  // assign values backwards
  {
    digitalWrite(array[3 - count], internalCount>>count&0x01);
  }

  delay(delayTime);
}

void loop() {
  // Keep track of cycle number
  cycle++;
  Serial.print(cycle);

  // Keep track of motor number
  for (int motor = 0; motor < motorQuantity; motor++)
  {
    // Rotate CCW, then CW
    for (int i = 0; i < n; i++)
    {
      // if statement serves to place commas between i valuesprint counter-clockwise at the end of the loop
      if(i == (n-1))
      {
        Serial.print(i + " counter-clockwise.");
        // execute ccw function
        counterClockWise(motors[motor]);
      } else
      {
        Serial.print(i + ", ");
        // execute ccw function
        counterClockWise(motors[motor]);
      }
    }

    for (int b=0; b < n; b++)
    {
      if(b==(n-1))
      {
        Serial.print(b);
        Serial.print(" clockwise.");
        clockWise(motors[motor]);
      } else
      {
        Serial.print(b);
        Serial.print(", ");
        clockWise(motors[motor]);
      }
    }
  }

  Serial.println("loop");
  // wait before looping
  delay(100*delayTime);
}

