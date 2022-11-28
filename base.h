class base {

public:
  int leftMotorForward;  // left motors forward
  int leftMotorReverse;  // left motors reverse
  int rightMotorForward; // right motors forward
  int rightMotorReverse; // right motors reverse

  int echoPin;           // pin Echo of HC-SR04
  int trigPin;           // pin Trig of HC-SR04

  // long duration;         // duration of soundwave travel 
  // int distance;          // calculated distance

	virtual void forwards(){};
  virtual void backwards(){};
  virtual void left(){};
  virtual void right(){};
  virtual void stop(){};

  virtual void donut(){};
  virtual int getDistance(){};
  virtual void avoid(int distance){};
};
