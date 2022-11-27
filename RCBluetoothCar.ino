#define echoPin 9 // attach pin D9 Arduino to pin Echo of HC-SR04
#define trigPin 8 // attach pin D8 Arduino to pin Echo of HC-SR04

char appInput;  // initializes char to be assigned

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

	// opens serial port at data rate
	Serial.begin(9600);
}


void forwards() { // turns on pins to rotate wheels forward
	digitalWrite(leftMotorForward, HIGH);
	digitalWrite(rightMotorForward, HIGH);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorReverse, LOW);
}


void backwards() { // turns on pins to rotate wheels backwards
	digitalWrite(leftMotorReverse, HIGH);
	digitalWrite(rightMotorReverse, HIGH);
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(rightMotorForward, LOW);
}


void left() { // right motor turned on, turns left
	digitalWrite(rightMotorForward, HIGH);
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
	digitalWrite(leftMotorReverse, LOW);
}



void right() { // left motor turned on, turns right

	digitalWrite(leftMotorForward, HIGH);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
}

void stop() {  // STOP, all motors off when no other input detected 
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
}

void donut() { // turn right motors on, doing a donut to the left        
	left();
	delay(3000);
	stop();
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
	Serial.print(" Distance: ");
	Serial.print(distance);

	return distance;
}

void avoid(int distance) {
	stop();
	delay(100);
	// backs up until distance is at least 35 cm
	while (getDistance() <= 35) {
		backwards();
		delay(500);
	}
	// After backing up, car rotates right and then stops
	right();
	delay(1000);
	stop();
}

// loops through 'if' statements to look for input
void loop() {
	if (Serial.available()) {
		// assigns char value from bluetooth app
		appInput = Serial.read();
		Serial.println(appInput);
	}

	// prints out and assigns detected distance
	distance = getDistance();

	// once distance is too small, avoid funtion is run
	if (distance <= 20) {
		avoid(distance);
	}

	if (appInput == 'F') {
		forwards();
	}

	else if (appInput == 'G') {
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
