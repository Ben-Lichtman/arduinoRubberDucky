#include <Arduino.h>
#include "duckyTeensy.h"

long d;//The base delay for this script
int ledPin;

//Config and Misc

void setLedPin(int pin)
{
	ledPin = pin;
}

void setLed(bool state)
{
	digitalWrite(ledPin, state ? HIGH : LOW);
}

void setDelay(long del)
{
	d = del;
}

void wait(long time)
{
	Keyboard.delay(d * time);
}

//Primitives

void typeChar(char c)
{
	Keyboard.write(c);
	wait(1);
}

void combo(char c, int mods)
{
	if(mods & MOD_CONTROL_LEFT == mods)
	{
		Keyboard.press(KEY_LEFT_CTRL);
	}
	if(mods & MOD_ALT_LEFT == mods)
	{
		Keyboard.press(KEY_LEFT_ALT);
	}
	if(mods & MOD_SHIFT_LEFT == mods)
	{
		Keyboard.press(KEY_LEFT_SHIFT);
	}
	if(mods & MOD_GUI_LEFT == mods)
	{
		Keyboard.press(KEY_LEFT_GUI);
	}
	Keyboard.press(c);
	wait(1);
	Keyboard.releaseAll();
	wait(1);
}

void typeString(char * str)
{
	Keyboard.print(str);
	wait(1);
}

//Compound

void typeLine(char * line)
{
	typeString(line);
	wait(1);
	typeChar('\n');
}

void spotlight(char * text)
{
	combo(GUI, ' ');
	typeLine(text);
}

void run(char * text)
{
	combo(GUI, 'r');
	typeLine(text);
}

void term()
{
	Keyboard.press(KEY_LEFT_ALT);
	Keyboard.press(KEY_F2);
	wait(5);
	Keyboard.releaseAll();
}

void enterCommandMac(char * cmd)
{
	char text[] = "term";
	spotlight(text);
	wait(5);
	typeLine(cmd);
}

void enterCommandWin(char * cmd)
{
	char text[] = "cmd";
	run(text);
	wait(10);
	typeLine(cmd);
}

void enterCommandLinux(char * cmd)
{
	term();
	wait(5);
	typeLine(cmd);
}
