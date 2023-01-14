int sensor_pin = A0; //  Sensor input at Analog PIN A0
int output_value ;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
     Serial.begin(9600);
   Serial.println("Reading From the Sensor ...");
}



  void loop() {
   output_value= analogRead(sensor_pin);
   Serial.print("Moisture : ");
   Serial.print(output_value);
    Serial.println("");
   if(output_value<400){
      digitalWrite(3,HIGH);
     }
     else{
            digitalWrite(3,LOW);
     }
   delay(100);
  }
