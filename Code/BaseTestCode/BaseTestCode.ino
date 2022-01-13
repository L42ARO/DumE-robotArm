#include <Servo.h>
Servo base;
void setup() {
  // put your setup code here, to run once:
  base.attach(4);
  base.write(0);
  Serial.begin(9600);
}
bool go=true;

void loop() {
  Serial.println(base.read());
  if(go==true){
    base.write(90);
  }
  if(base.read()>=90){
    go=false;
  }
}
