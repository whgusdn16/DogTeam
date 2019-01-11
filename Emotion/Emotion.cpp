#include <Arduino.h>
#include "Emotion.h"

void set_pin(int tag){
  	if(tag == 0){
    		pinMode(LED_A, OUTPUT);
    		pinMode(LED_B, OUTPUT);
    		pinMode(LED_C, OUTPUT);
    		pinMode(LED_D, OUTPUT);
    		pinMode(LED_E, OUTPUT);
    		pinMode(LED_F, OUTPUT);
    		pinMode(LED_G, OUTPUT);
    		pinMode(LED_H, OUTPUT);
  	}
  	else{
    		pinMode(LED_A, INPUT);
    		pinMode(LED_B, INPUT);
    		pinMode(LED_C, INPUT);
    		pinMode(LED_D, INPUT);
    		pinMode(LED_E, INPUT);
    		pinMode(LED_F, INPUT);
    		pinMode(LED_G, INPUT);
    		pinMode(LED_H, INPUT);
  	}
}

void emotion_cute(){
  	//row 1
  	set_pin(1);
  	pinMode(LED_A, OUTPUT);
  	pinMode(LED_E, OUTPUT);
  	digitalWrite(LED_A, HIGH);
  	digitalWrite(LED_E, LOW);

  	//row 2
  	set_pin(1);
  	pinMode(LED_B, OUTPUT);
  	pinMode(LED_D, OUTPUT);
  	pinMode(LED_F, OUTPUT);
  	digitalWrite(LED_B, HIGH);
  	digitalWrite(LED_D, LOW);
  	digitalWrite(LED_F, LOW);

  	//row 3
  	set_pin(1);
  	pinMode(LED_C, OUTPUT);
  	pinMode(LED_D, OUTPUT);
  	pinMode(LED_F, OUTPUT);
  	digitalWrite(LED_C, HIGH);
  	digitalWrite(LED_D, LOW);
  	digitalWrite(LED_F, LOW);

  	//row 4
  	set_pin(1);
  	pinMode(LED_D, OUTPUT);
  	pinMode(LED_B, OUTPUT);
  	pinMode(LED_G, OUTPUT);
  	digitalWrite(LED_D, HIGH);
  	digitalWrite(LED_B, LOW);
  	digitalWrite(LED_G, LOW);

  	//row 5
  	set_pin(1);
  	pinMode(LED_E, OUTPUT);
  	pinMode(LED_B, OUTPUT);
  	pinMode(LED_G, OUTPUT);
  	digitalWrite(LED_E, HIGH);
  	digitalWrite(LED_B, LOW);
  	digitalWrite(LED_G, LOW);
	
  	//row 6
  	set_pin(1);
  	pinMode(LED_F, OUTPUT);
  	pinMode(LED_A, OUTPUT);
  	pinMode(LED_H, OUTPUT);
  	digitalWrite(LED_F, HIGH);
  	digitalWrite(LED_A, LOW);
  	digitalWrite(LED_H, LOW);
	
  	//row 7
  	set_pin(1);
  	pinMode(LED_G, OUTPUT);
  	pinMode(LED_A, OUTPUT);
  	pinMode(LED_H, OUTPUT);
  	digitalWrite(LED_G, HIGH);
  	digitalWrite(LED_A, LOW);
  	digitalWrite(LED_H, LOW);

}

