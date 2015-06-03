#include <Arduino.h>

int i=0;

void setup() 
{

  Serial.begin(57600);
  pinMode(13,OUTPUT);

}

void loop() {
  
  i++;
  Serial.write(i);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13,LOW);
  delay(200);

}
