#include <SoftwareSerial.h>

#define sTX  1
#define sRX  0
#define slave1 0x01
#define slave2 0x02
#define slave3 0x03

SoftwareSerial rs485con(sRX,sTX);

const int ledpin=13;
const int dataenable = 2;
void setup(){
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(dataenable, OUTPUT);
  delay(10);
  digitalWrite(dataenable,LOW);
  rs485con.begin(4800);

}

void loop(){
  byte c=0;
  digitalWrite(ledpin,HIGH);
  digitalWrite(dataenable,HIGH);
 
  if(Serial.available()){
    c = Serial.read();
    if (c == 49){
      rs485con.print(slave1);
      Serial.println(slave1);
    }
    if (c==50){
      rs485con.print(slave2);
      Serial.println(slave2);
    }
    if(c==51){
      rs485con.print(slave3);
      Serial.println(slave3);
    }
  }
 
  
}

