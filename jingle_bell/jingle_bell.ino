
#include "pitches.h"

int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;//狀態切換

int melody[] = {
    NOTE_B5,NOTE_B5,NOTE_B5,NOTE_B5,NOTE_B5,NOTE_B5,NOTE_B5,NOTE_D6,NOTE_G5,NOTE_A5,NOTE_B5,
    NOTE_C6,NOTE_C6,NOTE_C6,NOTE_C6,NOTE_C6,NOTE_B5,NOTE_B5,NOTE_B5,NOTE_B5,
    NOTE_B5,NOTE_A5,NOTE_A5,NOTE_B5,NOTE_A5,NOTE_D6
  };

int noteDurations[] = {
    4,4,2,4,4,2,4,4,3,8,1,
    4,4,3,8,4,4,4,8,8,
    4,4,4,4,2,2
  };

void setup() {
      pinMode(greenPin,OUTPUT);
      pinMode(redPin,OUTPUT);
      pinMode(bluePin,OUTPUT);
}

void loop() {
    for (int thisNote = 0; thisNote < 26; thisNote++) {
        counter++;
      if(counter == 1){//點亮綠色
      analogWrite(greenPin,125);
      analogWrite(redPin,0);
      analogWrite(bluePin,87);
      }
      else if(counter == 2){//點亮紅色
      analogWrite(greenPin,0);
      analogWrite(redPin,0);
      analogWrite(bluePin,125);
      }  
      else if(counter == 3){//點亮藍色
      analogWrite(greenPin,0);
      analogWrite(redPin,127);
      analogWrite(bluePin,127);
      counter = 0;//歸零
      }
      //delay(1000); 
  
        
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(8, melody[thisNote], noteDuration);
      
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      
      noTone(8);
   
      }
    
}