void emotion_normal(){
  	//row 3
  	set_pin(1);
  	pinMode(LED_C, OUTPUT);
  	pinMode(LED_D, OUTPUT);
  	pinMode(LED_E, OUTPUT);
  	pinMode(LED_F, OUTPUT);
  	digitalWrite(LED_C, HIGH);
  	digitalWrite(LED_D, LOW);
  	digitalWrite(LED_E, LOW);
  	digitalWrite(LED_F, LOW);
  
  	//row 4
  	set_pin(1);
  	pinMode(LED_D, OUTPUT);
  	pinMode(LED_C, OUTPUT);
  	pinMode(LED_E, OUTPUT);
  	pinMode(LED_F, OUTPUT);
  	digitalWrite(LED_D, HIGH);
  	digitalWrite(LED_C, LOW);
  	digitalWrite(LED_E, LOW);
  	digitalWrite(LED_F, LOW);
  
  	//row 5
	set_pin(1);
	pinMode(LED_E, OUTPUT);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_D, OUTPUT);
	pinMode(LED_F, OUTPUT);
	digitalWrite(LED_E, HIGH);
	digitalWrite(LED_C, LOW);
	digitalWrite(LED_D, LOW);
  	digitalWrite(LED_F, LOW);
  
	//row 6
	set_pin(1);
	pinMode(LED_F, OUTPUT);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_D, OUTPUT);
	pinMode(LED_E, OUTPUT);
	digitalWrite(LED_F, HIGH);
	digitalWrite(LED_C, LOW);
	digitalWrite(LED_D, LOW);
	digitalWrite(LED_E, LOW);
}
void emotion_angry(){
	//row 1
	set_pin(1);
	pinMode(LED_A, OUTPUT);
	pinMode(LED_E, OUTPUT);
	digitalWrite(LED_A, HIGH);
	digitalWrite(LED_E, LOW);

	//row 2
	set_pin(1);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_E, OUTPUT);
	digitalWrite(LED_B, HIGH);
	digitalWrite(LED_E, LOW);

	//row 3
	set_pin(1);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_E, OUTPUT);
	digitalWrite(LED_C, HIGH);
	digitalWrite(LED_E, LOW);

	//row 4
	set_pin(1);
	pinMode(LED_D, OUTPUT);
	pinMode(LED_E, OUTPUT);
	digitalWrite(LED_D, HIGH);
	digitalWrite(LED_E, LOW);

	//row 5
	set_pin(1);
	pinMode(LED_E, OUTPUT);
	pinMode(LED_D, OUTPUT);
	digitalWrite(LED_E, HIGH);
	digitalWrite(LED_D, LOW);

	//row 6
	set_pin(1);
	pinMode(LED_F, OUTPUT);
	pinMode(LED_D, OUTPUT);
	digitalWrite(LED_F, HIGH);
	digitalWrite(LED_D, LOW);

	//row 7
	set_pin(1);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_D, OUTPUT);
	digitalWrite(LED_G, HIGH);
	digitalWrite(LED_D, LOW);

	//row 8
	set_pin(1);
	pinMode(LED_H, OUTPUT);
	pinMode(LED_D, OUTPUT);
	digitalWrite(LED_H, HIGH);
	digitalWrite(LED_D, LOW);
}

void emotion_death(){
	//row 1
	set_pin(1);
	pinMode(LED_A, OUTPUT);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_H, OUTPUT);
	digitalWrite(LED_A, HIGH);
	digitalWrite(LED_B, LOW);
	digitalWrite(LED_H, LOW);

	//row 2
	set_pin(1);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_A, OUTPUT);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_H, OUTPUT);
	digitalWrite(LED_B, HIGH);
	digitalWrite(LED_A, LOW);
	digitalWrite(LED_C, LOW);
	digitalWrite(LED_G, LOW);
	digitalWrite(LED_H, LOW);

	//row 3
	set_pin(1);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_D, OUTPUT);
	pinMode(LED_F, OUTPUT);
	pinMode(LED_G, OUTPUT);
	digitalWrite(LED_C, HIGH);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_D, OUTPUT);
	digitalWrite(LED_F, LOW);
	digitalWrite(LED_G, LOW);

	//row 4
	set_pin(1);
	pinMode(LED_D, OUTPUT);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_E, OUTPUT);
	pinMode(LED_F, OUTPUT);
	digitalWrite(LED_D, HIGH);
	digitalWrite(LED_C, LOW);
	digitalWrite(LED_E, LOW);
	digitalWrite(LED_F, LOW);

	//row 5
	set_pin(1);
	pinMode(LED_E, OUTPUT);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_D, OUTPUT);
	pinMode(LED_F, OUTPUT);
	digitalWrite(LED_E, HIGH);
	digitalWrite(LED_C, LOW);
	digitalWrite(LED_D, LOW);
	digitalWrite(LED_F, LOW);

	//row 6
	set_pin(1);
	pinMode(LED_F, OUTPUT);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_C, OUTPUT);
	pinMode(LED_E, OUTPUT);
	pinMode(LED_G, OUTPUT);
	digitalWrite(LED_F, HIGH);
	digitalWrite(LED_B, LOW);
	digitalWrite(LED_C, LOW);
	digitalWrite(LED_E, LOW);
	digitalWrite(LED_G, LOW);

	//row 7
	set_pin(1);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_A, OUTPUT);
	pinMode(LED_B, OUTPUT);
	pinMode(LED_F, OUTPUT);
	pinMode(LED_H, OUTPUT);
	digitalWrite(LED_G, HIGH);
	digitalWrite(LED_A, LOW);
	digitalWrite(LED_B, LOW);
	digitalWrite(LED_F, LOW);
	digitalWrite(LED_H, LOW);

	//row 8
	set_pin(1);
	pinMode(LED_H, OUTPUT);
	pinMode(LED_A, OUTPUT);
	pinMode(LED_G, OUTPUT);
	digitalWrite(LED_H, HIGH);
	digitalWrite(LED_A, LOW);
	digitalWrite(LED_G, LOW);
}