/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 12; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

int speedPin_M1 = 5;     //M1 Speed Control
int speedPin_M2 = 6;     //M2 Speed Control
int directionPin_M1 = 4;     //M1 Direction Control
int directionPin_M2 = 7;     //M1 Direction Control

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  analogWrite(analogOutPin, outputValue);
  
  Serial.print("sensor = ");
  Serial.print(sensorValue);

  if (analogRead(A0) < 200){
  Serial.println("clear");
  carAdvance(250,250); 
  } else if (analogRead(A0) > 200){
   Serial.println("OUT OF BOUNDS");
    carStop();
    }
  
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}

void carStop() {                //  Motor Stop
    digitalWrite(speedPin_M2, 0);
    digitalWrite(directionPin_M1, LOW);
    digitalWrite(speedPin_M1, 0);
    digitalWrite(directionPin_M2, LOW);
  }

void carAdvance(int leftSpeed, int rightSpeed) {     //Move forward
    analogWrite (speedPin_M2, leftSpeed);
    digitalWrite(directionPin_M1, LOW);
    analogWrite (speedPin_M1, rightSpeed);
    digitalWrite(directionPin_M2, LOW);
  }  
