char t;              //initializes char to be assigned
 
void setup() {
pinMode(4,OUTPUT);   //left motors forward
pinMode(5,OUTPUT);   //left motors reverse
pinMode(6,OUTPUT);   //right motors forward
pinMode(7,OUTPUT);   //right motors reverse
Serial.begin(9600);  //opens serial port at data rate
}
 
void loop() {            //loops through 'if' statements to look for input
if(Serial.available()){
  t = Serial.read();     //assigns char value from bluetooth app
  Serial.println(t);
}
 
if(t == 'F'){            //turns on pins to rotate wheels forward
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
}
 
else if(t == 'B'){      //turns on pins to rotate wheels backwards
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
}
 
else if(t == 'L'){      //right motor turned on, turns left
  digitalWrite(6,HIGH);
}
 
else if(t == 'R'){      //left motor turned on, turns right
  digitalWrite(4,HIGH);
}
 
else if(t == 'S'){      //STOP, all motors off when no other input detected
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
delay(100);
}
