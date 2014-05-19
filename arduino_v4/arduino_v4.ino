const int graphData[132] ={
  0,1,5,6,5,5,5,5,5,5,6,6,6,5,8,6,5,5,5,5,5,5,5,5,5,5,5,5,5,7,5,9,8,4,7,8,5,6,7,7,6,7,6,6,5,5,8,4,5,5,4,5,4,5,4,4,5,4,6,3,7,4,6,7,5,7,5,5,6,5,5,5,5,4,6,5,5,5,5,5,5,5,5,5,5,5,4,7,6,5,7,5,7,6,7,4,5,4,6,5,6,7,5,7,5,8,10,7,4,5,4,4,4,4,4,4,4,4,4,4,4,7,8,4,6,5,6,5,5,4,4,6};
// physical size of sculpture in inches
const int availableHeight = 10;
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
  {22,25,32,36},
  {22,27,32,37},
  {22,28,32,38},
  {22,29,32,39},
  {22,30,32,40},
  {22,31,32,41},
  {23,25,33,36},
  {23,27,33,37},
  {23,28,33,38},
  {23,29,33,39},
  {23,30,33,40},
  {23,31,33,41},
  {24,25,34,36},
  {24,27,34,37},
  {24,28,34,38},
  {24,29,34,39},
  {24,30,34,40},
  {24,31,34,41},
  {25,25,35,36},
  {25,27,35,37},
  {25,28,35,38},
  {25,29,35,39}};
// counters
int count = 0;
int internalCount = 0;
int cycle = 0;
// delay between motor steps
int delayTime = 500;
// loop length
const int circumference = 2.36;
int fullCircle = 2048;
int inch = 878;
int n;


//Set all pins up as OUTPUT
void setup() {
  Serial.begin(9600);
  // Delay here to have time to open the console monitor in peace
  delay(1000);
  //  Serial.print("Initializing. ");
  pinInit();
  for (int init = 0; init < totalPins; init++)
  {
  //  Serial.print("Pin ");
  //  Serial.print(motorPin[init]);
  //  Serial.print(". ");
  pinMode(motorPin[init+firstPin], OUTPUT);
  }
  Serial.println("All pins to output. ");
}

// Define pins used
void pinInit(){
  //  Serial.print("Pin Init... ");
  for (int p = 0; p < 20; p++)
  {
  motorPin[p] = firstPin+p;
  }
}

// take the dataset and convert it to physical values
void scaleData(){
  for (int index = 0; index < 132; index++)
  {
  Serial.print("Index ");
  Serial.print(index);
  Serial.print(" = ");
//  Serial.print(dataset[index]);
  Serial.print(". ");
//  graphData[index] = dataset[index] * availableHeight;
//  Serial.print(dataset[index], graphData[index]);
  }
  Serial.print("Data scaled. ");
}

//The motor number is a parameter
void counterClockWise(int *array) {
  // internalCount starts at 0
  if ((internalCount == 0) || ( internalCount == 1))
  // If the internal count is 0 or 1, make it 16
  {
  internalCount = 16;
  }
  // Bitshift the internal count one digit to the right.
  internalCount>>=1;
  // For loop counting down from 3 to 0
  for (count = 3; count >= 0; count--)
  // Turn pins on or off.
  // Take the last bit of the count value (hexadecimal masking)
  // Bit shift the internalCount value by the masked count (0 or 1)
  {
  digitalWrite(array[count], internalCount>>count&0x01);
  }

  //  Serial.print(count);
  delay(1);
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

  //  Serial.print(count);
  delay(1);
}

void loop() {
  Serial.print(" Cycle ");
  Serial.print(cycle);
  Serial.println(".");
  // Keep track of motor number
  for (int motor = 0; motor < 22; motor++)
  {
  int data = graphData[motor+cycle];
  int prev = graphData[motor+cycle-1];
  int deviation = data-prev;
  Serial.print("  Motor_");
  Serial.print(motor);
  Serial.print(". Data: ");
  Serial.print(data);

  if (data != 0 && deviation > 0)
  {
    Serial.print(". Deviation = ");
    Serial.print(deviation);
    Serial.print(". Total Rotations: ");
    Serial.print(inch*deviation);
    Serial.print(". Rotation: ");
    for (int i = 0; i < inch*deviation; i++)
    {
      // CCW for n duration
      // Clarify how motors[motor] works
      counterClockWise(motors[motor]);
      Serial.print(i);
      Serial.print(",");
    }
  }
  
  if (data != 0 && deviation < 0)
  {
    Serial.print(". Deviation = ");
    Serial.print(deviation);
    Serial.print(". Total Rotations: ");
    Serial.print(inch*deviation);
    Serial.print(". Rotation: ");
    for (int i = inch*deviation; i < 0; i++)
    {
      // CCW for n duration
      // Clarify how motors[motor] works
      clockWise(motors[motor]);
      Serial.print(i);
      Serial.print(",");
    }
  }
  
  if (data = 0)
  {
    Serial.print(". Nothing to do!");
  }

  
    Serial.println(" ");
  }

//  delay(1000);

  // Keep track of cycle number
  cycle++;

  Serial.println("End cycle");
}





