#include <Arduino.h>
#include "ducky.h"

int d;//The base delay for this script
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

void setDelay(int del)
{
	d = del;
}

void wait(int time)
{
	delay(d * time);
}

//Primitives

void typeString(char * str)
{
	Keyboard.print(str);
	wait(1);
}

void typeChar(char c)
{
	Keyboard.write(c);
	wait(1);
}

void combo(int mods, char c)
{
	if(mods & CTRL)
	{
		Keyboard.press(KEY_LEFT_CTRL);
	}
	if(mods & ALT)
	{
		Keyboard.press(KEY_LEFT_ALT);
	}
	if(mods & SHIFT)
	{
		Keyboard.press(KEY_LEFT_SHIFT);
	}
	if(mods & GUI)
	{
		Keyboard.press(KEY_LEFT_GUI);
	}
	Keyboard.press(c);
	wait(1);
	Keyboard.releaseAll();
	wait(1);
}

//Compound

void typeLine(char * line)
{
	typeString(line);
	typeChar('\n');
}

void spotlight(char * search)
{
	combo(GUI, ' ');
	typeLine(search);
}

void enterCommand(char * cmd)
{
	spotlight("term");
	wait(5);
	typeString(cmd);
	typeChar('\n');
}