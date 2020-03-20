/*
* CPSC 581 Project 3
* 
* Statue Control
* By Sarah, Erika, and Valerie
*
* This program uses an ultrasonic sensor, a windshield wiper fluid motor, and two LED's to 
* deter statue thieves. The sensor is used to detect when someone approaches 
* the statue, and within a certain distance threshold it will trigger the motor to spray the
* persorn and flash the LEDs to scare them away.
*
*/

// Approximately 30 activations of the spray before water runs out
// This is to ensure that we don't burn out the motor
#define ALLOWABLE_RUNS 30

// The minimum allowable distance between the statue and another object/person/thing
// before the spray gets triggered 
#define DISTANCE_THRESHOLD 40

//--------- Hardware Pins -----------------
const int trigPin = 2;    // Ultrasonic sensor
const int echoPin = 4;    // Ultrasonic sensor

const int sprayPin = 7;   // Spray motor

const int eyePinOne = 10; // LED
const int eyePinTwo = 12; // LED
//-----------------------------------------


// The amount of sprays that have gone already
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
  
}
void loop() {

  // Distance between statue and another object infront of sensor
  int distance = getDistance();
  
  // If within distance threshold and within the amount
  // of allowable runs, then spray
  if(distance < DISTANCE_THRESHOLD && runs < ALLOWABLE_RUNS)
  {  
    spray();
    flashEyes(3);
    stopSpray();
    flashEyes(3);
    
    runs++;
  }

}
