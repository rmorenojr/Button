# New & Improved Arduino Button Library

_by Ted Hayes, from code originally by Alexander Brevig & Tom Igoe_

The Arduino Button library makes it easy to do some very common but rather tedious tasks.  Usually when you interact with a button (such as a momentary switch), you mainly want to detect the state change, not just the current state.  You have to do something like:
```C++
int lastState = 0;

void loop(){
  int currentState = digitalRead(11);
  if(currentState != lastState){
    // do something
  }
  lastState = currentState;
}
```
It's not hard, just tedious.  This new and improved Button library makes this much simpler but adds so much more.  Now you can do it this way:
```C++
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
```

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

## Installing

To install, [download](https://github.com/virgildisgr4ce/Button/zipball/master) the library, extract it to ~/Documents/Arduino/libraries and rename the folder "Button." (Github generates a different name for the zip link.) Restart Arduino if it was already open.

I hope you find this useful! Please report any bugs using the [Github issue tracker](https://github.com/virgildisgr4ce/Button/issues).

## Functions

### constructor - button
##### Description
	Sets the inital state of this button     
##### Syntax
	Button myButton(int buttonPin, optional int buttonMode, optional bool debounceMode, optional int debounceDuration);
##### Parameters
###### buttonPin
	int specific Arduino pin connect to the button <required>
###### buttonMode [optional]
	BUTTON_PULLUP_INTERNAL using internal Arduino resistor <default>
	BUTTON_PULLUP   by extenal resistor
	BUTTON_PULLDOWN by extenal resistor
###### debouceMode [optional]
	bool true OR false <default=true>
###### debounceDuration [optional]
	int timeInMilliseconds <default=20>
##### Returns
	None.
##### Examples
```C++
Button myButton(11);
Button myButton(11, BUTTON_PULLUP_INTERNAL);
Button myButton(11, BUTTON_PULLUP_INTERNAL, true, 50);
```

### pullup
##### Description
	changes the buttonMode      
##### Syntax
	myButton.pullup(int buttonMode);
##### Parameters
###### buttonMode
	BUTTON_PULLUP_INTERNAL using internal Arduino resistor
	BUTTON_PULLUP   by extenal resistor
##### Returns
	None.
##### Examples
```C++
myButton.pullup(BUTTON_PULLUP);           //assumes external resistor 
myButton.pullup(BUTTON_PULLUP_INTERNAL);
```

### process
##### Description
	read and write states or isse callbacks      
##### Syntax
	myButton.process();
##### Parameters
	None.
##### Returns
	None.
##### Examples
```C++
myButton.process();
```

### isPressed
##### Description
	returns true if button is pressed      
##### Syntax
	myButton.isPressed();
##### Parameters
	None.
##### Returns
	bool true or false
##### Examples
```C++
if(myButton.isPressed()){
  //take action
}
```

### wasPressed
##### Description
	returns true if button was pressed some time in the past     
##### Syntax
	myButton.wasPressed();
##### Parameters
	None.
##### Returns
	bool true or false
##### Examples
```C++
if(myButton.wasPressed()){
  Serial.println("Button was pressed before");
}else{
  Serial.println("Button has not been pressed");
}
```

### stateChanged
##### Description
	detects a state change in the button     
##### Syntax
	myButton.stateChanged();
##### Parameters
	None.
##### Returns
	bool true or false
##### Examples
```C++
if(myButton.stateChanged()){
  //take action
}
```

### uniquePress
##### Description
	detects if button is pressed and was not pressed before     
##### Syntax
	myButton.uniquePress();
##### Parameters
	None.
##### Returns
	bool true or false
##### Examples
```C++
if(myButton.uniquePress()){
  //take action
}
```

## Callbacks
### pressHandler, releaseHandler, clickHandler, holdHandler
##### Description
	detects if button is pressed and was not pressed before     
##### Syntax
	myButton.pressHandler(functionName);
	myButton.releaseHandler(functionName);
	myButton.clickHandler(functionName);
	myButton.holdHandler(functionName, int milliseconds); 
##### Parameters
	functionName - the name of the function that will be called when true
	milliseconds - the amount of time in ms to trigger the event
##### Returns
	bool true or false
##### Examples
```C++
// Callback functions
// "Button& b" is a reference to the button that triggered the callback
// This way we can access its information so we know which button it was
void onPress(Button& b){
  // onPress do something
}
void onRelease(Button& b){
  // onRelease do something
}
void onHold(Button& b){
  // onHold do something
}
void onClick(Button& b){
  // onClick do something
}

void setup(){
  Serial.begin(9600);
  Serial.println("Started");
  // Assign callback functions
  myButton.pressHandler(onPress);
  myButton.releaseHandler(onRelease);
  myButton.holdHandler(onHold, 1000); // must be held for at least 1000 ms to trigger
  myButton2.clickHandler(onClick);
}

void loop(){
  // update the buttons' internals
  myButton.process();
  myButton2.process();
}
```
