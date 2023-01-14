int smokevalue = analogRead(mq2pin); // read analog input pin 0
  Serial.print("Smoke Value: ");
  Serial.println(smokevalue);

  if((temperature >= 25) || (sensorValue >= 180)){
    digitalWrite(alertpin, HIGH);
    delay(500);
    digitalWrite(alertpin, LOW);
    }
    else{
      digitalWrite(alertpin, LOW);
      }    

int chk = DHT.read11(dhtpin);
  Serial.print("Room Temperature = ");
  int temperature = DHT.temperature;
  Serial.println(DHT.temperature);
  Serial.print("Room Humidity = ");
  int humidity = DHT.humidity;
  Serial.println(DHT.humidity);
  if((temperature >= 25) || humidity>=95){
    digitalWrite(fanpin, HIGH);
    }
   else{
    digitalWrite(fanpin, LOW);
    }
