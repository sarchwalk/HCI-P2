/*
 * Calculates the distance from sensor to another object
 * in cm
 * Returns the distance in cm
 */
int getDistance()
{
  int distance;

  distance = readUltrasonicSensor()*0.034/2;
  
  return distance;
}


/*
 * Sends a burst and determines the time required to recieve it back
 * Returns the amount of time the burst takes to return to the sensor
 */
int readUltrasonicSensor()
{
  long duration;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Recieve message
  duration = pulseIn(echoPin, HIGH);

  return duration;
}
