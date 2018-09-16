/* ***********************************************************
||
|| @file DoubleClick.ino
|| @version 1.0
|| @author Ricardo Moreno
|| @contact rmorenojr2@live.com
||
|| @description
|| | Demonstrates a intuitive way of using a button for double-click
|| | when using this Hardware Abstraction class
|| #
||
|| @revisions
|| | 09_14_2008 v1.0 Initial version by Ricardo Moreno
|| #
||
|| @license
|| | Copyright (c) 2018 Ricardo Moreno. All rights reserved.
|| #
||
 * ********************************************************* */

#include <Button.h>

/* ***********************************************************
|| Circuit Wiring:
|| GND -----/ ------ pin 11 Button
|| GND -----/ ------ pin 12 LED
||
 * ********************************************************* */

/* ***********************************************************
 *                      Global Constants                     *
 * ********************************************************* */
const int buttonPin = 11;
const int ledPin = 12;

//create Button objects for physical switch
//   Uses debounce mode. You may need to experiment with
//   the debounce duration for your particular switch.

Button Button1(buttonPin, BUTTON_PULLUP_INTERNAL, true, 30);

/* ***********************************************************
 *                         Void Setup                        *
 * ********************************************************* */
void setup(){
  Serial.begin(9600);
  Serial.println("Started");
  pinMode(ledPin,OUTPUT);                //LED on pin 12
}

/* ***********************************************************
 *                         Void Loop                         *
 * ********************************************************* */
void loop(){
  if(Button1.isDoubleClicked()){
	digitalWrite(ledPin, !digitalRead(ledPin)));
  }
}