int lux = analogRead(ldrpin);
   Serial.print("Lux : ");
   Serial.println(lux);
   if(lux<=20){
    digitalWrite(ledpin,HIGH);
    }
    else{
    digitalWrite(ledpin,LOW);
    }
