/*
* CPSC 581 Project 3
* 
* Police Cam
* 
* By Sarah, Erika, and Valerie
*
*/

//--------- Hardware Pins -----------------
const int trigPin = 3;
const int echoPin = 2;

const int buttonPin = 4;
//-----------------------------------------


void setup() {

  //-------- Hardware Requirements ---------
  // Ultrasonic sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Button Setup
  pinMode(buttonPin,INPUT_PULLUP);
  //----------------------------------------
  
  Serial.begin(9600);
}
void loop() {
  
  // If button is pressed (safety is off), then check the distance
  if(buttonPressed())
  {
    //if(getDistance() < a specified distance in cm)
    //trigger the spray
  } 
}
