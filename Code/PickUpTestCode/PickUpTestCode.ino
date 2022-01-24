#include <Servo.h>
#include <math.h>
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
  goToAngle(shoulder,90);
  goToAngle(elbow,90);
  goToAngle(wrist,0);
  goToAngle(hand,90);
  goToAngle(grip,0);
}
void moveToCart(Servo xServo, float Dx, float Dy, float length){
  float angle;
  //if (length==0) return;
  if(Dx!=0) angle=acos(Dx/length);
  else if(Dy!=0) angle=asin(Dy/length);
  angle=angle*(180/M_PI);
  goToAngle(xServo, angle);
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
  shoulder.write(90);
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
  }
  //else if(rep==1) goToAngle(shoulder,45);
  else if (rep==2){
    delay(2000);
    moveToCart(shoulder,12, 0, 12);
    //goToAngle(shoulder,0);
  }
  rep++;
  Serial.println(rep);
}
