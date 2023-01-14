  
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

//PIR
int pirpin = 7;
int alertpin = 2;

//counting
#define IR 4 //ir pin 
#define trig A2 // trigger pin
#define echo A1 // echo pin
#define cntup A4
#define cntdw A5//COUNTING
long dis_a = 0;
int flag1 = 0, flag2 = 0;
int person = 0;//counting person initialization

//temperature
int temppin = A3;

//RFID
int SS_PIN=10;
int RST_PIN=9;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

//Servo
Servo s1;
Servo s2;
Servo s3;
int s1pin= 6;

void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus

  //PIR
  pinMode(pirpin, INPUT);
  pinMode(alertpin, OUTPUT);
  digitalWrite(alertpin,LOW); 
  

  //counting
  pinMode(IR, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);


  pinMode(cntup,OUTPUT);
   pinMode(cntdw,OUTPUT);

  //temperature
  pinMode(temppin, INPUT);

//  //LCD
//  lcd.begin();
//  lcd.backlight();
//  lcd.print("NULL");
//  lcd.setCursor(0, 1);
  
  //RFID
  mfrc522.PCD_Init();   // Initiate MFRC522
  
  //Servo
  s1.attach(s1pin); //servo pin
  s1.write(0);
  s2.attach(5);
  s3.attach(3);
}
void loop() 
{

  digitalWrite(cntup,LOW);
  digitalWrite(cntdw,LOW);

  //PIR
  int motion=digitalRead(pirpin);
  Serial.print("Motion Detected : ");
  Serial.println(motion);
  if(motion==0){          //Wait
  digitalWrite(alertpin,HIGH);
  }else{      
  digitalWrite(alertpin,LOW); 
}

  //Auto Door
  s2.write(90);
  s3.write(0);
  
//  //temperature
//  float tempvalue = analogRead(temppin);
//  tempvalue = (tempvalue/1024)*500;
//  Serial.print("Temperature : ");
//  Serial.println(tempvalue);
  
  

  //counting
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

  //RFID
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
  delay(1000);
}
