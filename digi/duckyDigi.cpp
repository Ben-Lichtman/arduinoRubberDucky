#include <DigiKeyboard.h>
#include "duckyDigi.h"

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
	delay(d * time);
}

//Primitives

void typeChar(char c)
{
	DigiKeyboard.sendKeyStroke((byte)c);
	wait(1);
}

void combo(char c, int mods)
{
	DigiKeyboard.sendKeyPress(c, mods);
	wait(1);
	DigiKeyboard.sendKeyPress(0);
	wait(1);
}

void typeString(char * str)
{
	DigiKeyboard.print(str);
	wait(1);
}

void typeLine(char * str)
{
	DigiKeyboard.println(str);
	wait(1);
}

//Compound

void spotlight(char * text)
{
	combo(KEY_SPACE, MOD_GUI_LEFT);
	typeLine(text);
}

void run(char * text)
{
	combo(KEY_R, MOD_GUI_LEFT);
	typeLine(text);
}

void term()
{
	combo(KEY_F2, MOD_ALT_LEFT);
}

void enterCommandMac(char * cmd)
{
	char text[] = "term";
	spotlight(text);
	wait(5);
	typeLine(cmd);
}

void enterCommandWin	(char * cmd)
{
	char text[] = "cmd";
	run(text);
	wait(10);
	typeLine(cmd);
}

void enterCommandLinux	(char * cmd)
{
	term();
	wait(5);
	typeLine(cmd);
}
