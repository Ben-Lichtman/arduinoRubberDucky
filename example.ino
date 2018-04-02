#include "ducky.h"

void setup()
{
	//Initialise
	setLedPin(11);
	setLed(false);
	setDelay(100);
	wait(5);

	//Invert screen
	combo(CTRL|ALT|GUI, '8');
	//Lulz
	enterCommand("open 'https://www.youtube.com/watch?v=dQw4w9WgXcQ'");

	setLed(true);
}

void loop()
{
}
