#include <SoftwareSerial.h>

int enA = 10;	//determines if turning motor should be on
int in1 = 9;	//determines if turning motor should turn clockwise
int in2 = 8;	//determines if turning motor should turn counter-clockwise
int enB = 5;	//determines if drive motor should be on
int in3 = 7;	//determines if drive motor should turn clockwise
int in4 = 6;	//determines if drive motor should turn counter-clockwise

char junk;
String inputString="";

SoftwareSerial mySerial (2,3);	//fixes conflict with computer-arduino interaction

//set pins as output to control motors
void setup(){
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  mySerial.begin(9600);  
}

void loop() {
  if(mySerial.available()){
	while(mySerial.available()){
      char inChar = (char)mySerial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    mySerial.println(inputString); //print input string
	
    while (mySerial.available() > 0){ 
		junk = mySerial.read(); // clear the serial buffer
	}      
		
	if(inputString == "a"){      //move forward
	  digitalWrite(in3, LOW);
	  digitalWrite(in4, HIGH);
	  analogWrite(enB, 255); 
	}
	else if(inputString == "b"){ //stop moving
	  analogWrite(enB, 0);
	}
	else if(inputString == "c"){ //move backward
	  digitalWrite(in3, HIGH);
	  digitalWrite(in4, LOW);
	  analogWrite(enB, 255); 
	}
	
	if(inputString == "d"){	    //turn left
	  digitalWrite(in1, HIGH);
	  digitalWrite(in2, LOW);
	  analogWrite(enA, 255);
	}
	else if(inputString == "e"){//stop turning
	  analogWrite(enA, 0);
	}
	else if(inputString == "f"){//turn right
	  digitalWrite(in1, LOW);
	  digitalWrite(in2, HIGH);
	  analogWrite(enA, 255);
	}
	inputString = ""; //clear input string
  }
}
