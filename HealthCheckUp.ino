bpm =  0;

  if(analogRead(pulsepin)>=threshold){
    while(analogRead(pulsepin)>=threshold){
      if((analogRead(pulsepin)-threshold)>=20){
        threshold=threshold+5;
        }
    }
    tnew = millis();
    }
    bpm = tnew-told;
    told=tnew;
    bpm=(bpm/1000);
    bpm=(60/bpm);
    if(bpm!=0 && bpm<120 && bpm>60){
      
      Serial.print("BPM : ");
      Serial.println(bpm);
      
      Serial.print("Threshold : ");
      Serial.println(threshold);
      Sending_To_phpmyadmindatabase();                    
    }
    else{
      threshold=threshold-10;
    }
