if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  //|| content.substring(1) == "5A 3F 0E 0B"
  if (content.substring(1) == "5A A8 D6 0B" )
  {
    Serial.println("Authorized Personnel");
    s1.write(90);
    delay(3000);
    s1.write(0);
  }
 else   {
    Serial.println("Access denied");
  }
