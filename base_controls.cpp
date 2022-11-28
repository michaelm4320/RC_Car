#include "base_controls.h"
#include <Arduino.h>

void base_controls::forwards() { // turns on pins to rotate wheels forward

	digitalWrite(leftMotorForward, HIGH);
	digitalWrite(rightMotorForward, HIGH);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorReverse, LOW);
}

void base_controls::backwards() { // turns on pins to rotate wheels backwards

	digitalWrite(leftMotorReverse, HIGH);
	digitalWrite(rightMotorReverse, HIGH);
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(rightMotorForward, LOW);
}

void base_controls::left() {   // right motor turned on, turns left
	digitalWrite(rightMotorForward, HIGH);
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
	digitalWrite(leftMotorReverse, LOW);  
}

void base_controls::right() {  // left motor turned on, turns right
	digitalWrite(leftMotorForward, HIGH);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
}

void base_controls::stop() {  // STOP, all motors off when no other input detected 
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
}


void base_controls::donut() { // turn right motors on, doing a donut to the left        
	left();
	delay(3000);
  stop();
}

int base_controls::getDistance() { // calculates distance using sensor
	// clears the trigPin condition
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// sets the trigPin HIGH for 10 ms
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);
	// calculates the distance
	distance = duration * 0.034 / 2; // speed of sound wave divided by 2 (back and forth)
	// prints distance on app screen
	Serial.print(" Distance: ");
	Serial.print(distance);

	return distance;
}

void base_controls::avoid(int distance) {
	stop();
	delay(100);
	// backs up until distance is at least 35 cm
	while (getDistance() <= 35) {  
		backwards();
		delay(500);
	}
	// after backing up, car rotates right and then stops
	right();
	delay(1000);
	stop();
}

