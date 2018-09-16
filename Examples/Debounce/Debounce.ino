/* ***********************************************************
||
|| @file Debounce.ino
|| @version 1.2
|| @author Ted Hayes
|| @contact ted.hayes@liminastudio.com
||
|| @description
|| | Detects a state change in the button
|| #
||
|| @revisions
|| | 09_15_2018 v1.2 Revised Wiring, LED 13 used by serial monitor,
|| |                 revised digitalWrite statement in void loop to toggle
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
|| Circuit Wiring:
|| GND -----/ ------ pin 11 to button
|| GND -----/ ------ pin 12 to LED
||
 * ********************************************************* */

//create a Button object at pin 11
// Uses debounce mode. You may need to experiment with the debounce duration
// for your particular switch.

Button myButton(11, BUTTON_PULLUP_INTERNAL, true, 50);

void setup(){
  Serial.begin(9600);
  pinMode(12,OUTPUT); //debug to led 12
}

void loop(){
  if(myButton.uniquePress()){
    Serial.println("Button Pressed");
    digitalWrite(12, !digitalRead(12)); 
  }
}