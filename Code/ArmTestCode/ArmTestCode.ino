#include <Servo.h>
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist;
Servo hand;
Servo grip;
void goToAngle(Servo myservo, int angle, int delTime=10, bool linear=false){
  if(angle>myservo.read()){
    for (int pos = myservo.read(); pos <= angle; pos += 1) {
      // in steps of 1 degree
      myservo.write(pos); 
      delay(delTime);
      if(linear==true)
        delTime++;
    }
  }
  else{
    for (int pos = myservo.read(); pos >= angle; pos -= 1) {
      // in steps of 1 degree
      myservo.write(pos);
      delay(delTime);
      if(linear==true)
        delTime++;
    }
  }
  Serial.println(myservo.read());
}
void initialPos(){
  goToAngle(base,0);
  goToAngle(shoulder,120);
  goToAngle(elbow,70);
  goToAngle(wrist,0);
  goToAngle(hand,90);
  goToAngle(grip,0);
}
void sayHiToRJ(){
  goToAngle(wrist,90);
  goToAngle(shoulder,130);
  goToAngle(elbow,60);
  goToAngle(base,90);
  goToAngle(grip,90);
  wrist.detach();
  for(int x=0; x<3; x++){
    goToAngle(elbow,90,10,true);
    delay(500);
    goToAngle(elbow,50,50);
    delay(500);
  }
}
void setup() {
  // put your setup code here, to run once:
  base.attach(4);
  shoulder.attach(5);
  elbow.attach(6);
  wrist.attach(7);
  hand.attach(8);
  grip.attach(9);
  base.write(0);
  shoulder.write(120);
  elbow.write(90);
  wrist.write(0);
  hand.write(90);
  grip.write(90);
  Serial.begin(9600);
}
int rep=0;
void loop() {
  if(rep==0){
    initialPos();
    delay(1000);
    rep++;
  }
  else if(rep==1){
    sayHiToRJ();
  }
}
