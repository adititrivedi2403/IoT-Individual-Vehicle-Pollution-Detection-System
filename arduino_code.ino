#include <SoftwareSerial.h> 
SoftwareSerial esp(2,3); // RX, TX 
int mq2=A0, mq7=A1, mq135=A2; 
void setup() { 
Serial.begin(9600); 
esp.begin(9600); 
} 
void loop() { 
int s2 = analogRead(mq2); 
int s7 = analogRead(mq7); 
int s135 = analogRead(mq135); 
Serial.println(String(s2)+","+String(s7)+","+String(s135)); 
esp.println(String(s2)+","+String(s7)+","+String(s135)); 
delay(1000); 
} 
