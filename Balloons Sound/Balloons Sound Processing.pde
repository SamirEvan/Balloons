import processing.sound.*; //this library needs to be downloaded from the sketch menu before it can be used 
import processing.serial.*; //this library is automatically installed

Serial myPort;
int linefeed = 10; //input the actual number 
int numSensors = 4; //telling processing that we are reading data from four sensors
int sensors[]; //array to read the 4 values
int pSensors[]; //array to store the previous reading, useful for comparing actual reading with the last one

SoundFile file1;  //preparing processing to find and read the sound files 
SoundFile file2;
SoundFile file3;
SoundFile file4; 

void setup(){ 
  size(600,600); //size and background values are irrelevant for this sketch
  background(0);
  
  //myPort = new Serial(this, Serial.list()[1], 9600); //read bytes into a buffer until you get a linefeed (ASCII 10):
  //myPort.bufferUntil(100); //tbh not really sure what this does
  
  file1 = new SoundFile(this, "nightmusic.mp3"); //tell processing where to find the sound files
  file2 = new SoundFile(this, "wagner.mp3");
  file3 = new SoundFile(this, "kingtobe.mp3");
  file4 = new SoundFile(this, "sleighride.mp3");
}


void draw(){ //don't play the sound files in the draw function because 
}            //it will play the file on top of itself every time the draw function is called  

void keyPressed(){ 
 if (key == CODED){
   if(keyCode == UP){   
     file1.play();
  } 
  else if (keyCode == RIGHT){
    file2.play();
  }
  else if (keyCode == LEFT){
    file3.play();
  }
  else if (keyCode == DOWN){
    file4.play();
    }
  }
}

  /*if((pSensors != null)&&(sensors !=null)) {
    //if valid data arrays are not null 
    //compare each sensor value with the previous reading to establish change
    for(int i=0; i <numSensors; i++){
      float f = sensors[i] - pSensors[i]; //actual value-previous value
    if (f > 0){
      println("sensor "+i+" increased by "+f); //value increased
      }
    if (f < 0) {
      println("sensor "+i+" decreased by "+f); //value decreased
     }
    }
    //now do something with the values read sensors [0] ... sensors[3]
    
 }
}

/*
void serialEvent(Serial myPort) { 
  //read the serial buffer
  String myString = myPort.readStringUntil(linefeed);
  
  //if you got any bytes other than the linefeed:
  if (myString != null) {
    myString = trim(myString);
    
    //split the string at the commas
    //and convert the sections into integers:
    
    pSensors = sensors;
    sensors = int(split(myString, ','));
    
    //print out the values you got:
    
    for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
      print("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t");
    }
    
    //add a linefeed after all the sensor values are printed 
    println();
    
 }
}*/