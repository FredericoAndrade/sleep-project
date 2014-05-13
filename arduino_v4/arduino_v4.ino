const int dataset[132]={
  0.19, 0.02, 0.51, 0.64, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.57, 0.57, 0.59, 0.54, 0.79, 0.56, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.49, 0.47, 0.70, 0.51, 0.90, 0.79, 0.41, 0.65, 0.82, 0.54, 0.63, 0.72, 0.65, 0.56, 0.72, 0.56, 0.60, 0.49, 0.49, 0.82, 0.42, 0.54, 0.54, 0.45, 0.54, 0.42, 0.54, 0.44, 0.44, 0.48, 0.39, 0.65, 0.34, 0.68, 0.39, 0.61, 0.65, 0.54, 0.71, 0.45, 0.49, 0.58, 0.47, 0.46, 0.50, 0.46, 0.40, 0.56, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.48, 0.37, 0.67, 0.57, 0.46, 0.67, 0.46, 0.68, 0.61, 0.70, 0.37, 0.51, 0.37, 0.56, 0.48, 0.59, 0.66, 0.52, 0.67, 0.48, 0.75, 0.99, 0.70, 0.42, 0.53, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.44, 0.70, 0.80, 0.41, 0.65, 0.47, 0.58, 0.48, 0.54, 0.41, 0.41, 0.56};
// physical size of sculpture in inches
const int availableHeight = 12;
const int circumference = 2.36;
int graphData[132];
// define number of motors
const int motorQuantity = 22;
// define the first pin
const int firstPin = 22;
// define the number of pins
const int totalPins = 20;
// pin array
int motorPin[totalPins];
// multiplexing matrix
// [22][4] matrix where each row is a motor and each column is a pin
int motors[motorQuantity][4] = {
  1,5,11,15,1,6,11,16,1,7,11,17,1,8,11,18,1,9,11,19,2,5,12,15,2,6,12,16,2,7,12,17,2,8,12,18,2,9,12,19,3,5,13,15,3,6,13,16,3,7,13,17,3,8,13,18,3,9,13,19,4,5,14,15,4,6,14,16,4,7,14,17,4,8,14,18,4,9,14,19};
// counters
int count = 0;
int internalCount = 0;
int cycle = 0;
// delay between motor steps
int delayTime = 500;
// loop length
int n = 64*8;

//Set all pins up as OUTPUT
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
  for (int p = firstPin; p < firstPin+totalPins-1; p++)
  {
    motorPin[p] = firstPin + p;
    Serial.print(p);
    Serial.print(motorPin[p]);
  }
}

// take the dataset and convert it to physical values
void scaleData(){
  for (int index = 0; index < 132; index++)
  {
    graphData[index] = dataset[index] * availableHeight;
    Serial.print(dataset[index], graphData[index]);
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

  Serial.print(count);
  delay(delayTime);
}

void loop() {
  // Keep track of motor number
  for (int motor = 0; motor < motorQuantity; motor++)
  {
    int data = graphData[motor+cycle];
    int prev = graphData[motor+cycle-1];
    int deviation = prev-data;
    Serial.print(data, prev);

    // make it work

    // Rotate CCW, then CW
    for (int i = 0; i < n; i++)
    {
      // CCW for n duration
      // Clarify how motors[motor] works
      counterClockWise(motors[motor]);
    }

    for (int b=0; b < n; b++)
    {
      // CW for n duration
      clockWise(motors[motor]);
    }
  }

  Serial.println("loop");

  delay(100*delayTime);

  // Keep track of cycle number
  cycle++;
  Serial.print(cycle);
}

