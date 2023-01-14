int motion=digitalRead(pirpin);
  Serial.print("Motion Detected : ");
  Serial.println(motion);
  if(motion==0){          //Wait
  digitalWrite(alertpin,HIGH);
  }else{      
  digitalWrite(alertpin,LOW); 
}
