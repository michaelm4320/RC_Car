char t;
 
void setup() {
pinMode(4,OUTPUT);   //left motors forward
pinMode(5,OUTPUT);   //left motors reverse
pinMode(6,OUTPUT);   //right motors forward
pinMode(7,OUTPUT);   //right motors reverse
Serial.begin(9600);
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(6,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(4,HIGH);
}

else if(t == 'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
 
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
delay(100);
}