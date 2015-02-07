// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo horizontal;  // create servo object to control a servo 
Servo vertical;  // create servo object to control a servo 
int val;
int xval;
int yval;

void setup() 
{ 
  vertical.attach(5);  // attaches the servo on pin 9 to the servo object 
  horizontal.attach(6);  // attaches the servo on pin 9 to the servo object 
  horizontal.write(90);                  // sets the servo position according to the scaled value 
  vertical.write(90);  
  Serial.begin(115200);
} 
 
void loop() 
{ 
    // look for the next valid integer in the incoming serial stream:
    val = Serial.parseInt();
    xval = map(val, 0, 640, 0, 180);
    // do it again:
    val = Serial.parseInt();
    yval = map(val, 0, 480, 180, 0);
    
  //vertical.write(yval);  // sets the servo position according to the scaled value
  horizontal.write(xval);
  vertical.write(yval);
  delay(15);
} 
