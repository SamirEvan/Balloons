#include <Ultrasonic.h>
#include <SerialLCD.h> 

Ultrasonic topLeft(7);
Ultrasonic topRight(8);
Ultrasonic bottomLeft(9);

int echoPin1 = 2;
int initPin1 = 3;
int distance1 = 0;


void setup() {
  
  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
 
  Serial.begin(9600);
}

void loop() {
  
  long val0 = bottomRight.MeasureInCentimeters();
  delay(100);
  
  long val1 = topLeft.MeasureInCentimeters();
  delay(100);

  long val2 = topRight.MeasureInCentimeters();
  delay(100);

  long val3 = bottomLeft.MeasureInCentimeters();
  delay(100);

 Serial.print(val1);
 Serial.print(",");
 Serial.print(val2);
 Serial.print(",");
 Serial.print(val3);
 Serial.print(",");
 Serial.println(val0);
}

int getDistance (int initPin, int echoPin){

 digitalWrite(initPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(initPin, LOW); 
 unsigned long pulseTime = pulseIn(echoPin, HIGH); 
 int distance = pulseTime/58;
 return distance;
}
 
 void printDistance(int id, int dist){
  
     Serial.print(id);
    if (dist >= 120 || dist <= 0 ){
      Serial.println(" Out of range");
    }else
    for (int i = 0; i <= dist; i++) { 
         Serial.print("-");
    }
    Serial.print(dist, DEC);
    Serial.println();
 }
