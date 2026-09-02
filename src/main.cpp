#include <Arduino.h>
#define ANALOG_X_PIN A4
#define ANALOG_Y_PIN A3
#define ANALOG_BUTTON_PIN A2

//Default values when axis not actioned 
#define ANALOG_X_CORRECTION 5
#define ANALOG_Y_CORRECTION 5
	 
struct joy_button { 
	byte pressed = 0; 
}; 
	 
struct analog { 
	short x, y; 

	joy_button button; 
}; 

byte readAnalogAxisLevel(int pin);
bool isAnalogButtonPressed(int pin);

void setup() {
	pinMode(ANALOG_BUTTON_PIN, INPUT_PULLUP);

	Serial.begin(115200);
}

void loop() {
	analog analog;

	analog.x = readAnalogAxisLevel(ANALOG_X_PIN) - ANALOG_X_CORRECTION;

	analog.y = readAnalogAxisLevel(ANALOG_Y_PIN) - ANALOG_Y_CORRECTION;

	analog.button.pressed = isAnalogButtonPressed(ANALOG_BUTTON_PIN);

	Serial.print(analog.x); 
	Serial.print(":"); 
	
	Serial.print(analog.y); 
	Serial.print(":"); 
	
	if (analog.button.pressed) { 
	Serial.println("1"); 
	} else { 
	Serial.println("0"); 
	} 
	delay(10);
}

byte readAnalogAxisLevel(int pin) 
{ 
	 return map(analogRead(pin), 0, 1023, 0, 10); 
} 
	 
bool isAnalogButtonPressed(int pin) 
{ 
	 return digitalRead(pin) == 0; 
} 