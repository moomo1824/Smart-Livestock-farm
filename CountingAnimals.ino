long time;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  time = pulseIn(echo, HIGH);
  dis_a = time / 29 / 2;
  delay(30);
  int statIRSensor = digitalRead (IR);
  Serial.print("da: "); Serial.println(dis_a); 
  Serial.print("ir: "); Serial.println(statIRSensor);
  if (dis_a < 12 && flag1 == 0) {
    flag1 = 1;
    if (flag2 == 0) {
      person = person + 1;
      digitalWrite(cntup,HIGH);
    }
  }
if (statIRSensor == 0  && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      if(person >= 1)
      person = person - 1;
      digitalWrite(cntdw,HIGH);
    }
  }
  if (dis_a > 12 && statIRSensor == 0 && flag1 == 1 && flag2 == 1) {
    flag1 = 0, flag2 = 0;
    delay(1000);
  }
