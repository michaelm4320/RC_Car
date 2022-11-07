#define echoPin 9 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 8

char appInput;              // initializes char to be assigned

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

void loop() {            // loops through 'if' statements to look for input
	if (Serial.available()) {
		appInput = Serial.read();     // assigns char value from bluetooth app
		Serial.println(appInput);
	}

	if (appInput == 'F') {            // turns on pins to rotate wheels forward
		digitalWrite(leftMotorForward, HIGH);
		digitalWrite(rightMotorForward, HIGH);
	}

	else if (appInput == 'B') {      // turns on pins to rotate wheels backwards
		digitalWrite(leftMotorReverse, HIGH);
		digitalWrite(rightMotorReverse, HIGH);
	}

	else if (appInput == 'L') {      // right motor turned on, turns left
		digitalWrite(rightMotorForward, HIGH);
	}

	else if (appInput == 'R') {      // left motor turned on, turns right
		digitalWrite(leftMotorForward, HIGH);
	}

	else if (appInput == 'X') {          // turn right motors on, doing a donut to the left
		digitalWrite(rightMotorForward, HIGH);
		//delay(3000);
	}

	// STOP, all motors off when no other input detected 
	else if (appInput == 'S') {
		digitalWrite(leftMotorForward, LOW);
		digitalWrite(leftMotorReverse, LOW);
		digitalWrite(rightMotorForward, LOW);
		digitalWrite(rightMotorReverse, LOW);
	}

delay(100);
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
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
