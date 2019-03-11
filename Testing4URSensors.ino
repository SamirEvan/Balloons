#include <Ultrasonic.h>
#include <Servo.h>

Ultrasonic Front(3);
Ultrasonic Back(11);

const int FDistance = analogRead(4);
const int BDistance =  analogRead(11);

Servo myservoR;  //servo object
int pos = 0;
Servo myservoL;
int posL = 0;

void setup() {
  Serial.begin(9600);
  myservoR.attach(9); //writing servo pin numbers
  myservoL.attach(13);
}

void loop() {

  long FDistance = Front.MeasureInCentimeters();
  //delay(100);

  long BDistance = Back.MeasureInCentimeters();
  //delay(100);
  if (FDistance < 50) {  //person
    //carAdvance(250, 250);
    for (pos = 0; pos <= 180; pos += 5) {  //wave arms
      myservoR.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 5) {
      myservoR.write(pos);
      delay(15);
    }
    for (posL = 0; posL <= 180; posL += 5) {  //wave arms
      myservoL.write(posL);
      delay(15);
    }
    for (posL = 180; posL >= 0; posL -= 5) {
      myservoL.write(posL);
      delay(15);
    }
  } else if (BDistance < 50) {
    //carTurnRight(250, 250);
    //delay(2000);
    //carAdvance(250, 250);
    for (pos = 0; pos <= 180; pos += 5) {  //wave arms
      myservoR.write(pos);
      delay(15);
      myservoL.write(posL);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos -= 5) {
      myservoR.write(pos);
      delay(15);
      myservoL.write(posL);
      delay(15);
    }
    Serial.print(FDistance);
    Serial.print(" , ");
    Serial.print(BDistance);
    Serial.println();
  }
}


