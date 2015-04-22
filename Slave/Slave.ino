#include <IRremote.h>

#define ON 0x3000,0x8022
#define OFF 0x3500,0xA337


const int ledpin = 13;
const int dataenable = 2;
IRsend irsend; 

void setup(){

    Serial.begin(4800);
    Serial.println("SLAVE");
    pinMode(ledpin,OUTPUT);
    pinMode(dataenable, OUTPUT);
    delay(50);
    
    digitalWrite(ledpin,LOW);
    digitalWrite(dataenable,LOW);

}

void loop()
{
  int b;
  if (Serial.available()){
    delay(100);
    b = Serial.read();
    Serial.println(b);
    if(b==58){
      switchON();
    }
    if(b==173){
      switchOFF();
    }
  }
}

void switchON()
	{
                        digitalWrite(ledpin, HIGH);
                        irsend.sendVOLTAS(ON);
                        delay(1000); // on  18 degreee Compressor
                        digitalWrite(ledpin, LOW);
                      //  delay(1000);
	}
void switchOFF()
	{
                        digitalWrite(ledpin, HIGH);
                        irsend.sendVOLTAS(OFF); // on  19 degreee Fan
                        digitalWrite(ledpin, LOW);
                        delay(1000);
	}

