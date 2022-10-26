char appInput;              //initializes char to be assigned

void setup() {
 int leftMotorForward = 4; //left motors forward
 int leftMotorReverses = 5; //left motors reverse
 int rightMotorForward = 6; //right motors forward
 int rightMotorReverse = 7; //right motors reverse
 
 pinMode(leftMotorForward,OUTPUT);   
 pinMode(leftMotorReverses,OUTPUT);   
 pinMode(rightMotorForward,OUTPUT);   
 pinMode(rightMotorReverse,OUTPUT);   
 Serial.begin(9600);  //opens serial port at data rate
}
 
void loop() {            //loops through 'if' statements to look for input
 if(Serial.available()){
   appInput = Serial.read();     //assigns char value from bluetooth app
   Serial.println(appInput);
}
 
if(appInput == 'F'){            //turns on pins to rotate wheels forward
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,HIGH);
}
 
else if(appInput == 'B'){      //turns on pins to rotate wheels backwards
  digitalWrite(leftMotorReverses,HIGH);
  digitalWrite(rightMotorReverse,HIGH);
}
 
else if(appInput == 'L'){      //right motor turned on, turns left
  digitalWrite(rightMotorForward,HIGH);
}
 
else if(appInput == 'R'){      //left motor turned on, turns right
  digitalWrite(leftMotorForward,HIGH);
}
 
else if(appInput == 'S'){      //STOP, all motors off when no other input detected
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorReverses,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorReverse,LOW);
}
delay(100);
}
