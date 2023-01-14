int foodlevel = analogRead(foodpin);
  Serial.print("Food Level: ");
  Serial.println(foodlevel);
  if(foodlevel<=50){
    digitalWrite(foodpwmpin, HIGH);
    }
    else{
      digitalWrite(foodpwmpin, LOW);
      }
