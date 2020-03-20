
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

void spray()
{
  digitalWrite(sprayPin, LOW);
}

void stopSpray()
{
  digitalWrite(sprayPin, HIGH);
}
