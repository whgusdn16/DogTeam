#define Servo_1 22    //LF(Left Front) 1
#define Servo_2 23    //LF 2
#define Servo_3 24    //RF(Right Front) 1
#define Servo_4 25    //RF 2
#define Servo_5 26    //LB(Left Back) 1
#define Servo_6 27    //LB 2
#define Servo_7 28    //RB(Right Back) 1
#define Servo_8 29    //RB 2
#define Servo_9 30    //Tail
#define Servo_10 31   //Head
#define Servo_11 32   
#define Servo_12 33   
#define Servo_13 34
#define Servo_14 35
#define Servo_15 36
#define Servo_16 37

void motor_Initialize();
void motor_attach();
void motor_detach();
void motion_stand();
void motion_crouch();
void motion_move(int a);
void motion_tail(int a);
void motion_head(int a);
void motion_death();