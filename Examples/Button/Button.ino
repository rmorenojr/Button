/*
||
|| @file Button.ino
|| @version 1.2
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Display the intuitive way of using a button when using this Hardware Abstraction class
|| #
||
|| @revisions
|| | xx_xx_xxxx Minor fixes by Ted Hayes / ted.hayes@liminastudio.com
|| | 09_13_2018 v1.2 Revised instantiation object name and format by Ricardo Moreno
|| #
||
|| @license
|| | Copyright (c) 2009 Alexander Brevig. All rights reserved.
|| | This code is subject to AlphaLicence.txt
|| | alphabeta.alexanderbrevig.com/AlphaLicense.txt
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
Button myButton(12, BUTTON_PULLUP_INTERNAL);

void setup(){
  pinMode(13,OUTPUT);         //debug to led 13
}

void loop(){
  if(myButton.isPressed()){
	digitalWrite(13,HIGH);
  }else{
	digitalWrite(13,LOW);
  }
}
