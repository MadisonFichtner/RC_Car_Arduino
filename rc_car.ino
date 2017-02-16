#include <SoftwareSerial.h>

int enA = 10;
int in1 = 9;
int in2 = 8;
int enB = 5;
int in3 = 7;
int in4 = 6;

char junk;
String inputString="";

SoftwareSerial mySerial (2,3);

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
//Control w/bluetooth
  
  if(mySerial.available()){
  while(mySerial.available())
    {
      char inChar = (char)mySerial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    mySerial.println(inputString);
    while (mySerial.available() > 0)  
    { 
    junk = mySerial.read() ; }      // clear the serial buffer
    if(inputString == "a"){   
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enB, 255); 
    }
    else if(inputString == "b"){ 
      analogWrite(enB, 0);
    }
    else if(inputString == "c"){
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 255); 
    }
    
    if(inputString == "d"){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, 255);
    }
    else if(inputString == "e"){
      analogWrite(enA, 0);
    }
    else if(inputString == "f"){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enA, 255);
    }
    inputString = "";
  }
}
