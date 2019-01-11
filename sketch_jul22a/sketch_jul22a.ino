#include "Timer.h"
#include "Emotion.h"
#include "Motion.h"
#include <Servo.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

//상태
#define INIT 0
#define GO 1
#define WAIT 2
#define HAND 3
#define TOUCH 4
#define CROUCH 5
#define DEATH 6
#define CALL 7

//초음파 거리감지 센서
#define TRIGER 11
#define ECHO 12

//터치센서
#define Touch_1 46
#define Touch_2 47
#define Touch_3 48
#define Touch_4 49
#define Touch_5 50

//서보모터
extern Servo servo1;          //LF(Left Front) 1
extern Servo servo2;          //LF 2
extern Servo servo3;          //RF(Right Front) 1
extern Servo servo4;          //RF 2
extern Servo servo5;          //LB(Left Back) 1
extern Servo servo6;          //LB 2
extern Servo servo7;          //RB(Right Back) 1
extern Servo servo8;          //RB 2
extern Servo servo9;          //Tail
extern Servo servo10;         //Head

//타이머용 변수
Timer t;

//터치센서 변수
int Touch_A;
int Touch_B;
int Touch_C;
int Touch_D;
int Touch_E;

void setup() {
  //터치센서 핀 설정
  pinMode(Touch_1, INPUT);
  pinMode(Touch_2, INPUT);
  pinMode(Touch_3, INPUT);
  pinMode(Touch_4, INPUT);
  pinMode(Touch_5, INPUT);
  //초음파 거리감지 센서 설정
  pinMode(TRIGER, OUTPUT);
  pinMode(ECHO, INPUT);
  //시리얼 설정
  Serial.begin(9600);
  Serial1.begin(9600);             // 음성인식 시리얼
  Serial3.begin(9600);             // mp3 모듈 시리얼
  //
  mp3_set_serial (Serial3);        // DFPlayer-mini mp3 module 시리얼 세팅
  delay(1);                         // 볼륨값 적용을 위한 delay
  mp3_set_volume (30);              // 볼륨조절 값 0~30
  motor_Initialize();
  motion_stand();
  mp3_play(1);
  delay(2000);
}

void loop() {

  //타이머
  t.update();
  unsigned long now;

  // 터치센서 갱신
  Touch_A = digitalRead(Touch_1);
  Touch_B = digitalRead(Touch_2);
  Touch_C = digitalRead(Touch_3);
  Touch_D = digitalRead(Touch_4);
  Touch_E = digitalRead(Touch_5);

  //터치가 입력됬을 때
  if ( Touch_A == HIGH)  {
    set_state(TOUCH);
    Serial.println("A");
  }
  else if ( Touch_B == HIGH) {
    set_state(TOUCH);
    Serial.println("B");
  }
  else if ( Touch_C == HIGH) {
    set_state(TOUCH);
    Serial.println("C");
  }
  else if ( Touch_D == HIGH) {
    set_state(TOUCH);
    Serial.println("D");
  }
  else if ( Touch_E == HIGH) {
    set_state(TOUCH);
    Serial.println("E");
  }
  if (Serial1.available()) {
    String str = "";
    str = readSerial();
    Serial.println(str);

    if (str == "앉아" || str == "안자" || str == "안쟈"
        || str == "앉 아" || str == "안 자" || str == "안 쟈") {
      while (str != "일어서") {
        str = readSerial();
        Serial.println(str);
        set_state(CROUCH);
      }
    }
    else if (str == "손") {
      set_state(HAND);
    }
    else if (str == "그레이" || str == "그래이" || str == "그래") {
      set_state(CALL);
    }
    else if (str == "이리 와" || str == "이리와") {
      set_state(GO);
    }
    else if ( str == "빵야" || str == "뻥이야") {
      mp3_play(2);
      while (str != "일어나") {
        str = readSerial();
        Serial.println(str);
        set_state(DEATH);
      }
      mp3_play(1);
      now = millis();
      while (millis() - now < 500) {
        emotion_normal();
        motion_crouch();
      }
    }
    else if (str == "노래 틀어 줘" || str == "노래 틀어줘" || str == "노래") {
      mp3_play(random(13) + 2);
    }
  }

  else {
    set_state(INIT);
    Touch_A == LOW;
    Touch_B == LOW;
    Touch_C == LOW;
    Touch_D == LOW;
    Touch_E == LOW;
  }
}

//음성인식
String readSerial() {
  String str = "";
  char ch;
  while ( Serial1.available() > 0 )
  {
    ch = Serial1.read();
    str.concat(ch);
    delay(10);
  }
  return str;
}

//상태별 함수
void set_state(int state) {
  unsigned long now;

  //초기상태
  if (state == INIT) {
    motion_stand();
    motion_head(0);
    motion_tail(0);
    emotion_normal();
  }
  //이동
  else if (state == GO) {
    now = millis();
    mp3_play(1);
    while (millis() - now < 7000) {
      //전방 15cm 내에 장애물이 있을 시
      if (distance_sensor() < 15) {
        while (distance_sensor() < 15) {
          set_state(WAIT);
        }
        now = millis();
      }

      if (((millis() - now) / 700) % 2 == 0) {
        emotion_normal();
        motion_head(0);
        motion_move(30);
      }
      else {
        emotion_normal();
        motion_head(0);
        motion_move(-30);
      }
    }
  }
  //대기
  else if (state == WAIT) {
    motion_stand();
    emotion_angry();
    if ((millis() / 500) % 2 == 0) {
      mp3_play(1);
    }
  }
  //손
  else if (state == HAND) {

  }
  //터치
  else if (state == TOUCH) {
    now = millis();
    while (millis() - now < 2700) {
      motion_stand();
      emotion_cute();
      if (((millis() - now) / 300) % 2 == 0) {
        motion_tail(45);
      }
      else {
        motion_tail(-45);
      }
    }
  }
  //앉아
  else if (state == CROUCH) {
    motion_crouch();
    emotion_cute();
  }
  else if (state == DEATH) {
    motion_death();
    emotion_death();
  }
  else if ( state == CALL) {


    now = millis();
    while (millis() - now < 2000) {
      motion_stand();
      if ((millis() / 500) % 2 == 0) {
        mp3_play(1);
        emotion_normal();
        motion_head(30);
      }
      else {
        emotion_normal();
        motion_head(-30);
      }
    }
  }
}

float distance_sensor() {
  digitalWrite(TRIGER, LOW);
  digitalWrite(ECHO, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ECHO, LOW);
  unsigned long duration = pulseIn(ECHO, HIGH);
  float distance = ((float)(340 * duration) / 10000) / 2;
  Serial.print(distance);
  Serial.println("cm");
  return distance;
}

