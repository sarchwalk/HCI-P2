/*
* CPSC 581 Project 3
* 
* Police Cam
* 
* By Sarah, Erika, and Valerie
*
*/

// Approximately 35 activations of the spray before water runs out
// This is to ensure that we don't burn out the motor
#define ALLOWABLE_RUNS 30

// 
//
#define DISTANCE_THRESHOLD 40

//--------- Hardware Pins -----------------
const int trigPin = 2;
const int echoPin = 4;


const int sprayPin = 7;

const int eyePinOne = 10;
const int eyePinTwo = 12;
//-----------------------------------------


// Testing things
int runs = 0;

void setup() {

  //-------- Hardware Requirements ---------
  // Ultrasonic sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Setup spray
  pinMode(sprayPin, OUTPUT);
  stopSpray();

  // Setup eye LEDs
  pinMode(eyePinOne, OUTPUT);
  pinMode(eyePinTwo, OUTPUT);
  //----------------------------------------
  
  Serial.begin(9600);
}
void loop() {


  int distance = getDistance();
  
  // If within 40 cm activite the shooter and within the amount
  // of allowable runs, then spray
  if(distance < DISTANCE_THRESHOLD && runs < ALLOWABLE_RUNS)
  {  
    Serial.println(distance);
    spray();
    flashEyes(3);
    stopSpray();
    flashEyes(3);
    
    runs++;
  }

}
