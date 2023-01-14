int waterlevel = analogRead(respin);
  Serial.print("Water Level: ");
  Serial.println(waterlevel);
  if(waterlevel<=50){
    digitalWrite(respwmpin, HIGH);
    }
    else{
      digitalWrite(respwmpin, LOW);
      }
