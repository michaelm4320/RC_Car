char appInput;              // initializes char to be assigned

 int leftMotorForward = 4;  // left motors forward
 int leftMotorReverse = 5;  // left motors reverse
 int rightMotorForward = 6; // right motors forward
 int rightMotorReverse = 7; // right motors reverse

void setup() {
 pinMode(leftMotorForward,OUTPUT);   
 pinMode(leftMotorReverse,OUTPUT);   
 pinMode(rightMotorForward,OUTPUT);   
 pinMode(rightMotorReverse,OUTPUT);   
 Serial.begin(9600);  // opens serial port at data rate
}
 
void loop() {            // loops through 'if' statements to look for input
 if(Serial.available()){
   appInput = Serial.read();     // assigns char value from bluetooth app
   Serial.println(appInput);
}
 
if(appInput == 'F'){            // turns on pins to rotate wheels forward
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,HIGH);
}
 
else if(appInput == 'B'){      // turns on pins to rotate wheels backwards
  digitalWrite(leftMotorReverse,HIGH);
  digitalWrite(rightMotorReverse,HIGH);
}
 
else if(appInput == 'L'){      // right motor turned on, turns left
  digitalWrite(rightMotorForward,HIGH);
}
 
else if(appInput == 'R'){      // left motor turned on, turns right
  digitalWrite(leftMotorForward,HIGH);
}
 
else if(appInput == 'X') {          // turn right motors on, doing a donut to the left
  digitalWrite(rightMotorForward,HIGH);
  delay(3000);
}

// STOP, all motors off when no other input detected 
else if(appInput == 'S'){  
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorReverse,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorReverse,LOW);
}
delay(100);
}
