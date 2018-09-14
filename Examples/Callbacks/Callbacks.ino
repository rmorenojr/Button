/*
||
|| @file Callbacks.ino
|| @version 1.1
|| @author Ted Hayes
|| @contact ted.hayes@liminastudio.com
||
|| @description
|| | Demonstrates the use of asynchronous callback functions instead of synchronous state checks
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
|| GND -----/ ------ pin 11 to button1
|| GND -----/ ------ pin 12 to button2
|| GND -----/ ------ pin 13 to LED
*/
//create two Button objects for two physical switches
// Uses debounce mode. You may need to experiment with the debounce duration
// for your particular switch.

Button myButton1(12, BUTTON_PULLUP_INTERNAL, true, 50);
Button myButton2(11, BUTTON_PULLUP_INTERNAL, true, 50);

// Callbacks
// "Button& b" is a reference to the button that triggered the callback
// This way we can access its information so we know which button it was
void onPress(Button& b){
	Serial.print("onPress: ");
	Serial.println(b.pin);
	digitalWrite(13,HIGH);
}

void onRelease(Button& b){
	Serial.print("onRelease: ");
	Serial.println(b.pin);
	digitalWrite(13,LOW);
}

void onHold(Button& b){
	Serial.print("Held for at least 1 second: ");
	Serial.println(b.pin);
}

void setup(){
  Serial.begin(9600);
  Serial.println("Started");
  pinMode(13,OUTPUT);              //debug to led 13

  // Assign callback functions
  myButton1.pressHandler(onPress);
  myButton1.releaseHandler(onRelease);
  myButton1.holdHandler(onHold, 1000); // must be held for at least 1000 ms to trigger

  myButton2.pressHandler(onPress);
  myButton2.releaseHandler(onRelease);
  myButton2.holdHandler(onHold, 1000); // must be held for at least 1000 ms to trigger
}

void loop(){
  // update the buttons' internals
  myButton1.process();
  myButton2.process();
}