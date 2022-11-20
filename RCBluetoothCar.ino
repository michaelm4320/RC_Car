#define echoPin 9 	// attach pin D9 Arduino to pin Echo of HC-SR04
#define trigPin 8	// attach pin D8 Arduino to pin Echo of HC-SR04

char appInput;         	// initializes char to be assigned

int leftMotorForward = 5;  // left motors forward
int leftMotorReverse = 4;  // left motors reverse
int rightMotorForward = 7; // right motors forward
int rightMotorReverse = 6; // right motors reverse

long duration;
int distance;

void setup() {
	pinMode(leftMotorForward, OUTPUT);
	pinMode(leftMotorReverse, OUTPUT);
	pinMode(rightMotorForward, OUTPUT);
	pinMode(rightMotorReverse, OUTPUT);

  	pinMode(trigPin, OUTPUT);	
  	pinMode(echoPin, INPUT);

	Serial.begin(9600);  // opens serial port at data rate
}


void forwards() {      // turns on pins to rotate wheels forward
  	digitalWrite(leftMotorForward, HIGH);
	digitalWrite(rightMotorForward, HIGH);
}

void backwards() {    // turns on pins to rotate wheels backwards
  	digitalWrite(leftMotorReverse, HIGH);
	digitalWrite(rightMotorReverse, HIGH);
} 

void left() {         // right motor turned on, turns left
  	digitalWrite(rightMotorForward, HIGH);
}

void right() {        // left motor turned on, turns right
	digitalWrite(leftMotorForward, HIGH);
}

void stop() {         // STOP, all motors off when no other input detected 
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
}

void donut() {        // turn right motors on, doing a donut to the left        
	digitalWrite(rightMotorForward, HIGH);
	//delay(3000);
}

int getDistance() {
	// Clears the trigPin condition
  	digitalWrite(trigPin, LOW);
  	delayMicroseconds(2);
  	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
 	digitalWrite(trigPin, HIGH);
 	delayMicroseconds(10);
  	digitalWrite(trigPin, LOW);
  	// Reads the echoPin, returns the sound wave travel time in microseconds
  	duration = pulseIn(echoPin, HIGH);
  	// Calculating the distance
  	distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  	// Displays the distance on the Serial Monitor
  	Serial.print("Dist: ");
  	Serial.print(distance);
  	Serial.println(" cm");
	
	return distance;
}

void avoid(int distance) {
	stop();
  	while (distance <= 30) {             	// backs up until distance is at least 40 cm
    		backwards();
  	}
	right();
  	delay(100); 
}

void loop() {                       		// loops through 'if' statements to look for input
	if (Serial.available()) {
		appInput = Serial.read(); 	// assigns char value from bluetooth app
		Serial.println(appInput);
	}

	distance = getDistance();         	// prints out and assigns detected distance

  	if (distance <= 13) {             	// once distance is too small, avoid funtion is run
    		avoid(distance);
  	}

	if (appInput == 'F') {           
    		forwards();
	}

	else if (appInput == 'B') {      
		backwards();
	}

	else if (appInput == 'L') {      
		left();
	}

	else if (appInput == 'R') {     
		right();
	}

	else if (appInput == 'X') {
		donut();
	}

	else if (appInput == 'S') {
		stop();
	}

	delay(100);
	
}
