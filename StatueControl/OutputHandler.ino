
/*
 * Blinks two LEDs on and off with a 100ms delay between on and off states
 * Accepts number of repeats as an int
 *  Note: the total time spent in this function will be repeats*200ms 
 */
void flashEyes(int repeats)
{
  for(int i = 0; i < repeats; i++)
  {
    digitalWrite(eyePinOne,HIGH);
    digitalWrite(eyePinTwo,HIGH);
    delay(100);
    digitalWrite(eyePinOne,LOW);
    digitalWrite(eyePinTwo,LOW);
    delay(100);
  }
}

/*
 * Turns on the water spraying motor
 */
void spray()
{
  digitalWrite(sprayPin, LOW);
}

/*
 * Turns off the water spraying motor
 */
void stopSpray()
{
  digitalWrite(sprayPin, HIGH);
}
