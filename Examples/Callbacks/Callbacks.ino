/* ***********************************************************
||
|| @file Callbacks.ino
|| @version 1.2
|| @author Ted Hayes
|| @contact ted.hayes@liminastudio.com
||
|| @description
|| | Demonstrates the use of asynchronous callback functions 
|| | instead of synchronous state checks
|| #
||
|| @revisions
|| | 09_15_2018 v1.2 Revised Wiring, made pin values constants,
|| |                 revised button object names, revised callback
|| |                 functions, included Callback doubleclickHandler
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
|| GND -----/ ------ pin 9 Button1
|| GND -----/ ------ pin 10 Button2
|| GND -----/ ------ pin 11 LED
|| GND -----/ ------ pin 12 LED
||
 * ********************************************************* */

/* ***********************************************************
 *                      Global Constants                     *
 * ********************************************************* */
const int b1Pin = 9;
const int b2Pin = 10;
const int led1Pin = 11;
const int led2Pin = 12;

//create two Button objects for two physical switches
// Uses debounce mode. You may need to experiment with the debounce duration
// for your particular switch.

Button ltButton(b1Pin, BUTTON_PULLUP_INTERNAL, true, 50);
Button rtButton(b2Pin, BUTTON_PULLUP_INTERNAL, true, 50);


/* ***********************************************************
 * Callback functions                                        *
 *   "Button& b" is a reference to the button that triggered *
 *   the callback. This way we can access its information so *
 *   we know which button it was.                            *
 * ********************************************************* */

void onPress(Button& b){
  Serial.print("onPress on pin: "); Serial.println(b.pinValue());
}

void onRelease(Button& b){
  Serial.print("onRelease on pin: "); Serial.println(b.pinValue());
}

void onHold(Button& b){
  Serial.print("Held for at least 1 second: "); Serial.println(b.pinValue());
  Serial.print("  holdEventThreshold is: "); Serial.print(b.holdEventThreshold);  Serial.println(" ms");

  //we only want change one of the LEDs that corresponds to that button
  if(b.pinValue()==b1Pin){ digitalWrite(led1Pin, !digitalRead(led1Pin)); }
  if(b.pinValue()==b2Pin){ digitalWrite(led2Pin, !digitalRead(led2Pin)); }
}

void onDoubleClick(Button& b){
  Serial.print("Double-click on pin: ");  Serial.println(b.pinValue());
  Serial.print("  doubleclickThreshold is: ");  Serial.print(b.doubleclickThreshold);  Serial.println(" ms");

  //we only want change one of the LEDs that corresponds to that button
  if(b.pinValue()==b1Pin){ digitalWrite(led1Pin, !digitalRead(led1Pin)); }
  if(b.pinValue()==b2Pin){ digitalWrite(led2Pin, !digitalRead(led2Pin)); }
}

/* ***********************************************************
 *                         Void Setup                        *
 * ********************************************************* */
void setup(){
  Serial.begin(9600);
  Serial.println("Started");
  pinMode(led1Pin,OUTPUT);                  //LED1 on pin 11
  pinMode(led2Pin,OUTPUT);                  //LED2 on pin 12

  // Assign callback functions
  ltButton.pressHandler(onPress);
  ltButton.releaseHandler(onRelease);
  ltButton.holdHandler(onHold, 1000); // must be held for at least 1000 ms to trigger
  ltButton.doubleclickThreshold = 900;// double-click threshold set for 900 ms max to trigger
  ltButton.doubleclickHandler(onDoubleClick);

  rtButton.pressHandler(onPress);
  rtButton.releaseHandler(onRelease);
  rtButton.holdHandler(onHold, 1000); // must be held for at least 1000 ms to trigger
  rtButton.doubleclickThreshold = 900;// double-click threshold set for 900 ms max to trigger
  rtButton.doubleclickHandler(onDoubleClick);
}

/* ***********************************************************
 *                         Void Loop                         *
 * ********************************************************* */
void loop(){
  // update the buttons' internals
  ltButton.process();
  rtButton.process();
}