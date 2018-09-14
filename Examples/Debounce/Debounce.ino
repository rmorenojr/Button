/*
||
|| @file Debounce.ino
|| @version 1.1
|| @author Ted Hayes
|| @contact ted.hayes@liminastudio.com
||
|| @description
|| | Detects a state change in the button
|| #
||
|| @revisions
|| | 09_13_2018 v1.1 Correct file name above and revised instantiation
|| |                 object name and format by Ricardo Moreno 
|| #
||
|| @license
|| | Copyright (c) 2012 Ted Hayes. All rights reserved.
|| #
||
*/

#include <Button.h>

/*
|| Wiring:
|| GND -----/ ------ pin 12 to button
|| GND -----/ ------ pin 13 to LED
*/
//create a Button object at pin 12
// Uses debounce mode. You may need to experiment with the debounce duration
// for your particular switch.

Button myButton(12, BUTTON_PULLUP_INTERNAL, true, 50);

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT); //debug to led 13
}

void loop(){
  if(myButton.uniquePress()){
    Serial.println("Button Pressed");
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
}