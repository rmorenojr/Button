# New & Improved Arduino Button Library

_by Ted Hayes, from code originally by Alexander Brevig & Tom Igoe_

The Arduino Button library makes it easy to do some very common but rather tedious tasks.  Usually when you interact with a button (such as a momentary switch), you mainly want to detect the state change, not just the current state.  You have to do something like:

	int lastState = 0;

	void loop(){
		int currentState = digitalRead(11);
		if(currentState != lastState){
			// do something
		}
		lastState = currentState;
	}

It's not hard, just tedious.  This new and improved Button library makes this much simpler but adds so much more.  Now you can do it this way:

	Button button = Button(12);

	void onPress(Button& b){
		Serial.print("onPress: ");
		Serial.println(b.pin);
		// will print out "onPress: 12"
	}

	void setup(){
	  Serial.begin(9600);
	  // Assign callback function
	  button.pressHandler(onPress);
	}

	void loop(){
	  // update the buttons' internals
	  button.process();
	}

## Features

* Instance-based design

	`Button myButton(11);`

* Automatic pull-up setting

	`Button myButton(11, BUTTON_PULLUP_INTERNAL);`

* Simplified state-change detection:

	`if(button.isPressed()) ...`

* Callback model

	`button.pressHandler(onPress)`

* Built-in debouncing

    `// Sets 50ms debounce duration`

    `Button button = Button(12, BUTTON_PULLUP_INTERNAL, true, 50);`
## Methods
 * `pullup(buttonMode) ` - Prepare logic for a pullup button. If mode is internal set pin HIGH as default
 * `pulldown() ` - Set pin LOW as default.
 * `process() ` - Read and write states; issue callbacks.
 * `isPressed() ` - Returns true if button is pressed.
 * `wasPressed() ` - Returns true if the button has been pressed.
 * `stateChanged() ` - Returns true if state has been changed.
 * `uniquePress() ` - Returns true if the button is pressed, and was not pressed before.
 * `setHheldoldThreshold(duration) ` - Set the hold event time threshold.
 * `held(duration) ` - Check to see if the button has been pressed for time ms.
 * `heldfor(duration) ` - Polling model for holding, this is true every check after hold time in ms.
 * `pressHandler(buttonEventHandler) ` - Register a handler for presses on this button.
 * `releaseHandler(buttonEventHandler) ` - Register a handler for releases on this button.
 * `clickHandler(buttonEventHandler)` - Register a handler for clicks on this button.
 * `holdHandler(buttonEventHandler, time) ` - Register a handler for when this button is held.
 * `unsigned int holdTime() ` - Returns The time this button has been held.
## Installing

To install, [download](https://github.com/virgildisgr4ce/Button/zipball/master) the library, extract it to ~/Documents/Arduino/libraries and rename the folder "Button." (Github generates a different name for the zip link.) Restart Arduino if it was already open.

I hope you find this useful! Please report any bugs using the [Github issue tracker](https://github.com/virgildisgr4ce/Button/issues).
