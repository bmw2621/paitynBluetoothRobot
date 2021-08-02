/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
  const char forward = 'f';
  const char backward = 'b';
  const char left = 'l';
  const char right = 'r';
  int leftSpeed = 0;
  int rightSpeed = 0;

// Motor A
  int enA = 9;
  int in1 = 8;
  int in2 = 7;
// Motor B
  int enB = 3;
  int in3 = 5;
  int in4 = 4;

  
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  if(Serial.available()>0) {
    char command = Serial.read();
    switch(command) {
      case 'o': digitalWrite(LED_BUILTIN, HIGH);break;
      case 'x': digitalWrite(LED_BUILTIN, LOW); break;
      case forward: goForward(); break;
      case backward: goBackward(); break;
      case left: turnLeft(); break;
      case right: turnRight(); break;
      default: break;
    }

  }
  delay(100);
}

void goForward() {
  Serial.println("forward");
  if(leftSpeed + 5 <= 255) leftSpeed = leftSpeed + 5;
  if(rightSpeed + 5 <= 255) rightSpeed = rightSpeed + 5;
  Serial.print("Left: " + String(leftSpeed));
  Serial.println(" Right: " + String(rightSpeed));
  Serial.println("----------------");
}

void goBackward() {
  Serial.println("backward");
  if(leftSpeed - 5 >= -255) leftSpeed = leftSpeed - 5;
  if(rightSpeed - 5 >= -255) rightSpeed = rightSpeed - 5;
  Serial.print("Left: " + String(leftSpeed));
  Serial.println(" Right: " + String(rightSpeed));
  Serial.println("----------------");
}

void turnLeft() {
  Serial.println("left");
  if(leftSpeed + 5 <= 255) leftSpeed = leftSpeed + 5;
  if(rightSpeed - 5 >= -255) rightSpeed = rightSpeed - 5;
  Serial.print("Left: " + String(leftSpeed));
  Serial.println(" Right: " + String(rightSpeed));
  Serial.println("----------------");
}

void turnRight() {
  Serial.println("right");
  if(leftSpeed - 5 >= -255) leftSpeed = leftSpeed - 5;
  if(rightSpeed + 5 <= 255)rightSpeed = rightSpeed + 5;
  Serial.print("Left: " + String(leftSpeed));
  Serial.println(" Right: " + String(rightSpeed));
  Serial.println("----------------");
}

void setWheelDirection() {
  if(leftSpeed > 0){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (leftSpeed < 0) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }

  if(rightSpeed > 0){
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  } else if (rightSpeed < 0) {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}

void setSpeed() {
  analogWrite(enA, abs(leftSpeed));
  analogWrite(enB, abs(rightSpeed));
}
