#include <dht.h>

dht DHT;
//input
int dhtpin = 2;
int ldrpin = A0;
int foodpin = A3;
int respin = A1;
int mq2pin = A2;
//output
int respwmpin = 3;
int foodpwmpin = 10;
int alertpin = 7;
int ledpin = 6;
int fanpin = 4;

float sensorValue;  //variable to store sensor value

void setup(){
  Serial.begin(9600);
  
  pinMode(ldrpin, INPUT);
  pinMode(dhtpin, INPUT);
  pinMode(respin, INPUT);
  pinMode(mq2pin, INPUT);
  
  pinMode(respwmpin, OUTPUT);
  pinMode(alertpin, OUTPUT);
  pinMode(ledpin, OUTPUT);
  pinMode(fanpin, OUTPUT);
}

void loop(){

  //Humidity
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
  
  //MQ2
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

  //Water 
  int waterlevel = analogRead(respin);
  Serial.print("Water Level: ");
  Serial.println(waterlevel);
  if(waterlevel<=50){
    digitalWrite(respwmpin, HIGH
    
    );
    }
    else{
      digitalWrite(respwmpin, LOW);
      }

     //Food 
  int foodlevel = analogRead(foodpin);
  Serial.print("Food Level: ");
  Serial.println(foodlevel);
  if(foodlevel<=50){
    digitalWrite(foodpwmpin, HIGH);
    }
    else{
      digitalWrite(foodpwmpin, LOW);
      }

   //LDR
   int lux = analogRead(ldrpin);
   Serial.print("Lux : ");
   Serial.println(lux);
   if(lux<=20){
    digitalWrite(ledpin,HIGH);
    }
    else{
    digitalWrite(ledpin,LOW);
    }

   delay(2000);
}
