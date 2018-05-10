#include "duckyDigi.h"

#define WINDOWS 1
#define MAC 2
#define LINUX 3

void setup()
{
	//Initialise ducky
	setLedPin(1);
	setLed(false);
	setDelay(100);

	int os = 0;
	os = WINDOWS;

	char * command = (char *)"";

	if(os == WINDOWS)
		command = (char *)"start \"\" https://www.youtube.com/watch?v=dQw4w9WgXcQ";
	else if(os == MAC)
		command = (char *)"osascript -e \"set Volume 10\";open https://www.youtube.com/watch?v=dQw4w9WgXcQ";
	else if(os == LINUX)
		command = (char *)"pactl set-sink-mute 0 0; pactl set-sink-volume 0 100%; amixer set Master unmute; amixer sset 'Master' 100%; xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ";

	if(os == WINDOWS)
		enterCommandWin(command);
	else if(os == MAC)
		enterCommandMac(command);
	else if(os == LINUX)
		enterCommandLinux(command);

	setLed(true);
}

void loop()
{
}
