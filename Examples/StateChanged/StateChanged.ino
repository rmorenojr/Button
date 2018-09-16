/* ***********************************************************
||
|| @file StateChange.ino
|| @version 1.2|| @author Ted Hayes
|| @contact ted.hayes@liminastudio.com
||
|| @description
|| | Detects a state change in the button
|| #
||
|| @revisions
|| | 09_15_2018 v1.2 Revised Wiring, LED 13 used by serial monitor,
|| |                 by Ricardo Moreno
|| | 09_13_2018 v1.1 Correct file name above and revised instantiation
|| |                 object name and format by Ricardo Moreno 
|| #
||
|| @license
|| | Copyright (c) 2012 Ted Hayes. All rights reserved.
|| #
||
 * ********************************************************* */

#include <Button.h>

/* ***********************************************************
|| Wiring:
|| GND -----/ ------ pin 11 to button
|| GND -----/ ------ pin 12 to LED
||
 * ********************************************************* */

//create a Button object at pin 11
Button myButton(11, BUTTON_PULLUP_INTERNAL);

void setup(){
  Serial.begin(9600);
  pinMode(12,OUTPUT);              //led on pin 12
}

void loop(){
  if(myButton.stateChanged()){
    Serial.println("stateChanged");
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(12,LOW);
  }
}