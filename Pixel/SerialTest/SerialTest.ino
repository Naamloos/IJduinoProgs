String testString = "";
void setup() 
{
  Serial.begin(57600);
  testString = "Pixel";
}

void loop() 
{
  Serial.println(testString);
  delay(300);
  for(int i=0;i<10;i++)
  {
     Serial.println(i);
     delay(300);
  }
}
