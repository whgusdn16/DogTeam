#include <Arduino.h>
#include <Servo.h>
#include "Motion.h"

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;
Servo servo12;
Servo servo13;
Servo servo14;
Servo servo15;
Servo servo16;

void motor_Initialize(){
	servo1.attach(Servo_1);
	servo2.attach(Servo_2);
	servo3.attach(Servo_3);
	servo4.attach(Servo_4);
	servo5.attach(Servo_5);
	servo6.attach(Servo_6);
	servo7.attach(Servo_7);
	servo8.attach(Servo_8);
	servo9.attach(Servo_9);
	servo10.attach(Servo_10);
	servo11.attach(Servo_11);
	servo12.attach(Servo_12);
	servo13.attach(Servo_13);
	servo14.attach(Servo_14);
	servo15.attach(Servo_15);
	servo16.attach(Servo_16);
}
void motor_detach(){
	servo1.detach();
	servo2.detach();
	servo3.detach();
	servo4.detach();
	servo5.detach();
	servo6.detach();
	servo7.detach();
	servo8.detach();
	servo9.detach();
	servo10.detach();
	servo11.detach();
	servo12.detach();
	servo13.detach();
	servo14.detach();
	servo15.detach();
	servo16.detach();
}
void motion_stand(){
	servo1.write(90);
	servo2.write(90);
	servo3.write(90);
	servo4.write(90);
	servo5.write(90);
	servo6.write(90);
	servo7.write(90);
	servo8.write(90);
}
void motion_crouch(){
	servo1.write(90);
	servo2.write(90);
	servo3.write(90);
	servo4.write(90);
	servo5.write(180);
	servo6.write(180);
	servo7.write(0);
	servo8.write(0);
}
void motion_move(int a){
	servo1.write(90 - a);
	servo2.write(90 - a);
	servo3.write(90 - a);
	servo4.write(90 - a);
	servo5.write(90 + a);
	servo6.write(90 + a);
	servo7.write(90 + a);
	servo8.write(90 + a);
}
void motion_tail(int a){
	servo9.write(90 + a);
}
void motion_head(int a){
	servo10.write(90 + a);
}
void motion_death(){
	servo1.write(180);
	servo2.write(180);
	servo3.write(0);
	servo4.write(0);
	servo5.write(180);
	servo6.write(180);
	servo7.write(0);
	servo8.write(0);
}