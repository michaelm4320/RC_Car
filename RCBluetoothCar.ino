#ifndef base_h
#define base_h
#include "base.h"
#endif
#include "base_controls.h"


base* myBase;
base_controls myBaseCar;

char appInput;  // initializes char to be assigned

long duration;
int distance;


void setup() {
  myBase = &myBaseCar;
	pinMode(myBase->leftMotorForward, OUTPUT);
	pinMode(myBase->leftMotorReverse, OUTPUT);
	pinMode(myBase->rightMotorForward, OUTPUT);
	pinMode(myBase->rightMotorReverse, OUTPUT);

	pinMode(myBase->trigPin, OUTPUT);
	pinMode(myBase->echoPin, INPUT);
	
	// opens serial port at data rate
	Serial.begin(9600);  
}


// loops through 'if' statements to look for input
void loop() {                       		
	if (Serial.available()) {
		// assigns char value from bluetooth app
		appInput = Serial.read(); 	
		Serial.println(appInput);
	}
	
	// prints out and assigns detected distance
	distance = myBase->getDistance(); 
	
	// once distance is too small, avoid funtion is run
	if (distance <= 20) { 
		myBase->avoid(distance);
	}

	if (appInput == 'F') {
		myBase->forwards();
	}

	else if (appInput == 'G') {
		myBase->backwards();
	}

	else if (appInput == 'L') {
		myBase->left();
	}

	else if (appInput == 'R') {
		myBase->right();
	}

	else if (appInput == 'X') {
		myBase->donut();
	}

	else if (appInput == 'S') {
		myBase->stop();
	}

	delay(100);
}
