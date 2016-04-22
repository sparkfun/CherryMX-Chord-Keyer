/*
 * Chord Keyer
 * Nick Poole 2016
 * SparkFun Electronics
 * 
 * The Chord Keyer is a one-handed text entry device based on the SparkFun
 * Pro Micro and the Cherry MX Blue Mechanical Switch. 3D Models for the 
 * keys and enclosure can be found at: 
 * https://github.com/sparkfun/CherryMX-Chord-Keyer
 * 
 * Enjoy! 
 */

#include <Keyboard.h>

int key = 0;
boolean capslock = 0;

void setup() {

pinMode(9, INPUT); digitalWrite(9,1); //Thumb
pinMode(3, INPUT); digitalWrite(3,1); //Index
pinMode(4, INPUT); digitalWrite(4,1); //Middle
pinMode(5, INPUT); digitalWrite(5,1); //Ring
pinMode(6, INPUT); digitalWrite(6,1); //Pinky

}

void loop() {

  //Look for Keypress
  if(digitalRead(9)==0 || digitalRead(3)==0 || digitalRead(4)==0 || digitalRead(5)==0 || digitalRead(6)==0){

    delay(100); //Give fingers time to settle

        //Lazy Binary Translate
        if(digitalRead(9)==0){key=key+1;}
        if(digitalRead(3)==0){key=key+2;}
        if(digitalRead(4)==0){key=key+4;}
        if(digitalRead(5)==0){key=key+8;}
        if(digitalRead(6)==0){key=key+16;}

        //Decision Tree
        if(key==31){Keyboard.print(" ");}
        if(key==27){Keyboard.print(".");}
        if(key==28){Keyboard.write(10);}
        if(key==29){Keyboard.write(8);}
        if(key==30){capslock=!capslock;}
        if(key!=0 && key<27){
        if(capslock){key=key+64;}else{key=key+96;}
        Keyboard.write(key);}
        key=0;

     delay(100);
  }

}
